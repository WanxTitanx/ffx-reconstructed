#!/usr/bin/env python3
"""breq_dll_probe.py — file-side sweep of FFX/FFX-2 ``magic_*.dll`` modules for
evidence that any shipped DLL can arm the ``AtelCurCtrlWork[+0x60]`` B-REQ veto
hook (see docs/reverse/FFX_EVENTVM_BPREFIX_2026-09-18.md — +0x60 is the no-arg
admission predicate consulted by REQ handlers only for B-family ops
0x47-49 / 0x4C-4E / 0x51-53; stock = FFX_Const_Return1 @0x86C450, installed
only-if-null @0x8711A0 after zero-init @0x86EE78; zero non-default writers in
the main exe).

Lane: Jarvis-BREQ-STORE (wave-16). Research-only, stdlib-only, read-only.

Method (what can prove/disprove arming file-side)
-------------------------------------------------
A magic DLL is a Phyre PRX plugin: it imports only CRT/KERNEL32, exports
``InitMagicPRX``/``GetEffectOverlayTable``, and talks to the host through a
frozen-ABI context table (thunk ``mov eax,[g_ctx]; mov eax,[eax+off]; jmp
eax``). It therefore has exactly three ways to write ``ctrl+0x60``:

  1. hardcode the exe VAs ``0x01326AE8``/``0x01325B60(+slot*0x238)`` — caught by
     *operand-verified* dword scan of ``.text`` (a ctrl-space dword counts only
     when preceded by a real mem32/disp32 opcode form — random blob bytes in the
     huge ``.data`` effect resource are rejected, see smoke-test notes);
  2. ``mov dword [reg+0x60], imm32`` where imm32 is a DLL-local VA = install a
     DLL function as the predicate (THE arm signature — ``store60_imm_self``);
  3. ``mov [reg+0x60], reg`` on a controller-derived pointer — counted as
     ``store60_reg_nonstack`` (noise-prone: +0x60 is a common struct offset;
     stack-base forms esp/ebp excluded). Without (1) or (2) it is not
     actionable but reported for completeness.

Exact-anchor dwords are also searched in ``.rdata``/``.data`` (pointer-table
installs) but reported separately — blob coincidence is possible there.

Verdicts: HIT = operand-verified exe-space ref or self-VA +0x60 store or
hooking string; REVIEW = weak signals only (non-stack +0x60 reg store, data
exact-anchor, unexplained abs-load); CLEAN otherwise.

Usage:
  python3 research_tools/Ps2/breq_dll_probe.py <root> [<root>...] --csv out.csv
"""

from __future__ import annotations

import argparse
import csv
import os
import re
import struct
import sys

# ---------------------------------------------------------------------------
# Canonical FFX.exe anchors (IDB C:\IDA_DB\ffxoficial.exe.i64, imagebase 0x400000)
# ---------------------------------------------------------------------------

ATEL_CUR_CTRL_WORK = 0x01326AE8          # dword ptr -> active controller record
CONTROLLERS_BASE = 0x01325B60            # Controllers[7] x 0x238
CTRL_STRIDE = 0x238
CTRL_COUNT = 7
CONTROLLERS_END = CONTROLLERS_BASE + CTRL_STRIDE * CTRL_COUNT   # 0x01326B58

FFX_CONST_RETURN1 = 0x0086C450           # stock predicate (mov eax,1; retn)
GATE_SITES = (0x008671F0, 0x00867390, 0x00867530)   # call [ctrl+0x60] sites
INSTALL_SITE = 0x008711A0                # default-install mov [esi+60h], off
ZEROINIT_SITE = 0x0086EE78               # zero-init of +0x58/+0x5C/+0x60 block
PREDICATE_MODEL = 0x0086BA70             # FFX_Field_CheckEncounterAllowed

