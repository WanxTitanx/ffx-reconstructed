#!/usr/bin/env python3
"""Require a real source-link receipt and audited replay before final acceptance."""
import argparse
import ast
import gzip
import json
import os
from pathlib import Path
import re
import shutil
import shlex
import subprocess
import sys
import tempfile

import definitive_match as exact
import leaf_build as support

ROOT = Path(__file__).resolve().parents[2]
MANIFEST_FIELDS = {
    'schema_version', 'status', 'target_sha256', 'candidate', 'candidate_sha256',
    'file_size', 'reference_read_by_linker', 'raw_code_blob_fallbacks', 'masked_bytes',
    'inputs', 'placed_fragments', 'defined_symbols', 'highlow_sites', 'text_stats',
    'imports', 'section_hashes',
}
OPEN_CALL = re.compile(r'^\s*(\d+)\s+(?:open|openat|openat2)\(')
PID = re.compile(r'^\s*(\d+)\s+')
EXIT = re.compile(r'^\s*(\d+)\s+\+\+\+ exited with (\d+) \+\+\+')
QUOTED = re.compile(r'"(?:\\.|[^"\\])*"')


def validate_manifest(manifest, candidate):
    if not isinstance(manifest, dict) or set(manifest) != MANIFEST_FIELDS:
        raise ValueError('complete source manifest fields are missing or unsupported')
    if (type(manifest['schema_version']) is not int or manifest['schema_version'] != 1
            or manifest['status'] != 'complete' or manifest['candidate'] != 'FFX.exe'
            or manifest['target_sha256'] != exact.EXE_SHA256
            or manifest['candidate_sha256'] != support.digest(candidate)
            or type(manifest['file_size']) is not int or manifest['file_size'] != len(candidate)):
        raise ValueError('complete image does not match its source build manifest')
    if manifest['reference_read_by_linker'] is not False:
        raise ValueError('source manifest permits a reference read by the linker')
    for name in ('raw_code_blob_fallbacks', 'masked_bytes'):
        if type(manifest[name]) is not int or manifest[name] != 0:
            raise ValueError('source manifest requires zero ' + name)
    if not isinstance(manifest['inputs'], list) or not manifest['inputs']:
        raise ValueError('source manifest must have a nonempty input closure')


def validate_inputs(manifest, directory, reference):
    """Read current inputs and their content-addressed snapshots; reject aliases."""
    directory, reference = directory.resolve(), reference.resolve()
    entries = manifest.get('inputs')
    if not isinstance(entries, list) or not entries:
        raise ValueError('source input closure is empty')
    seen, observed = set(), {}
    for entry in entries:
        if not isinstance(entry, dict) or set(entry) != {'path', 'sha256', 'snapshot'}:
            raise ValueError('invalid source input record')
        digest = entry['sha256']
        if not support.is_digest(digest) or entry['snapshot'] != 'inputs/' + digest:
            raise ValueError('invalid content-addressed source snapshot')
        if not isinstance(entry['path'], str) or not Path(entry['path']).is_absolute():
            raise ValueError('source input must have an absolute recorded path')
        path = Path(entry['path'])
        canonical = path.resolve()
        if canonical in seen:
            raise ValueError('duplicate source input: ' + str(path))
        seen.add(canonical)
        if canonical == reference or (reference.exists() and path.exists() and os.path.samefile(path, reference)):
            raise ValueError('original reference cannot be a source build input')
        if canonical == directory or directory in canonical.parents:
            raise ValueError('final output cannot prove its own source provenance')
        snapshot = directory / entry['snapshot']
        if snapshot.resolve() != directory / 'inputs' / digest:
            raise ValueError('source snapshot is redirected outside its recorded location')
        raw, retained = path.read_bytes(), snapshot.read_bytes()
        if support.digest(raw) != digest or retained != raw:
            raise ValueError('retained source/build input changed: ' + str(path))
        observed[path] = raw
        observed[snapshot] = retained
    return observed


