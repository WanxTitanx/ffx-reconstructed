#!/usr/bin/env python3
"""Admit previously built source-backed code sections into the complete link.

No reference executable is opened here. Source receipts and complete section
hashes establish the provider cache; the final image comparison is independent.
"""
import json
import re
import struct
from pathlib import Path
import coff_relocations as coff
import definitive_match as exact
import leaf_build as support
import symbolic_verify
import verify_ffx_memcmp
import mcwl_build


def section_for_symbol(obj,logical_name):
    matches=[]
    for symbol in obj['symbols'].values():
        match=re.fullmatch(r'[@_]('+re.escape(logical_name)+r')(?:@[0-9]+)?',symbol['name'])
        if match and symbol['storage']==2 and symbol['type']&0x20 and symbol['section']>0:
            if symbol['value']!=0:
                raise ValueError('compiled function is not an independent section')
            matches.append(obj['sections'][symbol['section']-1])
    if len(matches)!=1 or not matches[0]['characteristics']&0x20:
        raise ValueError('compiled function definition missing or ambiguous: '+logical_name)
    return matches[0]


def validate_body(section,target,bindings):
    if len(section['raw'])!=target['size']:
        raise ValueError('compiled body is not the complete target size')
    resolved,_=coff.relocate(section,target['va'],bindings)
    if support.digest(resolved)!=target['sha256']:
        raise ValueError('compiled body differs from its recorded full target hash')


def load(root):
    providers={}
    observed={}
    leaf_package=root/'recon/ffx/c_leaf'
    jobs,manifest,receipt,objects,inputs,log,seen=support.read_bundle(leaf_package)
    observed.update(seen)
    proof_path=leaf_package/'proof.json'
    proof_data=proof_path.read_bytes()
    proof=support.parse_json(proof_data,'C leaf proof')
    observed[proof_path]=proof_data
    if proof['build_manifest_sha256']!=support.digest(receipt) or proof['target_sha256']!=exact.EXE_SHA256:
        raise ValueError('C leaf proof is stale')
    parsed={name:coff.parse_coff(raw) for name,raw in objects.items()}
    by_symbol={g['symbol']:g for g in jobs['groups']}
    for target in proof['functions']:
        group=by_symbol[target['symbol']]
        selected=next((t for t in group['targets'] if t['va']==target['va']),None)
        if selected is None or any(target[k]!=selected[k] for k in selected):
            raise ValueError('C leaf proof target differs from retained jobs')
        section=section_for_symbol(parsed[target['variant']],target['symbol'])
        if section['relocations']:
            raise ValueError('relocation-free C provider contains relocations')
        validate_body(section,selected,{})
        providers[target['va']]={'key':'c_leaf:'+target['variant']+':'+target['symbol'],
            'family':'c_leaf','va':target['va'],'size':target['size'],'section':section,
            'sha256':target['sha256'],'build_manifest_sha256':support.digest(receipt)}
    symbolic_package=root/'recon/ffx/c_reloc'
    inputs,outputs,manifest,receipt,seen=symbolic_verify.read_bundle(symbolic_package)
    observed.update(seen)
    jobs=support.parse_json(inputs['jobs.json'],'symbolic C jobs')
    proof_path=symbolic_package/'proof.json'
    proof_data=proof_path.read_bytes()
    proof=support.parse_json(proof_data,'symbolic C proof')
    observed[proof_path]=proof_data
    if proof['build_manifest_sha256']!=support.digest(receipt) or proof['target_sha256']!=exact.EXE_SHA256:
        raise ValueError('symbolic C proof is stale')
    by_symbol={g['symbol']:g for g in jobs['groups']}
    parsed={name:coff.parse_coff(raw) for name,raw in outputs.items() if name.endswith('.obj')}
    bindings={'_'+s['name']:s['va'] for s in jobs['symbols']}
    for target in proof['functions']:
        group=by_symbol[target['symbol']]
        selected=next((t for t in group['targets'] if t['va']==target['va']),None)
        if selected is None or any(target[k]!=selected[k] for k in selected):
            raise ValueError('symbolic C proof differs from retained jobs')
        section=section_for_symbol(parsed[target['variant']],target['symbol'])
        symbolic_verify.link_function(section,target['va'],target['size'],group['relocations'],bindings)
        validate_body(section,selected,bindings)
        if target['va'] in providers:
            raise ValueError('duplicate C provider address')
        providers[target['va']]={'key':'c_reloc:'+target['variant']+':'+target['symbol'],
            'family':'c_reloc','va':target['va'],'size':target['size'],'section':section,
            'sha256':target['sha256'],'build_manifest_sha256':support.digest(receipt)}
    add_memcmp(root,providers,observed)
    add_mcwl(root,providers,observed)
    support.check_ranges([(r['va'],r['size']) for r in providers.values()],'compiled provider')
    support.check_unchanged(observed)
    return providers,observed


