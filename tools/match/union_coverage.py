import json, csv, collections
inv={}
for r in csv.DictReader(open('/mnt/ssd-kingston/ffx-reconstructed/tools/match/inventory.tsv'),delimiter='\t'):
    inv[int(r['start'],16)]=(int(r['size']), r['name'])
total_funcs=len(inv); total_bytes=sum(v[0] for v in inv.values())

claimed=collections.OrderedDict()  # va -> (size, name, source)

def claim(va, size, name, source, expect_name=None):
    if va not in inv: return False
    isz, iname = inv[va]
    if isz != size: return False
    if expect_name is not None and expect_name.lower() != iname.lower(): return False
    claimed.setdefault(va, (size, iname, source))
    return True

# Lua
lua=json.load(open('/mnt/ssd-kingston/ffx-reconstructed/recon/lua/confirmed.json'))
nl=0
for x in lua:
    if claim(x['va'], x['size'], x['idb_name'], 'lua-src'): nl+=1

# SDK libs
libs=json.load(open('/mnt/ssd-kingston/ffx-reconstructed/recon/sdk_libs_confirmed.json'))
per=collections.Counter(); nb=0
for lib, items in libs.items():
    for x in items:
        if claim(x['va'], x['size'], x['idb_name'], 'lib:'+lib):
            per[lib]+=1; nb+=1

# FFX_memcmp
claim(0x401020, 112, 'FFX_memcmp', 'ffx-src')

cov_f=len(claimed); cov_b=sum(v[0] for v in claimed.values())
print(f'IDB total                      : {total_funcs:,} funcs / {total_bytes:,} bytes')
print(f'UNIQUE byte-identical functions: {cov_f:,} funcs / {cov_b:,} bytes')
print(f'coverage                       : {100*cov_f/total_funcs:.2f}% of functions, {100*cov_b/total_bytes:.2f}% of code bytes')
print()
print('newly claimed per SDK lib (first-claimer):')
for k,v in per.most_common(): print(f'  {k:26s} {v:4d}')
print(f'  lua-src (compiled)         {nl:4d}')
src=collections.Counter(v[2] for v in claimed.values())
print('\nby evidence source:')
for k,v in src.most_common(): print(f'  {k:26s} {v:4d}')
json.dump({'functions':[{'va':va,'size':s,'idb_name':n,'source':src_} for va,(s,n,src_) in claimed.items()],
           'totals':{'idb_funcs':total_funcs,'idb_bytes':total_bytes,'matched_funcs':cov_f,'matched_bytes':cov_b}},
          open('/mnt/ssd-kingston/ffx-reconstructed/recon/matched_functions.json','w'), indent=1)
print('\nwrote recon/matched_functions.json')
