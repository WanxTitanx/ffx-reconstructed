import ida_kernwin, ida_hexrays, json

out = {}
w = ida_kernwin.find_widget("Pseudocode-A")
out["widget"] = "found" if w else "none"
if w:
    out["title"] = ida_kernwin.get_widget_title(w)
    try:
        vu = ida_hexrays.get_widget_vdui(w)
        if vu:
            out["vdui"] = "ok"
            out["vu_func"] = hex(vu.cfunc.entry_ea) if vu.cfunc else "no cfunc"
            out["vu_cur_ea"] = hex(vu.ctree.cur_ea) if vu.ctree else "no ctree"
        else:
            out["vdui"] = "none"
    except Exception as e:
        out["vdui"] = f"EXC {type(e).__name__}: {e}"
    # Try to close it
    try:
        ida_kernwin.close_widget(w, 0)
        out["close"] = "called"
    except Exception as e:
        out["close"] = f"EXC {type(e).__name__}: {e}"
print(json.dumps(out, indent=1))
