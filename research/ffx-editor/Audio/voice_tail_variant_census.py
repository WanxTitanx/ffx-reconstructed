#!/usr/bin/env python3
"""voice_tail_variant_census.py — wave-19 VOICE-TAIL lane.

Census of the two filename variant characters emitted by the voice-file
name builder (FFX.exe 0x8877E0, PS2 EE 0x2d6d88):

    bank = id >> 12
    f2   = ((id >> 6) & 0x1F) + 0x60      # char at Buffer[8]
    f3   = (id & 0x1F) + 0x60             # char at Buffer[9]
    name = "v{lang}%06d%c%c.vs" % (bank, f2, f3)

Cross-referenced against VoiceIDMapper.txt (ML\0\0, 8730 records), whose
proven codec (wave-13, voice_mapper_decode.py) is:

    id = NNNNNN * 0x1000 + speakerPack
    speakerPack = ((c1 - 0x60) << 6) | (c2 - 0x60)   # two 6-bit fields

Because every pair char is [a-z] (values 1..26 < 32), the builder's two
5-bit extracts reproduce pack2pair(id & 0xFFF) exactly -> the filename
tail IS the mapper name's speaker pair. This tool measures that claim
over the whole mapper (no loose .vs files exist on the mastered disc —
the runtime assets are packed in voiceNN.pvs / shout.dat / .fsb banks,
so 'file existence' is tested against the mapper name space itself).

Outputs (csvs dir):
  voice_tail_variant_census.csv   one row per mapper record
  voice_tail_variant_pairs.csv    distinct emitted (f2,f3) pairs + counts
"""
import argparse
import collections
import csv
import os
import re
import struct
import sys

MAGIC = b"ML\x00\x00"
BATTLE_THRESHOLD = 0x33000000
BATTLE_FORCED = {0x08341504, 0x0C545504, 0x28745504, 0x28746504, 0x00000504}
NAGISETSU_IDS = range(0x189, 0x18F)
NAME_RE = re.compile(r"^(\d{6})([a-z]{2})$")


def pair2pack(pair):
    return ((ord(pair[0]) - 0x60) << 6) | (ord(pair[1]) - 0x60)


def pack2pair(pack):
    c1, c2 = (pack >> 6) & 0x3F, pack & 0x3F
    if not (1 <= c1 <= 26 and 1 <= c2 <= 26):
        return "??"
    return chr(0x60 + c1) + chr(0x60 + c2)


def encode_name(name):
    m = NAME_RE.match(name)
    if not m:
        return None
    return int(m.group(1)) * 0x1000 + pair2pack(m.group(2))


def load_mapper(path):
    data = open(path, "rb").read()
    assert data[:4] == MAGIC, "bad magic %r" % data[:4]
    count = struct.unpack_from("<I", data, 4)[0]
    recs = []
    for i in range(count):
        vid, off = struct.unpack_from("<II", data, 8 + 8 * i)
        end = data.index(b"\x00", off)
        recs.append((vid, data[off:end].decode("ascii", "replace")))
    return recs


def builder(idv):
    """exact 0x8877E0 field extraction."""
    bank = idv >> 12
    f2 = ((idv >> 6) & 0x1F) + 0x60
    f3 = (idv & 0x1F) + 0x60
    return bank, f2, f3


def classify(vid, name):
    if vid in BATTLE_FORCED or vid > BATTLE_THRESHOLD:
        route = "btl"
    elif vid in NAGISETSU_IDS or name.endswith("_nagisetsu"):
        route = "special0"
    elif NAME_RE.match(name):
        route = "bank%02d" % int(name[:2])
    else:
        route = "unmatched"
    if vid in NAGISETSU_IDS:
        kind = "nagisetsu"
    elif encode_name(name) == vid:
        kind = "formula"
    elif NAME_RE.match(name):
        kind = "legacy"
    else:
        kind = "other"
    return kind, route


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("mapper")
    ap.add_argument("--csvs", required=True)
    args = ap.parse_args()

    os.makedirs(args.csvs, exist_ok=True)
    recs = load_mapper(args.mapper)
    rows = []
    pair_hist = collections.Counter()
    kind_hist = collections.Counter()
    mism_tail = mism_bank = 0
    for vid, name in recs:
        kind, route = classify(vid, name)
        kind_hist[kind] += 1
        bank, f2, f3 = builder(vid)
        fn = "v?%06d%c%c.vs" % (bank, f2, f3)
        m = NAME_RE.match(name)
        name_num = m.group(1) if m else ""
        name_pair = m.group(2) if m else ""
        tail = chr(f2) + chr(f3)
        tail_match = (tail == name_pair) if m else ""
        bank_match = (bank == int(name_num)) if m else ""
        if m and not tail_match:
            mism_tail += 1
        if m and not bank_match:
            mism_bank += 1
        pair_hist[tail] += 1
        rows.append({
            "voiceId": "0x%08X" % vid,
            "name": name,
            "kind": kind,
            "route": route,
            "bank_dec": bank,
            "f2_char": chr(f2),
            "f3_char": chr(f3),
            "filename": fn,
            "name_num": name_num,
            "name_pair": name_pair,
            "tail_eq_namepair": tail_match,
            "bank_eq_namenum": bank_match,
        })

    with open(os.path.join(args.csvs, "voice_tail_variant_census.csv"),
              "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)

    with open(os.path.join(args.csvs, "voice_tail_variant_pairs.csv"),
              "w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["pair", "c1_pack", "c2_pack", "records"])
        for pair, n in pair_hist.most_common():
            w.writerow([pair, (pair2pack(pair) >> 6) & 0x3F,
                        pair2pack(pair) & 0x3F, n])

    print("records=%d kinds=%s" % (len(recs), dict(kind_hist)))
    print("patterned names with tail mismatch: %d" % mism_tail)
    print("patterned names with bank mismatch: %d" % mism_bank)
    print("distinct emitted tails: %d" % len(pair_hist))
    print("top tails: %s" % pair_hist.most_common(12))


if __name__ == "__main__":
    main()
