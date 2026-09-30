import ida_bytes, idc

# Dump strings around 0xB5E800
for ea in range(0xB5E7C0, 0xB5EB40, 16):
    data = ida_bytes.get_bytes(ea, 16)
    if data:
        printable = ''.join(chr(b) if 32 <= b < 127 else '.' for b in data)
        print(f"0x{ea:X}: {data.hex(' ')}  {printable}")
