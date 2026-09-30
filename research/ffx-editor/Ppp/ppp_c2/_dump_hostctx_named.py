
import ida_bytes, struct, json, ida_funcs, ida_name
base = 0xC64CE8
b = ida_bytes.get_bytes(base, 512 * 8)
rows = []
for i in range(512):
    off = i * 8
    if off + 8 > len(b):
        break
    a = struct.unpack('<I', b[off:off+4])[0]
    bb = struct.unpack('<I', b[off+4:off+8])[0]
    if not a and not bb:
        continue
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
    rows.append({'slot': i, 'a': hex(a), 'a_name': nm(a), 'b': hex(bb), 'b_name': nm(bb)})
open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_named.json', 'w').write(json.dumps(rows))
print('OK', len(rows))
