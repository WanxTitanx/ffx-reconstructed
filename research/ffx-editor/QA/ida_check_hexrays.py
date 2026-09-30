import json
out = {}
try:
    import ida_hexrays
    out["ida_hexrays_import"] = "ok"
    out["hexrays_available"] = ida_hexrays.init_hexrays_plugin()
except Exception as e:
    out["ida_hexrays_import"] = f"ERR: {e}"
try:
    import ida_idaapi
    out["ida_idaapi"] = "ok"
except Exception as e:
    out["ida_idaapi"] = f"ERR: {e}"
try:
    import ida_loader
    out["ida_loader"] = "ok"
except Exception as e:
    out["ida_loader"] = f"ERR: {e}"
print(json.dumps(out, indent=1))
