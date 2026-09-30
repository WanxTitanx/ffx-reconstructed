#!/usr/bin/env python3
# ── reqdyn_ev_bounds.py — writer value-domain bound of the REQ-path dynamic `ev` tail ──
#
# Lane: REQDYN-TAIL (wave-19, 2026-09-18). Stdlib only, no repo deps beyond the
# sibling tool it extends. Follow-up of reqpath_ev_audit.py (w18): bound the
# residual 1,499 dynamic-ev sites in 14 unique scripts.
#
# Method — for every REQ site whose ev is NOT a folded const:
#   1. Recover the structured producer of the ev stack slot:
#        arr:N     -> PUSHAR N (index operand sliced recursively)
#        var:N     -> PUSHV N
#        expr:OP*  -> binary/unary tree: collect const addend + leaf roots
#        indirect:call -> CALL/CALLPOPA funcId (resolved via atel_map.csv)
#   2. Writer slice: every POPAR/POPARL N (arrays) or POPV/POPVL N (vars) in the
#      SAME code region; per writer, slice the STORED-VALUE producer
#      (POPAR: depth1 = value, depth0 = index; POPV: depth0 = value) and the
#      writer-index producer. Writers are attributed to the worker whose EP
#      range contains them.
#   3. Source-var chase: writers whose value is `PUSHV m` recurse one level into
#      var[m]'s own writers (this is how `arr[N][k] = var[X] = CALL51(-1)-base`
#      resolves to the actor-index-delta pattern).
#   4. Domain synthesis per site: literal-domain if every writer stores const;
#      otherwise semantic class + numeric estimate vs file funcCount.
#
# Runtime facts used (decompile-verified this lane, FFX.exe):
#   * POPAR/PUSHAR element access is CLAMPED: ArrayElementAccessor @0x86C500
#     clamps idx to [0, elem_count-1] of the 8-byte var descriptor
#     {u32 addrDesc; u16 elem_count; u16 tag} read from the worker's var table
#     (script_header->offset_var_table, +0x14). No array OOB possible.
#   * Common[51] = FFX_FieldOp_PopGetActorIndex @0x85B920 (intret slot):
#     arg<0 -> *(u16*)(ctx+0x2E) = executing worker's bound actor index;
#     arg>=0 -> same field on AiScriptStateMachine(arg) (another worker).
#     ctx+0x2E is passed as the source-actor arg of QueuePriorityNodeIfAbsent
#     and to Link/StopAndUnbindTriggerNode -> "self actor index" (stable
#     binding, set at worker spawn — NOT the ScriptWorkerContext+0x2E pending-
#     target written by SW/EW queue ops; different struct).
#   * Common[201] = FFX_FieldOp_PopGetWordFrom86BFB0 @0x85B400 (floatret):
#     pops slot idx, returns u16 field +6 of Scene PObject slot (scene-object
#     event-id read, assigned at scene setup).
#   * CALL funcId: ns = fid>>12, idx = fid&0xFFF; entry = table + 16*idx.
#
# Outputs (docs/reverse/data/wave15/):
#   reqdyn_ev_sites.csv    one row per dynamic-ev REQ site
#   reqdyn_ev_writers.csv  one row per (consumed slot x writer)
#   reqdyn_ev_bounds.csv   per-site bound verdict (mission deliverable)
#   reqdyn_ev_summary.csv  per-script roll-up + corpus footer
#
# Usage:
#   reqdyn_ev_bounds.py [--root DIR] [--outdir DIR] [--files GLOB]
# ────────────────────────────────────────────────────────────────────────────
import argparse
import bisect
import collections
import csv
import glob
import os
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)
import reqpath_ev_audit as R            # noqa: E402  (sibling tool, unmodified)

ROOTS = ["/mnt/nvme-xpg/ffx_ps2/ffx/master",
         "/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master"]
CANON = ROOTS[0]
OUTDIR = os.path.join(_HERE, "..", "..",
                      "docs", "reverse", "data", "wave15")
ATEL_MAP = os.path.join(_HERE, "..", "..",
                        "docs", "reverse", "data", "wave12", "atel_map.csv")

