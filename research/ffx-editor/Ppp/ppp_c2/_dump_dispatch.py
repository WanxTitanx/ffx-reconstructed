
import ida_bytes, struct, json
tbl = 0xC3A500
count = 418
stride = 0x28
out = []
for i in range(count):
    entry = tbl + i * stride
    b = ida_bytes.get_bytes(entry, stride)
    if not b or len(b) < stride:
        out.append(None)
        continue
    p0 = struct.unpack('<I', b[0:4])[0]
    p8 = struct.unpack('<I', b[8:12])[0]
    pC = struct.unpack('<I', b[12:16])[0]
    p1C = struct.unpack('<I', b[28:32])[0]
    out.append({'i': i, 'p0': hex(p0), 'p8': hex(p8), 'pC': hex(pC), 'p1C': hex(p1C)})
open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/dispatch_table_dump.json', 'w').write(json.dumps(out))
print('OK', len(out))
