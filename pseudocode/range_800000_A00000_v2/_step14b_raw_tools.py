import urllib.request, json

MCP = 'http://127.0.0.1:8745/mcp'

body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/list','params':{}})
req = urllib.request.Request(MCP, data=body.encode(),
                             headers={'Content-Type':'application/json'})
resp = urllib.request.urlopen(req, timeout=60)
raw = resp.read().decode()
print(raw[:3000])
