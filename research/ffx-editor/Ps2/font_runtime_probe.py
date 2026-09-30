#!/usr/bin/env python3
"""font_runtime_probe.py — FFX font runtime binding/cell resolver (stdlib only).

Lane Jarvis-FONT-RUNTIME, 2026-09-18. Encodes the PROVEN runtime map from
docs/reverse/FFX_FONT_RUNTIME_2026-09-18.md:

  * VRAM TBP upload table  (FFX_Font_RefreshVramAtlases 0x8B0FD0 /
                           FFX_Font_PushSlotsToLegacyGsUpload_stubbed 0x8B1140)
  * text page-code space   (FFX_Font_ResolveGlyphPagePath 0x8ACF00)
  * sprite/atlas-id space  (FFX_Menu2D_DrawDescSpriteQuad 0x8FE0B0 /
                           FFX_Menu2D_TexHandleByAtlasId ~0x8AC740)
  * subfont page (TBP 15744) block A/B/C cell formulas
  * markup marker decode   (0x06 = <F5:nn> -> slot5 newkit page 15712)

Usage:
  font_runtime_probe.py --tbp 15744        # what binds this TBP / spaces it lives in
  font_runtime_probe.py --markup 06        # decode a stream marker byte
  font_runtime_probe.py --cell 65 --block b|a|c   # atlas coords on the 15744 page
  font_runtime_probe.py --selftest
"""

UPLOAD_MAP = {
    # tbp: (source buffer global, dims, psm, identity)
    15360: ("g_FTCFontSlotTable[4*CurrentTextSlot]", "hdr", 20, "current .ftc font (slot0 JP/KR/CH, slot4 Western)"),
    15616: ("unk_1841D90 (Refresh: 1841D70/1841D80)", "hdr", 20, "event/battle font"),
    15680: ("g_FontUnkVar_1841DA0 (locale 0 only)", "hdr", 20, "JP aux/base variant"),
    15744: ("g_SubfontFmtBuf_1841D54 (Mscd 18,19)", "128x256", 20, "subfont.fmt dual-plane atlas (blocks A/B/C)"),
    15808: ("g_MenuTextFontSlotA (Mscd 4,14)", "256x128", 20, "icon sheet"),
    15872: ("g_MenuTextFontSlotB (Mscd 4,11)", "256x256", 19, "meswin window skin (SPRITE, not text)"),
    16128: ("g_MenuUnkVar_1841D5C (Mscd 4,15)", "512x128 | 256x256", 20, "strtex menu sprite atlas (SPRITE, not text)"),
    11936: ("g_FontUnkVar_1841DC8 (Mscd 4,8)", "64x64", 0, "min fallback"),
}

TEXT_PAGES = {
    15360: "menu/base_ftc (JP current slot)",
    15616: "event/battle *_ftc (slots 1,2)",
    15617: "help[_kr,_ch]/help_ftc (slot3)",
    15632: "menu_ch/base_ftc (CH current)",
    15648: "locale base variant",
    15664: "menu_kr/base_ftc (KR current)",
    15680: "menu_us/base_ftc (Western current slot4; JP aux upload)",
    15712: "menu[_kr,_ch]/newkit_ftc (slot5, <F5:nn>; NO upload target in binary)",
    15744: "menu/subfont (.fmt dual-plane atlas)",
}

ATLAS_IDS = {
    15808: "icon.dds.phyre (op6 sprite ids share via TexHandleByAtlasId)",
    15872: "meswin.dds.phyre (op6 field+20 in 0xC8..0x18F)",
    16128: "raw handle, no HD-path case (op6 field+20 in 0x190..0x257)",
}

MARKERS = {
    0x04: "KR/CH lead prefix: next code +1040",
    0x06: "<F5:nn> selector: next byte nn -> glyph nn-48, slot5 metrics, page 15712 newkit_ftc",
}

