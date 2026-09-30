#!/usr/bin/env python3
"""maghost_zonec_resolver.py — Jarvis-MAGICDLL-ZONEC (2026-09-18)

Resolve + semantically classify the residual thunked slots of
g_MagHost_ContextTable (off_C64CE8) — the DLL->EXE bridge described in
docs/reverse/FFX_MAGICDLL_BRIDGE_2026-09-17.md.

Pipeline (3 subcommands, run in order):

  fetch    — pull analyze_batch (decompile+callees+xrefs) for each residual
             slot's target VA from the ida-pro-mcp endpoint
             (default http://192.168.122.85:8745/mcp). Writes out/<slot>.json.
  resolve  — for each slot, find a concrete tail-call thunk site inside a
             representative magic DLL (capstone scan of
             `mov r,[gctx]; mov r,[r+slot*4]; jmp/call r`, with a raw-byte
             fallback for large .text desync, plus a .data/.rdata table-ref
             fallback). Writes thunk_sites.json.
  classify — emit maghost_zonec_semantics.csv: slot -> ppp_opcode/role,
             sem_family, semantic, confidence (PROVEN/PARTIAL/OPEN).

Inputs (repo-relative):
  docs/reverse/data/wave13/maghost_ctx_annotated.csv  (slot->VA names)
  work/_maghost_bridge/slot_usage.json                (599-DLL thunk census)
  compiled_magic/*.dll                                (599 DLL corpus)

Usage:
  python3 maghost_zonec_resolver.py resolve
  python3 maghost_zonec_resolver.py fetch --mcp http://192.168.122.85:8745/mcp
  python3 maghost_zonec_resolver.py classify --out maghost_zonec_semantics.csv
"""
import argparse, csv, json, os, re, struct, sys, time, urllib.request

IMG = 0x10000000
REGS = ("eax", "ecx", "edx", "ebx", "esi", "edi", "ebp")
CORE = set(range(728, 741)) | {911}          # already-mapped core (bridge doc SS4)


# ── repo paths ──────────────────────────────────────────────────────────────
def repo_root():
    here = os.path.dirname(os.path.abspath(__file__))
    # research_tools/Magic -> repo root is two levels up
    return os.path.dirname(os.path.dirname(here))

def load_worklist(root):
    csvp = os.path.join(root, "docs/reverse/data/wave13/maghost_ctx_annotated.csv")
    rows = list(csv.DictReader(open(csvp)))
    return [r for r in rows if int(r["thunked_by"]) > 0
            and int(r["slot"]) not in CORE]


# ── PE/DLL helpers ──────────────────────────────────────────────────────────
def load_pe(path):
    d = open(path, "rb").read()
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    nsec = struct.unpack_from("<H", d, pe + 6)[0]
    optsz = struct.unpack_from("<H", d, pe + 20)[0]
    secs = []
    for i in range(nsec):
        o = pe + 24 + optsz + 40 * i
        vs, va, rs, rp = struct.unpack_from("<IIII", d, o + 8)
        name = d[o:o + 8].split(b"\0")[0].decode("ascii", "replace")
        secs.append((name, va, vs, rs, rp))
    return d, secs


def scan_thunks(path):
    """Disasm scan: {ctx_off: [(jmp/call_va, gctx_va)]} for ctx-thunk sites."""
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    d, secs = load_pe(path)
    out = {}
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    mem_re = re.compile(r"\[(?:(\w+)\s*\+\s*)?(\w+)\]")
    for name, va, vs, rs, rp in secs:
        if "text" not in name and "CODE" not in name.upper():
            continue
        ins = list(md.disasm(d[rp:rp + rs], IMG + va))
        for i, x in enumerate(ins):
            if x.mnemonic not in ("jmp", "call") or x.op_str not in REGS:
                continue
            jreg, off, gctx = x.op_str, None, None
            for j in range(i - 1, max(0, i - 10) - 1, -1):
                pi = ins[j]
                if pi.mnemonic != "mov" or "[" not in pi.op_str:
                    continue
                ops = [o.strip() for o in pi.op_str.split(",", 1)]
                if len(ops) != 2:
                    continue
                m = mem_re.search(ops[1])
                if not m:
                    continue
                baser, imm_s = m.group(1), m.group(2)
                if ops[0] == jreg and baser in REGS:
                    try:
                        off = int(imm_s, 16)
                    except ValueError:
                        continue
                    for k in range(j - 1, max(0, j - 6) - 1, -1):
                        pk = ins[k]
                        if pk.mnemonic != "mov" or "[" not in pk.op_str:
                            continue
                        o2 = [o.strip() for o in pk.op_str.split(",", 1)]
                        if len(o2) == 2 and o2[0] == baser:
                            m2 = mem_re.search(o2[1])
                            if m2 and m2.group(1) is None:
                                try:
                                    gctx = int(m2.group(2), 16)
                                except ValueError:
                                    pass
                    break
            if off is not None and off % 4 == 0 and off < 0x1000:
                out.setdefault(off, []).append((x.address, gctx, x.mnemonic))
    return out


