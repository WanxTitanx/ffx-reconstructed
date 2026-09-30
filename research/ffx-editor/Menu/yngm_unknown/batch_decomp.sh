#!/bin/bash
# batch_decomp.sh — decompile a list of addrs/names, saving decomp_<safe>.txt
for target in "$@"; do
  safe=$(echo "$target" | tr -c 'A-Za-z0-9_' '_')
  out="decomp_${safe}.txt"
  ./mcp.sh decompile "{\"addr\":\"$target\"}" > "raw_${safe}.json" 2>/dev/null
  python3 -c "
import json,sys
try:
    d=json.load(open('raw_${safe}.json'))
    inner=json.loads(d['result']['content'][0]['text']) if 'result' in d else d
    open('${out}','w').write(inner.get('code','')+'\n\nREFS: '+json.dumps(inner.get('refs',[])))
    print('${out}', 'ok', inner.get('addr'))
except Exception as e:
    print('${out}','FAIL',e)
"
done
