#!/usr/bin/env python3
# ── reqdyn_domain.py — REQ-path dynamic `ev` DOMAIN bound (wave-20) ──────────
#
# Lane: REQDYN-DOMAIN (wave-20, 2026-09-18). Stdlib only. Extends the wave-19
# REQDYN-TAIL base (reqdyn_ev_bounds.py) — same sibling FileCtx/Slice engine —
# to answer the three residuals left PARTIAL after wave-19:
#
#   M1  Actor-index spread Δmax (family A — 722 sites):
#       The REQ dynamic `ev` is `base_table[IDX] + addend` where base_table is
#       a u8 EventData array (elem_count from the 8-byte descriptor hi u16) and
#       IDX is the *target actor's delta* (actor_idx - first_actor).  The
#       stored values in base_table are themselves actor deltas — each
#       participating worker computes `delta_i = Common[51](-1) - first_actor`
#       (Common[51] @0x85B920 returns the caller's bound actor index when the
#       arg is negative) and POPARs it into the table at some slot index.
#
#       KEY MEASUREMENT: the *number of distinct delta-writing workers* is the
#       authored actor-group size -> Δmax ~ (group_size - 1) (actors bind
#       ~consecutively).  ev <= Δmax + addend.  We compare the authored spread
#       (a) against the table elem_count (does the read index exceed the
#       authored range / hit the clamp-collision slot) and (b) against the
#       TARGET worker's funcCount (is epTable[ev] in range).  This refines the
#       wave-19 "bounded by clamp" verdict to "bounded by authored range".
#
#   M2  Scene-object +6 domain (family B — 3 sites):
#       ev = Common[201](slot) = *s16 field +6* of the 32-byte Scene PObject
#       record (FFX_Scene_GetPObjectSlotByIndex @0x86BFB0; movsx @0x85B418 —
#       SIGNED, so -1 -> 0xFFFF).  +6 = the object's authored event-id,
#       populated at scene load from map object-placement data.
#
#   M3  Target-worker epTable binding (all dynamic sites):
#       REQ queue ops pop THREE operands (decompile-verified):
#         req[4]=ev (1st popped), req[1]=dst_actor (2nd), req[3]=prio (3rd).
#       req[1] -> FFX_Field_AiScriptStateMachine -> node+12 = TARGET actor.
#       So REQs CAN cross-bind: ev indexes the funcTable of the worker bound
#       to the DST actor, not necessarily the caller's.  We classify each
#       site's dst producer: const actor / firstActor+offset (cross) / other.
#
# Runtime facts used (decompile-verified this lane, FFX.exe ffxoficial.i64):
#   * POPAR/PUSHAR idx clamped [0, elem_count-1] (var descriptor hi u16).
#   * REQ queue ops pop (ev,dst,prio):  QueueActorNodeType0 @0x8671D0 (ops
#     0x36,0x45-49), Type1 @0x867510 (0x37,0x4A-4E), Type2 @0x867370
#     (0x38,0x4F-53).  node+8=ev=req[4], node+12=dst=req[1], node+14=prio.
#   * epTable[ev] @0x869152 = *(*ActorByIndex+32) + *(ActorByIndex+4) + 4*ev
#     = funcTable of the worker bound to the DST actor (cross-bind bound).
#   * Var descriptor @ worker hdr +0x14 (varTableOff) .. +0x18 (intConstOff),
#     8 B each {u32 lo; u32 hi}:  lo[31:28]=type lo[27:25]=loc lo[23:0]=byteoff,
#     hi[15:0]=elem_count.  loc 6=EventData (script-wide), 3=Private.
#   * WORKER INDEX NOTE (reqpath_ev_audit.parse_chunk quirk): worker["idx"] is
#     a NESTED dict {idx:0,bad:True} — the real worker index is the LIST
#     POSITION (enumerate), which the offset table +0x38+4*pos also uses.
#
# Outputs (docs/reverse/data/wave15/):
#   reqdyn_domain_sites.csv   per-site ev/dst structure + verdict columns
#   reqdyn_domain_delta.csv   per-file Δ spread + elem_count + bound (M1)
#   reqdyn_domain_bind.csv    per-site dst classification (M3)
#   reqdyn_domain_summary.csv per-file roll-up + corpus footer
#
# Usage:
#   reqdyn_domain.py [--root DIR] [--outdir DIR] [--files GLOB] [--verbose]
# ────────────────────────────────────────────────────────────────────────────
import argparse
import bisect
import collections
import csv
import glob
import os
import struct
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, _HERE)
import reqpath_ev_audit as R            # noqa: E402  (sibling, unmodified)
import reqdyn_ev_bounds as RB           # noqa: E402  (wave-19 base, unmodified)

