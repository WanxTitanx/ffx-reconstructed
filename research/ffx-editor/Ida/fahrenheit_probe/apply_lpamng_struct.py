#!/usr/bin/env python3
"""Lote 8: cria a struct LpAbilityMapEngine e aplica em 0x16AD870.

Layout PROVADO (doc FFX_GHIDRA_FAHRENHEIT_SYMBOL_IMPORT + SPHERE_GRID docs):
  +0x0    header/estado
  +0x8    clusters[128]  (128 x 16B = 0x800)
  +0x808  nodes[1024]    (1024 x 0x28 = 0xA000)
  +0xA808 links[1024]    (1024 x 0x14 = 0x5000)
  +0xF808 node_type_infos[130] (UI info)
  total 0x12FC0
"""
import ida_typeinf
import idc


def main():
    idati = ida_typeinf.get_idati()
    ti = ida_typeinf.tinfo_t()
    decl = (
        "struct FFX_LpAbilityMapEngine {"
        " char state[8];"
        " char clusters[2048];"
        " char nodes[40960];"
        " char links[14336];"
        " char node_type_ui[33280];"
        "};"
    )
    ok = ida_typeinf.parse_decl(ti, idati, decl, 0)
    print(f"struct LpAbilityMapEngine: {ok}", flush=True)
    if ida_typeinf.apply_tinfo(0x16AD870, ti, ida_typeinf.TINFO_DEFINITE):
        print("aplicada em 0x16AD870", flush=True)
    else:
        print("FALHA em 0x16AD870", flush=True)
    idc.save_database("")
    print("db salva", flush=True)


if __name__ == "__main__":
    main()
