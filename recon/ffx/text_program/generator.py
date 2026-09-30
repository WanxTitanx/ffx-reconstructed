#!/usr/bin/env python3
"""Source-backed .text construction from verified C and explicit x86 instructions.

prepare() reads the pinned image and the immutable IDA typing export. The build
path consumes JSONL assembly/data declarations and compiled providers only.
Every byte has a declared owner; missing spans never become filler/stubs.
"""
import argparse
import bisect
import collections
import csv
import gzip
import io
import json
import struct
from pathlib import Path
from iced_x86 import Decoder
import code_providers
import coff_emit
import coff_relocations as coff
import definitive_match as exact
import leaf_reconstruct as leaf
import leaf_build as support
import x86_source
ROOT=Path(__file__).resolve().parents[2]
DATA_CLASSES={'ida_data','reviewed_pointer_table','reviewed_selector_data','ida_data_with_unknown_tail'}
PADDING_CLASSES={'ida_alignment','reviewed_alignment','section_raw_padding'}


def position(record):
    if record.get('kind')=='instruction':
        instruction=record['instruction']
        return instruction['ip'],instruction['length']
    return record['ip'],record['size']


def assemble_records(records,va,size,bindings,providers):
    if type(va) is not int or type(size) is not int or size<=0:
        raise ValueError('invalid declared text extent')
    output=bytearray()
    fixups=[]
    stats=collections.Counter()
    for record in records:
        ip,length=position(record)
        if type(ip) is not int or type(length) is not int or length<=0 or ip!=va+len(output) or ip+length>va+size:
            raise ValueError('text records have a gap, overlap or invalid extent')
        kind=record['kind']
        local=[]
        if kind=='instruction':
            if set(record)!={'kind','instruction','classification'}:
                raise ValueError('unsupported instruction wrapper')
            raw,local=x86_source.encode(record['instruction'],bindings,relocatable=True)
            stats['instruction_bytes']+=len(raw)
            stats['instructions']+=1
        elif kind=='coff':
            if set(record)!={'kind','ip','size','provider'}:
                raise ValueError('unsupported compiled-provider declaration')
            provider=providers.get(ip)
            if provider is None or provider['key']!=record['provider'] or provider['size']!=length:
                raise ValueError('compiled provider does not own this declared range')
            section=provider['section']
            raw=section['raw']
            for relocation in section['relocations']:
                if relocation['type']==0: continue
                if relocation['symbol_name'] not in bindings:
                    raise ValueError('compiled provider has an unresolved symbol')
                local.append({'offset':relocation['offset'],'type':relocation['type'],
                              'symbol_name':relocation['symbol_name'],
                              'base_relocation':relocation['type']==coff.DIR32})
            stats['c_bytes' if provider['family'].startswith('c_') else 'external_assembly_bytes']+=len(raw)
            stats['compiled_providers']+=1
        elif kind=='padding':
            if set(record)!={'kind','ip','size','value','classification'} or record['classification'] not in PADDING_CLASSES:
                raise ValueError('unsupported padding declaration')
            if type(record['value']) is not int or record['value'] not in (0,0x90,0xcc):
                raise ValueError('padding is not a supported alignment value')
            raw=bytes([record['value']])*length
            stats['padding_bytes']+=length
        elif kind=='data':
            raw,local=assemble_data(record,bindings)
            stats['data_bytes']+=len(raw)
        else:
            raise ValueError('text source cannot contain raw code or an unknown record type')
        if len(raw)!=length:
            raise ValueError('assembled record has a different declared size')
        for relocation in local:
            fixups.append(dict(relocation,offset=len(output)+relocation['offset']))
        output.extend(raw)
    if len(output)!=size:
        raise ValueError('text source does not cover the complete declared extent')
    return bytes(output),fixups,dict(stats)


