#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Extrai do noclip.website (FFX PS2) os artefatos de referencia PPP:
1) instructionTable (opcode -> classe de instrucao) — particle.ts
2) magicTable (ids nomeados de efeitos/magias) — magic.ts
3) KnownFunc / LOAD_ADDRESS — magic.ts
4) Estrutura do parseMagicFile (offsets de header) — bin.ts
"""
import json
import re
from pathlib import Path

SRC = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\noclip_reference")
OUT = SRC / "noclip_ppp_reference_20260731.json"

particle = (SRC / "particle.ts").read_text(encoding="utf-8")
magic = (SRC / "magic.ts").read_text(encoding="utf-8")
bin_ts = (SRC / "bin.ts").read_text(encoding="utf-8")

# 1) instructionTable: rawOpcode -> classe (anchor na ULTIMA entrada conhecida)
i = particle.find("const instructionTable")
anchor = particle.find("0x1002", i)
end = particle.find("];", anchor)
tbl = particle[i:end + 2]
rows = re.findall(r"[_(]\((0x[0-9A-Fa-f]+),\s*(\w+)", tbl)
instruction_table = [{"opcode": int(r[0], 16), "opcode_hex": r[0], "class": r[1]} for r in rows]

# 2) magicTable: entradas nomeadas com ids (main/alt)
entries = re.findall(r'_\("([^"]+)",\s*(0x[0-9A-Fa-f]+)(?:,\s*([0-9-]+))?', magic)
named_ids = [{"name": n, "id": int(i_, 16), "id_hex": i_, "alt": a} for n, i_, a in entries]

# categorias aproximadas (comentarios que precedem arrays)
cat_markers = re.findall(r"\[\s*//\s*(.+?)\n", magic)

# 3) KnownFunc enum + LOAD_ADDRESS
kf = re.search(r"enum KnownFunc\s*\{([^}]+)\}", magic)
known_funcs = []
if kf:
    for line in kf.group(1).splitlines():
        line = line.strip()
        m = re.match(r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m:
            known_funcs.append({"name": m.group(1), "addr": m.group(2)})
la = re.search(r"const LOAD_ADDRESS\s*=\s*(0x[0-9A-Fa-f]+)", magic)
load_address = la.group(1) if la else None

# 4) parseMagicFile offsets-chave (bin.ts)
pmf = bin_ts[bin_ts.find("export function parseMagicFile"):]
offsets = re.findall(r"0x([0-9A-Fa-f]{2})", pmf[:1200])
pmf_keys = [f"0x{o}" for o in offsets[:12]]

out = {
    "source": "noclip.website commit 39605028765aa2cfaf2cea175f01f3a77cd99c2e src/FinalFantasyX",
    "platform": "PS2 (EE/MIPS) — interpretador de particulas = PPP do FFX",
    "instruction_table_ps2": {"count": len(instruction_table), "entries": instruction_table},
    "magic_named_ids": {"count": len(named_ids), "entries": named_ids},
    "magic_categories_markers": cat_markers,
    "known_funcs_ps2": known_funcs,
    "load_address_mips": load_address,
    "parse_magic_file_key_offsets": pmf_keys,
    "particle_vec_count": 26,
    "frame_rate": 30,
}
(OUT).write_text(json.dumps(out, indent=1, ensure_ascii=False), encoding="utf-8")
print("OK:", OUT)
print("instructions:", len(instruction_table), "| named magic ids:", len(named_ids),
      "| known funcs:", len(known_funcs), "| LOAD_ADDRESS:", load_address)
