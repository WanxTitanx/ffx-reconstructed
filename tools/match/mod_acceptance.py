"""Independently rebuild, trace and verify standalone FFX modifications."""
import argparse
import ast
import contextlib
import gzip
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

import complete_acceptance as common
import definitive_match as exact
import leaf_build as support
import mod_link
import mod_io
import pe_structure
import verify_complete_image as complete

ROOT = Path(__file__).resolve().parents[2]
FIELDS = set(('schema_version kind status name baseline_sha256 candidate candidate_sha256 '
    'file_size reference_read_by_builder original_executable_input runtime_hooks masked_bytes '
    'original_bodies_preserved inputs compiler replacements changed_references module_symbols '
    'module_sections module_admission discarded_compiler_metadata highlow_sites imports differences '
    'placed_source_objects sections').split())
ENVIRONMENT = {'PATH': '/usr/bin:/bin', 'LANG': 'C.UTF-8', 'LC_ALL': 'C.UTF-8',
               'TZ': 'UTC', 'PYTHONNOUSERSITE': '1', 'PYTHONDONTWRITEBYTECODE': '1'}


def compare_replay(claimed, candidate, replay, rebuilt):
    if claimed != replay:
        raise ValueError('independent modification manifest differs')
    if candidate != rebuilt:
        raise ValueError('independent modification image differs')
    return True


def compare_compiler_outputs(left, right):
    for name, label in (('module.obj', 'object'), ('module.ll', 'IR')):
        if (left / name).read_bytes() != (right / name).read_bytes():
            raise ValueError('independent compiler ' + label + ' differs')
    return True


def validate_manifest(manifest, candidate):
    if not isinstance(manifest, dict) or set(manifest) != FIELDS:
        raise ValueError('modification manifest fields are incomplete or unsupported')
    if (type(manifest['schema_version']) is not int or manifest['schema_version'] != 1
            or manifest['kind'] != 'ffx-static-modification' or manifest['status'] != 'complete'
            or manifest['baseline_sha256'] != exact.EXE_SHA256 or manifest['candidate'] != 'FFX.exe'
            or manifest['candidate_sha256'] != support.digest(candidate)
            or manifest['candidate_sha256'] == exact.EXE_SHA256
            or type(manifest['file_size']) is not int or manifest['file_size'] != len(candidate)):
        raise ValueError('modification does not match its manifest')
    for field in ('reference_read_by_builder', 'original_executable_input', 'runtime_hooks'):
        if manifest[field] is not False:
            raise ValueError('modification manifest permits ' + field)
    if (type(manifest['masked_bytes']) is not int or manifest['masked_bytes'] != 0
            or manifest['original_bodies_preserved'] is not True
            or not manifest['replacements'] or not manifest['changed_references']):
        raise ValueError('modification does not prove static reference replacement')


