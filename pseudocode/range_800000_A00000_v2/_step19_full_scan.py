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

CHUNK_SIZE = 0x10000  # 64KB
range_start = 0x800000
range_end = 0xA00000

# Final strategy: search for "proc near" with include='all' to catch all lines
# Then filter to only unique addresses where the addr matches a function start
# The function start line has the format: .text:XXXXXXXX  sub_NAME proc near
# and the match kind will be 'disasm'

print("Comprehensive function scan...")
func_by_addr = {}  # addr -> function name

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
            'include': 'all'  # search both disasm and comments
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            addr = h.get('addr', '')
            fn = h.get('function', '')
            matches = h.get('matches', [])
            
            # Only count this as a function definition if the match is a 'disasm' kind
            # (function definition lines are disassembly, not comments)
            is_def = any(m.get('kind') == 'disasm' for m in matches)
            if is_def and fn:
                func_by_addr[addr] = fn
                
    except Exception as e:
        print('  ERR %s: %s' % (sh, e))
        continue

print('Functions found: %d' % len(func_by_addr))

# Sort by address
def addr_key(a):
    if isinstance(a, str):
        return int(a, 16) if a.startswith('0x') else int(a)
    return a
func_list = sorted(func_by_addr.items(), key=lambda x: addr_key(x[0]))

print('First 30:')
for addr, name in func_list[:30]:
    print('  %s %s' % (addr, name))
print('...')
print('Last 10:')
for addr, name in func_list[-10:]:
    print('  %s %s' % (addr, name))

# Save comprehensive list
with open(os.path.join(OUT, 'target_funcs_comprehensive.json'), 'w') as f:
    json.dump(func_list, f, indent=2)
with open(os.path.join(OUT, 'target_funcs_list_full.txt'), 'w') as f:
    for addr, name in func_list:
        f.write('%s %s\n' % (addr, name))
print('Saved %d functions' % len(func_list))
