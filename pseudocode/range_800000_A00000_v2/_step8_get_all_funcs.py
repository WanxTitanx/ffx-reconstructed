import urllib.request, json, os

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    d = json.loads(resp.read().decode())
    return d

# entity_query returns list of pages
# Let's try getting a page
print("=== entity_query large count ===")
raw = call('entity_query', {
    'database': DB,
    'queries': {'type': 'func', 'offset': 0, 'count': 50000, 'sort_by': 'addr'}
})

# raw is the full MCP response
content = raw['result']['content'][0]['text']
pages = json.loads(content)

# pages is a list of page objects
all_funcs = []
total = 0
for page in pages:
    data = page.get('data', [])
    total = page.get('total', 0)
    all_funcs.extend(data)
    nxt = page.get('next_offset')
    print('Page: %d items, next_offset=%s, total=%s' % (len(data), nxt, total))

print('Total collected: %d (out of %d)' % (len(all_funcs), total))

# Save full list
with open(os.path.join(OUT, 'all_funcs_full.json'), 'w') as f:
    json.dump(all_funcs, f, indent=2)
print('Saved all_funcs_full.json')

# Filter by address range 0x800000 - 0xA00000
range_funcs = []
for f in all_funcs:
    addr_str = f.get('addr', '0x0')
    if isinstance(addr_str, str):
        addr = int(addr_str, 16) if addr_str.startswith('0x') else int(addr_str)
    else:
        addr = addr_str
    if 0x800000 <= addr < 0xA00000:
        range_funcs.append(f)

print()
print('Functions in 0x800000-0xA00000: %d' % len(range_funcs))
for f in range_funcs[:20]:
    print('  %s %s' % (f['addr'], f['name']))
print('  ...')
for f in range_funcs[-5:]:
    print('  %s %s' % (f['addr'], f['name']))

# Save filtered list
with open(os.path.join(OUT, 'target_funcs_full.json'), 'w') as f:
    json.dump(range_funcs, f, indent=2)
print('Saved target_funcs_full.json')
