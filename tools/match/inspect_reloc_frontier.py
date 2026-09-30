#!/usr/bin/env python3
"""Inspect the real PE relocation dependencies of the preserved rejected C jobs."""
import bisect
import collections
import json
import struct
from pathlib import Path

import definitive_match as exact
import leaf_reconstruct as leaf

ROOT = Path(__file__).resolve().parents[2]


def main():
    data, sections = exact.load_pe(exact.EXE_DEFAULT)
    if leaf.digest(data) != exact.EXE_SHA256:
        raise ValueError('unexpected reference executable')
    read = exact.va_reader(data, sections)
    relocations = leaf.pe_relocations(data, sections)
    jobs = json.loads((ROOT / 'recon/ffx/c_leaf/jobs.json').read_text())
    proof = json.loads((ROOT / 'recon/ffx/c_leaf/proof.json').read_text())
    pending = {item['va'] for item in proof['unmatched']}
    kinds, segments, destinations, samples = collections.Counter(), collections.Counter(), {}, []
    dependencies = []
    print('PE relocation locations by section:',{
        name:sum(va <= site < va+max(vsize,rawsize) for site in relocations)
        for name,va,vsize,rawptr,rawsize in sections})
    for group in jobs['groups']:
        for target in group['targets']:
            va, size = target['va'], target['size']
            if va not in pending:
                continue
            code = read(va, size)
            if code is None or leaf.digest(code) != target['sha256']:
                raise ValueError('stale selected function')
            lo = bisect.bisect_left(relocations, va - 3)
            hi = bisect.bisect_left(relocations, va + size)
            sites = relocations[lo:hi]
            kinds[(group['source']['return_type'], group['source']['convention'], len(sites))] += 1
            for site in sites:
                if not va <= site <= va + size - 4:
                    raise ValueError('relocation crosses selected function')
                address = struct.unpack('<I', read(site, 4))[0]
                section = next((s for s in sections if s[1] <= address < s[1] + max(s[2],s[4])), None)
                kind = section[0] if section else 'unmapped'
                segments[kind] += 1
                entry = destinations.setdefault(address, {'va':address,'section':kind,'users':0})
                entry['users'] += 1
                dependencies.append({'function_va':va,'function_size':size,'symbol':group['symbol'],
                                     'site_va':site,'offset':site-va,'target_va':address,'section':kind})
                if len(samples) < 3 or kind == '.text':
                    samples.append({'function':target,'c':group['source'],'code':code.hex(),
                                    'site':hex(site),'target':hex(address),'section':kind,
                                    'data':(read(address,32) or b'').hex()})
    print(json.dumps({'pending':len(pending),'real_relocations':len(dependencies),
                      'unique_destinations':len(destinations),'target_sections':dict(segments),
                      'kinds':[(str(k),v) for k,v in kinds.items()],
                      'samples':samples},indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
