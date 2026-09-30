"""Measure accepted executable coverage from its immutable build-input snapshots.

Historical reports describe their recorded build, not a later source checkout.
No catalog, unselected C file, or current registry can add emitted-code credit.
"""
import argparse
import bisect
import collections
import csv
import gzip
import hashlib
import io
import json
from pathlib import Path

import coff_relocations as coff
import complete_acceptance
import leaf_build as support
import pe_structure
import recovered_build
import recovered_providers
import text_program

C_FAMILIES = {'c_leaf', 'c_reloc', 'c_memcmp', 'c_recovered'}
COUNTERS = ('text_raw_bytes', 'partition_bytes', 'c_provider_bytes', 'c_instruction_bytes',
            'c_data_bytes', 'c_padding_bytes', 'c_unknown_bytes', 'assembly_instruction_bytes',
            'assembly_instructions', 'manual_assembly_bytes', 'manual_assembly_instances',
            'declared_data_bytes', 'declared_padding_bytes', 'c_instances', 'c_implementations')


def summarize(records, providers, runs, start, size):
    """Count a gap-free emitted partition and intersect C with the native map."""
    if type(start) is not int or type(size) is not int or size <= 0:
        raise ValueError('invalid executable coverage range')
    starts = [a for a, _, _ in runs]
    for index, (a, b, kind) in enumerate(runs):
        if b <= a or (index and a != runs[index-1][1]) or kind not in ('code', 'data', 'alignment', 'unknown', 'mixeddata'):
            raise ValueError('native classification is not a contiguous partition')
    values = dict.fromkeys(COUNTERS, 0)
    implementations = set()
    cursor = start
    for record in records:
        ip, length = text_program.position(record)
        if type(ip) is not int or type(length) is not int or length <= 0 or ip != cursor or ip+length > start+size:
            raise ValueError('emitted records overlap, repeat, or leave a gap')
        kind = record['kind']
        if kind == 'coff':
            provider = providers.get(ip)
            if provider is None or provider['va'] != ip or provider['size'] != length or provider['key'] != record['provider']:
                raise ValueError('compiled bytes have no matching selected provider')
            family = provider['family']
            if family in C_FAMILIES:
                values['c_provider_bytes'] += length
                values['c_instances'] += 1
                implementations.add(provider['implementation'])
                at, index = ip, bisect.bisect_right(starts, ip)-1
                while at < ip+length:
                    if index < 0 or index >= len(runs) or not runs[index][0] <= at < runs[index][1]:
                        raise ValueError('native classification does not own the complete C range')
                    stop = min(ip+length, runs[index][1])
                    category = {'code': 'instruction', 'data': 'data', 'mixeddata': 'data',
                                'alignment': 'padding', 'unknown': 'unknown'}[runs[index][2]]
                    values['c_'+category+'_bytes'] += stop-at
                    at, index = stop, index+1
            elif family == 'asm_mcwl':
                values['manual_assembly_bytes'] += length
                values['manual_assembly_instances'] += 1
            else:
                raise ValueError('unrecognized compiled-source family')
        elif kind == 'instruction':
            values['assembly_instruction_bytes'] += length
            values['assembly_instructions'] += 1
        elif kind in ('padding', 'data'):
            values['declared_'+kind+'_bytes'] += length
        else:
            raise ValueError('unknown emitted record kind')
        cursor += length
    if cursor != start+size:
        raise ValueError('emitted records do not cover the executable section')
    values['text_raw_bytes'] = size
    values['partition_bytes'] = sum(values[key] for key in ('c_provider_bytes', 'manual_assembly_bytes',
        'assembly_instruction_bytes', 'declared_data_bytes', 'declared_padding_bytes'))
    values['c_implementations'] = len(implementations)
    if values['partition_bytes'] != size:
        raise ValueError('coverage categories do not sum to the raw executable section')
    return values


