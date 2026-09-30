import ida_hexrays, ida_funcs, traceback

print("init:", ida_hexrays.init_hexrays_plugin())

f = ida_funcs.get_func(0x8B1400)
print("func:", hex(f.start_ea) if f else None, "size:", hex(f.size()) if f else None)

try:
    cf = ida_hexrays.decompile(0x8B1400)
    if cf:
        print("OK len:", len(str(cf)))
        print(str(cf)[:500])
    else:
        print("DECOMPILE RETURNED None")
except Exception as e:
    print("EXC:", repr(e))
    traceback.print_exc()
