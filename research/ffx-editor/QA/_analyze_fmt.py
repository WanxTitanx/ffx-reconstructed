import struct, os

def analyze(path):
    data = open(path, 'rb').read()
    print(f"=== {path} ({len(data)} bytes) ===")
    # try 256-byte blocks
    block = 256
    nblocks = len(data) // block
    print(f"blocks of {block}B: {nblocks}")
    # dump first 8 glyph blocks: shape strings + pixel data summary
    for b in range(min(8, nblocks)):
        blk = data[b*block:(b+1)*block]
        # extract ASCII runs
        ascii_runs = []
        i = 0
        while i < 0x40:
            if 0x20 <= blk[i] <= 0x7e:
                j = i
                while j < 0x40 and 0x20 <= blk[j] <= 0x7e:
                    j += 1
                ascii_runs.append((i, blk[i:j].decode('ascii')))
                i = j
            else:
                i += 1
        # pixel data non-zero counts
        nz_40 = sum(1 for x in blk[0x40:0xC0] if x != 0)
        nz_c0 = sum(1 for x in blk[0xC0:0x100] if x != 0)
        print(f"  glyph {b}: ascii_runs={ascii_runs} nz[0x40:0xC0]={nz_40} nz[0xC0:0x100]={nz_c0}")
        print(f"    @0x40: {blk[0x40:0x50].hex()}")
        print(f"    @0xC0: {blk[0xC0:0xE0].hex()}")

for f in ['battle.fmt', 'icon.fmt', 'subfont.fmt', 'xfont1208.fmt', 'face_a.fmt']:
    analyze(f'D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/menu/{f}')
    print()