# FFX.exe image: imagebase 0x400000, PE ~10.7 MB -> image spans ~0x401000-0xE4xxxx.
# Everything below 0x10000000 (default DLL base of the magic modules) that is
# not the exe image is module/heap space — NOT an exe reference.
EXE_ABS_LO = 0x00400000                  # exe image low
EXE_ABS_HI = 0x00F00000                  # exe image high (generous: ~15 MB)

# String needles — deliberately specific (generic "Atel"/"debug"/"hook" drowned
# in CRT import names like _crt_debugger_hook on the smoke test).
STRING_NEEDLES = (
    b"AtelCurCtrlWork", b"Controllers", b"BREQ", b"BFREQ", b"BTREQ",
    b"veto", b"FFX.exe", b"ffxoficial", b"WriteProcessMemory",
    b"VirtualProtect", b"ReadProcessMemory", b"CheatEngine", b"Cheat Engine",
    b"GetModuleHandleA", b"GetModuleHandleW",
)
HOOKING_NEEDLES = {n.lower() for n in (
    "AtelCurCtrlWork", "Controllers", "BREQ", "BFREQ", "BTREQ", "veto",
    "WriteProcessMemory", "VirtualProtect", "ReadProcessMemory",
    "CheatEngine", "Cheat Engine", "GetModuleHandleA", "GetModuleHandleW",
)}

# Opcodes that legitimately precede a disp32/abs32 operand when the operand
# dword starts at pos (modrm at pos-1 ∈ {05,0D,15,1D,25,2D,35,3D}).
# NOTE: 05/0D/15/1D/25/2D/35/3D are ALSO accumulator-imm32 opcodes — ambiguity
# resolved by the caller (mem-op subset vs any modrm-capable opcode).
_OPCODE_PREFIX = {
    0x88, 0x89, 0x8A, 0x8B,          # mov r/m<->r
    0xC6, 0xC7,                      # mov r/m, imm
    0xF6, 0xF7,                      # test/not/neg/mul/div grp
    0xFE, 0xFF,                      # inc/dec/call/jmp/push grp
    0x80, 0x81, 0x83,                # alu grp imm
    0x00, 0x01, 0x02, 0x03,          # add/or/adc/sbb/and/sub/xor/cmp r forms
    0x08, 0x09, 0x0A, 0x0B,
    0x10, 0x11, 0x12, 0x13,
    0x18, 0x19, 0x1A, 0x1B,
    0x20, 0x21, 0x22, 0x23,
    0x28, 0x29, 0x2A, 0x2B,
    0x30, 0x31, 0x32, 0x33,
    0x38, 0x39, 0x3A, 0x3B,
    0x85, 0x87,                      # test/xchg
    0x8F,                            # pop r/m
    0x69, 0x6B,                      # imul
    0xC0, 0xC1, 0xD0, 0xD1, 0xD2, 0xD3,   # shifts
    0x62,                            # bound (rare)
    0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,  # x87 mem forms
    0x0F,                            # two-byte escape (modrm follows opcode)
}


# ---------------------------------------------------------------------------
# Minimal PE reader
# ---------------------------------------------------------------------------

class PeInfo:
    __slots__ = ("ok", "machine", "nsec", "imagebase", "opt_magic",
                 "size_of_image", "sections", "export_names", "import_dlls",
                 "import_names", "export_dir", "import_dir")

    def __init__(self) -> None:
        self.ok = False
        self.machine = 0
        self.nsec = 0
        self.imagebase = 0
        self.opt_magic = 0
        self.size_of_image = 0
        self.sections = []          # (name, va, vsize, raw_off, raw_size)
        self.export_names = []
        self.import_dlls = []
        self.import_names = []


