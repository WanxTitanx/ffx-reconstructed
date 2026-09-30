#!/usr/bin/env python3
"""Resolve compiler relocations through explicit layout symbols and compare literal bytes."""
import argparse
import bisect
import json
import re
import struct
from pathlib import Path
import coff_relocations as coff
import definitive_match as exact
import leaf_reconstruct as leaf
import leaf_build as support
import relocation_build as build
import symbolic_leaf as symbolic
ROOT=Path(__file__).resolve().parents[2]


def link_function(section,va,size,expected,bindings):
    if len(section['raw'])!=size or not section['characteristics']&0x20:
        raise ValueError('function is not its complete code section')
    observed=[]
    for record in section['relocations']:
        if record['type']==0:
            continue
        offset=record['offset']
        if offset<0 or offset+4>size:
            raise ValueError('relocation outside function')
        observed.append({'offset':offset,'type':record['type'],'symbol':record['symbol_name'],
                         'addend':struct.unpack_from('<i',section['raw'],offset)[0]})
    if observed!=expected:
        raise ValueError('COFF operand relocations do not match selected symbolic references')
    return coff.relocate(section,va,bindings)


def read_bundle(package):
    directory=package/'build'
    receipt=(directory/'build-manifest.json').read_bytes()
    manifest=support.parse_json(receipt,'relocation build manifest')
    if manifest.get('schema_version')!=1 or manifest.get('status')!='complete':
        raise ValueError('incomplete build manifest')
    observed={directory/'build-manifest.json':receipt}
    inputs={}
    for name in build.INPUTS:
        entry=manifest['inputs'][name]
        if entry['file']!='inputs/'+name:
            raise ValueError('manifest redirects an input')
        raw=(directory/entry['file']).read_bytes()
        if support.digest(raw)!=entry['sha256'] or (package/name).read_bytes()!=raw:
            raise ValueError('stale or modified build input: '+name)
        observed[directory/entry['file']]=raw
        observed[package/name]=raw
        inputs[name]=raw
    outputs={}
    for name in ('O2.obj','O1.obj','Oy.obj','build.log'):
        entry=manifest['outputs'][name]
        raw=(directory/name).read_bytes()
        if entry['file']!=name or support.digest(raw)!=entry['sha256']:
            raise ValueError('modified build output: '+name)
        outputs[name]=raw
        observed[directory/name]=raw
    return inputs,outputs,manifest,receipt,observed


def verify(package,project):
    (package/'proof.json').unlink(missing_ok=True)
    inputs,outputs,manifest,receipt,observed=read_bundle(package)
    versions=re.findall(r'Compiler Version ([0-9.]+) for x86',outputs['build.log'].decode(errors='replace'))
    if versions!=[support.COMPILER_VERSION]*3 or manifest['compiler_version']!=support.COMPILER_VERSION:
        raise ValueError('unexpected compiler')
    for filename,module in (('generator.py',symbolic),('relocation_build.py',build),('leaf_build.py',support)):
        if inputs[filename]!=Path(module.__file__).read_bytes():
            raise ValueError('current build logic differs from retained snapshot')
    jobs=support.parse_json(inputs['jobs.json'],'symbolic jobs')
    if jobs['source_sha256']!=support.digest(inputs['symbolic_leaf.c']):
        raise ValueError('jobs/source mismatch')
    inventory_path=project/'tools/match/inventory.tsv'
    inventory_data=inventory_path.read_bytes()
    if support.digest(inventory_data)!=jobs['inventory_sha256']:
        raise ValueError('inventory changed since selection')
    observed[inventory_path]=inventory_data
    inventory={r['va']:r for r in leaf.inventory_rows(inventory_data)}
    original,sections=exact.load_pe(exact.EXE_DEFAULT)
    if support.digest(original)!=exact.EXE_SHA256 or jobs['target_sha256']!=exact.EXE_SHA256:
        raise ValueError('reference changed')
    read=exact.va_reader(original,sections)
    pe_relocs=leaf.pe_relocations(original,sections)
    bindings={}
    for item in jobs['symbols']:
        if item!=symbolic.symbol_record(item['va'],sections,inventory):
            raise ValueError('symbol placement disagrees with selected PE section')
        name='_'+item['name']
        if name in bindings:
            raise ValueError('duplicate binding')
        bindings[name]=item['va']
    parsed={name:coff.parse_coff(raw) for name,raw in outputs.items() if name.endswith('.obj')}
    functions={}
    for name,obj in parsed.items():
        functions[name]={}
        for sym in obj['symbols'].values():
            m=re.fullmatch(r'[@_](leaf_[0-9a-f]{8})(?:@[0-9]+)?',sym['name'])
            if m and sym['storage']==2 and sym['type']&0x20 and sym['section']>0:
                if sym['value'] or m[1] in functions[name]:
                    raise ValueError('function is not an independent COFF section')
                functions[name][m[1]]=obj['sections'][sym['section']-1]
    return verify_targets(package,jobs,inventory,read,pe_relocs,bindings,functions,
                          outputs,receipt,observed)


