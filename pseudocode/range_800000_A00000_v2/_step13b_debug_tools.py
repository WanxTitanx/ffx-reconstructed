import urllib.request, json

MCP = 'http://127.0.0.1:8745/mcp'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=60)
    return json.loads(resp.read().decode())

raw = call('tools/list', {})
text = raw['result']['content'][0]['text']
data = json.loads(text)
print('Top keys:', list(data.keys()))

# Search for search_text, decompile
if 'tools' in data:
    for t in data['tools']:
        if t['name'] in ('search_text', 'decompile', 'find', 'find_bytes', 'get_bytes'):
            print('=== %s ===' % t['name'])
            print(json.dumps(t.get('inputSchema', {}), indent=2))
            print()
else:
    # Dump structure
    print(json.dumps(data, indent=2)[:2000])
