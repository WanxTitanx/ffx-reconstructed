import ida_funcs, ida_name, ida_bytes, json

addrs = [0x80CD60, 0x80BEA0, 0x9da420, 0x9dae70, 0xC48EC8, 0xC48E78, 0xC492C8, 0xC64CA0, 0xC3A500]
out = {}
for a in addrs:
    f = ida_funcs.get_func(a)
    name = ida_name.get_name(a)
    if f:
        out[hex(a)] = {"func": hex(f.start_ea), "name": name, "size": hex(f.size())}
    else:
        # check if it's data
        flags = ida_bytes.get_flags(a)
        out[hex(a)] = {"func": None, "name": name, "flags": hex(flags), "is_data": ida_bytes.is_data(flags)}
print(json.dumps(out, indent=1))
