
import ida_bytes, struct, json
# HostContextTable: 512 slots em 0xC64CE8 (estrutura por slot a confirmar — dump raw)
base = 0xC64CE8
b = ida_bytes.get_bytes(base, 512 * 8)
rows = []
for i in range(512):
    off = i * 8
    if off + 8 > len(b):
        break
    u32a = struct.unpack('<I', b[off:off+4])[0]
    u32b = struct.unpack('<I', b[off+4:off+8])[0]
    if u32a or u32b:
        rows.append({'slot': i, 'a': hex(u32a), 'b': hex(u32b)})
open(r'C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/host_context_dump.json', 'w').write(json.dumps(rows))
print('OK slots nao-vazios:', len(rows))
