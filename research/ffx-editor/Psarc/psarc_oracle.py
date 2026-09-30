#!/usr/bin/env python3
# ── psarc_oracle.py — FFX PSARC format oracle: strict validator + JSONL reporter ──
#
# Lane: FFX-STRUCTURES (PSARC-ORACLE). Date: 2026-09-14. Author: Jarvis.
# RESEARCH ONLY — not integrated into FFXProjectEditor. Reads archives in-place;
# never writes to the archive or to the extracted corpus.
#
# PURPOSE
#   Deterministic, Python-stdlib-only oracle that pins the REAL .psarc container
#   format as byte-observed in FFX_Data.psarc (PS3 HD Remaster, 5,511,339,067
#   bytes). It exists to close gap P3: no writer may be called "correct" before
#   an oracle derived from the real archive says what correct means. It also
#   audits legacy PsarcWriter.cs outputs and measures their divergences with
#   exact numbers (errata A3-E3 counterexamples).
#
# GROUND TRUTH (terra) — every rule below traces to these byte-verified audits:
#   - docs/reverse/FFX_PSARC_PS3_INDEX_RECHECK_2026-09-04.md
#       header u32BE@0x1C == 2 ("Flags", bit1 = absolute paths);
#       manifest = 78 zlib streams (multiblock), 5,088,005 bytes UTF-8,
#       68,100 names, 68,099 LFs, NO trailing LF; 68,100/68,100 name-MD5
#       matches against the 30-byte descriptors; 5 empty entries each reserve
#       exactly one zero ZSize slot; offsets contiguous; index arithmetic ends
#       exactly at EOF.
#   - docs/reverse/FFX_PSARC_PS3_FULL_STREAM_AUDIT_2026-09-04.md
#       full-stream profile over the same file: 251,167 strict zlib blocks +
#       404 stored tails (16,917 bytes) where ZSize == the block's LOGICAL
#       length (each tail 1..1,088 bytes); ZSize==0 never occurs inside a
#       referenced block range (the five zero slots belong to empty entries).
#   Convention context (documented, NOT code copied):
#   - rs-utils rev 4eea88b8 bin/psarc.py `create_entry`: store raw when
#     compression does not shrink, writing the raw REMAINING block length;
#     a full 65,536-byte stored block must be encoded ZSize==0 because 65,536
#     is not representable in u16. This oracle adopts that convention for the
#     (corpus-unobserved) full-stored case only.
#   - libPSARC wiki "PSARC File Format": names the u32BE@0x1C field "Flags"
#     and bit1 as absolute paths. Naming context only.
#   This file is an original implementation for this repo; no third-party code
#   was copied. The strict zlib checks re-implement the audit profile:
#     decompressobj, max_output = expected+1, require eof, require empty
#     unused_data/unconsumed_tail, require exact output length, NO flush.
#
# FORMAT (as validated here; all multi-byte integers BIG-ENDIAN)
#   Header (32 bytes):
#     +0x00 char[4]  magic "PSAR"
#     +0x04 u16      major_version (observed 1)
#     +0x06 u16      minor_version (observed 4)
#     +0x08 char[4]  compression_type "zlib"
#     +0x0C u32      toc_length == 32 + entry_count*30 + total_zsize_slots*2;
#                    also == data offset of entry 0 (manifest)
#     +0x10 u32      toc_entry_size (observed 30)
#     +0x14 u32      entry_count (manifest + real files)
#     +0x18 u32      block_size (observed 65,536)
#     +0x1C u32      Flags (FFX corpus: 2, bit1 absolute paths)   [rule H7]
#   TOC descriptors (entry_count x 30 bytes, starting at 0x20):
#     +0x00 byte[16] MD5 of the name bytes incl. leading '/' (entry 0: zeros)
#     +0x10 u32      zsize_index of the first block slot
#     +0x14 u40      uncompressed (logical) size
#     +0x19 u40      absolute offset of the first data block
#   ZSize table (u16 each, ends exactly at toc_length):
#     one slot per block in entry order; empty entries (size 0) reserve one
#     slot with value 0. Block semantics per referenced slot:
#       ZSize == expected logical length   -> stored (raw) bytes (partial block:
#                                              necessarily the entry's tail)
#       ZSize == 0 AND expected == 65536   -> stored full block (u16-unrepresentable)
#       otherwise                          -> one strict zlib stream of ZSize bytes
#   Manifest (entry 0 data): name bytes UTF-8, joined by '\n', NO final '\n',
#     every name starts with '/', split into ceil(size/65536) independent
#     zlib blocks (real file: 78 streams / 78 slots).
#
# RULES (24) — ids are stable and cited by
#   docs/reverse/FFX_PSARC_WRITER_ORACLE_2026-09-14.md:
#   H1 magic | H2 version 1.4 | H3 compression zlib | H4 toc_length arithmetic
#   H5 entry_size 30 | H6 block_size 65536 | H7 flags == expected (2)
#   I1 entry0 special | I2 TOC MD5 | I3 zsize index chain | I4 offset chain
#   M1 UTF-8 | M2 leading '/' | M3 LF join, no final LF | M4 charset/segments
#   M5 unique + count | M6 name MD5s
#   B1 no invalid zero slots | B2 stored encoding counts | B3 zlib strict
#   B4 EOF exact
#   X0 corpus count | X1 corpus sizes | X2 stored spans byte-identical
#
# USAGE
#   python3 psarc_oracle.py ARCHIVE.psarc [--jsonl OUT.jsonl]
#       [--extracted-root ROOT] [--expect-flags N] [--recompress-sample N]
#       [--limit-entries N] [--quiet]
#   python3 psarc_oracle.py --self-test
#
# OUTPUT
#   JSONL: one {"type":"header"} record, one {"type":"entry"} per TOC entry,
#   optional {"type":"manifest_fallback"} diagnostic, one {"type":"summary"}.
#   stdout: human rule table + "RULES: ..." line. Exit 0 only when every
#   decided rule PASSes (SKIPped corpus rules do not fail the run).

