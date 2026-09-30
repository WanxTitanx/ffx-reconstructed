#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ps2_otp_reader.py — PS2 FFX `tim/f_timpos.otp` TIM-placement table reader.

PROVEN (wave-13 corpus lane, 2026-09-18 — 7/7 unique files, byte-exact size
math on every file: size == 0x100 + 32*nSub + 128*nRec always; every
numeric claim below cross-checked against the sibling .tm2 TIM2 headers).

  ".otp" / "f_timpos" = dev-authored GS VRAM texture-layout plan for
  effect/overlay rendering ("Offset/TIM Position"?). The sub-records
  pre-place each texture PAGE at its target GS TBP and record its CLUT
  bank; the records then map each named .tm2 sprite onto (page, x, y) and
  publish the sprite's CLUT slot address. Every file embeds the authoring
  machine path (CP932-encoded, e.g. `Z:/abmap/maho/tim`,
  `C:/WINDOWS/ﾃﾞｽｸﾄｯﾌﾟ/partycl/bacld_g/tim` — half-width katakana
  "DESKTOP").

  Layout (little-endian):
    +0x00  u16 version     (always 1)
    +0x02  u16 nRecords    (tm2 record count)
    +0x04  f32 scaleU      (canvas U step; observed 1/2048, 1/512, ~0.5)
    +0x08  f32 scaleV      (canvas V step)
    +0x0C  u16 nSub        (page sub-record count)
    +0x0E  u16 unk         (0 in 6/7 files, 2 in bat_eff)
    +0x10  16B  gap/flags  (zero in observed files)
    +0x20  char devPath[224] (NUL-terminated author path, CP932)
    +0x100 nSub x 32B page sub-records:
             +0x00 u32 packed   = {u16 pageIdx, u16 clutBank}
                                  (encount: bank==pageIdx; mag_0148: bank=1
                                  for the 5 pages whose CBPs sit in the low
                                  CLUT region 15240..15252, else 0 —
                                  i.e. a CLUT staging-region group id)
             +0x04 u16 texTBP   = GS texture base pointer of the page,
                                  IDENTICAL to the resident .tm2's
                                  GsTex0.TBP (verified on all records —
                                  64-word units, i.e. VRAM addr/256)
             +0x06 u16 size256  = .tm2 image payload size / 256
                                  (bpp-aware: 512x416@16bpp -> 1664)
             +0x08 u16 pageW    = page buffer width  (== GsTex0.TBW*64)
             +0x0A u16 pageH    = page buffer height
             +0x0C u32 pxMode   = TIM2 imageType byte verbatim
                                  (5 = PSMT8 indexed, 1 = PSMCT16 direct)
             +0x10 16B zero pad
    then nRecords x 128B tm2 records:
             +0x00 char name[40]  ("m2_384.tm2", NUL-terminated)
             +0x28 u32  dataOff   = 0x40000 + GsTex0.CBP   (PROVEN 7/7 —
                                  the sprite's CLUT slot address in the
                                  shared descriptor space; 0 when the
                                  texture is direct-color / CLUT-less)
             +0x2C u16  dstPageW  = redundant copy of sub[pageIdx].pageW
             +0x2E u16  zero
             +0x30 u16  srcW      (== .tm2 width)
             +0x32 u16  srcH      (== .tm2 height)
             +0x34 u16  pageIdx   -> sub-records[]
             +0x36 u16  dstX      sprite X inside page
             +0x38 u16  dstY      sprite Y inside page
             +0x3A u16  srcH2     (== srcH, duplicate)
             +0x3C u16  zero
             +0x3E u16  zero
             +0x40..+0x7F zero pad (64B)

  Renders: see ps2_otp_render.py — compositing each .tm2 at
  (pageIdx,dstX,dstY) reproduces the authored page atlases pixel-perfectly
  (e.g. mag_0148 packs two 64x64 sprites side-by-side on 128x64 pages 3,4).

