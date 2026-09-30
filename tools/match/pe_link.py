#!/usr/bin/env python3
"""Link source-built COFF code/data and field-built headers into a complete PE.

This module never opens the reference executable. Every file byte has an
explicit source owner. Symbol addresses come from placed COFF definitions or
declared header/relocation fields; only real COFF relocations write operands.
"""
import argparse
import collections
import gzip
import json
from pathlib import Path
import sys

import coff_relocations as coff
import definitive_match as exact
import leaf_build as support
import pe_data_verify
import pe_headers
import pe_structure
import text_build
import text_program

ROOT=Path(__file__).resolve().parents[2]


def place_file(size,fragments):
    if type(size) is not int or not 0<size<2**32:
        raise ValueError('invalid final file size')
    result=bytearray()
    owners=set()
    for offset,raw,owner in sorted(fragments,key=lambda item:item[0]):
        if (type(offset) is not int or not isinstance(raw,bytes) or not raw
                or not isinstance(owner,str) or not owner or owner in owners):
            raise ValueError('invalid or duplicated file owner')
        if offset<len(result):
            raise ValueError('overlapping file fragments at '+owner)
        if offset>len(result):
            raise ValueError('undeclared file gap before '+owner)
        if offset+len(raw)>size:
            raise ValueError('file fragment exceeds declared size')
        owners.add(owner)
        result.extend(raw)
    if len(result)!=size:
        raise ValueError('file fragments do not cover the complete file')
    return bytes(result)


def definitions(obj,section_name,va,size):
    sections=[s for s in obj['sections'] if s['name']==section_name]
    if len(sections)!=1 or sections[0]['raw_size']!=size:
        raise ValueError('COFF owner section missing, ambiguous or wrong size')
    section=sections[0]
    result={}
    for symbol in obj['symbols'].values():
        if symbol['section']<=0 or symbol['storage']!=2:
            continue
        name=symbol['name']
        if not text_program.re_symbol(name):
            continue
        if symbol['section']!=section['index'] or not 0<=symbol['value']<size:
            raise ValueError('symbol definition is outside its declared owner')
        address=va+symbol['value']
        if address!=int(name[5:],16) or name in result:
            raise ValueError('symbol name/placement disagree or definition is duplicated')
        result[name]=address
    return result


def chunk_offset(layout,owner,va,size,zero_storage=False):
    owners=[s for s in layout['sections'] if s['name']==owner]
    if len(owners)!=1 or type(va) is not int or type(size) is not int or size<=0:
        raise ValueError('invalid section owner or chunk extent')
    section=owners[0]
    offset=va-layout['image_base']-section['virtual_address']
    if zero_storage:
        if offset<section['raw_size'] or offset+size>section['virtual_size']:
            raise ValueError('zero storage is outside the declared virtual tail')
        return None
    if offset<0 or offset+size>section['raw_size']:
        raise ValueError('chunk is outside file-backed section bytes')
    return section['raw_offset']+offset


def validate_zero_storage(layout,chunks):
    """Every virtual byte after a section's raw data has one explicit source owner."""
    groups=collections.defaultdict(list)
    for chunk in chunks:
        if chunk['zero_storage']:
            chunk_offset(layout,chunk['original_section'],chunk['va'],chunk['size'],True)
            groups[chunk['original_section']].append((chunk['va'],chunk['size']))
    for section in layout['sections']:
        start=layout['image_base']+section['virtual_address']
        cursor=start+section['raw_size']
        end=start+max(section['raw_size'],section['virtual_size'])
        for va,size in sorted(groups[section['name']]):
            if va!=cursor:
                raise ValueError('zero-storage tail has a gap or overlap: '+section['name'])
            cursor+=size
        if cursor!=end:
            raise ValueError('zero-storage tail is not completely declared: '+section['name'])


