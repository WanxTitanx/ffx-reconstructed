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
    return json.loads(resp.read().decode())

# search_text for "proc near" in the range 0x800000-0xA00000
# "proc near" is the marker IDA puts at function starts
# search_text takes pattern, start, end, offset, limit

print("=== search_text for 'proc near' in range ===")
raw = call('search_text', {
    'database': DB,
    'pattern': 'proc near',
    'start': '0x800000',
    'end': '0xA00000',
    'offset': 0,
    'limit': 100
})

content = raw['result']['content'][0]['text']
print('Content type:', type(content))
print('Content preview:', content[:2000])

text = json.loads(content)
print()
print('Parsed keys:', list(text.keys()) if isinstance(text, dict) else type(text))
if isinstance(text, dict):
    print('n:', text.get('n'))
    print('more:', text.get('more'))
    hits = text.get('hits', [])
    print('hits:', len(hits))
    for h in hits[:10]:
        print('  %s %s' % (h.get('addr'), h.get('function', '')))
    if len(hits) > 10:
        print('  ...')

# Check structured content
sc = raw['result'].get('structuredContent')
print()
print('SC:', json.dumps(sc, indent=2)[:1000] if sc else 'none')
