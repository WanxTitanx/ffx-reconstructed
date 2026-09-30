"""Compile a closed freestanding source package to fresh, auditable i386 COFF."""
import json
import os
from pathlib import Path, PurePosixPath
import shlex
import shutil
import struct
import subprocess
import tempfile

import coff_relocations as coff
import leaf_build as support
import mod_io

FLAGS = ['--target=i686-pc-windows-msvc', '-mno-incremental-linker-compatible',
         '-fno-temp-file', '-fno-gnu-inline-asm', '-fno-asm-blocks',
         '-fno-ms-extensions', '-fdeclspec', '-fdebug-compilation-dir=.',
         '-Wdate-time', '-O2', '-ffreestanding', '-fno-builtin',
         '-fno-stack-protector', '-fno-addrsig', '-fno-ident', '-fno-unwind-tables',
         '-fno-asynchronous-unwind-tables', '-fno-common', '-nostdinc', '-Werror']
RECIPE_KEYS = {'schema_version', 'name', 'source', 'files', 'replacements', 'bindings'}
LOADER_INIT = b'calling init: '
LOADER_PROGRAM = b'initialize program: '


def elf_interpreter(raw):
    """Read the kernel-loaded interpreter from the fingerprinted compiler."""
    if len(raw) < 64 or raw[:4] != bytes([127, 69, 76, 70]) or raw[4] not in (1, 2) or raw[5] not in (1, 2):
        raise ValueError('compiler is not a supported ELF executable')
    endian = '<' if raw[5] == 1 else '>'
    if raw[4] == 2:
        at = struct.unpack_from(endian + 'Q', raw, 32)[0]
        stride, count = struct.unpack_from(endian + 'HH', raw, 54)
        minimum, width, file_offset, size_offset = 56, 'Q', 8, 32
    else:
        at = struct.unpack_from(endian + 'I', raw, 28)[0]
        stride, count = struct.unpack_from(endian + 'HH', raw, 42)
        minimum, width, file_offset, size_offset = 32, 'I', 4, 16
    if stride < minimum or not count or at + stride * count > len(raw):
        raise ValueError('compiler ELF program headers are incomplete')
    paths = []
    for index in range(count):
        header = at + index * stride
        if struct.unpack_from(endian + 'I', raw, header)[0] != 3:
            continue
        offset = struct.unpack_from(endian + width, raw, header + file_offset)[0]
        size = struct.unpack_from(endian + width, raw, header + size_offset)[0]
        if size < 2 or offset + size > len(raw):
            raise ValueError('compiler ELF interpreter extent is invalid')
        name = raw[offset:offset + size]
        if name[-1] != 0 or 0 in name[:-1]:
            raise ValueError('compiler ELF interpreter path is malformed')
        path = Path(os.fsdecode(name[:-1]))
        if not path.is_absolute() or not path.is_file():
            raise ValueError('compiler ELF interpreter path is unavailable')
        paths.append(path.resolve())
    if len(paths) != 1:
        raise ValueError('compiler must declare exactly one ELF interpreter')
    return paths[0]


def package_inputs(package):
    package = Path(package).resolve()
    path = package / 'mod.json'
    raw = path.read_bytes()
    recipe = support.parse_json(raw, 'modification recipe')
    if (set(recipe) != RECIPE_KEYS or type(recipe['schema_version']) is not int
            or recipe['schema_version'] != 1 or not isinstance(recipe['name'], str)
            or not recipe['name'] or not isinstance(recipe['replacements'], list)
            or not isinstance(recipe['bindings'], dict)):
        raise ValueError('unsupported modification recipe')
    files = recipe['files']
    if not isinstance(files, list) or not files or any(not isinstance(f, str) for f in files):
        raise ValueError('declare source files explicitly')
    if len(files) != len(set(files)) or recipe['source'] not in files:
        raise ValueError('duplicate inputs or undeclared translation unit')
    if Path(recipe['source']).suffix not in ('.c', '.cc', '.cpp'):
        raise ValueError('translation unit must be C or C++ source')
    observed = {path: raw}
    for name in files:
        relative = PurePosixPath(name)
        if (relative.is_absolute() or '..' in relative.parts or str(relative) != name
                or '\\' in name or ':' in name or '\n' in name or name == 'mod.json'):
            raise ValueError('invalid source path: ' + name)
        target = package / name
        if target.is_symlink() or package not in target.resolve().parents:
            raise ValueError('source escapes its package: ' + name)
        observed[target] = target.read_bytes()
    return recipe, observed