def load_text(root,model,header_data):
    package=root/'recon/ffx/text_program'
    build=package/'build'
    plan_data=(package/'plan.json.gz').read_bytes()
    manifest_data=(build/'manifest.json').read_bytes()
    plan=support.parse_json(gzip.decompress(plan_data),'text plan')
    manifest=support.parse_json(manifest_data,'text build manifest')
    if (manifest.get('schema_version')!=1 or manifest.get('status')!='complete'
            or manifest.get('source_classification_verified') is not True
            or manifest.get('complete_text_sha256')!=plan['reference_text_sha256']
            or manifest.get('source_plan_sha256')!=support.digest(plan_data)
            or manifest.get('header_source_sha256')!=support.digest(header_data)
            or manifest.get('target_sha256')!=exact.EXE_SHA256
            or plan.get('target_sha256')!=exact.EXE_SHA256):
        raise ValueError('text build receipt is missing or stale')
    observed={package/'plan.json.gz':plan_data,build/'manifest.json':manifest_data}
    guard,classification_inputs=text_build.classification_guard(root,plan,model,
        {p['va']:p for p in plan['providers']})
    observed.update(classification_inputs)
    guard_bindings=text_build.layout_bindings(plan["symbols"],pe_headers.native_layout(model))

    def unchanged(path,expected):
        raw=path.read_bytes()
        if raw!=expected:
            raise ValueError('text retained input differs: '+str(path))
        observed[path]=raw

    unchanged(build/'inputs/plan.json.gz',plan_data)
    unchanged(build/'inputs/header-source.json.gz',header_data)
    current_tools=text_build.tool_inputs()
    if {str(p):support.digest(raw) for p,raw in current_tools.items()}!=manifest['tools']:
        raise ValueError('text assembler tools changed after compilation')
    for index,(path,raw) in enumerate(sorted(current_tools.items())):
        unchanged(build/'inputs/tools'/('%03d-'%index+path.name),raw)
    observed.update(current_tools)
    for relpath,digest in plan['provider_inputs'].items():
        raw=text_build.read_verified(root/relpath,digest)
        observed[root/relpath]=raw
        unchanged(build/'inputs/providers'/relpath,raw)
    if manifest['provider_inputs']!=plan['provider_inputs']:
        raise ValueError('text receipt uses a different provider selection')
    for relpath,digest in plan['classification_inputs'].items():
        observed[root/relpath]=text_build.read_verified(root/relpath,digest)
    for path,digest in ((Path(text_program.__file__),plan['source_generator_sha256']),
                        (Path(text_program.x86_source.__file__),plan['encoder_module_sha256'])):
        observed[path]=text_build.read_verified(path,digest)
    entries=manifest['entries']
    if len(entries)!=len(plan['chunks']):
        raise ValueError('text receipt does not cover every source chunk')
    objects={}
    cursor=plan['text_va']
    for chunk,entry in zip(plan['chunks'],entries):
        if chunk['va']!=cursor or chunk['section'] in objects:
            raise ValueError('text chunks have gaps, overlaps or duplicate names')
        for key in ('section','va','size','source','source_sha256'):
            if entry[key]!=chunk[key]:
                raise ValueError('text object differs from source placement')
        if (entry['object']!=chunk['section']+'.obj'
                or entry['linked_sha256']!=chunk['reference_sha256']):
            raise ValueError('text object output identity disagrees')
        source_path=package/chunk['source']
        raw=text_build.read_verified(source_path,chunk['source_sha256'])
        observed[source_path]=raw
        unchanged(build/'inputs'/chunk['source'],raw)
        for line in gzip.decompress(raw).splitlines():
            guard.validate(json.loads(line),guard_bindings)
        path=build/entry['object']
        raw=text_build.read_verified(path,entry['object_sha256'])
        observed[path]=raw
        objects[chunk['section']]=coff.parse_coff(raw)
        cursor+=chunk['size']
    if cursor!=plan['text_va']+plan['text_raw_size']:
        raise ValueError('text objects do not cover the complete source plan')
    guard.finish()
    return plan,manifest,objects,observed


def tool_inputs():
    paths={Path(__file__).resolve(),Path(sys.executable).resolve()}
    directory=Path(__file__).resolve().parent
    # runpy replaces __main__, so module discovery alone misses this launcher.
    paths.add(directory/'run_source_only.py')
    for name,module in list(sys.modules.items()):
        at=getattr(module,'__file__',None)
        if at:
            path=Path(at).resolve()
            if path.parent==directory or name.startswith('iced_x86'):
                paths.add(path)
    return {p:p.read_bytes() for p in paths}


