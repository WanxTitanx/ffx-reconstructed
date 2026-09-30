#!/usr/bin/env python3
"""Editable x86 instruction source and a reference-free assembler frontend.

Source records contain encoding names, operands and prefix attributes, never
original instruction bytes. Only preparation uses Decoder. Assembly creates a
fresh Instruction and Encoder from these fields; relocatable assembly emits
real symbol fixups for a COFF writer instead of taking reference operand words.
"""
from iced_x86 import Code, Decoder, Encoder, Instruction, OpKind, Register
import re

CODE_NAMES={value:name for name,value in vars(Code).items() if name.isupper() and type(value) is int}
REGISTER_NAMES={value:name for name,value in vars(Register).items() if name.isupper() and type(value) is int}
KIND_NAMES={value:name for name,value in vars(OpKind).items() if name.isupper() and type(value) is int}
FORBIDDEN_CODES={'INVALID','DECLAREBYTE','DECLAREWORD','DECLAREDWORD','DECLAREQWORD'}
FLAGS=('has_lock_prefix','has_rep_prefix','has_repne_prefix','is_broadcast',
       'zeroing_masking','suppress_all_exceptions')
ALLOWED={'ip','length','code','operands','memory','prefixes','base_relocations','text'}


def _symbol(value):
    return {'symbol':'_sym_%08x'%value}


def describe(instruction,offsets,base_relocation_sites=()):
    if instruction.is_invalid or CODE_NAMES[instruction.code] in FORBIDDEN_CODES:
        raise ValueError('invalid instruction cannot become assembly source')
    record={'ip':instruction.ip,'length':instruction.len,'code':CODE_NAMES[instruction.code],
            'operands':[],'prefixes':{},'base_relocations':[],'text':str(instruction)}
    immediates=[]
    for index in range(instruction.op_count):
        kind=instruction.op_kind(index)
        operand={'kind':KIND_NAMES[kind]}
        if kind==OpKind.REGISTER:
            operand['register']=REGISTER_NAMES[instruction.op_register(index)]
        elif OpKind.IMMEDIATE8<=kind<=OpKind.IMMEDIATE32TO64:
            operand['value']=instruction.immediate(index)
            immediates.append(index)
        elif kind in (OpKind.NEAR_BRANCH16,OpKind.NEAR_BRANCH32,OpKind.NEAR_BRANCH64):
            operand['target']=_symbol(instruction.near_branch_target)
        elif kind in (OpKind.FAR_BRANCH16,OpKind.FAR_BRANCH32):
            operand['target']=_symbol(instruction.far_branch16 if kind==OpKind.FAR_BRANCH16 else instruction.far_branch32)
            operand['selector']=instruction.far_branch_selector
        elif kind==OpKind.MEMORY:
            record['memory']={'base':REGISTER_NAMES[instruction.memory_base],
                'index':REGISTER_NAMES[instruction.memory_index], 'scale':instruction.memory_index_scale,
                'displacement':instruction.memory_displacement,'displ_size':instruction.memory_displ_size}
        record['operands'].append(operand)
    for flag in FLAGS:
        if getattr(instruction,flag): record['prefixes'][flag]=True
    if instruction.segment_prefix:
        record['prefixes']['segment_prefix']=REGISTER_NAMES[instruction.segment_prefix]
    if instruction.op_mask:
        record['prefixes']['op_mask']=REGISTER_NAMES[instruction.op_mask]
    if instruction.rounding_control:
        record['prefixes']['rounding_control']=instruction.rounding_control
    for site in sorted(base_relocation_sites):
        offset=site-instruction.ip
        if offsets.displacement_size==4 and offset==offsets.displacement_offset and 'memory' in record:
            record['memory']['displacement']=_symbol(instruction.memory_displacement)
            field='memory'
        elif offsets.immediate_size==4 and offset==offsets.immediate_offset and immediates:
            index=immediates[0]
            operand=record['operands'][index]
            operand['value']=_symbol(operand['value'])
            field='operand:'+str(index)
        else:
            raise ValueError('PE relocation is not an actual four-byte instruction operand')
        record['base_relocations'].append({'field':field,'offset':offset,'size':4})
    return record