REQ_ALL = R.REQ_ALL
POPAR, POPARL, POPV, POPVL = 0x23, 0x24, 0x20, 0x21
PUSHV, PUSHAR, PUSHARP = 0x1F, 0x22, 0x27
CALL, CALLPOPA = 0x35, 0x58
BINARY, UNARY = R.BINARY, R.UNARY

MAX_WRITER_WALK = 96        # writers can sit far from obvious anchors
LEAF_FUEL = 64

# funcspace table names (ns nibble) for call-leaf annotation
NS_NAMES = {0: "Common", 1: "Math", 4: "SgEvent", 5: "ChEvent", 6: "Camera",
            7: "Battle", 8: "Map", 9: "Mount", 0xB: "Movie", 0xC: "Debug",
            0xD: "AbiMap"}


def load_atel_map(path):
    """funcId -> 'Ns[idx] fnname' (any populated slot; prefer intret/call)."""
    m = {}
    if not os.path.isfile(path):
        return m
    for r in csv.DictReader(open(path, newline="")):
        try:
            fid = int(r["ct"], 16) | int(r["idx"])
        except Exception:
            continue
        name = (r.get("intret") or r.get("call") or r.get("floatret")
                or r.get("status") or "?")
        m[fid] = "%s[%s] %s" % (r["ns"], r["idx"], name)
    return m


class BoundSlice(R.Slice):
    """Slice + structured leaf-producer collection (non-destructive)."""

    def leaf(self, j, depth, out, fuel):
        """Collect terminal producer insns of slot `depth` before insn j.
        Appends (insn_index, kind) tuples: kind='insn' for real producers,
        'indirect:'/'unres:' for opaque ones."""
        if fuel[0] <= 0:
            out.append((-1, "fuel"))
            return
        fuel[0] -= 1
        kind, i = self._producer(j, depth)
        if kind != "found":
            # CALL/CALLPOPA producer: the call insn itself pushed the result
            # (intret/floatret slot) -> record the insn so fid is resolvable.
            if i >= 0 and kind in ("indirect:call", "indirect:callpopa"):
                out.append((i, "insn"))
            else:
                out.append((-1, kind))
            return
        addr, idx, operand = self.insns[i]
        if idx in BINARY:
            self.leaf(i, 1, out, fuel)
            self.leaf(i, 0, out, fuel)
            return
        if idx in UNARY or idx == 0x2B:          # unary / REPUSH
            self.leaf(i, 0, out, fuel)
            return
        out.append((i, "insn"))

    def leaves(self, j, depth):
        out = []
        self.leaf(j, depth, out, [LEAF_FUEL])
        return out

    def eval_f(self, j, depth):
        self.fuel = R.MAX_FUEL
        return self.eval(j, depth)


def insn_desc(insns, i):
    a, idx, op = insns[i]
    return "%s%s@0x%x" % (R.OP_NAMES[idx], "" if op is None else " %d" % op, a)