def bind_trace(raw, manifest, output, runtime):
    reads, writes, compiler_reads, compiler_writes = set(), set(), set(), set()
    ir_reads, ir_writes, ir_pids = set(), set(), set()
    runtime_pid, compiler_pids = None, set()
    lines = list(common.completed_trace_lines(raw))
    compiler_command = manifest['compiler']['command']
    ir_command = manifest['compiler']['ir_command']
    for line in lines:
        words = [ast.literal_eval(word) for word in common.QUOTED.findall(line)]
        if re.search(r'\bexecve\(', line) and re.search(r'=\s*0\s*$', line):
            pid = int(common.PID.match(line)[1])
            if words == [runtime[0], *runtime]:
                runtime_pid = pid
            if words == [compiler_command[0], *compiler_command]:
                compiler_pids.add(pid)
            if words == [ir_command[0], *ir_command]:
                ir_pids.add(pid)
    if runtime_pid is None or not compiler_pids or not ir_pids:
        raise ValueError('trace lacks the exact build, compiler or IR execution')
    for line in lines:
        opened = common.OPEN_CALL.match(line)
        if not opened or not re.search(r'=\s*\d+(?:<[^>]*>)?\s*$', line):
            continue
        descriptor = re.search(r'=\s*\d+<([^>]*)>\s*$', line)
        if descriptor is None or not Path(descriptor[1]).is_absolute():
            continue
        path = Path(descriptor[1]).resolve()
        pid = int(opened[1])
        if 'O_RDONLY' in line or 'O_RDWR' in line:
            reads.add(path)
            if pid in compiler_pids:
                compiler_reads.add(path)
            if pid in ir_pids:
                ir_reads.add(path)
        if 'O_WRONLY' in line or 'O_RDWR' in line:
            writes.add(path)
            if pid in compiler_pids:
                compiler_writes.add(path)
            if pid in ir_pids:
                ir_writes.add(path)
    required = {Path(item['path']).resolve() for item in manifest['inputs']}
    if not required or required-reads:
        raise ValueError('trace is missing declared source reads')
    if {output/'FFX.exe.tmp', output/'manifest.json.tmp'}-writes:
        raise ValueError('trace does not show creation of the candidate and manifest')
    stages = {p.parent for p in compiler_writes if p.name == 'module.obj'
              and p.parent.name.startswith('.compile-') and p.parent.parent == output/'compiler'}
    if len(stages) != 1:
        raise ValueError('trace does not prove one fresh compiler object')
    stage = next(iter(stages))
    dependencies = {(stage/name).resolve() for name in manifest['compiler']['dependencies']}
    if not dependencies or dependencies-compiler_reads or stage/'module.obj' not in reads:
        raise ValueError('compiler input/object consumption is not proven by the trace')
    ir_dependencies = {(stage/name).resolve() for name in manifest['compiler']['ir_dependencies']}
    if (stage/'module.ll' not in ir_writes or stage/'module.ll' not in reads
            or not ir_dependencies or ir_dependencies-ir_reads):
        raise ValueError('fresh compiler IR creation/input consumption is not proven by the trace')
    libraries = {Path(name).resolve() for name in manifest['compiler']['runtime_libraries']}
    if libraries-compiler_reads or libraries-ir_reads:
        raise ValueError('runtime libraries were not consumed by both compiler invocations')
    return {'exact_build_exec_verified': True, 'exact_compiler_exec_verified': True,
            'fresh_object_created_and_read': True, 'source_inputs_opened': len(required),
            'compiler_dependencies_opened': len(dependencies), 'outputs_created': True,
            'exact_ir_exec_verified': True, 'fresh_ir_created_and_read': True,
            'runtime_libraries_opened': len(libraries)}


def traced_command(root, script, arguments, trace):
    tracer = shutil.which('strace')
    if tracer is None:
        raise ValueError('strace is required for modification acceptance')
    runtime = [sys.executable, str(root/'tools/match/run_source_only.py'),
               str(root/'tools/match'/script), *arguments]
    return [tracer, '-f', '-s', '4096', '-yy', '-e', 'trace=open,openat,openat2,execve',
            '-o', str(trace), *runtime], runtime


