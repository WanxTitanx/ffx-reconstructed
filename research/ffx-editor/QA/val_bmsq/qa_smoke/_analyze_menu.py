import struct, sys, os

BASE = r"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"
FILES = {
    "clp":  os.path.join(BASE, "jppc", "menu", "menu.clp"),
    "dcp":  os.path.join(BASE, "jppc", "menu", "macrodic.dcp"),
    "fmt":  os.path.join(BASE, "jppc", "menu", "battle.fmt"),
    "sps2": os.path.join(BASE, "jppc", "help", "dvdcopy.sps2"),
}

def hexdump(data, off=0, length=None, width=16):
    if length is None:
        length = len(data) - off
    out = []
    for base in range(off, min(off+length, len(data)), width):
        chunk = data[base:base+width]
        hexs = " ".join(f"{b:02x}" for b in chunk)
        asc = "".join(chr(b) if 0x20 <= b < 0x7f else "." for b in chunk)
        out.append(f"{base:08x}  {hexs:<{width*3}}  {asc}")
    return "\n".join(out)

def u16le(b, o): return struct.unpack_from("<H", b, o)[0]
def u16be(b, o): return struct.unpack_from(">H", b, o)[0]
def u32le(b, o): return struct.unpack_from("<I", b, o)[0]
def u32be(b, o): return struct.unpack_from(">I", b, o)[0]

for name, path in FILES.items():
    print(f"\n{'='*80}\n### {name.upper()} — {os.path.basename(path)} ({os.path.getsize(path)} bytes)\n{'='*80}")
    data = open(path, "rb").read()
    print(f"First 128 bytes:")
    print(hexdump(data, 0, 128))
    print(f"\nLast 64 bytes:")
    print(hexdump(data, len(data)-64, 64))