class FileCtx:
    """One parsed file: chunks, insns, workers, slice, worker-owner map."""

    def __init__(self, path):
        self.path = path
        self.b = open(path, "rb").read()
        self.chunks = []
        for tag, ch in R.chunks_in_file(path)[1]:
            self.chunks.append((tag, ch))
        self.max_fc = -1
        self.min_fc = -1
        self.tgt_widx = -1
        self.per = []          # per-chunk prepared state

    def prepare(self):
        for tag, ch in self.chunks:
            cs, ce = ch["code_span"]
            insns = R.decode(self.b, ch["base"], cs, ce)
            workers = ch["workers"]
            splits = {cs}
            ep_owner = {}
            for wi, w in enumerate(workers):
                for ep in w.get("entryPoints", []):
                    splits.add(cs + ep)
                    ep_owner.setdefault(cs + ep, wi)
                for lb in w.get("jumpLabels", []):
                    splits.add(cs + lb)
            addr_set = set(a for a, _, _ in insns)
            for k, (a, idx, operand) in enumerate(insns[:-1]):
                if idx in R.TERMINATOR:
                    splits.add(insns[k + 1][0])
            splits &= addr_set
            eps_sorted = sorted(ep_owner)

            def resolver(addr, _eps=eps_sorted, _own=ep_owner):
                i = bisect.bisect_right(_eps, addr) - 1
                return workers[_own[_eps[i]]] if i >= 0 else None

            sl = BoundSlice(insns, splits, resolver)
            idx_by_addr = {a: k for k, (a, _, _) in enumerate(insns)}
            ep_list = sorted(ep_owner.items())

            def owner(addr, _eps=ep_list):
                keys = [e for e, _ in _eps]
                i = bisect.bisect_right(keys, addr) - 1
                return _eps[i][1] if i >= 0 else -1

            # one-pass writer index: (kind,slot) -> [insn indices]
            windex = collections.defaultdict(list)
            for k, (a, idx, op) in enumerate(insns):
                if op is None:
                    continue
                if idx in (POPAR, POPARL):
                    windex[("arr", op)].append(k)
                elif idx in (POPV, POPVL):
                    windex[("var", op)].append(k)
            funcs = [w["funcCount"] for w in workers if not w["bad"]]
            self.per.append({
                "tag": tag, "insns": insns, "sl": sl, "splits": splits,
                "idx_by_addr": idx_by_addr, "owner": owner,
                "workers": workers, "funcs": funcs, "windex": windex})
            if funcs:
                fmax = max(funcs)
                if fmax > self.max_fc:
                    self.tgt_widx = funcs.index(fmax)
                self.max_fc = max(self.max_fc, fmax)
                self.min_fc = (min(funcs) if self.min_fc < 0
                               else min(self.min_fc, min(funcs)))

    # ── writer enumeration ────────────────────────────────────────────────
    def writers(self, p, slot_kind, slot):
        """All POPAR/POPARL slot (arr) or POPV/POPVL slot (var) sites."""
        return p["windex"].get((slot_kind, slot), [])


def leaf_key(insns, leaf):
    """Compact leaf descriptor for CSVs."""
    i, kind = leaf
    if i < 0:
        return "unres:" + kind
    a, idx, op = insns[i]
    nm = R.OP_NAMES[idx]
    if idx in (CALL, CALLPOPA):
        return ("call:%d" % op) if op is not None else "call:?"
    if idx == PUSHV:
        return "var:%d" % op
    if idx in (PUSHAR, PUSHARP):
        return "arr:%d" % op
    if idx in (0x2D, 0x2E):                       # PUSHI / PUSHII
        return "imm:%d" % (op if idx == 0x2E and op < 0x8000
                           else (op - 0x10000 if idx == 0x2E else op))
    return "op:%s" % nm


def call_leaf_fid(insns, leaf):
    i, kind = leaf
    if i < 0:
        return None
    _, idx, op = insns[i]
    return op if idx in (CALL, CALLPOPA) else None


