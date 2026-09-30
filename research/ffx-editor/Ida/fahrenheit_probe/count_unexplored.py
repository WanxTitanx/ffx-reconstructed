#!/usr/bin/env python3
"""Conta bytes 'unexplored' (gaps entre itens definidos) por segmento."""
import ida_bytes
import ida_segment

BADADDR = -1


def main():
    total_udb = 0
    total_bytes = 0
    qty = ida_segment.get_segm_qty()
    for seg_idx in range(qty):
        seg = ida_segment.getnseg(seg_idx)
        if not seg:
            continue
        s = seg.start_ea
        e = seg.end_ea
        name = ida_segment.get_segm_name(seg) or "?"
        n_udb = 0
        cur = ida_bytes.get_item_head(s)
        if cur == BADADDR:
            n_udb = e - s
            total_udb += n_udb
            total_bytes += e - s
            pct = 100.0
            print(f"{name}: {n_udb} unexplored ({pct:.2f}%)", flush=True)
            continue
        n_udb = cur - s
        while cur < e:
            size = ida_bytes.get_item_size(cur)
            end_item = cur + size
            nxt = ida_bytes.next_head(cur, e)
            if nxt < 0 or nxt >= e or nxt == 0xFFFFFFFFFFFFFFFF:
                n_udb += e - end_item
                break
            n_udb += nxt - end_item
            cur = nxt
        total_udb += n_udb
        total_bytes += e - s
        pct = 100.0 * n_udb / (e - s) if e > s else 0
        if n_udb > 0:
            print(f"{name}: {n_udb} unexplored ({pct:.2f}%)", flush=True)
    print(f"TOTAL unexplored: {total_udb} / {total_bytes} bytes ({100.0*total_udb/max(total_bytes,1):.3f}%)", flush=True)
    import ida_pro
    ida_pro.qexit(0)


if __name__ == "__main__":
    main()



