import urllib.request, json

body = json.dumps({
    'jsonrpc': '2.0', 'id': 16,
    'method': 'tools/call',
    'params': {
        'name': 'list_funcs',
        'arguments': {
            'database': '1b332ea0',
            'queries': {'filter': '*', 'count': 0}
        }
    }
})
req = urllib.request.Request(
    'http://127.0.0.1:8745/mcp',
    data=body.encode(),
    headers={'Content-Type': 'application/json'}
)
resp = urllib.request.urlopen(req, timeout=300)
data = json.loads(resp.read().decode())
result = json.loads(data['result']['content'][0]['text'])

count = result.get('count', 0)
print(f'Total functions: {count}')

out = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2\all_funcs.json'
with open(out, 'w') as f:
    json.dump(result, f, indent=2)
print(f'Saved to {out}')

funcs = result.get('functions', result.get('items', []))
if funcs:
    for f in funcs[:10]:
        print(f'  {f}')
