import csv,gzip,sys
from pathlib import Path
import definitive_match as exact
original,sections=exact.load_pe(exact.EXE_DEFAULT)
read=exact.va_reader(original,sections)
root=Path(__file__).resolve().parents[2]
with gzip.open(root/'recon/ffx/analysis_map/text_runs.tsv.gz','rt') as stream:
    for row in csv.DictReader(stream,delimiter='\t'):
        if row['kind']!='unknown': continue
        va,size=int(row['start'],16),int(row['size'])
        raw=read(va,size)
        if raw is None: continue
        if len(set(raw))==1 and raw[0] in (0,0xcc,0x90): continue
        print(hex(va),size,raw.hex(),repr(raw))
