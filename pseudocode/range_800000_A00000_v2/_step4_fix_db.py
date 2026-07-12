import urllib.request, json, sys

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'

def call_raw(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=120)
    return resp.read().decode()

# Check the raw response for list_funcs
print("=== list_funcs raw ===")
raw = call_raw('list_funcs', {'database': DB, 'queries': {'filter': '*', 'count': 50000}})
parsed = json.loads(raw)
content_text = parsed['result']['content'][0]['text']
print(content_text[:2000])
print()

# Try func_query with name_regex='.' to match everything
print("=== func_query name_regex='.' ===")
try:
    d = json.loads(call_raw('func_query', {'database': DB, 'queries': {'name_regex': '.', 'count': 50000, 'sort_by': 'addr'}}))
    content = json.loads(d['result']['content'][0]['text'])
    print('Keys:', list(content.keys()))
    if 'result' in content:
        for i, page in enumerate(content['result']):
            items = page.get('data', [])
            print('Page %d: %d items' % (i, len(items)))
except Exception as e:
    print('Error:', e)

# Try decompile with a different format
print()
print("=== decompile raw response ===")
try:
    raw = call_raw('decompile', {'database': DB, 'addrs': '0x401000'})
    print(raw[:500])
except Exception as e:
    print('Error:', e)

# Try idb_save first to make sure DB is synced
print()
print("=== analyze_function test ===")
try:
    raw = call_raw('analyze_function', {'database': DB, 'addr': '0x401000'})
    print(raw[:500])
except Exception as e:
    print('Error:', e)

# Try calling the decompile tool via direct MCP - check if 'addrs' param should be an array
print()
print("=== decompile with array addrs ===")
try:
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':'decompile',
                                 'arguments':{'database': DB, 'addrs': ['0x401000']}}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=120)
    print(resp.read().decode()[:500])
except Exception as e:
    print('Error:', e)
