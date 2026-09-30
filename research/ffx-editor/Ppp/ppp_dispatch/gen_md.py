"""Gera work/ppp_dispatch/PPP_DISPATCH_TABLE_20260731.md a partir do JSON do extrator."""
import json
from pathlib import Path

ROOT = Path(r"C:\Users\wande\Documents\ffx-editor-main")
DATA = json.load(open(ROOT / "work/ppp_dispatch/PPP_DISPATCH_TABLE_20260731.json", encoding="utf-8"))

SLOT_LABEL = {0: "-", 4: "+0x04", 8: "+0x08", 12: "+0x0C"}

lines = []
lines.append("# PPP Dispatch Table — Extrato 2026-07-31")
lines.append("")
lines.append(f"Fonte: `{DATA['imagebase']:#x}` (FFX.exe, IDB COPY `ffxoficial_COPY.i64`).")
lines.append(f"Scan: `{DATA['scan_start']:#x}`..`{DATA['scan_end']:#x}`; entries de `{DATA['entry_size']:#x}` bytes; `{DATA['name_ptr_count']}` ponteiros para nomes `ppp*`; `{DATA['table_count']}` tabelas.")
lines.append("")
lines.append("Gerado por `scripts/ppp_dispatch_extractor.py` (roda dentro do IDA). Documento de método/evidências: `docs/reverse/PPP_DISPATCH_TABLE_RE_20260731.md`.")
lines.append("")

for t in DATA["tables"]:
    es = t["entries"]
    named = sum(1 for e in es if e["handler_named"])
    zero = sum(1 for e in es if not e["handler_ptr"])
    lines.append(f"## Tabela {t['table_id']} — `{t['start']:#x}`..`{t['end']:#x}` ({t['entry_count']} entries × 0x28)")
    lines.append("")
    lines.append(f"- Entries: {t['entry_count']} · handlers nomeados: {named} · entries sem handler (+4/+8/+0xC nulos): {zero}")
    lines.append("")
    lines.append("| # | Entry addr | Nome | Slot | Handler | Nome do handler | +0x1C | +0x20 |")
    lines.append("|---|-----------|------|------|---------|-----------------|-------|-------|")
    for i, e in enumerate(es):
        h = f"{e['handler_ptr']:#x}" if e["handler_ptr"] else "-"
        hn = e["handler_name"] or "-"
        c1 = f"{e['aux_ptr_1c']:#x}" if e["aux_ptr_1c"] else "-"
        c2 = f"{e['aux_ptr_20']:#x}" if e["aux_ptr_20"] else "-"
        lines.append(
            f"| {i} | {e['entry_addr']:#x} | {e['name']} | {SLOT_LABEL.get(e['handler_slot'], '?')} | {h} | {hn} | {c1} | {c2} |"
        )
    lines.append("")

out = ROOT / "work/ppp_dispatch/PPP_DISPATCH_TABLE_20260731.md"
out.write_text("\n".join(lines), encoding="utf-8")
print(f"wrote {out} ({len(lines)} lines)")
