import urllib.request, json, os, re

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def call_raw(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=120)
    return resp.read().decode()

def call(m, args):
    return json.loads(call_raw(m, args))

# 1. Try search_text on the rendered listing - look for function names
# Search for "FFX_" or "sub_" in the 0x800000-0xA00000 range
# search_text takes pattern, start, end
print("=== search_text for 'sub_' in 0x800000-0xA00000 ===")
try:
    raw = call_raw('search_text', {
        'database': DB,
        'pattern': 'sub_',
        'start': '0x800000',
        'end': '0xA00000'
    })
    print(raw[:3000])
except Exception as e:
    print('Error:', e)

print()

# 2. Try entity_query - it mentions "Query IDB entities with typed filters"
print("=== entity_query schema ===")
for t in call('tools/list', {})['result']['tools']:
    if t['name'] == 'entity_query':
        print(json.dumps(t['inputSchema'], indent=2))
        break

print()

# 3. Try find tool - "Search strings/immediates/refs for targets"
print("=== find schema ===")
for t in call('tools/list', {})['result']['tools']:
    if t['name'] == 'find':
        print(json.dumps(t['inputSchema'], indent=2))
        break

print()

# 4. Check if there's some way to scan for function prologues
# Actually, let me check if the idalib has an interactive IDAPython channel
# Let me look for any tool that might let me execute arbitrary IDAPython
print("=== ALL tool names ===")
for t in call('tools/list', {})['result']['tools']:
    print('  ', t['name'])