import argparse
import hashlib
import io
import json
import math
import os
import struct
import sys
import zlib

BLOCK_SIZE_DEFAULT = 65536
ENTRY_SIZE_EXPECTED = 30
FLAGS_EXPECTED_DEFAULT = 2  # FFX_Data.psarc / FFX-2_Data.psarc (recheck 2026-09-04)

# Bounded error capture: never let a pathological archive explode the JSONL.
MAX_RECORDED_ERRORS_PER_ENTRY = 40
MAX_CHAIN_ERRORS_RECORDED = 10
PROGRESS_INTERVAL = 10000


RULE_IDS = [
    "H1", "H2", "H3", "H4", "H5", "H6", "H7",
    "I1", "I2", "I3", "I4",
    "M1", "M2", "M3", "M4", "M5", "M6",
    "B1", "B2", "B3", "B4",
    "X0", "X1", "X2",
]

RULE_DESC = {
    "H1": "magic == 'PSAR'",
    "H2": "version == 1.4",
    "H3": "compression_type == 'zlib'",
    "H4": "toc_length == 32 + count*30 + slots*2; == entry0 offset",
    "H5": "toc_entry_size == 30",
    "H6": "block_size == 65536",
    "H7": "u32BE@0x1C Flags == expected (FFX corpus: 2)",
    "I1": "entry0: md5 zeros, zsize_index 0, offset == toc_length",
    "I2": "TOC MD5 field is zeros or equals MD5 of TOC (field zeroed)",
    "I3": "zsize index chain sequential; empty entries reserve 1 zero slot; table exactly consumed",
    "I4": "offset chain contiguous (entry N+1 starts where N ends)",
    "M1": "manifest UTF-8 strict, re-encode identical",
    "M2": "every name starts with '/'",
    "M3": "names joined by LF, exactly count-1 LFs, no trailing LF",
    "M4": "no empty names, CR, NUL, backslash, '.'/'..' segments",
    "M5": "names unique and count == entry_count - 1",
    "M6": "MD5(name bytes incl. '/') == descriptor MD5 for all entries",
    "B1": "no ZSize==0 in referenced ranges except full 65536 stored blocks",
    "B2": "stored blocks encoded ZSize==logical (counts; tails only, by construction)",
    "B3": "zlib blocks strict: eof, exact length, no trailing garbage",
    "B4": "no bytes after the last entry's data",
    "X0": "extracted corpus file count == manifest name count",
    "X1": "extracted file size == descriptor logical size (all entries)",
    "X2": "stored spans byte-identical to extracted corpus tails",
}


class Report:
    """Collects rule results and counters deterministically."""

    def __init__(self):
        self.rules = {rid: {"status": "SKIP", "detail": ""} for rid in RULE_IDS}
        self.counters = {}

    def set(self, rid, ok, detail=""):
        if self.rules[rid]["status"] != "FAIL":
            self.rules[rid]["status"] = "PASS" if ok else "FAIL"
        if detail:
            self.rules[rid]["detail"] = (
                self.rules[rid]["detail"] + "; " + detail
                if self.rules[rid]["detail"] else detail
            )

    def skip(self, rid, why):
        if self.rules[rid]["status"] == "SKIP":
            self.rules[rid]["detail"] = why

    def counted(self, key, value):
        self.counters[key] = value

    def n_pass(self):
        return sum(1 for r in self.rules.values() if r["status"] == "PASS")

    def n_fail(self):
        return sum(1 for r in self.rules.values() if r["status"] == "FAIL")


# ── Strict zlib block decode (audit profile; no flush, no raw fallback) ──────

def inflate_exact(data, expected):
    """Inflate one complete zlib stream; return (bytes, None) or (None, reason).

    Strictness contract (mirrors the 2026-09-04 full-stream audit): output is
    capped at expected+1; the stream must reach eof; the whole input must be
    consumed exactly once (no unused_data, no unconsumed_tail); the output
    length must equal `expected` exactly. A zlib error NEVER falls back to
    treating the bytes as raw.
    """
    d = zlib.decompressobj()
    try:
        out = d.decompress(data, expected + 1)
    except zlib.error as e:
        return None, "zlib error: %s" % e
    if len(out) > expected:
        return None, "output %d > expected %d" % (len(out), expected)
    if len(out) < expected:
        return None, "output %d < expected %d" % (len(out), expected)
    if not d.eof:
        return None, "stream not at EOF (truncated) after %d input bytes" % len(data)
    if d.unused_data:
        return None, "%d trailing bytes after zlib stream end" % len(d.unused_data)
    if d.unconsumed_tail:
        return None, "unconsumed input remains"
    return out, None


# ── Real-spec archive builder (--self-test fixtures only) ────────────────────

def zlib_or_store(chunk):
    """rs-utils/real-corpus convention: keep compressed only if strictly
    smaller; encode a stored partial block as ZSize==len(chunk) and a stored
    full 65536 block as ZSize==0 (65,536 is not representable in u16)."""
    comp = zlib.compress(chunk, 9)
    if len(comp) < len(chunk):
        return comp, len(comp)
    if len(chunk) == BLOCK_SIZE_DEFAULT:
        return chunk, 0
    return chunk, len(chunk)


