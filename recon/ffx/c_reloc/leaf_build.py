#!/usr/bin/env python3
"""Standalone leaf job validation and build receipt support (also staged in the VM)."""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

COMPILER_VERSION = '17.00.50727.1'
INPUT_FILES = {'source': 'ffx_leaf.c', 'jobs': 'jobs.json',
               'recipe': 'build.bat', 'helper': 'leaf_build.py'}
VARIANTS = ('O2', 'O1', 'Oy')


def digest(data):
    return hashlib.sha256(data).hexdigest()


def parse_json(data, label):
    def distinct(pairs):
        result = {}
        for key, value in pairs:
            if key in result:
                raise ValueError('duplicate JSON key: ' + key)
            result[key] = value
        return result
    try:
        value = json.loads(data, object_pairs_hook=distinct)
    except (ValueError, UnicodeError) as exc:
        raise ValueError(f'invalid {label}: {exc}') from exc
    if not isinstance(value, dict):
        raise ValueError(label + ' must be a JSON object')
    return value


def is_digest(value):
    return isinstance(value, str) and re.fullmatch('[0-9a-f]{64}', value) is not None


def check_ranges(ranges, label):
    previous_end = 0
    seen = set()
    for va, size in sorted(ranges):
        if va in seen:
            raise ValueError(f'duplicate {label} address {va:#x}')
        if va < previous_end:
            raise ValueError(f'overlapping {label} range at {va:#x}')
        seen.add(va)
        previous_end = va + size


def render_source(groups):
    lines = ['/* Generated C operations; no embedded reference instruction bytes. */',
             'typedef char require_x86_pointers[sizeof(void *) == 4 ? 1 : -1];']
    for group in groups:
        spec = group['source']
        lines.append('__declspec(noinline) %s %s %s(%s) { %s }' % (
            spec['return_type'], spec['convention'], group['symbol'], spec['arguments'], spec['body']))
    return ('\n'.join(lines) + '\n').encode('utf-8')


def validate_jobs(jobs, source=None):
    """Reject malformed jobs and any repeated/overlapping original address range."""
    if not isinstance(jobs, dict) or any(not is_digest(jobs.get(key)) for key in (
            'target_sha256', 'inventory_sha256', 'source_sha256')):
        raise ValueError('jobs must contain valid target, inventory and source SHA-256 values')
    groups = jobs.get('groups')
    if not isinstance(groups, list) or not groups:
        raise ValueError('jobs must contain nonempty groups')
    symbols, ranges = set(), []
    for group in groups:
        if not isinstance(group, dict):
            raise ValueError('invalid jobs group')
        symbol = group.get('symbol')
        if not isinstance(symbol, str) or not re.fullmatch('leaf_[0-9a-f]{8}', symbol):
            raise ValueError('invalid jobs symbol')
        if symbol in symbols:
            raise ValueError('duplicate jobs symbol: ' + symbol)
        symbols.add(symbol)
        spec = group.get('source')
        fields = {'return_type', 'convention', 'arguments', 'body'}
        if (not isinstance(spec, dict) or set(spec) != fields
                or any(not isinstance(value, str) or not value for value in spec.values())
                or spec['convention'] not in ('__cdecl', '__fastcall')):
            raise ValueError('invalid source specification for ' + symbol)
        targets = group.get('targets')
        if not isinstance(targets, list) or not targets:
            raise ValueError('jobs group has no targets: ' + symbol)
        group_hash = None
        for target in targets:
            if not isinstance(target, dict):
                raise ValueError('invalid job target')
            va, size = target.get('va'), target.get('size')
            if (type(va) is not int or type(size) is not int or not 0 < va < 2**32
                    or not 4 <= size <= 80 or va + size > 2**32
                    or not is_digest(target.get('sha256'))
                    or not isinstance(target.get('idb_name'), str) or not target['idb_name']):
                raise ValueError('invalid job target range/hash/name for ' + symbol)
            if group_hash is not None and target['sha256'] != group_hash:
                raise ValueError('targets in one job group have different bodies')
            group_hash = target['sha256']
            ranges.append((va, size))
    check_ranges(ranges, 'job target')
    if source is not None and (digest(source) != jobs['source_sha256'] or render_source(groups) != source):
        raise ValueError('source differs from rendered jobs/source hash')
    return jobs


