#!/usr/bin/env python3
"""btlai_census.py — FFX battle-AI ATEL opcode/structure census.

Maintained-by: Jarvis (research lane, wave-17)
Purpose      : research-only tooling. The battle AI corpus (.bin packs) was
               scanned for REQ-family ops before (B-LETTER wave-15, 0 hits)
               but never fully inventoried. This tool does the census:
               locates every ATEL script blob inside battle/mon AiFiles and
               battle/btl scene packs, decodes ONLY the code region, and
               counts usage of all 123 EventVM opcodes (0x00-0x7A).

READ-ONLY    : never writes into the corpus; outputs go to CSV/stdout.

Container formats handled (all proven on the live corpus, 2026-09-18):
  * signature-N pack (.bin): u32 sig @0 (8/7/5 = ptr-table format tag),
    u32[n] pointer table @4 with n = (ptr[0]-4)/4. Each non-null pointer
    is a chunk offset; chunks are validated as ATEL before decoding.
    battle/mon/*/mNNN.bin and battle/btl/<scene>/<scene>.bin are packs;
    the scene/AI script is always the first ATEL chunk (ptr[0] target).
  * EV01 wrapper (.ebp): "EV01" @0, ATEL blob @ u32[+0x04] (usually 0x40).
    Included so the same census can run on the field-event corpus for the
    battle-vs-event comparison (--events).
  * raw ATEL blob: header validates at offset 0 (e.g. menumain.bin).

ATEL chunk header (0x38, chunk-relative; proven vs m034.bin / bika00_00.bin):
  +0x00 u32 code_len        +0x04 u32 map_start
  +0x08 u32 offset_author   +0x0C u32 offset_name
  +0x10 u32 offset_jumps_end
  +0x18 u16 main_script_idx
  +0x20 u32 offset_event_data
  +0x28 u32 offset_area     +0x2C u32 offset_other
  +0x30 u32 offset_code     +0x34 u16 worker_count (script_num)
  +0x36 u16 worker_count_ex_subroutines
  +0x38 u32[worker_count] worker-header offsets (CHUNK-relative)

Worker/script header (0x34, all offsets CHUNK-relative):
  +0x00 u16 eventType       +0x02 u16 varCount
  +0x04 u16 intConstCount   +0x06 u16 floatConstCount
  +0x08 u16 entryPointCount +0x0A u16 jumpCount
  +0x10 u32 privDataLen     +0x14 u32 varTableOff
  +0x18 u32 intConstOff     +0x1C u32 floatConstOff
  +0x20 u32 entryPointTableOff ("funcTableOff" in older tools)
  +0x24 u32 jumpTableOff    +0x28 u32 dataOff
  +0x2C u32 privDataOff     +0x30 u32 sharedDataOff
Entry-point and jump tables hold u32 CODE-REGION-relative offsets
(verified: values < code_len; entryPtTable+funcs*4 lands on jumpTable,
and last jump table ends exactly at offset_jumps_end).

Instruction model (FFX_Atel_FetchOpcode @0x869D00, proven):
  opcode byte <  0x80 -> 1-byte instruction (index = byte)
  opcode byte >= 0x80 -> 3-byte instruction, u16 LE operand (index = byte&0x7F)
Bytes whose index would exceed 0x7A (0x7B-0x7F / 0xFB-0xFF) are INVALID in
this VM (123-entry dispatch) -> counted as `invalid_ops`, a data-in-code
tell. Decode ends exactly at code_off+code_len for clean files; a mid-
instruction truncation at the region end is flagged `truncated`.

Outputs (CSV):
  btlai_opcode_dist.csv   opcode x name x counts x files-using (mon/btl/event)
  btlai_file_index.csv    per file: id guess, workers, code bytes, top ops
  btlai_complexity.csv    files ranked by code size / branch metrics
  btlai_callfuncs.csv     CALL/CALLPOPA funcId usage (the REQ replacement)

Usage:
  btlai_census.py --battle-root <jppc/battle> --outdir <dir> [--events <event_root>]
Defaults: --battle-root /mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/battle
          --events      /mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj
"""
import argparse
import collections
import csv
import glob
import os
import struct
import sys

DEF_BATTLE = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/battle"
DEF_EVENTS = "/mnt/nvme-xpg/ffx_ps2/ffx/master/jppc/event/obj"

