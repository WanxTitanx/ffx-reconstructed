#!/usr/bin/env python3
"""Generate symbolic assembly declarations for PE data sections."""
import argparse
import bisect
import json
import shutil
import subprocess
import tempfile
from pathlib import Path
import definitive_match as exact
import leaf_reconstruct as leaf
import leaf_build as support
ROOT=Path(__file__).resolve().parents[2]


def chunk_ranges(va,size,relocations,limit=65536):
    spans=[]
    stop=va+size
    while va<stop:
        end=min(va+limit,stop)
        index=bisect.bisect_left(relocations,end)-1
        if index>=0 and relocations[index]<end<relocations[index]+4:
            end=relocations[index]
        if end<=va:
            raise ValueError('chunk cannot contain a complete pointer')
        spans.append((va,end-va))
        va=end
    return spans


def render_chunk(name,va,raw,refs,labels):
    sites=sorted(refs)
    previous=va
    for site in sites:
        if site<previous or site+4>va+len(raw):
            raise ValueError('overlapping or truncated data pointer')
        previous=site+4
    labels=sorted(x for x in labels if va<=x<va+len(raw))
    label_set=set(labels)
    lines=['.code32','.section '+name+',"dw"']
    cursor=va
    while cursor<va+len(raw):
        if cursor in label_set:
            symbol='_sym_%08x'%cursor
            lines.extend(('.globl '+symbol,symbol+':'))
        if cursor in refs:
            for inner in labels[bisect.bisect_right(labels,cursor):bisect.bisect_left(labels,cursor+4)]:
                symbol='_sym_%08x'%inner
                lines.extend(('.globl '+symbol,'.set '+symbol+', . + '+str(inner-cursor)))
            lines.append('.long _sym_%08x'%refs[cursor])
            cursor+=4
            continue
        li=bisect.bisect_right(labels,cursor)
        si=bisect.bisect_right(sites,cursor)
        next_label=labels[li] if li<len(labels) else va+len(raw)
        next_site=sites[si] if si<len(sites) else va+len(raw)
        end=min(cursor+16,va+len(raw),next_label,next_site)
        lines.append('.byte '+', '.join('0x%02x'%b for b in raw[cursor-va:end-va]))
        cursor=end
    return '\n'.join(lines)+'\n'


def render_zero_storage(name,va,size,labels):
    lines=['.code32','.section '+name+',"bw"']
    cursor=va
    for address in sorted(x for x in labels if va<=x<va+size):
        if address>cursor:
            lines.append('.zero '+str(address-cursor))
        symbol='_sym_%08x'%address
        lines.extend(('.globl '+symbol,symbol+':'))
        cursor=address
    if cursor<va+size:
        lines.append('.zero '+str(va+size-cursor))
    return '\n'.join(lines)+'\n'


def prepare(output):
    original,sections=exact.load_pe(exact.EXE_DEFAULT)
    if leaf.digest(original)!=exact.EXE_SHA256:
        raise ValueError('unexpected reference')
    read=exact.va_reader(original,sections)
    sites=leaf.pe_relocations(original,sections)
    destinations={}
    for site in sites:
        word=read(site,4)
        if word is None:
            raise ValueError('reference relocation is not file-backed')
        destinations[site]=int.from_bytes(word,'little')
    labels=set(destinations.values())
    output.mkdir(parents=True,exist_ok=True)
    (output/'sources').mkdir(exist_ok=True)
    chunks=[]
    for name,va,virtual_size,rawptr,rawsize in sections:
        if name in ('.text','.reloc'):
            continue
        for start,size in chunk_ranges(va,rawsize,sites):
            tag='d%07x'%(start-0x400000)
            refs={site:destinations[site] for site in sites[bisect.bisect_left(sites,start):bisect.bisect_left(sites,start+size)]}
            raw=read(start,size)
            text=render_chunk(tag,start,raw,refs,labels)
            source=('sources/'+tag+'.S')
            (output/source).write_bytes(text.encode())
            chunks.append({'source':source,'section':tag,'original_section':name,'va':start,'size':size,
                           'zero_storage':False,'source_sha256':leaf.digest(text.encode()),
                           'reference_sha256':leaf.digest(raw),'relocations':len(refs)})
        if virtual_size>rawsize:
            start,size=va+rawsize,virtual_size-rawsize
            tag='b%07x'%(start-0x400000)
            text=render_zero_storage(tag,start,size,labels)
            source='sources/'+tag+'.S'
            (output/source).write_bytes(text.encode())
            chunks.append({'source':source,'section':tag,'original_section':name,'va':start,'size':size,
                           'zero_storage':True,'source_sha256':leaf.digest(text.encode()),'relocations':0})
    return save_plan(output,chunks,labels,sections)


