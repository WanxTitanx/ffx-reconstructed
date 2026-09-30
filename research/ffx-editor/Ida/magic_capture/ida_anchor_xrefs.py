# IDAPython (static): locate magic/effect anchor strings in FFX.exe and list the functions that
# reference them. Run after auto-analysis: IDA > File > Script file...  Output: magic_anchor_xrefs.csv
# next to the .idb. READ-ONLY (no patching). IDA 7.4+ API.

import os
import csv
import idautils
import idc
import ida_funcs

ANCHORS = [
    "magicfile", "setmagicid", "magic_%04d", "magic%04d", "unknown magic file",
    "effectdata", "peffectvariant", "pposteffectmanager", "pposteffectbase",
    "bat_eff", "monmagic", "eff_", "effect%02d",
]


def matches(text):
    low = text.lower()
    return any(a in low for a in ANCHORS)


def main():
    rows = []
    for s in idautils.Strings():
        try:
            text = str(s)
        except Exception:
            continue
        if not matches(text):
            continue
        ea = s.ea
        refs = list(idautils.DataRefsTo(ea))
        if not refs:
            rows.append(("0x%08X" % ea, text.replace("\n", " ")[:140], "", ""))
            continue
        for r in refs:
            f = ida_funcs.get_func(r)
            fname = idc.get_func_name(f.start_ea) if f else ""
            faddr = "0x%08X" % f.start_ea if f else ""
            rows.append(("0x%08X" % ea, text.replace("\n", " ")[:140], "0x%08X" % r, fname or faddr))

    idb = idc.get_idb_path() or ""
    out = os.path.join(os.path.dirname(idb) if idb else ".", "magic_anchor_xrefs.csv")
    with open(out, "w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["string_ea", "string", "xref_ea", "func"])
        w.writerows(rows)
    print("ida_anchor_xrefs: wrote %d rows -> %s" % (len(rows), out))


main()