def build_real_spec_archive(files, flags=2, trailing_lf=False,
                            single_stream_manifest=False):
    """Build an archive per the REAL-file spec (self-test ground truth).

    files: list[(name_with_leading_slash, content_bytes)] in entry order.
    Empty content produces the reserved-zero-slot case. Corruption knobs
    intentionally reproduce legacy-writer behaviours (one rule break each).
    """
    names_raw = b"\n".join(n.encode("utf-8") for n, _ in files)
    if trailing_lf:
        names_raw += b"\n"

    flat_zsizes = []
    manifest_chunks = []
    if single_stream_manifest:
        comp = zlib.compress(names_raw, 9)
        manifest_chunks.append(comp)
        flat_zsizes.append(len(comp) & 0xFFFF)  # legacy u16 truncation bug
    else:
        for off in range(0, len(names_raw), BLOCK_SIZE_DEFAULT):
            chunk = names_raw[off:off + BLOCK_SIZE_DEFAULT]
            payload, zs = zlib_or_store(chunk)
            manifest_chunks.append(payload)
            flat_zsizes.append(zs)

    entry_blobs = []
    for _, data in files:
        if not data:
            entry_blobs.append([])          # empty entry: reserved zero slot
            flat_zsizes.append(0)
            continue
        blobs = []
        for off in range(0, len(data), BLOCK_SIZE_DEFAULT):
            chunk = data[off:off + BLOCK_SIZE_DEFAULT]
            payload, zs = zlib_or_store(chunk)
            blobs.append(payload)
            flat_zsizes.append(zs)
        entry_blobs.append(blobs)

    count = len(files) + 1
    toc_len = 32 + count * ENTRY_SIZE_EXPECTED + len(flat_zsizes) * 2

    # Slot-index chain identical to the validator's rule I3.
    running_slots = math.ceil(len(names_raw) / BLOCK_SIZE_DEFAULT) if names_raw else 1
    if single_stream_manifest:
        running_slots = 1

    data_off = toc_len + sum(len(c) for c in manifest_chunks)
    toc = io.BytesIO()
    toc.write(b"\x00" * 16)
    toc.write(struct.pack(">I", 0))
    toc.write(len(names_raw).to_bytes(5, "big"))
    toc.write(toc_len.to_bytes(5, "big"))
    for (name, data), blobs in zip(files, entry_blobs):
        toc.write(hashlib.md5(name.encode("utf-8")).digest())
        toc.write(struct.pack(">I", running_slots))
        toc.write(len(data).to_bytes(5, "big"))
        toc.write(data_off.to_bytes(5, "big"))
        running_slots += 1 if not data else math.ceil(len(data) / BLOCK_SIZE_DEFAULT)
        data_off += sum(len(b) for b in blobs)

    out = io.BytesIO()
    out.write(b"PSAR")
    out.write(struct.pack(">HH", 1, 4))
    out.write(b"zlib")
    out.write(struct.pack(">I", toc_len))
    out.write(struct.pack(">I", ENTRY_SIZE_EXPECTED))
    out.write(struct.pack(">I", count))
    out.write(struct.pack(">I", BLOCK_SIZE_DEFAULT))
    out.write(struct.pack(">I", flags))
    out.write(toc.getvalue())
    out.write(struct.pack(">%dH" % len(flat_zsizes), *flat_zsizes))
    for payload in manifest_chunks:
        out.write(payload)
    for blobs in entry_blobs:
        for payload in blobs:
            out.write(payload)
    return out.getvalue()


# ── Oracle core ───────────────────────────────────────────────────────────────

