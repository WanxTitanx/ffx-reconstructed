"""Build a modified FFX image from validated source objects and fresh C/C++ COFF.

The original executable is never an input. Unchanged bytes are assembled and
linked from the same sources as the strict baseline. Replacement references are
resolved through actual COFF records; no runtime installation is needed.
"""
import argparse
import csv
import gzip
import io
import json
from pathlib import Path
import sys

from iced_x86 import Decoder, FlowControl
import coff_relocations as coff
import definitive_match as exact
import leaf_build as support
import mod_compile
import mod_admission
import mod_boundaries
import mod_io
import mod_layout
import mod_objects
import pe_data_verify
import pe_headers
import pe_link
import pe_structure
import text_build
import text_program
import x86_source

ROOT = Path(__file__).resolve().parents[2]


def check_changes(baseline, candidate, allowed):
    if len(candidate) < len(baseline):
        raise ValueError('modified image unexpectedly shrank')
    permitted = bytearray(len(candidate))
    for at, size in allowed:
        if type(at) is not int or type(size) is not int or at < 0 or size < 0 or at + size > len(candidate):
            raise ValueError('invalid declared change region')
        permitted[at:at+size] = bytes([1]) * size
    differences, ranges, start = 0, [], None
    for at in range(len(candidate)):
        changed = at >= len(baseline) or candidate[at] != baseline[at]
        if changed:
            if not permitted[at]:
                raise ValueError('undeclared binary difference at file offset %#x' % at)
            differences += 1
            if start is None:
                start = at
        elif start is not None:
            ranges.append({'offset': start, 'size': at-start})
            start = None
    if start is not None:
        ranges.append({'offset': start, 'size': len(candidate)-start})
    return {'different_bytes': differences, 'added_bytes': len(candidate)-len(baseline),
            'ranges': ranges}


def baseline_sources(root):
    header_path = root / 'recon/ffx/pe_headers/source.json.gz'
    header_data = header_path.read_bytes()
    model = support.parse_json(gzip.decompress(header_data), 'PE source')
    layout = pe_headers.native_layout(model)
    tplan, tmanifest, objects, observed = pe_link.load_text(root, model, header_data)
    dplan, _, dobjects, inputs = pe_data_verify.read_bundle(root / 'recon/ffx/pe_data')
    observed.update(inputs)
    observed[header_path] = header_data
    if dplan['target_sha256'] != exact.EXE_SHA256 or set(objects) & set(dobjects):
        raise ValueError('data objects disagree with baseline ownership')
    objects.update(dobjects)
    chunks = [dict(c, original_section='.text', zero_storage=False) for c in tplan['chunks']] + dplan['chunks']
    support.check_ranges([(c['va'], c['size']) for c in chunks], 'source objects')
    pe_link.validate_zero_storage(layout, chunks)
    bindings = {}
    for chunk in chunks:
        pe_link.chunk_offset(layout, chunk['original_section'], chunk['va'], chunk['size'], chunk['zero_storage'])
        for name, va in pe_link.definitions(objects[chunk['section']], chunk['section'], chunk['va'], chunk['size']).items():
            if name in bindings:
                raise ValueError('duplicated baseline definition')
            bindings[name] = va
    declared = text_build.layout_bindings(tplan['symbols'], layout)
    for symbol in tplan['symbols']:
        name = symbol['name']
        if symbol['owner'] in ('headers', '.reloc'):
            if name in bindings:
                raise ValueError('header symbol has multiple owners')
            bindings[name] = declared[name]
        elif bindings.get(name) != declared[name]:
            raise ValueError('missing baseline definition: ' + name)
    fragments = [(0, pe_headers.emit_headers(model), 'headers')]
    highlow = []
    for chunk in chunks:
        section = next(s for s in objects[chunk['section']]['sections'] if s['name'] == chunk['section'])
        if chunk['zero_storage']:
            if section['raw'] or section['relocations'] or not section['characteristics'] & 0x80:
                raise ValueError('invalid baseline zero storage')
            continue
        raw, _ = coff.relocate(section, chunk['va'], bindings, layout['image_base'])
        if len(raw) != chunk['size'] or support.digest(raw) != chunk['reference_sha256']:
            raise ValueError('baseline source object is not exact: ' + chunk['section'])
        offset = pe_link.chunk_offset(layout, chunk['original_section'], chunk['va'], chunk['size'])
        fragments.append((offset, raw, chunk['section']))
        highlow.extend(chunk['va']+r['offset'] for r in section['relocations'] if r['type'] == coff.DIR32)
    reloc = next(s for s in layout['sections'] if s['name'] == '.reloc')
    fragments.append((reloc['raw_offset'], pe_headers.emit_base_relocations(model, highlow), '.reloc'))
    baseline = pe_link.place_file(layout['file_size'], fragments)
    if support.digest(baseline) != exact.EXE_SHA256:
        raise ValueError('source-built baseline is not literally exact')
    return model, layout, tplan, chunks, objects, bindings, baseline, highlow, observed