def parse_pe(d: bytes) -> PeInfo:
    info = PeInfo()
    if len(d) < 0x40 or d[:2] != b"MZ":
        return info
    pe = struct.unpack_from("<I", d, 0x3C)[0]
    if pe + 24 > len(d) or d[pe:pe + 4] != b"PE\0\0":
        return info
    (info.machine, info.nsec, _ts, _psym, _nsym, optsz, _chars) = \
        struct.unpack_from("<HHIIIHH", d, pe + 4)
    opt = pe + 24
    info.opt_magic = struct.unpack_from("<H", d, opt)[0]
    if info.opt_magic == 0x10B:
        info.imagebase = struct.unpack_from("<I", d, opt + 28)[0]
        info.size_of_image = struct.unpack_from("<I", d, opt + 56)[0]
        dd = opt + 96
    elif info.opt_magic == 0x20B:
        info.imagebase = struct.unpack_from("<Q", d, opt + 24)[0]
        info.size_of_image = struct.unpack_from("<I", d, opt + 56)[0]
        dd = opt + 112
    else:
        return info
    export_dir = struct.unpack_from("<II", d, dd + 0 * 8)
    import_dir = struct.unpack_from("<II", d, dd + 1 * 8)
    sec = opt + optsz
    for i in range(info.nsec):
        o = sec + i * 40
        if o + 40 > len(d):
            break
        name = d[o:o + 8].rstrip(b"\0").decode("ascii", "replace")
        vs, va, raws, rawp = struct.unpack_from("<IIII", d, o + 8)
        info.sections.append((name, va, vs, rawp, raws))
    info.ok = True
    info.export_dir = export_dir
    info.import_dir = import_dir
    return info


def va2off(info: PeInfo, va: int):
    for _name, sva, svs, sraw, sraws in info.sections:
        if sva <= va < sva + max(svs, sraws):
            return sraw + (va - sva)
    return None


def read_exports(d: bytes, info: PeInfo) -> None:
    if not info.export_dir[0]:
        return
    eo = va2off(info, info.export_dir[0])
    if eo is None or eo + 40 > len(d):
        return
    (_flags, _ts, _majv, _minv, _name_rva, _nbase, _nfunc, nname,
     aof, aon, aono) = struct.unpack_from("<IIHHIIIIIII", d, eo)
    on, of, oo = va2off(info, aon), va2off(info, aof), va2off(info, aono)
    if on is None or of is None or oo is None:
        return
    for i in range(min(nname, 4096)):
        try:
            nr = struct.unpack_from("<I", d, on + i * 4)[0]
            no = va2off(info, nr)
            ordi = struct.unpack_from("<H", d, oo + i * 2)[0]
            if no is None:
                continue
            nm = d[no:no + 128].split(b"\0")[0].decode("ascii", "replace")
            _fr = struct.unpack_from("<I", d, of + ordi * 4)[0]
            info.export_names.append(nm)
        except Exception:
            break


def read_imports(d: bytes, info: PeInfo) -> None:
    if not info.import_dir[0]:
        return
    io = va2off(info, info.import_dir[0])
    if io is None:
        return
    seen = set()
    for _ in range(256):
        if io + 20 > len(d):
            break
        ilt, _ts, _fwd, name_rva, iat = struct.unpack_from("<IIIII", d, io)
        io += 20
        if name_rva == 0 and ilt == 0:
            break
        no = va2off(info, name_rva)
        if no is None:
            continue
        dll = d[no:no + 128].split(b"\0")[0].decode("ascii", "replace")
        info.import_dlls.append(dll)
        thunk = va2off(info, ilt if ilt else iat)
        if thunk is None:
            continue
        for j in range(512):
            t = struct.unpack_from("<I", d, thunk + j * 4)[0]
            if t == 0:
                break
            if t & 0x80000000:
                continue
            ho = va2off(info, t)
            if ho is None:
                continue
            hn = d[ho + 2:ho + 96].split(b"\0")[0].decode("ascii", "replace")
            if hn not in seen:
                seen.add(hn)
                info.import_names.append(hn)


# ---------------------------------------------------------------------------
# .text region helpers
# ---------------------------------------------------------------------------

