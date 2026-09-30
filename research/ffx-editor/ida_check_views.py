import ida_kernwin, ida_hexrays, json

out = {}
# List all open widgets
try:
    widgets = []
    w = ida_kernwin.find_widget("Pseudocode-A")
    out["pseudo_A"] = "open" if w else "closed"
except Exception as e:
    out["pseudo_A"] = f"EXC {e}"

# Try to get current widget
try:
    cur = ida_kernwin.get_current_widget()
    out["current_widget"] = ida_kernwin.get_widget_title(cur) if cur else "None"
except Exception as e:
    out["current_widget"] = f"EXC {e}"

# Check decompiler state via internal
try:
    out["hexrays_plugin_loaded"] = ida_hexrays.init_hexrays_plugin()
except Exception as e:
    out["hexrays_plugin_loaded"] = f"EXC {e}"

print(json.dumps(out, indent=1))