def replacement_plan(root, recipe, exported, obj, baseline, layout, bindings, observed):
    if not recipe['replacements']:
        raise ValueError('declare at least one function replacement')
    selected = {}
    for item in recipe['replacements']:
        if not isinstance(item, dict) or set(item) != {'symbol', 'target'}:
            raise ValueError('replacement must name an original symbol and compiled target')
        symbol, target = item['symbol'], item['target']
        if not text_program.re_symbol(symbol) or symbol not in bindings or target not in exported:
            raise ValueError('replacement symbol or compiled target is missing')
        va = bindings[symbol]
        if va in selected or va == layout['image_base'] + layout['entry_rva']:
            raise ValueError('duplicate replacement or unsupported PE entry-point replacement')
        functions = [s for s in obj['symbols'].values()
                     if s['name'] == target and s['storage'] == 2 and s['section'] > 0 and s['type'] & 0x20]
        if len(functions) != 1:
            raise ValueError('replacement target is not a compiled function')
        section = obj['sections'][functions[0]['section']-1]
        if not section['characteristics'] & 0x20 or functions[0]['value'] >= section['raw_size']:
            raise ValueError('replacement target is outside compiled code')
        selected[va] = dict(item, va=va, new_va=exported[target])
    rows = mod_boundaries.load_inventory(root, observed)
    for va, item in selected.items():
        parts = [r for r in rows if int(r['function_start'], 16) == va]
        if len(parts) != 1 or parts[0]['kind'] != 'entry' or int(parts[0]['start'], 16) != va:
            raise ValueError('replacement needs a single proven function extent')
        row = parts[0]
        size = int(row['size'])
        if size <= 0 or int(row['end'], 16) != va + size or int(row['readable_bytes']) != size:
            raise ValueError('invalid native function extent')
        offset = pe_link.chunk_offset(layout, '.text', va, size)
        if support.digest(baseline[offset:offset+size]) != row['db_sha256']:
            raise ValueError('function boundary hash differs from the exact source baseline')
        if any(int(r['function_start'], 16) != va and int(r['start'], 16) < va+size
               and int(r['end'], 16) > va for r in rows):
            raise ValueError('replacement overlaps another function or shared tail')
        item.update(size=size, original_sha256=row['db_sha256'], file_offset=offset)
    result = sorted(selected.values(), key=lambda r: r['va'])
    support.check_ranges([(r['va'], r['size']) for r in result], 'replacements')
    return result


def source_entry_guards(root, plan, replacements, bindings, objects):
    """Reject incoming references that the object linker cannot safely redirect."""
    starts = {r['va'] for r in replacements}
    seen, may_fallthrough = set(), False
    terminating = {FlowControl.RETURN, FlowControl.UNCONDITIONAL_BRANCH,
                   FlowControl.INDIRECT_BRANCH, FlowControl.EXCEPTION}
    for chunk in plan['chunks']:
        raw = (root/'recon/ffx/text_program'/chunk['source']).read_bytes()
        records = [json.loads(line) for line in gzip.decompress(raw).splitlines()]
        mod_objects.check_instruction_references(records, bindings, replacements)
        section = next(s for s in objects[chunk['section']]['sections'] if s['name'] == chunk['section'])
        fixup_sites = {chunk['va']+r['offset'] for r in section['relocations'] if r['type']}
        for record in records:
            ip, size = text_program.position(record)
            if ip in starts:
                if may_fallthrough:
                    raise ValueError('function has an unrelocatable fallthrough predecessor at %#x' % ip)
                seen.add(ip)
            kind = record['kind']
            if kind == 'padding':
                if record['value'] == 0xcc:
                    may_fallthrough = False
            elif kind in ('instruction', 'coff'):
                at = ip-chunk['va']
                decoder = Decoder(32, section['raw'][at:at+size], ip=ip)
                instructions = list(decoder)
                if not instructions or any(i.is_invalid for i in instructions):
                    raise ValueError('source instruction boundary is not decodable')
                if kind == 'coff':
                    for decoded in instructions:
                        offsets = decoder.get_constant_offsets(decoded)
                        description = x86_source.describe(decoded, offsets)
                        # A decoded branch needs an actual COFF operand fixup.
                        for operand in description['operands']:
                            if operand['kind'].startswith('NEAR_BRANCH'):
                                operand['target'] = decoded.near_branch_target
                            elif operand['kind'].startswith('FAR_BRANCH'):
                                operand['target'] = (decoded.far_branch16
                                    if operand['kind'] == 'FAR_BRANCH16' else decoded.far_branch32)
                        relocated = set()
                        if decoded.ip+offsets.displacement_offset in fixup_sites and offsets.displacement_size == 4:
                            relocated.add('memory')
                        if decoded.ip+offsets.immediate_offset in fixup_sites and offsets.immediate_size == 4:
                            relocated.update('operand:'+str(index) for index, operand in enumerate(description['operands'])
                                             if operand['kind'].startswith(('IMMEDIATE', 'NEAR_BRANCH', 'FAR_BRANCH')))
                        mod_objects.check_numeric_fields(description, replacements, relocated)
                may_fallthrough = instructions[-1].flow_control not in terminating
    if seen != starts:
        raise ValueError('replacement does not start at an explicit source record')


