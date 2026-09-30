#!/usr/bin/env python3
# monster3_tail_audit.py — FFX monster3.bin tail-row audit (research-only, read-only on corpus)
#
# PURPOSE : answers "what ARE rows 347-365 of monster3.bin?" (the 19 tail rows never
#           referenced by any formation chunk2 — see FFX_MONSTER_FORMATION_CENSUS_2026-09-15).
#           For every row (IDs 181-365) it decodes the 128B MonsterStatSheetStruct
#           (5x TextScriptInfo + StatSheet + 4B pad — layout from
#           FFXProjectEditor/FfxLib/Monster/Monster_Structs.cs + Monster_StatSheet.cs),
#           resolves the 5 string offsets into the localized text pool, and classifies
#           each row: REAL (referenced-range stats) vs TEMPLATE (the 347-365 clone pattern)
#           vs ZERO-FILL. Also decodes the pool tail to prove the placeholder strings.
#
# RECORD  : 128B @ file +0x14 + (id-181)*128
#             +0x00..0x13  5 x TextScriptInfo { u16 offset (rel. to pool base), u16 scriptId }
#                          order: name, sensor, unused1(みしよう), scan, unused2(みしよう)
#             +0x14 u32 Hp   +0x18 u32 Mp   +0x1C u32 HpOverkill
#             +0x20 8x u8    Str Def Mag MDef Agi Luck Eva Acc
#             +0x28 i16 PropertyFlags       +0x2A u8 PoisonDamage
#             +0x2B 4x u8    ElementalWeakness (absorb/immune/resist/weak bitfields)
#             +0x2F 25x u8   StatusResistance (Death..Slow, 0=none, pct or 0xFF=immune)
#             +0x48 u16 AutoStatus1  +0x4A u16 AutoStatus2  +0x4C u16 AutoStatus3
#             +0x4E u16 ExtraImmunities
#             +0x50 16x u16  Abilities
#             +0x70 u16 ForcedAction  +0x72 i16 MonsterId  +0x74 i16 ModelId
#             +0x76 u8 CtbIconId  +0x77 s8 DoomCount  +0x78 s8 ArenaId  +0x79 u8 pad
#             +0x7A i16 Model2Id    +0x7C 4B padding
#
# USAGE   : python3 monster3_tail_audit.py [--csv]
#           Default corpus = /mnt/nvme-xpg/ffx_ps2/ffx/master/jppc (canonical PS2 master).
#
# LANE    : Jarvis-DEVIN swarm, leva 6 (work/_m347). 2026-09-15.

import os, sys, json, struct, hashlib, re, collections

ROOT = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc"
MON3 = os.path.join(ROOT, "battle/kernel/monster3.bin")
MON_DIR = os.path.join(ROOT, "battle/mon")
OUT_DIR = "/home/wanderson/Documents/ffx-editor-main/work/_m347"
JP_CS = "/home/wanderson/Documents/ffx-editor-main/FFXProjectEditor/FfxLib/Encoding/FfxEncoding.jp.cs"

# ---- JP decoder table, scraped from the repo's canonical table -----------------
def load_jp_table():
    table = {}
    src = open(JP_CS, encoding="utf-8").read()
    for m in re.finditer(r"\{\s*(\d+),\s*'((?:\\u[0-9A-Fa-f]{4})|(?:\\.)|[^'])'\s*\}", src):
        idx = int(m.group(1))
        raw = m.group(2)
        if raw.startswith("\\u"):
            ch = chr(int(raw[2:], 16))
        elif raw.startswith("\\"):
            ch = {"\\'": "'", "\\\\": "\\"}.get(raw, raw[-1])
        else:
            ch = raw
        table[idx] = ch
    return table

JP = load_jp_table()

def jp_decode(buf):
    """Decode one pool string (bytes up to 0x00) with the JP glyph map."""
    out = []
    for b in buf:
        if b == 0:
            break
        out.append(JP.get(b, f"<{b:02X}>"))
    return "".join(out)

def get_str(pool, off):
    if off >= len(pool):
        return None
    end = pool.find(b"\x00", off)
    if end < 0:
        end = len(pool)
    return jp_decode(pool[off:end]), end - off

