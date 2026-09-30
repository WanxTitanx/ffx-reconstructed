"""Stage closed recovered C/C++ packages and compile them with pinned MSVC x86.

Compile runs only on Windows and publishes a receipt after a new preprocessing
and object build. Verify is a separate, reference-reading host operation.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath, PureWindowsPath
import re
import shutil
import time
import uuid

import coff_relocations as coff
import leaf_build as support
import recovered_win32

ROOT = Path(__file__).resolve().parents[2]
TOOLS = Path(__file__).resolve().parent
TARGET = '78ce34397da5e6f49b72c2aebadedaf4cd3f6720e1949d46a1b8ed67d3db5ced'
HELPERS = ('recovered_build.py', 'recovered_win32.py', 'coff_relocations.py', 'leaf_build.py')
FLAGS = {'/O1', '/O2', '/Od', '/Ob0', '/Ob1', '/Ob2', '/Oi', '/Oi-', '/Oy', '/Oy-',
         '/GS-', '/MD', '/MT', '/arch:IA32', '/arch:SSE2', '/fp:precise', '/fp:strict',
         '/fp:fast', '/Gd', '/Gr', '/Gz', '/Zp1', '/Zp2', '/Zp4', '/Zp8', '/Zp16'}
CORE_TOOLS = {'cl.exe', 'c1.dll', 'c1xx.dll', 'c2.dll'}
NAME = re.compile(r'[a-z][a-z0-9_-]*\Z')
SYMBOL = re.compile(r'_sym_[0-9a-f]{8}\Z')
TOKEN = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*', re.S)


def json_bytes(value):
    return (json.dumps(value, sort_keys=True, separators=(',', ':'))+'\n').encode()


def relative(name):
    if (not isinstance(name, str) or not name or '\\' in name or ':' in name or '\0' in name
            or name.startswith('/') or any(x in ('', '.', '..') for x in name.split('/'))):
        raise ValueError('invalid relative package path: '+repr(name))
    return PurePosixPath(name)


def regular(path, root=None):
    path = Path(path).absolute()
    if root is not None:
        root = Path(root).resolve()
        if not path.is_relative_to(root):
            raise ValueError('package path escapes its root')
        parts = [root, *list(path.parents)[:-1], path]
        for item in parts:
            if item.is_symlink() or (hasattr(item, 'is_junction') and item.is_junction()):
                raise ValueError('redirected package path: '+str(path))
    if not path.is_file() or path.is_symlink() or path.stat().st_nlink != 1:
        raise ValueError('expected an ordinary unshared source/artifact: '+str(path))
    before = path.stat()
    raw = path.read_bytes()
    after = path.stat()
    if (before.st_size, before.st_mtime_ns, before.st_ino) != (after.st_size, after.st_mtime_ns, after.st_ino):
        raise ValueError('source/artifact changed while reading')
    return raw


def read_file(root, name, observed):
    path = Path(root)/relative(name)
    raw = regular(path, root)
    observed[path.resolve()] = raw
    return raw


def validate_recipe(recipe):
    fields = {'schema_version', 'language', 'source', 'files', 'include_dirs', 'flags',
              'intrinsics', 'libraries', 'toolchain'}
    if not isinstance(recipe, dict) or set(recipe) != fields or type(recipe['schema_version']) is not int or recipe['schema_version'] != 1:
        raise ValueError('unsupported recovered recipe schema')
    if recipe['language'] not in ('c', 'c++'):
        raise ValueError('recipe language must be c or c++')
    files, flags = recipe['files'], recipe['flags']
    if not isinstance(files, list) or not files or len(files) != len(set(files)):
        raise ValueError('source file list is missing or duplicated')
    for name in files:
        path = relative(name)
        if path.suffix not in ('.c', '.cpp', '.h', '.hpp', '.hh', '.inc'):
            raise ValueError('only declared C/C++ source and headers belong in the package')
    if recipe['source'] not in files or PurePosixPath(recipe['source']).suffix != ('.c' if recipe['language'] == 'c' else '.cpp'):
        raise ValueError('translation unit does not match its declared language')
    if (not isinstance(flags, list) or any(f not in FLAGS for f in flags)
            or len(flags) != len(set(flags))
            or sum(f in ('/O1', '/O2', '/Od') for f in flags) != 1
            or sum(f.startswith('/arch:') for f in flags) != 1):
        raise ValueError('unsupported, contradictory, or file-bearing compiler flags')
    for group in (('/MD', '/MT'), ('/Oi', '/Oi-'), ('/Oy', '/Oy-'), ('/Gd', '/Gr', '/Gz')):
        if sum(f in flags for f in group) > 1:
            raise ValueError('contradictory compiler switches')
    if not isinstance(recipe['include_dirs'], list) or len(recipe['include_dirs']) != len(set(recipe['include_dirs'])):
        raise ValueError('invalid include directories')
    for name in recipe['include_dirs']:
        relative(name)
    if not isinstance(recipe['intrinsics'], list) or any(not re.fullmatch(r'[A-Za-z_][A-Za-z_0-9]*', x) for x in recipe['intrinsics']):
        raise ValueError('invalid intrinsic declaration')
    if recipe['libraries'] != []:
        raise ValueError('this recovered profile binds existing image symbols; binary library inputs need a separate recipe')
    toolchain = recipe['toolchain']
    if (not isinstance(toolchain, dict) or set(toolchain) != {'version', 'architecture', 'files'}
            or toolchain['version'] != support.COMPILER_VERSION or toolchain['architecture'] != 'x86'
            or not isinstance(toolchain['files'], dict) or set(toolchain['files']) != CORE_TOOLS
            or any(not support.is_digest(v) for v in toolchain['files'].values())):
        raise ValueError('the complete pinned VS2012 x86 compiler identity is required')
    return recipe


def without_comments(text, strings=False):
    def replace(match):
        value = match[0]
        if value.startswith(('/',)) or strings:
            return '\n'*value.count('\n')+' '
        return value
    return TOKEN.sub(replace, text.replace('\\\r\n', '').replace('\\\n', ''))


def check_source(text, intrinsics, *, preprocessed=False):
    if not isinstance(text, str) or '\0' in text or '??' in text:
        raise ValueError('source must be text without NULs or trigraphs')
    comments_removed = without_comments(text)
    code = without_comments(text, strings=True)
    if re.search(r'\b(?:__asm__|__asm|_asm|asm|_emit|__emit|naked)\b', code):
        raise ValueError('instruction assembly cannot be promoted as C/C++')
    if re.search(r'\b__declspec\s*\(\s*allocate\b', code):
        raise ValueError('manually placed executable data is outside this source profile')
    for line in comments_removed.splitlines():
        if re.match(r'\s*#\s*pragma\b', line):
            match = re.fullmatch(r'\s*#\s*pragma\s+(?:once|(intrinsic)\s*\(([^)]*)\))\s*', line)
            if not match or (match[1] and not set(x.strip() for x in match[2].split(',')).issubset(intrinsics)):
                raise ValueError('unlisted intrinsic or unsupported compiler pragma')
        if not preprocessed and re.match(r'\s*#\s*(?:line|include_next)\b', line):
            raise ValueError('source cannot redirect dependency line information')


def check_includes(recipe, contents):
    dependencies = set()
    for name, raw in contents.items():
        text = raw.decode('utf-8-sig')
        check_source(text, recipe['intrinsics'])
        for line in without_comments(text).splitlines():
            if not re.match(r'\s*#\s*include\b', line):
                continue
            match = re.fullmatch(r'\s*#\s*include\s*["<]([^">]+)[">]\s*', line)
            if not match:
                raise ValueError('includes must name a literal declared header')
            include = relative(match[1])
            search = [PurePosixPath(name).parent, *(PurePosixPath(p) for p in recipe['include_dirs'])]
            found = next((str(base/include) for base in search if str(base/include) in contents), None)
            if found is None:
                raise ValueError('include is outside the declared source closure: '+match[1])
            dependencies.add(found)
    return dependencies


def read_registry(root, observed):
    folder = Path(root).resolve()/'recon/ffx/recovered'
    registry = support.parse_json(read_file(folder, 'registry.json', observed), 'recovered registry')
    if (set(registry) != {'schema_version', 'target_sha256', 'modules'}
            or type(registry['schema_version']) is not int or registry['schema_version'] != 1
            or registry['target_sha256'] != TARGET or not isinstance(registry['modules'], list)):
        raise ValueError('invalid recovered registry target/schema')
    seen, ranges = set(), []
    for module in registry['modules']:
        if (not isinstance(module, dict) or set(module) != {'id', 'enabled', 'language', 'recipe', 'build_dir', 'proof', 'functions'}
                or not isinstance(module['id'], str) or not NAME.fullmatch(module['id']) or module['id'] in seen
                or type(module['enabled']) is not bool or module['language'] not in ('c', 'c++')
                or not isinstance(module['functions'], list) or not module['functions']):
            raise ValueError('invalid or duplicate recovered module')
        seen.add(module['id'])
        for key in ('recipe', 'build_dir', 'proof'):
            relative(module[key])
        function_names, own_ranges = set(), []
        for item in module['functions']:
            if not isinstance(item, dict) or set(item) != {'va', 'size', 'symbol', 'contract', 'bindings'}:
                raise ValueError('invalid recovered function declaration')
            va, size = item['va'], item['size']
            if type(va) is not int or type(size) is not int or not 0x401000 <= va < va+size <= 0xb0bc00:
                raise ValueError('invalid recovered function interval')
            if not isinstance(item['symbol'], str) or not item['symbol'] or '\0' in item['symbol'] or item['symbol'] in function_names:
                raise ValueError('invalid or duplicate complete COFF function name')
            function_names.add(item['symbol'])
            relative(item['contract'])
            if not isinstance(item['bindings'], dict) or any(not isinstance(k, str) or not k or not isinstance(v, str) or not SYMBOL.fullmatch(v) for k, v in item['bindings'].items()):
                raise ValueError('bindings must use complete COFF names and canonical image symbols')
            own_ranges.append((va, size))
        support.check_ranges(own_ranges, 'module functions')
        if module['enabled']:
            ranges.extend(own_ranges)
    support.check_ranges(ranges, 'active recovered functions')
    return registry


def module_declaration(module):
    return {k: module[k] for k in ('id', 'language', 'functions')}


def package_inputs(root, module_id, observed):
    registry = read_registry(root, observed)
    modules = [m for m in registry['modules'] if m['id'] == module_id]
    if len(modules) != 1:
        raise ValueError('unknown recovered module: '+module_id)
    module = modules[0]
    folder = Path(root).resolve()/'recon/ffx/recovered'
    recipe_raw = read_file(folder, module['recipe'], observed)
    recipe = validate_recipe(support.parse_json(recipe_raw, 'recovered recipe'))
    if recipe['language'] != module['language']:
        raise ValueError('module and compiler language differ')
    sources = {name: read_file(folder, name, observed) for name in recipe['files']}
    check_includes(recipe, sources)
    contracts = {item['contract']: read_file(folder, item['contract'], observed) for item in module['functions']}
    helpers = {name: regular(TOOLS/name) for name in HELPERS}
    observed.update({(TOOLS/name).resolve(): raw for name, raw in helpers.items()})
    declaration = json_bytes(module_declaration(module))
    stage_manifest = {'schema_version': 1, 'target_sha256': TARGET,
                      'module_sha256': support.digest(declaration), 'recipe_sha256': support.digest(recipe_raw),
                      'sources': {k: support.digest(v) for k, v in sources.items()},
                      'contracts': {k: support.digest(v) for k, v in contracts.items()},
                      'helpers': {k: support.digest(v) for k, v in helpers.items()}}
    return module, recipe, stage_manifest, sources, contracts, helpers, recipe_raw, declaration


def empty_output(output):
    output = Path(output).absolute()
    if output.is_symlink() or any(p.is_symlink() for p in output.parents):
        raise ValueError('output must not be redirected')
    if output.exists() and (not output.is_dir() or any(output.iterdir())):
        raise ValueError('a new empty output directory is required')
    output.mkdir(parents=True, exist_ok=True)
    return output.resolve()


def stage(root, module_id, output):
    observed = {}
    module, recipe, manifest, sources, contracts, helpers, recipe_raw, declaration = package_inputs(root, module_id, observed)
    output = empty_output(output)
    for prefix, files in [('inputs', sources), ('contracts', contracts), ('helpers', helpers)]:
        for name, raw in files.items():
            path = output/prefix/name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(raw)
    (output/'recipe.json').write_bytes(recipe_raw)
    (output/'module.json').write_bytes(declaration)
    support.check_unchanged(observed)
    (output/'stage.json').write_bytes(json_bytes(manifest))
    return manifest


def read_stage(package):
    package = Path(package).resolve()
    manifest_raw = regular(package/'stage.json', package)
    manifest = support.parse_json(manifest_raw, 'staged recovered package')
    if set(manifest) != {'schema_version', 'target_sha256', 'module_sha256', 'recipe_sha256', 'sources', 'contracts', 'helpers'} or manifest['schema_version'] != 1 or manifest['target_sha256'] != TARGET:
        raise ValueError('invalid staged package schema')
    observed = {package/'stage.json': manifest_raw}
    groups = {}
    for key, prefix in [('sources', 'inputs'), ('contracts', 'contracts'), ('helpers', 'helpers')]:
        if not isinstance(manifest[key], dict) or not manifest[key]:
            raise ValueError('staged inputs are missing')
        groups[key] = {}
        for name, digest in manifest[key].items():
            relative(name)
            raw = read_file(package, prefix+'/'+name, observed)
            if not support.is_digest(digest) or support.digest(raw) != digest:
                raise ValueError('staged '+key+' changed: '+name)
            groups[key][name] = raw
    if set(groups['helpers']) != set(HELPERS):
        raise ValueError('staged build helper closure differs')
    recipe_raw = read_file(package, 'recipe.json', observed)
    module_raw = read_file(package, 'module.json', observed)
    if support.digest(recipe_raw) != manifest['recipe_sha256'] or support.digest(module_raw) != manifest['module_sha256']:
        raise ValueError('staged recipe/module changed')
    recipe = validate_recipe(support.parse_json(recipe_raw, 'staged recipe'))
    if set(groups['sources']) != set(recipe['files']):
        raise ValueError('recipe and staged file closure differ')
    check_includes(recipe, groups['sources'])
    return manifest, recipe, support.parse_json(module_raw, 'module'), groups, observed


def clean_environment(environment):
    return {key.upper(): value for key, value in environment.items()
            if key.upper() not in ('CL', '_CL_', 'LINK', '_LINK_')}


def compile_package(package, output):
    """Compile a closed snapshot in a new directory; publish success last."""
    if os.name != 'nt':
        raise RuntimeError('compile requires the Windows VS2012 x86 toolchain')
    manifest, recipe, module, groups, inputs = read_stage(package)
    for name in HELPERS:
        if regular(TOOLS/name) != groups['helpers'][name]:
            raise ValueError('running compiler helper differs from the staged helper')
    output = empty_output(output)
    started = time.time_ns()
    build_id = uuid.uuid4().hex
    try:
        snapshot = output/'package'
        snapshot.mkdir()
        for path, raw in inputs.items():
            target = snapshot/path.relative_to(Path(package).resolve())
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(raw)
        _, _, _, _, snapshot_inputs = read_stage(snapshot)
        inputs.update(snapshot_inputs)
        with (output/'environment.log').open('xb') as log:
            environment = clean_environment(support.compiler_environment(log))
        environment.update(VSLANG='1033', SOURCE_DATE_EPOCH='0')
        (output/'tmp').mkdir()
        environment['TMP'] = environment['TEMP'] = str(output/'tmp')
        compiler_name = shutil.which('cl.exe', path=environment.get('PATH'))
        if compiler_name is None:
            raise ValueError('pinned MSVC compiler is unavailable')
        compiler = Path(compiler_name).resolve()
        pinned = {str(compiler.with_name(name)): support.digest(regular(compiler.with_name(name)))
                  for name in CORE_TOOLS}
        if {Path(p).name.lower(): v for p, v in pinned.items()} != recipe['toolchain']['files']:
            raise ValueError('installed compiler/backend hashes differ from the recipe')
        invocations = []
        for phase in ('preprocess', 'compile'):
            support.check_unchanged(inputs)
            argv = compiler_command(str(compiler), recipe, phase)
            product = output/('preprocessed.i' if phase == 'preprocess' else 'module.obj')
            if product.exists():
                raise ValueError('compiler output existed before this invocation')
            trace = recovered_win32.run(argv, output, environment, output/(phase+'.log'))
            (output/(phase+'-trace.json')).write_bytes(json_bytes(trace))
            validate_runtime(trace, argv, recipe, phase)
            log_raw = regular(output/(phase+'.log'), output)
            versions = re.findall(r'Compiler Version ([0-9.]+) for x86', log_raw.decode('utf-8', errors='replace'))
            if versions != [support.COMPILER_VERSION]:
                raise ValueError('compiler banner does not identify the pinned x86 version')
            dependencies = include_dependencies(log_raw, recipe, str(output))
            if not product.is_file() or not product.stat().st_size:
                raise ValueError('successful command did not create a new compiler output')
            support.check_unchanged(inputs)
            invocations.append({'phase': phase, 'argv': argv, 'dependencies': dependencies,
                                'output': product.name, 'output_was_absent': True,
                                'exit_code': trace['exit_code']})
            if phase == 'preprocess':
                check_source(product.read_text(encoding='utf-8-sig', errors='strict'),
                             recipe['intrinsics'], preprocessed=True)
        if invocations[0]['dependencies'] != invocations[1]['dependencies']:
            raise ValueError('preprocessing and compilation used different includes')
        obj = coff.parse_coff(regular(output/'module.obj', output))
        for name, expected in pinned.items():
            if support.digest(regular(name)) != expected:
                raise ValueError('pinned compiler changed during the build')
        output_names = ['module.obj', 'preprocessed.i', 'environment.log', 'preprocess.log',
                        'compile.log', 'preprocess-trace.json', 'compile-trace.json']
        artifacts = {name: support.digest(regular(output/name, output)) for name in output_names}
        receipt = {'schema_version': 1, 'status': 'complete', 'build_id': build_id,
                   'started_ns': started, 'finished_ns': time.time_ns(),
                   'module_id': module['id'], 'language': recipe['language'],
                   'stage_sha256': support.digest(regular(snapshot/'stage.json', snapshot)),
                   'compiler': str(compiler), 'compiler_version': support.COMPILER_VERSION,
                   'compiler_architecture': 'x86', 'pinned_tools': pinned,
                   'workdir': str(output), 'invocations': invocations, 'outputs': artifacts,
                   'object_summary': object_summary(obj), 'inherited_flags_cleared': True,
                   'fresh_directory': True, 'linked_binary_libraries': []}
        support.check_unchanged(inputs)
        (output/'compile.json').write_bytes(json_bytes(receipt))
        return receipt
    except BaseException as exc:
        (output/'compile.json').unlink(missing_ok=True)
        (output/'failure.json').write_bytes(json_bytes({'build_id': build_id, 'status': 'failed',
            'exception': type(exc).__name__, 'message': str(exc), 'started_ns': started}))
        raise


def compiler_command(compiler, recipe, phase):
    if phase not in ('preprocess', 'compile'):
        raise ValueError('unknown compiler phase')
    flags = ['/c', '/X', '/Gy', '/Zl', '/showIncludes', '/TC' if recipe['language'] == 'c' else '/TP']
    flags += recipe['flags']
    flags += ['/Ipackage/inputs/'+name for name in recipe['include_dirs']]
    flags += ['/P', '/Fipreprocessed.i'] if phase == 'preprocess' else ['/Fomodule.obj']
    return [compiler, *flags, 'package/inputs/'+recipe['source']]


def validate_runtime(trace, argv, recipe, phase):
    if (not isinstance(trace, dict) or trace.get('schema_version') != 1
            or trace.get('method') != 'Windows DEBUG_PROCESS module/exit events'
            or trace.get('argv') != argv or trace.get('exit_code') != 0
            or trace.get('all_processes_exited') is not True
            or trace.get('all_processes_succeeded') is not True):
        raise ValueError('compiler process audit is incomplete or unsuccessful')
    events, loaded, processes, exits = trace.get('events'), {}, set(), {}
    if not isinstance(events, list) or not events:
        raise ValueError('compiler module events are missing')
    for event in events:
        if not isinstance(event, dict) or type(event.get('pid')) is not int:
            raise ValueError('invalid compiler process event')
        if event.get('kind') in ('process', 'dll'):
            name, digest = event.get('path'), event.get('sha256')
            if not isinstance(name, str) or not PureWindowsPath(name).is_absolute() or not support.is_digest(digest):
                raise ValueError('invalid consumed compiler module identity')
            if name in loaded and loaded[name] != digest:
                raise ValueError('compiler library identity changed in the trace')
            loaded[name] = digest
            if event['kind'] == 'process':
                if event['pid'] in processes:
                    raise ValueError('duplicate compiler process start')
                processes.add(event['pid'])
        elif event.get('kind') == 'exit':
            if event['pid'] in exits or type(event.get('exit_code')) is not int or event['exit_code'] != 0:
                raise ValueError('compiler child failed or has duplicate exit events')
            exits[event['pid']] = 0
        elif event.get('kind') != 'exception':
            raise ValueError('unsupported compiler process event')
    if not processes or set(exits) != processes or trace.get('root_pid') not in processes or loaded != trace.get('loaded_files'):
        raise ValueError('compiler trace closure is inconsistent')
    roots = [e for e in events if e['kind'] == 'process' and e['pid'] == trace['root_pid']]
    if len(roots) != 1 or PureWindowsPath(roots[0]['path']) != PureWindowsPath(argv[0]):
        raise ValueError('trace executed a different compiler')
    required = {'cl.exe', 'c1.dll' if recipe['language'] == 'c' else 'c1xx.dll'}
    if phase == 'compile':
        required.add('c2.dll')
    for name in required:
        matches = [digest for path, digest in loaded.items() if PureWindowsPath(path).name.lower() == name]
        if matches != [recipe['toolchain']['files'][name]]:
            raise ValueError('compiler did not consume the pinned backend: '+name)


def include_dependencies(log, recipe, workdir):
    base = PureWindowsPath(workdir)/'package'/'inputs'
    known = {str(base/relative(name)).casefold(): name for name in recipe['files']}
    found = {recipe['source']}
    for line in log.decode('utf-8', errors='replace').splitlines():
        match = re.match(r'^Note: including file:\s+(.+?)\s*$', line)
        if match:
            path = PureWindowsPath(match[1].strip())
            if not path.is_absolute():
                path = PureWindowsPath(workdir)/path
            name = known.get(str(path).casefold())
            if name is None:
                raise ValueError('compiler consumed an undeclared include: '+str(path))
            found.add(name)
    return sorted(found)


def object_summary(obj):
    return {'machine': obj['machine'], 'timestamp': obj['timestamp'],
            'sections': [{'index': s['index'], 'name': s['name'], 'size': s['raw_size'],
                          'sha256': support.digest(s['raw']), 'characteristics': s['characteristics'],
                          'relocations': [{k: r[k] for k in ('offset', 'type', 'symbol_index', 'symbol_name')}
                                          for r in s['relocations']]} for s in obj['sections']],
            'symbols': [{k: s[k] for k in ('name', 'index', 'value', 'section', 'storage', 'type', 'auxiliary_count')}
                        for s in obj['symbols'].values()]}


def read_receipt(root, module_id, directory, observed):
    """Bind a transported Windows receipt to current source and actual COFF bytes."""
    directory = Path(directory).resolve()
    module, recipe, expected, *_ = package_inputs(root, module_id, observed)
    actual, _, declaration, groups, retained = read_stage(directory/'package')
    observed.update(retained)
    if actual != expected or declaration != module_declaration(module):
        raise ValueError('recovered sources, contract, recipe, or build helpers changed after compilation')
    raw = read_file(directory, 'compile.json', observed)
    receipt = support.parse_json(raw, 'recovered compiler receipt')
    fields = {'schema_version', 'status', 'build_id', 'started_ns', 'finished_ns', 'module_id',
              'language', 'stage_sha256', 'compiler', 'compiler_version', 'compiler_architecture',
              'pinned_tools', 'workdir', 'invocations', 'outputs', 'object_summary',
              'inherited_flags_cleared', 'fresh_directory', 'linked_binary_libraries'}
    if (set(receipt) != fields or receipt['schema_version'] != 1 or receipt['status'] != 'complete'
            or receipt['module_id'] != module_id or receipt['language'] != recipe['language']
            or receipt['compiler_version'] != support.COMPILER_VERSION or receipt['compiler_architecture'] != 'x86'
            or receipt['inherited_flags_cleared'] is not True or receipt['fresh_directory'] is not True
            or receipt['linked_binary_libraries'] != [] or not re.fullmatch('[0-9a-f]{32}', receipt['build_id'])
            or type(receipt['started_ns']) is not int or type(receipt['finished_ns']) is not int
            or receipt['finished_ns'] <= receipt['started_ns']
            or receipt['stage_sha256'] != support.digest(retained[directory/'package/stage.json'])):
        raise ValueError('recovered compiler receipt is incomplete or stale')
    pinned = {PureWindowsPath(p).name.lower(): v for p, v in receipt['pinned_tools'].items()}
    if len(pinned) != len(receipt['pinned_tools']) or pinned != recipe['toolchain']['files']:
        raise ValueError('compiler receipt toolchain differs from the recipe')
    required_outputs = {'module.obj', 'preprocessed.i', 'environment.log', 'preprocess.log',
                        'compile.log', 'preprocess-trace.json', 'compile-trace.json'}
    if not isinstance(receipt['outputs'], dict) or set(receipt['outputs']) != required_outputs:
        raise ValueError('compiler output receipt is incomplete')
    outputs = {}
    for name, digest in receipt['outputs'].items():
        content = read_file(directory, name, observed)
        if not support.is_digest(digest) or support.digest(content) != digest:
            raise ValueError('compiler output changed: '+name)
        outputs[name] = content
    invocations = receipt['invocations']
    if not isinstance(invocations, list) or len(invocations) != 2:
        raise ValueError('both fresh preprocessing and compilation are required')
    for phase, invocation in zip(('preprocess', 'compile'), invocations):
        command = compiler_command(receipt['compiler'], recipe, phase)
        dependencies = include_dependencies(outputs[phase+'.log'], recipe, receipt['workdir'])
        expected_invocation = {'phase': phase, 'argv': command, 'dependencies': dependencies,
            'output': 'preprocessed.i' if phase == 'preprocess' else 'module.obj',
            'output_was_absent': True, 'exit_code': 0}
        if invocation != expected_invocation:
            raise ValueError('actual compiler invocation differs from the closed recipe')
        trace = support.parse_json(outputs[phase+'-trace.json'], 'compiler process trace')
        if trace.get('cwd') != receipt['workdir']:
            raise ValueError('compiler trace belongs to another working directory')
        validate_runtime(trace, command, recipe, phase)
        versions = re.findall(r'Compiler Version ([0-9.]+) for x86', outputs[phase+'.log'].decode(errors='replace'))
        if versions != [support.COMPILER_VERSION]:
            raise ValueError('compiler log does not prove the pinned compiler version')
    if invocations[0]['dependencies'] != invocations[1]['dependencies']:
        raise ValueError('preprocessing and compilation dependencies differ')
    check_source(outputs['preprocessed.i'].decode('utf-8-sig'), recipe['intrinsics'], preprocessed=True)
    obj = coff.parse_coff(outputs['module.obj'])
    if object_summary(obj) != receipt['object_summary']:
        raise ValueError('actual COFF symbols/sections/relocations differ from the receipt')
    return module, recipe, receipt, obj


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='action', required=True)
    staged = commands.add_parser('stage')
    staged.add_argument('--root', type=Path, default=ROOT)
    staged.add_argument('--module', required=True)
    staged.add_argument('--output', type=Path, required=True)
    compiled = commands.add_parser('compile')
    compiled.add_argument('--package', type=Path, required=True)
    compiled.add_argument('--output', type=Path, required=True)
    verified = commands.add_parser('verify')
    verified.add_argument('--root', type=Path, default=ROOT)
    verified.add_argument('--module', required=True)
    verified.add_argument('--build-dir', type=Path, required=True)
    verified.add_argument('--proof', type=Path, required=True)
    args = parser.parse_args()
    if args.action == 'stage':
        result = stage(args.root, args.module, args.output)
    elif args.action == 'compile':
        result = compile_package(args.package, args.output)
    else:
        import recovered_providers
        result = recovered_providers.verify(args.root, args.module, args.build_dir, args.proof)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
