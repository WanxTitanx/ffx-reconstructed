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
    'queries': {'type': 'func', 'offset': 0, 'count': 2000, 'sort_by': 'addr'}
})

sc = raw['result'].get('structuredContent')
print('structuredContent type:', type(sc))
print('structuredContent:', json.dumps(sc, indent=2)[:2000])

# Also try parsing text directly
text = raw['result']['content'][0]['text']
print()
print('text type:', type(text))
parsed = json.loads(text)
print('parsed type:', type(parsed))
if isinstance(parsed, list) and len(parsed) > 0:
    item = parsed[0]
    print('item keys:', list(item.keys()))
    print('data len:', len(item.get('data', [])))
    print('next_offset:', item.get('next_offset'))
    print('total:', item.get('total'))
    if item.get('data'):
        print('first:', item['data'][0])
        print('last:', item['data'][-1])
