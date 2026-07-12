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

# Step 1: Search for "proc near" in the full 0x800000-0xA00000 range with limit=500
print("=== search_text 'proc near' 0x800000-0xA00000 ===")
raw = call('search_text', {
    'database': DB,
    'pattern': 'proc near',
    'start': '0x800000',
    'end': '0xA00000',
    'limit': 500,
    'code_only': True
})

text = json.loads(raw['result']['content'][0]['text'])
n = text.get('n', 0)
more = text.get('more', False)
hits = text.get('hits', [])
print('Total hits returned: %d' % n)
print('More available: %s' % more)
print()

# Extract unique function addresses
funcs = {}
for h in hits:
    addr = h.get('addr', '')
    func_name = h.get('function', '')
    if func_name:
        funcs[addr] = func_name

print('Unique functions found: %d' % len(funcs))
func_list = sorted(funcs.items(), key=lambda x: int(x[0], 16) if x[0].startswith('0x') else 0)
print()
print('First 20:')
for addr, name in func_list[:20]:
    print('  %s %s' % (addr, name))
print()
print('Last 5:')
for addr, name in func_list[-5:]:
    print('  %s %s' % (addr, name))

# Save to file
with open(os.path.join(OUT, 'target_funcs_from_search.json'), 'w') as f:
    json.dump(func_list, f, indent=2)
print('Saved %d functions to target_funcs_from_search.json' % len(func_list))
