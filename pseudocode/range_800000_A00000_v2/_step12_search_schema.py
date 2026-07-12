import urllib.request, json, os

MCP = 'http://127.0.0.1:8745/mcp'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=60)
    return json.loads(resp.read().decode())

# Get structuredContent from tools/list
raw = call('tools/list', {})
tools = raw['result'].get('structuredContent', raw['result'])
if isinstance(tools, dict) and 'tools' in tools:
    tools = tools['tools']

for t in tools:
    name = t['name']
    if name in ('search_text', 'find', 'decompile', 'analyze_function'):
        print('=== %s ===' % name)
        print(json.dumps(t.get('inputSchema', {}), indent=2))
        print()