class Snapshots:
    def __init__(self, root, directory, manifest):
        self.directory = directory
        self.entries = {}
        paths = set()
        for entry in manifest['inputs']:
            path = Path(entry['path'])
            if not path.is_absolute() or str(path) in paths or entry['snapshot'] != 'inputs/'+entry['sha256']:
                raise ValueError('ambiguous or redirected build input')
            paths.add(str(path))
            snapshot = directory/entry['snapshot']
            if snapshot.is_symlink() or not support.is_digest(entry['sha256']):
                raise ValueError('invalid retained input')
            with snapshot.open('rb') as stream:
                if hashlib.file_digest(stream, 'sha256').hexdigest() != entry['sha256']:
                    raise ValueError('retained input hash differs: '+str(path))
            if path.is_relative_to(root):
                self.entries[path.relative_to(root).as_posix()] = entry

    def read(self, relative):
        if relative not in self.entries:
            raise ValueError('required build input was not recorded: '+relative)
        entry = self.entries[relative]
        raw = (self.directory/entry['snapshot']).read_bytes()
        if support.digest(raw) != entry['sha256']:
            raise ValueError('retained input changed while measuring')
        return raw

    def json(self, name, compressed=False):
        raw = self.read(name)
        return support.parse_json(gzip.decompress(raw) if compressed else raw, name)


def native_partition(inputs, start, size):
    metadata = inputs.json('recon/ffx/analysis_map/metadata.json')
    raw = inputs.read('recon/ffx/analysis_map/text_items.tsv.gz')
    if support.digest(raw) != metadata['tables']['text_items.tsv.gz']['sha256']:
        raise ValueError('native classification receipt differs')
    runs, cursor, rows = [], start, 0
    with gzip.open(io.BytesIO(raw), 'rt', encoding='utf-8', newline='') as stream:
        for row in csv.DictReader(stream, delimiter='\t'):
            rows += 1
            a, b = int(row['start'], 16), min(int(row['end'], 16), start+size)
            if a >= start+size:
                continue
            kind = 'data' if row['kind'] == 'string' else row['kind']
            if a != cursor or b <= a:
                raise ValueError('native coverage map has a gap')
            if runs and runs[-1][2] == kind:
                runs[-1] = (runs[-1][0], b, kind)
            else:
                runs.append((a, b, kind))
            cursor = b
    if cursor != start+size or rows != metadata['tables']['text_items.tsv.gz']['rows']:
        raise ValueError('native coverage map is incomplete')
    return runs


def validate_evidence(root, directory, manifest_raw, manifest, image, proof):
    """Revalidate both retained audits; proof booleans alone confer no credit."""
    reference = Path(complete_acceptance.exact.EXE_DEFAULT)
    facts, _ = complete_acceptance.validate_audit(directory, reference, manifest_raw, image, root=root)
    if proof.get('source_only_audit') != facts:
        raise ValueError('coverage proof belongs to another source-build audit')
    replay = proof.get('independent_source_link_replay', {})
    if (replay.get('replay_manifest_sha256') != support.digest(manifest_raw)
            or replay.get('replay_candidate_sha256') != support.digest(image)):
        raise ValueError('coverage replay belongs to another manifest or executable')
    packed = (directory/'acceptance/relink.trace.gz').read_bytes()
    log = (directory/'acceptance/relink.log').read_bytes()
    if (support.digest(packed) != replay.get('trace_compressed_sha256')
            or support.digest(log) != replay.get('log_sha256')
            or replay.get('source_link_replayed') is not True
            or replay.get('manifest_exactly_reproduced') is not True):
        raise ValueError('coverage replay evidence is incomplete or changed')
    trace = gzip.decompress(packed)
    replay_facts = complete_acceptance.trace_facts(trace, [reference, directory/'FFX.exe'])
    command = replay.get('command')
    if not isinstance(command, list) or '--output' not in command or command.index('--output')+1 >= len(command):
        raise ValueError('coverage replay has no exact output directory')
    output = Path(command[command.index('--output')+1])
    binding = complete_acceptance.validate_trace_binding(trace, manifest, output, command, link_only=True, root=root)
    if any(replay.get(key) != value for key, value in {**replay_facts, **binding}.items()):
        raise ValueError('coverage replay facts do not match the recorded proof')
    return {'source_only_audit_sha256': facts['source_only_audit_sha256'],
            'source_input_opens': facts['input_opens_verified'],
            'replay_trace_sha256': replay_facts['trace_sha256'],
            'replay_input_opens': binding['input_opens_verified'],
            'source_build_and_replay_audits_revalidated': True}