def text_ranges(info: PeInfo):
    """File-offset ranges of sections holding code (.text + any executable)."""
    out = []
    for name, _va, vs, raw, raws in info.sections:
        if raw and raws and (name.lower().startswith(".text")
                             or name.lower() in ("code", ".code")):
            out.append((raw, raw + min(raws, vs + 16)))
    if not out:  # fallback: first section
        for name, _va, vs, raw, raws in info.sections:
            if raw and raws:
                out.append((raw, raw + raws))
                break
    return out


def data_ranges(info: PeInfo):
    """File-offset ranges of non-code sections (rdata/data/rsrc)."""
    out = []
    for name, _va, vs, raw, raws in info.sections:
        nl = name.lower()
        if raw and raws and not (nl.startswith(".text") or nl == ".code"):
            out.append((raw, raw + min(raws, vs + 16)))
    return out


def in_ranges(off: int, ranges) -> bool:
    return any(a <= off < b for a, b in ranges)


def classify_abs_operand(d: bytes, pos: int) -> str:
    """Classify the dword at ``pos`` as an x86 operand.

    'moffs'   — A1/A2/A3 moffs accumulator form (always a real mem operand)
    'disp32'  — modrm mod00 rm101 preceded by a modrm-capable opcode
                (ambiguous: pos-1 byte could itself be an acc-imm opcode)
    'ptr32'   — disp32 restricted to the pointer forms {8B,89,C7,FF}
                (load/store/call/jmp/push through [abs] — unambiguous)
    'imm_mov' — B8..BF mov reg,imm32   'imm_push' — 68 push imm32
    'imm_acc' — acc-imm opcode (05..3D) — only reachable when pos-1 is that
                byte AND it is an opcode (indistinguishable from modrm-05;
                reported for completeness)
    'esc2'    — 0F-prefixed two-byte form
    'raw'     — no plausible operand framing"""
    if pos >= 1 and d[pos - 1] in (0xA1, 0xA2, 0xA3):
        return "moffs"
    if pos >= 2 and d[pos - 1] in (0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D,
                                   0x35, 0x3D):
        prev = d[pos - 2]
        if prev == 0x0F:
            return "esc2"
        if prev in (0x8B, 0x89, 0xC7, 0xFF):
            return "ptr32"
        if prev in _OPCODE_PREFIX:
            return "disp32"
        return "imm_acc"
    if pos >= 1:
        prev = d[pos - 1]
        if 0xB8 <= prev <= 0xBF:
            return "imm_mov"
        if prev == 0x68:
            return "imm_push"
    return "raw"


def scan_dwords_in_ranges(d: bytes, ranges, value_lo: int, value_hi: int,
                          verify_operands: bool):
    """Find dwords in [value_lo, value_hi) inside file-offset ranges.

    Returns dict value -> list of (offset, class) where class is the
    classify_abs_operand tag ('raw' when verify_operands=False)."""
    hits = {}
    for a, b in ranges:
        i = a
        end = min(b, len(d) - 4)
        while i < end:
            v = struct.unpack_from("<I", d, i)[0]
            if value_lo <= v < value_hi:
                cls = classify_abs_operand(d, i) if verify_operands else "raw"
                hits.setdefault(v, []).append((i, cls))
            i += 1
    return hits