def ev_structure(p, j):
    """Structured producer of ev (stack slot 0 before insn j).
    Returns dict: shape, addend (const int|None), roots [(kind,N)], leaf list,
    expr_desc."""
    sl = p["sl"]
    insns = p["insns"]
    res = sl.eval_f(j, 0)
    cls, val, desc = res
    out = {"shape": cls, "addend": None, "roots": [], "leaves": [],
           "expr_desc": desc}
    if cls == "const":
        out["shape"] = "const"
        out["addend"] = val
        return out
    if isinstance(val, str) and val.startswith("arr:"):
        n = int(val.split(":")[1])
        kind, i = sl._producer(j, 0)
        out["shape"] = "arr"
        out["roots"] = [("arr", n)]
        if kind == "found":
            out["index_leaves"] = sl.leaves(i, 0)
        return out
    if isinstance(val, str) and val.startswith("var:"):
        n = int(val.split(":")[1])
        out["shape"] = "var"
        out["roots"] = [("var", n)]
        return out
    if cls == "unres" and val == "start":
        out["shape"] = "unres-start"
        return out
    if cls == "unres" and str(val).startswith("indirect:call"):
        # ev popped straight from a native call result; recover funcId
        kind, i = sl._producer(j, 0)
        out["shape"] = "call"
        if kind == "indirect:call" and i >= 0 and \
                insns[i][1] in (CALL, CALLPOPA):
            out["roots"] = [("call", insns[i][2])]
            out["leaves"] = sl.leaves(i, 0)
            out["call_args"] = sl.leaves(i, 0)
        return out
    if val == "reqres" or val == "callres" or cls == "unres":
        out["shape"] = "opaque:" + str(val)
        return out
    if isinstance(val, str) and val.startswith("expr:"):
        # binary/unary expression: gather leaves + fold const addend
        kind, i = sl._producer(j, 0)
        out["shape"] = "expr"
        if kind == "found":
            a, idx, operand = insns[i]
            out["expr_op"] = R.OP_NAMES[idx]
            if idx in BINARY:
                ra = sl.eval_f(i, 1)
                rb = sl.eval_f(i, 0)
                for r in (ra, rb):
                    if r[0] == "const":
                        out["addend"] = (r[1] if out["addend"] is None
                                         else out["addend"] + r[1])
                lv = sl.leaves(i, 1) + sl.leaves(i, 0)
                out["leaves"] = lv
                for li, lk in lv:
                    if li < 0:
                        continue
                    a2, idx2, op2 = insns[li]
                    if idx2 == PUSHAR:
                        out["roots"].append(("arr", op2))
                        out.setdefault("arr_index", {})[op2] = sl.leaves(li, 0)
                    elif idx2 == PUSHV:
                        out["roots"].append(("var", op2))
                    elif idx2 in (CALL, CALLPOPA):
                        out["roots"].append(("call", op2))
            else:
                lv = sl.leaves(i, 0)
                out["leaves"] = lv
                for li, lk in lv:
                    if li < 0:
                        continue
                    a2, idx2, op2 = insns[li]
                    if idx2 == PUSHAR:
                        out["roots"].append(("arr", op2))
                        out.setdefault("arr_index", {})[op2] = sl.leaves(li, 0)
                    elif idx2 == PUSHV:
                        out["roots"].append(("var", op2))
                    elif idx2 in (CALL, CALLPOPA):
                        out["roots"].append(("call", op2))
        return out
    out["shape"] = "other:" + str(val)
    return out


def writer_value_class(p, wk):
    """Classify the stored-value producer of writer insn index wk.
    Returns (class, detail, const_or_None, extra_leaves)."""
    sl = p["sl"]
    insns = p["insns"]
    a, idx, op = insns[wk]
    if idx in (POPAR, POPARL):
        vdep, idep = 1, 0
    else:
        vdep, idep = 0, None
    v = sl.eval_f(wk, vdep)
    if idep is not None:
        iv = sl.eval_f(wk, idep)
        iresult = (iv[1] if iv[0] == "const" else
                   ("dyn:" + str(iv[1]) if iv[0] == "dyn"
                    else "unres:" + str(iv[1])))
    else:
        iresult = ""
    if v[0] == "const":
        return ("const", v[2], v[1], iresult, [])
    detail = v[2]
    if v[0] == "unres" and str(v[1]).startswith("indirect:call"):
        # eval() marks call results opaque, but _producer hands back the
        # call insn index: recover it so the funcId is resolvable.
        kind, i = sl._producer(wk, vdep)
        if i >= 0 and insns[i][1] in (CALL, CALLPOPA):
            return ("dyn:call", "CALL %d@0x%x" % (insns[i][2], insns[i][0]),
                    None, iresult, [(i, "insn")])
    leaves = sl.leaves(wk, vdep)
    cls = str(v[1])
    return ("dyn:" + (cls.split(":")[0] if v[0] == "dyn" else cls)
            if v[0] == "dyn" else "unres:" + str(v[1]),
            detail, None, iresult, leaves)