STATUS_NAMES = ["Death","Zombie","Petrify","Poison","BreakPower","BreakMagic","BreakArmor",
                "BreakMental","Confuse","Berserk","Provoke","Threaten","Sleep","Silence",
                "Darkness","Shell","Protect","Reflect","NulTide","NulBlaze","NulShock",
                "NulFrost","Regen","Haste","Slow"]

def decode_row(data, base):
    """Decode one 128B record. base = absolute file offset."""
    r = {}
    ts = []
    for i in range(5):
        off, sid = struct.unpack_from("<HH", data, base + i * 4)
        ts.append((off, sid))
    r["tsinfo"] = ts
    r["hp"], r["mp"], r["hp_overkill"] = struct.unpack_from("<III", data, base + 0x14)
    st = data[base + 0x20: base + 0x28]
    r["stats"] = dict(zip(["str","def","mag","mdef","agi","luck","eva","acc"], st))
    r["prop_flags"] = struct.unpack_from("<h", data, base + 0x28)[0]
    r["poison_dmg"] = data[base + 0x2A]
    r["elem"] = list(data[base + 0x2B: base + 0x2F])
    r["status_resist"] = {STATUS_NAMES[i]: data[base + 0x2F + i]
                          for i in range(25) if data[base + 0x2F + i]}
    r["auto1"], r["auto2"], r["auto3"], r["extra_imm"] = struct.unpack_from("<HHHH", data, base + 0x48)
    r["abilities"] = list(struct.unpack_from("<16H", data, base + 0x50))
    r["forced_action"], r["monster_id"], r["model_id"] = struct.unpack_from("<Hhh", data, base + 0x70)
    r["ctb_icon"] = data[base + 0x76]
    r["doom"] = struct.unpack_from("<b", data, base + 0x77)[0]
    r["arena_id"] = struct.unpack_from("<b", data, base + 0x78)[0]
    r["model2_id"] = struct.unpack_from("<h", data, base + 0x7A)[0]
    r["nonzero_bytes"] = sum(1 for b in data[base:base + 0x80] if b)
    return r

