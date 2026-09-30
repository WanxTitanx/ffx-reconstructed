import struct

def analyze(path):
    data = open(path, 'rb').read()
    print(f"=== {path} ({len(data)} bytes) ===")
    # header: 8 u32 BE offsets
    offs = struct.unpack_from('>8I', data, 0)
    print(f"header 8 u32 BE: {[hex(x) for x in offs]}")
    # find all u32 BE tables in the file
    # scan for candidate tables: sequences of increasing u32 BE values < file size
    for start in range(0, len(data)-4, 4):
        vals = []
        pos = start
        while pos + 4 <= len(data):
            v = struct.unpack_from('>I', data, pos)[0]
            if v > len(data) or v == 0xFFFFFFFF:
                break
            vals.append(v)
            pos += 4
        if len(vals) >= 3 and all(vals[i] < vals[i+1] for i in range(len(vals)-1)):
            print(f"  candidate table @0x{start:X}: {len(vals)} entries: {[hex(x) for x in vals[:10]]}{'...' if len(vals)>10 else ''}")

analyze('/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp')