def read_bundle(package):
    """Read each artifact once; verify receipt hashes against retained and current inputs."""
    build_dir = package / 'build'
    manifest_path = build_dir / 'build-manifest.json'
    manifest_data = manifest_path.read_bytes()
    manifest = parse_json(manifest_data, 'build manifest')
    if (type(manifest.get('schema_version')) is not int or manifest['schema_version'] != 1
            or manifest.get('status') != 'complete'):
        raise ValueError('build manifest must describe a complete schema-version-1 build')
    observed = {manifest_path: manifest_data}

    def record(group, key, name):
        entries = manifest.get(group)
        entry = entries.get(key) if isinstance(entries, dict) else None
        if not isinstance(entry, dict) or entry.get('file') != name:
            raise ValueError(f'invalid {key} path in build manifest')
        path = build_dir / name
        data = path.read_bytes()
        if entry.get('sha256') != digest(data):
            raise ValueError(f'{key} SHA-256 differs from build manifest')
        observed[path] = data
        return data

    inputs = {}
    for key, name in INPUT_FILES.items():
        data = record('inputs', key, 'inputs/' + name)
        current = (package / name).read_bytes()
        if current != data:
            raise ValueError(f'current {key} differs from build-time snapshot; rebuild required')
        observed[package / name] = current
        inputs[key] = data
    jobs = validate_jobs(parse_json(inputs['jobs'], 'jobs'), inputs['source'])
    objects = {variant: record('outputs', variant, variant + '.obj') for variant in VARIANTS}
    log = record('outputs', 'build_log', 'build.log')
    versions = re.findall(r'Compiler Version ([0-9.]+) for x86', log.decode('utf-8', errors='replace'))
    if (versions != [COMPILER_VERSION] * len(VARIANTS)
            or manifest.get('compiler_version') != COMPILER_VERSION
            or manifest.get('compiler_architecture') != 'x86'):
        raise ValueError('build manifest/log do not identify three pinned VS2012 x86 compilations')
    return jobs, manifest, manifest_data, objects, inputs, log, observed


def check_unchanged(observed):
    for path, data in observed.items():
        if path.read_bytes() != data:
            raise ValueError(f'input or artifact changed during verification: {path.name}')


VCVARS = r'C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat'


def compiler_environment(log):
    env = dict(os.environ)
    if os.name == 'nt':
        result = subprocess.run('call "' + VCVARS + '" x86 >nul && set',
                                shell=True, capture_output=True)
        log.write(b'> vcvarsall.bat x86 (environment setup)\n')
        if result.returncode:
            log.write(result.stderr)
            raise ValueError(f'VS2012 environment setup failed: {result.returncode}')
        env = {key.upper(): value for key, value in env.items()}
        for line in result.stdout.decode('mbcs').splitlines():
            key, separator, value = line.partition('=')
            if separator and key:
                env[key.upper()] = value
    # Inherited extra flags must not silently override the recorded recipe.
    for key in list(env):
        if key.upper() in {'CL', '_CL_', 'LINK', '_LINK_'}:
            del env[key]
    return env


