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
    d = json.loads(resp.read().decode())
    return json.loads(d['result']['content'][0]['text'])

def call_raw(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

# Check tools list properly
print("=== tools/list ===")
lt = call_raw('tools/list', {})
data = lt
if 'result' in data:
    tools = data['result']
    if isinstance(tools, dict) and 'tools' in tools:
        for t in tools['tools']:
            print('  ', t['name'])
elif isinstance(data, dict) and 'tools' in data:
    for t in data['tools']:
        print('  ', t['name'])

print()

# Let's try the find tool - search for function markers
# First check if find works
print("=== find 'sub_' in text ===")
try:
    d = call('find', {'database': DB, 'targets': 'sub_', 'offset': 0, 'count': 10})
    print(json.dumps(d)[:2000])
except Exception as e:
    print('Error:', e)

# Let me try entity_query
print()
print("=== entity_query basic ===")
try:
    d = call('entity_query', {'database': DB, 'queries': {'type': 'func', 'offset': 0, 'count': 5}})
    # Check structure
    print('type:', type(d))
    s = json.dumps(d)
    print(s[:2000])
except Exception as e:
    print('Error:', e)