# ── 123-op EventVM table (name / operand-class) ─────────────────────────────
# Ground truth: g_FFX_Atel_OpcodeNameTable @0xC54600 +
# docs/reverse/data/wave13/eventvm_ops.csv (Jarvis-DEVIN, decompile-proven).
OP_NAMES = [
    "NOP", "OPLOR", "OPLAND", "OPOR", "OPEOR", "OPAND", "OPEQ", "OPNE",
    "OPGTU", "OPLSU", "OPGT", "OPLS", "OPGTEU", "OPLSEU", "OPGTE", "OPLSE",
    "OPBON", "OPBOFF", "OPSLL", "OPSRL", "OPADD", "OPSUB", "OPMUL", "OPDIV",
    "OPMOD", "OPNOT", "OPUMINUS", "OPFIXADRS", "OPBNOT", "LABEL", "TAG",
    "PUSHV", "POPV", "POPVL", "PUSHAR", "POPAR", "POPARL", "POPA", "PUSHA",
    "PUSHARP", "PUSHX", "PUSHY", "POPX", "REPUSH", "POPY", "PUSHI", "PUSHII",
    "PUSHF", "JMP", "CJMP", "NCJMP", "JSR", "RTS", "CALL", "REQ", "REQSW",
    "REQEW", "PREQ", "PREQSW", "PREQEW", "RET", "RETN", "RETT", "RETTN",
    "HALT", "PUSHN", "PUSHT", "PUSHVP", "PUSHFIX", "FREQ", "TREQ", "BREQ",
    "BFREQ", "BTREQ", "FREQSW", "TREQSW", "BREQSW", "BFREQSW", "BTREQSW",
    "FREQEW", "TREQEW", "BREQEW", "BFREQEW", "BTREQEW", "DRET", "POPXJMP",
    "POPXCJMP", "POPXNCJMP", "CALLPOPA", "POPI0", "POPI1", "POPI2", "POPI3",
    "POPF0", "POPF1", "POPF2", "POPF3", "POPF4", "POPF5", "POPF6", "POPF7",
    "POPF8", "POPF9", "PUSHI0", "PUSHI1", "PUSHI2", "PUSHI3", "PUSHF0",
    "PUSHF1", "PUSHF2", "PUSHF3", "PUSHF4", "PUSHF5", "PUSHF6", "PUSHF7",
    "PUSHF8", "PUSHF9", "PUSHAINTER", "SYSTEM", "REQWAIT", "PREQWAIT",
    "REQCHG", "ACTREQ",
]
assert len(OP_NAMES) == 123

# opcode groups used for complexity/family metrics (indices, not encodings)
G_COND_JMP = (0x31, 0x32, 0x56, 0x57)            # CJMP NCJMP POPXCJMP POPXNCJMP
G_ALL_JMP = (0x30, 0x31, 0x32, 0x55, 0x56, 0x57)  # + JMP POPXJMP
G_COMPARE = tuple(range(0x06, 0x12))             # OPEQ..OPBOFF
G_CALL = (0x35, 0x58)                            # CALL CALLPOPA
G_REQ_FAMILY = (0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
                0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
                0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53,
                0x77, 0x78, 0x79, 0x7A)
G_B_OPS = (0x47, 0x48, 0x49, 0x4C, 0x4D, 0x4E, 0x51, 0x52, 0x53)
G_DEAD = (0x1B, 0x41, 0x42, 0x43, 0x44)          # FIXADRS/PUSHN/T/VP/FIX: NOPs


def u16(b, o):
    return struct.unpack_from("<H", b, o)[0]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def i32(b, o):
    return struct.unpack_from("<i", b, o)[0]


def cstr(b, o):
    if o <= 0 or o >= len(b):
        return ""
    e = b.find(b"\x00", o)
    if e < 0:
        e = len(b)
    return b[o:e].decode("ascii", "replace")


# ── ATEL chunk parse ────────────────────────────────────────────────────────

def valid_atel(b, off):
    """Cheap header sanity for pointer-table probing. Returns bool."""
    if off < 0 or off + 0x38 > len(b):
        return False
    code_len = u32(b, off)
    code_off = u32(b, off + 0x30)
    wcount = u16(b, off + 0x34)
    if not (0 < code_len <= len(b)):
        return False
    if not (0x38 <= code_off < len(b)):
        return False
    if wcount == 0 or wcount > 64:
        return False
    if off + 0x38 + 4 * wcount > len(b):
        return False
    w0 = u32(b, off + 0x38)
    if w0 < 0x38 or off + w0 + 0x34 > len(b):
        return False
    return True


