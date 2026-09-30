#!/usr/bin/env python3
"""Independent literal file, PE structure and rebased-memory comparison."""
import argparse
import json
import os
from pathlib import Path
import struct
import sys
import definitive_match as exact
import leaf_build as support
import pe_structure
import complete_acceptance as acceptance

ROOT=Path(__file__).resolve().parents[2]


def compare_bytes(reference,candidate):
    length=min(len(reference),len(candidate))
    mismatch=sum(a!=b for a,b in zip(reference,candidate))+abs(len(reference)-len(candidate))
    first=next((i for i,(a,b) in enumerate(zip(reference,candidate)) if a!=b),None)
    if first is None and len(reference)!=len(candidate): first=length
    return {'literal_equal':reference==candidate,'compared_bytes':length,
            'reference_size':len(reference),'candidate_size':len(candidate),
            'different_bytes':mismatch,'first_difference':first}


def highlow_sites(data,layout):
    directory=layout['directories'][5]
    section=next(s for s in layout['sections'] if s['name']=='.reloc')
    offset=section['raw_offset']+directory['rva']-section['virtual_address']
    end=offset+directory['size']
    sites=[]
    while offset<end:
        if offset+8>end: raise ValueError('truncated relocation block')
        page,size=struct.unpack_from('<II',data,offset)
        if size<8 or size%4 or page%4096 or offset+size>end:
            raise ValueError('invalid relocation block')
        for pos in range(offset+8,offset+size,2):
            word=struct.unpack_from('<H',data,pos)[0]
            type_,displacement=word>>12,word&4095
            if type_==3: sites.append(page+displacement)
            elif type_!=0: raise ValueError('unsupported base relocation')
        offset+=size
    support.check_ranges([(site,4) for site in sites],'independent HIGHLOW')
    return sorted(sites)


def mapped_image(data,layout,base,sites):
    image=bytearray(layout['optional_header']['size_of_image'])
    headers=layout['optional_header']['size_of_headers']
    image[:headers]=data[:headers]
    for section in layout['sections']:
        offset,size=section['raw_offset'],section['raw_size']
        va=section['virtual_address']
        image[va:va+size]=data[offset:offset+size]
    delta=base-layout['image_base']
    for site in sites:
        if not 0<=site<=len(image)-4:
            raise ValueError('relocation outside loaded image')
        value=struct.unpack_from('<I',image,site)[0]
        struct.pack_into('<I',image,site,(value+delta)&0xffffffff)
    return image


def verify(directory,reference_path,root=ROOT):
    directory,reference_path,root=directory.resolve(),reference_path.resolve(),root.resolve()
    proof_path=directory/'proof.json'
    proof_path.unlink(missing_ok=True)
    candidate_path=directory/'FFX.exe'
    if os.path.samefile(candidate_path,reference_path):
        raise ValueError('candidate and original are the same file')
    reference=reference_path.read_bytes()
    candidate=candidate_path.read_bytes()
    if support.digest(reference)!=exact.EXE_SHA256:
        raise ValueError('original executable SHA-256 changed')
    comparison=compare_bytes(reference,candidate)
    if not comparison['literal_equal']:
        raise ValueError('full-file mismatch: '+json.dumps(comparison))
    manifest_path=directory/'manifest.json'
    manifest_data=manifest_path.read_bytes()
    manifest=support.parse_json(manifest_data,'complete link manifest')
    acceptance.validate_manifest(manifest,candidate)
    observed={reference_path:reference,candidate_path:candidate,manifest_path:manifest_data}
    observed.update(acceptance.validate_inputs(manifest,directory,reference_path))
    audit,audit_inputs=acceptance.validate_audit(directory,reference_path,manifest_data,candidate,root)
    observed.update(audit_inputs)
    verifier_inputs={Path(__file__).resolve():Path(__file__).read_bytes(),
                     Path(acceptance.__file__).resolve():Path(acceptance.__file__).read_bytes()}
    observed.update(verifier_inputs)
    replay,replay_inputs=acceptance.replay_link(root,directory,reference_path,manifest,candidate)
    observed.update(replay_inputs)
    original_layout=pe_structure.parse_layout(reference)
    candidate_layout=pe_structure.parse_layout(candidate)
    if original_layout!=candidate_layout:
        raise ValueError('structured PE header comparison failed')
    imports=pe_structure.parse_imports(candidate,candidate_layout)
    if imports!=pe_structure.parse_imports(reference,original_layout):
        raise ValueError('import DLL/name/ordinal/IAT comparison failed')
    sites=highlow_sites(candidate,candidate_layout)
    if [candidate_layout['image_base']+site for site in sites]!=manifest['highlow_sites']:
        raise ValueError('emitted loader relocations differ from linked COFF sites')
    original_sites=highlow_sites(reference,original_layout)
    rebases=[]
    for base in (0x10000000,0x50000000):
        original_memory=mapped_image(reference,original_layout,base,original_sites)
        candidate_memory=mapped_image(candidate,candidate_layout,base,sites)
        if original_memory!=candidate_memory:
            raise ValueError('mapped image differs after loader relocation')
        rebases.append({'image_base':hex(base),'mapped_bytes':len(candidate_memory),
                        'literal_equal':True,'memory_sha256':support.digest(candidate_memory)})
        del original_memory,candidate_memory
    support.check_unchanged(observed)
    proof={'schema_version':1,'whole_executable_reconstructed':True,**comparison,
           'target_sha256':exact.EXE_SHA256,'candidate_sha256':support.digest(candidate),
           'manifest_sha256':support.digest(manifest_data),'source_build_inputs_verified':len(manifest['inputs']),
           'source_backed_link_verified':True,'raw_code_blob_fallbacks':0,'masked_bytes':0,
           'source_only_audit':audit,'independent_source_link_replay':replay,
           'acceptance_verifier_inputs':{str(p):support.digest(raw) for p,raw in verifier_inputs.items()},
           'section_count':len(candidate_layout['sections']),'import_dlls':len(imports),
           'actual_highlow_relocations':len(sites),'rebased_images':rebases,
           'text_source_categories':manifest['text_stats'],
           'gameplay_runtime_tested':False,'representation':'C plus explicit assembly and declared data/assets'}
    pending=directory/'proof.json.tmp'
    pending.write_text(json.dumps(proof,indent=2)+'\n')
    pending.replace(proof_path)
    print(json.dumps(proof,indent=2))
    return proof


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--directory',type=Path,default=ROOT/'recon/ffx/complete')
    parser.add_argument('--reference',type=Path,default=Path(exact.EXE_DEFAULT))
    parser.add_argument('--root',type=Path,default=ROOT)
    args=parser.parse_args()
    try:
        verify(args.directory,args.reference,args.root)
    except (OSError,ValueError,KeyError,TypeError,struct.error) as exc:
        print('error: '+str(exc),file=sys.stderr)
        raise SystemExit(2)
