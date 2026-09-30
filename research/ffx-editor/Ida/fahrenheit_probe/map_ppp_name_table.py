#!/usr/bin/env python3
"""Mapa da tabela de nomes de handlers PPP em 0xC3DC28 (stride e conteudo)."""
import ida_bytes


def main():
    for stride in (16, 24, 32):
        raw = ida_bytes.get_bytes(0xC3DC28, stride * 8) or b""
        print(f"=== stride {stride} ===", flush=True)
        for i in range(8):
            base = i * stride
            if base + 16 > len(raw):
                break
            name_ptr = int.from_bytes(raw[base:base + 4], "little")
            fn_ptr = int.from_bytes(raw[base + 12:base + 16], "little")
            nm = ""
            if name_ptr and 0x400000 < name_ptr < 0x2000000:
                s = ida_bytes.get_bytes(name_ptr, 40) or b""
                nm = s.split(b"\x00")[0].decode("ascii", "replace")
            print(f"  [{i}] name={hex(name_ptr)} {nm} fn={hex(fn_ptr)}", flush=True)


if __name__ == "__main__":
    main()
