#!/usr/bin/env python3
"""Decode MSVC decorated string literals and resolve their address in a PE.

Hex-Rays prints a string literal as its linker symbol, ``??_C@_<len>@<hash>@<text>@``.
The text is not literal: ``?`` introduces an escape.  ``?$XY`` is a single byte
whose value is ``f(X)*16 + f(Y)`` with ``A-Z`` = 0..25, ``a-z`` = 26..51 and
``0-9`` = 52..61; ``?$AA`` ends the literal.  A one-letter escape maps through
TABLE, which is where ``?5`` becomes a space and ``?3`` a colon.

Resolving the address requires the decoded bytes to occur exactly once in the
image, so a match is evidence rather than a guess.
"""
import re

TABLE = {'0': ',', '1': '/', '2': '\\', '3': ':', '4': '.', '5': ' ', '6': ';', '7': '=',
         '8': "'", '9': '^', 'A': '<', 'B': '>', 'C': '[', 'D': ']', 'E': '_', 'F': '$',
         'G': '+', 'H': '-', 'I': '!', 'J': '|', 'K': '*', 'L': '(', 'M': ')', 'N': '@',
         'O': '#', 'P': '&', 'Q': '~', 'R': '-', 'S': '-', 'T': '?', 'U': '?', 'V': '.',
         'W': '-', 'X': '.', 'Y': '-', 'Z': '.'}


class UnknownSymbol(ValueError):
    pass


def _digit(char):
    if 'A' <= char <= 'Z':
        return ord(char) - ord('A')
    if 'a' <= char <= 'z':
        return ord(char) - ord('a') + 26
    if '0' <= char <= '9':
        return ord(char) - ord('0') + 52
    raise UnknownSymbol('not a decorated-string digit: %r' % char)


def decode(symbol):
    """Return the literal bytes of a ``??_C@`` symbol, or None if it is not one."""
    # The linker prints either ``??_C@_<size><hash>@<text>@`` or
    # ``??_C@_<size>@<hash>@<text>@`` depending on the literal, so the size
    # and the hash are both optional prefix segments before the text.
    match = re.search(r'\?\?_C@_[^@]*@(?:[0-9A-Za-z]+@)?(.*)', symbol)
    if not match:
        return None
    body = match.group(1)
    out = []
    i = 0
    while i < len(body):
        char = body[i]
        if char == '?' and body[i + 1:i + 2] == '$':
            code = body[i + 2:i + 4]
            if code == 'AA':
                break
            if re.fullmatch('[A-Za-z0-9]{2}', code or ''):
                out.append(_digit(code[0]) * 16 + _digit(code[1]))
                i += 4
                continue
            i += 2
            continue
        if char == '?' and i + 1 < len(body):
            out.append(ord(TABLE.get(body[i + 1], body[i + 1])))
            i += 2
            continue
        out.append(ord(char))
        i += 1
    return bytes(out)


def address(data, secs, symbol):
    """Return the unique VA where the literal occurs, or None.

    Both the NUL-terminated form and the bare bytes are tried, because a literal
    that is the tail of a longer one has no terminator of its own.
    """
    raw = decode(symbol)
    if raw is None:
        return None
    # The symbol name ends with an '@' separator; it is part of the decorated
    # name, not of the literal.  Leaving it in rejected 16 of the 133 string
    # references in one batch, so strip a single trailing '@' before matching.
    if raw.endswith(b'@'):
        raw = raw[:-1]
    for probe in (raw + b'\x00', raw):
        if not probe:
            continue
        hits = set()
        start = 0
        while True:
            j = data.find(probe, start)
            if j < 0:
                break
            for _nm, vaddr, vsize, rawptr, rawsize in secs:
                if rawptr <= j < rawptr + rawsize:
                    hits.add(vaddr + (j - rawptr))
                    break
            start = j + 1
            if len(hits) > 1:
                break
        if len(hits) == 1:
            return next(iter(hits))
    return None
