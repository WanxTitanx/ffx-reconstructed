#!/usr/bin/env python3
"""Assemble the complete .text from source declarations, without the original EXE."""
import argparse
import bisect
import collections
import gzip
import hashlib
import importlib.metadata
import json
from pathlib import Path
import sys
import code_providers
import coff_emit
import coff_relocations as coff
import leaf_build as support
import pe_headers
import text_program
import x86_source
ROOT=Path(__file__).resolve().parents[2]


class ClassificationGuard:
    """Tie source record types to the independent native item map and reviewed exceptions."""
    def __init__(self,runs,sites,overrides,providers):
        self.runs=runs
        self.starts=[r[0] for r in runs]
        self.sites=sorted(sites)
        self.providers=providers
        self.provider_starts=sorted(providers)
        self.overrides={(o['va'],o['size']):o for o in overrides}
        if len(self.overrides)!=len(overrides):
            raise ValueError('duplicate classification override')
        self.used=set()

    def validate(self,record,bindings):
        ip,size=text_program.position(record)
        kind=record['kind']
        i=bisect.bisect_right(self.provider_starts,ip)-1
        provider=self.providers.get(self.provider_starts[i]) if i>=0 else None
        if provider is not None and ip<self.provider_starts[i]+provider['size']:
            if (kind!='coff' or ip!=self.provider_starts[i] or size!=provider['size']
                    or record['provider']!=provider['key']):
                raise ValueError('compiled code provider was replaced or split')
            return
        if kind=='coff':
            raise ValueError('source declares an unselected compiled provider')
        i=bisect.bisect_right(self.starts,ip)-1
        if i<0 or ip+size>self.runs[i][1]:
            raise ValueError('source record crosses a native classification boundary')
        native=self.runs[i][2]
        classification=record.get('classification')
        expected={'code':('instruction','ida_code'),'data':('data','ida_data'),
                  'mixeddata':('data','ida_data_with_unknown_tail')}
        if native in expected:
            if (kind,classification)!=expected[native]:
                raise ValueError('source kind contradicts native code/data classification')
            return
        if native=='alignment':
            if (kind,classification) not in (('instruction','decoded_alignment'),('padding','ida_alignment')):
                raise ValueError('native alignment has an unsupported source kind')
            return
        if native!='unknown':
            raise ValueError('unrecognized native classification')
        override=self.overrides.get((ip,size))
        if override is None:
            raise ValueError('native unknown range lacks a reviewed classification override')
        self.used.add((ip,size))
        sites=self.sites[bisect.bisect_left(self.sites,ip):bisect.bisect_left(self.sites,ip+size)]
        reason=override['reason']
        if (kind,classification)==('padding','reviewed_alignment'):
            valid=(not sites and reason=='uniform alignment fill'
                   and record['value']==override.get('value') and record['value'] in (0,0x90,0xcc))
        elif (kind,classification)==('data','reviewed_pointer_table'):
            raw,fixups=text_program.assemble_data(record,bindings)
            valid=(reason=='every dword has an actual PE pointer relocation'
                   and sites==list(range(ip,ip+size,4))
                   and [ip+r['offset'] for r in fixups]==sites and len(raw)==size)
        elif (kind,classification)==('data','reviewed_selector_data'):
            raw,fixups=text_program.assemble_data(record,bindings)
            valid=(not sites and not fixups and len(raw)==size and set(raw).issubset({0,1,2})
                   and reason=='reviewed small selector table; all scalar values 0..2')
        elif (kind,classification)==('instruction','decoded_alignment'):
            raw,fixups=x86_source.encode(record['instruction'],bindings)
            valid=(not sites and not fixups and raw==bytes.fromhex('8d4900')
                   and reason=='reviewed LEA ECX,[ECX] alignment instruction')
        else:
            valid=False
        if not valid:
            raise ValueError('source does not satisfy its reviewed unknown-range classification')

    def finish(self):
        if self.used!=set(self.overrides):
            raise ValueError('classification overrides are unused or missing from the source')


def classification_guard(root,plan,model,providers):
    observed={}
    generator=Path(text_program.__file__).resolve()
    raw=read_verified(generator,plan['source_generator_sha256'])
    observed[generator]=raw
    snapshot=root/'recon/ffx/text_program/generator.py'
    if snapshot.read_bytes()!=raw:
        raise ValueError('prepared generator snapshot differs from source generator')
    observed[snapshot]=raw
    encoder=Path(x86_source.__file__).resolve()
    observed[encoder]=read_verified(encoder,plan['encoder_module_sha256'])
    _,sites=pe_headers._emit_relocations(model,None)
    runs,classification_inputs=text_program.native_runs(root,plan['text_va'],
        plan['text_va']+plan['text_raw_size'],sites)
    actual={str(p.relative_to(root)):support.digest(raw) for p,raw in classification_inputs.items()}
    if actual!=plan['classification_inputs']:
        raise ValueError('native classification inputs changed after source preparation')
    observed.update(classification_inputs)
    return ClassificationGuard(runs,sites,plan['classification_overrides'],providers),observed