def scan_store60(d: bytes, ranges, img_lo: int, img_hi: int):
    """+0x60 store idioms inside code ranges.

    C7 <modrm> [sib] 60 <imm32>  -> imm classified self/exe/other
    89 <modrm> [sib] 60         -> reg store; base classified stack vs reg
    Returns dict with counts + sample list."""
    out = {"imm_self": 0, "imm_exe": 0, "imm_other": 0, "imm_self_stack": 0,
           "reg_stack": 0, "reg_nonstack": 0, "samples": []}

    def _sib_base(sib):
        return sib & 7

    for a, b in ranges:
        i = a
        n = min(b, len(d) - 8)
        while i < n:
            op = d[i]
            if op == 0xC7 or op == 0x89:
                modrm = d[i + 1]
                mod = modrm >> 6
                rm = modrm & 7
                if mod == 2:               # [reg + disp32] — disp32 must be 0x60
                    k = i + 2
                    sib32 = None
                    if rm == 4:
                        sib32 = d[k]
                        k += 1
                    if struct.unpack_from("<I", d, k)[0] == 0x60:
                        if op == 0x89:
                            stack = (sib32 is not None
                                     and _sib_base(sib32) in (4, 5))
                            key = "reg_stack" if stack else "reg_nonstack"
                            out[key] += 1
                            if len(out["samples"]) < 10:
                                out["samples"].append(
                                    f"{i:x}:89d32/{modrm:02x}:{key}")
                        else:
                            imm = struct.unpack_from("<I", d, k + 4)[0]
                            stack = (sib32 is not None
                                     and _sib_base(sib32) in (4, 5))
                            if img_lo <= imm < img_hi:
                                out["imm_self_stack" if stack
                                    else "imm_self"] += 1
                            elif EXE_ABS_LO <= imm < EXE_ABS_HI:
                                out["imm_exe"] += 1
                            else:
                                out["imm_other"] += 1
                    i += 1
                    continue
                if mod == 1:
                    k = i + 2
                    sib = None
                    if rm == 4:
                        sib = d[k]
                        k += 1
                    if d[k] == 0x60:
                        if op == 0x89:
                            stack = (rm == 5) or \
                                (sib is not None and _sib_base(sib) in (4, 5))
                            key = "reg_stack" if stack else "reg_nonstack"
                            out[key] += 1
                            if len(out["samples"]) < 10:
                                out["samples"].append(
                                    f"{i:x}:89/{modrm:02x}{'s' if sib is not None else ''}:{key}")
                        else:
                            imm = struct.unpack_from("<I", d, k + 1)[0]
                            stack = (rm == 5) or \
                                (sib is not None and _sib_base(sib) in (4, 5))
                            if img_lo <= imm < img_hi:
                                out["imm_self_stack" if stack
                                    else "imm_self"] += 1
                                if len(out["samples"]) < 10:
                                    out["samples"].append(
                                        f"{i:x}:C7/{modrm:02x}=>{hex(imm)}"
                                        + ("stk" if stack else ""))
                            elif EXE_ABS_LO <= imm < EXE_ABS_HI:
                                out["imm_exe"] += 1
                                if len(out["samples"]) < 10:
                                    out["samples"].append(
                                        f"{i:x}:C7/{modrm:02x}=exe>{hex(imm)}")
                            else:
                                out["imm_other"] += 1
            i += 1
    return out


def scan_strings(d: bytes, needles):
    hits = {}
    for nd in needles:
        c = d.count(nd)
        if c:
            hits[nd.decode("ascii", "replace")] = c
    return hits


# ---------------------------------------------------------------------------
# Capstone operand verification (optional but decisive)
# ---------------------------------------------------------------------------
# A raw dword match inside .text can be a *straddle* — bytes spanning two real
# instructions (smoke test: "0xA27C10" was `7C A2 00 10` = imm 0x1000A27C read
# one byte late).  Capstone re-decodes a window and keeps only hits where the
# flagged value is a genuine imm/mem.disp operand of a decoded instruction.

try:
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM
    _MD = Cs(CS_ARCH_X86, CS_MODE_32)
    _MD.detail = True
    _HAVE_CAPSTONE = True
except Exception:                                   # pragma: no cover
    _HAVE_CAPSTONE = False


def _decode_synced(d: bytes, pos: int, span: int = 64):
    """Yield (base_off, insns) for 4 candidate sync offsets covering pos."""
    for delta in (0, 1, 2, 3):
        start = max(0, pos - span - delta)
        try:
            ins = list(_MD.disasm(d[start:pos + 16], start))
        except Exception:
            continue
        if ins:
            yield start, ins


