"""Admit whole, freshly compiled C/C++ functions into the existing source linker.

Normal load never opens the original executable. Reference comparison happens
only in verify; every ordinary load rechecks source receipts, native boundaries,
complete compiled sections, and the independently declared PE relocation sites.
"""
import copy
import gzip
import json
from pathlib import Path
import struct

import coff_relocations as coff
import leaf_build as support
import mod_boundaries
import pe_headers
import recovered_build as build


def select_section(obj, symbol_name, size):
    matches = [s for s in obj['symbols'].values() if s['name'] == symbol_name
               and s['storage'] == 2 and s['section'] > 0 and s['type'] & 0x20]
    if len(matches) != 1 or matches[0]['value'] != 0:
        raise ValueError('recovered symbol is missing, ambiguous, or an interior entry')
    symbol = matches[0]
    section = obj['sections'][symbol['section']-1]
    if (type(size) is not int or size <= 0 or not section['characteristics'] & 0x20
            or section['raw_size'] != size or len(section['raw']) != size):
        raise ValueError('recovered function must own its complete executable COFF section')
    others = [s for s in obj['symbols'].values() if s['section'] == symbol['section']
              and s['index'] != symbol['index'] and (s['type'] & 0x20 or s['storage'] == 2)]
    if others:
        raise ValueError('recovered section has another function or exported alias')
    # A section-definition auxiliary record, when present, must describe this
    # whole section. No arbitrary slice or associative COMDAT is admitted.
    for owner in obj['symbols'].values():
        if owner['section'] == symbol['section'] and owner['storage'] == 3 and owner['auxiliary']:
            aux = owner['auxiliary'][0]
            if len(aux) != 18 or struct.unpack_from('<I', aux)[0] != size or aux[14] == 5:
                raise ValueError('unsupported or inconsistent COFF section auxiliary record')
    return section


def resolve_section(section, va, bindings, expected_sha256, expected_highlow):
    used = {r['symbol_name'] for r in section['relocations'] if r['type'] != coff.ABSOLUTE}
    if (not isinstance(bindings, dict) or set(bindings) != used
            or any(not isinstance(name, str) or not build.SYMBOL.fullmatch(name) for name in bindings.values())):
        raise ValueError('every actual COFF reference needs one canonical binding, without extras')
    highlow = sorted(r['offset'] for r in section['relocations'] if r['type'] == coff.DIR32)
    if (not isinstance(expected_highlow, list) or any(type(x) is not int for x in expected_highlow)
            or highlow != expected_highlow):
        raise ValueError('compiled absolute pointer relocations differ from original HIGHLOW sites')
    addresses = {name: int(canonical[5:], 16) for name, canonical in bindings.items()}
    resolved, _ = coff.relocate(section, va, addresses)
    if not support.is_digest(expected_sha256) or support.digest(resolved) != expected_sha256:
        raise ValueError('compiled C/C++ body differs after actual COFF relocations')
    result = copy.deepcopy(section)
    for relocation in result['relocations']:
        if relocation['type'] != coff.ABSOLUTE:
            relocation['symbol_name'] = bindings[relocation['symbol_name']]
    # Original object bytes and in-place addends are never rewritten. Only the
    # symbol identity exposed to the final linker changes to a canonical name.
    if result['raw'] != section['raw']:
        raise AssertionError('compiler bytes changed during canonical symbol binding')
    return result


def native_owners(root, functions, observed):
    rows = mod_boundaries.load_inventory(root, observed)
    owners = {}
    for item in functions:
        va, size = item['va'], item['size']
        parts = [r for r in rows if int(r['function_start'], 16) == va]
        if (len(parts) != 1 or parts[0]['kind'] != 'entry' or int(parts[0]['start'], 16) != va
                or int(parts[0]['end'], 16) != va+size or int(parts[0]['size']) != size):
            raise ValueError('recovered function lacks a single complete native extent')
        if any(int(r['function_start'], 16) != va and int(r['start'], 16) < va+size
               and int(r['end'], 16) > va for r in rows):
            raise ValueError('recovered function overlaps a shared tail or another owner')
        owners[va] = parts[0]
    return owners


def header_sites(root, observed):
    name = Path(root)/'recon/ffx/pe_headers/source.json.gz'
    raw = build.regular(name, root)
    observed[name.resolve()] = raw
    model = support.parse_json(gzip.decompress(raw), 'PE header source')
    _, sites = pe_headers._emit_relocations(model, None)
    return sites, support.digest(raw)


