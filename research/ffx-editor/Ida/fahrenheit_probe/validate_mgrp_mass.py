#!/usr/bin/env python3
"""Valida o decoder .mgrp em massa: conta records e coerencia de 60 arquivos."""
import os
import struct
import sys
from collections import Counter

sys.stdout.reconfigure(encoding="utf-8", errors="replace")
ROOT = r"F:\ffx_ps2\ffx"

def sx(v, bits):
    m = 1 << (bits - 1)
    return (v ^ m) - m

def decode_stream(buf, pos, nframes=64):
    delta = 0; sample = 0; run = 0; out = []
    for _ in range(nframes):
        if run != 0:
            run -= 1
        else:
            if pos >= len(buf):
                break
            c = buf[pos]; pos += 1
            if c < 0x80:
                delta = sx(c & 0x7F, 7)
            elif c & 0x40:
                if pos >= len(buf):
                    break
                lo = c & 0x3F; hi = buf[pos]; pos += 1
                delta = sx(lo | (hi << 6), 14)
            else:
                run = c & 0x3F
        sample = sx((sample + delta) & 0xFFFF, 16)
        out.append(sample)
    return out

def coherence(samples):
    if len(samples) < 3:
        return 0.0
    diffs = [abs(samples[i+1] - samples[i]) for i in range(len(samples) - 1)]
    return sum(1 for d in diffs if d <= 256) / len(diffs)

results = Counter()
details = []
count = 0
for dirpath, dirs, files in os.walk(ROOT):
    for fn in files:
        if not fn.lower().endswith(".mgrp"):
            continue
        fp = os.path.join(dirpath, fn)
        try:
            data = open(fp, "rb").read()
        except OSError:
            continue
        if len(data) < 24:
            results["stub(<24B)"] += 1
            continue
        dr = struct.unpack_from("<I", data, 0x0C)[0]
        N = (len(data) - dr) // 20 if len(data) > dr else 0
        if N <= 0:
            results["0 records"] += 1
        else:
            # valida o record[0]
            ro = dr
            a = struct.unpack_from("<H", data, ro + 8)[0]
            b = struct.unpack_from("<H", data, ro + 10)[0]
            offB = struct.unpack_from("<I", data, ro + 16)[0]
            if 0 < offB < len(data):
                try:
                    samples = decode_stream(data, offB)
                    c = coherence(samples)
                    if c > 0.7:
                        results["ok coh>0.7"] += 1
                    else:
                        results[f"coh baixa ({c:.2f})"] += 1
                except Exception:
                    results["erro decode"] += 1
            else:
                results["offB invalido"] += 1
        count += 1
        if count >= 400:
            break
    if count >= 400:
        break

print(f"validados: {count} arquivos .mgrp")
for k, v in results.most_common():
    print(f"  {k}: {v}")
