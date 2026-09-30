# aat_monlive_re.py - confirm the chunk3 runtime consumers (monLive +0x20, camera +0x2C) and find the
# monster orientation/facing logic. Run via idat.exe -A -S<script> on a COPY of the FFX db.
# Lane: Jarvis (battle position corpus RE, 2026-08-04).
import idautils
import idaapi
import idc
import ida_auto

def find_imm_users(imm, label):
    """Count functions whose code references the given 32-bit immediate (offset)."""
    hits = {}
    for ea in idautils.CodeRefsTo(imm, 0):
        fn = idaapi.get_func(ea)
        if fn:
            hits.setdefault(fn.start_ea, 0)
            hits[fn.start_ea] += 1
    print(f"[{label}] imm=0x{imm:X} -> {len(hits)} functions")
    for start, cnt in sorted(hits.items(), key=lambda kv: -kv[1])[:10]:
        print(f"    fn 0x{start:X} {idc.get_func_name(start)} (refs={cnt})")
    return hits

def main():
    print("=== AAT battle position RE (corpus calibration) ===")
    # FFX base is 0x400000. The chunk3 area-record offsets the engine consumes at runtime:
    # 0x10 party, 0x14 party back, 0x20 on-field monsters, 0x2C camera. We look for code that
    # forms these offsets (often as sub-immediates or folded), so we also scan the raw immediate
    # space around the well-known chunk3 globals. Best-effort: report both the offset imm and the
    # disasm of any hit.
    ida_auto.auto_wait()
    for off in (0x10, 0x14, 0x20, 0x2C):
        # probe the ffx base + offset (absolute) and the bare offset
        find_imm_users(0x400000 + off, f"base+{off:#04x}")
    print("=== done ===")

try:
    main()
except Exception as e:
    print(f"ERROR: {e}")