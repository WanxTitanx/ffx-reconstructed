import urllib.request, json, os

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

raw = call('entity_query', {
    'database': DB,
    'queries': {'type': 'func', 'offset': 0, 'count': 3, 'sort_by': 'addr'}
})

print('Top keys:', list(raw.keys()))
print('result type:', type(raw['result']))
print('result keys:', list(raw['result'].keys()))
content = raw['result']['content']
print('content type:', type(content))
print('content len:', len(content))
print('content[0] type:', type(content[0]))
print('content[0] keys:', list(content[0].keys()))
text = content[0]['text']
print('text type:', type(text))
print('text[:500]:', text[:500])

# Parse text as JSON
parsed = json.loads(text)
print()
print('parsed type:', type(parsed))
if isinstance(parsed, list):
    print('list len:', len(parsed))
    for i, item in enumerate(parsed):
        print('item %d type:' % i, type(item))
        if isinstance(item, dict):
            print('  keys:', list(item.keys()))
            print('  data:', json.dumps(item, indent=2)[:500])
            break
elif isinstance(parsed, dict):
    print('keys:', list(parsed.keys()))
