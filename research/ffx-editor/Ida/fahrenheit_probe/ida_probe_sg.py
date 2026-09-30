#!/usr/bin/env python3
"""Probe da DB canonica do FFX para mapear TODOS os limites do Sphere Grid.

Objetivo: mapear onde vivem as constantes 1024 nodes / 1024 links / 128 clusters
(struct estatico LpAbilityMapEngine, 0x12FC0) e todos os pontos que dependem
delas, para planejar o aumento de limite. Read-only (nao salva a DB).
"""
import json
import re
import sys
import traceback
from contextlib import redirect_stderr, redirect_stdout
from io import StringIO
from pathlib import Path

import idapro

OUT = Path(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\ida_results")
OUT.mkdir(parents=True, exist_ok=True)

DB_CANDIDATES = [
    r"F:\ffx-reconstructed\extras\ffxoficial.exe.i64",
    r"C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\FFX_recon.i64",
    r"F:\ffx-reconstructed\extras\ffxoficial_COPY.i64",
]

# Funcoes alvo conhecidas da pipeline ABMAP (VA IDA, base 0x400000)
FUNC_TARGETS = {
    0xA572E0: "FFX_Abmap_InitStaticMenuStateBuffers",
    0xA45570: "FFX_Abmap_LoadCompiledLayoutAndDeriveNodeCells",
    0xA49590: "FFX_Abmap_ApplyRuntimeNodeStates",
    0xA51340: "FFX_Abmap_DrawRuntimePanelNodes",
    0xA54860: "FFX_Abmap_RecomputePartyStatsAndLearnedMoves",
    0xA5BB70: "FFX_Abmap_ExitPersistSave",
    0xA56060: "FFX_Abmap_ExitConfirmPersistAndLeave",
    0x681DB0: "FFX_Menu2D_InitBatchBuffers_NoTextureFallback",
    0x7F4900: "FFX_Menu2D_DrawQuadIndexedBatch",
    0x8E27E0: "FFX_Abmap_DeactivateAndReturnToFieldUI",
}

# Ponteiro global do menu blob (RVA 0x1F05834 + base 0x400000 = VA 0x2305834)
G_MENU_PTR = 0x2305834

# Constantes de limite de interesse
LIMIT_CONSTS = {
    "1024": 1024, "861": 861, "860": 860, "128": 128,
    "0x12FC0": 0x12FC0, "0xA000": 0xA000, "0x5000": 0x5000,
    "0x800": 0x800, "0x1320": 0x1320, "0x28": 0x28, "0x14": 0x14, "0x10": 0x10,
}

# Constantes RELEVANTES para o range scan (filtra ruido de 0x10/0x14/0x28/0x800)
LIMIT_CONSTS_RELEVANT = {
    "1024": 1024, "861": 861, "860": 860,
    "0x12FC0": 0x12FC0, "0xA000": 0xA000, "0x5000": 0x5000, "0x1320": 0x1320,
    "0x35D": 0x35D, "0x35C": 0x35C,
}


def decompile(hexrays, funcs, ea):
    """Decompila uma funcao; retorna (ok, text)."""
    f = funcs.get_func(ea)
    if not f:
        return False, "no_func"
    try:
        cf = hexrays.decompile(ea)
        return True, str(cf)
    except Exception as exc:  # noqa: BLE001
        return False, f"decompile_error: {exc}"


def imm_in_text(text, imm_hex):
    """True se o pseudocodigo contem a constante (hex ou decimal)."""
    return (f"0x{imm_hex:X}" in text) or (f"0x{imm_hex:x}" in text) or (str(imm_hex) in text)


def main():
    opened = None
    for db in DB_CANDIDATES:
        if not Path(db).exists():
            print(f"SKIP (missing): {db}", flush=True)
            continue
        try:
            with redirect_stdout(StringIO()), redirect_stderr(StringIO()):
                rc = idapro.open_database(db, False)
        except Exception as exc:  # noqa: BLE001
            print(f"OPEN FAIL {db}: {exc}", flush=True)
            continue
        if rc != 0:
            print(f"OPEN FAIL (rc={rc}): {db}", flush=True)
            continue
        print(f"OPENED: {db}", flush=True)
        opened = db
        break

    if opened is None:
        print("FATAL: nenhuma DB abriu", flush=True)
        return 2

    import ida_ida
    import ida_name
    import ida_segment
    import ida_funcs
    import ida_hexrays
    import idautils
    import idc

    info = {
        "db": opened,
        "root": idc.get_root_filename(),
        "min_ea": hex(ida_ida.inf_get_min_ea()),
        "proc": idc.get_inf_attr(idc.INF_PROCNAME),
    }
    print(f"DB: {info}", flush=True)

    results = {"db_info": info, "targets": {}, "abmap_range": [], "menu_ptr_xrefs": [], "static_buffer": None}

    # 1) Decompila funcoes alvo
    for ea, label in FUNC_TARGETS.items():
        ok, text = decompile(ida_hexrays, ida_funcs, ea)
        entry = {"label": label, "ok": ok, "text": text}
        if ok:
            entry["consts"] = {k: imm_in_text(text, v) for k, v in LIMIT_CONSTS.items()}
            hits = [k for k, v in entry["consts"].items() if v]
            print(f"[TARGET] {label} @ 0x{ea:X} consts={hits}", flush=True)
        results["targets"][f"0x{ea:X}"] = entry

    # 2) Todas as funcoes na faixa ABMAP real (0xA40000..0xA60000) com constantes RELEVANTES
    range_hits = []
    for ea in idautils.Functions(0xA40000, 0xA60000):
        nm = ida_name.get_name(ea) or ""
        ok, text = decompile(ida_hexrays, ida_funcs, ea)
        if not ok:
            continue
        consts = {k: imm_in_text(text, v) for k, v in LIMIT_CONSTS_RELEVANT.items()}
        hits = [k for k, v in consts.items() if v]
        if hits:
            range_hits.append({"ea": hex(ea), "name": nm, "consts": hits, "text": text})
            print(f"[HIT] {nm or hex(ea)} @ {hex(ea)} consts={hits}", flush=True)
    results["abmap_range"] = range_hits
    print(f"[RANGE] ABMAP funcs com consts relevantes: {len(range_hits)}", flush=True)


    # 3) Xrefs ao ponteiro global do menu blob
    ptr_xrefs = []
    try:
        for xr in idautils.XrefsTo(G_MENU_PTR, 0):
            fn = ida_funcs.get_func(xr.frm)
            fn_name = ida_name.get_name(fn.start_ea) if fn else ""
            ptr_xrefs.append({"from": hex(xr.frm), "type": xr.type, "func": fn_name})
    except Exception as exc:  # noqa: BLE001
        ptr_xrefs.append({"error": str(exc)})
    results["menu_ptr_xrefs"] = ptr_xrefs
    print(f"[PTR] xrefs to 0x{G_MENU_PTR:X}: {len(ptr_xrefs)}", flush=True)

    # 4) Buffer estatico: enderecos de dados citados no codigo de A572E0
    try:
        cf = ida_hexrays.decompile(0xA572E0)
        text = str(cf)
        addrs = re.findall(r"0x([0-9A-Fa-f]{5,8})", text)
        interesting = []
        for a in addrs:
            v = int(a, 16)
            if v > 0x400000:
                seg = ida_segment.getseg(v)
                if seg:
                    interesting.append({"addr": hex(v), "seg": ida_segment.get_segm_name(seg)})
        results["static_buffer"] = {"a572e0_text": text, "data_candidates": interesting}
        print(f"[BUF] candidatos em A572E0: {interesting}", flush=True)
    except Exception as exc:  # noqa: BLE001
        results["static_buffer"] = {"error": str(exc)}

    # 5) Info de secoes (salva JSON antes, para nao perder nada)
    (OUT / "sg_limit_probe.json").write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding="utf-8")
    segs = []
    for s in idautils.Segments():
        seg = ida_segment.getseg(s)
        name = ida_segment.get_segm_name(seg) if seg else "?"
        end = seg.end_ea if seg else s
        segs.append({"name": name, "start": hex(s), "end": hex(end)})
    results["segments"] = segs

    (OUT / "sg_limit_probe.json").write_text(json.dumps(results, indent=2, ensure_ascii=False), encoding="utf-8")

    md = ["# SG Limit Probe (fahrenheit cross-check)", "",
          f"- DB: `{info['db']}` root=`{info['root']}` min_ea={info['min_ea']}",
          f"- Funcoes alvo: {len(results['targets'])}",
          f"- Faixa ABMAP: {len(range_hits)} funcoes com constantes de limite", ""]
    md.append("## Funcoes com constantes de limite")
    md.append("| EA | Nome | Consts |")
    md.append("|---|---|---|")
    for f in range_hits:
        md.append(f"| {f['ea']} | {f['name'] or '-'} | {', '.join(f['consts'])} |")
    for ea, t in results["targets"].items():
        if t.get("ok"):
            consts = [k for k, v in t.get("consts", {}).items() if v]
            md.append(f"| {ea} | {t['label']} | {', '.join(consts) or '-'} |")
    md.append("")
    md.append("## Xrefs ao ponteiro global (menu blob)")
    md.append("| De | Tipo | Funcao |")
    md.append("|---|---|---|")
    for x in ptr_xrefs:
        md.append(f"| {x.get('from')} | {x.get('type')} | {x.get('func', '')} |")
    md.append("")
    md.append("## Buffer estatico (de A572E0)")
    if isinstance(results.get("static_buffer"), dict) and "error" not in results["static_buffer"]:
        for c in results["static_buffer"].get("data_candidates", []):
            md.append(f"- {c['addr']} ({c['seg']})")
        md.append("")
        md.append("### Pseudocodigo A572E0")
        md.append("```c")
        md.append(results["static_buffer"]["a572e0_text"])
        md.append("```")
    (OUT / "sg_limit_probe_summary.md").write_text("\n".join(md), encoding="utf-8")

    with redirect_stdout(StringIO()), redirect_stderr(StringIO()):
        idapro.close_database(False)
    print("DONE -> " + str(OUT), flush=True)
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception:  # noqa: BLE001
        traceback.print_exc()
        sys.exit(1)

    results = {"db_info": info, "targets": {}, "abmap_range": [], "menu_ptr_xrefs": [], "static_buffer": None}

    # 1) Decompila funcoes alvo
    for ea, label in FUNC_TARGETS.items():
        ok, text = decompile(ida_hexrays, ida_funcs, ea)
        entry = {"label": label, "ok": ok, "text": text}
        if ok:
            entry["consts"] = {k: imm_in_text(text, v) for k, v in LIMIT_CONSTS.items()}
            hits = [k for k, v in entry["consts"].items() if v]
            print(f"[TARGET] {label} @ 0x{ea:X} consts={hits}", flush=True)
        results["targets"][f"0x{ea:X}"] = entry

    # 2) Todas as funcoes na faixa ABMAP (0xA40000..0xA70000) com constantes de limite
    range_hits = []
    for ea in autils.Functions(0xA40000, 0xA70000):
        nm = ida_name.get_name(ea) or ""
        ok, text = decompile(ida_hexrays, ida_funcs, ea)
        if not ok:
            continue
        consts = {k: imm_in_text(text, v) for k, v in LIMIT_CONSTS.items()}
        hits = [k for k, v in consts.items() if v]
        if hits:
            range_hits.append({"ea": hex(ea), "name": nm, "consts": hits})
            print(f"[HIT] {nm or ea:#x} @ {ea:#x} consts={hits}", flush=True)
    results["abmap_range"] = range_hits
    print(f"[RANGE] total ABMAP funcs scanned, {len(range_hits)} com consts", flush=True)
