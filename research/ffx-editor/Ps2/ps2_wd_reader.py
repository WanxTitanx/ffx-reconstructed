#!/usr/bin/env python3
# ── FFX PS2 .wd sound-bank reader + SPU-ADPCM decoder (research tool) ──────────
#
# Purpose: parse the PS2 `.wd` wave-bank container (magic "WD"), resolve the
# program/descriptor tables, and decode the sample bodies from PS2 SPU-ADPCM
# (4-bit VAG) to 16-bit mono WAV — stdlib only, no external codec (the product
# currently relies on an external vgmstream oracle for this).
#
# Proven layout (byte-level, re-proven on this corpus 2026-09-14; matches the
# earlier proof in docs/history/FFX_PS2_WD_DESCRIPTOR_SEMANTICS_2026-06-02.md):
#
#   FILE HEADER (0x10 bytes, all little-endian)
#     +0x00 char[2] magic "WD"          (errata A3-E7: "WD" + u16 id, no 'X')
#     +0x02 u16     file id             (== wave number in filename, e.g.
#                                        wave2533.wd -> 2533 == 0x09E5)
#     +0x04 u32     bodySize            (SPU-RAM allocation hint; NOT a clean
#                                        body byte count — do not trust it)
#     +0x08 u32     nPrograms
#     +0x0C u32     nSamples
#     +0x10 .. 0x1F zero padding
#
#   PROGRAM TABLE (starts 0x20, nPrograms * u32)
#     Absolute file offsets partitioning the descriptor array into programs.
#     progtab[0] = desc_base (start of the contiguous descriptor array).
#     A literal tag b"SDBse" may sit between the table end and desc_base
#     (1 file in corpus: wave0011.wd) — it is signature padding, layout is
#     unchanged.
#
#   DESCRIPTOR[i] @ desc_base + i*0x20, i in 0..nSamples-1 (contiguous, 0x20 B)
#     +0x00 u32 field0            program/sample flags (0x00010100-style in
#                                 multi-sample programs; 0 when 1:1)
#     +0x04 u32 sampleBodyOffset  (sbo) offset relative to body_start, but the
#                                 array is BIASED by sbo[0] in some banks
#                                 (70/865 files) — universal fix:
#                                 start[i] = body_start + (sbo[i] - sbo[0])
#     +0x08 u32 loopStart         ("sizeOrLoop"; == sbo when no loop; exact
#                                 loop semantics NOT proven here)
#     +0x0C u8  vol               (0xFF typical)
#     +0x0D u8  pan
#     +0x0E u16 spuPitch          Q4.12-ish; NOT converted to Hz here (the
#                                 pitch->sample-rate mapping is unproven —
#                                 WAVs are written at a flat provisional rate)
#     +0x10 u32 adsr1             envelope (bit semantics not decoded)
#     +0x14 u32 adsr2             (0x407f7f3c dominant)
#     +0x18 u64 usually 0; NONZERO marks an out-of-bank reference
#                                 (31 descriptors in 2 files: smikado.wd has
#                                 30, wave0133.wd has 1) — their sbo points
#                                 beyond EOF (companion/streamed data?), so
#                                 they are EXCLUDED from body resolution here.
#
#   body_start = desc_base + nSamples*0x20   (EXACT end of the descriptor
#   array, NO alignment — wave-2 fix, see below)
#
#   ── WAVE-2 ANCHOR FIX (2026-09-14) ──
#   Wave 1 used align32up(desc_end) as the body anchor and marked 25 banks
#   DIRTY (~60% invalid frame headers from the first frames). Wave 2 proved
#   the DIRTY banks were never a second codec: their ADPCM frames are 100%
#   valid, just offset by k = desc_end mod 16 bytes from the aligned anchor.
#   The unified law is anchor = desc_end (unaligned):
#     start[i] = desc_end + (sbo[i] - sbo[0])
#   Evidence (full corpus, 865 files):
#     - 25/25 DIRTY banks: 100.0% valid frames at grid == desc_end (mod 16);
#       k in {4,8,12} per bank, constant across all bodies of the bank.
#     - All 840 previously-CLEAN banks have desc_end % 16 == 0 (pad to the
#       align32 guess was 0 or 16), so both anchors coincide mod 16 there —
#       that is WHY wave 1 guessed align32 and got away with it.
#     - Flag semantics pin the anchor byte-exactly: with anchor=desc_end,
#       5972/5972 bodies start with frame flag 0 and 5962/5972 (99.8%) end
#       with an END flag (1/3/7); with anchor=desc_end+16 only 14.4% end
#       with an END flag (reading mid-sample).
#   Side effect: the 587 banks whose align32 pad was 16 gain ONE leading
#   28-sample frame vs wave 1 output (the frame that lives in what wave 1
#   treated as alignment padding).
#
#   BODY SIZING (proven on this corpus, supersedes naive "next descriptor"):
#     The sbo array is NOT monotonic in every bank — later descriptors may
#     alias earlier bodies (e.g. wave0016.wd s41..s49 repeat sbo of s16..s24).
#     Correct rule: collect distinct starts, sort; each body ends at the next
#     distinct start; the physically-last body ends at EOF. Aliases share the
#     same body. Naive delta sizing produces negative sizes on 11 files.
#
#   BODY CODEC = PS2 SPU-ADPCM (VAG): 16-byte frames -> 28 samples.
#     frame[0]: low nibble = shift (0..12), high nibble = filter (0..4)
#     frame[1]: flags (clean bodies use {0,1,2,3,4,7}; 0=play,1=end,2=loop..)
#     frame[2..15]: 14 bytes = 28 nibbles, LOW nibble first.
#     Standard 5-tap predictor pairs (public SPU-ADPCM table, as in
#     vgmstream/jpsxdec/noclip decoder references — coefficients are public
#     hardware constants, no code copied).
#
# Corpus verdicts (2026-09-14 wave 2, 865 files: 843 proj/sound/wave + 22
#   us/wave): 863/863 non-empty banks decode with ZERO invalid frames under
#   the desc_end anchor (the 25 wave-1 DIRTY banks are RESOLVED — they were
#   never a codec variant, only the mis-aligned anchor). 2 banks (wave2531/
#   4034) are 0x50-byte empty stubs (zero descriptor, no body).
#
# MAINT: research-only script (research_tools/), does NOT ship in the editor.
# Writer/repack is out of scope. Sample rate in output WAVs is provisional.