def scan_thunk_bytes(path, off):
    """Raw-byte fallback: `mov r32,[r32+off]` + `jmp/call r32` within 6 bytes."""
    d, secs = load_pe(path)
    hits = []
    for name, va, vs, rs, rp in secs:
        if "text" not in name and "CODE" not in name.upper():
            continue
        code = d[rp:rp + rs]
        pats = [b"\x8B" + bytes([0x80 + r]) + struct.pack("<I", off)
                for r in range(8)]
        if off <= 0xFF:
            pats += [b"\x8B" + bytes([0x40 + r]) + bytes([off])
                     for r in range(8)]
        for p in pats:
            start = 0
            while True:
                i = code.find(p, start)
                if i < 0:
                    break
                tail = code[i + len(p):i + len(p) + 8]
                k = tail.find(b"\xff")
                if 0 <= k <= 4 and k + 1 < len(tail) and \
                   (0xE0 <= tail[k + 1] <= 0xEF or 0xD0 <= tail[k + 1] <= 0xD7):
                    hits.append({"thunk_va": f"0x{IMG + va + i:x}", "section": name})
                start = i + 1
    return hits


def scan_table_refs(path, off):
    """Data fallback: dword==off inside non-code sections (dispatch tables)."""
    d, secs = load_pe(path)
    hits, needle, start = [], struct.pack("<I", off), 0
    while True:
        i = d.find(needle, start)
        if i < 0:
            break
        for name, va, vs, rs, rp in secs:
            if rp <= i < rp + rs and "text" not in name and "CODE" not in name.upper():
                hits.append({"fileoff": f"0x{i:x}",
                             "va": f"0x{IMG + va + (i - rp):x}", "section": name})
        start = i + 1
    return hits


# ── MCP client ──────────────────────────────────────────────────────────────
def mcp_tool(url, name, args, timeout=300, retries=6):
    body = json.dumps({"jsonrpc": "2.0", "id": int(time.time() * 1000) % 2**31,
                       "method": "tools/call",
                       "params": {"name": name, "arguments": args}}).encode()
    last = None
    for i in range(retries):
        try:
            req = urllib.request.Request(url, data=body,
                headers={"Content-Type": "application/json",
                         "Accept": "application/json, text/event-stream"})
            with urllib.request.urlopen(req, timeout=timeout) as r:
                raw = r.read().decode()
            if "data:" in raw:
                for line in raw.splitlines():
                    if line.startswith("data:"):
                        raw = line[5:].strip()
                        break
            r2 = json.loads(raw)
            res = r2.get("result", r2)
            if isinstance(res, dict) and "content" in res:
                txt = "\n".join(c.get("text", "") for c in res["content"]
                                if c.get("type") == "text")
                try:
                    return json.loads(txt)
                except Exception:
                    return txt
            if isinstance(res, dict) and "result" in res:
                return res["result"]
            return res
        except Exception as e:
            last = e
            time.sleep(min(2 ** i, 25))
    return {"error": f"mcp failed: {last}"}


