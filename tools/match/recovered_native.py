"""Compile and run the recovered vec3 verifier on Windows x86, using real PE bytes.

The harness is separate test code and receives no C-recovery credit. Its mapped
images bind only the actual MSVCR110 _CIsqrt import; the game is not started.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path, PureWindowsPath
import re
import shutil

import leaf_build as support
import recovered_build as build
import recovered_win32

BASES = (0x10000000, 0x20000000, 0x50000000)


def parse_success(text):
    lines = text.strip().splitlines()
    if len(lines) != 3:
        raise ValueError('native report must contain exactly three completed base runs')
    runs = []
    for line, base in zip(lines, BASES):
        match = re.fullmatch(r'PASS vec3 base=([0-9a-f]{8}) cases=(\d+) calls=(\d+) '
            r'modes=12 alias_modes=2 relocations=283602', line)
        if not match or int(match[1], 16) != base or int(match[2]) != 110592 or int(match[3]) != 221184:
            raise ValueError('native report omits cases, a base, or required ABI/FP modes')
        runs.append({'base': base, 'cases': int(match[2]), 'calls': int(match[3])})
    return {'runs': runs, 'cases': sum(r['cases'] for r in runs), 'calls': sum(r['calls'] for r in runs),
            'known_value_calls': 12, 'total_calls': sum(r['calls'] for r in runs)+12}


def file_hash(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def library_searches(log):
    # VS2012 /VERBOSE:LIB reports the full paths it searched, without the
    # member-level Loaded lines emitted by some later linkers. Retain this
    # complete search set as inputs; do not label every library as consumed.
    names = {}
    for line in log.decode(errors='replace').splitlines():
        match = re.match(r'^\s*Searching (.+[.]lib):\s*$', line, re.I)
        if match:
            path = PureWindowsPath(match[1])
            if not path.is_absolute():
                raise ValueError('native linker search path is not absolute')
            names[str(path).casefold()] = str(path)
    return sorted(names.values())


def compiler_dependencies(log):
    headers = {}
    for line in log.decode(errors='replace').splitlines():
        match = re.match(r'^Note: including file:\s+(.+?)\s*$', line)
        if match:
            path = Path(match[1]).resolve()
            if not path.is_file():
                raise ValueError('native harness include is unavailable: '+str(path))
            headers[str(path)] = file_hash(path)
    libraries = {str(Path(name).resolve()): file_hash(name) for name in library_searches(log)}
    if not headers or not libraries:
        raise ValueError('native test compiler did not report headers and library search inputs')
    return {'headers': headers, 'link_search_libraries': libraries}


def validate(reference, candidate, runtime, source_dir, recipe_path, output):
    if os.name != 'nt':
        raise RuntimeError('the native PE/x87 verifier runs on the Windows x86 test host')
    reference, candidate, runtime = (Path(p).resolve() for p in (reference, candidate, runtime))
    for image in (reference, candidate):
        if image.stat().st_size != 10675712 or file_hash(image) != build.TARGET:
            raise ValueError('native vanilla test requires the complete pinned executable')
    output = build.empty_output(output)
    source = Path(source_dir).resolve()/'vec3_check.c'
    recipe = build.validate_recipe(support.parse_json(Path(recipe_path).read_bytes(), 'compiler identity recipe'))
    inputs = {str(path): file_hash(path) for path in (source, reference, candidate, runtime,
        Path(__file__).resolve(), Path(recovered_win32.__file__).resolve(), Path(build.__file__).resolve(),
        Path(support.__file__).resolve(), Path(recipe_path).resolve())}
    try:
        (output/'source').mkdir()
        shutil.copyfile(source, output/'source/vec3_check.c')
        with (output/'environment.log').open('wb') as log:
            environment = support.compiler_environment(log)
        environment['VSLANG'] = '1033'
        compiler = Path(shutil.which('cl.exe', path=environment.get('PATH'))).resolve()
        for name, expected in recipe['toolchain']['files'].items():
            if file_hash(compiler.with_name(name)) != expected:
                raise ValueError('native test compiler differs from its pinned identity')
        argv = [str(compiler), '/TC', '/MT', '/Od', '/Oy-', '/GS-', '/W3', '/WX', '/showIncludes',
                '/D_CRT_SECURE_NO_WARNINGS', '/Foharness.obj', '/Feharness.exe', 'source/vec3_check.c',
                '/link', '/ENTRY:reserve_start', '/BASE:0x30000000', '/DYNAMICBASE:NO', '/FIXED', '/VERBOSE:LIB']
        compiler_trace = recovered_win32.run(argv, output, environment, output/'compile.log')
        build.validate_runtime(compiler_trace, argv, recipe, 'compile')
        dependencies = compiler_dependencies((output/'compile.log').read_bytes())
        (output/'compile-trace.json').write_bytes(build.json_bytes(compiler_trace))
        executable = output/'harness.exe'
        if not executable.is_file():
            raise ValueError('native test compilation produced no executable')
        commands = [str(executable), str(reference), str(candidate), str(runtime)]
        # Run the negative control first. The deliberately wrong test callee must
        # fail on an observed state/output mismatch, not an absent DLL or process.
        negative = recovered_win32.run(commands+['negative'], output, environment, output/'negative.log')
        (output/'negative-trace.json').write_bytes(build.json_bytes(negative))
        negative_log = (output/'negative.log').read_text(errors='replace')
        if negative['exit_code'] != 1 or ('FAIL vec3 base=%08x index=0' % BASES[0]) not in negative_log:
            raise ValueError('native differential test did not reject its wrong-function control: '+negative_log)
        trace = recovered_win32.run(commands, output, environment, output/'run.log')
        (output/'run-trace.json').write_bytes(build.json_bytes(trace))
        if trace['exit_code'] != 0 or not trace['all_processes_succeeded']:
            raise ValueError('native recovered function failed: '+(output/'run.log').read_text(errors='replace'))
        observed_runtime = [digest for path, digest in trace['loaded_files'].items()
                            if PureWindowsPath(path).name.casefold() == 'msvcr110.dll']
        if observed_runtime != [inputs[str(runtime)]]:
            raise ValueError('native test did not load the supplied original-game CRT')
        counts = parse_success((output/'run.log').read_text())
        for path, expected in inputs.items():
            if file_hash(path) != expected:
                raise ValueError('native test input changed: '+path)
        for group in dependencies.values():
            for path, expected in group.items():
                if file_hash(path) != expected:
                    raise ValueError('native test compiler dependency changed')
        outputs = {name: file_hash(output/name) for name in ('harness.exe', 'harness.obj', 'compile.log',
            'compile-trace.json', 'negative.log', 'negative-trace.json', 'run.log', 'run-trace.json')}
        result = {'schema_version': 1, 'status': 'passed', 'target_sha256': build.TARGET,
            'candidate_sha256': inputs[str(candidate)], 'function_va': 0x93d3d0, 'function_size': 102,
            'runtime_sha256': inputs[str(runtime)], 'inputs': inputs, 'dependencies': dependencies,
            'compiler_command': argv, 'run_command': commands, 'negative_control_rejected': True,
            'library_scope': 'all named linker-search library inputs; individual static members are not claimed',
            'negative_exit_code': negative['exit_code'], 'outputs': outputs, **counts,
            'x87_precision_modes': [24, 53, 64], 'x87_rounding_modes': ['nearest', 'down', 'up', 'toward_zero'],
            'x87_exceptions': 'masked; status flags and empty x87 stack compared',
            'checks': ['bitwise output', 'source preservation', 'buffer sentinels', 'in-place alias',
                       'EBX/ESI/EDI/EBP', 'ESP cleanup', 'x87 control/status', 'known 3-4-0, zero, NaN'],
            'gameplay_runtime_tested': False,
            'preferred_base': 'not used by this Windows harness: loader allocations occupy it before entry; existing mod_native and literal cmp remain required',
            'scope': 'isolated callee from complete mapped PEs, genuine HIGHLOW rebasing and real _CIsqrt; no game entry point'}
        (output/'report.json').write_bytes(build.json_bytes(result))
        return result
    except BaseException as exc:
        (output/'report.json').unlink(missing_ok=True)
        (output/'failure.json').write_bytes(build.json_bytes({'status': 'failed', 'message': str(exc)}))
        raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('reference', 'candidate', 'runtime', 'source-dir', 'recipe', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    args = parser.parse_args()
    result = validate(args.reference, args.candidate, args.runtime, args.source_dir, args.recipe, args.output)
    print(json.dumps({key: result[key] for key in ('status', 'cases', 'calls', 'known_value_calls',
                     'total_calls', 'negative_control_rejected', 'candidate_sha256')}, indent=2))


if __name__ == '__main__':
    main()
