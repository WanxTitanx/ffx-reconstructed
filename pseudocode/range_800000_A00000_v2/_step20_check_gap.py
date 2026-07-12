import urllib.request, json, os

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=120)
    return json.loads(resp.read().decode())

# Check the last 0x10000 bytes before 0xA00000
print("=== Checking last 64KB before 0xA00000 ===")
raw = call('search_text', {
    'database': DB,
    'pattern': 'proc near',
    'start': '0x9F0000',
    'end': '0xA00000',
    'limit': 500,
    'code_only': True,
    'include': 'disasm'
})
text = json.loads(raw['result']['content'][0]['text'])
hits = text.get('hits', [])
print('Results from 0x9F0000-0xA00000:')
for h in hits:
    print('  %s %s (kind=%s)' % (h.get('addr'), h.get('function'), [m.get('kind') for m in h.get('matches', [])]))

print()
print("=== Checking 0x9F0400-0xA00000 specifically ===")
raw = call('search_text', {
    'database': DB,
    'pattern': 'proc near',
    'start': '0x9F0400',
    'end': '0xA00000',
    'limit': 500,
    'code_only': True,
    'include': 'disasm'
})
text2 = json.loads(raw['result']['content'][0]['text'])
hits2 = text2.get('hits', [])
print('Results from 0x9F0400-0xA00000:')
for h in hits2:
    print('  %s %s' % (h.get('addr'), h.get('function')))

# Also check endp in the tail
print()
print("=== endp in tail ===")
raw = call('search_text', {
    'database': DB,
    'pattern': 'endp',
    'start': '0x9F0400',
    'end': '0xA00000',
    'limit': 500,
    'code_only': True,
    'include': 'disasm'
})
text3 = json.loads(raw['result']['content'][0]['text'])
hits3 = text3.get('hits', [])
print('endp results from 0x9F0400-0xA00000:')
for h in hits3:
    print('  %s %s' % (h.get('addr'), h.get('function')))