def run_compiler(command, work, env, log):
    log.write(('> ' + subprocess.list2cmdline(command) + '\n').encode('utf-8'))
    log.flush()
    result = subprocess.run(command, cwd=work, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    log.write(result.stdout)
    log.write(('\nexit_code=' + str(result.returncode) + '\n').encode('ascii'))
    log.flush()
    if result.returncode:
        raise ValueError(f'compiler failed with exit code {result.returncode}')
    versions = re.findall(r'Compiler Version ([0-9.]+) for x86', result.stdout.decode('utf-8', errors='replace'))
    if versions != [COMPILER_VERSION]:
        raise ValueError('build requires the pinned VS2012 x86 compiler ' + COMPILER_VERSION)


def build(package, output):
    """Compile retained C, validate inputs before/after each run, and publish receipt last."""
    output.mkdir(parents=True, exist_ok=True)
    manifest_path = output / 'build-manifest.json'
    pending = output / 'build-manifest.json.tmp'
    for stale in {manifest_path, pending, package / 'build-manifest.json',
                  package / 'proof.json', output / 'proof.json'}:
        stale.unlink(missing_ok=True)
    current = {key: package / name for key, name in INPUT_FILES.items()}
    log_path = output / 'build.log'
    with log_path.open('wb') as log:
        try:
            contents = {key: path.read_bytes() for key, path in current.items()}
            validate_jobs(parse_json(contents['jobs'], 'jobs'), contents['source'])
            if current['helper'].resolve() != Path(__file__).resolve():
                raise ValueError('build must execute the helper recorded in the package')
            inputs = {key: {'file': 'inputs/' + INPUT_FILES[key], 'sha256': digest(data)}
                      for key, data in contents.items()}
            env = compiler_environment(log)
            compiler = shutil.which('cl.exe', path=env.get('PATH'))
            if compiler is None:
                raise ValueError('missing VS2012 compiler cl.exe')
            compiler = str(Path(compiler).resolve())
            commands = []
            artifacts = {}
            with tempfile.TemporaryDirectory(prefix='leaf-build-', dir=output) as tmp:
                work = Path(tmp)
                (work / 'inputs').mkdir()
                for key, data in contents.items():
                    (work / inputs[key]['file']).write_bytes(data)

                def check_inputs():
                    for key, expected in contents.items():
                        if (current[key].read_bytes() != expected
                                or (work / inputs[key]['file']).read_bytes() != expected):
                            raise ValueError(f'{key} changed during build; no manifest published')

                for variant, optimize, frame in (('O2', '/O2', '/Oy-'),
                                                 ('O1', '/O1', '/Oy-'), ('Oy', '/O2', '/Oy')):
                    check_inputs()
                    name = variant + '.obj'
                    command = [compiler, '/c', '/GS-', optimize, '/MD', frame, '/Oi', '/arch:IA32',
                               '/Gy', 'inputs/ffx_leaf.c', '/Fo' + name]
                    commands.append(command)
                    run_compiler(command, work, env, log)
                    check_inputs()
                    artifacts[variant] = (work / name).read_bytes()
                    if not artifacts[variant]:
                        raise ValueError('compiler produced empty object: ' + name)
                check_inputs()
                for variant, data in artifacts.items():
                    if (work / (variant + '.obj')).read_bytes() != data:
                        raise ValueError('object changed during build: ' + variant)
                (output / 'inputs').mkdir(exist_ok=True)
                for key, data in contents.items():
                    (output / inputs[key]['file']).write_bytes(data)
                for variant, data in artifacts.items():
                    (output / (variant + '.obj')).write_bytes(data)
        except (OSError, ValueError) as exc:
            log.write(('error: ' + str(exc) + '\n').encode('utf-8'))
            raise
    # Capture the closed log and check published artifacts before the atomic receipt.
    log_data = log_path.read_bytes()
    observed = {current[key]: data for key, data in contents.items()}
    observed.update({output / inputs[key]['file']: data for key, data in contents.items()})
    observed.update({output / (variant + '.obj'): data for variant, data in artifacts.items()})
    observed[log_path] = log_data
    check_unchanged(observed)
    manifest = {
        'schema_version': 1, 'status': 'complete', 'inputs': inputs,
        'outputs': {variant: {'file': variant + '.obj', 'sha256': digest(data)}
                    for variant, data in artifacts.items()},
        'compiler_version': COMPILER_VERSION, 'compiler_architecture': 'x86',
        'commands': commands,
    }
    manifest['outputs']['build_log'] = {'file': 'build.log', 'sha256': digest(log_data)}
    pending.write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
    pending.replace(manifest_path)
    return manifest


def main(argv=None):
    package = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', type=Path, default=package / 'build')
    args = parser.parse_args(argv)
    manifest = build(package, args.output_dir.resolve())
    print('Built all three leaf variants from snapshots; published build-manifest.json')
    for variant in VARIANTS:
        print(variant + '_sha256=' + manifest['outputs'][variant]['sha256'])
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