def assemble_data(record,bindings):
    if set(record)!={'kind','ip','size','classification','elements'} or record['classification'] not in DATA_CLASSES:
        raise ValueError('unsupported data-island declaration')
    raw=bytearray()
    fixups=[]
    for item in record['elements']:
        if set(item)=={'width','symbol'}:
            if item['width']!=4 or item['symbol'] not in bindings:
                raise ValueError('invalid or unresolved data pointer')
            fixups.append({'offset':len(raw),'type':coff.DIR32,'symbol_name':item['symbol'],'base_relocation':True})
            raw.extend(bytes(4))
        elif set(item)=={'width','values'}:
            width=item['width']
            if type(width) is not int or width not in (1,2,4,8):
                raise ValueError('unsupported scalar data width')
            for value in item['values']:
                if type(value) is not int or not 0<=value<1<<(8*width):
                    raise ValueError('data scalar does not fit its declared width')
                raw.extend(value.to_bytes(width,'little'))
        else:
            raise ValueError('opaque or malformed data declaration')
    return bytes(raw),fixups


def native_runs(root,raw_start,raw_end,sites):
    directory=root/'recon/ffx/analysis_map'
    metadata_data=(directory/'metadata.json').read_bytes()
    metadata=support.parse_json(metadata_data,'analysis metadata')
    path=directory/'text_items.tsv.gz'
    compressed=path.read_bytes()
    if support.digest(compressed)!=metadata['tables'][path.name]['sha256']:
        raise ValueError('native instruction classification changed')
    runs=[]
    cursor=raw_start
    count=0
    with gzip.open(io.BytesIO(compressed),'rt',encoding='utf-8',newline='') as stream:
        for row in csv.DictReader(stream,delimiter='\t'):
            start,end=int(row['start'],16),int(row['end'],16)
            count+=1
            if start>=raw_end:
                continue
            end=min(end,raw_end)
            if start!=cursor or end<=start:
                raise ValueError('native classification has a gap or overlap')
            kind=row['kind']
            if kind not in ('code','alignment','data','unknown','string'):
                raise ValueError('unsupported native classification')
            if kind=='string': kind='data'
            if runs and runs[-1][2]==kind:
                runs[-1]=(runs[-1][0],end,kind)
            else:
                runs.append((start,end,kind))
            cursor=end
    if cursor!=raw_end or count!=metadata['tables'][path.name]['rows']:
        raise ValueError('native map does not partition the file-backed .text')
    repaired=[]
    for start,end,kind in runs:
        index=bisect.bisect_left(sites,start)-1
        crossing=index>=0 and sites[index]<start<sites[index]+4
        if crossing:
            if not repaired or repaired[-1][2] not in ('data','unknown','mixeddata') or kind not in ('data','unknown'):
                raise ValueError('relocation crosses a code classification boundary')
            previous=repaired.pop()
            repaired.append((previous[0],end,'mixeddata'))
        else:
            repaired.append((start,end,kind))
    return repaired,{directory/'metadata.json':metadata_data,path:compressed}


def record_symbols(record,providers):
    result=set()
    kind=record['kind']
    if kind=='instruction':
        instruction=record['instruction']
        for operand in instruction['operands']:
            for key in ('target','value'):
                value=operand.get(key)
                if isinstance(value,dict): result.add(value['symbol'])
        memory=instruction.get('memory',{})
        if isinstance(memory.get('displacement'),dict): result.add(memory['displacement']['symbol'])
    elif kind=='data':
        result.update(item['symbol'] for item in record['elements'] if 'symbol' in item)
    elif kind=='coff':
        result.update(r['symbol_name'] for r in providers[record['ip']]['section']['relocations'] if r['type'])
    return result


def data_record(ip,raw,sites,classification):
    elements=[]
    cursor=0
    for site in sites:
        offset=site-ip
        if offset<cursor or offset+4>len(raw):
            raise ValueError('data relocation overlaps or extends outside its declaration')
        if offset>cursor:
            elements.append({'width':1,'values':list(raw[cursor:offset])})
        address=int.from_bytes(raw[offset:offset+4],'little')
        elements.append({'width':4,'symbol':'_sym_%08x'%address})
        cursor=offset+4
    if cursor<len(raw): elements.append({'width':1,'values':list(raw[cursor:])})
    return {'kind':'data','ip':ip,'size':len(raw),'classification':classification,'elements':elements}


