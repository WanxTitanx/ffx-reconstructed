# -*- coding: utf-8 -*-
"""dump_keyhole_named.py — roda DENTRO do IDA (via ida_mcp_client.py exec_file).

Lê a tabela de dispatch KEYHOLE em 0xC86080 (32 entries x 0x28 bytes),
resolve nomes de p0(+0), p8(+8), pC(+0xC), p1C(+0x1C) e salva
work/ppp_c2/dispatch_keyhole_named.json.

Semântica esperada (padrão das dispatch tables PPP do FFX):
  p0  -> ponteiro p/ string com o nome do opcode (ex.: "pppAccele")
  p8  -> ponteiro p/ handler (funcao .text) ou 0
  pC  -> ponteiro p/ handler alternativo (funcao .text) ou 0
  p1C -> ponteiro p/ handler alternativo 2 (funcao .text) ou 0
"""
import json

import ida_bytes
import ida_funcs
import ida_name
import ida_segment
import idc

TABLE_VA = 0xC86080
ENTRIES = 32
STRIDE = 0x28
OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\ppp_c2\dispatch_keyhole_named.json"


def resolve(ea: int) -> dict:
    """Resolve um ponteiro: funcao? string? global? raw."""
    if ea == 0:
        return {"va": "0x0", "name": None, "kind": "null"}
    out = {"va": hex(ea)}
    f = ida_funcs.get_func(ea)
    if f:
        out["kind"] = "func"
        out["name"] = ida_funcs.get_func_name(ea) or idc.get_func_name(ea)
        out["size"] = hex(f.end_ea - f.start_ea)
        return out
    s = idc.get_strlit_contents(ea, -1, idc.STRTYPE_C)
    if s:
        try:
            txt = s.decode("utf-8", "replace")
        except Exception:
            txt = repr(s)
        out["kind"] = "string"
        out["name"] = txt[:96]
        return out
    nm = ida_name.get_name(ea)
    if nm:
        out["kind"] = "global"
        out["name"] = nm
        return out
    seg = ida_segment.getseg(ea)
    out["kind"] = "data" if seg else "raw"
    out["name"] = None
    return out


def main():
    rows = []
    for i in range(ENTRIES):
        base = TABLE_VA + i * STRIDE
        p0 = ida_bytes.get_dword(base + 0x00)
        p8 = ida_bytes.get_dword(base + 0x08)
        pC = ida_bytes.get_dword(base + 0x0C)
        p1C = ida_bytes.get_dword(base + 0x1C)
        row = {
            "i": i,
            "entry_va": hex(base),
            "p0": resolve(p0),
            "p8": resolve(p8),
            "pC": resolve(pC),
            "p1C": resolve(p1C),
        }
        # nome do opcode vem da string apontada por p0 (quando disponivel)
        row["opcode"] = row["p0"]["name"] if row["p0"]["kind"] == "string" else None
        rows.append(row)

    with open(OUT, "w", encoding="utf-8") as fh:
        json.dump(rows, fh, indent=1, ensure_ascii=False)

    # imprime resumo compacto (vai pro stdout do MCP)
    print("KEYHOLE_DUMP_OK", OUT)
    for r in rows:
        def nm(x):
            return x["name"] if x["name"] else ("0" if x["kind"] == "null" else "?")
        print(
            f"[{r['i']:2d}] {r['entry_va']}  p0={nm(r['p0']):28s} "
            f"p8={nm(r['p8']):22s} pC={nm(r['pC']):22s} p1C={nm(r['p1C'])}"
        )


if __name__ == "__main__":
    main()