def verify_targets(package,jobs,inventory,read,pe_relocs,bindings,functions,outputs,receipt,observed):
    targets=[t for g in jobs['groups'] for t in g['targets']]
    support.check_ranges([(t['va'],t['size']) for t in targets],'symbolic target')
    matched,unmatched=[],[]
    for group in jobs['groups']:
        for target in group['targets']:
            va,size=target['va'],target['size']
            if inventory.get(va)!=target:
                raise ValueError('target inventory mismatch')
            reference=read(va,size)
            if reference is None or support.digest(reference)!=target['sha256']:
                raise ValueError('reference body changed')
            offsets=[p-va for p in pe_relocs[bisect.bisect_left(pe_relocs,va-3):bisect.bisect_left(pe_relocs,va+size)]]
            expected=group['relocations']
            if len(expected)!=1 or offsets!=[expected[0]['offset']]:
                raise ValueError('selected relocations differ from real PE directory')
            symbol=expected[0]['symbol']
            if int.from_bytes(reference[offsets[0]:offsets[0]+4],'little')!=bindings[symbol]:
                raise ValueError('symbol points at a different original target')
            if symbolic.source_spec(reference,offsets,symbol[1:])!=group['source']:
                raise ValueError('source specification differs from selected operation')
            for variant,table in functions.items():
                section=table.get(group['symbol'])
                if section is None:
                    continue
                try:
                    linked,evidence=link_function(section,va,size,expected,bindings)
                except ValueError:
                    continue
                if linked==reference:
                    matched.append(dict(target,symbol=group['symbol'],variant=variant,
                        object_sha256=support.digest(outputs[variant]),section_index=section['index'],
                        code_sha256=support.digest(linked),relocations=evidence,masked_bytes=0))
                    break
            else:
                unmatched.append(dict(target,symbol=group['symbol'],reason='symbolic_codegen_mismatch'))
    report={'target_sha256':exact.EXE_SHA256,'build_manifest_sha256':support.digest(receipt),
            'jobs_sha256':support.digest((package/'jobs.json').read_bytes()),
            'linker_sha256':support.digest(Path(coff.__file__).read_bytes()),
            'functions':matched,'unmatched':unmatched,'exact_functions':len(matched),
            'exact_bytes':sum(t['size'] for t in matched),'real_relocations':len(matched),
            'build_provenance_verified':True,'data_dependency_closure_verified':False,
            'whole_executable_reconstructed':False,'method':'COFF record resolution, then literal equality'}
    support.check_unchanged(observed)
    (package/'proof.json').write_bytes((json.dumps(report,indent=2)+'\n').encode())
    print('Literal symbolic-link matches:',len(matched),'functions;',report['exact_bytes'],
          'bytes;',len(unmatched),'codegen mismatches')
    return report


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--package',type=Path,default=ROOT/'recon/ffx/c_reloc')
    parser.add_argument('--project',type=Path,default=leaf.DEFAULT_PROJECT)
    args=parser.parse_args()
    verify(args.package,args.project)