def describe_range(ip,raw,kind,all_sites,overrides):
    sites=all_sites[bisect.bisect_left(all_sites,ip):bisect.bisect_left(all_sites,ip+len(raw))]
    if kind in ('data','mixeddata'):
        classification='ida_data' if kind=='data' else 'ida_data_with_unknown_tail'
        yield data_record(ip,raw,sites,classification)
        return
    if kind in ('alignment','unknown') and not sites and len(set(raw))==1 and raw[0] in (0,0x90,0xcc):
        classification='ida_alignment' if kind=='alignment' else 'reviewed_alignment'
        if kind=='unknown': overrides.append({'va':ip,'size':len(raw),'reason':'uniform alignment fill','value':raw[0]})
        yield {'kind':'padding','ip':ip,'size':len(raw),'value':raw[0],'classification':classification}
        return
    if kind=='unknown':
        if len(raw)%4==0 and sites==list(range(ip,ip+len(raw),4)):
            overrides.append({'va':ip,'size':len(raw),'reason':'every dword has an actual PE pointer relocation'})
            yield data_record(ip,raw,sites,'reviewed_pointer_table')
            return
        if not sites and set(raw).issubset({0,1,2}):
            overrides.append({'va':ip,'size':len(raw),'reason':'reviewed small selector table; all scalar values 0..2'})
            yield data_record(ip,raw,sites,'reviewed_selector_data')
            return
        if raw!=bytes.fromhex('8d4900'):
            raise ValueError('unresolved native unknown range %x (%d bytes)'%(ip,len(raw)))
        overrides.append({'va':ip,'size':len(raw),'reason':'reviewed LEA ECX,[ECX] alignment instruction'})
    decoder=Decoder(32,raw,ip=ip)
    for instruction in decoder:
        start=instruction.ip
        relocations=all_sites[bisect.bisect_left(all_sites,start):bisect.bisect_left(all_sites,start+instruction.len)]
        source=x86_source.describe(instruction,decoder.get_constant_offsets(instruction),relocations)
        record={'kind':'instruction','instruction':source,'classification':
                'ida_code' if kind=='code' else 'decoded_alignment'}
        symbols=record_symbols(record,{})
        bindings={name:int(name[5:],16) for name in symbols}
        encoded,_=x86_source.encode(source,bindings)
        reference=raw[start-ip:start-ip+instruction.len]
        if encoded!=reference:
            raise ValueError('source encoding differs at %x: %s'%(start,source['text']))
        yield record


def source_records(raw,text_va,runs,providers,sites,overrides):
    cursor=text_va
    end=text_va+len(raw)
    starts=sorted(providers)
    index=0
    while cursor<end:
        provider=providers.get(cursor)
        if provider is not None:
            reference=raw[cursor-text_va:cursor-text_va+provider['size']]
            if len(reference)!=provider['size'] or support.digest(reference)!=provider['sha256']:
                raise ValueError('compiled-provider reference is stale')
            yield {'kind':'coff','ip':cursor,'size':provider['size'],'provider':provider['key']}
            cursor+=provider['size']
            continue
        while index<len(runs) and runs[index][1]<=cursor:
            index+=1
        if index==len(runs) or not runs[index][0]<=cursor<runs[index][1]:
            raise ValueError('classification does not cover the next text byte')
        next_index=bisect.bisect_right(starts,cursor)
        next_provider=starts[next_index] if next_index<len(starts) else end
        stop=min(runs[index][1],next_provider,end)
        for record in describe_range(cursor,raw[cursor-text_va:stop-text_va],runs[index][2],sites,overrides):
            yield record
        cursor=stop


def symbol_owner(name,sections,header_size):
    if not re_symbol(name):
        raise ValueError('unexpected assembly label: '+name)
    va=int(name[5:],16)
    if 0x400000<=va<0x400000+header_size:
        return {'name':name,'va':va,'owner':'headers','offset':va-0x400000}
    for section,base,vsize,rawptr,rawsize in sections:
        if base<=va<base+max(vsize,rawsize):
            return {'name':name,'va':va,'owner':section,'offset':va-base,
                    'file_backed':va-base<rawsize}
    raise ValueError('referenced label has no declared image provider: '+name)


def re_symbol(name):
    return isinstance(name,str) and name.startswith('_sym_') and len(name)==13 and all(c in '0123456789abcdef' for c in name[5:])