def derive(root, module_id, directory, observed):
    module, recipe, receipt, obj = build.read_receipt(root, module_id, directory, observed)
    owners = native_owners(root, module['functions'], observed)
    sites, header_hash = header_sites(root, observed)
    selected = {item['va']: select_section(obj, item['symbol'], item['size']) for item in module['functions']}
    section_owners = {selected[item['va']]['index']: item for item in module['functions']}
    if len(section_owners) != len(selected):
        raise ValueError('two recovered functions select the same compiler section')
    result, records = {}, []
    receipt_hash = support.digest(observed[Path(directory).resolve()/'compile.json'])
    for item in module['functions']:
        va, section = item['va'], selected[item['va']]
        native = owners[va]
        folder = Path(root)/'recon/ffx/recovered'
        contract_raw = build.read_file(folder, item['contract'], observed)
        contract = support.parse_json(contract_raw, 'function ABI contract')
        if (contract.get('schema_version') != 1 or contract.get('va') != va
                or contract.get('size') != item['size'] or contract.get('symbol') != item['symbol']
                or not isinstance(contract.get('abi'), str) or not contract['abi']
                or contract.get('reference_sha256') != native['db_sha256']):
            raise ValueError('ABI contract does not name the exact original function')
        mapping, external = {}, set()
        for relocation in section['relocations']:
            if relocation['type'] == coff.ABSOLUTE:
                continue
            symbol = obj['symbols'][relocation['symbol_index']]
            name = symbol['name']
            if symbol['section'] > 0:
                owner = section_owners.get(symbol['section'])
                if owner is None or not 0 <= symbol['value'] < owner['size']:
                    raise ValueError('compiled dependency requires a separately recovered whole owner: '+name)
                mapping[name] = '_sym_%08x' % (owner['va']+symbol['value'])
            elif symbol['section'] == 0 and symbol['value'] == 0 and symbol['storage'] == 2:
                external.add(name)
                if name not in item['bindings']:
                    raise ValueError('unbound compiler external symbol: '+name)
                mapping[name] = item['bindings'][name]
            else:
                raise ValueError('unsupported absolute/common/weak compiler symbol')
        if external != set(item['bindings']):
            raise ValueError('unused or non-external recovered function binding')
        highlow = sorted(site-va for site in sites if va <= site < va+item['size'])
        canonical = resolve_section(section, va, mapping, native['db_sha256'], highlow)
        result[va] = {'key': 'c_recovered:%s:%08x' % (module_id, va), 'family': 'c_recovered',
                      'language': recipe['language'], 'va': va, 'size': item['size'],
                      'section': canonical, 'sha256': native['db_sha256'],
                      'build_manifest_sha256': receipt_hash}
        records.append({'va': va, 'size': item['size'], 'symbol': item['symbol'],
                        'section_index': section['index'], 'section_name': section['name'],
                        'section_raw_sha256': support.digest(section['raw']),
                        'linked_sha256': native['db_sha256'], 'highlow_offsets': highlow,
                        'bindings': mapping, 'contract_sha256': support.digest(contract_raw)})
    evidence = {'schema_version': 1, 'kind': 'recovered-compiled-function-proof',
                'target_sha256': build.TARGET, 'module_id': module_id, 'language': recipe['language'],
                'build_receipt_sha256': receipt_hash, 'build_id': receipt['build_id'],
                'stage_sha256': receipt['stage_sha256'], 'object_sha256': receipt['outputs']['module.obj'],
                'header_source_sha256': header_hash, 'functions': records,
                'masked_bytes': 0, 'compiler_instruction_patches': 0,
                'whole_executable_verified': False}
    return result, evidence


def entry_evidence(root, functions, reference, sections, observed):
    """Check static incoming references against the original typed code map."""
    from iced_x86 import Decoder, FlowControl, OpKind
    import definitive_match as exact
    import leaf_reconstruct
    import text_program
    read = exact.va_reader(reference, sections)
    sites = leaf_reconstruct.pe_relocations(reference, sections)
    start = next(s[1] for s in sections if s[0] == '.text')
    size = next(s[4] for s in sections if s[0] == '.text')
    runs, inputs = text_program.native_runs(root, start, start+size, sites)
    observed.update(inputs)
    counts = {f['va']: {'direct_entries': 0, 'pointer_entries': 0, 'interior_entries': 0,
                         'short_incoming_branches': 0, 'fallthrough_entries': 0} for f in functions}
    terminating = {FlowControl.RETURN, FlowControl.UNCONDITIONAL_BRANCH,
                   FlowControl.INDIRECT_BRANCH, FlowControl.EXCEPTION}
    for a, b, kind in runs:
        if kind != 'code':
            continue
        decoder = Decoder(32, read(a, b-a), ip=a)
        for instruction in decoder:
            if instruction.is_invalid:
                raise ValueError('native code map contains an invalid instruction')
            for target in functions:
                va, end = target['va'], target['va']+target['size']
                if va <= instruction.ip < end:
                    continue
                if instruction.next_ip == va and instruction.flow_control not in terminating:
                    counts[va]['fallthrough_entries'] += 1
                if instruction.op_count and instruction.op0_kind in (OpKind.NEAR_BRANCH16, OpKind.NEAR_BRANCH32, OpKind.NEAR_BRANCH64):
                    dest = instruction.near_branch_target
                    if va <= dest < end:
                        counts[va]['direct_entries'] += 1
                        counts[va]['interior_entries'] += int(dest != va)
                        counts[va]['short_incoming_branches'] += int(decoder.get_constant_offsets(instruction).immediate_size != 4)
    for site in sites:
        target_va = struct.unpack('<I', read(site, 4))[0]
        for target in functions:
            va, end = target['va'], target['va']+target['size']
            if va <= target_va < end and not va <= site < end:
                counts[va]['pointer_entries'] += 1
                counts[va]['interior_entries'] += int(target_va != va)
    for va, count in counts.items():
        if count['interior_entries'] or count['short_incoming_branches'] or count['fallthrough_entries']:
            raise ValueError('recovered entry requires an inseparable group: %#x %s' % (va, count))
    return {str(va): record for va, record in sorted(counts.items())}