def build_once(root, package, output):
    mod_link.output_guard(root, package, output)
    output.mkdir(parents=True, exist_ok=True)
    trace, log = output/'build.trace', output/'build.log'
    command, runtime = traced_command(root, 'mod_link.py',
        ['--root', str(root), '--package', str(package), '--output', str(output)], trace)
    with log.open('wb') as stream:
        subprocess.run(command, cwd=root, env=ENVIRONMENT, stdout=stream,
                       stderr=subprocess.STDOUT, check=True, timeout=900)
    candidate = (output/'FFX.exe').read_bytes()
    manifest_data = (output/'manifest.json').read_bytes()
    manifest = support.parse_json(manifest_data, 'modification manifest')
    validate_manifest(manifest, candidate)
    observed = common.validate_inputs(manifest, output, Path(exact.EXE_DEFAULT))
    receipt = support.parse_json((output/'compiler/compile.json').read_bytes(), 'compiler receipt')
    if receipt != manifest['compiler'] or support.digest((output/'compiler/module.obj').read_bytes()) != receipt['object_sha256']:
        raise ValueError('fresh compiler object or receipt does not match the manifest')
    ir_data = (output/'compiler/module.ll').read_bytes()
    if (support.digest(ir_data) != receipt['ir_sha256']
            or manifest['module_admission']['ir_sha256'] != receipt['ir_sha256']):
        raise ValueError('fresh compiler IR does not match the typed pointer admission')
    for item in receipt['inputs']:
        if (output/'compiler'/item['snapshot']).read_bytes() != observed[Path(item['path'])]:
            raise ValueError('compiler source snapshot differs from the linked input')
    raw_trace = trace.read_bytes()
    facts = common.trace_facts(raw_trace, [Path(exact.EXE_DEFAULT), root/'recon/ffx/complete/FFX.exe', output/'FFX.exe'])
    binding = bind_trace(raw_trace, manifest, output, runtime)
    packed = gzip.compress(raw_trace, mtime=0)
    (output/'build.trace.gz').write_bytes(packed)
    audit = {'command': command, 'environment': ENVIRONMENT, **facts, **binding,
             'packed_trace_sha256': support.digest(packed), 'log_sha256': support.digest(log.read_bytes()),
             'candidate_sha256': support.digest(candidate), 'manifest_sha256': support.digest(manifest_data),
             'compiler_object_sha256': receipt['object_sha256'], 'compiler_ir_sha256': receipt['ir_sha256']}
    (output/'source_only_audit.json').write_text(json.dumps(audit, indent=2)+chr(10))
    support.check_unchanged(observed)
    return manifest, candidate, audit, observed


def verify_baseline(root, package, directory):
    mod_link.output_guard(root, package, directory)
    directory.mkdir(parents=True, exist_ok=True)
    for name in ('manifest.json', 'proof.json'):
        mod_io.unlink(directory/name, missing_ok=True)
    command, _ = traced_command(root, 'rebuild_complete.py',
        ['--root', str(root), '--output', str(directory)], directory/'build.trace')
    with (directory/'build.log').open('wb') as log:
        subprocess.run(command, cwd=root, env=ENVIRONMENT, stdout=log,
                       stderr=subprocess.STDOUT, check=True, timeout=900)
    reference = Path(exact.EXE_DEFAULT).resolve()
    common.record_audit(directory, reference, command)
    with (directory/'verify.log').open('w') as log, contextlib.redirect_stdout(log):
        proof = complete.verify(directory, reference, root)
    comparator = shutil.which('cmp')
    if comparator is None:
        raise ValueError('cmp is required for final whole-file baseline comparison')
    cmp_command = [comparator, '--silent', str(reference), str(directory/'FFX.exe')]
    subprocess.run(cmp_command, check=True)
    return {'directory': str(directory), 'sha256': proof['candidate_sha256'],
            'different_bytes': proof['different_bytes'], 'compared_bytes': proof['compared_bytes'],
            'cmp_command': cmp_command, 'cmp_exit_code': 0,
            'proof_sha256': support.digest((directory/'proof.json').read_bytes()),
            'full_text_data_reassembly': True, 'baseline_c_provider_receipts_revalidated': True}


