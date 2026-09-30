# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): restored from git history
# commit 53d82b2a (RuntimeTools/FFXMapViewerWeb/work/_claude_ida/_tmp/ffx_crc_verify.py).
# Save CRC16 verifier cited by docs/reverse/FFX_SAVE_CHECKSUM_CRACKED_2026-06-10.md;
# work/_claude_ida_tmp/ scratch tree was never committed at this path.
import os, struct, glob

SAVE_DIR = os.path.join(os.environ['USERPROFILE'],
    'Documents', 'SQUARE ENIX', 'FINAL FANTASY X&X-2 HD Remaster', 'FINAL FANTASY X')

def crc16_genibus(data):
    # poly 0x1021, init 0xFFFF, non-reflected, xorout 0xFFFF  (matches sub_8B1400)
    crc = 0xFFFF
    for b in data:
        crc = ((crc << 8) ^ TBL[(b ^ (crc >> 8)) & 0xFF]) & 0xFFFF
    return crc ^ 0xFFFF

# build the CCITT table exactly like sub_8B1400 (process n<<8 through 8 MSB-first steps, poly 0x1021)
TBL = []
for n in range(256):
    v = n << 8
    for _ in range(8):
        v = ((v << 1) ^ 0x1021) & 0xFFFF if (v & 0x8000) else (v << 1) & 0xFFFF
    TBL.append(v)
# quirk: sub_8B1400 table loop runs n=0..254 only (while n<0xFF) -> TBL[255] stays 0
TBL[255] = 0

REGION_OFF = 0x40
REGION_LEN = 25784          # 0x64B8
ZERO_DWORD_FILEOFF = 25844  # 0x64F4 (Buffer_4[6461])
CHECKSUM_FILEOFF = 0x1A     # high16 of hdr+0x18  (*(u16*)(buf+26))

print(f"region file[0x{REGION_OFF:X}:0x{REGION_OFF+REGION_LEN:X}] len={REGION_LEN} (0x{REGION_LEN:X})")
print(f"zero dword @ file 0x{ZERO_DWORD_FILEOFF:X}; stored checksum @ file 0x{CHECKSUM_FILEOFF:X}\n")

allok = True
for p in sorted(glob.glob(os.path.join(SAVE_DIR, 'ffx_00*'))):
    with open(p, 'rb') as f:
        d = bytearray(f.read())
    if len(d) != 0x6900:
        continue
    stored = struct.unpack_from('<H', d, CHECKSUM_FILEOFF)[0]
    dword64F4 = struct.unpack_from('<I', d, ZERO_DWORD_FILEOFF)[0]
    # replicate validator: zero the 0x64F4 dword, then CRC over region
    d[ZERO_DWORD_FILEOFF:ZERO_DWORD_FILEOFF+4] = b'\x00\x00\x00\x00'
    region = bytes(d[REGION_OFF:REGION_OFF+REGION_LEN])
    calc = crc16_genibus(region)
    ok = (calc == stored)
    redun_ok = (dword64F4 == stored)
    allok &= ok
    print(f"{os.path.basename(p):20} stored=0x{stored:04X}  calc=0x{calc:04X}  {'MATCH' if ok else 'MISMATCH'}"
          f"   redundant@0x64F4=0x{dword64F4:08X} {'ok' if redun_ok else 'DIFF'}")

print("\n", "=== ALL MATCH — CRC CRACKED & PROVEN ===" if allok else "=== MISMATCH — algorithm/region wrong ===")
