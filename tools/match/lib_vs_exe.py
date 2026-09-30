#!/usr/bin/env python3
"""Decide whether a static library's machine code is inside a PE image.

This answers the decisive question for byte-identical reconstruction of the
third-party slice of FFX.exe: were the prebuilt VS2012 ``.lib`` files shipped
with PhyreEngine 3.21 the actual code that was linked into the game? If they
were, that part of the binary is reproducible exactly with no source and no
compiler.

A naive byte search under-reports, because a ``.lib`` stores placeholder dwords
wherever the linker will later patch an address, while the linked image holds
the resolved value. So this walker parses each object's COFF relocation table,
aligns the object on a relocation-free seed window, and then scores the match
both with and without the relocatable dwords taken into account.
"""

import struct
import sys


def parse_archive(data: bytes):
    """Yield (name, offset, size) for each object member of an MS .lib."""
    if not data.startswith(b"!<arch>\n"):
        raise ValueError("not an ar archive")
    pos = 8
    longnames = b""
    members = []
    while pos + 60 <= len(data):
        header = data[pos : pos + 60]
        if header[58:60] != b"`\n":
            break
        name = header[0:16].rstrip(b" ").decode("latin-1")
        size = int(header[48:58].decode("latin-1").strip())
        body = pos + 60
        if name == "//":
            longnames = data[body : body + size]
        elif name not in ("/", "/SYM64/"):
            if name.startswith("/") and name[1:].isdigit():
                noff = int(name[1:])
                end = longnames.find(b"\n", noff)
                name = longnames[noff:end].rstrip(b"/").decode("latin-1")
            members.append((name, body, size))
        pos = body + size + (size & 1)
    return members


def coff_sections(data: bytes, offset: int, size: int):
    """Return a list of dicts describing each section of a COFF object."""
    if size < 20:
        return []
    machine, nsec, _ts, symptr, nsym, optsize, _chars = struct.unpack_from(
        "<HHIIIHH", data, offset
    )
    if machine not in (0x14C, 0x8664):
        return []
    sec_base = offset + 20 + optsize
    strtab = offset + symptr + nsym * 18
    out = []
    for i in range(nsec):
        off = sec_base + i * 40
        if off + 40 > offset + size:
            break
        raw_name = data[off : off + 8]
        if raw_name.startswith(b"/"):
            digits = raw_name[1:].rstrip(b"\x00") or b"0"
            nameoff = strtab + int(digits)
            end = data.find(b"\x00", nameoff)
            name = data[nameoff:end].decode("latin-1", "replace")
        else:
            name = raw_name.rstrip(b"\x00").decode("latin-1", "replace")
        _vsize, _vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, off + 8)
        relocptr, _ln, nreloc, _nrln = struct.unpack_from("<IIHH", data, off + 24)
        text = data[offset + rawptr : offset + rawptr + rawsize] if rawptr else b""
        relocs = set()
        for r in range(nreloc):
            roff = offset + relocptr + r * 10
            if roff + 10 > len(data):
                break
            rva, _sym, rtype = struct.unpack_from("<IIH", data, roff)
            if rtype == 0x0002:  # LNKB: no bytes written
                continue
            for b in range(rva, min(rva + 4, len(text))):
                relocs.add(b)
        out.append({"name": name, "text": text, "relocs": relocs})
    return out


def longest_seed(text: bytes, relocs: set, window: int, exe: bytes):
    """Find the longest relocation-free window of text that also occurs in exe.

    Longer seeds first: a 24-byte coincidence is possible, a 64-byte one is not.
    """
    n = len(text)
    for win in (96, 64, 48, 32, 24):
        if win > n:
            continue
        positions = range(0, n - win + 1, max(1, win // 8))
        # Bounded tries: a section that is really in the image anchors from
        # almost any window, so a handful of spread-out positions suffices.
        # Exhaustive scanning made 40KB sections take minutes each.
        idxs = sorted(set(list(positions)[:4] + list(positions)[-4:] + list(positions)[::max(1, len(list(positions)) // 6)][:8]))
        for start in idxs:
            if any((start + k) in relocs for k in range(win)):
                continue
            idx = exe.find(text[start : start + win])
            if idx >= 0:
                return start, idx
    return None


def main() -> int:
    lib_path, exe_path = sys.argv[1], sys.argv[2]
    lib = open(lib_path, "rb").read()
    exe = open(exe_path, "rb").read()
    members = parse_archive(lib)

    tot = tot_same = tot_nr = tot_same_nr = 0
    exact_objs = 0
    no_seed = 0
    sections = 0
    results = []
    for name, off, size in members:
        for sec in coff_sections(lib, off, size):
            text, relocs = sec["text"], sec["relocs"]
            if not sec["name"].startswith(".text") or len(text) < 48:
                continue
            sections += 1
            seed = longest_seed(text, relocs, 24, exe)
            if seed is None:
                no_seed += 1
                results.append((0.0, 0, len(text), f"{name} [{sec['name']}]"))
                tot += len(text)
                tot_nr += len(text)
                continue
            start0, idx = seed
            off0 = idx - start0
            if off0 < 0:
                no_seed += 1
                results.append((0.0, 0, len(text), f"{name} [{sec['name']}]"))
                tot += len(text)
                tot_nr += len(text)
                continue
            limit = min(len(text), len(exe) - off0)
            same = same_nr = total_nr = 0
            for k in range(limit):
                if text[k] == exe[off0 + k]:
                    same += 1
                if (start0 + k) in relocs:
                    continue
                total_nr += 1
                if text[k] == exe[off0 + k]:
                    same_nr += 1
            tot += limit
            tot_same += same
            tot_nr += total_nr
            tot_same_nr += same_nr
            frac = same_nr / total_nr if total_nr else 0.0
            if frac >= 0.98:
                exact_objs += 1
            results.append((frac, same_nr, total_nr, f"{name} [{sec['name']}]"))

    print(f"archive members            : {len(members)}")
    print(f".text sections examined    : {sections} ({no_seed} with no anchor in the image)")
    print(f"object code bytes examined : {tot:,}")
    print(f"  raw byte agreement       : {100 * tot_same / max(tot, 1):.2f}%")
    print(f"  agreement ignoring relocs: {100 * tot_same_nr / max(tot_nr, 1):.2f}%")
    print(f"  objects >=98% identical  : {exact_objs}")
    results.sort(reverse=True)
    print()
    print("strongest matches:")
    for frac, m, t, name in results[:15]:
        tail = name.rsplit("\\", 1)[-1]
        print(f"  {100 * frac:6.1f}%  {m:7d}/{t:<7d}  {tail[:60]}")
    print()
    print("weakest matches:")
    for frac, m, t, name in results[-8:]:
        tail = name.rsplit("\\", 1)[-1]
        print(f"  {100 * frac:6.1f}%  {m:7d}/{t:<7d}  {tail[:60]}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