def var_source_domain(p, vslot, depth=0, seen=None):
    """Domain of var[vslot]: union of its writers' value classes.
    Returns (classes:set, consts:set, calls:set, leaves:set)."""
    seen = seen or set()
    if vslot in seen or depth > 2:
        return {"recurse"}, set(), set(), set()
    seen = seen | {vslot}
    classes, consts, calls, all_leaves = set(), set(), set(), set()
    for wk in p["windex"].get(("var", vslot), []):
        cls, detail, const, _ires, leaves = writer_value_class(p, wk)
        if const is not None:
            classes.add("const")
            consts.add(const)
        elif cls.startswith("dyn:var"):
            classes.add("var")
            # chase: which var? parse detail 'PUSHV m@..'
            src = None
            for li, lk in leaves:
                if li >= 0 and p["insns"][li][1] == PUSHV:
                    src = p["insns"][li][2]
            if src is not None:
                c2, k2, f2, l2 = var_source_domain(p, src, depth + 1, seen)
                classes |= c2
                consts |= k2
                calls |= f2
                all_leaves |= l2
        elif cls.startswith("dyn:call"):
            classes.add("call")
            for li, lk in leaves:
                fid = call_leaf_fid(p["insns"], (li, lk))
                if fid is not None:
                    calls.add(fid)
        elif cls.startswith("dyn:expr"):
            classes.add("expr")
            for li, lk in leaves:
                if li < 0:
                    all_leaves.add("unres:" + lk)
                    continue
                key = leaf_key(p["insns"], (li, lk))
                all_leaves.add(key)
                fid = call_leaf_fid(p["insns"], (li, lk))
                if fid is not None:
                    calls.add(fid)
                if key.startswith("var:"):
                    c2, k2, f2, l2 = var_source_domain(
                        p, int(key.split(":")[1]), depth + 1, seen)
                    classes |= c2
                    consts |= k2
                    calls |= f2
                    all_leaves |= l2
        elif cls.startswith("dyn:arr"):
            classes.add("arr-elem")
        else:
            classes.add(cls)
    return classes, consts, calls, all_leaves


