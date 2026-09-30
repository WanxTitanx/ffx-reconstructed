import json, subprocess
batch = {'globals': [{'addr': '0x63d9c0', 'name': 'FFX_Magic_BindShaderResourcePackAll'}]}
r = subprocess.run(['python', 'scripts/ida_mcp_client.py', '--port', '13337', 'rename', json.dumps(batch)], capture_output=True, text=True, encoding='utf-8', errors='replace')
print('STDOUT:', r.stdout[-300:])