def parse_workers(b, base, wcount):
    """Parse worker descriptors. Returns (workers, notes[])."""
    workers, notes = [], []
    for i in range(wcount):
        wo = u32(b, base + 0x38 + 4 * i)
        w = {"off": wo}
        if wo < 0x38 or base + wo + 0x34 > len(b):
            w["bad"] = f"worker{i}-offset-0x{wo:x}-out-of-range"
            notes.append(w["bad"])
            workers.append(w)
            continue
        for k, off, rd in (
                ("eventType", 0x00, u16), ("varCount", 0x02, u16),
                ("intConstCount", 0x04, u16), ("floatConstCount", 0x06, u16),
                ("entryPointCount", 0x08, u16), ("jumpCount", 0x0A, u16),
                ("privDataLen", 0x10, u32), ("varTableOff", 0x14, u32),
                ("intConstOff", 0x18, u32), ("floatConstOff", 0x1C, u32),
                ("entryPointTableOff", 0x20, u32), ("jumpTableOff", 0x24, u32),
                ("dataOff", 0x28, u32), ("privDataOff", 0x2C, u32),
                ("sharedDataOff", 0x30, u32)):
            w[k] = rd(b, base + wo + off)
        # entry-point table: u32 code-region-relative offsets
        ep, jp = [], []
        epoff = base + w["entryPointTableOff"]
        if 0 <= w["entryPointTableOff"] and epoff + 4 * w["entryPointCount"] <= len(b):
            ep = [u32(b, epoff + 4 * j) for j in range(w["entryPointCount"])]
        elif w["entryPointCount"]:
            notes.append(f"worker{i}-entrypoint-table-oob")
        jpoff = base + w["jumpTableOff"]
        if 0 <= w["jumpTableOff"] and jpoff + 4 * w["jumpCount"] <= len(b):
            jp = [u32(b, jpoff + 4 * j) for j in range(w["jumpCount"])]
        elif w["jumpCount"]:
            notes.append(f"worker{i}-jumptable-oob")
        w["entryPoints"], w["jumpLabels"] = ep, jp
        workers.append(w)
    return workers, notes


def decode_code(b, start, end):
    """Linear decode of the code region. Returns (hist, operands, invalid,
    truncated, insns). hist: opcode-index -> count. operands: idx -> Counter
    of u16 operand values (for CALL funcId stats; kept for all ops, cheap).
    """
    hist = collections.Counter()
    operands = collections.defaultdict(collections.Counter)
    invalid = 0
    truncated = False
    insns = 0
    i = start
    while i < end:
        byte = b[i]
        idx = byte & 0x7F
        if byte < 0x80:
            if idx > 0x7A:
                invalid += 1
            else:
                hist[idx] += 1
                insns += 1
            i += 1
        else:
            if i + 3 > end:
                truncated = True
                break
            op16 = u16(b, i + 1)
            if idx > 0x7A:
                invalid += 1
            else:
                hist[idx] += 1
                operands[idx][op16] += 1
                insns += 1
            i += 3
    return hist, operands, invalid, truncated, insns


def scan_atel(b, base, tag):
    """Parse one ATEL chunk at file offset `base`. Returns a record dict."""
    rec = {"base": base, "tag": tag, "status": "ok", "notes": []}
    code_len = u32(b, base)
    code_off = u32(b, base + 0x30)
    rec["code_len"] = code_len
    rec["code_off"] = code_off
    rec["total_len"] = u32(b, base + 0x10)
    rec["main_script_idx"] = u16(b, base + 0x18)
    rec["worker_count"] = u16(b, base + 0x34)
    rec["worker_count_ex"] = u16(b, base + 0x36)
    rec["author"] = cstr(b, base + u32(b, base + 0x08)) if u32(b, base + 0x08) else ""
    rec["name"] = cstr(b, base + u32(b, base + 0x0C)) if u32(b, base + 0x0C) else ""

    # code region bounds (chunk-relative offsets -> file absolute)
    cs = base + code_off
    ce = base + code_off + code_len
    rec["code_span"] = (cs, ce)
    if cs >= len(b):
        rec["status"] = "bad:code-off-past-eof"
        return rec
    if ce > len(b):
        rec["notes"].append(f"code-region-clipped(+0x{ce - len(b):x})")
        ce = len(b)

    workers, notes = parse_workers(b, base, rec["worker_count"])
    rec["workers"] = workers
    rec["notes"] += notes

    hist, operands, invalid, truncated, insns = decode_code(b, cs, ce)
    rec["hist"] = hist
    rec["operands"] = operands
    rec["invalid_ops"] = invalid
    rec["insns"] = insns
    if truncated:
        rec["notes"].append("truncated-insn-at-region-end")
    # out-of-range jump/entry offsets (honesty metric: data-in-code suspicion)
    oob = 0
    for w in workers:
        for v in w.get("entryPoints", ()):
            if v >= code_len:
                oob += 1
        for v in w.get("jumpLabels", ()):
            if v >= code_len:
                oob += 1
    rec["label_oob"] = oob
    return rec