import argparse
import os
import struct
import sys
import wave
from collections import Counter

# ── SPU-ADPCM constants ────────────────────────────────────────────────────────
# Hardware predictor coefficient pairs (f1, f2) indexed by the 3-bit filter
# nibble. Public PS2/PS1 SPU documentation standard values.
SPU_FILTERS = ((0, 0), (60, 0), (115, -52), (98, -55), (122, -60))
MAX_SHIFT = 12
SAMPLES_PER_FRAME = 28
FRAME_SIZE = 16

# Provisional flat rate: pitch->Hz mapping unproven (see doc header). Only
# affects playback speed, not decode correctness.
PROVISIONAL_RATE_HZ = 24000


class WdFormatError(Exception):
    """Raised when a file cannot be parsed as a .wd container."""


class WdDescriptor:
    __slots__ = ("index", "field0", "sbo", "loop_start", "vol", "pan",
                 "spu_pitch", "adsr1", "adsr2", "reserved18")

    def __init__(self, index, field0, sbo, loop_start, vol, pan, spu_pitch,
                 adsr1, adsr2, reserved18=0):
        self.index = index
        self.field0 = field0
        self.sbo = sbo
        self.loop_start = loop_start
        self.vol = vol
        self.pan = pan
        self.spu_pitch = spu_pitch
        self.adsr1 = adsr1
        self.adsr2 = adsr2
        self.reserved18 = reserved18

    def __repr__(self):
        return (f"desc[{self.index}] f0={self.field0:#010x} sbo={self.sbo:#x} "
                f"loop={self.loop_start:#x} vol={self.vol:#x} pan={self.pan} "
                f"pitch={self.spu_pitch:#06x} adsr1={self.adsr1:#010x} "
                f"adsr2={self.adsr2:#010x}")


