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

# The range is 0x800000-0xA00000 = 2MB. Split into 64KB chunks (32 chunks)
# Each chunk likely has <500 functions, so limit=500 should work
CHUNK_SIZE = 0x10000  # 64KB
range_start = 0x800000
range_end = 0xA00000

all_funcs = {}
chunk = 0

for start_addr in range(range_start, range_end, CHUNK_SIZE):
    end_addr = min(start_addr + CHUNK_SIZE, range_end)
    start_hex = '0x%X' % start_addr
    end_hex = '0x%X' % end_addr
    
    # Use 'endp' as end markers - unique per function
    try:
        raw = call('search_text', {
            'database': DB,
            'pattern': 'endp',
            'start': start_hex,
            'end': end_hex,
            'limit': 500,
            'code_only': True
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            addr = h.get('addr', '')
            func_name = h.get('function', '')
            if func_name:
                all_funcs[addr] = func_name
        
        chunk += 1
        if chunk % 10 == 0:
            print('Chunk %d: %s-%s, found %d unique so far' % (
                chunk, start_hex, end_hex, len(all_funcs)))
            
    except Exception as e:
        print('ERROR at chunk %s-%s: %s' % (start_hex, end_hex, e))
        continue

print()
print('Total chunks scanned: %d' % chunk)
print('Total unique functions: %d' % len(all_funcs))

func_list = sorted(all_funcs.items(), key=lambda x: int(x[0], 16) if x[0].startswith('0x') else 0)

print()
print('First 20:')
for addr, name in func_list[:20]:
    print('  %s %s' % (addr, name))
print()
print('Last 5:')
for addr, name in func_list[-5:]:
    print('  %s %s' % (addr, name))

with open(os.path.join(OUT, 'target_funcs_endp.json'), 'w') as f:
    json.dump(func_list, f, indent=2)
print('Saved %d functions to target_funcs_endp.json' % len(func_list))
