import urllib.request, json

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=120)
    return json.loads(json.loads(resp.read().decode())['result']['content'][0]['text'])

# 1. Server health
print("=== server_health ===")
h = call('server_health', {'database': DB})
print(json.dumps(h, indent=2)[:800])
print()

# 2. list_funcs with no filter (count=50000)
print("=== list_funcs (count=50000, no filter) ===")
d = call('list_funcs', {'database': DB, 'queries': {'count': 50000}})
print('Keys:', list(d.keys()))
if 'result' in d:
    for i, page in enumerate(d['result']):
        items = page.get('data', [])
        print('Page %d: %d items, next_offset=%s' % (i, len(items), page.get('next_offset')))
        if items:
            print('  first:', items[0])
            print('  last:', items[-1])
print()

# 3. list_funcs with filter='*' count=50000
print("=== list_funcs (filter='*', count=50000) ===")
d = call('list_funcs', {'database': DB, 'queries': {'filter': '*', 'count': 50000}})
if 'result' in d:
    for i, page in enumerate(d['result']):
        items = page.get('data', [])
        print('Page %d: %d items' % (i, len(items)))
print()

# 4. Try decompile on first function
print("=== decompile test ===")
d = call('decompile', {'database': DB, 'addrs': '0x401000'})
print('Keys:', list(d.keys()))
if 'functions' in d:
    for k, v in d['functions'].items():
        print('  %s: %d chars' % (k, len(v['pseudocode'])))
        print('  Preview:', v['pseudocode'][:200])