def _loader_paths(stage, prefix, compiler):
    traces = sorted(stage.glob(prefix + '.*'))
    if not traces:
        raise ValueError('compiler loader did not emit an ELF dependency trace')
    programs, dependencies = set(), set()
    for trace in traces:
        raw = trace.read_bytes()
        if not raw or b'\0' in raw:
            raise ValueError('compiler ELF dependency trace is empty or malformed')
        for line in raw.splitlines():
            for marker, destination in ((LOADER_INIT, dependencies),
                                        (LOADER_PROGRAM, programs)):
                if marker not in line:
                    continue
                encoded = line.split(marker, 1)[1].strip()
                if encoded.endswith(b' [0]'):
                    encoded = encoded[:-4].rstrip()
                path = Path(os.fsdecode(encoded))
                if not path.is_absolute():
                    raise ValueError('compiler loader reported a non-absolute ELF input')
                resolved = path.resolve()
                if not resolved.is_file():
                    raise ValueError('compiler loader reported a missing ELF input: ' + str(path))
                destination.add(resolved)
    if compiler.resolve() not in programs:
        raise ValueError('ELF dependency trace does not belong to the requested compiler')
    if not dependencies:
        raise ValueError('compiler ELF dependency closure is empty')
    return dependencies


def _run_with_loader_trace(command, stage, environment, prefix, timeout):
    if any(stage.glob(prefix + '.*')):
        raise ValueError('stale compiler ELF dependency trace')
    traced_environment = dict(environment, LD_DEBUG='files', LD_DEBUG_OUTPUT=prefix)
    result = subprocess.run(command, cwd=stage, env=traced_environment,
                            capture_output=True, timeout=timeout)
    dependencies = _loader_paths(stage, prefix, Path(command[0]))
    return result, dependencies, traced_environment


def source_dependencies(stage, filename, target, declared):
    text = (stage / filename).read_text().replace(chr(92) + chr(10), '')
    if not text.startswith(target + ':'):
        raise ValueError('compiler did not emit the requested dependency receipt')
    dependencies = shlex.split(text.split(':', 1)[1])
    if not dependencies:
        raise ValueError('compiler emitted an empty source dependency receipt')
    for dependency in dependencies:
        if (stage / dependency).resolve() not in declared:
            raise ValueError('compiler read an undeclared source: ' + dependency)
    return sorted(set(dependencies))


