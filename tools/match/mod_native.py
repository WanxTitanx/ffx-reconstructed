"""Fresh freestanding i386 execution of the real comparison-demo PE image."""
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import tempfile

import coff_relocations as coff
import leaf_build as support
import mod_io
import pe_structure

ROOT = Path(__file__).resolve().parents[2]
BASES = (0x400000, 0x10000000, 0x50000000)
SYMBOLS = {'FN_RVA': '_FFX_memcmp_modified', 'DESC_RVA': '_ffx_compare_description',
           'SCALE_RVA': '_ffx_compare_scale', 'CALLS_RVA': '_ffx_compare_calls',
           'RECORDS_RVA': '_ffx_compare_recent'}
ENVIRONMENT = {'PATH': '/usr/bin:/bin', 'LANG': 'C', 'LC_ALL': 'C', 'TZ': 'UTC', 'SOURCE_DATE_EPOCH': '0'}


def configuration(data, manifest):
    if support.digest(data) != manifest['candidate_sha256']:
        raise ValueError('native test image does not match its manifest')
    layout = pe_structure.parse_layout(data)
    base = layout['image_base']
    symbols = manifest['module_symbols']
    if any(name not in symbols for name in SYMBOLS.values()):
        raise ValueError('native-demo requires the comparison example interface')
    result = {key: symbols[name]-base for key, name in SYMBOLS.items()}
    if any(type(value) is not int or value <= 0 or value >= layout['optional_header']['size_of_image']
           for value in result.values()):
        raise ValueError('native-demo symbol lies outside the PE image')
    expected_target = symbols[SYMBOLS['FN_RVA']]
    selected = None
    for record in manifest['changed_references']:
        at, site = record['file_offset'], record['site']
        if record['type'] != coff.REL32 or record['to'] != expected_target:
            continue
        owners = [s for s in layout['sections'] if s['characteristics'] & 0x20000000
                  and s['virtual_address'] <= site-base-1
                  and site-base+4 <= s['virtual_address']+s['raw_size']]
        if len(owners) != 1:
            raise ValueError('native-demo caller lies outside executable source code')
        section = owners[0]
        if (at != section['raw_offset']+site-base-section['virtual_address']
                or not 1 <= at <= len(data)-4 or data[at-1] != 0xe8
                or site+4+struct.unpack_from('<i', data, at)[0] != expected_target):
            raise ValueError('native-demo call is not the manifest-linked E8 target')
        selected = record
        break
    if selected is None:
        raise ValueError('native-demo has no actual relinked caller')
    result.update(IMAGE_BASE=base, CALL_SITE_RVA=selected['site']-base-1,
                  EXPECTED_RELOCATIONS=len(manifest['highlow_sites']))
    return result