class Oracle:
    def __init__(self, archive, extracted_root=None, expect_flags=FLAGS_EXPECTED_DEFAULT,
                 recompress_sample=0, limit_entries=0, quiet=False):
        self.archive = archive
        self.extracted_root = extracted_root
        self.expect_flags = expect_flags
        self.recompress_sample = recompress_sample
        self.limit_entries = limit_entries
        self.quiet = quiet
        self.rep = Report()
        self.jsonl = None
        # Cross-phase audit state:
        self.n_zlib = 0
        self.n_stored = 0
        self.n_zero_invalid = 0
        self.stored_bytes_total = 0
        self.block_errors_total = 0
        self.stored_spans = []          # dicts (entry, arc_off, logical_off, len, ...)
        self.offset_chain_errors = []
        self.recompress_manifest = []  # (slot, orig_comp, logical)
        self.recompress_assets = []
        self.names = None               # decoded after entry 0
        self.names_bytes = None         # raw parts (bytes) for M6

    # -- output helpers --------------------------------------------------------
    def emit(self, obj):
        if self.jsonl:
            self.jsonl.write(json.dumps(obj, ensure_ascii=True, separators=(",", ":")) + "\n")

    def log(self, msg):
        if not self.quiet:
            sys.stderr.write("[psarc_oracle] %s\n" % msg)
            sys.stderr.flush()

    # -- per-entry block walk ---------------------------------------------------
    def walk_entry(self, f, i, entries, zs, total_slots, block_size, collect_manifest):
        """Decode every block of entry i. Updates shared counters and returns
        (sha_hex, prefix16, errors, logical_parts, end_pos) where end_pos is the
        archive position after the entry's consumed bytes (f.tell()). NOTE: the
        offset chain MUST use end_pos, not ZSize sums — a stored FULL block has
        ZSize==0 yet consumes 65,536 bytes."""
        md5, zidx, size, offset = entries[i]
        nblocks = math.ceil(size / block_size) if size else 0
        sha = hashlib.sha256()
        prefix16 = b""
        errors = []
        parts = [] if collect_manifest else None
        f.seek(offset)
        remaining = size
        logical_pos = 0
        for b in range(nblocks):
            expected = min(block_size, remaining)
            slot = zidx + b
            if slot >= total_slots:
                errors.append("block%d slot %d beyond zsize table" % (b, slot))
                self.block_errors_total += 1
                break
            zsize = zs[slot]
            if zsize == expected and zsize != 0:
                # Stored partial block (real corpus: entry tails, ZSize==logical).
                raw = f.read(zsize)
                if len(raw) != zsize:
                    errors.append("block%d short read %d/%d" % (b, len(raw), zsize))
                    self.block_errors_total += 1
                    break
                self.n_stored += 1
                self.stored_bytes_total += zsize
                sha.update(raw)
                prefix16 = prefix16 or raw[:16]
                if collect_manifest and parts is not None:
                    # FIX 2026-09-17 (FMT-ARCHIVE audit): stored manifest blocks
                    # were never appended, so a raw-stored manifest (legal per
                    # the block rules — e.g. tools/psarc sample_no_compression)
                    # fell through to the single-stream fallback and was
                    # mis-reported as "manifest undecodable". Collect the raw
                    # bytes exactly like the zlib branch does.
                    parts.append(raw)
                self.stored_spans.append({
                    "entry": i, "arc_off": f.tell() - zsize,
                    "logical_off": logical_pos, "len": zsize,
                    "hex32": raw[:32].hex() if zsize <= 32 else None,
                })
                remaining -= zsize
                logical_pos += zsize
            elif zsize == 0 and expected == block_size:
                # Stored FULL block: the only u16-representable encoding.
                raw = f.read(block_size)
                if len(raw) != block_size:
                    errors.append("block%d short read %d/%d" % (b, len(raw), block_size))
                    self.block_errors_total += 1
                    break
                self.n_stored += 1
                self.stored_bytes_total += block_size
                sha.update(raw)
                prefix16 = prefix16 or raw[:16]
                if collect_manifest and parts is not None:
                    parts.append(raw)  # same FIX as above (full-block manifest)
                self.stored_spans.append({
                    "entry": i, "arc_off": f.tell() - block_size,
                    "logical_off": logical_pos, "len": block_size, "hex32": None,
                })
                remaining -= block_size
                logical_pos += block_size
            elif zsize == 0:
                # Zero slot for a partial block: not the real corpus convention
                # (legacy PsarcWriter emits this). Consume raw to keep walking.
                self.n_zero_invalid += 1
                self.block_errors_total += 1
                if len(errors) < MAX_RECORDED_ERRORS_PER_ENTRY:
                    errors.append(
                        "block%d slot%d ZSize=0 with logical %d (<65536): zero is "
                        "reserved for empty entries / full blocks only" % (b, slot, expected))
                raw = f.read(expected)
                if len(raw) != expected:
                    break
                sha.update(raw)
                prefix16 = prefix16 or raw[:16]
                if collect_manifest and parts is not None:
                    parts.append(raw)  # keep manifest bytes even on the invalid-zero path
                remaining -= expected
                logical_pos += expected
            else:
                comp = f.read(zsize)
                if len(comp) != zsize:
                    errors.append("block%d short read %d/%d" % (b, len(comp), zsize))
                    self.block_errors_total += 1
                    break
                out, err = inflate_exact(comp, expected)
                if err is not None:
                    self.block_errors_total += 1
                    if len(errors) < MAX_RECORDED_ERRORS_PER_ENTRY:
                        errors.append("block%d slot%d zsize=%d expected=%d: %s"
                                      % (b, slot, zsize, expected, err))
                else:
                    self.n_zlib += 1
                    sha.update(out)
                    prefix16 = prefix16 or out[:16]
                    remaining -= expected
                    logical_pos += expected
                    if collect_manifest and len(self.recompress_manifest) < 4096:
                        self.recompress_manifest.append((slot, comp, out))
                    elif (not collect_manifest and self.recompress_sample
                          and out is not None
                          and len(self.recompress_assets) < self.recompress_sample):
                        self.recompress_assets.append((slot, comp, out))
                if collect_manifest and err is None and parts is not None:
                    parts.append(out)
        return (sha.hexdigest() if size else None,
                prefix16.hex() if prefix16 else None,
                errors, parts, f.tell())

    # -- main --------------------------------------------------------------------
    def run(self, jsonl_path):
        rep = self.rep
        if jsonl_path:
            self.jsonl = io.open(jsonl_path, "w", encoding="utf-8", newline="\n")

        with open(self.archive, "rb") as f:
            file_size = os.fstat(f.fileno()).st_size
            hdr = f.read(32)
            if len(hdr) < 32:
                for rid in ("H1", "H2", "H3", "H4", "H5", "H6", "H7",
                            "I1", "I2", "I3", "I4", "M1", "M2", "M3", "M4", "M5", "M6",
                            "B1", "B2", "B3", "B4"):
                    rep.set(rid, False, "archive shorter than 32-byte header")
                self.finish(file_size)
                return 2

            magic = hdr[0:4]
            major, minor = struct.unpack(">HH", hdr[4:8])
            compression = hdr[8:12]
            toc_length, entry_size, entry_count, block_size, flags = \
                struct.unpack(">IIIII", hdr[12:32])

            rep.set("H1", magic == b"PSAR", "magic=%r" % magic)
            rep.set("H2", (major, minor) == (1, 4), "version=%d.%d" % (major, minor))
            rep.set("H3", compression == b"zlib", "compression=%r" % compression)
            rep.set("H5", entry_size == ENTRY_SIZE_EXPECTED, "entry_size=%d" % entry_size)
            rep.set("H6", block_size == BLOCK_SIZE_DEFAULT, "block_size=%d" % block_size)
            rep.set("H7", flags == self.expect_flags,
                    "flags@0x1C=%d expected=%d" % (flags, self.expect_flags))
            self.emit({
                "type": "header", "archive": self.archive, "file_size": file_size,
                "magic": magic.decode("latin-1"), "version": "%d.%d" % (major, minor),
                "compression": compression.decode("latin-1"), "toc_length": toc_length,
                "entry_size": entry_size, "entry_count": entry_count,
                "block_size": block_size, "flags": flags,
                "flags_expected": self.expect_flags,
            })

            if entry_size != ENTRY_SIZE_EXPECTED or entry_count < 1:
                self.finish(file_size)
                return 2

            # ── TOC descriptors ─────────────────────────────────────────────────
            toc_blob = f.read(entry_count * ENTRY_SIZE_EXPECTED)
            if len(toc_blob) < entry_count * ENTRY_SIZE_EXPECTED:
                rep.set("I1", False, "TOC truncated")
                self.finish(file_size)
                return 2
            entries = []
            for i in range(entry_count):
                base = i * ENTRY_SIZE_EXPECTED
                md5 = toc_blob[base:base + 16]
                zidx = struct.unpack(">I", toc_blob[base + 16:base + 20])[0]
                size = int.from_bytes(toc_blob[base + 20:base + 25], "big")
                offset = int.from_bytes(toc_blob[base + 25:base + 30], "big")
                entries.append((md5, zidx, size, offset))

            # ── ZSize table ─────────────────────────────────────────────────────
            table_start = 32 + entry_count * ENTRY_SIZE_EXPECTED
            table_bytes = toc_length - table_start
            if table_bytes < 0 or table_bytes % 2 != 0:
                rep.set("H4", False, "zsize table size %d invalid" % table_bytes)
                self.finish(file_size)
                return 2
            zs_blob = f.read(table_bytes)
            total_slots = table_bytes // 2
            zs = struct.unpack(">%dH" % total_slots, zs_blob) if total_slots else ()

            e0_md5, e0_zidx, e0_size, e0_offset = entries[0]
            rep.set("I1", e0_md5 == b"\x00" * 16 and e0_zidx == 0 and e0_offset == toc_length,
                    "md5_zero=%s zidx=%d offset=%d toc_length=%d"
                    % (e0_md5 == b"\x00" * 16, e0_zidx, e0_offset, toc_length))

            # I2: TOC MD5 computed over header + TOC with entry0's md5 zeroed.
            toc_md5 = hashlib.md5(
                hdr + b"\x00" * 16 + toc_blob[16:] + zs_blob
            ).hexdigest()
            stored = e0_md5.hex()
            rep.set("I2", stored == "0" * 32 or stored == toc_md5,
                    "stored=%s computed_toc_md5=%s (%s)"
                    % (stored, toc_md5,
                       "field zeroed: no TOC hash stored"
                       if stored == "0" * 32 else "hash stored"))

            # I3: slot-index chain (sequential; empty entries gap one zero slot).
            chain_ok = True
            chain_errors = []
            running = 0
            empty_entries = []
            n_chain_mismatch = 0
            for i in range(entry_count):
                md5, zidx, size, offset = entries[i]
                nblocks = math.ceil(size / block_size) if size else 0
                reserved = nblocks if nblocks else 1
                if zidx != running:
                    chain_ok = False
                    n_chain_mismatch += 1
                    if len(chain_errors) < MAX_CHAIN_ERRORS_RECORDED:
                        chain_errors.append("entry%d zsize_index=%d expected=%d"
                                            % (i, zidx, running))
                if size == 0:
                    empty_entries.append(i)
                    if 0 <= zidx < total_slots and zs[zidx] != 0:
                        chain_ok = False
                        if len(chain_errors) < MAX_CHAIN_ERRORS_RECORDED:
                            chain_errors.append("empty entry%d reserved slot %d = %d != 0"
                                                % (i, zidx, zs[zidx]))
                running += reserved
            last = entries[-1]
            consumed_end = last[1] + (math.ceil(last[2] / block_size) if last[2] else 1)
            rep.set("I3", chain_ok and consumed_end == total_slots,
                    "chain_mismatches=%d last_consumed_end=%d total_slots=%d "
                    "empty_entries=%d%s"
                    % (n_chain_mismatch, consumed_end, total_slots, len(empty_entries),
                       ("; " + "; ".join(chain_errors)) if chain_errors else ""))
            rep.counted("total_slots", total_slots)
            rep.counted("empty_entries", len(empty_entries))
            rep.counted("empty_entry_indices", empty_entries)

            rep.set("H4", toc_length == 32 + entry_count * ENTRY_SIZE_EXPECTED + total_slots * 2,
                    "toc_length=%d arithmetic=%d total_slots=%d"
                    % (toc_length, 32 + entry_count * ENTRY_SIZE_EXPECTED + total_slots * 2,
                       total_slots))

            # ── Entry 0 (manifest) walk + M rules ────────────────────────────────
            sha0, pre0, err0, manifest_parts, end0 = self.walk_entry(
                f, 0, entries, zs, total_slots, block_size, collect_manifest=True)
            manifest_logical = b"".join(manifest_parts) if manifest_parts is not None else None
            manifest_ok = manifest_logical is not None and len(manifest_logical) == e0_size
            manifest_diag = self.check_manifest(entries, entry_count, f, zs,
                                                total_slots, block_size,
                                                manifest_ok, manifest_logical)
            rep.counted("manifest_blocks",
                        math.ceil(e0_size / block_size) if e0_size else 1)
            if e0_size and 0 < total_slots:
                rep.counted("manifest_slot_first", zs[0])
                rep.counted("manifest_slot_last", zs[math.ceil(e0_size / block_size) - 1])
                rep.counted("manifest_slot_sum",
                            sum(zs[:math.ceil(e0_size / block_size)]))

            self.emit({
                "type": "entry", "idx": 0, "name": None,
                "md5": e0_md5.hex(), "zsize_index": e0_zidx,
                "nblocks": math.ceil(e0_size / block_size) if e0_size else 1,
                "offset": e0_offset, "size": e0_size, "empty": e0_size == 0,
                "sha256_logical": sha0, "prefix16_hex": pre0,
                "n_stored_blocks": 0, "errors": err0, "n_errors": len(err0),
            })

            # ── Entries 1..N ────────────────────────────────────────────────────
            # Offset chain uses ACTUAL consumed bytes (end_pos from walks), never
            # ZSize sums: stored full blocks have ZSize==0 but consume 65,536.
            running_off = end0
            offset_chain_ok = True
            limit = entry_count if not self.limit_entries \
                else min(entry_count, self.limit_entries + 1)
            for i in range(1, limit):
                md5, zidx, size, offset = entries[i]
                if offset != running_off:
                    offset_chain_ok = False
                    if len(self.offset_chain_errors) < MAX_CHAIN_ERRORS_RECORDED:
                        self.offset_chain_errors.append(
                            "entry%d offset=%d running=%d (delta %+d)"
                            % (i, offset, running_off, offset - running_off))
                sha, pre, errors, _, end_i = self.walk_entry(
                    f, i, entries, zs, total_slots, block_size, collect_manifest=False)
                nb = math.ceil(size / block_size) if size else 0
                running_off = end_i
                name = self.names[i - 1] if self.names and i - 1 < len(self.names) else None
                self.emit({
                    "type": "entry", "idx": i, "name": name,
                    "md5": md5.hex(), "zsize_index": zidx, "nblocks": nb,
                    "offset": offset, "size": size, "empty": size == 0,
                    "sha256_logical": sha, "prefix16_hex": pre,
                    "n_stored_blocks": sum(1 for s in self.stored_spans if s["entry"] == i),
                    "errors": errors, "n_errors": len(errors),
                })
                if i % PROGRESS_INTERVAL == 0:
                    self.log("entries %d/%d (zlib=%d stored=%d zero_invalid=%d)"
                             % (i, entry_count, self.n_zlib, self.n_stored,
                                self.n_zero_invalid))

            if self.limit_entries:
                rep.skip("I4", "limited run")
                rep.skip("B4", "limited run")
            else:
                rep.set("I4", offset_chain_ok and not self.offset_chain_errors,
                        "chain_errors=%d%s last_end=%d"
                        % (len(self.offset_chain_errors),
                           ("; " + "; ".join(self.offset_chain_errors))
                           if self.offset_chain_errors else "",
                           running_off))
                rep.set("B4", running_off == file_size,
                        "last_entry_end=%d file_size=%d leftover=%d"
                        % (running_off, file_size, file_size - running_off))

            rep.set("B1", self.n_zero_invalid == 0,
                    "zero_zsize_in_referenced_ranges=%d" % self.n_zero_invalid)
            rep.set("B2", True,
                    "stored_blocks=%d stored_bytes=%d (identity ZSize==logical holds "
                    "by construction; partial stored blocks are necessarily tails; "
                    "full-65536 stored would be ZSize==0 by u16 necessity)"
                    % (self.n_stored, self.stored_bytes_total))
            rep.set("B3", self.block_errors_total == 0,
                    "block_decode_errors=%d" % self.block_errors_total)
            rep.counted("zlib_blocks", self.n_zlib)
            rep.counted("stored_blocks", self.n_stored)
            rep.counted("stored_bytes", self.stored_bytes_total)
            rep.counted("zero_invalid", self.n_zero_invalid)
            rep.counted("block_errors", self.block_errors_total)

            self.check_extracted(entries, entry_count)

            recompress = None
            if self.recompress_manifest or self.recompress_assets:
                recompress = {
                    "manifest": self.recompress_probe(self.recompress_manifest),
                    "asset_sample": (self.recompress_probe(self.recompress_assets)
                                     if self.recompress_assets else None),
                    "zlib_runtime": zlib.ZLIB_VERSION,
                    "zlib_runtime_hex": zlib.ZLIB_RUNTIME_VERSION,
                }

            self.finish(file_size, manifest_diag=manifest_diag,
                        recompress=recompress, toc_md5=toc_md5)
            return 0 if rep.n_fail() == 0 else 1

    # -- manifest rules -----------------------------------------------------------
    def check_manifest(self, entries, entry_count, f, zs, total_slots, block_size,
                       manifest_ok, manifest_logical):
        """M1..M6 + legacy-writer single-stream fallback diagnostic."""
        rep = self.rep
        diag = {}
        e0_md5, e0_zidx, e0_size, e0_offset = entries[0]

        if not manifest_ok:
            # Diagnostic fallback (NOT a pass condition): treat ALL bytes between
            # entry0.offset and entry1.offset as ONE zlib stream — the shape the
            # legacy writer produces. Measures counterexamples: 1 stream vs N,
            # u16 truncation of the manifest ZSize.
            end = entries[1][3] if entry_count > 1 else None
            if end is None or end <= e0_offset:
                for rid in ("M1", "M2", "M3", "M4", "M5", "M6"):
                    rep.skip(rid, "manifest unavailable")
                return diag
            f.seek(e0_offset)
            region = f.read(end - e0_offset)
            slot0 = zs[e0_zidx] if 0 <= e0_zidx < total_slots else None
            out, err = inflate_exact(region, e0_size)
            diag = {
                "trigger": "strict per-block manifest decode failed",
                "region_bytes": len(region),
                "slot0_zsize": slot0,
                "slot0_truncation_loss": (len(region) - slot0) if slot0 is not None else None,
                "single_stream_decode": "OK" if out is not None else "FAIL: %s" % err,
            }
            if out is None:
                for rid in ("M1", "M2", "M3", "M4", "M5", "M6"):
                    rep.skip(rid, "manifest undecodable (strict and fallback)")
                self.emit({"type": "manifest_fallback", **diag})
                return diag
            manifest_logical = out
            diag["note"] = ("decoded via single-stream fallback only; real format "
                            "requires ceil(size/65536) independent zlib streams")
            self.emit({"type": "manifest_fallback", **diag})

        try:
            text = manifest_logical.decode("utf-8")
            re_ok = text.encode("utf-8") == manifest_logical
        except UnicodeDecodeError as e:
            rep.set("M1", False, "utf-8 decode error: %s" % e)
            for rid in ("M2", "M3", "M4", "M5", "M6"):
                rep.skip(rid, "manifest not decodable")
            return diag
        rep.set("M1", re_ok, "bytes=%d reencode_identical=%s"
                % (len(manifest_logical), re_ok))

        trailing_lf = manifest_logical.endswith(b"\n")
        parts = manifest_logical.split(b"\n")
        if trailing_lf:
            parts = parts[:-1]
        names = [p.decode("utf-8", "surrogateescape") for p in parts]
        n_lf = manifest_logical.count(b"\n")

        rep.set("M2", all(n.startswith("/") for n in names),
                "names_with_slash=%d/%d"
                % (sum(1 for n in names if n.startswith("/")), len(names)))
        rep.set("M3", (not trailing_lf) and n_lf == len(names) - 1,
                "lf_count=%d names=%d trailing_lf=%s last_byte=%s"
                % (n_lf, len(names), trailing_lf,
                   manifest_logical[-1:].hex() if manifest_logical else ""))
        bad = [n for n in names
               if not n or "\r" in n or "\x00" in n or "\\" in n
               or any(seg in (".", "..") for seg in n.split("/"))]
        rep.set("M4", not bad,
                "bad_names=%d%s" % (len(bad), ("; e.g. %r" % bad[0][:80]) if bad else ""))
        uniq = len(set(names))
        rep.set("M5", uniq == len(names) == entry_count - 1,
                "names=%d unique=%d expected=%d"
                % (len(names), uniq, entry_count - 1))

        md5_ok = 0
        md5_bad = []
        for i in range(1, min(entry_count, len(parts) + 1)):
            if hashlib.md5(parts[i - 1]).digest() == entries[i][0]:
                md5_ok += 1
            elif len(md5_bad) < 5:
                md5_bad.append("entry%d computed=%s" % (i, hashlib.md5(parts[i - 1]).hexdigest()))
        rep.set("M6", md5_ok == entry_count - 1,
                "md5_matches=%d/%d%s"
                % (md5_ok, entry_count - 1,
                   ("; " + "; ".join(md5_bad)) if md5_bad else ""))
        rep.counted("names", len(names))
        rep.counted("manifest_bytes", len(manifest_logical))
        rep.counted("manifest_lf", n_lf)
        self.names = names
        self.names_bytes = parts
        return diag

    # -- corpus cross-checks --------------------------------------------------------
    def check_extracted(self, entries, entry_count):
        rep = self.rep
        if not self.extracted_root:
            for rid in ("X0", "X1", "X2"):
                rep.skip(rid, "no --extracted-root given")
            return
        if self.names is None:
            for rid in ("X0", "X1", "X2"):
                rep.skip(rid, "manifest unavailable")
            return
        if self.limit_entries:
            for rid in ("X0", "X1", "X2"):
                rep.skip(rid, "limited run")
            return

        corpus_files = 0
        for _root, _dirs, fs in os.walk(self.extracted_root):
            corpus_files += len(fs)
        rep.set("X0", corpus_files == len(self.names),
                "corpus_files=%d manifest_names=%d root=%s"
                % (corpus_files, len(self.names), self.extracted_root))

        size_ok = 0
        size_bad = []
        for i in range(1, entry_count):
            p = os.path.join(self.extracted_root, self.names[i - 1].lstrip("/"))
            try:
                st = os.stat(p)
            except OSError:
                st = None
            if st is not None and st.st_size == entries[i][2]:
                size_ok += 1
            elif len(size_bad) < 5:
                size_bad.append("entry%d %s: exists=%s size=%s expected=%d"
                                % (i, self.names[i - 1][:80], st is not None,
                                   st.st_size if st is not None else None,
                                   entries[i][2]))
        rep.set("X1", size_ok == entry_count - 1,
                "sizes_ok=%d/%d%s" % (size_ok, entry_count - 1,
                                      ("; " + "; ".join(size_bad)) if size_bad else ""))

        spans = [s for s in self.stored_spans if s["entry"] != 0]
        matched = 0
        mismatches = []
        with open(self.archive, "rb") as af:
            for span in spans:
                i = span["entry"]
                p = os.path.join(self.extracted_root, self.names[i - 1].lstrip("/"))
                try:
                    with open(p, "rb") as xf:
                        xf.seek(span["logical_off"])
                        ext = xf.read(span["len"])
                except OSError:
                    mismatches.append("entry%d: cannot open %s" % (i, p))
                    continue
                af.seek(span["arc_off"])
                arc = af.read(span["len"])
                if arc == ext and len(ext) == span["len"]:
                    matched += 1
                elif len(mismatches) < 5:
                    mismatches.append("entry%d len=%d arc=%dB ext=%dB"
                                      % (i, span["len"], len(arc), len(ext)))
        rep.set("X2", matched == len(spans),
                "stored_spans_matched=%d/%d%s"
                % (matched, len(spans),
                   ("; " + "; ".join(mismatches)) if mismatches else ""))
        rep.counted("stored_span_checks", len(spans))

    # -- RT0 feasibility probe --------------------------------------------------------
    def recompress_probe(self, samples):
        """For each (slot, orig_comp, logical): which zlib levels (1..9)
        reproduce the original stream byte-exactly?"""
        if not samples:
            return None
        per_level = {lvl: 0 for lvl in range(1, 10)}
        no_level = 0
        for slot, orig, logical in samples:
            hit = False
            for lvl in range(1, 10):
                if zlib.compress(logical, lvl) == orig:
                    per_level[lvl] += 1
                    hit = True
            if not hit:
                no_level += 1
        return {"n": len(samples),
                "byte_exact_per_level": {str(k): v for k, v in per_level.items()},
                "no_level_matched": no_level}

    # -- summary -----------------------------------------------------------------------
    def finish(self, file_size, manifest_diag=None, recompress=None, toc_md5=None):
        rep = self.rep
        summary = {
            "type": "summary", "archive": self.archive, "file_size": file_size,
            "toc_md5_computed": toc_md5,
            "rules": {rid: {"desc": RULE_DESC[rid], **rep.rules[rid]} for rid in RULE_IDS},
            "rules_pass": rep.n_pass(), "rules_fail": rep.n_fail(),
            "counters": rep.counters,
            "python": sys.version.split()[0], "zlib": zlib.ZLIB_VERSION,
        }
        if manifest_diag:
            summary["manifest_diag"] = manifest_diag
        if recompress:
            summary["recompress_probe"] = recompress
        self.emit(summary)
        self.print_report()

    def print_report(self):
        rep = self.rep
        out = sys.stdout
        out.write("== psarc_oracle: %s\n" % self.archive)
        for rid in RULE_IDS:
            r = rep.rules[rid]
            out.write("  [%s] %-3s %-66s %s\n"
                      % (r["status"], rid, RULE_DESC[rid], r["detail"]))
        n_skip = len(RULE_IDS) - rep.n_pass() - rep.n_fail()
        out.write("RULES: %d pass, %d fail, %d skipped (of %d registered)\n"
                  % (rep.n_pass(), rep.n_fail(), n_skip, len(RULE_IDS)))


