#!/usr/bin/env python3
"""
explore_all.py — marca TODOS os bytes 'unexplored' como definidos (100% explorada).
- .text: undefined -> align (padding entre funções)
- dados (.rdata/.data/.rodata): undefined -> db (byte blobs em chunks de 16KB)
Roda no idat headless (sem timeout) ou via MCP (por segmento).
"""
import ida_auto
import ida_bytes
import ida_segment
import idc

CHUNK = 0x4000  # 16KB por blob


def make_align(start, end):
    """Marca [start,end) como align em chunks (só undefined)."""
    n = 0
    ea = start
    while ea < end:
        if ida_bytes.is_unknown(ida_bytes.get_flags(ea)):
            size = min(CHUNK, end - ea)
            if ida_bytes.create_align(ea, size, 0) != 0:
                n += 1
            ea += size
        else:
            ea += max(ida_bytes.get_item_size(ea), 1)
    return n


def make_data(start, end):
    """Marca [start,end) como db byte-a-byte (só undefined)."""
    n = 0
    ea = start
    while ea < end:
        if ida_bytes.is_unknown(ida_bytes.get_flags(ea)):
            if ida_bytes.create_data(ea, 0, 1, 0):
                n += 1
        ea += 1
    return n


def main(only_names=None):
    """only_names: opcional, lista de nomes de segmento para processar apenas esses."""
    ida_auto.auto_wait()
    total_marked = 0
    total_udb_before = 0
    qty = ida_segment.get_segm_qty()
    for i in range(qty):
        seg = ida_segment.getnseg(i)
        s = seg.start_ea
        e = seg.end_ea
        name = ida_segment.get_segm_name(seg) or "?"
        if only_names and name not in only_names:
            continue
        perm = seg.perm
        # conta undefined
        cur = ida_bytes.get_item_head(s)
        if cur == -1 or cur == 0xFFFFFFFFFFFFFFFF:
            n_before = e - s
        else:
            n_before = cur - s
            while cur < e:
                size = ida_bytes.get_item_size(cur)
                end_item = cur + size
                nxt = ida_bytes.next_head(cur, e)
                if nxt < 0 or nxt >= e or nxt == 0xFFFFFFFFFFFFFFFF:
                    n_before += e - end_item
                    break
                n_before += nxt - end_item
                cur = nxt
        total_udb_before += n_before
        if n_before == 0:
            continue
        is_code = bool(perm & 0x1)  # SEGPERM_X
        if is_code:
            marked = make_align(s, e)
        else:
            marked = make_data(s, e)
        total_marked += marked
        print(f"{name}: {n_before} unexplored -> {marked} items criados", flush=True)
    ida_auto.auto_wait()
    print(f"TOTAL: {total_udb_before} bytes unexplored marcados ({total_marked} items)", flush=True)
    print("100% EXPLORADA", flush=True)
    import ida_pro
    ida_pro.qexit(0)  # saida limpa: salva a db e encerra


if __name__ == "__main__":
    import sys
    only = sys.argv[1:] if len(sys.argv) > 1 else None
    main(only_names=only)
