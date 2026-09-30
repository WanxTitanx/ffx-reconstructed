#!/usr/bin/env python3
"""Build C address expressions with real external-symbol relocations."""
import argparse
import bisect
import json
from pathlib import Path
import definitive_match as exact
import leaf_reconstruct as leaf
ROOT = Path(__file__).resolve().parents[2]


def source_spec(code, relocation_offsets, symbol):
    if len(relocation_offsets) != 1:
        raise ValueError('expected one real operand relocation')
    offset = relocation_offsets[0]
    if len(code) == 6 and code[0] == 0xb8 and code[-1] == 0xc3 and offset == 1:
        return {'return_type':'const void *','convention':'__cdecl','arguments':'void',
                'body':'return ' + symbol + ';'}
    if code.startswith(b'\xc7') and code.endswith(b'\xc3'):
        operand = leaf.memory_operand(code[1:-1], 1)
        if operand and offset == 1 + operand[1] and offset + 4 == len(code) - 1:
            return {'return_type':'void','convention':'__fastcall','arguments':'unsigned char *p',
                    'body':'*(const void **)(%s) = %s;' % (leaf.pointer(operand[0]),symbol)}
    raise ValueError('unsupported symbolic operand or relocation offset')


def symbol_record(va, sections, inventory):
    section = next((s for s in sections if s[1] <= va < s[1]+max(s[2],s[4])), None)
    if section is None:
        raise ValueError('destination is outside the image')
    record = {'name':'sym_%08x' % va,'va':va,'section':section[0],
              'section_offset':va-section[1], 'file_backed':va-section[1] < section[4]}
    if section[0] == '.text':
        record['kind'] = 'function' if va in inventory else 'code_or_text_data'
        if va in inventory:
            record['inventory'] = inventory[va]
    else:
        record['kind'] = 'data' if record['file_backed'] else 'zero_initialized_storage'
    return record


def prepare(project, output):
    original, sections = exact.load_pe(exact.EXE_DEFAULT)
    if leaf.digest(original) != exact.EXE_SHA256:
        raise ValueError('reference executable hash differs')
    read = exact.va_reader(original, sections)
    relocations = leaf.pe_relocations(original, sections)
    inventory_data = (project/'tools/match/inventory.tsv').read_bytes()
    inventory = {r['va']:r for r in leaf.inventory_rows(inventory_data)}
    seed_data = (ROOT/'recon/ffx/c_leaf/jobs.json').read_bytes()
    seed = json.loads(seed_data)
    if seed['inventory_sha256'] != leaf.digest(inventory_data):
        raise ValueError('preserved leaf jobs use another inventory')
    groups, symbols = [], {}
    for group in seed['groups']:
        selected, destinations, offsets = [], set(), None
        for target in group['targets']:
            va, size = target['va'], target['size']
            if inventory.get(va) != target:
                raise ValueError('seed target disagrees with inventory')
            code = read(va,size)
            if code is None or leaf.digest(code) != target['sha256']:
                raise ValueError('seed target disagrees with executable')
            lo = bisect.bisect_left(relocations,va-3)
            hi = bisect.bisect_left(relocations,va+size)
            sites = relocations[lo:hi]
            if not sites:
                continue
            if len(sites) != 1 or not va <= sites[0] <= va+size-4:
                raise ValueError('unexpected relocation in pending leaf')
            offsets = [sites[0]-va]
            destinations.add(int.from_bytes(read(sites[0],4),'little'))
            selected.append(target)
        if not selected:
            continue
        if len(destinations) != 1:
            raise ValueError('one identity group has different destinations')
        address = destinations.pop()
        name = 'sym_%08x' % address
        symbols[name] = symbol_record(address,sections,inventory)
        spec = source_spec(read(selected[0]['va'],selected[0]['size']),offsets,name)
        groups.append({'symbol':group['symbol'],'source':spec,'targets':selected,
                       'relocations':[{'offset':offsets[0],'type':6,'symbol':'_'+name,'addend':0}]})
    return write_package(output,groups,symbols,sections,inventory_data,seed_data)


def write_package(output,groups,symbols,sections,inventory_data,seed_data):
    lines = ['/* Symbolic C; address operands use COFF relocations. */',
             'typedef char require_x86_pointers[sizeof(void *) == 4 ? 1 : -1];']
    for name in sorted(symbols):
        lines.append('extern const unsigned char %s[];' % name)
    for group in groups:
        s = group['source']
        lines.append('__declspec(noinline) %s %s %s(%s) { %s }' % (
            s['return_type'],s['convention'],group['symbol'],s['arguments'],s['body']))
    source = ('\n'.join(lines)+'\n').encode()
    generator = Path(__file__).read_bytes()
    jobs = {'schema_version':1,'target_sha256':exact.EXE_SHA256,
            'inventory_sha256':leaf.digest(inventory_data),'seed_jobs_sha256':leaf.digest(seed_data),
            'generator_sha256':leaf.digest(generator),'source_sha256':leaf.digest(source),
            'groups':groups,'symbols':list(symbols.values()),
            'sections':[{'name':n,'va':va,'virtual_size':vs,'raw_offset':rp,'raw_size':rs}
                        for n,va,vs,rp,rs in sections]}
    output.mkdir(parents=True,exist_ok=True)
    for name in ('proof.json','build/build-manifest.json'):
        (output/name).unlink(missing_ok=True)
    (output/'symbolic_leaf.c').write_bytes(source)
    (output/'jobs.json').write_bytes((json.dumps(jobs,indent=2)+'\n').encode())
    (output/'generator.py').write_bytes(generator)
    print('Symbolic C:',len(groups),'definitions;',sum(len(g['targets']) for g in groups),
          'addresses;',len(symbols),'external symbols')
    return jobs


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project',type=Path,default=leaf.DEFAULT_PROJECT)
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/c_reloc')
    args=parser.parse_args()
    prepare(args.project,args.output)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
