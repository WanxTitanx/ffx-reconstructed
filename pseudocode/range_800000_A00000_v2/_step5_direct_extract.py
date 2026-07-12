import urllib.request, json, os, time

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

# 1. Try to query a function at a known address in the 0x800000+ range
# From README: A tel interpreter at 0x864180, ForcePerformCommand at 0x705A
# These are RVA. With imagebase 0x400000, the VA would be 0x40705A for 0x705A
# But 0x800000 is a VA, so it's actual VA.

# Let's try a few known addresses from the README
test_addrs = [
    '0x864180',  # ATEL interpreter
    '0x869D00',  # FFX_Atel_FetchOpcode
    '0x869600',  # Try nearby
    '0x871000',  # Higher range
    '0x800000',  # Start of range
    '0x900000',  # Middle of range  
    '0x9F0000',  # End of range
    '0x7B2DD0',  # Battle pool actor from README
    '0x794340',  # Battle QueryActorBitmask
    '0x7170F0',  # PPP Processor
]

print("=== Testing known addresses via analyze_function ===")
for addr in test_addrs:
    try:
        raw = call('analyze_function', {'database': DB, 'addr': addr})
        content = json.loads(raw['result']['content'][0]['text'])
        if content.get('error') is None and content.get('name'):
            print('OK  0x%s %s (size=%s)' % (content['addr'], content['name'], content.get('size', '?')))
        else:
            print('ERR 0x%s: %s' % (addr, content.get('error', 'no function')))
    except Exception as e:
        print('ERR  %s: %s' % (addr, e))

# 2. Try decompile directly
print()
print("=== Testing decompile ===")
for addr in test_addrs[:3]:
    try:
        raw = call('decompile', {'database': DB, 'addr': addr})
        print('decompile response keys:', list(raw.keys()))
        content_text = raw['result']['content'][0]['text']
        print(content_text[:300])
        print()
    except Exception as e:
        print('ERR  %s: %s' % (addr, e))

# 3. Get decompile tool schema
print("=== decompile schema ===")
raw = call('tools/list', {})
for t in raw['result']['tools']:
    if t['name'] == 'decompile':
        print(json.dumps(t['inputSchema'], indent=2))
