#!/usr/bin/env python3
"""Reference-free MCWL assembly build with immutable inputs and a final receipt."""
import argparse
import json
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import leaf_build as support

ROOT=Path(__file__).resolve().parents[2]
OUTPUTS=('mcwl.o','mcwl.bin','mcwl.obj','mcwl_semantics','build.log')


def input_paths(root):
    return {'source':root/'recon/ffx/phyre_memcmp_with_length.S',
            'harness':root/'recon/ffx/byteproof/mcwl_semantics.c',
            'builder':Path(__file__).resolve()}


def build(root,output):
    output.mkdir(parents=True,exist_ok=True)
    for name in ('build-manifest.json','proof.json'):
        (output/name).unlink(missing_ok=True)
    paths=input_paths(root)
    contents={key:path.read_bytes() for key,path in paths.items()}
    tools={name:Path(shutil.which(name) or '').resolve() for name in ('as','objcopy','gcc')}
    tool_data={path:path.read_bytes() for path in tools.values()}
    observed={paths[key]:raw for key,raw in contents.items()}
    observed.update(tool_data)
    log=bytearray()
    commands=[]
    with tempfile.TemporaryDirectory(prefix='mcwl-',dir=output) as tmp:
        work=Path(tmp)
        (work/'inputs').mkdir()
        for key,raw in contents.items():
            path=work/'inputs'/paths[key].name
            path.write_bytes(raw)
            observed[path]=raw

        def run(command):
            support.check_unchanged(observed)
            commands.append(command)
            result=subprocess.run(command,cwd=work,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
            log.extend(('> '+json.dumps(command)+'\n').encode()+result.stdout+
                       ('\nexit_code='+str(result.returncode)+'\n').encode())
            (output/'build.log').write_bytes(bytes(log))
            if result.returncode:
                raise ValueError('native MCWL command failed: '+str(result.returncode))
            support.check_unchanged(observed)
            return result.stdout.decode('utf-8',errors='replace').strip()

        assembler_version=run([str(tools['as']),'--version']).splitlines()[0]
        compiler_version=run([str(tools['gcc']),'--version']).splitlines()[0]
        run([str(tools['as']),'--32','inputs/phyre_memcmp_with_length.S','-o','mcwl.o'])
        run([str(tools['objcopy']),'-O','binary','--only-section=.text','mcwl.o','mcwl.bin'])
        run([str(tools['objcopy']),'-O','pe-i386','--prefix-symbols=_','mcwl.o','mcwl.obj'])
        run([str(tools['gcc']),'-m32','-march=i386','-O2','-ffreestanding','-fno-builtin',
             '-fno-stack-protector','-fno-pic','-fno-pie','-nostdlib','-static','-no-pie',
             '-Wl,-e,_start','inputs/mcwl_semantics.c','mcwl.o','-o','mcwl_semantics'])
        result=run([str(work/'mcwl_semantics')])
        if not re.fullmatch('checks=[0-9]+',result) or int(result[7:])!=87645:
            raise ValueError('semantic harness did not execute all 87645 cases')
        artifacts={name:(work/name).read_bytes() for name in OUTPUTS if name!='build.log'}
        artifacts['build.log']=bytes(log)
        (output/'inputs').mkdir(exist_ok=True)
        for key,raw in contents.items():
            (output/'inputs'/paths[key].name).write_bytes(raw)
        for name,raw in artifacts.items():
            (output/name).write_bytes(raw)
        support.check_unchanged(observed)
    receipt={'schema_version':1,'status':'complete','semantic_checks':87645,'semantic_exit_code':0,
             'assembler_version':assembler_version,'compiler_version':compiler_version,'commands':commands,
             'inputs':{key:{'file':'inputs/'+paths[key].name,'sha256':support.digest(raw)}
                       for key,raw in contents.items()},
             'outputs':{name:{'file':name,'sha256':support.digest(raw)} for name,raw in artifacts.items()},
             'tools':{str(path):support.digest(raw) for path,raw in tool_data.items()}}
    pending=output/'build-manifest.json.tmp'
    pending.write_text(json.dumps(receipt,indent=2)+'\n')
    pending.replace(output/'build-manifest.json')
    try:
        read_bundle(root,output)
    except (ValueError,OSError):
        (output/'build-manifest.json').unlink(missing_ok=True)
        raise
    return receipt


def read_bundle(root,output):
    path=output/'build-manifest.json'
    receipt_data=path.read_bytes()
    receipt=support.parse_json(receipt_data,'MCWL receipt')
    if (receipt.get('schema_version')!=1 or receipt.get('status')!='complete'
            or receipt.get('semantic_checks')!=87645 or receipt.get('semantic_exit_code')!=0):
        raise ValueError('MCWL receipt is incomplete')
    observed={path:receipt_data}
    paths=input_paths(root)
    if set(receipt['inputs'])!=set(paths) or set(receipt['outputs'])!=set(OUTPUTS):
        raise ValueError('MCWL receipt has missing or additional inputs/outputs')
    for key,current in paths.items():
        entry=receipt['inputs'][key]
        if entry['file']!='inputs/'+current.name:
            raise ValueError('MCWL input path differs')
        snapshot=output/entry['file']
        raw=snapshot.read_bytes()
        if support.digest(raw)!=entry['sha256'] or current.read_bytes()!=raw:
            raise ValueError('MCWL '+key+' differs from retained build-time snapshot')
        observed[current]=observed[snapshot]=raw
    outputs={}
    for name in OUTPUTS:
        entry=receipt['outputs'][name]
        if entry['file']!=name:
            raise ValueError('MCWL output path differs')
        path=output/name
        raw=path.read_bytes()
        if support.digest(raw)!=entry['sha256']:
            raise ValueError('MCWL artifact changed: '+name)
        outputs[name]=raw
        observed[path]=raw
    for name,digest in receipt['tools'].items():
        path=Path(name)
        raw=path.read_bytes()
        if support.digest(raw)!=digest:
            raise ValueError('MCWL assembler/compiler changed')
        observed[path]=raw
    support.check_unchanged(observed)
    return receipt,outputs,observed


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/byteproof/build')
    args=parser.parse_args()
    build(args.root,args.output)
