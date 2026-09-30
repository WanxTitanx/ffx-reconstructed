#!/usr/bin/env python3
"""Build symbolic C using retained inputs and pinned VS2012."""
import argparse
import json
import shutil
import tempfile
from pathlib import Path
import leaf_build as support
INPUTS=('symbolic_leaf.c','jobs.json','generator.py','build.bat','relocation_build.py','leaf_build.py')


def build(package,output):
    output.mkdir(parents=True,exist_ok=True)
    for path in (output/'build-manifest.json',output/'proof.json',package/'proof.json'):
        path.unlink(missing_ok=True)
    contents={name:(package/name).read_bytes() for name in INPUTS}
    jobs=support.parse_json(contents['jobs.json'],'jobs')
    if support.digest(contents['symbolic_leaf.c']) != jobs['source_sha256']:
        raise ValueError('source hash differs from jobs')
    if support.digest(contents['generator.py']) != jobs['generator_sha256']:
        raise ValueError('generator hash differs from jobs')
    return compile_inputs(package,output,contents)


def compile_inputs(package,output,contents):
    observed={package/name:data for name,data in contents.items()}
    commands,artifacts=[],{}
    with (output/'build.log').open('wb') as log:
        env=support.compiler_environment(log)
        compiler=shutil.which('cl.exe',path=env.get('PATH'))
        if compiler is None:
            raise ValueError('VS2012 compiler is unavailable')
        with tempfile.TemporaryDirectory(prefix='reloc-build-',dir=output) as tmp:
            work=Path(tmp)
            (work/'inputs').mkdir()
            for name,data in contents.items():
                path=work/'inputs'/name
                path.write_bytes(data)
                observed[path]=data
            for variant,opt,frame in (('O2','/O2','/Oy-'),('O1','/O1','/Oy-'),('Oy','/O2','/Oy')):
                support.check_unchanged(observed)
                cmd=[compiler,'/c','/GS-',opt,'/MD',frame,'/Oi','/arch:IA32','/Gy',
                     'inputs/symbolic_leaf.c','/Fo'+variant+'.obj']
                commands.append(cmd)
                support.run_compiler(cmd,work,env,log)
                support.check_unchanged(observed)
                artifacts[variant+'.obj']=(work/(variant+'.obj')).read_bytes()
            for name,data in artifacts.items():
                observed[work/name]=data
            support.check_unchanged(observed)
            (output/'inputs').mkdir(exist_ok=True)
            for name,data in contents.items():
                (output/'inputs'/name).write_bytes(data)
            for name,data in artifacts.items():
                (output/name).write_bytes(data)
    return publish(package,output,contents,artifacts,commands)


def publish(package,output,contents,artifacts,commands):
    observed={package/name:data for name,data in contents.items()}
    observed.update({output/'inputs'/name:data for name,data in contents.items()})
    observed.update({output/name:data for name,data in artifacts.items()})
    log=(output/'build.log').read_bytes()
    observed[output/'build.log']=log
    support.check_unchanged(observed)
    compiler=Path(commands[0][0])
    tool_hashes={str(compiler):support.digest(compiler.read_bytes())}
    for name in ('c1.dll','c2.dll'):
        path=compiler.with_name(name)
        if path.is_file():
            tool_hashes[str(path)]=support.digest(path.read_bytes())
    manifest={'schema_version':1,'status':'complete','compiler_version':support.COMPILER_VERSION,
              'compiler_architecture':'x86','commands':commands,'tool_hashes':tool_hashes,
              'inputs':{name:{'file':'inputs/'+name,'sha256':support.digest(data)}
                        for name,data in contents.items()},
              'outputs':{name:{'file':name,'sha256':support.digest(data)}
                         for name,data in dict(artifacts,**{'build.log':log}).items()}}
    pending=output/'build-manifest.json.tmp'
    pending.write_bytes((json.dumps(manifest,indent=2)+'\n').encode())
    pending.replace(output/'build-manifest.json')
    print('Symbolic C build complete; all inputs and COFF outputs bound in manifest')
    return manifest


def main():
    package=Path(__file__).resolve().parent
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir',type=Path,default=package/'build')
    args=parser.parse_args()
    build(package,args.output_dir.resolve())
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
