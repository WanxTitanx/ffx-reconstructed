#!/usr/bin/env python3
"""sysfp liveness probe — Jarvis-ORPHAN-SYSFP (2026-09-17).

Reproduces the evidence for the wave-13 orphan-tail verdict on
``jppc/event/obj/sy/sysfp/sysfp.ebp`` (eventId 8):

  * parses ``eventid.bin``  -> proves idx 8 == "sysfp"
  * parses ``evmapinfo.bin`` -> proves entry 8 == 0xFFFF (unbound / not map-bound)
  * dumps the sysfp chunk0 header (workers/actors) and the key op sequence
    (SYSTEM 1 + the four Debug-namespace CALLPOPAs it invokes)
  * prints the proven dispatch model + the boot-dispatch constants pulled
    from ``FFX_Field_FullSceneReset`` so the reader sees *why* id 8 is never
    dispatched by retail boot.

Pure stdlib; no IDA needed (the IDB-side facts are reproduced as literals
that were read out of the canonical IDB during the lane and are cited by VA).

Usage:
    python3 research_tools/Atel/sysfp_probe.py \
        [--event-root /mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event] \
        [--header /mnt/nvme-xpg/ffx_ps2/ffx/proj/event/header/eventid.bin] \
        [--sysfp work/_sysfp/sysfp_chunk0.bin]

It exits 0 and prints a verdict block; missing files are reported, not fatal.
"""
import argparse
import os
import struct
import sys

# ---- IDB-side facts (read out of C:\IDA_DB\ffxoficial.exe.i64 during the lane)
# Cited by VA; reproduced as literals so the probe runs offline.
DISPATCH = [
    ("FFX_Scene_PumpPendingTransition", "0x88D347",
     "per-frame pump; reads save_ram->scene_id, calls SceneReloadDispatch"),
    ("FFX_FieldEngine_SceneReloadDispatch", "0x88DFE0",
     "clears scene state, calls LoadObjResources(scene_id)"),
    ("FFX_Event_LoadObjResources", "0x872E90",
     "resolves path via Res_GetPathByGroupIndex(12, 18*scene_id)"),
    ("FFX_Res_GetPathByGroupIndex", "0x8AB780",
     "group-12 resource table -> event-object .ebp path"),
]
# Boot dispatch tail of FFX_Field_FullSceneReset @0x820B40 (decompiled):
#   if (ffx_debugmode)                 SceneReloadDispatch(0)
#   else if (argv=="_ECalm")           SceneReloadDispatch(g_atelFuncspaceCount_23_1=393)
#   else                               SceneReloadDispatch(23)
BOOT_DISPATCH = {
    "ffx_debugmode": 0,          # event00 debug scene
    "launch-arg _ECalm": 393,    # g_atelFuncspaceCount_23_1 (Eternal Calm scene1)
    "retail default": 23,        # first playable field
}
SPECIAL_SCENE_BASE = 393  # g_atelFuncspaceCount_23_1; ids 393..399 = eternalCalm


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def i32(b, o):
    return struct.unpack_from("<i", b, o)[0]


def cstr(b, o):
    e = b.find(b"\x00", o)
    if e < 0:
        e = len(b)
    return b[o:e].decode("ascii", "replace")


