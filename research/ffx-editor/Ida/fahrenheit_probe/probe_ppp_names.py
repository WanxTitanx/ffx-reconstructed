#!/usr/bin/env python3
"""Probe: estrutura das tabelas de nomes de handlers PPP.

- 0xC3DC28 / 0xC3FD50: ponteiros para strings de nomes?
- 0xB4FEB0: strings?
"""
import ida_bytes
import ida_name


def main():
    for base in (0xC3DC28, 0xC3FD50):
        raw = ida_bytes.get_bytes(base, 64) or b""
        ptrs = [int.from_bytes(raw[i:i + 4], "little") for i in range(0, 64, 4)]
        print(f"{hex(base)}: ptrs={[hex(p) for p in ptrs[:8]]}", flush=True)
        for p in ptrs[:4]:
            if p and 0x400000 < p < 0x2000000:
                s = ida_bytes.get_bytes(p, 48) or b""
                st = s.split(b"\x00")[0].decode("ascii", "replace")
                print(f"  -> {hex(p)}: {st}", flush=True)
    raw = ida_bytes.get_bytes(0xB4FEB0, 256) or b""
    print("B4FEB0 head:", raw[:64].hex(), flush=True)


if __name__ == "__main__":
    main()
