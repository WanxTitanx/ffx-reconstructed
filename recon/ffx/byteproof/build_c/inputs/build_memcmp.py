#!/usr/bin/env python3
"""Build from retained inputs and publish a receipt only after all steps succeed."""
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
VCVARS = r'C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat'


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def compiler_environment(log):
    env = dict(os.environ)
    if os.name == 'nt':
        # `set` is captured only to inherit vcvarsall's environment; never log it.
        command = 'call "' + VCVARS + '" x86 >nul && set'
        result = subprocess.run(command, shell=True, capture_output=True)
        log.write(b'> vcvarsall.bat x86 (environment setup)\n')
        if result.returncode:
            log.write(result.stderr)
            raise ValueError(f'VS2012 x86 environment setup failed: {result.returncode}')
        env = {key.upper(): value for key, value in env.items()}
        for line in result.stdout.decode('mbcs').splitlines():
            key, separator, value = line.partition('=')
            if separator and key:
                env[key.upper()] = value
    # Otherwise hidden command-line flags could change the recorded recipe.
    for key in list(env):
        if key.upper() in {'CL', '_CL_', 'LINK', '_LINK_'}:
            del env[key]
    return env


def run_tool(command, work, env, log):
    log.write(('> ' + subprocess.list2cmdline(command) + '\n').encode('utf-8'))
    log.flush()
    result = subprocess.run(command, cwd=work, env=env, stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT)
    log.write(result.stdout)
    log.write(('\nexit_code=' + str(result.returncode) + '\n').encode('ascii'))
    log.flush()
    if result.returncode:
        raise ValueError(f'{Path(command[0]).name} failed with exit code {result.returncode}')
    return result.stdout


def build(source, output):
    output.mkdir(parents=True, exist_ok=True)
    # A failed rebuild must never leave an earlier success receipt in place.
    manifest_path = output / 'build-manifest.json'
    manifest_path.unlink(missing_ok=True)
    (output / 'proof.json').unlink(missing_ok=True)
    helper = Path(__file__).resolve()
    current = {'source': source.resolve(),
               'recipe': helper.with_name('build_memcmp.bat'), 'helper': helper}
    log_path = output / 'build.log'
    with log_path.open('wb') as log:
        try:
            contents = {key: path.read_bytes() for key, path in current.items()}
            filenames = {'source': 'ffx_memcmp.c', 'recipe': 'build_memcmp.bat',
                         'helper': 'build_memcmp.py'}
            inputs = {key: {'file': 'inputs/' + filenames[key], 'sha256': sha256(data)}
                      for key, data in contents.items()}
            env = compiler_environment(log)
            tools = {}
            for name in ('cl.exe', 'link.exe', 'dumpbin.exe'):
                path = shutil.which(name, path=env.get('PATH'))
                if path is None:
                    raise ValueError(f'missing VS2012 tool: {name}')
                tools[name] = str(Path(path).resolve())
            with tempfile.TemporaryDirectory(prefix='memcmp-build-', dir=output) as tmp:
                work = Path(tmp)
                (work / 'inputs').mkdir()
                for key, data in contents.items():
                    (work / inputs[key]['file']).write_bytes(data)
                commands = [
                    [tools['cl.exe'], '/c', '/GS-', '/O2', '/MD', '/Oy-', '/Oi', '/GL',
                     'inputs/ffx_memcmp.c', '/Foffx_memcmp.obj'],
                    [tools['link.exe'], '/nologo', '/LTCG', '/OUT:ffx_memcmp.exe',
                     '/MAP:ffx_memcmp.map', 'ffx_memcmp.obj', 'kernel32.lib',
                     '/SUBSYSTEM:CONSOLE', '/ENTRY:FFX_memcmp'],
                    [tools['dumpbin.exe'], '/DISASM', 'ffx_memcmp.exe'],
                ]
                compiler_output = run_tool(commands[0], work, env, log)
                versions = re.findall(r'Compiler Version ([0-9.]+) for x86',
                                      compiler_output.decode('utf-8', errors='replace'))
                if versions != [COMPILER_VERSION]:
                    raise ValueError('build requires the pinned VS2012 x86 compiler ' + COMPILER_VERSION)
                run_tool(commands[1], work, env, log)
                disassembly = run_tool(commands[2], work, env, log)
                (work / 'ffx_memcmp.dis.txt').write_bytes(disassembly)
                for key, data in contents.items():
                    if (current[key].read_bytes() != data
                            or (work / inputs[key]['file']).read_bytes() != data):
                        raise ValueError(f'{key} changed during build; no manifest published')
                # Fresh work directory prevents a failed compiler from reusing stale objects.
                artifacts = {name: (work / name).read_bytes() for name in (
                    'ffx_memcmp.exe', 'ffx_memcmp.obj', 'ffx_memcmp.map', 'ffx_memcmp.dis.txt')}
                (output / 'inputs').mkdir(exist_ok=True)
                for key, data in contents.items():
                    (output / inputs[key]['file']).write_bytes(data)
                for name, data in artifacts.items():
                    (output / name).write_bytes(data)
        except (OSError, ValueError) as exc:
            log.write(('error: ' + str(exc) + '\n').encode('utf-8'))
            raise
    # The log is closed before hashing. The receipt is the last published file.
    manifest = {
        'schema_version': 1, 'status': 'complete', 'inputs': inputs,
        'outputs': {
            'candidate': {'file': 'ffx_memcmp.exe', 'sha256': sha256(artifacts['ffx_memcmp.exe'])},
            'build_log': {'file': 'build.log', 'sha256': sha256(log_path.read_bytes())},
        },
        'compiler_version': COMPILER_VERSION, 'compiler_architecture': 'x86',
        'commands': commands,
    }
    pending = output / 'build-manifest.json.tmp'
    pending.write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
    pending.replace(manifest_path)
    return manifest


def main(argv=None):
    package = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=package.parent / 'ffx_memcmp.c')
    parser.add_argument('--output-dir', type=Path, default=package / 'build_c')
    args = parser.parse_args(argv)
    manifest = build(args.source, args.output_dir.resolve())
    print('Built FFX_memcmp with input snapshots and build-manifest.json')
    print('candidate_image_sha256=' + manifest['outputs']['candidate']['sha256'])
    return 0


if __name__ == '__main__':
    try:
        raise SystemExit(main())
    except (OSError, ValueError) as exc:
        print(f'error: {exc}', file=sys.stderr)
        raise SystemExit(2)
