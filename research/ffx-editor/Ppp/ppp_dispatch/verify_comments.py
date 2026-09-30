import json, subprocess
items = json.load(open('work/_ppp_dispatch/comment_manifest.json'))
CH = 200
bad = []
for i in range(0, len(items), CH):
    chunk = {'items': items[i:i+CH]}
    p = subprocess.run(['python3', 'research_tools/Ida/ida_mcp.py', 'append_comments',
                        json.dumps(chunk)], capture_output=True, text=True, timeout=300)
    try:
        res = json.loads(p.stdout)
        for r in res:
            if not r.get('appended') and not r.get('skipped'):
                bad.append(r)
            if r.get('skipped'):
                pass  # dedupe skip = already present, fine
    except Exception as e:
        bad.append({'chunk': i, 'err': str(e), 'out': p.stdout[:300]})
print('failures:', len(bad), bad[:10])
