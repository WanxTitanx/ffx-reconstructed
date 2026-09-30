import sys, json
sys.path.insert(0, "work/_mislabel_audit")
from apply_renames import call, init, post
init()
d = json.loads(post({"jsonrpc":"2.0","id":2,"method":"tools/list"}))
tools = d.get("result",{}).get("tools",[])
for t in tools:
    if t["name"] == "rename":
        print(json.dumps(t.get("inputSchema",{}), indent=1))