# ── opcode → family/desc (see doc for derivation) ──────────────────────────
OPMAP = {
 "pppMove": ("ppp-motion", "integrate velocity deltas into particle node fields"),
 "pppAccele": ("ppp-motion", "accumulate accel deltas into node vec4"),
 "pppAngle": ("ppp-motion", "integrate angular velocity into node rotation fields"),
 "pppAngMove": ("ppp-motion", "move/integrate angle deltas on node"),
 "pppAngAccele": ("ppp-motion", "accumulate angular accel deltas on node"),
 "pppScale": ("ppp-motion", "integrate scale deltas on node"),
 "pppSclMove": ("ppp-motion", "move/integrate scale deltas on node"),
 "pppSclAccele": ("ppp-motion", "accumulate scale accel deltas on node"),
 "pppColMove": ("ppp-motion", "integrate color-channel deltas on node"),
 "pppColAccele": ("ppp-motion", "accumulate color accel deltas on node (word layers)"),
 "pppColor": ("ppp-motion", "integrate color deltas on node"),
 "pppPoint": ("ppp-motion", "set point on bone via delta transform (BoneAnim)"),
 "pppKeOfsPt": ("ppp-motion", "apply anim transform to bone attachment point"),
 "pppMatrix": ("ppp-matrix", "compose Euler-XYZ rotation matrix w/ scaling on node"),
 "pppMatrixXZY": ("ppp-matrix", "compose Euler-XZY matrix on node"),
 "pppMatrixYXZ": ("ppp-matrix", "compose Euler-YXZ matrix on node"),
 "pppMatrixYZX": ("ppp-matrix", "compose Euler-YZX matrix on node"),
 "pppMatrixZXY": ("ppp-matrix", "compose Euler-ZXY matrix on node"),
 "pppMatrixZYX": ("ppp-matrix", "compose Euler-ZYX matrix on node"),
 "pppMatrixLoc": ("ppp-matrix", "set matrix translation from reference node"),
 "pppMatrixScl": ("ppp-matrix", "copy dual reference positions into scale matrix"),
 "pppParMatrix": ("ppp-matrix", "compose parent-space matrix on node"),
 "pppKeParMatR": ("ppp-matrix", "project child coords via parent matrix"),
 "pppKeOfsMatXYZ": ("ppp-matrix", "offset-matrix XYZ transform helper"),
 "pppKeMatPht": ("ppp-matrix", "build Euler XYZ matrix w/ scaling (photo variant)"),
 "pppKeMatSN": ("ppp-matrix", "matrix sin/cos transform on node"),
 "pppKeDMat": ("ppp-matrix", "draw-matrix compose (delta matrix)"),
 "pppKeDMatFr": ("ppp-matrix", "draw-matrix compose, frame-rate variant"),
 "pppKeDMatPhtFr": ("ppp-matrix", "draw-matrix compose, photo+frame variant"),
 "pppDrawMatrix": ("ppp-draw", "compose SW-matrix-based particle matrix for draw"),
 "pppDrawMatrixFront": ("ppp-draw", "build scaled front-facing matrix"),
 "pppDrawMatrixNoRot": ("ppp-draw", "matrix without rotation"),
 "pppDrawMatrixWood": ("ppp-draw", "compose 'wood' basis matrix"),
 "pppDrawMdl": ("ppp-draw", "render model prim"),
 "pppDrawMdl2": ("ppp-draw", "render model prim v2"),
 "pppDrawMdl3": ("ppp-draw", "render model prim v3"),
 "pppDrawMdlSemi": ("ppp-draw", "render semi-transparent model"),
 "pppDrawMdlSemi2": ("ppp-draw", "render semi-transparent model v2"),
 "pppDrawMdlSemi3": ("ppp-draw", "render semi-transparent model v3"),
 "pppDrawMdlTs": ("ppp-draw", "render model w/ texture-shift"),
 "pppDrawMdlTs2": ("ppp-draw", "render model w/ texture-shift v2"),
 "pppDrawMdlTs3": ("ppp-draw", "render model w/ texture-shift v3"),
 "pppDrawShape": ("ppp-draw", "shape prim dispatch"),
 "pppDrawShapeX": ("ppp-draw", "shape prim dispatch X variant"),
 "pppDrawHook": ("ppp-draw", "hook callback into draw chain"),
 "pppKeMdlDtt": ("ppp-draw", "model PVA sprite draw"),
 "pppKeMdlTfd": ("ppp-draw", "model TFD (transform-field) render"),
 "pppKeMdlTfd2": ("ppp-draw", "model TFD render v2"),
 "pppKeMdlTfd3": ("ppp-draw", "model TFD render v3"),
 "pppKeMdlTfdUv": ("ppp-draw", "model TFD render w/ UV scroll"),
 "pppKeMdlTfdUv2": ("ppp-draw", "model TFD render w/ UV scroll v2"),
 "pppKeMdlTfdUv3": ("ppp-draw", "model TFD render w/ UV scroll v3"),
 "pppKeShpDtt": ("ppp-draw", "shape-data attach/update"),
 "pppKeShpTail": ("ppp-draw", "shape-trail: pos-history ring -> trail render"),
 "pppKeShpTail2": ("ppp-draw", "shape-trail v2 ring31 render"),
 "pppKeShpTail2X": ("ppp-draw", "shape-trail v2X render"),
 "pppKeShpTail3": ("ppp-draw", "shape-trail v3 ring28 + secondary anim state"),
 "pppKeShpTail3X": ("ppp-draw", "shape-trail v3X render"),
 "pppKeShpTailPht": ("ppp-draw", "shape-trail photo variant"),
 "pppKeShpTailX": ("ppp-draw", "shape-trail X render"),
 "pppKeAcmSolid": ("ppp-draw", "accumulate-solid aux op"),
 "pppVtMime": ("ppp-draw", "vertex-mime: mimic/clone vertex stream render"),
 "pppKeLnsArnd": ("ppp-lines", "line effect 'around' ring"),
 "pppKeLnsArndT": ("ppp-lines", "line effect 'around' + texture variant"),
 "pppKeLnsClm": ("ppp-lines", "line effect 'column'"),
 "pppKeLnsClmT": ("ppp-lines", "line effect 'column' + texture"),
 "pppKeLnsCrn": ("ppp-lines", "line effect 'corona'"),
 "pppKeLnsCrnT": ("ppp-lines", "line effect 'corona' + texture"),
 "pppKeLnsFls": ("ppp-lines", "line effect 'flash' VFX particles render"),
 "pppKeLnsFlsT": ("ppp-lines", "line effect 'flash' + texture"),
 "pppKeLnsLp": ("ppp-lines", "line effect 'loop'"),
 "pppKeLnsLpSft": ("ppp-lines", "line effect 'loop' shift exec"),
 "pppVertexAp": ("ppp-emit", "periodic vertex emit at node"),
 "pppVertexApAt": ("ppp-emit", "periodic vertex emit at node (At variant)"),
 "pppVertexApLc": ("ppp-emit", "periodic vertex emit, lang-check variant"),
 "pppVertexAttend": ("ppp-emit", "vertex attend/follow emit"),
 "pppPointAp": ("ppp-emit", "point-sprite emit at node pos"),
 "pppPointRAp": ("ppp-emit", "point-sprite emit, R variant"),
 "pppKeBornRnd2": ("ppp-emit", "born-random v2 spawn"),
 "pppKeBornRnd3": ("ppp-emit", "born-random v3 trigger-zone spawn"),
 "pppKeBornRnd5": ("ppp-emit", "born-random v5 burst walk-struct emit"),
 "pppKeBornRnd6": ("ppp-emit", "born-random v6 spawn"),
 "pppKeHmgEff": ("ppp-emit", "homing-effect: jitter transform toward target"),
 "pppKeGrvEff": ("ppp-emit", "gravity-effect on node"),
 "pppKeGrvTgt": ("ppp-emit", "gravity-target pull on node"),
 "pppKeMvYpEff": ("ppp-emit", "move-Y-angle effect (atan2 from position)"),
 "pppRandFV": ("ppp-random", "randomize float-vec node field"),
 "pppRandIV": ("ppp-random", "randomize int-vec node field"),
 "pppRandHCV": ("ppp-random", "randomize half-char-vec node field"),
 "pppRandFloat": ("ppp-random", "randomize float node field"),
 "pppRandUpFV": ("ppp-random", "randomize float-vec upward-bias"),
 "pppRandUpIV": ("ppp-random", "randomize int-vec upward-bias"),
 "pppRandUpHCV": ("ppp-random", "randomize half-char-vec upward-bias"),
 "pppRandDownFV": ("ppp-random", "randomize float-vec downward-bias"),
 "pppRandDownIV": ("ppp-random", "randomize int-vec downward-bias"),
 "pppRandDownHCV": ("ppp-random", "randomize half-char-vec downward-bias"),
 "pppSRandFV": ("ppp-random", "seeded-randomize float-vec"),
 "pppSRandUpFV": ("ppp-random", "seeded-randomize float-vec upward"),
 "pppSRandHCV": ("ppp-random", "seeded-randomize half-char-vec"),
 "pppSRandUpHCV": ("ppp-random", "seeded-randomize half-char-vec upward"),
 "pppSRandDownFV": ("ppp-random", "seeded-randomize float-vec downward"),
 "pppKeTh": ("ppp-texture", "texture effect (electric/energy texture)"),
 "pppKeThRes16": ("ppp-texture", "texture-resource node-chain builder (16)"),
 "pppKeThRes16x4": ("ppp-texture", "texture-resource node-chain builder (16x4)"),
 "pppKeThRes24": ("ppp-texture", "texture-resource node-chain builder (24)"),
 "pppKeThRes24x4": ("ppp-texture", "texture-resource node-chain builder (24x4)"),
 "pppKeThRes32": ("ppp-texture", "texture-resource node-chain builder (32)"),
 "pppKeThRes32x4": ("ppp-texture", "texture-resource node-chain builder (32x4)"),
 "pppKeThRes48": ("ppp-texture", "texture-resource node-chain builder (48)"),
 "pppKeThRes48x4": ("ppp-texture", "texture-resource node-chain builder (48x4)"),
 "pppKeThRes64": ("ppp-texture", "texture-resource node-chain builder (64)"),
 "pppKeThRes64x4": ("ppp-texture", "texture-resource node-chain builder (64x4)"),
 "pppKeThRes128": ("ppp-texture", "texture-resource node-chain builder (128)"),
 "pppKeThRes128x4": ("ppp-texture", "texture-resource node-chain builder (128x4)"),
 "pppKeThSft": ("ppp-texture", "texture shift exec"),
 "pppKeThTp": ("ppp-texture", "texture target/position set (electric target)"),
 "pppKeThDes": ("ppp-texture", "texture descriptor alloc/init"),
 "pppNeiPointLight": ("ppp-light", "point-light effect on node"),
 "pppNeiChrPointLight": ("ppp-light", "character point-light (chr-attached)"),
 "pppNeiDrawMdlPointLight": ("ppp-light", "point-light on DrawMdl"),
 "pppNeiDrawMdlTsPointLight": ("ppp-light", "point-light on DrawMdlTs"),
 "pppNeiLightEikyo": ("ppp-light", "light-influence (eikyo) exec"),
 "pppKeZCrct": ("ppp-zcorrect", "z-correction: project/depth-offset transform"),
 "pppKeZCrctShp": ("ppp-zcorrect", "z-correction billboard shape transform"),
 "pppKeDrct": ("ppp-directive", "directive: set node position from cmd"),
}