def _resolve(value,bindings):
    if type(value) is int and 0<=value<2**64:
        return value
    if not isinstance(value,dict) or set(value)!={'symbol'} or value['symbol'] not in bindings:
        raise ValueError('missing or invalid assembly symbol')
    result=bindings[value['symbol']]
    if type(result) is not int or not 0<=result<2**64:
        raise ValueError('invalid bound symbol address')
    return result


def _field_symbol(record,field):
    if field=='memory':
        if 'memory' not in record or not any(o['kind']=='MEMORY' for o in record['operands']):
            raise ValueError('memory relocation has no memory operand')
        value=record['memory']['displacement']
    else:
        match=re.fullmatch('operand:([0-4])',field) if isinstance(field,str) else None
        if match is None or int(match[1])>=len(record['operands']):
            raise ValueError('base relocation has an invalid operand field')
        operand=record['operands'][int(match[1])]
        if operand['kind']!='IMMEDIATE32':
            raise ValueError('base relocation does not name a four-byte immediate operand')
        value=operand['value']
    if not isinstance(value,dict) or set(value)!={'symbol'}:
        raise ValueError('base relocation must refer to an explicit symbol')
    return value['symbol']


def _operand_keys(operand):
    if not isinstance(operand,dict) or operand.get('kind') not in KIND_NAMES.values():
        raise ValueError('invalid operand kind')
    name=operand['kind']
    keys={'kind'}
    if name=='REGISTER': keys.add('register')
    elif name.startswith('IMMEDIATE'): keys.add('value')
    elif name.startswith('NEAR_BRANCH'): keys.add('target')
    elif name.startswith('FAR_BRANCH'): keys.update(('target','selector'))
    if set(operand)!=keys:
        raise ValueError('operand fields do not belong to their declared kind')


