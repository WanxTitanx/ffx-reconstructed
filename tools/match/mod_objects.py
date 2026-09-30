"""Place compiled modification sections and resolve authentic COFF references."""
import struct
import coff_relocations as coff
import leaf_build as support
import text_program
import x86_source

GROUPS = ('.modtxt', '.modro', '.moddat')


def align(value, alignment):
    return (value + alignment - 1) // alignment * alignment


def allocate(obj):
    sizes = {name: 0 for name in GROUPS}
    entries = {}
    accepted = []
    base_order = {}
    for position, section in enumerate(obj['sections']):
        size = section['raw_size']
        if not size:
            if section['relocations']:
                raise ValueError('empty modification section contains references')
            continue
        flags = section['characteristics']
        if (section['name'] in ('.debug$S', '.debug$T') and flags & 0x02000000
                and not flags & 0xa0000020 and not section['relocations']):
            continue
        name, separator, suffix = section['name'].partition('$')
        if name == '.text' and flags & 0x20 and not flags & 0x80000000:
            group = '.modtxt'
        elif name in ('.rdata', '.rodata') and flags & 0x40 and not flags & 0xa0000000:
            group = '.modro'
        elif name in ('.data', '.bss') and flags & 0xc0 and not flags & 0x20000000:
            group = '.moddat'
        else:
            raise ValueError('unsupported compiled modification section: ' + section['name'])
        encoded_alignment = (flags >> 20) & 15
        if encoded_alignment == 15:
            raise ValueError('invalid COFF alignment')
        alignment = 1 << (encoded_alignment - 1) if encoded_alignment else 16
        if alignment > 4096:
            raise ValueError('modification alignment exceeds PE section alignment')
        base = (group, name)
        if base not in base_order:
            base_order[base] = len(base_order)
        suffix_bytes = suffix.encode('utf-8', errors='surrogateescape')
        key = (GROUPS.index(group), base_order[base], bool(separator), suffix_bytes, position)
        accepted.append((key, section, group, alignment))
    for _, section, group, alignment in sorted(accepted, key=lambda item: item[0]):
        size = section['raw_size']
        offset = align(sizes[group], alignment)
        entries[section['index']] = {'group': group, 'offset': offset, 'size': size,
                                     'source_section': section['name']}
        sizes[group] = offset + size
    if not sizes['.modtxt']:
        raise ValueError('modification contains no compiled code')
    return {k: v for k, v in sizes.items() if v}, entries


def symbols(obj, entries, group_addresses, external, baseline):
    """Use COFF indexes internally: local/section names need not be unique."""
    addresses, exported = {}, {}
    needed = {r['symbol_index'] for s in obj['sections'] for r in s['relocations'] if r['type']}
    used_external = set()
    for index, symbol in obj['symbols'].items():
        section = symbol['section']
        if section > 0:
            placement = entries.get(section)
            if placement is None:
                if index in needed:
                    raise ValueError('reference to an unplaced compiler section')
                continue
            if not 0 <= symbol['value'] <= placement['size']:
                raise ValueError('compiler symbol exceeds its section')
            va = group_addresses[placement['group']] + placement['offset'] + symbol['value']
            addresses[index] = va
            if symbol['storage'] == 2:
                if symbol['name'] in exported:
                    raise ValueError('duplicate compiled definition: ' + symbol['name'])
                exported[symbol['name']] = va
        elif section == -1:
            addresses[index] = symbol['value']
        elif index in needed:
            if section != 0 or symbol['storage'] != 2 or symbol['value']:
                raise ValueError('unsupported common, weak or debug symbol')
            alias = external.get(symbol['name'])
            if alias not in baseline:
                raise ValueError('undeclared external modification symbol: ' + symbol['name'])
            addresses[index] = baseline[alias]
            used_external.add(symbol['name'])
    if set(external) != used_external:
        raise ValueError('unused or invalid external modification bindings')
    return addresses, exported