def read_verified(path,expected):
    raw=path.read_bytes()
    if support.digest(raw)!=expected:
        raise ValueError('source/artifact hash differs: '+str(path))
    return raw


def layout_bindings(symbols,layout):
    result={}
    base=layout['image_base']
    sections={s['name']:s for s in layout['sections']}
    for symbol in symbols:
        name,va,offset=symbol['name'],symbol['va'],symbol['offset']
        if (not text_program.re_symbol(name) or type(va) is not int or type(offset) is not int
                or va!=int(name[5:],16) or name in result):
            raise ValueError('invalid or duplicated layout symbol')
        if symbol['owner']=='headers':
            expected=base+offset
            limit=layout['optional_header']['size_of_headers']
        else:
            section=sections.get(symbol['owner'])
            if section is None:
                raise ValueError('symbol has no mapped section owner')
            expected=base+section['virtual_address']+offset
            limit=max(section['virtual_size'],section['raw_size'])
        if va!=expected or not 0<=offset<limit:
            raise ValueError('symbol does not belong to its declared layout range')
        result[name]=va
    return result


def tool_inputs():
    if importlib.metadata.version('iced-x86')!='1.21.0':
        raise ValueError('assembly requires pinned iced-x86 1.21.0')
    paths={Path(module.__file__).resolve() for module in
           (support,code_providers,coff_emit,coff,pe_headers,text_program,x86_source)}
    paths.add(Path(__file__).resolve())
    paths.add(Path(sys.executable).resolve())
    for name,module in list(sys.modules.items()):
        at=getattr(module,'__file__',None)
        if name.startswith('iced_x86') and at and (name=='iced_x86' or str(at).endswith(('.so','.pyd'))):
            paths.add(Path(at).resolve())
    return {path:path.read_bytes() for path in paths}


