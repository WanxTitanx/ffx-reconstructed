import ida_hexrays
names = [n for n in dir(ida_hexrays) if n.startswith("MERR")]
for n in sorted(names):
    print(n, getattr(ida_hexrays, n))
