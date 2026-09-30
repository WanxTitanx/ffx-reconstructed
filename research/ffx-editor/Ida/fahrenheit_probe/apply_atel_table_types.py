#!/usr/bin/env python3
"""Atualiza a struct FFX_AtelFuncspaceEntry: +4 = status_fn (nao pad)."""
import ida_typeinf

# (endereco, entradas, nome)
TABLES = [
    (0xC40E20, 383, "Movie"),
    (0xC42618, 311, "Battle"),
    (0xC43988, 3180, "Camera"),
    (0xC50050, 689, "Common"),
    (0xC52B60, 8, "Default"),
    (0xC52BE0, 31, "Math"),
    (0xC52DD8, 2734, "Debug"),
    (0xC5D8C0, 61, "Mount"),
    (0xC5DC90, 4096, "Map"),
    (0xC85EB0, 749, "AbiMap"),
    (0xC88D88, 71, "SgEvent"),
    (0xC891F8, 256, "ChEvent"),
]


def main():
    idati = ida_typeinf.get_idati()
    ti = ida_typeinf.tinfo_t()
    decl = ("struct FFX_AtelFuncspaceEntry { void *callpopa_fn; void *status_fn; "
            "void *float_return_fn; void *int_return_fn; };")
    ok = ida_typeinf.parse_decl(ti, idati, decl, 0)
    print(f"struct atualizada: {ok}", flush=True)
    for ea, count, tname in TABLES:
        arr = ida_typeinf.tinfo_t()
        if not arr.create_array(ti, count):
            continue
        ida_typeinf.apply_tinfo(ea, arr, ida_typeinf.TINFO_DEFINITE)
    print("12 tabelas reaplicadas", flush=True)


if __name__ == "__main__":
    main()