def analyze(path, amap):
    fc = FileCtx(path)
    fc.prepare()
    site_rows = []
    writer_rows = []
    for p in fc.per:
        insns, sl = p["insns"], p["sl"]
        for j, (a, idx, operand) in enumerate(insns):
            if idx not in REQ_ALL:
                continue
            ev = sl.eval_f(j, 0)
            if ev[0] == "const":
                continue
            st = ev_structure(p, j)
            wowner = p["owner"](a)
            # ── writers per consumed root ────────────────────────────────
            roots = st["roots"] or [("?", -1)]
            dom_consts, dom_calls, dom_classes, dom_leaves = set(), set(), set(), set()
            n_writers = 0
            idx_descs = []
            for rk, rn in roots:
                if rk == "arr":
                    # index leaves of the consumed read
                    il = st.get("index_leaves") or (
                        st.get("arr_index", {}).get(rn) or [])
                    idx_descs.append("arr%d[%s]" % (
                        rn, ";".join(leaf_key(insns, l) for l in il) or "?"))
                    for wk in fc.writers(p, "arr", rn):
                        n_writers += 1
                        cls, detail, const, ires, leaves = \
                            writer_value_class(p, wk)
                        wk_addr = insns[wk][0]
                        writer_rows.append({
                            "file": path, "site": "0x%x" % a,
                            "slot": "arr:%d" % rn, "writer": "0x%x" % wk_addr,
                            "worker": p["owner"](wk_addr),
                            "value_class": cls, "value": const if const is not None else "",
                            "value_desc": detail[:80],
                            "writer_index": str(ires)[:40],
                            "consumer_worker": wowner})
                        if const is not None:
                            dom_consts.add(const)
                        else:
                            # chase var-sourced values / calls in leaves
                            for li, lk in leaves:
                                if li < 0:
                                    dom_leaves.add("unres:" + lk)
                                    continue
                                key = leaf_key(insns, (li, lk))
                                dom_leaves.add(key)
                                fid = call_leaf_fid(insns, (li, lk))
                                if fid is not None:
                                    dom_calls.add(fid)
                                if key.startswith("var:"):
                                    c2, k2, f2, l2 = var_source_domain(
                                        p, int(key.split(":")[1]))
                                    dom_classes |= c2
                                    dom_consts |= k2
                                    dom_calls |= f2
                                    dom_leaves |= l2
                            dom_classes.add(cls[4:] if cls.startswith('dyn:') else cls)
                elif rk == "var":
                    for wk in fc.writers(p, "var", rn):
                        n_writers += 1
                        cls, detail, const, ires, leaves = \
                            writer_value_class(p, wk)
                        wk_addr = insns[wk][0]
                        writer_rows.append({
                            "file": path, "site": "0x%x" % a,
                            "slot": "var:%d" % rn, "writer": "0x%x" % wk_addr,
                            "worker": p["owner"](wk_addr),
                            "value_class": cls, "value": const if const is not None else "",
                            "value_desc": detail[:80],
                            "writer_index": str(ires)[:40],
                            "consumer_worker": wowner})
                        if const is not None:
                            dom_consts.add(const)
                        else:
                            for li, lk in leaves:
                                if li < 0:
                                    dom_leaves.add("unres:" + lk)
                                    continue
                                key = leaf_key(insns, (li, lk))
                                dom_leaves.add(key)
                                fid = call_leaf_fid(insns, (li, lk))
                                if fid is not None:
                                    dom_calls.add(fid)
                                if key.startswith("var:"):
                                    c2, k2, f2, l2 = var_source_domain(
                                        p, int(key.split(":")[1]))
                                    dom_classes |= c2
                                    dom_consts |= k2
                                    dom_calls |= f2
                                    dom_leaves |= l2
                            dom_classes.add(cls[4:] if cls.startswith('dyn:') else cls)
                elif rk == "call":
                    dom_classes.add("call-result")
                    dom_calls.add(rn)
                    carg = st.get("call_args") or []
                    idx_descs.append("call%d[%s]" % (
                        rn, ";".join(leaf_key(insns, l) for l in carg)
                        or "?"))
            # ── domain classification ────────────────────────────────────
            add = st["addend"] or 0
            leafset = sorted(l for l in dom_leaves if not l.startswith("unres"))
            callnames = sorted(amap.get(f, "fid:0x%x" % f)
                               for f in dom_calls)
            if not dom_classes and not dom_leaves and not dom_calls:
                # all writers stored consts
                domain_kind = "literal"
                est = sorted(v + add for v in dom_consts)
                verdict = ("PROVEN" if est and max(est) <= fc.max_fc - 1
                           else "REFUTED" if est else "OPEN")
            elif (dom_classes <= {"expr", "call", "var", "const"}
                  and all(c == 51 for c in dom_calls)
                  and any(l.startswith("var:") or l.startswith("call")
                          for l in leafset)):
                domain_kind = "actor-index-delta"
                est = []
                verdict = "PARTIAL"
            elif dom_calls:
                domain_kind = "call-derived"
                est = []
                verdict = "PARTIAL"
            elif dom_consts and len(dom_classes) <= 1:
                domain_kind = "literal+dyn"
                est = sorted(v + add for v in dom_consts)
                verdict = "PARTIAL"
            else:
                domain_kind = "mixed"
                est = sorted(v + add for v in dom_consts)
                verdict = "PARTIAL" if (dom_consts or dom_calls) else "OPEN"
            site_rows.append({
                "locale": os.path.basename(os.path.dirname(
                    os.path.dirname(path))),
                "file": path, "chunk": p["tag"], "rel": "0x%x" % a,
                "op": R.OP_NAMES[idx], "worker": wowner,
                "shape": st["shape"],
                "addend": st["addend"] if st["addend"] is not None else "",
                "roots": ";".join("%s:%d" % r for r in roots),
                "index": "|".join(idx_descs)[:120],
                "n_writers": n_writers,
                "domain_kind": domain_kind,
                "literal_domain": ";".join(str(v) for v in est[:24]),
                "domain_calls": "|".join(callnames)[:160],
                "domain_leaves": "|".join(leafset)[:160],
                "min_ev": min(est) if est else "",
                "max_ev": max(est) if est else "",
                "max_fc": fc.max_fc,
                "ev_desc": ev[2][:120],
                "verdict": verdict})
    return site_rows, writer_rows, fc


