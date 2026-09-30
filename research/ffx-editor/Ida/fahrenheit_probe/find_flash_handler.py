#!/usr/bin/env python3
"""Acha o ponteiro de funcao do handler pppop_flash no blob 0xC3DC28..0xC3FD50."""
import ida_bytes
import ida_name
import ida_funcs


def main():
    start = 0xC3DC28
    end = 0xC3FD50
    raw = ida_bytes.get_bytes(start, end - start) or b""
    name_ptr = 0xB504E4
    for off in range(0, len(raw) - 4, 4):
        v = int.from_bytes(raw[off:off + 4], "little")
        if v == name_ptr:
            print(f"name_ptr em {hex(start + off)}", flush=True)
            # procura fn_ptr num raio de 0x40
            for j in range(off + 4, min(off + 0x50, len(raw) - 4), 4):
                fv = int.from_bytes(raw[j:j + 4], "little")
                if 0x400000 <= fv < 0xA00000 and ida_funcs.get_func(fv):
                    fn = ida_name.get_name(fv)
                    print(f"  fn_ptr {hex(start + j)} -> {hex(fv)} {fn}", flush=True)


if __name__ == "__main__":
    main()
