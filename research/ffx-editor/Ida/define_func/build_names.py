#!/usr/bin/env python3
"""build_names.py — derive names for the newly-defined funcs.

For each new func [s,e): slice insns from chunk_disasm, extract call/jmp
targets, vtbl writes, string refs. Emit rename plan {addr, name, comment}.

Naming rules (honesty-tagged — these are sweep-defined, evidence varies):
  thunk (body ends in single far jmp / only jmp)  -> <TargetModule>_Tramp_<hex>
  vtbl write + jmp/retn (dtor/ctor shape)         -> <Class>_CtorDtor_<hex>
  FFX_/Phyre_/Engine_ callee majority             -> <Mod>_Loose_<hex>
  no evidence                                     -> FFX_Orp_<hex>
"""
import json, os, re
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
DATAM = lambda t: t.split(";")[0].strip().lower().startswith(
    ("dd ", "dw ", "db ", "dq ", "dt ", "align", "unicode"))

# insns per chunk
insn_by_addr = {}
for l in open(os.path.join(HERE, "chunk_disasm.jsonl")):
    for a, t in json.loads(l)["insns"]:
        insn_by_addr[a] = t

after = json.load(open(os.path.join(HERE, "funcs_after.json")))
before_addrs = {int(f["addr"], 16)
                for f in json.load(open(os.path.join(HERE, "funcs_fresh.json")))}
new_funcs = [f for f in after if int(f["addr"], 16) not in before_addrs]
print("new funcs:", len(new_funcs))

CALLRE = re.compile(r"(?:call|jmp)\s+(?:short\s+|near\s+ptr\s+)?"
                    r"(loc_\w+|locret_\w+|[0-9A-Fa-f]+h\b|"
                    r"[A-Za-z_?@$][\w?@$:.<>()'* ,]*)", re.I)
VTBL = re.compile(r"offset\s+(vtbl_\w+|g_vtable_\w+)", re.I)
STRRE = re.compile(r"offset\s+(a[A-Z]\w*|Format__\w*|s_\w+)", re.I)
GLOBRE = re.compile(r"(?:dword|byte|word) ptr (?:ds:)?(unk_\w+|FFX_\w+|g_\w+|"
                    r"save_ram_\w+|dword_\w+|flt_\w+)|"
                    r"\b(save_ram_\w+|unk_\w+|FFX_\w+)\b(?!\s*\()", re.I)


def profile(s, e):
    ins = [(a, insn_by_addr[a]) for a in sorted(insn_by_addr)
           if s <= a < e and a in insn_by_addr]
    code = [t.split(";")[0].strip() for a, t in ins if not DATAM(t)]
    callees, vtbls, strs, globs = [], [], [], []
    for t in code:
        for m in CALLRE.finditer(t):
            op = m.group(1).strip()
            if not op.startswith(("loc_", "locret_")) and not re.match(
                    r"^[0-9A-Fa-f]+h$", op):
                callees.append(op.split(";")[0].strip())
        for m in VTBL.finditer(t):
            vtbls.append(m.group(1))
        for m in STRRE.finditer(t):
            strs.append(m.group(1))
        for m in GLOBRE.finditer(t):
            globs.append(m.group(1) or m.group(2))
    return code, callees, vtbls, strs, globs


def module_of(name):
    for p in ("FFX_", "Phyre_", "Engine_", "Bullet_", "bt", "Fmod",
              "Steam_", "std_"):
        if name.startswith(p):
            if p == "FFX_":
                m = re.match(r"FFX_([A-Za-z0-9]+)", name)
                return "FFX_" + (m.group(1) if m else "Gen")
            return p.rstrip("_")
    return None


def main():
    used = set(f["name"] for f in after)
    plan = []
    stats = Counter()
    for f in new_funcs:
        s = int(f["addr"], 16); e = s + int(f["size"], 16)
        code, callees, vtbls, strs, globs = profile(s, e)
        nonterm = [t for t in code if t.split()[0] not in ("int3", "nop")]
        is_thunk = (nonterm and nonterm[-1].startswith("jmp")
                    and len(nonterm) <= 6)
        mod_votes = Counter(module_of(c) for c in callees)
        mod_votes.pop(None, None)
        top_mod = mod_votes.most_common(1)[0][0] if mod_votes else None
        cls = None
        if vtbls:
            m = re.match(r"(?:vtbl_|g_vtable_)(.+)", vtbls[0])
            cls = m.group(1)[:40] if m else vtbls[0][:40]
            cls = re.sub(r"[^A-Za-z0-9_]", "_", cls)
        hexs = f"{s:X}"
        if cls and len(nonterm) <= 6 and (
                "Destructor" in " ".join(callees) or any(
                    t.startswith("retn") for t in nonterm)):
            base = f"Phyre_{cls}_CtorDtor" if "Phyre" in vtbls[0] or \
                "PClassDesc" in vtbls[0] else f"{cls}_CtorDtor"
            kind = "ctordtor"
        elif is_thunk and callees:
            tgt = callees[-1].split("(")[0].strip()
            tgt = re.sub(r"[^A-Za-z0-9_]", "_", tgt)[:48]
            base = f"{tgt}_Tramp"
            kind = "thunk"
        elif top_mod:
            base = f"{top_mod}_Loose"
            kind = "loose"
        else:
            base = "FFX_Orp"
            kind = "orp"
        if base[0].isdigit():
            base = "_" + base
        name = f"{base}_{hexs}"
        i = 2
        while name in used:
            name = f"{base}_{hexs}_{i}"
            i += 1
        used.add(name)
        stats[kind] += 1
        # pre-existing real names (original binary labels like WakkYubisasi,
        # j_* thunks, nullsub_*) are kept — rename skipped, comment only
        orig = f["name"]
        keep = not orig.startswith("sub_")
        if keep:
            name = orig
            used.add(name)
        ev = []
        if callees:
            ev.append("calls:" + ",".join(list(dict.fromkeys(callees))[:8]))
        if vtbls:
            ev.append("vtbl:" + vtbls[0])
        if strs:
            ev.append("str:" + strs[0])
        if globs:
            ev.append("glob:" + ",".join(list(dict.fromkeys(globs))[:4]))
        cmt = ("DEFINE-FUNC-SWEEP leva9: orphan code block defined as function "
               "(was decoded code, 0 xrefs, not a func item). "
               + ("original-name-kept. " if keep else "")
               + " ".join(ev))[:240]
        plan.append({"addr": s, "name": name, "kind": kind, "size": e - s,
                     "comment": cmt, "rename": not keep})
    print(stats)
    json.dump(plan, open(os.path.join(HERE, "rename_plan.json"), "w"),
              indent=0)
    print("planned", len(plan))


if __name__ == "__main__":
    main()
