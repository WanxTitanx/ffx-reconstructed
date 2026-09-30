
import ida_bytes, struct, json, ida_name, ida_funcs
def nm(addr):
    if not addr:
        return ''
    name = ida_name.get_name(addr) or ''
    if name:
        return name
    f = ida_funcs.get_func(addr)
    if f:
        return ida_name.get_name(f.start_ea) or hex(f.start_ea)
    return hex(addr)

out = {}
for tname, tbl, count in [("main", 0xC3A500, 418), ("alt", 0xC3E798, 246), ("keyhole", 0xC86080, 32)]:
    rows = []
    for i in range(count):
        entry = tbl + i * 0x28
        b = ida_bytes.get_bytes(entry, 0x28)
        if not b or len(b) < 0x28:
            rows.append(None)
            continue
        p8 = struct.unpack('<I', b[8:12])[0]
        pC = struct.unpack('<I', b[12:16])[0]
        rows.append({'i': i, 'p8': hex(p8), 'p8n': nm(p8), 'pC': hex(pC), 'pCn': nm(pC)})
    out[tname] = rows
open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/dispatch_named_all.json', 'w').write(json.dumps(out))
print('OK')