def encode(record,bindings,bitness=32,relocatable=False):
    if not isinstance(record,dict) or set(record)-ALLOWED:
        raise ValueError('unsupported instruction-source field')
    if record.get('code') in FORBIDDEN_CODES or record.get('code') not in vars(Code):
        raise ValueError('source does not name an encodable instruction')
    ip,length=record['ip'],record['length']
    if (bitness not in (16,32,64) or type(ip) is not int or not 0<=ip<2**64
            or type(length) is not int or not 1<=length<=15):
        raise ValueError('invalid instruction address/length')
    instruction=Instruction()
    instruction.code=getattr(Code,record['code'])
    operands=record['operands']
    if not isinstance(operands,list) or len(operands)!=instruction.op_count:
        raise ValueError('wrong operand count')
    for operand in operands:
        _operand_keys(operand)
    if not isinstance(record['base_relocations'],list):
        raise ValueError('invalid base relocation table')
    for relocation in record['base_relocations']:
        if (not isinstance(relocation,dict) or set(relocation)!={'field','offset','size'}
                or type(relocation['offset']) is not int or not 0<=relocation['offset']<=length-4
                or type(relocation['size']) is not int or relocation['size']!=4):
            raise ValueError('invalid declared relocation shape')
        _field_symbol(record,relocation['field'])
    relocation_fields={r['field'] for r in record['base_relocations']}
    if len(relocation_fields)!=len(record['base_relocations']):
        raise ValueError('duplicate base relocation field')
    relative_operands=[]
    for index,operand in enumerate(operands):
        name=operand['kind']
        if name not in vars(OpKind):
            raise ValueError('invalid operand kind')
        kind=getattr(OpKind,name)
        instruction.set_op_kind(index,kind)
        if kind==OpKind.REGISTER:
            instruction.set_op_register(index,getattr(Register,operand['register']))
        elif OpKind.IMMEDIATE8<=kind<=OpKind.IMMEDIATE32TO64:
            value=_resolve(operand['value'],bindings)
            instruction.set_immediate_u64(index,value)
            if instruction.immediate(index)!=value:
                raise ValueError('immediate value exceeds its kind or lacks canonical sign extension')
            if relocatable and 'operand:'+str(index) in relocation_fields:
                instruction.set_immediate_u64(index,0)
        elif kind in (OpKind.NEAR_BRANCH16,OpKind.NEAR_BRANCH32,OpKind.NEAR_BRANCH64):
            value=_resolve(operand['target'],bindings)
            width={OpKind.NEAR_BRANCH16:16,OpKind.NEAR_BRANCH32:32,OpKind.NEAR_BRANCH64:64}[kind]
            if value>=1<<width:
                raise ValueError('branch target exceeds declared address width')
            # Long relative branches become genuine COFF REL32 records. Short
            # branches remain assembler-resolved between declared layout labels.
            long_branch=kind==OpKind.NEAR_BRANCH32 and not (
                instruction.is_jcc_short or instruction.is_jmp_short or
                instruction.is_loop or instruction.is_loopcc or instruction.is_jcx_short)
            if relocatable and long_branch:
                value=ip+length
                relative_operands.append(index)
            setattr(instruction,{OpKind.NEAR_BRANCH16:'near_branch16',OpKind.NEAR_BRANCH32:'near_branch32',
                                 OpKind.NEAR_BRANCH64:'near_branch64'}[kind],value)
        elif kind in (OpKind.FAR_BRANCH16,OpKind.FAR_BRANCH32):
            setattr(instruction,'far_branch16' if kind==OpKind.FAR_BRANCH16 else 'far_branch32',
                    _resolve(operand['target'],bindings))
            instruction.far_branch_selector=operand['selector']
    if 'memory' in record:
        memory=record['memory']
        if (not any(o['kind']=='MEMORY' for o in operands)
                or set(memory)!={'base','index','scale','displacement','displ_size'}):
            raise ValueError('invalid memory expression')
        instruction.memory_base=getattr(Register,memory['base'])
        instruction.memory_index=getattr(Register,memory['index'])
        instruction.memory_index_scale=memory['scale']
        instruction.memory_displ_size=memory['displ_size']
        displacement=_resolve(memory['displacement'],bindings)
        if relocatable and 'memory' in relocation_fields: displacement=0
        instruction.memory_displacement=displacement
    for key,value in record['prefixes'].items():
        if key in FLAGS:
            if type(value) is not bool:
                raise ValueError('prefix flag is not a boolean')
            setattr(instruction,key,value)
        elif key in ('segment_prefix','op_mask'):
            setattr(instruction,key,getattr(Register,value))
        elif key=='rounding_control':
            instruction.rounding_control=value
        else:
            raise ValueError('unsupported instruction prefix')
    encoder=Encoder(bitness)
    encoder.encode(instruction,ip)
    raw=encoder.take_buffer()
    offsets=encoder.get_constant_offsets()
    if len(raw)!=length:
        raise ValueError('encoding length changed: %s at %x: %d != %d' % (record['code'],ip,len(raw),length))
    fixups=[]
    for relocation in record['base_relocations']:
        field=relocation['field']
        if field=='memory':
            offset,size=offsets.displacement_offset,offsets.displacement_size
        else:
            actual_immediate=[i for i,o in enumerate(operands) if o['kind'].startswith('IMMEDIATE')]
            if not actual_immediate or field!='operand:'+str(actual_immediate[0]):
                raise ValueError('base relocation does not own the encoded immediate field')
            offset,size=offsets.immediate_offset,offsets.immediate_size
        if size!=4 or offset!=relocation['offset'] or relocation['size']!=4:
            raise ValueError('assembler relocation moved outside its declared operand')
        if relocatable:
            if raw[offset:offset+4]!=b'\0'*4:
                raise ValueError('unexpected implicit assembler addend')
            fixups.append({'offset':offset,'type':6,'symbol_name':_field_symbol(record,field),
                           'base_relocation':True})
    for index in relative_operands:
        if offsets.immediate_size!=4 or raw[offsets.immediate_offset:offsets.immediate_offset+4]!=b'\0'*4:
            raise ValueError('unsupported relative branch relocation shape')
        fixups.append({'offset':offsets.immediate_offset,'type':20,
                       'symbol_name':operands[index]['target']['symbol'],'base_relocation':False})
    return raw,fixups