class WdSample:
    """A descriptor resolved to a physical body region (or an out-of-bank
    reference when `external` is True — body lives outside this file)."""

    __slots__ = ("descriptor", "start", "size", "is_alias", "external")

    def __init__(self, descriptor, start, size, is_alias, external=False):
        self.descriptor = descriptor
        self.start = start
        self.size = size
        self.is_alias = is_alias
        self.external = external


class WdFile:
    def __init__(self, data, path):
        self.path = path
        self.data = data
        if len(data) < 0x20 or data[:2] != b"WD":
            raise WdFormatError(f"{path}: magic is {data[:2]!r}, expected b'WD'")
        (self.file_id, self.body_size_field, self.n_programs,
         self.n_samples) = struct.unpack_from("<HIII", data, 0x02)
        if self.n_programs == 0 or self.n_samples == 0:
            raise WdFormatError(f"{path}: zero programs/samples "
                                f"({self.n_programs}/{self.n_samples})")
        prog_end = 0x20 + 4 * self.n_programs
        if prog_end > len(data):
            raise WdFormatError(f"{path}: program table overruns file")
        self.prog_table = struct.unpack_from(f"<{self.n_programs}I", data, 0x20)
        # 0xFFFFFFFF entries are sentinels (smikado.wd: 13 declared programs,
        # 3 of them 0xFFFFFFFF) — tolerated, not treated as pointers.
        self.prog_sentinels = sum(1 for p in self.prog_table if p == 0xFFFFFFFF)
        self.desc_base = self.prog_table[0]
        if self.desc_base + self.n_samples * 0x20 > len(data):
            raise WdFormatError(f"{path}: descriptor array overruns file "
                                f"(desc_base={self.desc_base:#x}, "
                                f"nSamples={self.n_samples})")
        # "SDBse" signature padding between program table and descriptors
        # (only wave0011.wd in this corpus). Informational only.
        self.sdbse_tag = b"SDB" in data[prog_end:self.desc_base]

        self.descriptors = []
        for i in range(self.n_samples):
            o = self.desc_base + i * 0x20
            f0, sbo, lp = struct.unpack_from("<III", data, o)
            vol, pan = data[o + 0x0C], data[o + 0x0D]
            pitch, = struct.unpack_from("<H", data, o + 0x0E)
            a1, a2 = struct.unpack_from("<II", data, o + 0x10)
            r18, = struct.unpack_from("<Q", data, o + 0x18)
            self.descriptors.append(
                WdDescriptor(i, f0, sbo, lp, vol, pan, pitch, a1, a2, r18))

        # WAVE-2 FIX: body anchor is the EXACT unaligned end of the
        # descriptor array — NOT align32up. WHY: the 25 wave-1 DIRTY banks
        # are 100% valid SPU-ADPCM whose frame grid sits at desc_end mod 16
        # (k in {4,8,12} past the aligned anchor); clean banks all have
        # desc_end % 16 == 0 so align32 coincided there. Flag semantics
        # (first frame flag 0 in 5972/5972 bodies, END flag 1/3/7 on the
        # last frame in 99.8%) pin desc_end as the byte-exact anchor.
        self.desc_end = self.desc_base + self.n_samples * 0x20
        self.body_start = self.desc_end
        # Distance the wave-1 align32 guess would have introduced. 0 or 16
        # on every previously-clean bank (both keep the grid mod 16);
        # 4/8/12/20/24/28 on the 25 previously-dirty banks broke it.
        self.align32_pad = ((-self.desc_end) % 32)

        # ── Alias-aware body resolution ──
        # WHY: the sbo array is biased by sbo[0] in 70/865 banks and is not
        # monotonic in 11 banks (duplicate/alias descriptors). Distinct starts
        # sorted ascending define physical bodies; each body ends at the next
        # distinct start; the last one ends at EOF. Aliases share a body.
        # Descriptors flagged with reserved18 != 0 point OUTSIDE the bank
        # (sbo beyond EOF — 31 descriptors in smikado.wd/wave0133.wd): they
        # are marked external and excluded from body sizing.
        sbo0 = self.descriptors[0].sbo
        starts = [self.body_start + (d.sbo - sbo0) for d in self.descriptors]
        # Guard st >= desc_end: a real body can never point back into the
        # header/program/descriptor region (defensive; never trips on this
        # corpus — every in-bank start clears desc_end).
        in_bank = [st for d, st in zip(self.descriptors, starts)
                   if d.reserved18 == 0 and self.desc_end <= st < len(data)]
        distinct = sorted(set(in_bank))
        end_of = {}
        for i, s in enumerate(distinct):
            end_of[s] = distinct[i + 1] if i + 1 < len(distinct) else len(self.data)
        self.samples = []
        seen = Counter()
        for d, st in zip(self.descriptors, starts):
            if d.reserved18 != 0 or st >= len(data):
                self.samples.append(WdSample(d, st, 0, False, external=True))
                continue
            size = end_of[st] - st
            seen[st] += 1
            self.samples.append(WdSample(d, st, size, seen[st] > 1))
        self.distinct_bodies = [(s, end_of[s]) for s in distinct]