# ── container discovery ─────────────────────────────────────────────────────

def scan_file(path, family):
    """Return (file_record, [chunk_records])."""
    try:
        b = open(path, "rb").read()
    except OSError as exc:
        return {"file": path, "family": family, "status": f"io-error:{exc}"}, []
    frec = {"file": path, "family": family, "size": len(b)}
    chunks = []
    if len(b) < 0x38:
        frec["status"] = "too-small"
        return frec, chunks
    if b[:4] == b"EV01":
        blob_off = u32(b, 0x04)
        frec["container"] = "EV01"
        if blob_off >= len(b) or not valid_atel(b, blob_off):
            frec["status"] = "bad:ev01-blob"
            return frec, chunks
        frec["status"] = "ok"
        chunks.append(scan_atel(b, blob_off, "blob"))
        return frec, chunks

    sig = u32(b, 0)
    p0 = u32(b, 4)
    nptr = (p0 - 4) // 4 if p0 >= 4 else 0
    if sig in (5, 7, 8) and 1 <= nptr <= 16 and p0 <= len(b):
        frec["container"] = f"sig{sig}-pack"
        frec["sig"] = sig
        ptrs = [u32(b, 4 + 4 * i) for i in range(nptr)]
        hits = []
        for i, p in enumerate(ptrs):
            if p and valid_atel(b, p):
                hits.append(i)
                chunks.append(scan_atel(b, p, f"ptr{i}"))
        frec["ptrs"] = ptrs
        frec["atel_ptr_idx"] = hits
        frec["status"] = "ok" if chunks else "no-atel"
        return frec, chunks

    if valid_atel(b, 0):
        frec["container"] = "raw-atel"
        frec["status"] = "ok"
        chunks.append(scan_atel(b, 0, "raw"))
        return frec, chunks

    frec["container"] = "?"
    frec["status"] = f"unrecognized:sig0x{sig:x}"
    return frec, chunks


# ── aggregation helpers ─────────────────────────────────────────────────────

def mon_id_from_name(path):
    """m034.bin -> 34 ; _m034 -> 34. Returns int or ''."""
    stem = os.path.splitext(os.path.basename(path))[0].lstrip("_mM")
    return int(stem) if stem.isdigit() else ""


def scene_from_name(path):
    return os.path.splitext(os.path.basename(path))[0]


def top_ops(hist, n=3):
    return hist.most_common(n)


def fam_metrics(hist):
    g = lambda grp: sum(hist.get(o, 0) for o in grp)
    return {"cond_jmp": g(G_COND_JMP), "all_jmp": g(G_ALL_JMP),
            "cmp": g(G_COMPARE), "call": g(G_CALL),
            "req": g(G_REQ_FAMILY), "b_ops": g(G_B_OPS),
            "dead": g(G_DEAD)}


def iter_files(root, patterns):
    for pat in patterns:
        yield from sorted(glob.glob(os.path.join(root, pat), recursive=True))