def output_guard(root, package, output):
    output = mod_io.validate_directory(output)
    root, package = root.resolve(), package.resolve()
    protected = [root/'recon/ffx'/name for name in
                 ('complete', 'pe_headers', 'pe_data', 'text_program', 'c_leaf', 'c_reloc', 'byteproof')]
    if (output == root or output in root.parents or output == package or output in package.parents
            or package in output.parents
            or any(output == p or p in output.parents for p in protected)
            or output/'FFX.exe' == Path(exact.EXE_DEFAULT).resolve()):
        raise ValueError('output must be separate from baseline, original and source packages')


def build(root, package, output):
    output_guard(root, package, output)
    root, package, output = root.resolve(), package.resolve(), output.resolve()
    output_guard(root, package, output)
    output.mkdir(parents=True, exist_ok=True)
    for name in ('manifest.json', 'proof.json'):
        mod_io.unlink(output/name, missing_ok=True)
    tools = pe_link.tool_inputs()
    recipe, obj, mod_inputs, compiler_receipt = mod_compile.compile_package(package, output/'compiler')
    print('Fresh modification object:', compiler_receipt['object_sha256'], flush=True)
    model, layout, tplan, chunks, objects, bindings, baseline, old_sites, observed = baseline_sources(root)
    observed.update(mod_inputs)
    observed.update(tools)
    print('Source baseline exact:', support.digest(baseline), flush=True)
    admission = mod_admission.validate_ir(obj.get('llvm_ir'), layout)
    if admission['ir_sha256'] != compiler_receipt['ir_sha256']:
        raise ValueError('compiled IR differs from its fresh receipt')
    sizes, entries = mod_objects.allocate(obj)
    provisional = mod_layout.extend_model(model, sizes, old_sites)
    extension = pe_headers.native_layout(provisional)
    group_addresses = {s['name']: layout['image_base']+s['virtual_address']
                       for s in extension['sections'] if s['name'] in sizes}
    addresses, exported = mod_objects.symbols(obj, entries, group_addresses, recipe['bindings'], bindings)
    replacements = replacement_plan(root, recipe, exported, obj, baseline, layout, bindings, observed)
    source_entry_guards(root, tplan, replacements, bindings, objects)
    contents, new_sites, module_records = mod_objects.emit_module(obj, sizes, entries,
        group_addresses, addresses, layout['image_base'])
    fragments, changes, section_records, highlow = [], [], [], []
    for chunk in chunks:
        if chunk['zero_storage']:
            continue
        name = chunk['section']
        section = next(s for s in objects[name]['sections'] if s['name'] == name)
        raw, references, sites = mod_objects.relink(section, chunk['va'], bindings, replacements, layout['image_base'])
        offset = pe_link.chunk_offset(layout, chunk['original_section'], chunk['va'], chunk['size'])
        fragments.append((offset, raw, name))
        changes.extend(dict(r, file_offset=offset+r['site']-chunk['va']) for r in references)
        highlow.extend(sites)
        section_records.append({'owner': name, 'va': chunk['va'], 'file_offset': offset,
                                'size': len(raw), 'sha256': support.digest(raw)})
    for replacement in replacements:
        incoming = [r for r in changes if r['from'] == replacement['va']]
        if not incoming:
            raise ValueError('replacement has no statically linked incoming reference')
        replacement['incoming_references'] = len(incoming)
    highlow.extend(new_sites)
    final_model = mod_layout.extend_model(model, sizes, highlow)
    final_layout = pe_headers.native_layout(final_model)
    fragments.append((0, pe_headers.emit_headers(final_model), 'headers'))
    reloc = next(s for s in final_layout['sections'] if s['name'] == '.reloc')
    fragments.append((reloc['raw_offset'], pe_headers.emit_base_relocations(final_model, highlow), '.reloc'))
    for section in final_layout['sections']:
        if section['name'] not in contents:
            continue
        raw = contents[section['name']]
        if layout['image_base']+section['virtual_address'] != group_addresses[section['name']]:
            raise ValueError('module placement changed after relocation construction')
        fragments.append((section['raw_offset'], raw + bytes(section['raw_size']-len(raw)), section['name']))
    candidate = pe_link.place_file(final_layout['file_size'], fragments)
    parsed = pe_structure.parse_layout(candidate)
    if pe_structure.emit_nt_headers(parsed) != pe_structure.emit_nt_headers(final_layout):
        raise ValueError('modified PE fields failed independent roundtrip')
    imports = pe_structure.parse_imports(candidate, parsed)
    if imports != pe_structure.parse_imports(baseline, layout):
        raise ValueError('undeclared change to baseline imports')
    for item in replacements:
        at, size = item['file_offset'], item['size']
        if candidate[at:at+size] != baseline[at:at+size]:
            raise ValueError('original function body was changed instead of static reference linking')
    allowed = [(0, layout['optional_header']['size_of_headers']),
               (reloc['raw_offset'], reloc['raw_size']),
               (len(baseline), len(candidate)-len(baseline))]
    allowed.extend((r['file_offset'], 4) for r in changes)
    delta = check_changes(baseline, candidate, allowed)
    if not delta['different_bytes'] or support.digest(candidate) == exact.EXE_SHA256:
        raise ValueError('modification did not change the executable')
    support.check_unchanged(observed)
    if tools != pe_link.tool_inputs():
        raise ValueError('modification tools changed during compilation/linking')
    snapshots = output/'inputs'
    snapshots.mkdir(exist_ok=True)
    inputs = []
    for path, data in sorted(observed.items()):
        digest = support.digest(data)
        mod_io.write(snapshots/digest, data)
        inputs.append({'path': str(path), 'sha256': digest, 'snapshot': 'inputs/'+digest})
    manifest = {'schema_version': 1, 'kind': 'ffx-static-modification', 'status': 'complete',
        'name': recipe['name'], 'baseline_sha256': support.digest(baseline),
        'candidate': 'FFX.exe', 'candidate_sha256': support.digest(candidate), 'file_size': len(candidate),
        'reference_read_by_builder': False, 'original_executable_input': False, 'runtime_hooks': False,
        'masked_bytes': 0, 'original_bodies_preserved': True, 'inputs': inputs,
        'compiler': compiler_receipt, 'replacements': replacements, 'changed_references': changes,
        'module_symbols': exported, 'module_sections': module_records, 'module_admission': admission,
        'discarded_compiler_metadata': [{'name': s['name'], 'size': s['raw_size'],
            'sha256': support.digest(s['raw'])} for s in obj['sections']
            if s['raw_size'] and s['index'] not in entries],
        'highlow_sites': sorted(highlow), 'imports': imports, 'differences': delta,
        'placed_source_objects': section_records,
        'sections': [dict(s, name_bytes=s['name_bytes'].decode('latin-1'),
                         sha256=support.digest(candidate[s['raw_offset']:s['raw_offset']+s['raw_size']]))
                     for s in parsed['sections']]}
    support.check_unchanged(observed)
    mod_io.write(output/'FFX.exe.tmp', candidate)
    mod_io.replace(output/'FFX.exe.tmp', output/'FFX.exe')
    mod_io.write(output/'manifest.json.tmp', json.dumps(manifest, sort_keys=True, separators=(',', ':')) + chr(10))
    mod_io.replace(output/'manifest.json.tmp', output/'manifest.json')
    print('Static modification linked:', len(candidate), 'bytes;', len(changes), 'references;',
          support.digest(candidate), flush=True)
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--package', type=Path, default=ROOT/'recon/ffx/mods/compare_demo')
    parser.add_argument('--output', type=Path, default=ROOT/'recon/ffx/mods/build/compare_demo')
    parser.add_argument('--disable', action='store_true')
    args = parser.parse_args()
    output_guard(args.root, args.package, args.output)
    root, package, output = args.root.resolve(), args.package.resolve(), args.output.resolve()
    output_guard(root, package, output)
    if args.disable:
        import subprocess
        output.mkdir(parents=True, exist_ok=True)
        for name in ('manifest.json', 'proof.json'):
            mod_io.unlink(output/name, missing_ok=True)
        subprocess.run([sys.executable, str(root/'tools/match/run_source_only.py'),
                        str(root/'tools/match/rebuild_complete.py'), '--root', str(root),
                        '--output', str(output)], cwd=root, check=True)
    else:
        build(root, package, output)


if __name__ == '__main__':
    main()
