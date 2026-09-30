import json, subprocess
items = json.load(open('work/_ppp_aux/comment_manifest_aux.json'))
CH = 150
for i in range(0, len(items), CH):
    chunk = {'items': items[i:i+CH]}
    p = subprocess.run(['python3', 'research_tools/Ida/ida_mcp.py', 'append_comments',
                        json.dumps(chunk)], capture_output=True, text=True, timeout=300)
    line = p.stdout.strip().splitlines()
    print('chunk', i//CH, '->', (line[0][:200] if line else p.stderr[:200]))