def save_plan(output,chunks,labels,sections):
    symbols=[]
    for va in sorted(labels):
        owner=next((c for c in chunks if c['va']<=va<c['va']+c['size']),None)
        kind='data' if owner else 'code_or_external'
        symbols.append({'name':'_sym_%08x'%va,'va':va,'kind':kind,
                        'section':owner['section'] if owner else None,
                        'offset':va-owner['va'] if owner else None})
    plan={'target_sha256':exact.EXE_SHA256,'generator_sha256':leaf.digest(Path(__file__).read_bytes()),
          'chunks':chunks,'symbols':symbols,'data_is_declared_payload':True,
          'code_payload_copied':False,'reference_sections':sections}
    (output/'plan.json').write_bytes((json.dumps(plan,indent=2)+'\n').encode())
    (output/'generator.py').write_bytes(Path(__file__).read_bytes())
    print('Data declarations:',len(chunks),'chunks;',sum(c['size'] for c in chunks if not c['zero_storage']),
          'file-backed bytes;',sum(c['relocations'] for c in chunks),'symbolic pointer fields')
    return plan


def build(output):
    builddir=output/'build'
    builddir.mkdir(exist_ok=True)
    (builddir/'manifest.json').unlink(missing_ok=True)
    (output/'proof.json').unlink(missing_ok=True)
    plan_data=(output/'plan.json').read_bytes()
    plan=json.loads(plan_data)
    if leaf.digest(Path(__file__).read_bytes())!=plan['generator_sha256']:
        raise ValueError('data generator changed; prepare again')
    generator=Path(__file__).read_bytes()
    snapshots=builddir/'inputs'
    (snapshots/'sources').mkdir(parents=True,exist_ok=True)
    (snapshots/'plan.json').write_bytes(plan_data)
    (snapshots/'generator.py').write_bytes(generator)
    observed={output/'plan.json':plan_data,Path(__file__):generator,
              snapshots/'plan.json':plan_data,snapshots/'generator.py':generator}
    entries=[]
    logs=[]
    for chunk in plan['chunks']:
        source=output/chunk['source']
        contents=source.read_bytes()
        if leaf.digest(contents)!=chunk['source_sha256']:
            raise ValueError('declared data changed')
        with tempfile.TemporaryDirectory(prefix='data-asm-',dir=builddir) as tmp:
            work=Path(tmp)
            (work/'source.S').write_bytes(contents)
            command=['clang','--target=i686-pc-windows-msvc','-c','-x','assembler',
                     'source.S','-o','data.obj']
            result=subprocess.run(command,cwd=work,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
            logs.append(('source='+chunk['source']+'\ncommand='+json.dumps(command)+'\n').encode()
                        +result.stdout+('\nexit_code='+str(result.returncode)+'\n').encode())
            (builddir/'build.log').write_bytes(b''.join(logs))
            if result.returncode:
                raise ValueError('native COFF data assembly failed: '+chunk['source'])
            if source.read_bytes()!=contents or (work/'source.S').read_bytes()!=contents:
                raise ValueError('data source changed during assembly')
            raw=(work/'data.obj').read_bytes()
        name=chunk['section']+'.obj'
        (builddir/name).write_bytes(raw)
        (snapshots/chunk['source']).write_bytes(contents)
        observed[source]=contents
        observed[snapshots/chunk['source']]=contents
        observed[builddir/name]=raw
        entries.append({'object':name,'object_sha256':leaf.digest(raw),'source':chunk['source'],
                        'source_sha256':chunk['source_sha256']})
    support.check_unchanged(observed)
    manifest={'plan_sha256':leaf.digest(plan_data),'generator_sha256':leaf.digest(generator),'entries':entries,
              'build_log_sha256':leaf.digest((builddir/'build.log').read_bytes()),
              'assembler_sha256':leaf.digest(Path(shutil.which('clang')).read_bytes()),
              'assembler':subprocess.check_output(['clang','--version'],text=True).splitlines()[0],
              'target':'i686-pc-windows-msvc','format':'native COFF, no intermediate-format conversion'}
    if (output/'plan.json').read_bytes()!=plan_data:
        raise ValueError('data plan changed during build')
    (builddir/'manifest.json').write_bytes((json.dumps(manifest,indent=2)+'\n').encode())
    print('Assembled declared data into',len(entries),'COFF objects')
    return manifest


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action',choices=('prepare','build'))
    parser.add_argument('--output',type=Path,default=ROOT/'recon/ffx/pe_data')
    args=parser.parse_args()
    (prepare if args.action=='prepare' else build)(args.output)
