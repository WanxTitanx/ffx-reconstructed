#!/usr/bin/env python3
"""Lote 4 v2: renomeia handlers PPP usando o blob de nomes (0xC3DC28..0xC3FD50).

Strings ppp* extraidas dos bytes crus (0xB40000..0xB70000); para cada ponteiro de
funcao no blob, casa com a string mais proxima antes dele.
"""
import ida_bytes
import ida_funcs
import ida_name
import idc
import re

BLOB_START = 0xC3DC28
BLOB_END = 0xC3FD50
FN_RANGE = (0x700000, 0x780000)
STR_RANGE = (0xB40000, 0xB70000)
DEFAULT = re.compile(r"^(sub_|FUN_|nullsub_|loc_|j_)", re.I)
STR_RE = re.compile(rb"ppp[A-Za-z0-9_]{2,}")


def main():
    # strings dos bytes crus
    raw_str = ida_bytes.get_bytes(STR_RANGE[0], STR_RANGE[1] - STR_RANGE[0]) or b""
    str_map = []
    for m in STR_RE.finditer(raw_str):
        str_map.append((STR_RANGE[0] + m.start(), m.group().decode("ascii", "replace")))
    print(f"strings ppp* encontradas: {len(str_map)}", flush=True)
    raw = ida_bytes.get_bytes(BLOB_START, BLOB_END - BLOB_START) or b""
    # mapa: addr_do_blob -> nome da string apontada
    blob_names = {}
    for off in range(0, len(raw) - 4, 4):
        ptr = int.from_bytes(raw[off:off + 4], "little")
        for str_addr, str_name in str_map:
            if ptr == str_addr:
                blob_names[BLOB_START + off] = str_name
                break
    print(f"ponteiros p/ strings no blob: {len(blob_names)}", flush=True)
    applied = 0
    for off in range(0, len(raw) - 4, 4):
        ptr = int.from_bytes(raw[off:off + 4], "little")
        if not (FN_RANGE[0] <= ptr < FN_RANGE[1]):
            continue
        cur = ida_name.get_name(ptr)
        if cur and not DEFAULT.match(cur):
            continue
        # procura name_ptr num raio de 0x140 antes
        best = None
        for boff, bname in blob_names.items():
            if 0 <= BLOB_START + off - boff <= 0x140:
                best = bname
                break
        if best and ida_name.set_name(ptr, best, ida_name.SN_NOCHECK | ida_name.SN_FORCE):
            applied += 1
    idc.save_database("")
    print(f"DONE: applied={applied} — db salva.", flush=True)


if __name__ == "__main__":
    main()