def verify(root, package, output, *, native_demo=False):
    mod_link.output_guard(root, package, output)
    root, package, output = root.resolve(), package.resolve(), output.resolve()
    mod_link.output_guard(root, package, output)
    output.mkdir(parents=True, exist_ok=True)
    mod_io.unlink(output/'proof.json', missing_ok=True)
    checker_inputs = {Path(__file__).resolve(): Path(__file__).read_bytes(),
                      Path(common.__file__).resolve(): Path(common.__file__).read_bytes(),
                      Path(complete.__file__).resolve(): Path(complete.__file__).read_bytes()}
    # Full baseline assembly refreshes content-addressed cache receipts. Perform
    # it before either modification captures those exact serialized inputs.
    print('Reassembling the disabled baseline and requiring whole-file cmp equality.', flush=True)
    baseline = verify_baseline(root, package, output.parent/'disabled')
    print('Tracing a fresh modification compile and complete source link.', flush=True)
    manifest, candidate, audit, observed = build_once(root, package, output)
    observed.update(checker_inputs)
    observed[output/'manifest.json'] = (output/'manifest.json').read_bytes()
    observed[output/'FFX.exe'] = candidate
    acceptance = output/'acceptance'
    acceptance.mkdir(exist_ok=True)
    print('Recompiling and relinking independently in an empty directory.', flush=True)
    with tempfile.TemporaryDirectory(prefix='replay-', dir=acceptance) as temporary:
        replay_output = Path(temporary)
        replay, rebuilt, replay_audit, replay_inputs = build_once(root, package, replay_output)
        compare_replay(manifest, candidate, replay, rebuilt)
        compare_compiler_outputs(output/'compiler', replay_output/'compiler')
        for name in ('manifest.json', 'source_only_audit.json', 'build.trace.gz', 'build.log'):
            (acceptance/('replay-'+name)).write_bytes((replay_output/name).read_bytes())
        (acceptance/'replay-module.obj').write_bytes((replay_output/'compiler/module.obj').read_bytes())
        (acceptance/'replay-module.ll').write_bytes((replay_output/'compiler/module.ll').read_bytes())
        support.check_unchanged(replay_inputs)
    layout = pe_structure.parse_layout(candidate)
    sites = complete.highlow_sites(candidate, layout)
    if [layout['image_base']+site for site in sites] != manifest['highlow_sites']:
        raise ValueError('independently parsed PE relocations differ from actual COFF sites')
    rebased = []
    for base in (0x400000, 0x10000000, 0x50000000):
        mapped = complete.mapped_image(candidate, layout, base, sites)
        rebased.append({'image_base': hex(base), 'mapped_bytes': len(mapped),
                        'memory_sha256': support.digest(mapped)})
    native = None
    if native_demo:
        import mod_native
        print('Executing compiled comparison behavior in mapped x86 images.', flush=True)
        native = mod_native.validate(output/'FFX.exe', manifest, output/'native')
    # Neither independent modification build may change any recorded source or
    # baseline cache identity. Do not normalize JSON or waive byte comparisons.
    support.check_unchanged(observed)
    baseline_proof = Path(baseline['directory'])/'proof.json'
    if support.digest(baseline_proof.read_bytes()) != baseline['proof_sha256']:
        raise ValueError('disabled baseline proof changed during modification verification')
    subprocess.run(baseline['cmp_command'], check=True)
    proof = {'schema_version': 1, 'kind': 'ffx-static-modification-acceptance', 'accepted': True,
             'candidate_sha256': support.digest(candidate), 'file_size': len(candidate),
             'manifest_sha256': support.digest(observed[output/'manifest.json']),
             'source_only_audit': audit, 'independent_fresh_compile_and_link': replay_audit,
             'whole_manifest_equal': True, 'whole_image_equal_to_replay': True,
             'whole_compiler_object_equal': True, 'whole_compiler_ir_equal': True,
             'native_demo': native, 'mapped_images': rebased, 'disabled_baseline': baseline,
             'gameplay_runtime_tested': False, 'runtime_hooks_required': False,
             'checker_inputs': {str(p): support.digest(raw) for p, raw in checker_inputs.items()}}
    mod_io.write(output/'proof.json.tmp', json.dumps(proof, indent=2)+chr(10))
    mod_io.replace(output/'proof.json.tmp', output/'proof.json')
    print('Accepted source-built modification:', proof['candidate_sha256'], flush=True)
    return proof


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--package', type=Path, default=ROOT/'recon/ffx/mods/compare_demo')
    parser.add_argument('--output', type=Path, default=ROOT/'recon/ffx/mods/build/compare_demo')
    parser.add_argument('--native-demo', action='store_true')
    args = parser.parse_args()
    verify(args.root, args.package, args.output, native_demo=args.native_demo)


if __name__ == '__main__':
    main()