def link(root,output):
    root,output=root.resolve(),output.resolve()
    if output==root or root in output.parents and output==root/'recon/ffx':
        raise ValueError('use a distinct output directory for the linked image')
    output.mkdir(parents=True,exist_ok=True)
    for name in ('manifest.json','proof.json'):
        (output/name).unlink(missing_ok=True)
    header_path=root/'recon/ffx/pe_headers/source.json.gz'
    header_data=header_path.read_bytes()
    model=support.parse_json(gzip.decompress(header_data),'structured PE source')
    layout=pe_headers.native_layout(model)
    headers=pe_headers.emit_headers(model)
    observed={header_path:header_data}
    tools=tool_inputs()
    observed.update(tools)
    tplan,tmanifest,tobjects,inputs=load_text(root,model,header_data)
    observed.update(inputs)
    dpackage=root/'recon/ffx/pe_data'
    dplan,dmanifest,dobjects,inputs=pe_data_verify.read_bundle(dpackage)
    observed.update(inputs)
    if dplan['target_sha256']!=exact.EXE_SHA256:
        raise ValueError('data source targets a different executable')
    chunks=[dict(c,original_section='.text',zero_storage=False) for c in tplan['chunks']]+dplan['chunks']
    support.check_ranges([(c['va'],c['size']) for c in chunks],'placed code/data')
    validate_zero_storage(layout,chunks)
    objects=dict(tobjects)
    if set(objects)&set(dobjects):
        raise ValueError('duplicate code/data section name')
    objects.update(dobjects)
    bindings={}
    for chunk in chunks:
        chunk_offset(layout,chunk['original_section'],chunk['va'],chunk['size'],chunk['zero_storage'])
        for name,va in definitions(objects[chunk['section']],chunk['section'],chunk['va'],chunk['size']).items():
            if name in bindings:
                raise ValueError('multiple source definitions for '+name)
            bindings[name]=va
    declared=text_build.layout_bindings(tplan['symbols'],layout)
    for symbol in tplan['symbols']:
        name=symbol['name']
        if symbol['owner'] in ('headers','.reloc'):
            if name in bindings:
                raise ValueError('header/relocation label collides with a code/data symbol')
            bindings[name]=declared[name]
        elif bindings.get(name)!=declared[name]:
            raise ValueError('layout label lacks an actual COFF definition: '+name)
    fragments=[(0,headers,'headers')]
    records=[]
    highlow=[]
    for chunk in chunks:
        name=chunk['section']
        section=next(s for s in objects[name]['sections'] if s['name']==name)
        offset=chunk_offset(layout,chunk['original_section'],chunk['va'],chunk['size'],chunk['zero_storage'])
        if chunk['zero_storage']:
            if section['raw'] or section['relocations'] or not section['characteristics']&0x80:
                raise ValueError('declared BSS is not uninitialized COFF storage')
            records.append({'owner':name,'va':chunk['va'],'size':chunk['size'],'zero_storage':True})
            continue
        raw,evidence=coff.relocate(section,chunk['va'],bindings,layout['image_base'])
        if len(raw)!=chunk['size'] or support.digest(raw)!=chunk['reference_sha256']:
            raise ValueError('fully linked chunk differs from its declared hash: '+name)
        highlow.extend(chunk['va']+r['offset'] for r in section['relocations'] if r['type']==coff.DIR32)
        fragments.append((offset,raw,name))
        records.append({'owner':name,'original_section':chunk['original_section'],'va':chunk['va'],
                        'file_offset':offset,'size':len(raw),'sha256':support.digest(raw),
                        'coff_relocations':len(evidence),'zero_storage':False})
    support.check_ranges([(site,4) for site in highlow],'real linked HIGHLOW')
    reloc=pe_headers.emit_base_relocations(model,expected_highlow_sites=highlow)
    relocation_section=next(s for s in layout['sections'] if s['name']=='.reloc')
    fragments.append((relocation_section['raw_offset'],reloc,'.reloc'))
    image=place_file(layout['file_size'],fragments)
    parsed=pe_structure.parse_layout(image)
    if pe_structure.emit_nt_headers(parsed)!=pe_structure.emit_nt_headers(layout):
        raise ValueError('linked PE structure differs from its source fields')
    imports=pe_structure.parse_imports(image,parsed)
    if support.digest(image)!=exact.EXE_SHA256:
        raise ValueError('complete image digest differs: '+support.digest(image))
    support.check_unchanged(observed)
    if tool_inputs()!=tools:
        raise ValueError('linker tools changed during link')
    snapshots=output/'inputs'
    snapshots.mkdir(exist_ok=True)
    input_records=[]
    for path,raw in sorted(observed.items()):
        digest=support.digest(raw)
        snapshot=snapshots/digest
        snapshot.write_bytes(raw)
        input_records.append({'path':str(path),'sha256':digest,'snapshot':'inputs/'+digest})
    support.check_unchanged(observed)
    for entry in input_records:
        if support.digest((output/entry['snapshot']).read_bytes())!=entry['sha256']:
            raise ValueError('link input snapshot changed')
    destination=output/'FFX.exe'
    if destination.resolve()==Path(exact.EXE_DEFAULT).resolve():
        raise ValueError('output cannot replace the original executable')
    candidate=output/'FFX.exe.tmp'
    candidate.write_bytes(image)
    candidate.replace(destination)
    manifest={'schema_version':1,'status':'complete','target_sha256':exact.EXE_SHA256,
              'candidate':'FFX.exe','candidate_sha256':support.digest(image),'file_size':len(image),
              'reference_read_by_linker':False,'raw_code_blob_fallbacks':0,'masked_bytes':0,
              'inputs':input_records,'placed_fragments':records,'defined_symbols':len(bindings),
              'highlow_sites':sorted(highlow),'text_stats':tmanifest['stats'],
              'imports':imports,'section_hashes':[
                  {'name':s['name'],'offset':s['raw_offset'],'size':s['raw_size'],
                   'sha256':support.digest(image[s['raw_offset']:s['raw_offset']+s['raw_size']])}
                  for s in layout['sections']]}
    pending=output/'manifest.json.tmp'
    pending.write_text(json.dumps(manifest,separators=(',',':'))+'\n')
    pending.replace(output/'manifest.json')
    print('Complete PE:',len(image),'bytes; SHA256',support.digest(image),flush=True)
    print('Actual HIGHLOW:',len(highlow),'; defined symbols:',len(bindings),'; import DLLs:',len(imports))
    return manifest


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/complete')
    args=parser.parse_args()
    try:
        link(args.root,args.output)
    except (OSError,ValueError,KeyError,TypeError) as exc:
        print('error: '+str(exc),file=sys.stderr)
        raise SystemExit(2)
