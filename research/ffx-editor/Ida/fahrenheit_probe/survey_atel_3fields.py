#!/usr/bin/env python3
"""Survey corrigido: conta entradas preenchidas nos 3 campos (callpopa@+0, float@+8, int@+0xC)."""
import ida_bytes
import ida_name

TABLES = [("Movie", 0xC40E20), ("Battle", 0xC42618), ("Camera", 0xC43988),
          ("Common", 0xC50050), ("Default", 0xC52B60), ("Math", 0xC52BE0),
          ("Debug", 0xC52DD8), ("Mount", 0xC5D8C0), ("Map", 0xC5DC90),
          ("AbiMap", 0xC85EB0), ("SgEvent", 0xC88D88), ("ChEvent", 0xC891F8)]


def main():
    # ordena por endereco para saber o tamanho real de cada tabela
    for idx, (tname, taddr) in enumerate(sorted(TABLES, key=lambda x: x[1])):
        end = TABLES[idx + 1][1] if idx + 1 < len(TABLES) else taddr + 256 * 16
        # find next table address greater than taddr
        nxt = min((tb[1] for tb in TABLES if tb[1] > taddr), default=taddr + 256 * 16)
        size = nxt - taddr
        n = size // 16
        raw = ida_bytes.get_bytes(taddr, size) or b""
        filled = 0
        fields = {"+0": 0, "+8": 0, "+C": 0}
        for i in range(n):
            base = i * 16
            vals = {
                "+0": int.from_bytes(raw[base:base + 4], "little"),
                "+8": int.from_bytes(raw[base + 8:base + 12], "little"),
                "+C": int.from_bytes(raw[base + 12:base + 16], "little"),
            }
            hit = [k for k, v in vals.items() if v]
            if hit:
                filled += 1
                for k in hit:
                    fields[k] += 1
        print(f"{tname} @ {hex(taddr)}: {filled}/{n} preenchidas {fields}", flush=True)


if __name__ == "__main__":
    main()