def verify_operand(d: bytes, pos: int, value: int) -> str:
    """'real' if a decoded instruction covers pos..pos+3 AND has value as an
    imm or mem.disp operand; 'straddle' if covered but the operand value
    differs (or it lands inside an instruction's other bytes); 'unsynced'."""
    if not _HAVE_CAPSTONE:
        return "unverified"
    best = "unsynced"
    for _start, insns in _decode_synced(d, pos):
        covered = False
        for i in insns:
            if i.address <= pos < i.address + i.size:
                covered = True
                for op in i.operands:
                    if op.type == X86_OP_IMM and (op.imm & 0xFFFFFFFF) == value:
                        return "real"
                    if op.type == X86_OP_MEM and \
                            (op.mem.disp & 0xFFFFFFFF) == value:
                        return "real"
                # instruction covers pos but operand != value -> straddle
                if i.address + i.size >= pos + 4:
                    best = "straddle"
        if covered and best == "unsynced":
            best = "straddle"
    return best


def verify_insn_at(d: bytes, pos: int) -> bool:
    """True when a decoded instruction starts exactly at ``pos`` (boundary-
    aligned) — used to confirm the C7/89 +0x60 store idiom isn't a straddle."""
    if not _HAVE_CAPSTONE:
        return False
    for _start, insns in _decode_synced(d, pos, span=32):
        for i in insns:
            if i.address == pos:
                return True
            if i.address > pos:
                break
    return False


# ---------------------------------------------------------------------------
# Per-file probe
# ---------------------------------------------------------------------------

COLUMNS = [
    "dll", "size", "machine", "nsec", "imagebase", "n_exports",
    "extra_exports", "import_dlls", "n_imports",
    "txt_anch_atelcurctrlwork", "txt_anch_controllers_base",
    "txt_ctrl_span_operands", "txt_anch_return1", "txt_anch_sites",
    "txt_loadabs_operands",
    "dat_anch_exact", "dat_ctrl_span_raw",
    "store60_imm_self", "store60_imm_exe", "store60_imm_other",
    "store60_imm_self_stack", "store60_reg_nonstack", "store60_reg_stack",
    "store60_samples",
    "str_hits", "verdict", "notes",
]


