#!/usr/bin/env python3
"""Generate a translation-ready inventory of missing i18n keys for the FRENCH satellite.

Deterministic: reads Strings.resx (EN source of truth), Strings.pt.resx (PT reference)
and Strings.fr.resx, computes missing = EN keys - FR keys, groups them by module prefix
and writes a bullet-point .md so a translator can translate all keys in one pass.

Output: docs/ai/i18n_gap/I18N_GAP_FR_2026-08-18.md
"""
import os
import re
import html

REPO = r"C:\Users\wande\Documents\ffx-editor-main"
EN_PATH = os.path.join(REPO, "FFXProjectEditor", "Resources", "Strings.resx")
PT_PATH = os.path.join(REPO, "FFXProjectEditor", "Resources", "Strings.pt.resx")
FR_PATH = os.path.join(REPO, "FFXProjectEditor", "Resources", "Strings.fr.resx")
OUT_PATH = os.path.join(REPO, "docs", "ai", "i18n_gap", "I18N_GAP_FR_2026-08-18.md")

DATA_RE = re.compile(r'<data name="([^"]+)"[^>]*>\s*<value>(.*?)</value>', re.S)

# Module map: first-2-segment prefix -> section header.
MODULE_MAP = {
    "U_Ai_": "Monster AI Editor",
    "U_Au_": "Aurora Chamber / Aurora Field Explorer",
    "U_CBC_": "CustomBossCreator",
    "U_Sgb_": "SphereGridBuilder",
    "U_Sgp_": "SphereGridPanel",
    "U_Sge_": "SphereGridExplorer",
    "U_Dd_": "DifficultyDirector",
    "U_Bb_": "FfxLib Battle",
    "U_Fe_": "FormationEditor",
    "U_Ee_": "EventExplorer",
    "U_Lbl_": "Generic labels",
    "U_Env_": "Shared Controls",
    "U_Cap_": "Shared Controls",
    "U_Chg_": "Shared Controls",
    "U_Diff_": "Shared Controls",
    "U_Rcpt_": "Shared Controls",
    "U_Ws_": "Shared Controls",
}

F2_GROUP = "F2_* (Legacy MonsterAi)"
LEGACY_GROUP = "Legacy/outros"


def parse_resx(path):
    """Return {key: raw_value} parsed from a resx file (BOM-tolerant)."""
    with open(path, encoding="utf-8-sig") as fh:
        text = fh.read()
    return {m.group(1): m.group(2) for m in DATA_RE.finditer(text)}


def group_of(key):
    """Deterministic group assignment based on the key name."""
    if key.startswith("F2_"):
        return F2_GROUP
    parts = key.split("_")
    if len(parts) >= 2:
        prefix = parts[0] + "_" + parts[1] + "_"
    else:
        prefix = key
    return MODULE_MAP.get(prefix, LEGACY_GROUP)


def clean_value(raw):
    """Decode XML escapes and make the value safe for a single markdown line."""
    val = html.unescape(raw)          # &amp; &lt; &gt; &#x...; etc.
    val = val.replace("\r\n", "\n").replace("\r", "\n")
    val = val.replace("\n", "\\n")    # keep the bullet on one line
    val = val.replace('"', '\\"')     # keep markdown valid
    return val


def main():
    en = parse_resx(EN_PATH)
    pt = parse_resx(PT_PATH)
    fr = parse_resx(FR_PATH)

    missing = sorted(set(en) - set(fr))
    missing_count = len(missing)

    # Group by module prefix, keys sorted alphabetically inside each group.
    groups = {}
    for key in missing:
        groups.setdefault(group_of(key), []).append(key)
    for g in groups.values():
        g.sort()

    # Sort groups by count descending (stable tie-break keeps deterministic order).
    ordered_groups = sorted(groups.items(), key=lambda kv: (-len(kv[1]), kv[0]))

    lines = []
    lines.append("# I18N GAP \u2014 Fran\u00e7ais (fr) \u2014 2026-08-18")
    lines.append("")
    lines.append(
        f"> Missing keys: **{missing_count}** | EN total: **{len(en)}** | fr total: **{len(fr)}**"
    )
    lines.append("")
    lines.append(
        "> All keys below are absent from `Strings.fr.resx` and currently fall back to EN in the UI. "
        "Translate them in one pass; EN is the source of truth, PT is the reference."
    )
    lines.append("")
    lines.append(f"> Generated deterministically by `work/gen_gap_fr.py` (missing = EN keys \u2212 fr keys).")
    lines.append("")

    for group, keys in ordered_groups:
        lines.append(f"## {group} ({len(keys)})")
        lines.append("")
        for key in keys:
            en_val = clean_value(en[key])
            bullet = f'- [ ] {key} \u2014 EN: "{en_val}"'
            if key in pt and pt[key].strip() != "":
                pt_val = clean_value(pt[key])
                bullet += f' | PT: "{pt_val}"'
            lines.append(bullet)
        lines.append("")

    os.makedirs(os.path.dirname(OUT_PATH), exist_ok=True)
    with open(OUT_PATH, "w", encoding="utf-8") as fh:
        fh.write("\n".join(lines))

    # Verify bullet count == missing count.
    bullet_count = sum(1 for line in lines if line.startswith("- [ ] "))
    print(f"EN keys: {len(en)} | PT keys: {len(pt)} | fr keys: {len(fr)}")
    print(f"Missing keys: {missing_count}")
    print(f"Groups: {len(ordered_groups)}")
    for group, keys in ordered_groups:
        print(f"  {len(keys):5d}  {group}")
    print(f"Bullets written: {bullet_count}")
    print(f"Output: {OUT_PATH}")
    assert bullet_count == missing_count, "bullet count mismatch"


if __name__ == "__main__":
    main()