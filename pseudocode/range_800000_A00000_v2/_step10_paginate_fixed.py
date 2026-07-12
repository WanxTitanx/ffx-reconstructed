import urllib.request, json, os, sys

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'
PAGE_SIZE = 2000

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

def get_page(raw):
    """Extract page data from raw MCP response"""
    # structuredContent.result[0] has the page
    sc = raw['result'].get('structuredContent', {})
    if isinstance(sc, dict) and 'result' in sc:
        pages = sc['result']
        if isinstance(pages, list) and len(pages) > 0:
            return pages[0]
    return None

# Paginate through ALL functions
all_funcs = []
total = None
offset = 0
page_num = 0

print('Paginating through all functions...')
while total is None or offset < total:
    raw = call('entity_query', {
        'database': DB,
        'queries': {'type': 'func', 'offset': offset, 'count': PAGE_SIZE, 'sort_by': 'addr'}
    })
    
    page = get_page(raw)
    if page is None:
        print('ERROR: Could not extract page data')
        print('SC:', json.dumps(raw['result'].get('structuredContent', {}), indent=2)[:500])
        break
    
    data = page.get('data', [])
    nxt = page.get('next_offset')
    total = page.get('total', 0)
    err = page.get('error')
    
    if err:
        print('ERROR at offset %d: %s' % (offset, err))
        break
    
    all_funcs.extend(data)
    page_num += 1
    print('  Page %d: offset=%d, got=%d, cumulative=%d, total=%d' % (
        page_num, offset, len(data), len(all_funcs), total))
    
    if nxt is not None:
        offset = nxt
    elif len(data) < PAGE_SIZE:
        break
    else:
        offset += PAGE_SIZE
    
    if page_num > 50:
        print('TOO MANY PAGES - safety break')
        break

print()
print('Total functions collected: %d (total reported: %s)' % (len(all_funcs), total))

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

# Sort by address
def addr_key(f):
    a = f.get('addr', '0x0')
    return int(a, 16) if isinstance(a, str) and a.startswith('0x') else int(a)
range_funcs.sort(key=addr_key)

print()
print('Functions in 0x800000-0xA00000: %d' % len(range_funcs))
if range_funcs:
    for f in range_funcs[:10]:
        print('  %s %s' % (f['addr'], f['name']))
    print('  ...')
    for f in range_funcs[-5:]:
        print('  %s %s' % (f['addr'], f['name']))

# Save filtered list
with open(os.path.join(OUT, 'target_funcs_full.json'), 'w') as f:
    json.dump(range_funcs, f, indent=2)
print('Saved target_funcs_full.json')