def trace_facts(raw, forbidden_paths):
    """Check observed opens and exits. This is a trace audit, not an OS sandbox."""
    text = raw.decode('utf-8')
    forbidden = {str(Path(path).resolve()) for path in forbidden_paths}
    processes, exited, calls = set(), set(), 0
    for line in text.splitlines():
        match = PID.match(line)
        if not match:
            raise ValueError('unrecognized or truncated syscall trace line')
        processes.add(int(match[1]))
        for token in QUOTED.findall(line):
            try:
                decoded = ast.literal_eval(token)
            except (ValueError, SyntaxError) as exc:
                raise ValueError('unreadable syscall trace path') from exc
            if decoded in forbidden:
                raise ValueError('syscall trace opens a forbidden original/reference path')
        # -yy also records the resolved file behind a relative path or symlink.
        if any(path in forbidden for path in re.findall(r'<(/[^>]*)>', line)):
            raise ValueError('syscall trace accesses a forbidden original/reference file')
        if OPEN_CALL.match(line):
            calls += 1
        ended = EXIT.match(line)
        if ended:
            if int(ended[2]) != 0:
                raise ValueError('traced process exited unsuccessfully')
            exited.add(int(ended[1]))
        if '+++ killed by ' in line:
            raise ValueError('traced process was killed')
    if not calls or not processes or exited != processes:
        raise ValueError('syscall trace is empty or missing successful process exits')
    return {'observed_open_syscalls': calls, 'traced_processes': len(processes),
            'original_path_open_calls': 0, 'trace_sha256': support.digest(raw)}


def completed_trace_lines(raw):
    """Rejoin calls split by strace while another traced process is running."""
    pending = {}
    for line in raw.decode('utf-8').splitlines():
        match = PID.match(line)
        if not match:
            raise ValueError('invalid syscall trace line')
        pid = int(match[1])
        if '<unfinished ...>' in line:
            if pid in pending:
                raise ValueError('overlapping unfinished syscall trace')
            pending[pid] = line.split('<unfinished ...>', 1)[0]
            continue
        if ' resumed>' in line:
            if pid not in pending:
                raise ValueError('resumed syscall lacks its trace prefix')
            line = pending.pop(pid) + line.split(' resumed>', 1)[1]
        yield line
    if pending:
        raise ValueError('incomplete syscall trace')


def validate_trace_binding(raw, manifest, directory, command, *, link_only=False, root=ROOT):
    """Bind a trace to its executed command, consumed inputs and emitted output."""
    if isinstance(command, str):
        command = shlex.split(command)
    if (not isinstance(command, list) or not command
            or any(not isinstance(arg, str) for arg in command)
            or Path(command[0]).name != 'strace' or '-f' not in command or '-yy' not in command):
        raise ValueError('audit command must trace descendants and resolved descriptors')
    try:
        events = command[command.index('-e') + 1]
        runtime = command[command.index('-o') + 2:]
    except (ValueError, IndexError) as exc:
        raise ValueError('audit command is missing its trace options') from exc
    if (not events.startswith('trace=')
            or not {'open', 'openat', 'openat2', 'execve'}.issubset(events[6:].split(','))
            or len(runtime) < 3 or Path(runtime[1]).name != 'run_source_only.py'
            or Path(runtime[2]).name != 'rebuild_complete.py'
            or ('--link-only' in runtime) != link_only):
        raise ValueError('audit command does not describe the required full build/link-only replay')
    root, directory = root.resolve(), directory.resolve()
    prefix = [sys.executable, str(root / 'tools/match/run_source_only.py'),
              str(root / 'tools/match/rebuild_complete.py')]
    expected = [prefix + ['--root', str(root), '--output', str(directory)]
                + (['--link-only'] if link_only else [])]
    # The documented full-build defaults are trusted only for this exact source
    # checkout/output. Alternate scripts, interpreters and roots are rejected.
    if not link_only and root == ROOT and directory == root / 'recon/ffx/complete':
        expected.append(prefix)
    if runtime not in expected:
        raise ValueError('audit runtime differs from the trusted interpreter/scripts/root/output')
    reads, writes, executed = set(), set(), False
    for line in completed_trace_lines(raw):
        words = [ast.literal_eval(word) for word in QUOTED.findall(line)]
        if re.search(r'\bexecve\(', line) and re.search(r'=\s*0\s*$', line):
            if words == [runtime[0], *runtime]:
                executed = True
        if not OPEN_CALL.match(line) or not re.search(r'=\s*\d+(?:<[^>]*>)?\s*$', line):
            continue
        descriptor = re.search(r'=\s*\d+<([^>]*)>\s*$', line)
        name = descriptor[1] if descriptor else (words[0] if words else '')
        if not Path(name).is_absolute():
            continue
        path = Path(name).resolve()
        if 'O_RDONLY' in line or 'O_RDWR' in line:
            reads.add(path)
        if 'O_WRONLY' in line or 'O_RDWR' in line:
            writes.add(path)
    if not executed:
        raise ValueError('syscall trace does not contain successful execve of the recorded command')
    required = {Path(entry['path']).resolve() for entry in manifest['inputs']}
    if not required or required - reads:
        raise ValueError('syscall trace did not successfully open all manifest inputs: '
                         + ', '.join(str(p) for p in sorted(required - reads)[:3]))
    outputs = {directory.resolve() / name for name in ('FFX.exe.tmp', 'manifest.json.tmp')}
    if outputs - writes:
        raise ValueError('syscall trace does not show creation of the claimed outputs')
    return {'executed_build_command_verified': True, 'input_opens_verified': len(required),
            'output_creation_verified': True}


