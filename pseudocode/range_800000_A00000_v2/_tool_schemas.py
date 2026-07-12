import urllib.request, json

body = json.dumps({'jsonrpc':'2.0','id':20,'method':'tools/list','params':{}})
req = urllib.request.Request('http://127.0.0.1:8745/mcp', data=body.encode(),
                             headers={'Content-Type':'application/json'})
resp = urllib.request.urlopen(req, timeout=30)
tools = json.loads(resp.read().decode())['result']['tools']

for t in tools:
    if t['name'] in ('func_query', 'export_funcs', 'lookup_funcs', 'survey_binary'):
        print('=== %s ===' % t['name'])
        print(json.dumps(t['inputSchema'], indent=2))
        print()