def decode_spu_adpcm(data, start, size):
    """Decode one SPU-ADPCM body to a list of s16 samples.

    Returns (samples, stats). Invalid frames (filter>4 or shift>12) are still
    decoded defensively (capped coefficients) but counted in stats so callers
    can flag dirty bodies — decode never raises on garbage.
    """
    frames = size // FRAME_SIZE
    samples = []
    append = samples.append
    bad_frames = 0
    flags = Counter()
    h1 = 0
    h2 = 0
    for f in range(frames):
        o = start + f * FRAME_SIZE
        if o + FRAME_SIZE > len(data):
            break
        hdr = data[o]
        flag = data[o + 1]
        flags[flag] += 1
        shift = hdr & 0xF
        filt = (hdr >> 4) & 0xF
        if filt > 4 or shift > MAX_SHIFT:
            bad_frames += 1
            f1, f2 = SPU_FILTERS[0]
            shift = min(shift, MAX_SHIFT)
        else:
            f1, f2 = SPU_FILTERS[filt]
        for j in range(2, FRAME_SIZE):
            b = data[o + j]
            for nib in (b & 0x0F, (b >> 4) & 0x0F):
                n = nib - 16 if nib >= 8 else nib
                s = (n << 12) >> shift
                s += (f1 * h1 + f2 * h2) >> 6
                if s > 32767:
                    s = 32767
                elif s < -32768:
                    s = -32768
                h2 = h1
                h1 = s
                append(s)
    stats = {
        "frames": frames,
        "decoded": len(samples),
        "bad_frames": bad_frames,
        "expected_samples": frames * SAMPLES_PER_FRAME,
        "flags": flags,
    }
    return samples, stats