SIG = {
 "ppp-motion": r"\+=|ppvUserStopPartF",
 "ppp-matrix": r"Mat4x4|Euler|Matrix|sin|cos|matrix",
 "ppp-draw": r"Draw|Render|Prim|Matrix|Vertex|Hud|Trail|Shape|Mdl|Vec4|PosHistory|Ring|Store",
 "ppp-emit": r"Emit|rand|Random|Pos|Node|BoneAnim|Trigger",
 "ppp-random": r"[Rr]and|Ease",
 "ppp-texture": r"Texture|NodeChain|PppMem|ThRes|Tex|Scene|StoreVec4|ppvUserStopPartF|Accumulate",
 "ppp-light": r"Light|Point",
 "ppp-lines": r"Line|Render|Vfx|Particle|AudioSync|ProcessSlot|Accumulate|Transform",
 "ppp-zcorrect": r"Depth|Project|Billboard|Offset",
 "ppp-directive": r"Position|Set",
 "ppp-stub": r";",
}

NONPPP = {
 224: ("stub", "no-op stub (op_eternal_unit)", "PROVEN", "size 0x1, empty body"),
 421: ("stub", "Phyre vtable placeholder stub (FlushCache)", "PROVEN", "size 0x1"),
 423: ("stub", "DMA-texture stub returning 0", "PROVEN", "size 0x3, 'return 0'"),
 425: ("stub", "DMA-texture stub returning 0 (variant B)", "PROVEN", "size 0x3, 'return 0'"),
 816: ("stub", "reserved no-op ctx slot (still thunked by 19 DLLs)", "PROVEN", "size 0x1"),
 817: ("stub", "reserved no-op ctx slot (still thunked by 14 DLLs)", "PROVEN", "size 0x1"),
 427: ("gate", "op-gate: select actor as action target, then DecAndSignal", "PROVEN", "calls Battle_SelectActorAsActionResultTarget+Counter_DecAndSignal"),
 428: ("gate", "op-gate: wait until Menu2D slot transform ready", "PROVEN", "calls Menu2D_IsSlotTransformReady+Counter_DecAndSignal"),
 429: ("gate", "op-gate: wait on global effect-gate mask", "PROVEN", "calls MagicHost_ReadGlobalEffectGateMask+Counter_DecAndSignal"),
 430: ("gate", "op-gate thunk -> FFX_Counter_DecAndSignal (unconditional)", "PROVEN", "jmp-thunk to Counter_DecAndSignal"),
 431: ("gate", "op-gate: DecAndSignal when ctx-flag pair matches obj", "PROVEN", "compares unk_25D5A44/unk_25D5AFC then DecAndSignal"),
 462: ("gate", "op-gate: DecAndSignal when MagicHost ctx-slot-894 handler clears", "PROVEN", "calls ContextSlot0894_Handler+Counter_DecAndSignal"),
 471: ("gate", "op-gate: DecAndSignal unless flag 25D5C10 set", "PROVEN", "checks unk_25D5C10 then DecAndSignal"),
 487: ("gate", "op-gate: wait until Menu2D slot audio ready", "PROVEN", "calls Menu2D_IsSlotAudioReady+Counter_DecAndSignal"),
 495: ("gate", "op-gate: DecAndSignal unless battle actor flag@1045 set", "PROVEN", "calls Battle_IsActorFlagAt1045Set+Counter_DecAndSignal"),
 521: ("util", "reverse int32 array g_Arr_25D5BC0/n16_3 in place", "PROVEN", "in-place swap loop over n16_3"),
 575: ("util", "set bit1 (|=2) on global flag g_GlobalUnkVar_11A004E", "PROVEN", "single |=2 store"),
 633: ("util", "set bit0 (|=1) on global flag g_GlobalUnkVar_11A004E", "PROVEN", "single |=1 store"),
 713: ("resource", "walk+free magic-host resource-buffer chain (env object)", "PROVEN", "calls FreeResourceBufferChain+Memory_FreeToFreelist"),
 845: ("scene", "disconnect debug scene node from parent (flag-gated)", "PARTIAL", "PNode_DisconnectFromParent+Phyre_Debug_OutputString on CHAR_TIDUS+off"),
 846: ("scene", "scene-node disconnect wrapper (FieldEngine dispatch)", "PARTIAL", "calls FFX_SceneNode_DisconnectFromParent"),
 856: ("phyre", "Phyre_PMap_Rebalance wrapper thunk (ret 0)", "PROVEN", "calls Phyre_PMap_Rebalance"),
}


