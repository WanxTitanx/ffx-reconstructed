import struct, sys

def analyze(path):
    data = open(path, 'rb').read()
    print(f"=== {path} ({len(data)} bytes) ===")
    magic, count, data_size, data_offset, offsets_offset, file_size = struct.unpack_from('<6I', data, 0)
    print(f"magic={magic} count={count} data_size=0x{data_size:X} data_offset=0x{data_offset:X} offsets_offset=0x{offsets_offset:X} file_size=0x{file_size:X}")
    print(f"padding[0x18:0x20]={data[0x18:0x20].hex()}")
    # entries in data region
    n = (offsets_offset - data_offset) // 12
    print(f"data region 0x{data_offset:X}-0x{offsets_offset:X} = {offsets_offset-data_offset} bytes -> {n} entries of 12B")
    for i in range(n):
        e = data[data_offset + i*12 : data_offset + i*12 + 12]
        vals = struct.unpack('<6H', e)
        print(f"  E{i}: x_min={vals[0]} x_max={vals[1]} y_min={vals[2]} y_max={vals[3]} type={vals[4]} sentinel=0x{vals[5]:04X}")
    # offsets table
    offs = []
    pos = offsets_offset
    while pos + 4 <= len(data):
        v = struct.unpack_from('<I', data, pos)[0]
        if v == 0 or v >= len(data):
            break
        offs.append(v)
        pos += 4
    print(f"offsets table @0x{offsets_offset:X}: {len(offs)} entries, first 16: {[hex(x) for x in offs[:16]]}")
    print(f"  last 8: {[hex(x) for x in offs[-8:]]}")
    print(f"  table ends at 0x{pos:X}")
    # check what's at data_size boundary
    print(f"  byte @ data_size 0x{data_size:X} = 0x{data[data_size]:02X}, @0x{data_size+4:X} = {data[data_size+4:data_size+8].hex()}")
    # dump first page
    if offs:
        p = offs[0]
        print(f"  page0 @0x{p:X}: {data[p:p+64].hex()}")

for f in ['dvdcopy.sps2', 'test_proj.sps2', 's_monitor.sps2']:
    analyze(f'/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/help/{f}')
    print()
