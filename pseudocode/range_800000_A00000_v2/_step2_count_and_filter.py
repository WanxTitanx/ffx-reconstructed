import urllib.request, json, sys

MCP_URL = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT_DIR = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def mcp_call(method, params):
    body = json.dumps({'jsonrpc': '2.0', 'id': 99, 'method': 'tools/call',
                       'params': {'name': method, 'arguments': params}})
    req = urllib.request.Request(MCP_URL, data=body.encode(),
                                 headers={'Content-Type': 'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    data = json.loads(resp.read().decode())
    content = json.loads(data['result']['content'][0]['text'])
    return content

# Get all functions using list_funcs
print("Listing ALL functions...")
all_data = mcp_call('list_funcs', {
    'database': DB,
    'queries': {'filter': '*', 'count': 0}
})

# Parse the response
all_funcs = []
if 'result' in all_data:
    for page in all_data['result']:
        all_funcs.extend(page.get('data', []))
elif 'functions' in all_data:
    all_funcs = all_data['functions']
elif 'items' in all_data:
    all_funcs = all_data['items']

print(f"Total functions in DB: {len(all_funcs)}")

# Filter by address range 0x800000 - 0xA00000
target_funcs = []
for f in all_funcs:
    addr_str = f.get('addr', '0x0')
    # addr can be a string like "0x401000" or an int
    if isinstance(addr_str, str):
        addr = int(addr_str, 16)
    else:
        addr = addr_str
    name = f.get('name', 'unknown')
    size_str = f.get('size', '0x0')
    
    if 0x800000 <= addr < 0xA00000:
        target_funcs.append({
            'addr': addr,
            'name': name,
            'size': size_str,
            'addr_hex': hex(addr)
        })

target_funcs.sort(key=lambda x: x['addr'])
print(f"Functions in range 0x800000-0xA00000: {len(target_funcs)}")

# Save filtered list
with open(f'{OUT_DIR}\\target_funcs.json', 'w') as f:
    json.dump(target_funcs, f, indent=2)
print(f"Saved filtered list to target_funcs.json")

# Show first 20 and last 5
print("\nFirst 20:")
for f in target_funcs[:20]:
    print(f"  0x{f['addr']:08x} {f['name']} ({f['size']})")
print(f"\n... and last 5:")
for f in target_funcs[-5:]:
    print(f"  0x{f['addr']:08x} {f['name']} ({f['size']})")