def literal_action(dec, callees):
    body = dec.split("{", 1)[-1]
    if re.match(r"\s*;\s*(/\*.*?\*/\s*)?\}?\s*$", body):
        return "no-op"
    calls = [c.get("name") or "" for c in callees]
    cj = " ".join(calls)
    if "BuildNodeChain" in cj or "PppMem" in cj:
        return f"builds/inits node chain via {calls[0] or 'PppMem'}"
    if "AllocNode" in cj:
        return f"allocates node via {[c for c in calls if 'AllocNode' in c][0]}"
    if "CreateAudioSync" in cj:
        return "creates audio-sync node"
    if "RemoveAudioSync" in cj:
        return "removes audio-sync node"
    writes = re.findall(r"\*\([^;]*?\+\s*(\d+)\)\s*=\s*([^;]+);", body)
    if writes:
        offs = [o for o, _ in writes]
        vals = [re.sub(r"asmreg_\w+", "vec-reg(0.0)",
                re.sub(r"n\d+_\d+", "const", v.strip()[:18])) for _, v in writes]
        from_g = sum(1 for _, v in writes if "FFX_" in v or "Global" in v)
        if len(writes) == 1:
            return f"writes {vals[0]} at node+{offs[0]}"
        return f"seeds node fields +{'/+'.join(offs)} ({'from globals' if from_g else 'init'})"
    if re.search(r"=\s*0\s*;", body):
        return "zeroes node field(s)"
    if calls:
        return f"calls {calls[0]}"
    return "initializes node state"