def main():
    os.makedirs(OUT_DIR, exist_ok=True)
    data = open(MON3, "rb").read()
    size = len(data)
    minidx, maxidx, esize, tsize, toff = struct.unpack_from("<hhhHi", data, 8)
    rows = maxidx - minidx + 1
    data_end = toff + rows * esize
    pool = data[data_end:]
    print(f"file={MON3} size={size} (0x{size:X})")
    print(f"header: min={minidx} max={maxidx} stride={esize} tableSize={tsize} dataOff=0x{toff:X}")
    print(f"data region: 0x{toff:X}..0x{data_end:X}  pool: 0x{data_end:X}..0x{size:X} ({len(pool)}B)")
    print()

    out = []
    for mid in range(minidx, maxidx + 1):
        base = toff + (mid - minidx) * esize
        r = decode_row(data, base)
        r["id"] = mid
        r["file_off"] = base
        strs = []
        for i, (off, sid) in enumerate(r["tsinfo"]):
            s = get_str(pool, off)
            strs.append({"off": off, "sid": sid,
                         "text": s[0] if s else None, "len": s[1] if s else None,
                         "in_pool": off < len(pool)})
        r["strings"] = strs
        out.append(r)

    # ---- classify rows -----------------------------------------------------
    # template signature observed on rows 347-365 (m347-m360 clone family)
    def is_template(r):
        return (r["hp"] == 1 and r["mp"] == 1 and r["hp_overkill"] == 1
                and r["stats"]["str"] == 1 and not any(r["abilities"]))
    for r in out:
        if r["nonzero_bytes"] == 0:
            r["class"] = "ZERO_FILL"
        elif is_template(r):
            r["class"] = "TEMPLATE_347"
        else:
            r["class"] = "POPULATED"

    # ---- tail table --------------------------------------------------------
    print(f"{'id':>4} {'off':>7} {'nzB':>4} {'hp':>7} {'str..acc':>20} {'monId':>6} {'mdlId':>6} "
          f"{'arena':>5} {'name_off':>8}  name")
    for r in out[-40:]:
        s = " ".join(f"{r['stats'][k]:>2}" for k in ["str","def","mag","mdef","agi","luck","eva","acc"])
        name = r["strings"][0]["text"]
        print(f"{r['id']:>4} 0x{r['file_off']:05X} {r['nonzero_bytes']:>4} {r['hp']:>7} {s:>20} "
              f"{r['monster_id']:>6} {r['model_id']:>6} {r['arena_id']:>5} "
              f"0x{r['strings'][0]['off']:>05X}  {name!r}")

    # ---- class histogram ---------------------------------------------------
    cls = collections.Counter(r["class"] for r in out)
    print("\nrow classes:", dict(cls))
    print("zero-fill rows:", [r["id"] for r in out if r["class"] == "ZERO_FILL"])
    print("template rows :", [r["id"] for r in out if r["class"] == "TEMPLATE_347"])

    # ---- boundary: last row before the template run --------------------------
    ids = [r["id"] for r in out if r["class"] != "TEMPLATE_347" and r["class"] != "ZERO_FILL"]
    print(f"last POPULATED row: {max(ids) if ids else None}")

    # ---- strings referenced by template rows -------------------------------
    print("\n-- string slots of template rows (347-365) --")
    for r in out:
        if r["class"] != "TEMPLATE_347":
            continue
        lbl = ["name","sensor","unused1","scan","unused2"]
        desc = " | ".join(f"{lbl[i]}=({r['strings'][i]['text']!r}@0x{r['strings'][i]['off']:05X},sid{r['strings'][i]['sid']})"
                          for i in range(5))
        print(f"  id {r['id']}: {desc}")

    # ---- pool tail decode --------------------------------------------------
    print("\n-- pool tail: strings at offsets used by rows 347-365 --")
    seen = sorted({s["off"] for r in out[-19:] for s in r["strings"]})
    for off in seen:
        gs = get_str(pool, off)
        print(f"  pool+0x{off:05X} (file 0x{data_end+off:05X}): {gs[0]!r} len={gs[1]}")

    # ---- dump json ---------------------------------------------------------
    with open(os.path.join(OUT_DIR, "monster3_tail.json"), "w") as f:
        json.dump({"file": MON3, "size": size, "min": minidx, "max": maxidx,
                   "rows": out}, f, indent=1, ensure_ascii=False)
    with open(os.path.join(OUT_DIR, "monster3_tail.csv"), "w") as f:
        f.write("id,off,nzB,hp,mp,ovk,str,def,mag,mdef,agi,luck,eva,acc,propflags,poison,"
                "auto1,auto2,auto3,extraimm,forced,monster_id,model_id,ctb,doom,arena,model2,"
                "name_off,name_sid,name,sensor,scan,class\n")
        for r in out:
            st = r["stats"]
            nm = (r["strings"][0]["text"] or "").replace(",", " ")
            se = (r["strings"][1]["text"] or "").replace(",", " ")[:40]
            sc = (r["strings"][3]["text"] or "").replace(",", " ")[:40]
            f.write(f"{r['id']},0x{r['file_off']:05X},{r['nonzero_bytes']},{r['hp']},{r['mp']},{r['hp_overkill']},"
                    f"{st['str']},{st['def']},{st['mag']},{st['mdef']},{st['agi']},{st['luck']},{st['eva']},{st['acc']},"
                    f"{r['prop_flags']},{r['poison_dmg']},{r['auto1']},{r['auto2']},{r['auto3']},{r['extra_imm']},"
                    f"{r['forced_action']},{r['monster_id']},{r['model_id']},{r['ctb_icon']},{r['doom']},{r['arena_id']},{r['model2_id']},"
                    f"0x{r['strings'][0]['off']:05X},{r['strings'][0]['sid']},{nm},{se},{sc},{r['class']}\n")
    print(f"\nwrote {OUT_DIR}/monster3_tail.json + .csv")

if __name__ == "__main__":
    main()