def record_audit(directory, reference, command):
    """Bind an existing successful build trace to its exact output and receipt."""
    directory = directory.resolve()
    path = directory / 'source_only_audit.json'
    path.unlink(missing_ok=True)
    trace = (directory / 'build.trace').read_bytes()
    facts = trace_facts(trace, [reference, directory / 'FFX.exe'])
    packed = gzip.compress(trace, mtime=0)
    candidate = (directory / 'FFX.exe').read_bytes()
    manifest = (directory / 'manifest.json').read_bytes()
    binding = validate_trace_binding(trace, support.parse_json(manifest, 'build manifest'), directory, command)
    log = (directory / 'build.log').read_bytes()
    report = {**facts, **binding, 'trace_file': 'build.trace', 'trace_compressed_file': 'build.trace.gz',
              'trace_compressed_sha256': support.digest(packed),
              'original_path': str(reference.resolve()), 'original_calls': [],
              'trace_includes_child_processes': True, 'command': command, 'build_exit_code': 0,
              'candidate_sha256': support.digest(candidate), 'manifest_sha256': support.digest(manifest),
              'build_log_sha256': support.digest(log),
              'scope': 'Observed open/openat/openat2 calls and child exits; not an operating-system sandbox.'}
    (directory / 'build.trace.gz').write_bytes(packed)
    path.write_text(json.dumps(report, indent=2) + '\n')
    return report


def validate_audit(directory, reference, manifest_data, candidate, root=ROOT):
    path = directory / 'source_only_audit.json'
    audit_data = path.read_bytes()
    audit = support.parse_json(audit_data, 'source-only audit')
    if (audit.get('trace_file') != 'build.trace'
            or audit.get('trace_compressed_file') != 'build.trace.gz'
            or audit.get('original_path') != str(reference.resolve())
            or audit.get('trace_includes_child_processes') is not True
            or type(audit.get('build_exit_code')) is not int or audit['build_exit_code'] != 0
            or type(audit.get('original_path_open_calls')) is not int or audit['original_path_open_calls'] != 0
            or audit.get('original_calls') != []):
        raise ValueError('source-only audit is incomplete or unsuccessful')
    packed_path = directory / 'build.trace.gz'
    packed = packed_path.read_bytes()
    if support.digest(packed) != audit.get('trace_compressed_sha256'):
        raise ValueError('compressed syscall trace changed')
    trace = gzip.decompress(packed)
    facts = trace_facts(trace, [reference, directory / 'FFX.exe'])
    if (audit.get('trace_sha256') != facts['trace_sha256']
            or type(audit.get('observed_open_syscalls')) is not int
            or audit['observed_open_syscalls'] != facts['observed_open_syscalls']):
        raise ValueError('source-only audit trace hash/count does not recompute')
    if audit.get('manifest_sha256') != support.digest(manifest_data):
        raise ValueError('source-only audit belongs to another manifest')
    binding = validate_trace_binding(trace, support.parse_json(manifest_data, 'build manifest'),
                                     directory, audit.get('command'), root=root)
    if any(audit.get(key) != value for key, value in binding.items()):
        raise ValueError('source-only audit command/input/output binding does not recompute')
    if audit.get('candidate_sha256') != support.digest(candidate):
        raise ValueError('source-only audit belongs to another candidate')
    log_path = directory / 'build.log'
    log = log_path.read_bytes()
    if audit.get('build_log_sha256') != support.digest(log):
        raise ValueError('source-only audit build log changed')
    return {**facts, **binding, 'source_only_audit_sha256': support.digest(audit_data),
            'trace_compressed_sha256': support.digest(packed)}, {
                path: audit_data, packed_path: packed, log_path: log}