def measure(root, image_dir, before=None):
    root, directory = Path(root).resolve(), Path(image_dir).resolve()
    manifest_raw = (directory/'manifest.json').read_bytes()
    manifest = support.parse_json(manifest_raw, 'complete image manifest')
    proof = support.parse_json((directory/'proof.json').read_bytes(), 'complete image proof')
    image = (directory/'FFX.exe').read_bytes()
    complete_acceptance.validate_manifest(manifest, image)
    required = {'literal_equal': True, 'different_bytes': 0, 'masked_bytes': 0,
                'raw_code_blob_fallbacks': 0, 'source_backed_link_verified': True,
                'candidate_size': len(image), 'candidate_sha256': support.digest(image),
                'manifest_sha256': support.digest(manifest_raw)}
    if len(image) != 10675712 or support.digest(image) != recovered_build.TARGET or any(proof.get(k) != v for k, v in required.items()):
        raise ValueError('coverage needs a complete accepted vanilla image')
    evidence = validate_evidence(root, directory, manifest_raw, manifest, image, proof)
    inputs = Snapshots(root, directory, manifest)
    plan = inputs.json('recon/ffx/text_program/plan.json.gz', compressed=True)
    build = inputs.json('recon/ffx/text_program/build/manifest.json')
    if build['source_plan_sha256'] != support.digest(inputs.read('recon/ffx/text_program/plan.json.gz')):
        raise ValueError('emitted objects do not belong to the prepared source plan')
    start, size = plan['text_va'], plan['text_raw_size']
    layout = pe_structure.parse_layout(image)
    section = next(s for s in layout['sections'] if s['name'] == '.text')
    if section['raw_size'] != size or section['raw_offset'] != plan['text_raw_offset']:
        raise ValueError('source coverage does not describe the actual PE section')
    providers, recovered = {}, []
    registry = inputs.json('recon/ffx/recovered/registry.json') if 'recon/ffx/recovered/registry.json' in inputs.entries else {'modules': []}
    for source in plan['providers']:
        p = dict(source)
        va, length = p['va'], p['size']
        if va in providers or not start <= va < va+length <= start+size:
            raise ValueError('duplicate or invalid selected provider')
        at = section['raw_offset']+va-start
        if support.digest(image[at:at+length]) != p['sha256']:
            raise ValueError('final executable does not contain the claimed provider body')
        if p['family'] == 'c_recovered':
            module_id = p['key'].split(':')[1]
            modules = [m for m in registry['modules'] if m['id'] == module_id and m['enabled']]
            if len(modules) != 1:
                raise ValueError('emitted recovered module is not enabled in its captured registry')
            module = modules[0]
            prefix = 'recon/ffx/recovered/'+module['build_dir']+'/'
            receipt_raw = inputs.read(prefix+'compile.json')
            receipt = support.parse_json(receipt_raw, 'compiler receipt')
            body_proof = inputs.json('recon/ffx/recovered/'+module['proof'])
            records = [f for f in body_proof['functions'] if f['va'] == va and f['size'] == length]
            if len(records) != 1 or support.digest(receipt_raw) != p['build_manifest_sha256'] or body_proof['build_receipt_sha256'] != p['build_manifest_sha256']:
                raise ValueError('recovered object has no matching fresh-build proof')
            record = records[0]
            obj_raw = inputs.read(prefix+'module.obj')
            if support.digest(obj_raw) != receipt['outputs']['module.obj']:
                raise ValueError('retained compiler object differs')
            selected = recovered_providers.select_section(coff.parse_coff(obj_raw), record['symbol'], length)
            canonical = recovered_providers.resolve_section(selected, va, record['bindings'], p['sha256'], record['highlow_offsets'])
            linked, _ = coff.relocate(canonical, va, {name: int(name[5:], 16) for name in record['bindings'].values()})
            if linked != image[at:at+length]:
                raise ValueError('compiler object did not provide the final image range')
            recipe = inputs.json('recon/ffx/recovered/'+module['recipe'])
            source_name = recipe['source']
            source_hash = support.digest(inputs.read('recon/ffx/recovered/'+source_name))
            p['implementation'] = source_hash+':'+record['symbol']
            recovered.append({'va': va, 'size': length, 'module': module_id, 'language': module['language'],
                'source': source_name, 'source_sha256': source_hash, 'symbol': record['symbol'],
                'build_id': receipt['build_id'], 'build_receipt_sha256': p['build_manifest_sha256'],
                'object_sha256': support.digest(obj_raw), 'section_index': selected['index'],
                'file_offset': at, 'emitted_sha256': p['sha256']})
        else:
            parts = p['key'].split(':')
            p['implementation'] = ':'.join([parts[0], *parts[2:]]) if len(parts) >= 3 else p['key']
        providers[va] = p
    support.check_ranges([(p['va'], p['size']) for p in providers.values()], 'coverage providers')
    def records():
        for chunk in plan['chunks']:
            raw = inputs.read('recon/ffx/text_program/'+chunk['source'])
            if support.digest(raw) != chunk['source_sha256']:
                raise ValueError('emitted source chunk differs from its plan')
            with gzip.open(io.BytesIO(raw), 'rt', encoding='utf-8') as stream:
                for line in stream:
                    yield json.loads(line)
    counts = summarize(records(), providers, native_partition(inputs, start, size), start, size)
    expected_stats = {'c_bytes': counts['c_provider_bytes'], 'instruction_bytes': counts['assembly_instruction_bytes'],
        'instructions': counts['assembly_instructions'], 'external_assembly_bytes': counts['manual_assembly_bytes'],
        'padding_bytes': counts['declared_padding_bytes'], 'data_bytes': counts['declared_data_bytes'],
        'compiled_providers': counts['c_instances']+counts['manual_assembly_instances']}
    if expected_stats != manifest['text_stats'] or expected_stats != build['stats'] or expected_stats['compiled_providers'] != len(providers):
        raise ValueError('measured emitted partition disagrees with the final build')
    result = {'schema_version': 1, 'image_dir': str(directory), 'target_sha256': recovered_build.TARGET,
        'image_sha256': support.digest(image), 'manifest_sha256': support.digest(manifest_raw),
        'proof_sha256': support.digest((directory/'proof.json').read_bytes()),
        'source_plan_sha256': support.digest(inputs.read('recon/ffx/text_program/plan.json.gz')),
        'classification_sha256': support.digest(inputs.read('recon/ffx/analysis_map/text_items.tsv.gz')),
        'input_snapshots_verified': len(manifest['inputs']), 'counts': counts,
        'audits': evidence,
        'recovered_functions': recovered, 'binary_library_code_credit': 0,
        'scope': 'accepted executable and its immutable input snapshots; not current-source or gameplay validation'}
    if before is not None:
        previous = support.parse_json(Path(before).read_bytes(), 'previous coverage')
        if previous['target_sha256'] != result['target_sha256'] or previous['classification_sha256'] != result['classification_sha256']:
            raise ValueError('coverage delta changed the target or native classification')
        result['delta'] = {key: value-previous['counts'][key] for key, value in counts.items()}
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument('--image-dir', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--before', type=Path)
    args = parser.parse_args()
    result = measure(args.root, args.image_dir, args.before)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(recovered_build.json_bytes(result))
    print(json.dumps({'counts': result['counts'], 'delta': result.get('delta'),
                      'recovered_functions': result['recovered_functions']}, indent=2))


if __name__ == '__main__':
    main()
