#!/usr/bin/env python3
"""Analisa os globals do relatorio sem modulo claro (top_fn sem prefixo conhecido)."""
import json
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
d = json.load(open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\data_globals_report.json", encoding="utf-8"))
top = d["top"]
known = ("FFX_Magic", "FFX_Ppp", "ppp", "FFX_Abmap", "FFX_FieldMap", "FFX_Field", "FFX_FieldMath",
         "FFX_Battle", "FFX_Btl", "FFX_Sound", "FFX_Menu2D", "FFX_Atel", "FFX_Save", "FFX_Sphere",
         "FFX_Text", "FFX_Input", "FFX_Encounter", "FFX_Camera", "FFX_KR_", "FFX_GDraw", "FFX_Mscd",
         "FFX_Event", "FFX_Chr", "Phyre", "PClassDescriptor", "FmodManager")
unknown = [t for t in top if not any(t["top_fn"].startswith(k) for k in known)]
print(f"globals sem modulo: {len(unknown)}")
for t in unknown:
    print(f"  {t['count']:4d}x  {t['ea']}  <- {t['top_fn']}")
