#!/usr/bin/env python3
"""Measure instruction-source roundtrip failures before admitting any code source."""
import bisect
import collections
import json
from pathlib import Path
from iced_x86 import Decoder
import definitive_match as exact
import leaf_reconstruct as leaf
import x86_source as source


def bindings_for(record):
    values=[operand.get('value',operand.get('target')) for operand in record['operands']]
    if 'memory' in record: values.append(record['memory']['displacement'])
    return {v['symbol']:int(v['symbol'][5:],16) for v in values if isinstance(v,dict)}


def main():
    original,sections=exact.load_pe(exact.EXE_DEFAULT)
    if leaf.digest(original)!=exact.EXE_SHA256: raise ValueError('wrong reference')
    read=exact.va_reader(original,sections)
    sites=leaf.pe_relocations(original,sections)
    inventory=leaf.inventory_rows((leaf.DEFAULT_PROJECT/'tools/match/inventory.tsv').read_bytes())
    counts=collections.Counter()
    samples=[]
    for number,function in enumerate(inventory):
        raw=read(function['va'],function['size'])
        decoder=Decoder(32,raw,ip=function['va'])
        for instruction in decoder:
            va=instruction.ip
            relevant=sites[bisect.bisect_left(sites,va):bisect.bisect_left(sites,va+instruction.len)]
            reference=raw[va-function['va']:va-function['va']+instruction.len]
            try:
                record=source.describe(instruction,decoder.get_constant_offsets(instruction),relevant)
                encoded,_=source.encode(record,bindings_for(record))
                reason='exact' if encoded==reference else 'noncanonical_encoding'
            except (ValueError,OverflowError,AttributeError) as exc:
                reason=type(exc).__name__+': '+str(exc)
                encoded=None
            counts[reason]+=1
            if reason!='exact' and len(samples)<200:
                samples.append({'va':hex(va),'function':function['idb_name'],'text':str(instruction),
                                'reason':reason,'reference':reference.hex(),
                                'candidate':encoded.hex() if encoded is not None else None})
        if number and number%15000==0:
            print('probe progress:',number,'functions,',counts['exact'],'exact instructions',flush=True)
    output=Path(__file__).resolve().parents[2]/'recon/ffx/asm_source'
    output.mkdir(exist_ok=True)
    report={'counts':dict(counts),'samples':samples,'not_an_acceptance_proof':True,
            'caveat':'Inventory ranges can contain data; the IDA typed map must classify final source.'}
    (output/'encoding_probe.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({'counts':dict(counts),'samples':samples[:8]},indent=2))
    return 0


if __name__=='__main__': raise SystemExit(main())