def main():
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--battle-root", default=DEF_BATTLE)
    ap.add_argument("--events", default=None,
                    help="event .ebp root for comparison columns")
    ap.add_argument("--outdir", required=True)
    ap.add_argument("--quiet", action="store_true")
    args = ap.parse_args()

    os.makedirs(args.outdir, exist_ok=True)

    # ── battle corpus: mon AiFiles + btl scene packs ────────────────────────
    jobs = []  # (family, path)
    for f in iter_files(args.battle_root, ["mon/*/m*.bin"]):
        jobs.append(("mon", f))
    for f in iter_files(args.battle_root, ["btl/*/*.bin"]):
        jobs.append(("btl", f))

    file_rows, chunk_rows = [], []
    hist_all = collections.Counter()
    hist_fam = collections.defaultdict(collections.Counter)
    files_using = collections.defaultdict(set)
    files_using_fam = collections.defaultdict(lambda: collections.defaultdict(set))
    callfunc_ctr = collections.Counter()      # funcId -> hits
    callfunc_files = collections.defaultdict(set)
    status_ctr = collections.Counter()
    total_insns = 0
    total_code_bytes = 0
    total_invalid = 0

    for family, path in jobs:
        frec, chunks = scan_file(path, family)
        rel = os.path.relpath(path, args.battle_root)
        status_ctr[frec["status"].split(":")[0]] += 1
        fhist = collections.Counter()
        finsns = fcode = finvalid = flabel_oob = 0
        wcount = entrypts = jlabels = 0
        etypes = set()
        cnotes = []
        for c in chunks:
            fhist.update(c.get("hist") or {})
            finsns += c.get("insns", 0)
            fcode += c.get("code_len", 0)
            finvalid += c.get("invalid_ops", 0)
            flabel_oob += c.get("label_oob", 0)
            cnotes += c.get("notes", [])
            wcount += c.get("worker_count", 0)
            for w in c.get("workers", []):
                entrypts += w.get("entryPointCount", 0)
                jlabels += w.get("jumpCount", 0)
                if "eventType" in w:
                    etypes.add(w["eventType"])
            for op, cnt in (c.get("hist") or {}).items():
                files_using[op].add(rel)
                files_using_fam[op][family].add(rel)
            for op, ops_ctr in (c.get("operands") or {}).items():
                if op in G_CALL:
                    for fid, n in ops_ctr.items():
                        callfunc_ctr[fid] += n
                        callfunc_files[fid].add(rel)
        m = fam_metrics(fhist)
        t = top_ops(fhist, 3)
        row = {"family": family, "file": rel,
               "monster_id": mon_id_from_name(path) if family == "mon" else "",
               "scene": scene_from_name(path) if family == "btl" else "",
               "container": frec.get("container", "?"),
               "status": frec["status"],
               "atel_chunks": len(chunks),
               "workers": wcount, "worker_eventTypes": "/".join(hex(x) for x in sorted(etypes)),
               "entry_points": entrypts, "jump_labels": jlabels,
               "code_bytes": fcode, "insns": finsns,
               "invalid_ops": finvalid, "label_oob": flabel_oob,
               "notes": ";".join(sorted(set(cnotes))),
               **m,
               "top1": f"{OP_NAMES[t[0][0]]}:{t[0][1]}" if len(t) > 0 else "",
               "top2": f"{OP_NAMES[t[1][0]]}:{t[1][1]}" if len(t) > 1 else "",
               "top3": f"{OP_NAMES[t[2][0]]}:{t[2][1]}" if len(t) > 2 else "",
               }
        file_rows.append(row)
        chunk_rows.append((family, rel, chunks))
        for op, cnt in fhist.items():
            hist_all[op] += cnt
            hist_fam[family][op] += cnt
        total_insns += finsns
        total_code_bytes += fcode
        total_invalid += finvalid

    # ── optional event (.ebp) corpus for the battle-vs-event diff ───────────
    ev_hist = collections.Counter()
    ev_files_using = collections.defaultdict(set)
    ev_insns = 0
    ev_nfiles = 0
    if args.events:
        for path in iter_files(args.events, ["**/*.ebp"]):
            frec, chunks = scan_file(path, "event")
            rel = os.path.relpath(path, args.events)
            ev_nfiles += 1
            for c in chunks:
                for op, cnt in (c.get("hist") or {}).items():
                    ev_hist[op] += cnt
                    ev_files_using[op].add(rel)
                ev_insns += c.get("insns", 0)

    # ── CSV 1: opcode distribution ──────────────────────────────────────────
    p1 = os.path.join(args.outdir, "btlai_opcode_dist.csv")
    with open(p1, "w", newline="") as fh:
        w = csv.writer(fh)
        hdr = ["opcode", "name", "count", "files_using", "pct_insns",
               "mon_count", "mon_files", "btl_count", "btl_files"]
        if args.events:
            hdr += ["event_count", "event_files", "battle_only"]
        w.writerow(hdr)
        for op in range(0x7B):
            cnt = hist_all.get(op, 0)
            row = [f"0x{op:02X}", OP_NAMES[op], cnt, len(files_using.get(op, ())),
                   f"{100.0 * cnt / total_insns:.3f}" if total_insns else "0",
                   hist_fam["mon"].get(op, 0), len(files_using_fam[op]["mon"]),
                   hist_fam["btl"].get(op, 0), len(files_using_fam[op]["btl"])]
            if args.events:
                ec = ev_hist.get(op, 0)
                row += [ec, len(ev_files_using.get(op, ())),
                        "yes" if cnt and not ec else ""]
            w.writerow(row)

    # ── CSV 2: per-file index ───────────────────────────────────────────────
    p2 = os.path.join(args.outdir, "btlai_file_index.csv")
    cols = ["family", "file", "monster_id", "scene", "container", "status",
            "atel_chunks", "workers", "worker_eventTypes", "entry_points",
            "jump_labels", "code_bytes", "insns", "invalid_ops", "label_oob",
            "notes",
            "cond_jmp", "all_jmp", "cmp", "call", "req", "b_ops", "dead",
            "top1", "top2", "top3"]
    with open(p2, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=cols)
        w.writeheader()
        for r in file_rows:
            w.writerow({k: r.get(k, "") for k in cols})

    # ── CSV 3: complexity ranking ───────────────────────────────────────────
    p3 = os.path.join(args.outdir, "btlai_complexity.csv")
    ranked = sorted(file_rows,
                    key=lambda r: (r["code_bytes"], r["cond_jmp"], r["insns"]),
                    reverse=True)
    with open(p3, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["rank", "file", "family", "monster_id", "scene",
                    "code_bytes", "insns", "cond_jmp", "all_jmp", "cmp_ops",
                    "call_ops", "jump_labels", "workers", "entry_points",
                    "req_ops", "invalid_ops"])
        for i, r in enumerate(ranked, 1):
            w.writerow([i, r["file"], r["family"], r["monster_id"], r["scene"],
                        r["code_bytes"], r["insns"], r["cond_jmp"], r["all_jmp"],
                        r["cmp"], r["call"], r["jump_labels"], r["workers"],
                        r["entry_points"], r["req"], r["invalid_ops"]])

    # ── CSV 4 (bonus): CALL funcId usage — the REQ replacement ──────────────
    p4 = os.path.join(args.outdir, "btlai_callfuncs.csv")
    with open(p4, "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["funcId", "namespace", "index", "calls", "files"])
        for fid, n in callfunc_ctr.most_common():
            w.writerow([f"0x{fid:04X}", fid >> 12, fid & 0xFFF, n,
                        len(callfunc_files[fid])])

    # ── stdout summary ──────────────────────────────────────────────────────
    ok = sum(1 for r in file_rows if r["status"] == "ok")
    if not args.quiet:
        print(f"battle corpus: {len(file_rows)} files "
              f"({status_ctr.get('ok', 0)} ok) "
              f"mon={sum(1 for r in file_rows if r['family'] == 'mon')} "
              f"btl={sum(1 for r in file_rows if r['family'] == 'btl')}")
        print(f"code bytes={total_code_bytes} insns={total_insns} "
              f"invalid_ops={total_invalid}")
        print("status:", dict(status_ctr))
        print(f"{'op':>5} {'name':<12} {'count':>8} {'files':>6} {'%insns':>7}")
        for op, cnt in hist_all.most_common(25):
            print(f"0x{op:02X} {OP_NAMES[op]:<12} {cnt:>8} "
                  f"{len(files_using[op]):>6} {100.0 * cnt / total_insns:>6.2f}%")
        absent = [op for op in range(0x7B) if op not in hist_all]
        print("ABSENT ops:", " ".join(f"0x{x:02X}" for x in absent))
        reqtot = sum(hist_all.get(o, 0) for o in G_REQ_FAMILY)
        print(f"REQ-family total: {reqtot}")
        print(f"distinct CALL funcIds: {len(callfunc_ctr)}; top: " +
              ", ".join(f"0x{fid:04X}x{n}" for fid, n in callfunc_ctr.most_common(12)))
        if args.events:
            print(f"event corpus: {ev_nfiles} .ebp files, {ev_insns} insns")
            battle_only = [op for op in range(0x7B)
                           if hist_all.get(op) and not ev_hist.get(op)]
            event_only = [op for op in range(0x7B)
                          if ev_hist.get(op) and not hist_all.get(op)]
            print("battle-only ops:", [f"0x{x:02X}" for x in battle_only])
            print("event-only ops:", [f"0x{x:02X}" for x in event_only])
    print(f"wrote {p1}\nwrote {p2}\nwrote {p3}\nwrote {p4}", file=sys.stderr)


if __name__ == "__main__":
    main()
