import urllib.request, json

MCP = 'http://127.0.0.1:8745/mcp'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=60)
    return json.loads(resp.read().decode())

# Get tool schemas from text field
raw = call('tools/list', {})
text = raw['result']['content'][0]['text']
tools = json.loads(text)
print('tools type:', type(tools))
if isinstance(tools, dict) and 'tools' in tools:
    for t in tools['tools']:
        name = t['name']
        if name in ('search_text', 'decompile', 'analyze_function', 'find', 'find_bytes', 'get_bytes'):
            print('=== %s ===' % name)
            print(json.dumps(t.get('inputSchema', {}), indent=2))
            print()
elif isinstance(tools, list):
    for item in tools:
        print(type(item), str(item)[:200])
