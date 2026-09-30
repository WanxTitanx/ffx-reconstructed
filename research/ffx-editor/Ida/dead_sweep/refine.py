#!/usr/bin/env python3
"""refine.py — ptr-check transitive candidates + dead-table-target pass.

1) The 71 transitive funcs got dead status w/o ptr scan -> verify.
2) ptr-kept funcs whose ONLY match sites are inside dead funcs' bodies
   (dead jump tables / immediates in dead code) -> transitive dead.
"""
import json, os, bisect, time
from mcpc import Ida

HERE = os.path.dirname(os.path.abspath(__file__))


def load(n):
    return json.load(open(f"{HERE}/{n}"))


def main():
    funcs = load("funcs.json")
    xrefs = load("xref.json")
    ptrs = load("ptr.json")
    dead = load("dead.json")            # {addr_str(int? -> see below)}
    # dead.json keys are python-int -> json str
    dead = {int(k): v for k, v in dead.items()}
    byaddr = {f["addr"]: f for f in funcs}
    starts = sorted(byaddr)

    def owner(a):
        i = bisect.bisect_right(starts, a) - 1
        return starts[i] if i >= 0 else None

    ida = Ida()

    # --- 1) ptr-scan transitive candidates not yet scanned ---
    trans = [a for a, v in dead.items()
             if v.get("transitive") and f"{a:x}" not in ptrs]
    print(f"transitive pending ptr-scan: {len(trans)}")
    B = 150
    for i in range(0, len(trans), B):
        batch = trans[i:i + B]
        pats = [f"{a & 0xff:02X} {(a >> 8) & 0xff:02X} "
                f"{(a >> 16) & 0xff:02X} {(a >> 24) & 0xff:02X}"
                for a in batch]
        r = ida.call("find_bytes", {"patterns": pats, "limit": 50})
        bypat = {}
        for item in r:
            a = int.from_bytes(bytes.fromhex(
                item["pattern"].replace(" ", "")), "little")
            bypat[a] = [int(m, 16) for m in item.get("matches", [])]
        for a in batch:
            ptrs[f"{a:x}"] = bypat.get(a, [])
        print(f"  scanned {i + len(batch)}/{len(trans)}", flush=True)

    # un-dead transitive that actually have ptr hits outside dead code
    revived = []
    for a, v in list(dead.items()):
        if not v.get("transitive"):
            continue
        ms = ptrs.get(f"{a:x}", [])
        live = [m for m in ms
                if not (owner(m) in dead and
                        seg_of(m) == ".text")]
        if live:
            v["transitive"] = False
            v["ptr_revived"] = live[:4]
            revived.append(a)
            del dead[a]
    print(f"revived (real ptr): {len(revived)}")

    # --- 2) ptr-kept funcs reachable only via dead code -> transitive ---
    added = 0
    for f in funcs:
        a = f["addr"]
        if a in dead:
            continue
        ms = ptrs.get(f"{a:x}")
        if not ms:
            continue  # either had xrefs, or zero-xref w/o ptrs already dead
        # only for funcs that were zero-xref + ptr-kept
        if xrefs.get(f"{a:x}", {}).get("n", 0) != 0:
            continue
        live = [m for m in ms
                if not (seg_of(m) == ".text" and owner(m) in dead)]
        if not live:
            dead[a] = {"name": f["name"], "size": f["size"], "class": "?",
                       "transitive": True, "deadptr_only": ms[:4]}
            added += 1
    print(f"dead-table-target transitive added: {added}")

    json.dump({str(k): v for k, v in dead.items()},
              open(f"{HERE}/dead.json", "w"), indent=0)
    json.dump(ptrs, open(f"{HERE}/ptr.json", "w"))
    print(f"final dead: {len(dead)}")


def seg_of(a):
    for n, s, e in [(".text", 0x401000, 0xB0C000), (".idata", 0xB0C000,
                    0xB0C8C0), (".rdata", 0xB0C8C0, 0xC0A000),
                    (".data", 0xC0A000, 0x25D7000),
                    (".rodata", 0x25D7000, 0x25D8000),
                    ("_RDATA", 0x25D8000, 0x25D9000)]:
        if s <= a < e:
            return n
    return "?"


if __name__ == "__main__":
    import bisect  # noqa
    main()