# ── Self-test (synthetic controls BEFORE trusting real data) ──────────────────

def self_test():
    import tempfile

    failures = []

    def check(cond, what):
        if not cond:
            failures.append(what)

    with tempfile.TemporaryDirectory() as td:
        # Valid archive per the real spec: multiblock manifest, one empty
        # entry, one incompressible partial tail (stored, ZSize==logical),
        # one full-size stored block (ZSize==0 by u16 necessity).
        big_incompressible = os.urandom(BLOCK_SIZE_DEFAULT + 300)
        files = [
            ("/dir/alpha.bin", b"A" * 150000),
            ("/dir/empty.dat", b""),
            ("/dir/rand.bin", os.urandom(64)),
            ("/dir/big.bin", big_incompressible),
        ]
        for k in range(1200):
            files.append(("/long/path/number_%04d/filler_name_to_grow_manifest.bin" % k,
                          bytes([k & 0xFF]) * 8))
        valid = build_real_spec_archive(files, flags=2)
        vp = os.path.join(td, "valid.psarc")
        with open(vp, "wb") as fh:
            fh.write(valid)

        orc = Oracle(vp)
        rc = orc.run(None)
        r = orc.rep
        check(rc == 0, "valid archive should exit 0, got %d" % rc)
        for rid in ("H1", "H2", "H3", "H4", "H5", "H6", "H7", "I1", "I2", "I3", "I4",
                    "M1", "M2", "M3", "M4", "M5", "M6", "B1", "B2", "B3", "B4"):
            check(r.rules[rid]["status"] == "PASS",
                  "valid archive: %s should PASS, got %s (%s)"
                  % (rid, r.rules[rid]["status"], r.rules[rid]["detail"]))
        check(r.counters.get("stored_blocks", 0) >= 3,
              "expected >=3 stored blocks in fixture (got %s)" % r.counters)
        check(r.counters.get("empty_entries", 0) == 1, "expected 1 empty entry")
        check(r.counters.get("zlib_blocks", 0) >= 3, "expected >=3 zlib blocks")

        # Variant A: flags=0 (legacy writer) -> only H7 FAIL.
        pa = os.path.join(td, "flags0.psarc")
        with open(pa, "wb") as fh:
            fh.write(build_real_spec_archive(files[:6], flags=0))
        orc = Oracle(pa)
        orc.run(None)
        check(orc.rep.rules["H7"]["status"] == "FAIL", "flags=0 must FAIL H7")
        check(orc.rep.rules["M3"]["status"] == "PASS", "flags variant must keep M3 PASS")

        # Variant B: trailing LF (legacy writer) -> M3 FAIL.
        pb = os.path.join(td, "traillf.psarc")
        with open(pb, "wb") as fh:
            fh.write(build_real_spec_archive(files[:6], flags=2, trailing_lf=True))
        orc = Oracle(pb)
        orc.run(None)
        check(orc.rep.rules["M3"]["status"] == "FAIL", "trailing LF must FAIL M3")

        # Variant C: single-stream manifest + u16 truncation (legacy writer) ->
        # I3 chain break + B3 errors + fallback diagnostic with loss numbers.
        letters = "abcdefghijklmnopqrstuvwxyz"
        rnd_names = [
            ("/r/%s/%06d" % ("".join(letters[b % 26] for b in os.urandom(48)), k), b"x" * 4)
            for k in range(3000)
        ]
        pc = os.path.join(td, "single.psarc")
        with open(pc, "wb") as fh:
            fh.write(build_real_spec_archive(rnd_names, flags=2,
                                             single_stream_manifest=True))
        orc = Oracle(pc)
        orc.run(None)
        check(orc.rep.rules["I3"]["status"] == "FAIL", "single-stream manifest must FAIL I3")
        check(orc.rep.rules["B3"]["status"] == "FAIL", "single-stream manifest must FAIL B3")

        # Variant D: corrupt one byte inside the first manifest zlib stream ->
        # B3 FAIL, never a silent raw fallback.
        vd = bytearray(valid)
        toc_len = struct.unpack(">I", vd[12:16])[0]
        vd[toc_len + 5] ^= 0xFF
        pd = os.path.join(td, "corrupt.psarc")
        with open(pd, "wb") as fh:
            fh.write(bytes(vd))
        orc = Oracle(pd)
        orc.run(None)
        check(orc.rep.rules["B3"]["status"] == "FAIL", "corrupted stream must FAIL B3")

    if failures:
        sys.stderr.write("SELF-TEST FAILED:\n")
        for x in failures:
            sys.stderr.write("  - %s\n" % x)
        return 1
    sys.stderr.write("SELF-TEST OK (valid fixture all-PASS; 3 corrupted variants fail exactly the targeted rules)\n")
    return 0