Usage: ps2_otp_reader.py FILE.otp... [--json]
"""
import struct
import sys
import json


def parse(path):
    d = open(path, "rb").read()
    n = len(d)
    if n < 0x100:
        raise ValueError("too small")
    ver, nrec = struct.unpack_from("<HH", d, 0)
    su, sv = struct.unpack_from("<ff", d, 4)
    nsub, unk = struct.unpack_from("<HH", d, 0x0C)
    devpath = d[0x20:0x100].split(b"\0")[0].decode("cp932", "replace")
    expect = 0x100 + 32 * nsub + 128 * nrec
    assert expect == n, "size %d != %d (nsub=%d nrec=%d)" % (n, expect, nsub, nrec)

    subs = []
    for i in range(nsub):
        o = 0x100 + 32 * i
        packed = struct.unpack_from("<I", d, o)[0]
        tbp, size256, pw, ph = struct.unpack_from("<4H", d, o + 4)
        pxmode = struct.unpack_from("<I", d, o + 12)[0]
        subs.append({"index": i,
                     "pageIdx": packed & 0xFFFF, "clutBank": packed >> 16,
                     "texTBP": tbp, "size256": size256,
                     "pageW": pw, "pageH": ph, "pxMode": pxmode,
                     # compat fields (raw dump retained for older callers)
                     "params": d[o + 4:o + 12].hex(" "), "count": pxmode})

    recs = []
    base = 0x100 + 32 * nsub
    for i in range(nrec):
        o = base + 128 * i
        nm = d[o:o + 40].split(b"\0")[0].decode("ascii", "replace")
        dataoff, dpw = struct.unpack_from("<IH", d, o + 0x28)
        f = struct.unpack_from("<8H", d, o + 0x30)
        recs.append({"name": nm,
                     # dataOff = 0x40000 + GsTex0.CBP of the sprite's tm2
                     # (0 for CLUT-less/direct-color textures)
                     "dataOff": dataoff, "clutCBP": dataoff - 0x40000 if dataoff else 0,
                     "dstPageW": dpw, "flag": dpw,
                     "srcW": f[0], "srcH": f[1],
                     "pageIdx": f[2], "dstX": f[3], "dstY": f[4],
                     "srcH2": f[5],
                     "fields16": list(f)})
    return {"path": path, "size": n, "version": ver, "nRecords": nrec,
            "scaleU": su, "scaleV": sv, "nSub": nsub, "unk": unk,
            "devPath": devpath, "subRecords": subs, "records": recs}


def main(argv):
    as_json = "--json" in argv
    files = [a for a in argv if not a.startswith("-")]
    if not files:
        print(__doc__)
        return 1
    nok = 0
    for path in files:
        try:
            rep = parse(path)
            nok += 1
            if as_json:
                print(json.dumps(rep, indent=1))
            else:
                print("%s: %dB v%d nRec=%d nSub=%d scale=(%.6f,%.6f) path=%s"
                      % (path, rep["size"], rep["version"], rep["nRecords"],
                         rep["nSub"], rep["scaleU"], rep["scaleV"], rep["devPath"]))
                for i, s in enumerate(rep["subRecords"]):
                    print("   page%-2d tbp=%5d size256=%-4d %3dx%-3d pxMode=%d clutBank=%d"
                          % (s["pageIdx"], s["texTBP"], s["size256"],
                             s["pageW"], s["pageH"], s["pxMode"], s["clutBank"]))
                for r in rep["records"]:
                    print("   %-18s dataOff=%#07x (CBP=%5d) pageW=%3d src=%3dx%-3d page=%d @(%d,%d)"
                          % (r["name"], r["dataOff"], r["clutCBP"], r["dstPageW"],
                             r["srcW"], r["srcH"], r["pageIdx"], r["dstX"], r["dstY"]))
        except Exception as e:
            print("%s: FAIL %s" % (path, e))
    print("%d/%d parsed" % (nok, len(files)))
    return 0 if nok == len(files) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