def emit_module(obj, sizes, entries, group_addresses, addresses, image_base):
    contents = {name: bytearray(size) for name, size in sizes.items()}
    highlow, records = [], []
    bindings = {'@mod:' + str(i): va for i, va in addresses.items()}
    for section in obj['sections']:
        if section['index'] not in entries:
            continue
        place = entries[section['index']]
        va = group_addresses[place['group']] + place['offset']
        if not section['raw']:
            if not section['characteristics'] & 0x80 or section['relocations']:
                raise ValueError('unbacked modification section is not zero storage')
            raw, evidence = bytes(section['raw_size']), []
        else:
            relocations = [dict(r, symbol_name='@mod:' + str(r['symbol_index']))
                           if r['type'] else dict(r) for r in section['relocations']]
            raw, evidence = coff.relocate(dict(section, relocations=relocations), va, bindings, image_base)
        contents[place['group']][place['offset']:place['offset'] + len(raw)] = raw
        highlow.extend(va + r['offset'] for r in section['relocations'] if r['type'] == coff.DIR32)
        records.append(dict(place, va=va, sha256=support.digest(raw), relocations=evidence))
    return {name: bytes(data) for name, data in contents.items()}, highlow, records


def owner(address, replacements):
    for item in replacements:
        if item['va'] <= address < item['va'] + item['size']:
            return item
    return None


def relink(section, va, bindings, replacements, image_base=0x400000):
    """Retarget only recorded references whose effective target is an exact entry."""
    adjusted = dict(bindings)
    relocations, changes, highlow = [], [], []
    for index, record in enumerate(section['relocations']):
        item = dict(record)
        if not record['type']:
            relocations.append(item)
            continue
        name = record['symbol_name']
        if name not in bindings:
            raise ValueError('missing baseline symbol: ' + name)
        offset = record['offset']
        addend = struct.unpack_from('<i', section['raw'], offset)[0]
        target = bindings[name] + addend
        replacement = owner(target, replacements)
        site = va + offset
        if replacement is not None and owner(site, replacements) is None:
            if target != replacement['va']:
                raise ValueError('external reference enters replacement interior at %#x' % target)
            alias = '@replacement:' + str(index)
            adjusted[alias] = replacement['new_va'] - addend
            item['symbol_name'] = alias
            changes.append({'site': site, 'from': target, 'to': replacement['new_va'],
                            'type': record['type'], 'symbol': name, 'addend': addend})
        if record['type'] == coff.DIR32:
            highlow.append(site)
        relocations.append(item)
    raw, _ = coff.relocate(dict(section, relocations=relocations), va, adjusted, image_base)
    return raw, changes, highlow


def check_instruction_references(records, bindings, replacements):
    for record in records:
        if record['kind'] != 'instruction':
            continue
        instruction = record['instruction']
        source_owner = owner(instruction['ip'], replacements)
        if source_owner is not None:
            continue
        check_numeric_fields(instruction, replacements)
        affected = {name for name in text_program.record_symbols(record, {})
                    if name in bindings and owner(bindings[name], replacements) is not None
                    and owner(bindings[name], replacements) is not source_owner}
        if not affected:
            continue
        _, fixups = x86_source.encode(instruction, bindings, relocatable=True)
        relocated = {r['symbol_name'] for r in fixups}
        if affected - relocated:
            raise ValueError('short or unrelocated reference to a replaced function at %#x' % instruction['ip'])


def check_numeric_fields(instruction, replacements, relocated_fields=()):
    if owner(instruction['ip'], replacements) is not None:
        return
    values = [('memory', instruction.get('memory', {}).get('displacement'))]
    values.extend(('operand:' + str(i), operand.get('value', operand.get('target')))
                  for i, operand in enumerate(instruction['operands']))
    for field, value in values:
        if field not in relocated_fields and type(value) is int and owner(value, replacements) is not None:
            raise ValueError('unrelocated numeric function address at %#x (%s)' % (instruction['ip'], field))
