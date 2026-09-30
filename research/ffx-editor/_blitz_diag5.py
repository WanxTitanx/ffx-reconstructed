import ida_hexrays
print("before term:", ida_hexrays.init_hexrays_plugin())
r = ida_hexrays.term_hexrays_plugin()
print("term result:", r)
r2 = ida_hexrays.init_hexrays_plugin()
print("re-init:", r2)