def compile_package(package, output):
    output = mod_io.validate_directory(output)
    package, output = Path(package).resolve(), Path(output).resolve()
    if output == package or output in package.parents or package in output.parents:
        raise ValueError('compiler output must not replace source package')
    output.mkdir(parents=True, exist_ok=True)
    mod_io.unlink(output / 'compile.json', missing_ok=True)
    recipe, observed = package_inputs(package)
    found = shutil.which('clang')
    if found is None:
        raise ValueError('clang with the i686-pc-windows-msvc target is required')
    compiler = Path(found).resolve()
    observed[compiler] = compiler.read_bytes()
    interpreter = elf_interpreter(observed[compiler])
    environment = {'PATH': '/usr/bin:/bin', 'LANG': 'C', 'LC_ALL': 'C',
                   'TZ': 'UTC', 'SOURCE_DATE_EPOCH': '0'}
    flags = list(FLAGS)
    if Path(recipe['source']).suffix != '.c':
        flags += ['-fno-exceptions', '-fno-rtti', '-fno-threadsafe-statics']
    command = [str(compiler), *flags, '-I', 'source', '-MD', '-MF', 'module.d',
               '-MT', 'module.obj', '-c', 'source/' + recipe['source'], '-o', 'module.obj']
    ir_command = [str(compiler), *flags, '-I', 'source', '-MD', '-MF', 'module-ir.d',
                  '-MT', 'module.ll', '-S', '-emit-llvm', 'source/' + recipe['source'], '-o', 'module.ll']
    with tempfile.TemporaryDirectory(prefix='.compile-', dir=output) as temporary:
        stage = Path(temporary)
        for name in recipe['files']:
            destination = stage / 'source' / name
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_bytes(observed[package / name])
        version_result, discovered, _ = _run_with_loader_trace(
            [str(compiler), '--version'], stage, environment, '.version-loader', 30)
        if version_result.returncode:
            raise ValueError('unable to identify the modification compiler')
        version = version_result.stdout.decode()
        if interpreter not in discovered:
            raise ValueError('kernel-loaded compiler interpreter is absent from the loader closure')
        for dependency in discovered:
            observed[dependency] = dependency.read_bytes()
        result, actual_dependencies, compile_environment = _run_with_loader_trace(
            command, stage, environment, '.compiler-loader', 120)
        log = result.stdout + result.stderr
        mod_io.write(output / 'compile.log', log)
        if result.returncode:
            raise ValueError('modification compiler failed: ' + log.decode(errors='replace'))
        if actual_dependencies != discovered:
            missing = sorted(str(path) for path in discovered - actual_dependencies)
            added = sorted(str(path) for path in actual_dependencies - discovered)
            raise ValueError('fresh compiler ELF dependency closure changed: missing=%r added=%r'
                             % (missing, added))
        dependency_text = (stage / 'module.d').read_text().replace('\\\n', '')
        if not dependency_text.startswith('module.obj:'):
            raise ValueError('compiler did not emit the requested dependency receipt')
        dependencies = shlex.split(dependency_text.split(':', 1)[1])
        ir_result, ir_libraries, ir_environment = _run_with_loader_trace(
            ir_command, stage, environment, '.ir-loader', 120)
        log += ir_result.stdout + ir_result.stderr
        mod_io.write(output / 'compile.log', log)
        if ir_result.returncode:
            raise ValueError('typed IR compiler failed: ' + log.decode(errors='replace'))
        if ir_libraries != discovered:
            raise ValueError('typed IR compiler ELF dependency closure changed')
        declared = {(stage / 'source' / name).resolve() for name in recipe['files']}
        for dependency in dependencies:
            if (stage / dependency).resolve() not in declared:
                raise ValueError('compiler read an undeclared source: ' + dependency)
        ir_dependencies = source_dependencies(stage, 'module-ir.d', 'module.ll', declared)
        if ir_dependencies != sorted(set(dependencies)):
            raise ValueError('COFF and typed IR compilation consumed different source dependencies')
        for name in recipe['files']:
            if (stage / 'source' / name).read_bytes() != observed[package / name]:
                raise ValueError('staged source changed during compilation')
        object_data = (stage / 'module.obj').read_bytes()
        ir_data = (stage / 'module.ll').read_bytes()
        obj = coff.parse_coff(object_data)
        obj['llvm_ir'] = ir_data.decode('utf-8')
        if obj['timestamp'] != 0:
            raise ValueError('compiler emitted a nondeterministic COFF timestamp')
        support.check_unchanged(observed)
        snapshots = output / 'inputs'
        snapshots.mkdir(exist_ok=True)
        records = []
        for path, data in sorted(observed.items()):
            digest = support.digest(data)
            mod_io.write(snapshots / digest, data)
            records.append({'path': str(path), 'sha256': digest, 'snapshot': 'inputs/' + digest})
        elf_dependencies = [{'path': str(path), 'sha256': support.digest(observed[path])}
                            for path in sorted(discovered)]
        receipt = {'schema_version': 1, 'target': 'i686-pc-windows-msvc',
                   'compiler': str(compiler), 'version': version, 'command': command,
                   'environment': compile_environment, 'inputs': records,
                   'elf_dependencies': elf_dependencies,
                   'elf_interpreter': {'path': str(interpreter), 'sha256': support.digest(observed[interpreter])},
                   'runtime_libraries': sorted(str(path) for path in discovered if path != interpreter),
                   'dependencies': sorted(set(dependencies)), 'object': 'module.obj',
                   'object_sha256': support.digest(object_data),
                   'ir_command': ir_command, 'ir_environment': ir_environment,
                   'ir_dependencies': ir_dependencies, 'ir_sha256': support.digest(ir_data),
                   'log_sha256': support.digest(log)}
        mod_io.write(output / 'module.obj', object_data)
        mod_io.write(output / 'module.ll', ir_data)
        mod_io.write(output / 'compile.json', json.dumps(receipt, sort_keys=True, indent=2) + chr(10))
        return recipe, obj, observed, receipt
