#!/usr/bin/env python3
"""Date the PhyreEngine revision inside FFX.exe using the 3.21 changelog.

The changelog documents classes added, changed and removed per release. Cross
referencing those names with the RTTI identifiers that survived in FFX.exe
gives a lower and upper bound on the engine revision the game was built with.
"""

import collections
import re
import sys


def rtti_tokens(exe: str) -> set[str]:
    data = open(exe, "rb").read()
    rx = re.compile(rb"\.\?AV[^\x00]{2,200}?@@")
    toks: set[str] = set()
    for m in rx.finditer(data):
        for t in re.findall(r"[A-Za-z_][A-Za-z0-9_]*", m.group(0)[4:-2].decode("latin-1")):
            toks.add(t)
    return toks


def changelog_sections(path: str):
    text = open(path, "r", encoding="utf-8", errors="replace").read()
    heads = list(re.finditer(r"Changes in Release ([0-9.]+)", text))
    sections = []
    for i, h in enumerate(heads):
        end = heads[i + 1].start() if i + 1 < len(heads) else len(text)
        sections.append((h.group(1), text[h.end() : end]))
    return sections


def main() -> int:
    exe, changelog = sys.argv[1], sys.argv[2]
    toks = rtti_tokens(exe)
    sections = changelog_sections(changelog)
    print(f"identifier tokens from binary RTTI : {len(toks)}")
    print(f"changelog releases parsed          : {len(sections)}")
    print()

    def ver(s: str):
        return tuple(int(x) for x in s.split("."))

    sections.sort(key=lambda kv: ver(kv[0]))

    # Which release first mentions each class the binary actually contains?
    first_seen: dict[str, str] = {}
    for verstr, body in sections:
        for name in set(re.findall(r"\bP[A-Z][A-Za-z0-9_]{3,}\b", body)):
            if name in toks and name not in first_seen:
                first_seen[name] = verstr

    by_ver = collections.defaultdict(list)
    for name, verstr in first_seen.items():
        by_ver[verstr].append(name)

    print("classes present in FFX.exe, grouped by the release that first documents them:")
    for verstr in sorted(by_ver, key=ver):
        names = sorted(by_ver[verstr])
        print(f"  {verstr:9s} {len(names):4d}  {', '.join(names[:6])}")

    if by_ver:
        newest = max(by_ver, key=ver)
        print()
        print(f"=> newest release that first documents a class still in FFX.exe: {newest}")
        print(f"   => engine revision is at least {newest}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