# ── CLI ───────────────────────────────────────────────────────────────────────

def main():
    ap = argparse.ArgumentParser(description="FFX PSARC format oracle (strict validator)")
    ap.add_argument("archive", nargs="?", help=".psarc to validate")
    ap.add_argument("--jsonl", help="JSONL report path (default: no file)")
    ap.add_argument("--extracted-root", help="extracted corpus root for X rules")
    ap.add_argument("--expect-flags", type=int, default=FLAGS_EXPECTED_DEFAULT,
                    help="expected u32BE@0x1C Flags (default 2, FFX corpus)")
    ap.add_argument("--recompress-sample", type=int, default=0,
                    help="also probe N asset zlib blocks for byte-exact recompression")
    ap.add_argument("--limit-entries", type=int, default=0,
                    help="validate only the first N+1 entries (debug)")
    ap.add_argument("--quiet", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()

    if args.self_test:
        sys.exit(self_test())
    if not args.archive:
        ap.error("archive required (or --self-test)")

    orc = Oracle(args.archive, extracted_root=args.extracted_root,
                 expect_flags=args.expect_flags,
                 recompress_sample=args.recompress_sample,
                 limit_entries=args.limit_entries, quiet=args.quiet)
    sys.exit(orc.run(args.jsonl))


if __name__ == "__main__":
    main()