def probe_file(path: str):
    row = {k: "" for k in COLUMNS}
    row["dll"] = path
    try:
        d = open(path, "rb").read()
    except OSError as e:
        row["verdict"] = "ERROR"
        row["notes"] = str(e)
        return row
    row["size"] = len(d)
    info = parse_pe(d)
    if not info.ok:
        row["verdict"] = "NOT-PE"
        return row
    row["machine"] = hex(info.machine)
    row["nsec"] = info.nsec
    row["imagebase"] = hex(info.imagebase)
    read_exports(d, info)
    read_imports(d, info)
    row["n_exports"] = len(info.export_names)
    extra = [e for e in info.export_names
             if e not in ("GetEffectOverlayTable", "InitMagicPRX")]
    row["extra_exports"] = ";".join(extra[:12])
    row["import_dlls"] = ";".join(info.import_dlls)
    row["n_imports"] = len(info.import_names)

    tr = text_ranges(info)
    dr = data_ranges(info)

    # ---- .text operand-verified anchors ---------------------------------
    exact = scan_dwords_in_ranges(
        d, tr, ATEL_CUR_CTRL_WORK, ATEL_CUR_CTRL_WORK + 1, True)
    row["txt_anch_atelcurctrlwork"] = ";".join(
        f"{o:x}:{c}" for vs in exact.values() for o, c in vs)
    exact2 = scan_dwords_in_ranges(
        d, tr, CONTROLLERS_BASE, CONTROLLERS_BASE + 1, True)
    row["txt_anch_controllers_base"] = ";".join(
        f"{o:x}:{c}" for vs in exact2.values() for o, c in vs)
    def _verify_hits(hits):
        """Keep (value -> [(off, class, verdict)]) where capstone confirms the
        dword is a genuine operand ('real'); degrade to class tag otherwise."""
        out = {}
        for v, ts in hits.items():
            kept = []
            for o, c in ts:
                verdict = verify_operand(d, o, v)
                if verdict == "real" or verdict == "unverified":
                    kept.append((o, c + "/" + verdict))
            if kept:
                out[v] = kept
        return out

    operand_cls = {"moffs", "ptr32", "disp32", "imm_mov", "imm_push",
                   "imm_acc", "esc2"}
    span = scan_dwords_in_ranges(d, tr, CONTROLLERS_BASE + 4,
                                 CONTROLLERS_END, True)
    span_ops = {v: [t for t in ts if t[1] in operand_cls]
                for v, ts in span.items()}
    span_ops = _verify_hits(span_ops)
    row["txt_ctrl_span_operands"] = ";".join(
        f"{hex(v)}@{o}:{c}" for v, ts in sorted(span_ops.items())
        for o, c in ts)
    r1 = scan_dwords_in_ranges(d, tr, FFX_CONST_RETURN1,
                               FFX_CONST_RETURN1 + 1, True)
    r1v = _verify_hits(r1)
    row["txt_anch_return1"] = ";".join(
        f"{o:x}:{c}" for vs in r1v.values() for o, c in vs)
    site_hits = []
    for s in GATE_SITES + (INSTALL_SITE, ZEROINIT_SITE, PREDICATE_MODEL):
        h = scan_dwords_in_ranges(d, tr, s, s + 1, True)
        for v, ts in _verify_hits(h).items():
            for o, c in ts:
                site_hits.append(f"{hex(s)}@{o:x}:{c}")
    row["txt_anch_sites"] = ";".join(site_hits)

    # ---- .text absolute loads/stores into exe space ----------------------
    # DLL self-image refs (imagebase..imagebase+size) are normal globals
    # access, not exe refs — filtered out before reporting.
    img_lo = info.imagebase
    img_hi = info.imagebase + max(info.size_of_image, 1)
    la = scan_dwords_in_ranges(d, tr, EXE_ABS_LO, EXE_ABS_HI, True)
    la_ops = {v: [t for t in ts if t[1] in ("moffs", "ptr32")]
              for v, ts in la.items() if not (img_lo <= v < img_hi)}
    la_ops = _verify_hits(la_ops)
    row["txt_loadabs_operands"] = ";".join(
        f"{hex(v)}@{ts[0][0]:x}:{ts[0][1]}x{len(ts)}" for v, ts in
        sorted(la_ops.items(), key=lambda kv: -len(kv[1]))[:16])

    # ---- data sections: exact anchors only (span too noisy) --------------
    dat_hits = []
    for v in (ATEL_CUR_CTRL_WORK, CONTROLLERS_BASE, FFX_CONST_RETURN1):
        h = scan_dwords_in_ranges(d, dr, v, v + 1, False)
        for o, _c in [t for ts in h.values() for t in ts]:
            dat_hits.append(f"{hex(v)}@{o:x}")
    row["dat_anch_exact"] = ";".join(dat_hits[:16])
    span_data = scan_dwords_in_ranges(d, dr, CONTROLLERS_BASE + 4,
                                      CONTROLLERS_END, False)
    row["dat_ctrl_span_raw"] = len(span_data)

    # ---- +0x60 store idiom in .text --------------------------------------
    st = scan_store60(d, tr, img_lo, img_hi)
    # capstone-verify the recorded samples are boundary-aligned real insns
    verified = []
    for s in st["samples"]:
        off = int(s.split(":")[0], 16)
        verified.append(s + ("*" if verify_insn_at(d, off) else "?"))
    row["store60_imm_self"] = st["imm_self"]
    row["store60_imm_exe"] = st["imm_exe"]
    row["store60_imm_other"] = st["imm_other"]
    row["store60_imm_self_stack"] = st["imm_self_stack"]
    row["store60_reg_nonstack"] = st["reg_nonstack"]
    row["store60_reg_stack"] = st["reg_stack"]
    row["store60_samples"] = ";".join(verified)

    # ---- strings -----------------------------------------------------------
    sh = scan_strings(d, STRING_NEEDLES)
    row["str_hits"] = ";".join(f"{k}x{v}" for k, v in sorted(sh.items()))

    # ---- verdict ---------------------------------------------------------
    notes = []
    verdict = "CLEAN"
    if row["txt_anch_atelcurctrlwork"] or row["txt_anch_controllers_base"] \
            or row["txt_ctrl_span_operands"] or row["txt_anch_return1"] \
            or row["txt_anch_sites"]:
        verdict = "HIT"
        notes.append("operand-verified exe-space ref in .text")
    if st["imm_self"]:
        verdict = "HIT"
        notes.append("store [r+60h] of DLL-local VA (callback install)")
    if st["imm_exe"]:
        verdict = "HIT"
        notes.append("store [r+60h] of exe-space VA (exe-fn install)")
    hooking = [k for k in sh if k.lower() in HOOKING_NEEDLES]
    if hooking:
        verdict = "HIT"
        notes.append("hook/ctrl string: " + ",".join(hooking))
    if verdict == "CLEAN":
        if dat_hits:
            verdict = "REVIEW"
            notes.append("exact anchor dword in data section")
        elif st["reg_nonstack"]:
            verdict = "REVIEW"
            notes.append("+0x60 reg-store (non-stack) in .text")
        elif la_ops:
            verdict = "REVIEW"
            notes.append("abs mem operand into exe space")
        elif st["imm_other"]:
            verdict = "REVIEW"
            notes.append("+0x60 imm-store (external imm)")
        elif st["imm_self_stack"]:
            verdict = "REVIEW"
            notes.append("DLL-local VA stored into stack frame +0x60 "
                         "(local struct member, not a controller write)")
    row["verdict"] = verdict
    row["notes"] = " | ".join(notes)
    return row