def write_wav(path, samples, rate=PROVISIONAL_RATE_HZ):
    """Write mono 16-bit PCM RIFF WAV (stdlib `wave` writes the header)."""
    payload = struct.pack(f"<{len(samples)}h", *samples)
    with wave.open(path, "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(payload)


def validate_body(data, start, size):
    """Cheap structural frame validation (no PCM decode)."""
    frames = size // FRAME_SIZE
    bad = 0
    for f in range(frames):
        o = start + f * FRAME_SIZE
        if o + FRAME_SIZE > len(data):
            bad += 1
            continue
        hdr = data[o]
        if (hdr >> 4) & 0xF > 4 or (hdr & 0xF) > MAX_SHIFT:
            bad += 1
    return frames, bad


def scan_corpus(root):
    """Walk root for *.wd, parse and structurally validate everything.

    Returns (per_file_results, aggregate_stats). Verdicts:
      CLEAN  — every distinct body has >=1 frame and 0 invalid frames
      DIRTY  — some body contains invalid frames (codec variant suspicion)
      EMPTY  — no in-file body at all (0x50-byte stub banks)
    External descriptors (reserved18 != 0) are excluded from sizing and
    counted; they never fail a file.
    """
    results = []
    agg = {
        "files": 0, "parsed": 0, "clean": 0, "dirty": 0, "empty": 0,
        "parse_errors": 0, "distinct_bodies": 0, "clean_bodies": 0,
        "alias_descriptors": 0, "sbo0_bias_files": 0, "sdbse_files": 0,
        "nonmonotonic_files": 0, "bad_frames_total": 0,
        "frames_total": 0, "external_descriptors": 0,
        "prog_sentinel_files": 0,
        "dirty_file_list": [], "parse_error_list": [], "empty_file_list": [],
    }
    for dirpath, _dirs, files in os.walk(root):
        for name in sorted(files):
            if not name.lower().endswith(".wd"):
                continue
            path = os.path.join(dirpath, name)
            agg["files"] += 1
            try:
                with open(path, "rb") as fh:
                    wd = WdFile(fh.read(), path)
            except (OSError, WdFormatError) as exc:
                agg["parse_errors"] += 1
                agg["parse_error_list"].append(str(exc))
                results.append((path, "PARSE_ERROR", str(exc), None))
                continue
            agg["parsed"] += 1
            if wd.sdbse_tag:
                agg["sdbse_files"] += 1
            if wd.descriptors[0].sbo != 0:
                agg["sbo0_bias_files"] += 1
            if wd.prog_sentinels:
                agg["prog_sentinel_files"] += 1
            sbos = [d.sbo for d in wd.descriptors]
            if any(sbos[i + 1] < sbos[i] for i in range(len(sbos) - 1)):
                agg["nonmonotonic_files"] += 1
            agg["alias_descriptors"] += sum(1 for s in wd.samples if s.is_alias)
            agg["external_descriptors"] += sum(
                1 for s in wd.samples if s.external)

            verdict = "CLEAN"
            reasons = []
            dirty_bodies = 0
            zero_frame_bodies = 0
            for s_start, s_end in wd.distinct_bodies:
                size = s_end - s_start
                frames, bad = validate_body(wd.data, s_start, size)
                agg["distinct_bodies"] += 1
                agg["frames_total"] += frames
                if frames == 0:
                    zero_frame_bodies += 1
                    continue
                if bad == 0:
                    agg["clean_bodies"] += 1
                else:
                    dirty_bodies += 1
                    agg["bad_frames_total"] += bad
            n_ext = sum(1 for s in wd.samples if s.external)
            if not wd.distinct_bodies:
                verdict = "EMPTY"
                reasons.append("no in-file body (stub bank)")
                agg["empty"] += 1
                agg["empty_file_list"].append(os.path.relpath(path, root))
            elif dirty_bodies:
                verdict = "DIRTY"
                reasons.append(f"{dirty_bodies} bodies with invalid frames")
                agg["dirty"] += 1
                agg["dirty_file_list"].append(
                    os.path.relpath(path, root))
            else:
                agg["clean"] += 1
                if zero_frame_bodies:
                    reasons.append(
                        f"{zero_frame_bodies} zero-frame bodies (stubs)")
            if n_ext:
                reasons.append(f"{n_ext} external descriptors "
                               f"(reserved18!=0, body out of bank)")
            results.append((path, verdict, "; ".join(reasons), wd))
    return results, agg


def decode_some(results, out_dir, limit):
    """Decode up to `limit` distinct CLEAN bodies to WAV in out_dir."""
    os.makedirs(out_dir, exist_ok=True)
    written = []
    decoded_total = 0
    checked = 0
    for path, verdict, _why, wd in results:
        if verdict != "CLEAN" or wd is None:
            continue
        for s_start, s_end in wd.distinct_bodies:
            if checked >= limit:
                return written, decoded_total
            samples, stats = decode_spu_adpcm(wd.data, s_start, s_end - s_start)
            checked += 1
            if not samples:
                continue
            base = os.path.splitext(os.path.basename(path))[0]
            out = os.path.join(out_dir, f"{base}_b{s_start:08x}.wav")
            write_wav(out, samples)
            # Self-verify: reopen with the stdlib wave parser (RIFF sanity).
            with wave.open(out, "rb") as w:
                assert w.getnframes() == len(samples), out
                assert w.getframerate() == PROVISIONAL_RATE_HZ, out
            peak = max(abs(s) for s in samples)
            nonzero = sum(1 for s in samples if s) / max(len(samples), 1)
            written.append((out, len(samples), stats["frames"], peak, nonzero))
            decoded_total += len(samples)
    return written, decoded_total


def decode_file(path, out_dir):
    """Decode ALL distinct in-bank bodies of one .wd file to WAV + stats.

    Added in wave 2 to prove the desc_end anchor on the previously-DIRTY
    banks (audio sanity: peak amplitude and non-zero ratio, WAV re-opened
    with the stdlib wave parser). Returns list of per-body stat rows.
    """
    os.makedirs(out_dir, exist_ok=True)
    with open(path, "rb") as fh:
        wd = WdFile(fh.read(), path)
    base = os.path.splitext(os.path.basename(path))[0]
    rows = []
    for s_start, s_end in wd.distinct_bodies:
        samples, stats = decode_spu_adpcm(wd.data, s_start, s_end - s_start)
        if not samples:
            continue
        out = os.path.join(out_dir, f"{base}_b{s_start:08x}.wav")
        write_wav(out, samples)
        with wave.open(out, "rb") as w:  # RIFF sanity self-check
            assert w.getnframes() == len(samples), out
        peak = max(abs(s) for s in samples)
        nonzero = sum(1 for s in samples if s) / max(len(samples), 1)
        end_flags = sum(1 for f, c in stats["flags"].items() if f in (1, 3, 7))
        rows.append((out, len(samples), stats["frames"], stats["bad_frames"],
                     peak, nonzero, end_flags))
    return rows


def dump_file(path):
    """Verbose single-file layout dump (header, tables, descriptors, bodies)."""
    with open(path, "rb") as fh:
        data = fh.read()
    wd = WdFile(data, path)
    print(f"file        : {path} ({len(data)} bytes)")
    print(f"magic/id    : 'WD' id={wd.file_id} (expect {os.path.basename(path)})")
    print(f"bodySize@04 : {wd.body_size_field:#x} (allocation hint, not body len)")
    print(f"programs    : {wd.n_programs}  samples: {wd.n_samples}")
    print(f"prog table  : {[hex(p) for p in wd.prog_table]}")
    print(f"desc_base   : {wd.desc_base:#x}  body_start(anchor=desc_end): "
          f"{wd.body_start:#x}  align32_pad: {wd.align32_pad}")
    print(f"SDBse tag   : {wd.sdbse_tag}")
    print(f"sbo[0] bias : {wd.descriptors[0].sbo:#x}"
          + ("  (biased, fixed)" if wd.descriptors[0].sbo else ""))
    print("descriptors :")
    for s in wd.samples:
        d = s.descriptor
        alias = " ALIAS" if s.is_alias else ""
        ext = " EXTERNAL(r18!=0)" if s.external else ""
        print(f"  [{d.index:3d}] f0={d.field0:#010x} sbo={d.sbo:8d} "
              f"loop={d.loop_start:8d} vol={d.vol:#04x} pan={d.pan:3d} "
              f"pitch={d.spu_pitch:#06x} adsr={d.adsr1:#010x}/{d.adsr2:#010x}"
              f" -> start={s.start:#08x} size={s.size}{alias}{ext}")
    print("bodies (distinct, sorted):")
    total_frames = 0
    total_bad = 0
    for s_start, s_end in wd.distinct_bodies:
        frames, bad = validate_body(wd.data, s_start, s_end - s_start)
        total_frames += frames
        total_bad += bad
        print(f"  {s_start:#08x}..{s_end:#08x}  {s_end - s_start:8d} B  "
              f"frames={frames:6d} bad={bad}")
    print(f"total frames={total_frames} bad={total_bad} "
          f"-> PCM @ {PROVISIONAL_RATE_HZ} Hz: "
          f"{total_frames * SAMPLES_PER_FRAME / PROVISIONAL_RATE_HZ:.3f} s")


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="FFX PS2 .wd reader/validator + SPU-ADPCM decoder "
                    "(stdlib-only research tool)")
    ap.add_argument("root", help="corpus root to scan for *.wd")
    ap.add_argument("--file", help="verbose single-file dump instead of scan")
    ap.add_argument("--decode", type=int, default=0, metavar="N",
                    help="decode N distinct CLEAN bodies to WAV")
    ap.add_argument("--decode-file",
                    help="decode ALL bodies of this single .wd to WAV")
    ap.add_argument("--out", default="/tmp/ffx_wd_decode",
                    help="output dir for WAVs (default /tmp/ffx_wd_decode)")
    args = ap.parse_args(argv)

    if args.file:
        dump_file(args.file)
        return 0

    if args.decode_file:
        rows = decode_file(args.decode_file, args.out)
        print(f"== decoded {len(rows)} bodies of {args.decode_file} -> "
              f"{args.out}")
        for out, ns, frames, bad, peak, nonzero, endf in rows:
            print(f"    {os.path.basename(out)}: {ns} samples ({frames} "
                  f"frames, bad={bad}) peak={peak} "
                  f"nonzero={nonzero * 100:.1f}% end-flags={endf}")
        return 0

    results, agg = scan_corpus(args.root)
    print(f"== .wd corpus scan: {args.root}")
    print(f"files found          : {agg['files']}")
    print(f"parsed OK            : {agg['parsed']}")
    print(f"parse errors         : {agg['parse_errors']}")
    for e in agg["parse_error_list"][:20]:
        print(f"    {e}")
    print(f"CLEAN (0 bad frames) : {agg['clean']}/{agg['parsed']} "
          f"({agg['clean'] / max(agg['parsed'], 1) * 100:.1f}%)")
    print(f"DIRTY (invalid frames): {agg['dirty']}  EMPTY stub banks: "
          f"{agg['empty']}")
    print(f"distinct bodies      : {agg['distinct_bodies']} "
          f"(clean: {agg['clean_bodies']}, "
          f"bad frames total: {agg['bad_frames_total']}/{agg['frames_total']})")
    print(f"alias descriptors    : {agg['alias_descriptors']} "
          f"(non-monotonic banks: {agg['nonmonotonic_files']})")
    print(f"external descriptors : {agg['external_descriptors']} "
          f"(banks with 0xFFFFFFFF prog sentinels: "
          f"{agg['prog_sentinel_files']})")
    print(f"sbo[0]!=0 bias banks : {agg['sbo0_bias_files']}   "
          f"SDBse-tagged banks: {agg['sdbse_files']}")
    if agg["empty_file_list"]:
        print(f"empty stub banks ({len(agg['empty_file_list'])}):")
        for f in agg["empty_file_list"]:
            print(f"    {f}")
    print(f"dirty files ({len(agg['dirty_file_list'])}):")
    for f in agg["dirty_file_list"]:
        print(f"    {f}")
    if agg["frames_total"]:
        pcm_s = agg["frames_total"] * SAMPLES_PER_FRAME / PROVISIONAL_RATE_HZ
        print(f"total body PCM @ {PROVISIONAL_RATE_HZ} Hz (provisional rate): "
              f"{pcm_s:.1f} s")

    if args.decode > 0:
        written, decoded_total = decode_some(results, args.out, args.decode)
        print(f"== decoded {len(written)} bodies -> {args.out} "
              f"({decoded_total} samples, "
              f"{decoded_total / PROVISIONAL_RATE_HZ:.1f} s @ "
              f"{PROVISIONAL_RATE_HZ} Hz; each WAV re-opened with stdlib "
              f"wave parser for RIFF sanity)")
        for out, ns, frames, peak, nonzero in written[:10]:
            print(f"    {os.path.basename(out)}: {ns} samples "
                  f"({frames} frames) peak={peak} nonzero={nonzero * 100:.1f}%")
        if len(written) > 10:
            print(f"    ... and {len(written) - 10} more")
    return 0


if __name__ == "__main__":
    sys.exit(main())
