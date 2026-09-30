#!/usr/bin/env python3
"""Lote 16: limpa nomes de locals corrompidos nos decompiles.

Locals com padrao '[Jarvis...' ou com colchetes/espacos viram nomes curtos.
Melhora a legibilidade de TODOS os decompiles futuros.
"""
import ida_funcs
import ida_hexrays
import ida_name
import idc
import re

BAD = re.compile(r"\[|]|\s|/|:")


def main():
    if not ida_hexrays.init_hexrays_plugin():
        print("hexrays nao disponivel", flush=True)
        return
    qty = ida_funcs.get_func_qty()
    fixed = 0
    checked = 0
    for i in range(qty):
        f = ida_funcs.getn_func(i)
        if not f:
            continue
        fname = ida_name.get_name(f.start_ea) or ""
        # filtra: funcoes com nomes da sessao de junho (procuram locals corrompidos)
        if not any(k in fname for k in ("Jarvis", "proved", "_structural", "CALL")):
            continue
        cf = ida_hexrays.decompile(f)
        if not cf:
            continue
        checked += 1
        for lv in cf.lvars:
            name = lv.name
            if name and ("[" in name or "]" in name or "/" in name or " " in name):
                clean = BAD.sub("_", name).strip("_")
                if not clean:
                    clean = "v"
                if len(clean) > 24:
                    clean = clean[:24]
                try:
                    if lv.set_name(clean):
                        fixed += 1
                except Exception:
                    pass
        if checked >= 30:
            break
    idc.save_database("")
    with open(r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe\clean_locals_log.txt", "a", encoding="utf-8") as f:
        f.write(f"funcoes={checked} locals_limpos={fixed}\n")

    print(f"DONE: funcoes={checked} locals limpos={fixed} — db salva.", flush=True)


if __name__ == "__main__":
    main()

