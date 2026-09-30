#!/usr/bin/env python3
# ── spu_sidecar_dump.py ─────────────────────────────────────────────
# Standalone parser for the FFX.exe (PC) SPU/FMOD *sidecar* files —
# research tool, NOT part of FFXProjectEditor. Lives in research_tools/Audio/.
#
# Lane: Jarvis-SPU-TAIL (wave-13 tail, 2026-09-18).
# Formats PROVEN against `FFX.exe` decompiles (IDB sync16):
#
#   *_common.txt   — `FFX_FmodSfx_LoadNonloopEvents`   @0x710450
#   *_loop.txt     — `FFX_SoundCmd_LoadLoopPMapFile`   @0x710D30
#   VoiceIDMapper  — `FFX_FmodVoice_LoadMapperData`    @0x70AC80 (-> voiceState+36)
#   VoiceFevMapper — same loader                        (-> voiceState+40)
#
# Despite the ".txt" extension all four are BINARY dword streams:
#
#   _common.txt : size>>3 fixed records {u32 seqId, u32 eventIndex}
#                 -> PMapTree seqId->eventIndex (the "nonloop" 1:1 seq map).
#
#   _loop.txt   : size>>2 dword stream, VARIABLE records
#                 {u32 seqId, u32 count, u32 eventIndex[count]}*
#                 -> PMapPair 28B nodes {+12 seqId, +16..24 vec{count,cap,ptr}}
#                 (the "loop" fan-out map: one seqId -> N loop-group events).
#
#   *Mapper.txt : "ML\0\0" magic + u32 count + count x {u32 id, u32 nameOff}
#                 + NUL-terminated name blob. nameOff is relative to the
#                 START OF FILE (id -> event/fev name string).
#
# Usage:
#   spu_sidecar_dump.py <file>            # auto-detect format, dump records
#   spu_sidecar_dump.py --selftest        # build synthetic blobs, round-trip
# ──────────────────────────────────────────────────────────────────
import struct
import sys


def parse_common_txt(data: bytes):
    """_common.txt: fixed 8B {seqId, eventIndex} records (size>>3)."""
    if len(data) % 8 != 0:
        raise ValueError(f"_common.txt size {len(data)} not a multiple of 8")
    return [struct.unpack_from("<II", data, i * 8) for i in range(len(data) // 8)]


def parse_loop_txt(data: bytes):
    """_loop.txt: dword stream {seqId, count, eventIdx[count]}* (size>>2)."""
    if len(data) % 4 != 0:
        raise ValueError(f"_loop.txt size {len(data)} not a multiple of 4")
    n = len(data) // 4
    d = struct.unpack(f"<{n}I", data)
    out, i = [], 0
    while i + 2 <= n:
        seq, cnt = d[i], d[i + 1]
        i += 2
        idxs = list(d[i:i + cnt]) if i + cnt <= n else list(d[i:])
        out.append((seq, idxs))
        i += cnt
    return out  # [(seqId, [eventIdx, ...]), ...]


def parse_mapper_txt(data: bytes):
    """Voice*Mapper.txt: 'ML\\0\\0' + u32 count + {id, nameOff}[count] + names."""
    if len(data) < 8 or data[:4] != b"ML\x00\x00":
        raise ValueError("not an 'ML\\0\\0' mapper blob")
    count = struct.unpack_from("<I", data, 4)[0]
    recs = []
    for i in range(count):
        rid, off = struct.unpack_from("<II", data, 8 + i * 8)
        end = data.find(b"\x00", off)
        name = data[off:end].decode("ascii", "replace") if 0 <= off < len(data) else "?"
        recs.append((rid, off, name))
    return recs


def detect(data: bytes) -> str:
    if data[:4] == b"ML\x00\x00":
        return "mapper"
    # heuristic: try loop-parse; if it consumes exactly, prefer loop
    try:
        recs = parse_loop_txt(data)
        consumed = sum(2 + len(v) for _, v in recs) * 4
        if consumed == len(data) and recs:
            return "loop"
    except Exception:
        pass
    return "common" if len(data) % 8 == 0 else "unknown"


def dump(path: str):
    data = open(path, "rb").read()
    kind = detect(data)
    print(f"# {path}  ({len(data)} B)  detected={kind}")
    if kind == "mapper":
        for rid, off, name in parse_mapper_txt(data):
            print(f"  id=0x{rid:08X} ({rid:>10})  off=0x{off:06X}  {name}")
    elif kind == "loop":
        for seq, idxs in parse_loop_txt(data):
            print(f"  seqId={seq:<6} count={len(idxs)}  eventIdx={idxs}")
    elif kind == "common":
        for seq, idx in parse_common_txt(data):
            print(f"  seqId={seq:<6} eventIndex={idx}")
    else:
        print("  (unrecognised — dump u32s)")
        for i in range(0, len(data) - 3, 4):
            print(f"  +{i:04X}: {struct.unpack_from('<I', data, i)[0]}")


def selftest():
    print("== selftest ==")
    common = struct.pack("<II", 7, 3) + struct.pack("<II", 9, 41)
    loop = struct.pack("<II", 5, 2) + struct.pack("<II", 11, 22) \
         + struct.pack("<III", 6, 3, 100) + struct.pack("<II", 101, 102)
    names = [b"ffx_jp_voice01\x00", b"evt_0007\x00"]
    blob = b"ML\x00\x00" + struct.pack("<I", len(names))
    off = 8 + len(names) * 8
    offs = []
    body = b""
    for nm in names:
        offs.append(off + len(body))
        body += nm
    for i, nm in enumerate(names):
        blob += struct.pack("<II", 0x1234 + i, offs[i])
    blob += body

    assert parse_common_txt(common) == [(7, 3), (9, 41)]
    lr = parse_loop_txt(loop)
    assert lr == [(5, [11, 22]), (6, [100, 101, 102])], lr
    mr = parse_mapper_txt(blob)
    assert mr[0][2] == "ffx_jp_voice01" and mr[1][2] == "evt_0007", mr
    for rid, o, nm in mr:
        print(f"  mapper  id=0x{rid:08X}  {nm}")
    for s, v in lr:
        print(f"  loop    seqId={s} eventIdx={v}")
    print("  common ", parse_common_txt(common))
    print("OK — all three formats round-trip")


if __name__ == "__main__":
    if len(sys.argv) >= 2 and sys.argv[1] == "--selftest":
        selftest()
    elif len(sys.argv) >= 2:
        for p in sys.argv[1:]:
            dump(p)
    else:
        print(__doc__)
        sys.exit(1)
