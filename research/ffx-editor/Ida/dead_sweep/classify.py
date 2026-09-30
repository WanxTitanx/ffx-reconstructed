#!/usr/bin/env python3
"""classify.py — assign classes, build census + rename plan."""
import json, os, re
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
ENTRYPOINT = 0x9493C7

PS2 = re.compile(
    r"(SPU|Spu|Dma|DMA|Vif|VIF|GsPacket|_GS_|Gs_|GS_|Vu0|Vu1|VU|Iop|IOP|"
    r"Sif|SIF|Vram|VRAM|Clut|CLUT|Gif|GIF|Ps2|PS2|Tm2|TM2|Vsync|VSync)",
    re.I)
DBG = re.compile(r"(Debug|Dbg|Assert|Trace|Profile|Inspect)", re.I)


def name_class(n, addr):
    if 0x948D42 <= addr <= 0x94911A and n not in ("start",):
        return "win32-iat-thunk"
    if n.startswith("DEAD_"):
        return "pre-tagged"
    if n.startswith("__RTC_") or n in ("EncodePointer", "DecodePointer"):
        return "crt-rtc"
    if n.startswith(("nullsub_", "j_")):
        return "empty-stub" if n.startswith("nullsub_") else "dead-thunk"
    if n.startswith("unknown_libname"):
        return "crt-lib-orphan"
    if n.startswith(("__", "_get_", "_wcstoul", "_vacopy", "__vacopy",
                    "__getmbcp", "__cfltcvt", "__security")) or \
            n in ("_get_int_arg",) or n.startswith("_get_int_arg"):
        return "crt-lib"
    if n.startswith("??") or n.startswith("Std") or "Concurrency" in n \
            or n.startswith("?"):
        return "cpp-stl-conc"
    if n.startswith("SteamAPI_") or n.startswith("Steam"):
        return "steam-api"
    if n.startswith("Bullet_") or n.startswith("bt"):
        return "bullet-physics"
    if n.startswith("mkvparser_"):
        return "mkv-video-parser"
    if n.startswith(("FMOD_", "FFX_Fmod")):
        return "fmod-audio"
    if PS2.search(n):
        return "ps2-leftover"
    if DBG.search(n):
        return "debug-dev"
    if n.startswith(("Phyre", "PClass", "PCluster", "PShader", "PCaller",
                     "PMap", "PPost", "PtrAccessor", "CDefault",
                     "GetStaticSlot", "GetSizeArray", "PhyreCleanup",
                     "PStream", "PApplication")):
        return "phyre-middleware"
    if n.startswith(("FFX_", "Menu2D_", "Menu_", "Save_", "Abmap_",
                     "Ppp", "Heap", "ThreadPool", "ThreadWorkerPool",
                     "Engine_", "small_", "Get")):
        return "ffx-engine"
    if n.startswith("sub_"):
        return "unknown"
    return "other"


def main():
    funcs = json.load(open(f"{HERE}/funcs.json"))
    dead = {int(k): v for k, v in json.load(open(f"{HERE}/dead.json"))
            .items()}
    byaddr = {f["addr"]: f for f in funcs}

    # clusters on final dead set
    daddrs = sorted(dead)
    clusters, cur = [], [daddrs[0]]
    for a in daddrs[1:]:
        if a - (cur[-1] + byaddr[cur[-1]]["size"]) <= 0x80:
            cur.append(a)
        else:
            clusters.append(cur)
            cur = [a]
    clusters.append(cur)

    # class per func (name rule first)
    for a, v in dead.items():
        v["class"] = name_class(v["name"], a)

    # cluster context: homogeneous cluster => generic members inherit
    for c in clusters:
        cc = Counter(dead[a]["class"] for a in c)
        top, n_top = cc.most_common(1)[0]
        if n_top >= max(3, len(c) * 0.5) and top != "unknown":
            for a in c:
                if dead[a]["class"] in ("unknown", "other",
                                        "empty-stub", "dead-thunk",
                                        "crt-lib-orphan"):
                    dead[a]["class"] = top + "(cluster)"
    # attach cluster id
    for i, c in enumerate(clusters):
        for a in c:
            dead[a]["cluster"] = i

    json.dump({str(k): v for k, v in dead.items()},
              open(f"{HERE}/dead.json", "w"), indent=0)
    census = {"entrypoint": ENTRYPOINT, "total_funcs": len(funcs),
              "dead_count": len(dead),
              "funcs": {f"0x{a:x}": {"name": v["name"], "size": v["size"],
                                    "class": v["class"],
                                    "transitive": v.get("transitive",
                                                       False),
                                    "cluster": v.get("cluster")}
                        for a, v in dead.items()}}
    json.dump(census, open(f"{HERE}/dead_census.json", "w"), indent=1)

    cj = [{"id": i, "start": c[0], "end": c[-1] + byaddr[c[-1]]["size"],
           "n": len(c),
           "classes": Counter(dead[a]["class"] for a in c).most_common(4),
           "samples": [byaddr[x]["name"] for x in c[:8]]}
          for i, c in enumerate(clusters)]
    cj.sort(key=lambda c: -c["n"])
    json.dump(cj, open(f"{HERE}/clusters_final.json", "w"), indent=1)

    print("class distribution:")
    for k, v in Counter(x["class"] for x in dead.values()).most_common():
        print(f"  {v:6d}  {k}")
    print(f"\nclusters: {len(clusters)}, top 15:")
    for c in cj[:15]:
        print(f"  0x{c['start']:x}-0x{c['end']:x} n={c['n']} "
              f"{c['classes'][:2]} {c['samples'][:2]}")


if __name__ == "__main__":
    main()