def parse_eventid(path):
    """eventid.bin: u32{N}{...} header then 8-byte {stroff,namelen} records.

    Returns list[(eventId, name)] and the index->name map for idx 8.
    """
    b = open(path, "rb").read()
    n = u32(b, 0)
    recs = []
    for i in range(n // 8):
        off, ln = u32(b, 8 * i), u32(b, 8 * i + 4)
        name = cstr(b, off) if off and off + ln <= len(b) else "?"
        recs.append((i, name))
    return recs


def dump_sysfp(path):
    """Minimal chunk0 dump: codeLen, scriptId, worker count + CALLPOPA census."""
    b = open(path, "rb").read()
    code_len = i32(b, 0)
    code_off = i32(b, 0x30)
    script_id = cstr(b, i32(b, 0x0C))
    wcount = u16(b, 0x34)
    acount = u16(b, 0x36)
    # linear sweep for the SYSTEM(0xF6)/CALLPOPA(0xD8) opcodes we care about
    ops = []
    pos = code_off
    end = min(len(b), code_off + code_len)
    while pos < end:
        op = b[pos]
        if op & 0x80:
            operand = u16(b, pos + 1) if pos + 3 <= end else None
            ops.append((pos - code_off, op, operand))
            pos += 3
        else:
            ops.append((pos - code_off, op, None))
            pos += 1
    interesting = [a for a in ops
                   if a[1] == 0xF6 or (a[1] == 0xD8 and a[2] and a[2] >= 0xC000)]
    return dict(size=len(b), code_len=code_len, code_off=code_off,
                script_id=script_id, workers=wcount, actors=acount,
                interesting=interesting)


def main(argv):
    ap = argparse.ArgumentParser(description="sysfp liveness probe (Jarvis-ORPHAN-SYSFP)")
    ap.add_argument("--event-root",
                    default="/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event")
    ap.add_argument("--header",
                    default="/mnt/nvme-xpg/ffx_ps2/ffx/proj/event/header/eventid.bin")
    ap.add_argument("--evmap",
                    default="/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj/evmapinfo.bin")
    ap.add_argument("--sysfp", default="work/_sysfp/sysfp_chunk0.bin")
    a = ap.parse_args(argv)

    ok = True
    print("=" * 70)
    print("sysfp liveness probe — Jarvis-ORPHAN-SYSFP 2026-09-17")
    print("=" * 70)

    # 1. eventid.bin -> idx 8 == 'sysfp'
    if os.path.exists(a.header):
        recs = parse_eventid(a.header)
        byid = dict(recs)
        print(f"[eventid.bin] {a.header}")
        print(f"  records={len(recs)}  idx8={byid.get(8)!r}  "
              f"neighbors: 1={byid.get(1)!r} 9={byid.get(9)!r} 23={byid.get(23)!r}")
        assert byid.get(8) == "sysfp", "idx 8 is not sysfp?!"
    else:
        ok = False
        print(f"[eventid.bin] MISSING {a.header}")

    # 2. evmapinfo.bin -> entry 8 unbound (contrast: entry 23 bound = retail boot)
    if os.path.exists(a.evmap):
        b = open(a.evmap, "rb").read()
        n = len(b) // 2
        live = sum(1 for i in range(n) if u16(b, 2 * i) != 0xFFFF)
        v8 = u16(b, 16)
        v23 = u16(b, 46)
        v1 = u16(b, 2)
        print(f"[evmapinfo.bin] {a.evmap}")
        print(f"  u16 entries={n}  live={live}")
        print(f"  entry[1] startmap0 = mapIdx {v1}  (BOUND, boot map)")
        print(f"  entry[23] test20   = mapIdx {v23}  (BOUND, retail boot scene)")
        print(f"  entry[8] sysfp     = 0x{v8:04X}  "
              f"-> {'UNBOUND (not map-bound)' if v8 == 0xFFFF else 'bound'}")
        assert v8 == 0xFFFF, "entry 8 unexpectedly bound"
    else:
        ok = False
        print(f"[evmapinfo.bin] MISSING {a.evmap}")

    # 3. sysfp chunk0 structure + the four Debug ops it calls
    if os.path.exists(a.sysfp):
        s = dump_sysfp(a.sysfp)
        print(f"[sysfp chunk0] {a.sysfp}")
        print(f"  size=0x{s['size']:x} codeLen=0x{s['code_len']:x} "
              f"scriptId={s['script_id']!r} workers={s['workers']} actors={s['actors']}")
        print("  SYSTEM/Debug CALLPOPA ops (code-rel off, op, operand):")
        for rel, op, operand in s["interesting"]:
            nm = "SYSTEM" if op == 0xF6 else "CALLPOPA"
            tag = {0xC003: "SetFieldMapGroupA", 0xC00B: "LoadBattleParticles",
                   0xC00C: "LoadFieldParticles", 0xC031: "SetMapIdAndLoadScene"}.get(
                       operand, "")
            print(f"    @{rel:#06x}  {nm:<9} {operand:#06x} {tag}")
    else:
        ok = False
        print(f"[sysfp chunk0] MISSING {a.sysfp} "
              f"(extract from the .ebp EV01 blob, chunk @+4)")

    # 4. dispatch model + boot constants (IDB-side, cited by VA)
    print("[dispatch model]  scene_id = save_ram+0 u16 ('now event jump id')")
    for nm, va, why in DISPATCH:
        print(f"  {nm:<36} {va}  {why}")
    print(f"[special scenes]  ids {SPECIAL_SCENE_BASE}..399 = eternalCalm "
          f"(g_atelFuncspaceCount_23_1=0x{SPECIAL_SCENE_BASE:x})")
    print("[boot dispatch]  FFX_Field_FullSceneReset @0x820B40 (decompiled tail):")
    for cond, sid in BOOT_DISPATCH.items():
        print(f"    if ({cond:<18}) -> SceneReloadDispatch({sid})")
    print("    => scene_id 8 (sysfp) is NEVER in the boot set {0,23,393}.")
    print("[only reachable path] FFX_Dbg_EventIdFileSelector @0x854EA0 reads")
    print("    eventid.bin (debug-only, loaded under ffx_debugmode @0x820A72),")
    print("    builds a scrollable list of all 400 eventIds+names incl 'sysfp'@8,")
    print("    dev picks -> dispatch.")

    print("-" * 70)
    print("VERDICT: sysfp = DEV-ONLY (debug-selectable dev scene; not retail-live;")
    print("         not unreachable-dead; not an auto-run system-worker).")
    print("=" * 70)
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