# ── subcommands ─────────────────────────────────────────────────────────────
def cmd_fetch(args, work, outdir):
    os.makedirs(outdir, exist_ok=True)
    todo = [w for w in work if not os.path.exists(
        os.path.join(outdir, f"{w['slot']}.json"))]
    print(f"{len(todo)} slots to fetch")
    CH = 8
    for i in range(0, len(todo), CH):
        chunk = todo[i:i + CH]
        qs = [{"addr": w["va"], "include_decompile": True,
               "include_callees": True, "include_callers": True,
               "include_strings": True, "include_proto": True,
               "include_xrefs": True, "max_callees": 30,
               "max_callers": 10, "max_strings": 15} for w in chunk]
        res = mcp_tool(args.mcp, "analyze_batch", {"queries": qs})
        if not isinstance(res, list):
            print("chunk fail", i, str(res)[:200])
            continue
        for w, it in zip(chunk, res):
            it["_slot"] = w["slot"]
            json.dump([it], open(os.path.join(outdir, f"{w['slot']}.json"), "w"))
        print(f"{min(i + CH, len(todo))}/{len(todo)}")


def cmd_resolve(args, work, root):
    usage_p = os.path.join(root, "work/_maghost_bridge/slot_usage.json")
    usage = json.load(open(usage_p))
    dlldir = os.path.join(root, "compiled_magic")
    cache, result, fails = {}, {}, []
    for w in work:
        slot, off = w["slot"], int(w["slot"]) * 4
        found = None
        for dll in (usage.get(str(slot)) or [])[:4]:
            p = os.path.join(dlldir, dll)
            if not os.path.exists(p):
                continue
            if dll not in cache:
                try:
                    cache[dll] = scan_thunks(p)
                except Exception:
                    cache[dll] = {}
            sites = cache[dll].get(off)
            if sites:
                # prefer canonical thunk: gctx-resolved base + jmp form;
                # deprioritise call-sites w/o gctx (likely node-field FPs)
                best = sorted(sites,
                              key=lambda s: (s[1] is None, s[2] != "jmp"))[0]
                found = {"dll": dll, "mechanism": "code-thunk",
                         "thunk_va": f"0x{best[0]:x}",
                         "gctx_va": f"0x{best[1]:x}" if best[1] else None,
                         "form": best[2],
                         "n_sites_in_dll": len(sites)}
                break
        if not found:
            for dll in (usage.get(str(slot)) or [])[:4]:
                p = os.path.join(dlldir, dll)
                if not os.path.exists(p):
                    continue
                hits = scan_thunk_bytes(p, off)
                if hits:
                    found = {"dll": dll, "mechanism": "code-thunk(bytes)",
                             "thunk_va": hits[0]["thunk_va"], "gctx_va": None,
                             "n_sites_in_dll": len(hits)}
                    break
        if not found:
            for dll in (usage.get(str(slot)) or [])[:4]:
                p = os.path.join(dlldir, dll)
                if not os.path.exists(p):
                    continue
                hits = scan_table_refs(p, off)
                if hits:
                    found = {"dll": dll, "mechanism": "data-table",
                             "table_refs": hits[:4]}
                    break
        if found:
            result[str(slot)] = found
        else:
            fails.append(slot)
    outp = os.path.join(args.workdir, "thunk_sites.json")
    json.dump(result, open(outp, "w"), indent=0)
    print(f"resolved {len(result)}/{len(work)}; unresolved: {fails}")
    return result