def add_memcmp(root,providers,observed):
    package=root/'recon/ffx/byteproof/build_c'
    candidate=package/'ffx_memcmp.exe'
    image,sections=exact.load_pe(candidate)
    provenance=verify_ffx_memcmp.verify_provenance(candidate,image)
    proof_data=(package/'proof.json').read_bytes()
    proof=support.parse_json(proof_data,'memcmp proof')
    if (proof['build_manifest_sha256']!=provenance['build_manifest_sha256']
            or proof['candidate_image_sha256']!=support.digest(image)
            or proof['target_sha256']!=exact.EXE_SHA256):
        raise ValueError('memcmp proof differs from compiled image receipt')
    code=next((s for s in sections if s[0]=='.text'),None)
    if code is None or code[2]!=112:
        raise ValueError('memcmp compiled image has wrong code section')
    raw=exact.va_reader(image,sections)(code[1],112)
    section={'raw':raw,'characteristics':0x60000020,'relocations':[]}
    target={'va':0x401020,'size':112,'sha256':proof['reference_sha256']}
    validate_body(section,target,{})
    providers[0x401020]=dict(target,key='c_memcmp',family='c_memcmp',section=section,
                            build_manifest_sha256=provenance['build_manifest_sha256'])
    observed[candidate]=image
    observed[package/'proof.json']=proof_data
    for path in (package/'build-manifest.json',package/'build.log',
                 root/'recon/ffx/ffx_memcmp.c',root/'recon/ffx/byteproof/build_memcmp.py',
                 root/'recon/ffx/byteproof/build_memcmp.bat'):
        observed[path]=path.read_bytes()
    for path in (package/'inputs').iterdir():
        if path.is_file(): observed[path]=path.read_bytes()


def add_mcwl(root,providers,observed):
    package=root/'recon/ffx/byteproof/build'
    receipt,artifacts,inputs=mcwl_build.read_bundle(root,package)
    observed.update({p:b for p,b in inputs.items() if p.is_relative_to(root)})
    proof_data=(package/'proof.json').read_bytes()
    proof=support.parse_json(proof_data,'MCWL assembly proof')
    obj_data=artifacts['mcwl.obj']
    receipt_hash=support.digest(inputs[package/'build-manifest.json'])
    if (receipt['inputs']['source']['sha256']!=proof['source_sha256']
            or proof.get('build_provenance_verified') is not True
            or proof.get('build_manifest_sha256')!=receipt_hash
            or support.digest(obj_data)!=proof['coff_sha256']
            or proof['target_sha256']!=exact.EXE_SHA256):
        raise ValueError('MCWL assembly source/object proof is stale')
    parsed=coff.parse_coff(obj_data)
    section=next((s for s in parsed['sections'] if s['name']=='.text'),None)
    if section is None or section['relocations']:
        raise ValueError('MCWL assembly is not a standalone exact code section')
    target={'va':0x617420,'size':144,'sha256':proof['reference_sha256']}
    validate_body(section,target,{})
    providers[0x617420]=dict(target,key='asm_mcwl',family='asm_mcwl',section=section,
                            build_manifest_sha256=receipt_hash)
    observed[package/'proof.json']=proof_data
    observed[package/'mcwl.obj']=obj_data
