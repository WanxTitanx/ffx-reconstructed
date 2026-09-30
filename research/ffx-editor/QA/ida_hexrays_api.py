import ida_hexrays, json

names = [n for n in dir(ida_hexrays) if not n.startswith("__")]
interesting = [n for n in names if any(k in n.lower() for k in ["state", "reset", "clear", "busy", "init", "term", "exit", "decomp"])]
print(json.dumps(interesting, indent=1))