SLOT_LEADS = {
    "0x2C-0x2F / byte>=0x2C": "current text slot (slot0 JP/KR/CH -> 15360; slot4 Western -> 15680; KR 15664; CH 15632)",
    "0x2A-0x2B": "slot1 -> g=208*hi+lo-8784 -> 15616 event",
    "0x28-0x29": "slot2 -> g=208*hi+lo-8368 -> 15616 battle",
    "0x26-0x27": "slot3 -> g=208*hi+lo-7952 -> 15617 help",
}


def cell_xy(idx: int, block: str):
    """Atlas (x, y, parity) on the 128x256 TBP-15744 page for compact-ASCII
    index idx (= byte-32) or glyph id for block 'a'."""
    if block == "a":
        cell = idx >> 1
        return (10 * ((idx % 24) // 2), 12 * (idx // 24) + 144, idx & 1)
    if block == "b":
        return (8 * ((idx % 32) // 2), 192 + 10 * (idx // 32), idx & 1)
    if block == "c":
        return (8 * ((idx % 32) // 2), 240 + 8 * (idx // 32), idx & 1)
    raise ValueError(block)


def describe_tbp(tbp: int) -> str:
    out = [f"TBP {tbp} (0x{tbp:X}):"]
    if tbp in UPLOAD_MAP:
        src, dims, psm, what = UPLOAD_MAP[tbp]
        out.append(f"  [upload]   {what}; src={src}; dims={dims}; PSM={psm}")
    else:
        out.append("  [upload]   (not an upload target)")
    if tbp in TEXT_PAGES:
        out.append(f"  [textpage] {TEXT_PAGES[tbp]}")
    else:
        out.append("  [textpage] (not a text page code)")
    if tbp in ATLAS_IDS:
        out.append(f"  [spriteid] {ATLAS_IDS[tbp]}")
    return "\n".join(out)


def _selftest() -> bool:
    # block formulas must land in the documented strips (idx = byte-32)
    x, y, p = cell_xy(1, "b"); assert (x, y, p) == (0, 192, 1)   # '!' row0
    x, y, p = cell_xy(1, "c"); assert (x, y, p) == (0, 240, 1)
    x, y, p = cell_xy(33, "b"); assert (x, y, p) == (0, 202, 1)  # row1 of B strip
    x, y, p = cell_xy(33, "c"); assert (x, y, p) == (0, 248, 1)  # row1 of C strip
    x, y, p = cell_xy(10, "a"); assert (x, y) == (50, 144)
    # 15744 must be both upload target and text page; 15872/16128 must not be text pages
    assert 15744 in UPLOAD_MAP and 15744 in TEXT_PAGES
    assert 15872 not in TEXT_PAGES and 16128 not in TEXT_PAGES
    assert 15872 in ATLAS_IDS and 16128 in ATLAS_IDS
    # newkit page must be a text page but never an upload target
    assert 15712 in TEXT_PAGES and 15712 not in UPLOAD_MAP
    print("selftest OK: block formulas + 3-space separation + newkit gap all hold")
    return True


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--tbp", type=lambda s: int(s, 0), help="TBP/page value e.g. 15744 or 0x3D80")
    ap.add_argument("--markup", type=lambda s: int(s, 0), help="stream marker byte e.g. 0x06")
    ap.add_argument("--cell", type=int, help="glyph/compact-ASCII index")
    ap.add_argument("--block", choices=["a", "b", "c"], default="b")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        return 0 if _selftest() else 1
    if a.tbp is not None:
        print(describe_tbp(a.tbp))
    if a.markup is not None:
        print(f"marker 0x{a.markup:02X}:", MARKERS.get(a.markup, "(not a font marker)"))
        for k, v in SLOT_LEADS.items():
            print(f"  lead {k}: {v}")
    if a.cell is not None:
        x, y, p = cell_xy(a.cell, a.block)
        print(f"block {a.block.upper()} idx={a.cell}: x={x} y={y} parity(plane)={p} on TBP 15744 (128x256)")
    if a.tbp is None and a.markup is None and a.cell is None and not a.selftest:
        ap.print_help()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
