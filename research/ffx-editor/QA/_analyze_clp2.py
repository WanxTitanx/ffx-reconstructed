import struct

data = open('D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/menu.clp', 'rb').read()
print(f"size={len(data)}")
# compare 4KB blocks
for i in range(4):
    blk = data[i*0x1000:(i+1)*0x1000]
    print(f"block {i} @0x{i*0x1000:X}: first 64B: {blk[:64].hex()}")
    # find non-zero regions
    nz = [j for j in range(len(blk)) if blk[j] != 0]
    if nz:
        print(f"  non-zero range: 0x{nz[0]:X}-0x{nz[-1]:X} ({len(nz)} bytes)")
# dump the region 0x180-0x1000 of block 0
print("\n=== region 0x180-0x200 ===")
print(data[0x180:0x200].hex())
print("\n=== region 0x200-0x300 ===")
print(data[0x200:0x300].hex())
print("\n=== region 0x300-0x400 ===")
print(data[0x300:0x400].hex())
