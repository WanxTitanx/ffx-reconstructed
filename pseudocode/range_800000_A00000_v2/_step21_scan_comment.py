import urllib.request, json, os, re

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

CHUNK_SIZE = 0x20000  # 128KB chunks
range_start = 0x800000
range_end = 0xA00000

# Strategy A: search for "endp" to get function count, then use lookup_funcs for each endp to find start
# Strategy B: search for function definition comments "; int" or "; void" or "; signed"
# Strategy C: search for function-like patterns using regex

# Actually, let me try a smarter approach:
# The `proc near` approach found 1970. But there should be more.
# Maybe some functions don't have the standard comment format.
# Let me search for endp (unique per function), collect the function names,
# then use lookup_funcs with each function NAME to get the start address.

print("=== Finding all functions via endp + lookup_funcs ===")

# First, collect ALL endp hits with function names
endp_funcs = {}  # function name -> (end_addr, )

for start_addr in range(range_start, range_end, CHUNK_SIZE):
    end_addr = min(start_addr + CHUNK_SIZE, range_end)
    sh = '0x%X' % start_addr
    eh = '0x%X' % end_addr
    
    try:
        raw = call('search_text', {
            'database': DB,
            'pattern': 'endp',
            'start': sh,
            'end': eh,
            'limit': 500,
            'code_only': True,
            'include': 'disasm'
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            fn = h.get('function', '')
            if fn:
                endp_funcs[fn] = h.get('addr', '')
    except Exception as e:
        print('  ERR %s: %s' % (sh, e))

print('Found %d unique function names via endp' % len(endp_funcs))

# Load proc near functions
proc_funcs = {}
for start_addr in range(range_start, range_end, CHUNK_SIZE):
    end_addr = min(start_addr + CHUNK_SIZE, range_end)
    sh = '0x%X' % start_addr
    eh = '0x%X' % end_addr
    
    try:
        raw = call('search_text', {
            'database': DB,
            'pattern': 'proc near',
            'start': sh,
            'end': eh,
            'limit': 500,
            'code_only': True,
            'include': 'disasm'
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            fn = h.get('function', '')
            addr = h.get('addr', '')
            matches = h.get('matches', [])
            is_def = any(m.get('kind') == 'disasm' for m in matches)
            if is_def and fn:
                proc_funcs[fn] = addr
    except Exception as e:
        print('  ERR %s: %s' % (sh, e))

print('Found %d unique function names via proc near' % len(proc_funcs))

# Functions in endp but not in proc near
missing = set(endp_funcs.keys()) - set(proc_funcs.keys())
print('Functions in endp but NOT in proc near: %d' % len(missing))
if missing:
    # Show first 20 missing
    print('First 20 missing:')
    for fn in sorted(list(missing))[:20]:
        print('  %s (endp at %s)' % (fn, endp_funcs[fn]))

# Now, for the missing functions, try lookup_funcs to get their start addresses
print()
print('Looking up missing functions...')
found_starts = {}
missing_list = sorted(list(missing))
# Process in batches of 50
for i in range(0, len(missing_list), 50):
    batch = missing_list[i:i+50]
    try:
        raw = call('lookup_funcs', {
            'database': DB,
            'queries': batch
        })
        lookup_result = raw['result']['content'][0]['text']
        lookup_data = json.loads(lookup_result)
        for item in lookup_data.get('result', []):
            fn_info = item.get('fn')
            if fn_info:
                found_starts[fn_info.get('name')] = fn_info.get('addr')
    except Exception as e:
        print('  ERR batch %d: %s' % (i//50, e))

print('Found starts for %d missing functions' % len(found_starts))
if found_starts:
    print('First 10:')
    for fn, addr in sorted(found_starts.items())[:10]:
        print('  %s -> %s' % (fn, addr))

# Combine into final list
final_funcs = {}
for fn, addr in proc_funcs.items():
    final_funcs[addr] = fn
for fn, addr in found_starts.items():
    final_funcs[addr] = fn

print()
print('Final combined function count: %d' % len(final_funcs))

# Save
flist = sorted(final_funcs.items(), key=lambda x: int(x[0],16) if x[0].startswith('0x') else 0)
with open(os.path.join(OUT, 'target_funcs_combined.json'), 'w') as f:
    json.dump(flist, f, indent=2)
with open(os.path.join(OUT, 'target_funcs_list_combined.txt'), 'w') as f:
    for addr, name in flist:
        f.write('%s %s\n' % (addr, name))
print('Saved combined list')
print()
print('First 30:')
for addr, name in flist[:30]:
    print('  %s %s' % (addr, name))
print('...')
print('Last 10:')
for addr, name in flist[-10:]:
    print('  %s %s' % (addr, name))
