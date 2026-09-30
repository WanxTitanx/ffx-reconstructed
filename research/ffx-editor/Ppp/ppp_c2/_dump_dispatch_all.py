
import ida_bytes, struct, json
tables = [("main", 0xC3A500, 418, 0x28), ("alt", 0xC3E798, 246, 0x28), ("keyhole", 0xC86080, 32, 0x28)]
out = {}
for name, tbl, count, stride in tables:
    rows = []
    for i in range(count):
        entry = tbl + i * stride
        b = ida_bytes.get_bytes(entry, stride)
        if not b or len(b) < stride:
            rows.append(None)
            continue
        p0 = struct.unpack('<I', b[0:4])[0]
        p8 = struct.unpack('<I', b[8:12])[0]
        pC = struct.unpack('<I', b[12:16])[0]
        p1C = struct.unpack('<I', b[28:32])[0]
        rows.append({'i': i, 'p0': hex(p0), 'p8': hex(p8), 'pC': hex(pC), 'p1C': hex(p1C)})
    out[name] = rows
open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/dispatch_tables_all.json', 'w').write(json.dumps(out))
print('OK', {k: len(v) for k, v in out.items()})