def compare_replay(claimed, candidate, replay, rebuilt):
    if candidate != rebuilt:
        raise ValueError('source replay produced different complete-file bytes')
    if claimed != replay:
        fields = sorted(key for key in set(claimed) | set(replay) if claimed.get(key) != replay.get(key))
        raise ValueError('source replay manifest/closure differs: ' + ', '.join(fields))


def replay_link(root, directory, reference, manifest, candidate):
    """Derive the entire receipt again in a fresh process without reading either EXE."""
    tracer = shutil.which('strace')
    if tracer is None:
        raise ValueError('strace is required for independently audited source-link replay')
    with tempfile.TemporaryDirectory(prefix='ffx-acceptance-', dir=directory) as tmp:
        work = Path(tmp)
        trace_path, log_path, output = work / 'relink.trace', work / 'relink.log', work / 'linked'
        command = [tracer, '-f', '-s', '4096', '-yy', '-e', 'trace=open,openat,openat2,execve',
                   '-o', str(trace_path), sys.executable,
                   str(root / 'tools/match/run_source_only.py'),
                   str(root / 'tools/match/rebuild_complete.py'),
                   '--root', str(root), '--output', str(output), '--link-only']
        with log_path.open('wb') as log:
            result = subprocess.run(command, cwd=root, stdout=log, stderr=subprocess.STDOUT, timeout=600)
        if result.returncode != 0:
            raise ValueError('source-link replay failed: ' + log_path.read_text(errors='replace')[-3000:])
        trace = trace_path.read_bytes()
        facts = trace_facts(trace, [reference, directory / 'FFX.exe'])
        replay_data = (output / 'manifest.json').read_bytes()
        replay = support.parse_json(replay_data, 'replayed source link manifest')
        rebuilt = (output / 'FFX.exe').read_bytes()
        validate_manifest(replay, rebuilt)
        compare_replay(manifest, candidate, replay, rebuilt)
        binding = validate_trace_binding(trace, replay, output, command, link_only=True, root=root)
        retained = directory / 'acceptance'
        retained.mkdir(exist_ok=True)
        packed = gzip.compress(trace, mtime=0)
        log_data = log_path.read_bytes()
        trace_output, log_output = retained / 'relink.trace.gz', retained / 'relink.log'
        trace_output.write_bytes(packed)
        log_output.write_bytes(log_data)
        return {**facts, **binding, 'source_link_replayed': True, 'manifest_exactly_reproduced': True,
                'input_closure_entries': len(replay['inputs']),
                'replay_manifest_sha256': support.digest(replay_data),
                'replay_candidate_sha256': support.digest(rebuilt),
                'trace_compressed_sha256': support.digest(packed), 'log_sha256': support.digest(log_data),
                'command': command}, {trace_output: packed, log_output: log_data}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('record-audit',))
    parser.add_argument('--directory', type=Path, default=ROOT / 'recon/ffx/complete')
    parser.add_argument('--reference', type=Path, default=Path(exact.EXE_DEFAULT))
    args = parser.parse_args()
    command = ['strace', '-f', '-s', '4096', '-yy', '-e', 'trace=open,openat,openat2,execve',
               '-o', str(args.directory.resolve() / 'build.trace'), sys.executable,
               str(ROOT / 'tools/match/run_source_only.py'), str(ROOT / 'tools/match/rebuild_complete.py')]
    try:
        report = record_audit(args.directory, args.reference, command)
        print(json.dumps(report, indent=2))
    except (OSError, ValueError, TypeError, KeyError) as exc:
        print('error: ' + str(exc), file=sys.stderr)
        raise SystemExit(2)