def validate(exe, manifest, output):
    exe = Path(exe).resolve()
    output = mod_io.validate_directory(output)
    if output == exe.parent or output in exe.parents:
        raise ValueError('native outputs must not replace the candidate directory')
    output.mkdir(parents=True, exist_ok=True)
    mod_io.unlink(output/'report.json', missing_ok=True)
    data = exe.read_bytes()
    config = configuration(data, manifest)
    source = ROOT/'recon/ffx/mods/native_check.c'
    startup = ROOT/'recon/ffx/mods/native_start.S'
    found = shutil.which('gcc')
    if found is None:
        raise ValueError('gcc with freestanding i386 output is required for native-demo')
    compiler = Path(found).resolve()
    observed = {exe: data, source: source.read_bytes(), startup: startup.read_bytes(),
                Path(__file__).resolve(): Path(__file__).read_bytes(), compiler: compiler.read_bytes()}
    version = subprocess.run([str(compiler), '--version'], env=ENVIRONMENT,
                             check=True, capture_output=True).stdout.decode()
    # Pin the actual compiler, assembler and linker programs selected by gcc.
    for component in ('cc1', 'as', 'ld'):
        name = subprocess.run([str(compiler), '-print-prog-name='+component], env=ENVIRONMENT,
                              check=True, capture_output=True).stdout.decode().strip()
        path = Path(name if Path(name).is_absolute() else (shutil.which(name) or name)).resolve()
        observed[path] = path.read_bytes()
    compile_command = [str(compiler), '-m32', '-O2', '-Wall', '-Wextra', '-Werror',
        '-ffreestanding', '-fno-builtin', '-fno-stack-protector', '-fno-pie',
        '-fno-asynchronous-unwind-tables', '-fno-unwind-tables', '-fno-ident',
        '-c', 'native_check.c', '-o', 'native_check.o']
    startup_command = [str(compiler), '-m32', '-fno-pie', '-c', 'native_start.S', '-o', 'native_start.o']
    link_command = [str(compiler), '-m32', '-nostdlib', '-static', '-no-pie',
        '-Wl,--build-id=none', '-Wl,-z,noexecstack', '-Wl,-e,_start',
        'native_start.o', 'native_check.o', '-o', 'native_check']
    snapshots = output/'inputs'
    snapshots.mkdir(exist_ok=True)
    records = []
    for path, raw in sorted(observed.items()):
        digest = support.digest(raw)
        mod_io.write(snapshots/digest, raw)
        records.append({'path': str(path), 'sha256': digest, 'snapshot': 'inputs/'+digest})
    runs = []
    for base in BASES:
        destination = output/('%08x' % base)
        destination.mkdir(exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='.native-', dir=output) as temporary:
            stage = Path(temporary)
            mod_io.write(stage/'native_check.c', observed[source])
            mod_io.write(stage/'native_start.S', observed[startup])
            lines = ['#define %s 0x%xu' % (key, value) for key, value in sorted(config.items())]
            lines += ['#define LOAD_BASE 0x%xu' % base,
                      'static const char candidate_path[] = '+json.dumps(str(exe))+';']
            mod_io.write(stage/'native_config.h', chr(10).join(lines)+chr(10))
            build_log = bytearray()
            for command in (compile_command, startup_command, link_command):
                completed = subprocess.run(command, cwd=stage, env=ENVIRONMENT,
                                           capture_output=True, timeout=60)
                build_log.extend(completed.stdout+completed.stderr)
                if completed.returncode:
                    mod_io.write(destination/'build.log', bytes(build_log))
                    raise ValueError('native harness build failed: '+build_log.decode(errors='replace'))
            completed = subprocess.run([str(stage/'native_check')], cwd=stage, env=ENVIRONMENT,
                                       capture_output=True, timeout=30)
            text = (completed.stdout+completed.stderr).decode(errors='replace')
            mod_io.write(destination/'build.log', bytes(build_log))
            mod_io.write(destination/'run.log', text)
            if completed.returncode:
                raise ValueError('native execution failed (%s): %s' % (completed.returncode, text))
            match = re.fullmatch(r'PASS native candidate harness\s+loaded=(0x[0-9a-f]+) '
                r'preferred=(0x[0-9a-f]+) delta=(0x[0-9a-f]+) relocations=(\d+) '
                r'cases=(\d+) calls=(\d+) final_scale=(\d+)\s*', text)
            if (match is None or int(match[1], 16) != base or int(match[2], 16) != config['IMAGE_BASE']
                    or int(match[4]) != config['EXPECTED_RELOCATIONS']
                    or int(match[5]) != 33800 or int(match[6]) != 33800 or int(match[7]) != 11):
                raise ValueError('native execution report is incomplete or inconsistent')
            retained = {}
            for name in ('native_check.c', 'native_start.S', 'native_config.h',
                         'native_check.o', 'native_start.o', 'native_check'):
                raw = (stage/name).read_bytes()
                mod_io.write(destination/name, raw)
                retained[name] = support.digest(raw)
            (destination/'native_check').chmod(0o755)
            runs.append({'load_base': '0x%08x' % base, 'cases': int(match[5]), 'calls': int(match[6]),
                         'relocations': int(match[4]), 'exit_code': completed.returncode,
                         'files': retained, 'log_sha256': support.digest(text.encode()),
                         'executed_workdir': str(stage), 'retained_workdir': str(destination)})
        support.check_unchanged(observed)
    report = {'schema_version': 1, 'passed': True, 'candidate_sha256': support.digest(data),
              'total_cases': sum(r['cases'] for r in runs), 'runs': runs, 'configuration': config,
              'commands': [compile_command, startup_command, link_command], 'environment': ENVIRONMENT,
              'compiler_version': version, 'inputs': records, 'actual_call_target_checked': True,
              'callee_executed_natively': True, 'whole_original_caller_executed': False,
              'gameplay_executed': False, 'buffer_lengths': [0, 64], 'scales': [7, 11],
              'alignment_pairs': [[0, 3], [1, 2], [2, 1], [3, 0]],
              'call_counter_and_ring_records_checked': True}
    support.check_unchanged(observed)
    mod_io.write(output/'report.json', json.dumps(report, indent=2)+chr(10))
    return report