def iter_target_files(roots, globpat):
    seen = set()
    for root in roots:
        if not os.path.isdir(root):
            continue
        for loc in sorted(os.listdir(root)):
            ld = os.path.join(root, loc)
            if not os.path.isdir(ld):
                continue
            for pat in globpat.split(","):
                for p in sorted(glob.glob(os.path.join(ld, pat),
                                          recursive=True)):
                    # dedupe by /master/-relative path (two corpus mounts
                    # carry identical trees under different prefixes)
                    key = (p.split("/master/")[-1] if "/master/" in p
                           else os.path.realpath(p))
                    if key in seen:
                        continue
                    seen.add(key)
                    yield p


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="REQ-path dynamic ev writer value-domain bound")
    ap.add_argument("--root", action="append", default=[])
    ap.add_argument("--outdir", default=OUTDIR)
    ap.add_argument("--files", default="**/*.ebp",
                    help="glob under each locale dir (default all .ebp)")
    ap.add_argument("--canonical-only", action="store_true", default=True)
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args(argv)
    roots = [r for r in (a.root or [CANON]) if os.path.isdir(r)]
    if not roots:
        print("no corpus root found")
        return 2

    amap = load_atel_map(ATEL_MAP)
    site_rows, writer_rows = [], []
    per_script = collections.defaultdict(lambda: collections.Counter())
    for path in iter_target_files(roots, a.files):
        try:
            srows, wrows, fc = analyze(path, amap)
        except Exception as e:
            print("ERR %s: %s" % (path, e))
            continue
        if not srows:
            continue
        site_rows += srows
        writer_rows += wrows
        base = os.path.basename(path)
        for r in srows:
            per_script[base]["sites"] += 1
            per_script[base][r["verdict"]] += 1
            per_script[base][r["domain_kind"]] += 1
        per_script[base]["writers"] += len(
            [w for w in wrows if w["file"] == path])
        per_script[base]["max_fc"] = fc.max_fc
        if a.verbose:
            print("%s: %d dyn-ev sites, %d writers" %
                  (base, len(srows), len(wrows)))

    os.makedirs(a.outdir, exist_ok=True)
    p1 = os.path.join(a.outdir, "reqdyn_ev_sites.csv")
    f1 = ["locale", "file", "chunk", "rel", "op", "worker", "shape",
          "addend", "roots", "index", "n_writers", "domain_kind",
          "literal_domain", "domain_calls", "domain_leaves",
          "min_ev", "max_ev", "max_fc", "ev_desc", "verdict"]
    with open(p1, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=f1)
        w.writeheader()
        for r in site_rows:
            w.writerow(r)

    p2 = os.path.join(a.outdir, "reqdyn_ev_writers.csv")
    f2 = ["file", "site", "slot", "writer", "worker", "consumer_worker",
          "value_class", "value", "value_desc", "writer_index"]
    with open(p2, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=f2)
        w.writeheader()
        for r in writer_rows:
            w.writerow(r)

    p3 = os.path.join(a.outdir, "reqdyn_ev_bounds.csv")
    f3 = ["site", "script", "producer_kind", "writer_count",
          "literal_domain", "min_ev", "max_ev", "max_fc", "verdict"]
    with open(p3, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=f3)
        w.writeheader()
        for r in site_rows:
            w.writerow({
                "site": "%s!%s" % (os.path.basename(r["file"]), r["rel"]),
                "script": os.path.basename(r["file"]),
                "producer_kind": "%s(%s)%s" % (
                    r["domain_kind"], r["roots"],
                    ("+" + str(r["addend"])) if r["addend"] != "" else ""),
                "writer_count": r["n_writers"],
                "literal_domain": r["literal_domain"],
                "min_ev": r["min_ev"], "max_ev": r["max_ev"],
                "max_fc": r["max_fc"], "verdict": r["verdict"]})

    p4 = os.path.join(a.outdir, "reqdyn_ev_summary.csv")
    with open(p4, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["script", "sites", "writers", "max_fc",
                    "PROVEN", "PARTIAL", "OPEN", "REFUTED", "domain_kinds"])
        for base in sorted(per_script):
            c = per_script[base]
            dk = ";".join("%s:%d" % (k, v) for k, v in c.items()
                          if k not in ("sites", "writers", "max_fc",
                                       "PROVEN", "PARTIAL", "OPEN",
                                       "REFUTED"))
            w.writerow([base, c["sites"], c["writers"], c["max_fc"],
                        c["PROVEN"], c["PARTIAL"], c["OPEN"], c["REFUTED"],
                        dk])
    print("dyn-ev sites: %d | writers: %d | scripts: %d"
          % (len(site_rows), len(writer_rows), len(per_script)))
    vc = collections.Counter(r["verdict"] for r in site_rows)
    print("verdicts:", dict(vc))
    print("wrote %s\nwrote %s\nwrote %s\nwrote %s" % (p1, p2, p3, p4))
    return 0


if __name__ == "__main__":
    sys.exit(main())