def prepare(root,output,chunk_limit=65536):
    output.mkdir(parents=True,exist_ok=True)
    (output/'sources').mkdir(exist_ok=True)
    original,sections=exact.load_pe(exact.EXE_DEFAULT)
    if support.digest(original)!=exact.EXE_SHA256:
        raise ValueError('preparation reference differs from the pinned executable')
    text=next(s for s in sections if s[0]=='.text')
    _,text_va,virtual_size,rawptr,rawsize=text
    raw=original[rawptr:rawptr+rawsize]
    sites=leaf.pe_relocations(original,sections)
    runs,classification_inputs=native_runs(root,text_va,text_va+rawsize,sites)
    providers,provider_inputs=code_providers.load(root)
    chunk_records=[]
    chunk_start=text_va
    chunks=[]
    labels=set()
    counts=collections.Counter()
    overrides=[]

    def flush(stop):
        nonlocal chunk_start,chunk_records
        name='a%07x'%(chunk_start-0x400000)
        source_name='sources/'+name+'.jsonl.gz'
        content=b''.join((json.dumps(r,separators=(',',':'))+'\n').encode() for r in chunk_records)
        compressed=gzip.compress(content,compresslevel=6,mtime=0)
        (output/source_name).write_bytes(compressed)
        chunks.append({'section':name,'va':chunk_start,'size':stop-chunk_start,
                       'source':source_name,'source_sha256':support.digest(compressed),
                       'source_json_sha256':support.digest(content),'records':len(chunk_records),
                       'reference_sha256':support.digest(raw[chunk_start-text_va:stop-text_va])})
        chunk_start=stop
        chunk_records=[]

    for record in source_records(raw,text_va,runs,providers,sites,overrides):
        ip,size=position(record)
        if chunk_records and ip+size-chunk_start>chunk_limit:
            flush(ip)
        chunk_records.append(record)
        labels.update(record_symbols(record,providers))
        counts[record['kind']+'_records']+=1
        counts[record['kind']+'_bytes']+=size
        if sum(counts[k] for k in ('instruction_records','coff_records','data_records','padding_records'))%250000==0:
            print('prepared through',hex(ip),'instructions',counts['instruction_records'],flush=True)
    flush(text_va+rawsize)
    # All PE address operands, including data pointers to code, need layout labels.
    reader=exact.va_reader(original,sections)
    labels.update('_sym_%08x'%int.from_bytes(reader(site,4),'little') for site in sites)
    labels.update('_sym_%08x'%va for va in providers)
    labels.add('_sym_00400000')
    symbols=[symbol_owner(name,sections,1024) for name in sorted(labels)]
    plan={'schema_version':1,'target_sha256':exact.EXE_SHA256,'text_va':text_va,
          'text_raw_offset':rawptr,'text_raw_size':rawsize,'text_virtual_size':virtual_size,
          'reference_text_sha256':support.digest(raw),'chunks':chunks,'symbols':symbols,
          'counts':dict(counts),'classification_overrides':overrides,
          'classification_inputs':{str(p.relative_to(root)):support.digest(data) for p,data in classification_inputs.items()},
          'provider_inputs':{str(p.relative_to(root)):support.digest(data) for p,data in provider_inputs.items()},
          'providers':[{'va':p['va'],'size':p['size'],'key':p['key'],'family':p['family'],
                        'sha256':p['sha256'],'build_manifest_sha256':p['build_manifest_sha256']}
                       for p in sorted(providers.values(),key=lambda p:p['va'])],
          'source_generator_sha256':support.digest(Path(__file__).read_bytes()),
          'encoder_module_sha256':support.digest(Path(x86_source.__file__).read_bytes()),
          'original_instruction_blobs':False,'method':'mixed compiled C, explicit instruction fields, classified data and padding'}
    support.check_unchanged(dict(classification_inputs,**{}))
    support.check_unchanged(provider_inputs)
    (output/'generator.py').write_bytes(Path(__file__).read_bytes())
    plan_data=(json.dumps(plan,separators=(',',':'))+'\n').encode()
    (output/'plan.json.gz').write_bytes(gzip.compress(plan_data,compresslevel=6,mtime=0))
    print('Complete text source:',len(chunks),'chunks;',counts['instruction_records'],
          'explicit instructions;',len(providers),'compiled providers;',rawsize,'bytes')
    return plan


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action',choices=('prepare',))
    parser.add_argument('--root',type=Path,default=ROOT)
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/text_program')
    args=parser.parse_args()
    prepare(args.root,args.output)