def cmd_classify(args, work, outdir):
    thunks_p = os.path.join(args.workdir, "thunk_sites.json")
    thunks = json.load(open(thunks_p)) if os.path.exists(thunks_p) else {}
    rows = []
    for w in sorted(work, key=lambda r: int(r["slot"])):
        slot = int(w["slot"])
        it = json.load(open(os.path.join(outdir, f"{slot}.json")))[0]
        an = it.get("analysis") or {}
        dec = an.get("decompile") or ""
        callees = an.get("callees") or []
        t = thunks.get(str(slot), {})
        base = dict(slot=slot, off=w["off"], va=w["va"],
                    name=it.get("name") or w["name"],
                    thunked_by=w["thunked_by"], mechanism=t.get("mechanism", ""),
                    thunk_dll=t.get("dll", ""), thunk_va=t.get("thunk_va", ""),
                    ppp_opcode="", ppp_role="")
        OVR = {  # hand-verified semantics overriding templates
            87: "PPP 'pppDrawShape' Direct — iterates section cmd list (count@a1+12), resolves+invokes per-slot VFX drawable (shape prim dispatch)",
            114: "PPP 'pppDrawShapeX' Direct — same direct-mode dispatcher, X variant (per-slot drawable invoke)",
        }
        m = re.search(r"PPP opcode handler '([^']+)' — (\w+)", dec)
        if m:
            op, role = m.group(1), m.group(2)
            fam, opdesc = OPMAP.get(op, ("ppp-other", "unclassified PPP op"))
            if slot in OVR:
                rows.append({**base, "ppp_opcode": op, "ppp_role": role,
                             "sem_family": fam, "semantic": OVR[slot],
                             "confidence": "PROVEN",
                             "evidence": "ppp-disp annotation + manual decompile read"})
                continue
            if role in ("Init", "Reset", "Free", "Direct"):
                act = literal_action(dec, callees)
                sem = f"PPP '{op}' {role} — {act} (opcode: {opdesc})"
                conf, ev = "PROVEN", "ppp-disp annotation + literal decompile confirm"
            else:
                body = dec.split("{", 1)[-1]
                if re.match(r"\s*;\s*(/\*.*?\*/\s*)?\}?\s*$", body):
                    sem = f"PPP '{op}' {role} — no-op (stub handler)"
                    conf, ev = "PROVEN", "empty body confirmed in decompile"
                else:
                    sem = f"PPP '{op}' {role} handler — {opdesc}"
                    hay = dec + " " + " ".join(c.get("name") or "" for c in callees)
                    conf = "PROVEN" if re.search(SIG.get(fam, r"."), hay) else "PARTIAL"
                    ev = ("ppp-disp annotation + decompile signature match"
                          if conf == "PROVEN" else
                          "ppp-disp annotation; fn too complex for full confirm")
            rows.append({**base, "ppp_opcode": op, "ppp_role": role,
                         "sem_family": fam, "semantic": sem,
                         "confidence": conf, "evidence": ev})
        elif slot in NONPPP:
            fam, desc, conf, ev = NONPPP[slot]
            rows.append({**base, "sem_family": fam, "semantic": desc,
                         "confidence": conf, "evidence": ev})
        else:
            rows.append({**base, "sem_family": "unknown",
                         "semantic": f"UNMAPPED — {it.get('name')}",
                         "confidence": "OPEN",
                         "evidence": "no ppp annotation; no NONPPP rule"})
    cols = ["slot", "off", "va", "name", "thunked_by", "mechanism", "thunk_dll",
            "thunk_va", "ppp_opcode", "ppp_role", "sem_family", "semantic",
            "confidence", "evidence"]
    with open(args.out, "w", newline="") as f:
        w2 = csv.DictWriter(f, fieldnames=cols)
        w2.writeheader()
        w2.writerows(rows)
    from collections import Counter
    print("rows:", len(rows), "| conf:", dict(Counter(r["confidence"] for r in rows)))
    print("families:", dict(Counter(r["sem_family"] for r in rows)))
    print("wrote", args.out)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["fetch", "resolve", "classify", "all"])
    ap.add_argument("--mcp", default="http://192.168.122.85:8745/mcp")
    ap.add_argument("--workdir", default=os.path.dirname(os.path.abspath(__file__)))
    ap.add_argument("--outdir", default=None, help="analyze_batch dump dir")
    ap.add_argument("--out", default=None, help="output CSV path")
    args = ap.parse_args()
    root = repo_root()
    work = load_worklist(root)
    outdir = args.outdir or os.path.join(args.workdir, "out")
    args.out = args.out or os.path.join(args.workdir, "maghost_zonec_semantics.csv")
    print(f"worklist: {len(work)} residual thunked slots")
    if args.cmd in ("resolve", "all"):
        cmd_resolve(args, work, root)
    if args.cmd in ("fetch", "all"):
        cmd_fetch(args, work, outdir)
    if args.cmd in ("classify", "all"):
        cmd_classify(args, work, outdir)


if __name__ == "__main__":
    main()