def build(root,package,output):
    output.mkdir(parents=True,exist_ok=True)
    (output/'manifest.json').unlink(missing_ok=True)
    (output/'proof.json').unlink(missing_ok=True)
    plan_path=package/'plan.json.gz'
    plan_data=plan_path.read_bytes()
    plan=support.parse_json(gzip.decompress(plan_data),'text source plan')
    header_source_path=root/'recon/ffx/pe_headers/source.json.gz'
    header_data=header_source_path.read_bytes()
    header_model=support.parse_json(gzip.decompress(header_data),'header source')
    layout=pe_headers.native_layout(header_model)
    text=next(s for s in layout['sections'] if s['name']=='.text')
    if (plan['text_va']!=layout['image_base']+text['virtual_address']
            or plan['text_raw_size']!=text['raw_size'] or plan['text_raw_offset']!=text['raw_offset']):
        raise ValueError('text source extent disagrees with PE layout')
    bindings=layout_bindings(plan['symbols'],layout)
    providers,provider_inputs=code_providers.load(root)
    guard,classification_inputs=classification_guard(root,plan,header_model,providers)
    current={p['va']:{k:p[k] for k in ('va','size','key','family','sha256','build_manifest_sha256')}
             for p in providers.values()}
    if len(current)!=len(plan['providers']) or any(current.get(p['va'])!=p for p in plan['providers']):
        raise ValueError('compiled providers differ from the selected source plan')
    expected_inputs=plan['provider_inputs']
    if {str(p.relative_to(root)):support.digest(raw) for p,raw in provider_inputs.items()}!=expected_inputs:
        raise ValueError('compiled source provenance changed after text preparation')
    observed=dict(provider_inputs)
    observed.update(classification_inputs)
    observed[plan_path]=plan_data
    observed[header_source_path]=header_data
    tools=tool_inputs()
    observed.update(tools)
    snapshots=output/'inputs'
    snapshots.mkdir(exist_ok=True)
    (snapshots/'sources').mkdir(exist_ok=True)
    (snapshots/'plan.json.gz').write_bytes(plan_data)
    (snapshots/'header-source.json.gz').write_bytes(header_data)
    for path,raw in provider_inputs.items():
        destination=snapshots/'providers'/path.relative_to(root)
        destination.parent.mkdir(parents=True,exist_ok=True)
        destination.write_bytes(raw)
        observed[destination]=raw
    for index,(path,raw) in enumerate(sorted(tools.items())):
        destination=snapshots/'tools'/('%03d-'%index+path.name)
        destination.parent.mkdir(exist_ok=True)
        destination.write_bytes(raw)
        observed[destination]=raw
    entries=[]
    highlow=[]
    total_stats=collections.Counter()
    full_text_hash=hashlib.sha256()
    aliases=sorted((va,name) for name,va in bindings.items())
    alias_addresses=[va for va,_ in aliases]
    cursor=plan['text_va']
    for index,chunk in enumerate(plan['chunks']):
        if chunk['va']!=cursor or chunk['size']<=0:
            raise ValueError('source chunks have a gap or overlap')
        source_path=package/chunk['source']
        source_data=read_verified(source_path,chunk['source_sha256'])
        source_json=gzip.decompress(source_data)
        if support.digest(source_json)!=chunk['source_json_sha256']:
            raise ValueError('source content checksum differs')
        records=[json.loads(line) for line in source_json.splitlines()]
        if len(records)!=chunk['records']:
            raise ValueError('source record count differs')
        observed[source_path]=source_data
        destination=snapshots/chunk['source']
        destination.write_bytes(source_data)
        observed[destination]=source_data
        for record in records:
            guard.validate(record,bindings)
        raw,fixups,stats=text_program.assemble_records(records,chunk['va'],chunk['size'],bindings,providers)
        lo=bisect.bisect_left(alias_addresses,chunk['va'])
        hi=bisect.bisect_left(alias_addresses,chunk['va']+chunk['size'])
        definitions={name:va-chunk['va'] for va,name in aliases[lo:hi]}
        object_data=coff_emit.make_object(chunk['section'],raw,fixups,definitions)
        section=coff.parse_coff(object_data)['sections'][0]
        linked,_=coff.relocate(section,chunk['va'],bindings)
        if support.digest(linked)!=chunk['reference_sha256']:
            raise ValueError('assembled text differs at chunk '+chunk['section'])
        full_text_hash.update(linked)
        name=chunk['section']+'.obj'
        (output/name).write_bytes(object_data)
        observed[output/name]=object_data
        highlow.extend(chunk['va']+r['offset'] for r in section['relocations'] if r['type']==coff.DIR32)
        entries.append({'section':chunk['section'],'va':chunk['va'],'size':chunk['size'],
                        'source':chunk['source'],'source_sha256':chunk['source_sha256'],
                        'object':name,'object_sha256':support.digest(object_data),
                        'linked_sha256':support.digest(linked),'stats':stats,'defined_symbols':len(definitions),
                        'relocations':len(section['relocations'])})
        total_stats.update(stats)
        cursor+=chunk['size']
        if (index+1)%16==0:
            print('assembled text chunks:',index+1,'of',len(plan['chunks']),flush=True)
    if cursor!=plan['text_va']+plan['text_raw_size']:
        raise ValueError('assembled text does not cover its complete raw size')
    guard.finish()
    if full_text_hash.hexdigest()!=plan['reference_text_sha256']:
        raise ValueError('complete text hash differs from its source plan')
    support.check_ranges([(site,4) for site in highlow],'assembled HIGHLOW')
    support.check_unchanged(observed)
    if tool_inputs()!=tools:
        raise ValueError('assembler code or binaries changed during build')
    manifest={'schema_version':1,'status':'complete','source_plan_sha256':support.digest(plan_data),
              'header_source_sha256':support.digest(header_data),'target_sha256':plan['target_sha256'],
              'tools':{str(p):support.digest(raw) for p,raw in tools.items()},
              'provider_inputs':expected_inputs,'entries':entries,'stats':dict(total_stats),
              'actual_highlow_sites':sorted(highlow),'reference_executable_read_by_builder':False,
              'source_classification_verified':True,'complete_text_sha256':full_text_hash.hexdigest(),
              'scope':'Complete .text, emitted from source into COFF and resolved by actual relocation records'}
    data=(json.dumps(manifest,separators=(',',':'))+'\n').encode()
    (output/'manifest.json').write_bytes(data)
    print('Complete text assembled:',len(entries),'COFF objects;',plan['text_raw_size'],
          'literal bytes;',len(highlow),'actual HIGHLOW sites')
    return manifest


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--package',type=Path,default=ROOT/'recon/ffx/text_program')
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/text_program/build')
    args=parser.parse_args()
    build(args.root,args.package,args.output)