# ---------------------------------------------------------------------------
# Driver
# ---------------------------------------------------------------------------

def iter_dlls(roots, regex):
    rx = re.compile(regex, re.I)
    for root in roots:
        for dirpath, _dirs, files in os.walk(root):
            for f in files:
                if rx.match(f):
                    yield os.path.join(dirpath, f)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("roots", nargs="+", help="directories to walk")
    ap.add_argument("--csv", help="write per-DLL rows here")
    ap.add_argument("--family-regex", default=r"magic_.*\.dll$",
                    help="filename filter (default magic_*.dll)")
    ap.add_argument("--max", type=int, default=0, help="cap files scanned")
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args(argv)

    files = sorted(iter_dlls(args.roots, args.family_regex))
    if args.max:
        files = files[: args.max]
    rows = []
    tally = {"CLEAN": 0, "REVIEW": 0, "HIT": 0, "ERROR": 0, "NOT-PE": 0}
    for idx, path in enumerate(files):
        row = probe_file(path)
        row["dll"] = os.path.relpath(path, args.roots[0]) \
            if len(args.roots) == 1 else path
        rows.append(row)
        tally[row["verdict"]] = tally.get(row["verdict"], 0) + 1
        if not args.quiet and (idx % 200 == 0
                               or row["verdict"] in ("HIT", "ERROR")):
            print(f"[{idx + 1}/{len(files)}] {row['verdict']:6s} {row['dll']}",
                  file=sys.stderr)
        if row["verdict"] == "HIT":
            print("HIT:", row["dll"], "|", row["notes"], "|",
                  row["store60_samples"], "|", row["txt_loadabs_operands"],
                  "|", row["str_hits"], file=sys.stderr)

    if args.csv and rows:
        with open(args.csv, "w", newline="") as fh:
            w = csv.DictWriter(fh, fieldnames=COLUMNS, extrasaction="ignore")
            w.writeheader()
            w.writerows(rows)
    print(f"scanned={len(rows)} verdicts={tally}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    sys.exit(main())