ROOTS = RB.ROOTS
OUTDIR = os.path.join(_HERE, "..", "..",
                      "docs", "reverse", "data", "wave15")
ATEL_MAP = RB.ATEL_MAP

REQ_ALL = R.REQ_ALL
POPAR, POPARL, POPV, POPVL = 0x23, 0x24, 0x20, 0x21
PUSHV, PUSHAR, PUSHARP = 0x1F, 0x22, 0x27
PUSHI, PUSHII = 0x2D, 0x2E
CALL, CALLPOPA = 0x35, 0x58
OPSUB = 0x15

LOCS = {0: "SaveData", 1: "Common", 2: "Data", 3: "Private",
        4: "Shared", 5: "IntReg", 6: "EventData"}
TYPES = {0: "u8", 1: "s8", 2: "u16", 3: "s16", 4: "u32", 5: "s32",
         6: "f32", 7: "b8"}


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


# ── var descriptor table ─────────────────────────────────────────────────────
def worker_var_table(b, base, wpos):
    """Var descriptors for worker at list-position wpos. Returns {slot:dict}."""
    wo = u32(b, base + 0x38 + 4 * wpos)
    if not (0x38 <= wo and base + wo + 0x34 <= len(b)):
        return {}
    d = base + wo
    vt, it = u32(b, d + 0x14), u32(b, d + 0x18)
    if not vt or it <= vt or base + it > len(b):
        return {}
    out = {}
    for k in range((it - vt) // 8):
        lo = u32(b, base + vt + 8 * k)
        hi = u32(b, base + vt + 8 * k + 4)
        out[k] = {"type": (lo >> 28) & 0xF, "loc": (lo >> 25) & 7,
                  "byteoff": lo & 0xFFFFFF, "elem": hi & 0xFFFF}
    return out


def expr_consts_and_leaves(p, j, depth):
    """Fold const addends + collect roots/leaves of a stack-slot producer."""
    sl, insns = p["sl"], p["insns"]
    out = {"const": 0, "has_const": False, "roots": [], "vars": set(),
           "calls": set(), "arr_index": {}, "opaque": []}
    res = sl.eval_f(j, depth)
    cls, val, desc = res
    if cls == "const":
        out["const"], out["has_const"], out["shape"] = val, True, "const"
        return out
    out["shape"] = str(val)
    out["desc"] = desc
    kind, i = sl._producer(j, depth)
    lv = []
    if isinstance(val, str) and val.startswith("expr:") and kind == "found":
        lv = sl.leaves(i, 1) + sl.leaves(i, 0)
    elif isinstance(val, str) and (val.startswith("arr:") or
                                 val.startswith("var:")) and kind == "found":
        lv = [(i, "insn")]
        if val.startswith("arr:"):
            out["arr_index"][int(val.split(":")[1])] = sl.leaves(i, 0)
    else:
        out["opaque"].append(str(val))
    for li, lk in lv:
        if li < 0:
            out["opaque"].append(lk)
            continue
        a2, idx2, op2 = insns[li]
        if idx2 == PUSHAR:
            out["roots"].append(("arr", op2))
            out["arr_index"][op2] = sl.leaves(li, 0)
        elif idx2 == PUSHV:
            out["roots"].append(("var", op2))
            out["vars"].add(op2)
        elif idx2 in (CALL, CALLPOPA):
            out["roots"].append(("call", op2))
            out["calls"].add(op2)
        elif idx2 == PUSHII:
            v = op2 if op2 < 0x8000 else op2 - 0x10000
            out["const"] += v
            out["has_const"] = True
    return out


def var_domain(p, vslot, insns, depth=0, seen=None):
    """Union of var[vslot] writers' value classes: consts, calls, leaf keys."""
    seen = seen or set()
    if vslot in seen or depth > 2:
        return set(), set(), set(), set()
    seen = seen | {vslot}
    consts, calls, leaves, classes = set(), set(), set(), set()
    for wk in p["windex"].get(("var", vslot), []):
        cls, detail, const, _ires, lvs = RB.writer_value_class(p, wk)
        classes.add(cls)
        if const is not None:
            consts.add(const)
            continue
        for li, lk in lvs:
            if li < 0:
                leaves.add("unres:" + lk)
                continue
            key = RB.leaf_key(insns, (li, lk))
            leaves.add(key)
            fid = RB.call_leaf_fid(insns, (li, lk))
            if fid is not None:
                calls.add(fid)
            if key.startswith("var:"):
                c2, k2, f2, l2 = var_domain(p, int(key.split(":")[1]),
                                            insns, depth + 1, seen)
                classes |= c2
                consts |= k2
                calls |= f2
                leaves |= l2
    return classes, consts, calls, leaves


def find_anchor_var(p, insns):
    """The 'first actor' anchor: a var POPV'd from CALL51(-1) that later appears
    as the subtracted operand of `CALL51(-1) - var` (the delta computation)."""
    call51_self = set()
    for k, (a, idx, op) in enumerate(insns):
        if idx in (POPV, POPVL) and op is not None:
            kind, i = p["sl"]._producer(k, 0)
            # a CALL-produced value yields kind='indirect:call' (i=call idx)
            if i >= 0 and insns[i][1] == CALL and insns[i][2] == 51:
                call51_self.add(op)
    subbed = set()
    for k, (a, idx, op) in enumerate(insns):
        if idx != OPSUB:
            continue
        for d in (0, 1):
            for li, lk in p["sl"].leaves(k, d):
                if li < 0 or insns[li][1] != PUSHV:
                    continue
                v = insns[li][2]
                if v not in call51_self:
                    continue
                for li2, lk2 in p["sl"].leaves(k, 1 - d):
                    if li2 >= 0 and insns[li2][1] == CALL \
                            and insns[li2][2] == 51:
                        subbed.add(v)
    anchor = sorted(subbed & call51_self)
    return anchor[0] if anchor else None


# arg counts for calls seen in REQ operand position (Common[201] slot getter
# and Common[51] actor getter both take 1 arg).  Default: 1.
CALL_ARGC = {201: 1, 51: 1}


def stack_operands(p, j, k=3, window=48):
    """Forward operand-stack simulation over insns[j-window:j]; returns the
    top-k producer descriptors at insn j (the REQ) as a list of insn indices /
    ('CALL',fid) / ('lit',val) tuples, top-of-stack last.  This bypasses the
    backward-eval limitation where a top-of-stack CALL hides depth>=1 slots.
    Seed placeholders absorb underflow when the window starts mid-expression."""
    insns = p["insns"]
    stack = [("seed", -1)] * (k + 6)
    for a, idx, op in insns[max(0, j - window):j]:
        ef = R.EFFECT.get(idx)
        if ef == 'V':
            pops, pushes = CALL_ARGC.get(op, 1), 1
        elif ef is None:
            pops, pushes = 0, 0
        else:
            pops, pushes = ef
        # REQ itself is at index j — excluded by slice [..:j]
        for _ in range(pops):
            if stack:
                stack.pop()
        for _ in range(pushes):
            if idx == PUSHII:
                stack.append(("lit", op if op < 0x8000 else op - 0x10000))
            elif idx == PUSHI:
                stack.append(("pushi", op))
            elif idx == PUSHV:
                stack.append(("var", op))
            elif idx in (PUSHAR, PUSHARP):
                stack.append(("arr", op))
            elif idx in (CALL, CALLPOPA):
                stack.append(("call", op))
            else:
                nm = R.OP_NAMES[idx] if idx < len(R.OP_NAMES) else idx
                stack.append(("op", nm, op))
    return stack[-k:]


def describe_stack_op(entry, p):
    """Compact descriptor for a stack entry."""
    tag = entry[0]
    if tag == "lit":
        return "lit:%d" % entry[1]
    if tag == "call":
        return "call:%s" % entry[1]
    if tag == "var":
        return "var:%d" % entry[1]
    if tag == "arr":
        return "arr:%d" % entry[1]
    if tag == "pushi":
        return "intconst:%d" % entry[1]
    if tag == "op":
        return "op:%s" % entry[1]
    return tag


def is_delta_value(p, wk, insns):
    """True if POPAR/POPV writer `wk` stores `CALL51 - <var>` (actor delta)."""
    lvs = p["sl"].leaves(wk, 1 if insns[wk][1] in (POPAR, POPARL) else 0)
    has_call51 = any(li >= 0 and insns[li][1] == CALL and insns[li][2] == 51
                     for li, lk in lvs)
    has_var = any(li >= 0 and insns[li][1] == PUSHV for li, lk in lvs)
    return has_call51 and has_var


def _stored_value_is_delta(p, wk, insns):
    """True if a POPAR/POPV writer stores a value that traces to Common[51]
    (actor index) — i.e. an actor-offset 'delta'.  The stored operand is a var
    whose own writer computed `CALL51(-1) - firstActor`; resolve via var_domain.
    Also catches a direct `CALL51 - var` expression."""
    if is_delta_value(p, wk, insns):
        return True
    cls, detail, const, ires, lvs = RB.writer_value_class(p, wk)
    for li, lk in lvs:
        if li < 0:
            continue
        key = RB.leaf_key(insns, (li, lk))
        if RB.call_leaf_fid(insns, (li, lk)) == 51:
            return True
        if key.startswith("var:"):
            vn = int(key.split(":")[1])
            c2, k2, f2, l2 = var_domain(p, vn, insns)
            if f2 & {51}:
                return True
    return False


def analyze(path, amap):
    fc = RB.FileCtx(path)
    fc.prepare()
    site_rows = []
    file_delta = {"file": path, "anchor_var": None, "delta_writers": set(),
                  "delta_vars": set(), "delta_workers": set(),
                  "tables": set(), "max_write_idx": -1,
                  "max_read_idx_elem": -1, "min_elem": None, "max_addend": 0,
                  "n_sites": 0, "cross": 0, "selfish": 0, "const_dst": 0,
                  "delta_fc_min": None, "delta_fc_max": None}
    for ci, p in enumerate(fc.per):
        insns, sl = p["insns"], p["sl"]
        base = fc.chunks[ci][1]["base"]
        vartabs = {wi: worker_var_table(fc.b, base, wi)
                   for wi in range(len(p["workers"]))}
        anchor = find_anchor_var(p, insns)
        if anchor is not None and file_delta["anchor_var"] is None:
            file_delta["anchor_var"] = anchor
        # ── pre-pass: participants per EventData delta table ────────────────
        # A 'participant' of table T is a worker that POPARs an actor-offset
        # delta (CALL51-derived) into T.  These workers are bound to the
        # consecutive actors firstActor+0.. firstActor+(N-1); they are exactly
        # the REQ dst candidates (dst = firstActor + idx).  Collect their
        # funcCounts so each site can bound the TARGET worker's epTable.
        tab_part = collections.defaultdict(set)
        for wk, (a2, i2, o2) in enumerate(insns):
            if i2 not in (POPAR, POPARL):
                continue
            if _stored_value_is_delta(p, wk, insns):
                ow = p["owner"](a2)
                if ow >= 0:
                    tab_part[o2].add(ow)
        for j, (a, idx, operand) in enumerate(insns):
            if idx not in REQ_ALL:
                continue
            ev = sl.eval_f(j, 0)
            if ev[0] == "const":
                continue
            file_delta["n_sites"] += 1
            wowner = p["owner"](a)
            evst = expr_consts_and_leaves(p, j, 0)
            # robust operand stack: [prio, dst, ev] (top-of-stack last)
            sops = stack_operands(p, j, 3)
            prio_e, dst_e, _ev_e = sops[0], sops[1], sops[2]
            prio = {"const": prio_e[1], "has_const": prio_e[0] == "lit"}
            dst_tag = dst_e[0]
            # base_table descriptors + read-index domain
            base_tabs = [n for k, n in evst["roots"] if k == "arr"]
            elems, idx_desc = [], []
            read_idx_max = -1
            for n in base_tabs:
                vt = vartabs.get(wowner, {}) or {}
                el = vt.get(n, {}).get("elem", -1)
                elems.append("%d:%d" % (n, el))
                if el >= 0:
                    file_delta["min_elem"] = el if \
                        file_delta["min_elem"] is None else \
                        min(file_delta["min_elem"], el)
                il = evst["arr_index"].get(n, [])
                for li, lk in il:
                    if li < 0:
                        continue
                    a2, i2, o2 = insns[li]
                    idx_desc.append("%s %s" % (R.OP_NAMES[i2], o2))
            # stored-value domain for consumed arrays (delta detection)
            stored_consts, stored_calls, delta_vars = set(), set(), set()
            n_wr, max_widx = 0, -1
            for n in base_tabs:
                for wk in fc.writers(p, "arr", n):
                    n_wr += 1
                    cls, detail, const, ires, lvs = \
                        RB.writer_value_class(p, wk)
                    # write index operand (numeric if literal)
                    iv = sl.eval_f(wk, 0)
                    if iv[0] == "const" and isinstance(iv[1], int):
                        max_widx = max(max_widx, iv[1])
                    if const is not None:
                        stored_consts.add(const)
                        continue
                    if is_delta_value(p, wk, insns):
                        file_delta["delta_writers"].add(p["owner"](
                            insns[wk][0]))
                    for li, lk in lvs:
                        if li < 0:
                            continue
                        key = RB.leaf_key(insns, (li, lk))
                        fid = RB.call_leaf_fid(insns, (li, lk))
                        if fid is not None:
                            stored_calls.add(fid)
                        if key.startswith("var:"):
                            vn = int(key.split(":")[1])
                            c2, k2, f2, l2 = var_domain(p, vn, insns)
                            stored_consts |= k2
                            stored_calls |= f2
                            if f2 & {51}:
                                delta_vars.add(vn)
                                file_delta["delta_vars"].add(vn)
                                # the worker that WRITES this delta var = a
                                # participating actor -> a candidate target
                                for wk2 in p["windex"].get(("var", vn), []):
                                    ow = p["owner"](insns[wk2][0])
                                    if ow >= 0:
                                        file_delta["delta_workers"].add(ow)
            file_delta["max_write_idx"] = max(file_delta["max_write_idx"],
                                              max_widx)
            file_delta["max_addend"] = max(file_delta["max_addend"],
                                           evst["const"])
            # dst classification (M3): the REQ's 2nd operand = TARGET actor.
            #   lit  -> a specific authored actor index (cross-bind)
            #   var/arr/op/call -> computed actor (e.g. firstActor+offset)
            # Every dynamic site pushes an explicit dst actor -> CROSS-BIND
            # unless it provably equals the caller's own bound actor index.
            if dst_tag == "lit":
                dst_cls = "const:%d" % dst_e[1]
                file_delta["const_dst"] += 1
            else:
                dst_cls = describe_stack_op(dst_e, p)
                file_delta["cross"] += 1
            # ── per-site verdict (M1 + M3) ──────────────────────────────────
            # The read table's 'participants' = the workers that wrote an
            # actor-offset delta into it; they bind to actors
            # firstActor+0 .. firstActor+(N-1) and ARE the dst candidates
            # (dst = firstActor + idx).  Stored values are actor offsets, so
            #   ev <= (N-1) + addend      [consecutive-actor authored range]
            # and every target's funcCount >= min(participant funcCounts).
            # SAFE iff the authored ev bound is below every participant's fc.
            part_workers = set()
            for n in base_tabs:
                part_workers |= tab_part.get(n, set())
            part_fcs = [p["workers"][wi]["funcCount"]
                        for wi in part_workers
                        if 0 <= wi < len(p["workers"])
                        and not p["workers"][wi]["bad"]]
            n_part = len(part_workers)
            pmin = min(part_fcs) if part_fcs else None
            pmax = max(part_fcs) if part_fcs else None
            addend = evst["const"] if evst["has_const"] else 0
            ev_e = sops[2]
            if base_tabs and n_part:
                ev_bound = (n_part - 1) + addend
                verdict = ("AUTHORED-SAFE" if pmin is not None
                           and ev_bound < pmin else "AUTHORED-PARTIAL")
            elif base_tabs:
                ev_bound, verdict = "", "ARR-NODELTA"
            elif ev_e[0] == "call" and ev_e[1] == 201:
                # Family B: ev = Common[201](slot) -> s16 field +6 of the
                # 32-byte Scene PObject record.  Domain not yet recovered.
                ev_bound, verdict = "", "SCENEOBJ-PARTIAL"
            elif ev_e[0] == "call":
                ev_bound, verdict = "", "CALL:%s" % ev_e[1]
            else:
                ev_bound, verdict = "", "NON-ARR"
            file_delta["tables"] |= set(base_tabs)
            site_rows.append({
                "file": path, "chunk": p["tag"], "rel": "0x%x" % a,
                "op": R.OP_NAMES[idx], "worker": wowner,
                "ev_desc": (ev[2] or "")[:70],
                "roots": ";".join("%s:%d" % r for r in evst["roots"]),
                "base_tabs": ";".join(str(t) for t in base_tabs),
                "elems": ";".join(elems),
                "read_idx": ";".join(idx_desc)[:60],
                "const_addend": evst["const"] if evst["has_const"] else "",
                "stored_consts": ";".join(str(c)
                                        for c in sorted(stored_consts)),
                "stored_calls": "|".join(
                    amap.get(f, "fid:0x%x" % f)
                    for f in sorted(stored_calls)),
                "delta_vars": ";".join(str(v) for v in sorted(delta_vars)),
                "n_arr_writers": n_wr, "max_write_idx": max_widx,
                "anchor_var": anchor if anchor is not None else "",
                "dst_cls": dst_cls,
                "prio": prio["const"] if prio["has_const"]
                else describe_stack_op(prio_e, p),
                "n_part": n_part, "part_fc_min": pmin, "part_fc_max": pmax,
                "ev_bound": ev_bound, "verdict": verdict,
                "max_fc": fc.max_fc})
    return site_rows, file_delta, fc


def iter_target_files(roots, globpat):
    seen = set()
    for root in roots:
        if not os.path.isdir(root):
            continue
        for loc in sorted(os.listdir(root)):
            ld = os.path.join(root, loc)
            if not os.path.isdir(ld):
                continue
            for p in sorted(glob.glob(os.path.join(ld, globpat),
                                      recursive=True)):
                key = os.path.realpath(p)
                if key not in seen:
                    seen.add(key)
                    yield p


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="REQ-path dynamic ev DOMAIN bound (wave-20)")
    ap.add_argument("--root", action="append", default=[])
    ap.add_argument("--outdir", default=OUTDIR)
    ap.add_argument("--files", default="**/*.ebp")
    ap.add_argument("--verbose", action="store_true")
    a = ap.parse_args(argv)
    roots = [r for r in (a.root or [RB.CANON]) if os.path.isdir(r)]
    if not roots:
        print("no corpus root found")
        return 2

    amap = RB.load_atel_map(ATEL_MAP)
    site_rows, delta_rows, bind_rows = [], [], []
    per_script = collections.defaultdict(lambda: collections.Counter())
    for path in iter_target_files(roots, a.files):
        try:
            srows, fdelta, fc = analyze(path, amap)
        except Exception as e:
            print("ERR %s: %s" % (path, e))
            continue
        if not srows:
            continue
        site_rows += srows
        base = os.path.basename(path)
        per_script[base]["sites"] += len(srows)
        # Δ spread metrics -> delta_rows (rolled up from per-site verdicts)
        group = len(fdelta["delta_workers"]) or len(fdelta["delta_vars"])
        vc = collections.Counter(r["verdict"] for r in srows)
        evbs = [r["ev_bound"] for r in srows if isinstance(r["ev_bound"], int)]
        pmins = [r["part_fc_min"] for r in srows
                 if isinstance(r["part_fc_min"], int)]
        nparts = [r["n_part"] for r in srows if r["n_part"]]
        g_fcs = []
        for p2 in fc.per:
            for wi in fdelta["delta_workers"]:
                if 0 <= wi < len(p2["workers"]) and \
                        not p2["workers"][wi]["bad"]:
                    g_fcs.append(p2["workers"][wi]["funcCount"])
        delta_rows.append({
            "file": base, "anchor_var": fdelta["anchor_var"],
            "n_sites": fdelta["n_sites"],
            "delta_workers": len(fdelta["delta_workers"]),
            "delta_vars": len(fdelta["delta_vars"]),
            "group_size": group,
            "min_elem": fdelta["min_elem"],
            "max_write_idx": fdelta["max_write_idx"],
            "max_addend": fdelta["max_addend"],
            "n_part_min": min(nparts) if nparts else "",
            "n_part_max": max(nparts) if nparts else "",
            "ev_bound_min": min(evbs) if evbs else "",
            "ev_bound_max": max(evbs) if evbs else "",
            "ev_bound_u8": 255 + fdelta["max_addend"],
            "part_fc_min": min(pmins) if pmins else "",
            "part_fc_max": max(pmins) if pmins else "",
            "grp_fc_min": min(g_fcs) if g_fcs else "",
            "grp_fc_max": max(g_fcs) if g_fcs else "",
            "cross": fdelta["cross"], "const_dst": fdelta["const_dst"],
            "verdict_counts": ";".join("%s:%d" % kv
                                       for kv in vc.most_common()),
            "file_verdict": ("SAFE" if vc and set(vc) <= {"AUTHORED-SAFE"}
                             else "/".join("%s=%d" % kv
                                           for kv in vc.most_common())),
            "max_fc": fc.max_fc, "min_fc": fc.min_fc})
        for r in srows:
            bind_rows.append({
                "file": base, "rel": r["rel"], "op": r["op"],
                "worker": r["worker"], "dst_cls": r["dst_cls"],
                "prio": r["prio"], "n_part": r["n_part"],
                "ev_bound": r["ev_bound"], "verdict": r["verdict"]})
        if a.verbose:
            print("%s: %d sites anchor=%s grp=%d min_elem=%s "
                  "maxWidx=%s addend=%s evB=%s..%s verdict=%s"
                  % (base, len(srows), fdelta["anchor_var"], group,
                     fdelta["min_elem"], fdelta["max_write_idx"],
                     fdelta["max_addend"],
                     min(evbs) if evbs else "", max(evbs) if evbs else "",
                     dict(vc)))

    os.makedirs(a.outdir, exist_ok=True)

    def dump(name, fields, rows):
        p = os.path.join(a.outdir, name)
        with open(p, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=fields)
            w.writeheader()
            for r in rows:
                w.writerow({k: r.get(k, "") for k in fields})
        print("wrote %s (%d rows)" % (p, len(rows)))

    dump("reqdyn_domain_sites.csv",
         ["file", "chunk", "rel", "op", "worker", "ev_desc", "roots",
          "base_tabs", "elems", "read_idx", "const_addend", "stored_consts",
          "stored_calls", "delta_vars", "n_arr_writers", "max_write_idx",
          "anchor_var", "dst_cls", "prio", "n_part", "part_fc_min",
          "part_fc_max", "ev_bound", "verdict", "max_fc"], site_rows)
    dump("reqdyn_domain_delta.csv",
         ["file", "anchor_var", "n_sites", "delta_workers", "delta_vars",
          "group_size", "min_elem", "max_write_idx", "max_addend",
          "n_part_min", "n_part_max", "ev_bound_min", "ev_bound_max",
          "ev_bound_u8", "part_fc_min", "part_fc_max", "grp_fc_min",
          "grp_fc_max", "cross", "const_dst", "verdict_counts",
          "file_verdict", "max_fc", "min_fc"],
         delta_rows)
    dump("reqdyn_domain_bind.csv",
         ["file", "rel", "op", "worker", "dst_cls", "prio", "n_part",
          "ev_bound", "verdict"],
         bind_rows)
    return 0


if __name__ == "__main__":
    sys.exit(main())
