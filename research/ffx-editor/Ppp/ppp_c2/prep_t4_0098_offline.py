#!/usr/bin/env python3
"""
ONDA 3 GOAL 8h (2026-08-02, Jarvis-MAGIC) — Preparacao T4 do clone 0098 OFFLINE.
Gera as DLLs mutadas em work/_t4_prep/ (nunca toca a Steam Library):
  1. magic_0098_mut_sclmove.dll  — SclMove record 0x1C0F0, campo X (+0x10) x2.0
  2. magic_0098_mut_angaccele.dll — AngAccele record 0x19A30, campo Y (+0x14) x2.0 (int32 graus)

Para cada uma: SHA antes/depois, diff confinado a 4 bytes (janela 16B provada),
RT0 do resto do arquivo (hash dos bytes fora do diff == identico), backup .bak,
e evidencia JSON (padrao work/layer_c/t1b/evidence/).
"""
import hashlib, json, os, shutil, struct, sys
from pathlib import Path

sys.stdout.reconfigure(encoding="utf-8", errors="replace")

SRC = Path(r"F:\ffx-reconstructed\extras\magicFiles\FFX\magic_0098.dll")
OUT = Path(r"work\_t4_prep")
EVID = Path(r"work\_t4_prep\evidence")
OUT.mkdir(parents=True, exist_ok=True)
EVID.mkdir(parents=True, exist_ok=True)

assert SRC.exists(), f"corpus ausente: {SRC}"
data = bytearray(SRC.read_bytes())

# --- PE: achar o raw pointer do .data ---
pe = struct.unpack_from("<I", data, 0x3C)[0]
coff = pe + 4
num = struct.unpack_from("<H", data, coff + 2)[0]
opt = struct.unpack_from("<H", data, coff + 16)[0]
st = coff + 20 + opt
dp = None
for i in range(num):
    so = st + i * 40
    nm = bytes(data[so:so + 8]).rstrip(b"\x00")
    if nm in (b".data", b"D\x00A\x00T\x00A\x00"):
        dp = struct.unpack_from("<I", data, so + 20)[0]
assert dp is not None, ".data nao encontrado"

def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()

def mutate(src: bytearray, record_rel: int, field_off: int, scale: float, is_int: bool):
    """Copia + muta campo (offset relativo ao record, dentro da janela +0x10..+0x1F)."""
    out = bytearray(src)
    abs_off = dp + record_rel + field_off
    if is_int:
        old = struct.unpack_from("<i", out, abs_off)[0]
        new = int(old * scale)
        struct.pack_into("<i", out, abs_off, new)
    else:
        old = struct.unpack_from("<f", out, abs_off)[0]
        new = old * scale
        struct.pack_into("<f", out, abs_off, new)
    return out, old, new

def build(name, record_rel, field_off, scale, is_int, desc):
    orig = bytes(data)
    mut, old, new = mutate(data, record_rel, field_off, scale, is_int)

    # Diff confinado: 1..4 bytes, todos dentro da janela U1 provada (record+0x10..+0x1F).
    # f32 x2.0 muda so o byte do expoente (1 byte); int32 x2 muda ate 4 bytes.
    diffs = [i for i in range(len(orig)) if orig[i] != mut[i]]
    window_start = dp + record_rel + 0x10
    window_end = dp + record_rel + 0x20
    assert 1 <= len(diffs) <= 4, f"esperado 1..4 bytes de diff, veio {len(diffs)}: {[hex(d) for d in diffs]}"
    assert all(window_start <= d < window_end for d in diffs), \
        f"diff fora da janela U1: {[hex(d) for d in diffs]}"

    # RT0 do resto: hash dos bytes fora do diff identico.
    mask = bytearray(1 for _ in orig)
    for d in diffs:
        mask[d] = 0
    orig_rest = bytes(b for b, m in zip(orig, mask) if m)
    mut_rest = bytes(b for b, m in zip(mut, mask) if m)
    assert sha(orig_rest) == sha(mut_rest), "RT0 do resto do arquivo FALHOU"

    dest = OUT / name
    dest.write_bytes(mut)
    (OUT / (name + ".bak")).write_bytes(orig)

    ev = {
        "dll": "magic_0098.dll",
        "effect": "Death",
        "mutation": desc,
        "record_rel": hex(record_rel),
        "field_off": hex(field_off),
        "field_abs": hex(dp + record_rel + field_off),
        "type": "int32" if is_int else "f32",
        "scale": scale,
        "old": old,
        "new": new,
        "sha_before": sha(orig),
        "sha_after": sha(mut),
        "diff_offsets": [hex(d) for d in diffs],
        "diff_confined_to_u1_window": True,
        "rt0_rest_ok": True,
        "generated": "2026-08-02",
        "lane": "Jarvis-MAGIC",
        "status": "preparado_offline_aguardando_ambiente_limpo",
    }
    ev_path = EVID / (name.replace(".dll", "") + ".json")
    ev_path.write_text(json.dumps(ev, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"OK {name}: {desc}")
    print(f"   record {hex(record_rel)} campo {hex(field_off)}: {old} -> {new} ({scale}x)")
    print(f"   SHA {ev['sha_before'][:12]} -> {ev['sha_after'][:12]}")
    print(f"   diff {len(diffs)} bytes @ {[hex(d) for d in diffs]} (janela U1 ok, RT0 resto ok)")
    print(f"   evidencia: {ev_path}")
    print()
    return ev

# Candidata 1 (runbook): SclMove 0x1C0F0, X (+0x10) x2.0 — double-layer, escala.
ev1 = build("magic_0098_mut_sclmove.dll", 0x1C0F0, 0x10, 2.0, False,
            "SclMove record 0x1C0F0 campo X(+0x10) x2.0 (escala X cresce ~2x no frame 59)")

# Candidata 2 (runbook): AngAccele 0x19A30, Y (+0x14) x2.0 — int32 graus, mira.
ev2 = build("magic_0098_mut_angaccele.dll", 0x19A30, 0x14, 2.0, True,
            "AngAccele record 0x19A30 campo Y(+0x14) x2.0 (int32 graus: -5 -> -10, mira gira 2x mais rapido)")

summary = {"generated": "2026-08-02", "lane": "Jarvis-MAGIC",
           "source": str(SRC), "source_sha": sha(bytes(data)),
           "mutations": [ev1, ev2]}
(OUT / "T4_PREP_SUMMARY.json").write_text(json.dumps(summary, ensure_ascii=False, indent=1), encoding="utf-8")
print("SUMMARY: work/_t4_prep/T4_PREP_SUMMARY.json")