def verify(root, module_id, directory, proof_path):
    import definitive_match as exact
    import leaf_reconstruct
    root, directory, proof_path = Path(root).resolve(), Path(directory).resolve(), Path(proof_path).resolve()
    # This command produces only a per-function proof, not whole-image credit.
    proof_path.parent.mkdir(parents=True, exist_ok=True)
    proof_path.unlink(missing_ok=True)
    observed = {}
    providers, evidence = derive(root, module_id, directory, observed)
    reference, sections = exact.load_pe(exact.EXE_DEFAULT)
    if support.digest(reference) != build.TARGET or len(reference) != mod_boundaries.REFERENCE_SIZE:
        raise ValueError('reference executable is not the pinned target')
    read = exact.va_reader(reference, sections)
    highlow = leaf_reconstruct.pe_relocations(reference, sections)
    for item in evidence['functions']:
        va, size = item['va'], item['size']
        if support.digest(read(va, size)) != item['linked_sha256']:
            raise ValueError('native extent hash disagrees with the actual original body')
        if sorted(site-va for site in highlow if va <= site < va+size) != item['highlow_offsets']:
            raise ValueError('header declarations differ from actual original pointer relocations')
    evidence['entry_analysis'] = entry_evidence(root, evidence['functions'], reference, sections, observed)
    evidence['verifier_inputs'] = {str(path.relative_to(root)): support.digest(raw)
        for path, raw in observed.items() if path.parent == root/'tools/match'}
    own = Path(__file__).resolve()
    evidence['verifier_inputs'][str(own.relative_to(root))] = support.digest(own.read_bytes())
    support.check_unchanged(observed)
    proof_path.write_bytes(build.json_bytes(evidence))
    return evidence


def load(root, observed):
    registry = build.read_registry(root, observed)
    folder = Path(root)/'recon/ffx/recovered'
    result = {}
    for module in registry['modules']:
        if not module['enabled']:
            continue
        proof_raw = build.read_file(folder, module['proof'], observed)
        proof = support.parse_json(proof_raw, 'recovered function proof')
        candidates, evidence = derive(root, module['id'], folder/module['build_dir'], observed)
        if set(proof) != set(evidence) | {'entry_analysis', 'verifier_inputs'} or any(proof[k] != value for k, value in evidence.items()):
            raise ValueError('recovered function proof is stale or does not describe these compiler outputs')
        expected_keys = {str(item['va']) for item in evidence['functions']}
        if not isinstance(proof['entry_analysis'], dict) or set(proof['entry_analysis']) != expected_keys:
            raise ValueError('recovered entry analysis is incomplete')
        for count in proof['entry_analysis'].values():
            if (set(count) != {'direct_entries', 'pointer_entries', 'interior_entries', 'short_incoming_branches', 'fallthrough_entries'}
                    or any(type(x) is not int or x < 0 for x in count.values())
                    or any(count[k] for k in ('interior_entries', 'short_incoming_branches', 'fallthrough_entries'))):
                raise ValueError('recovered function has unsafe entry boundaries')
        if not isinstance(proof['verifier_inputs'], dict) or 'tools/match/recovered_providers.py' not in proof['verifier_inputs']:
            raise ValueError('recovered proof lacks its verifier identity')
        for path, expected in proof['verifier_inputs'].items():
            raw = build.read_file(root, path, observed)
            if support.digest(raw) != expected:
                raise ValueError('recovered verifier changed since the function proof')
        if result.keys() & candidates.keys():
            raise ValueError('recovered providers would overwrite another module')
        result.update(candidates)
    support.check_ranges([(p['va'], p['size']) for p in result.values()], 'recovered providers')
    return result
