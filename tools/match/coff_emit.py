#!/usr/bin/env python3
"""Emit normal i386 COFF objects from assembled code and symbol fixups."""
import struct
import coff_relocations as coff


def make_object(section_name,raw,relocations,definitions,characteristics=0x60100020):
    if not isinstance(raw,bytes) or not raw:
        raise ValueError('assembled section must contain bytes')
    if not isinstance(section_name,str) or not 1<=len(section_name.encode('ascii'))<=8:
        raise ValueError('section name must fit a normal COFF short name')
    if not isinstance(definitions,dict) or not isinstance(relocations,list):
        raise ValueError('invalid assembler symbol/fixup tables')
    if len(relocations)>65535:
        raise ValueError('split the assembler section before relocation count overflow')
    for name,value in definitions.items():
        if type(value) is not int or not 0<=value<=len(raw):
            raise ValueError('definition lies outside its assembled section')
    all_names=set(definitions)
    for record in relocations:
        if record.get('type') not in (coff.DIR32,coff.DIR32NB,coff.REL32):
            raise ValueError('unsupported assembler fixup')
        offset=record.get('offset')
        if type(offset) is not int or not 0<=offset<=len(raw)-4:
            raise ValueError('fixup is outside assembled section')
        all_names.add(record['symbol_name'])
    names=sorted(all_names)
    if any(not isinstance(name,str) or not name or '\0' in name for name in names):
        raise ValueError('invalid assembler symbol name')
    indexes={name:index for index,name in enumerate(names)}
    string_data=bytearray(b'\0'*4)
    symbols=[]
    for name in names:
        encoded=name.encode('utf-8')+b'\0'
        name_field=struct.pack('<II',0,len(string_data))
        string_data.extend(encoded)
        section=1 if name in definitions else 0
        value=definitions.get(name,0)
        symbols.append(struct.pack('<8sIhHBB',name_field,value,section,0,2,0))
    struct.pack_into('<I',string_data,0,len(string_data))
    relocation_data=b''.join(struct.pack('<IIH',r['offset'],indexes[r['symbol_name']],r['type'])
                             for r in relocations)
    raw_offset=60
    relocation_offset=raw_offset+len(raw) if relocations else 0
    symbols_offset=raw_offset+len(raw)+len(relocation_data)
    header=struct.pack('<HHIIIHH',0x14c,1,0,symbols_offset,len(names),0,0)
    section=struct.pack('<8sIIIIIIHHI',section_name.encode().ljust(8,b'\0'),0,0,
                        len(raw),raw_offset,relocation_offset,0,len(relocations),0,characteristics)
    result=header+section+raw+relocation_data+b''.join(symbols)+bytes(string_data)
    # Independent structural validation rejects overlapping writes and malformed
    # tables before an emitted object can reach the image linker.
    coff.parse_coff(result)
    return result
