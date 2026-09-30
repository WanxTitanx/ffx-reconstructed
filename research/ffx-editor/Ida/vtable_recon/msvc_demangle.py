#!/usr/bin/env python3
"""Mini MSVC demangler for .?AV/.?AU RTTI TypeDescriptor names and ??_7 vftable symbols.
Produces 'Ns::Class<Ns::Arg, N>' style names. Handles: ?$ templates, V-class refs,
P/A/Q/R/S/T cv-ptr/ref prefixes, basic type letters, $N int constants, digit backrefs."""
import re

BASIC = {
    "X": "void", "D": "char", "C": "signed char", "E": "unsigned char",
    "F": "short", "G": "unsigned short", "H": "int", "I": "unsigned int",
    "J": "long", "K": "unsigned long", "M": "float", "N": "double",
    "O": "long double", "_N": "bool", "W": "wchar_t", "_J": "__int64",
    "_K": "unsigned __int64", "U": "u8",
}

class Demangler:
    def __init__(self, s):
        self.s = s
        self.i = 0
        self.names = []  # fragments for digit backrefs

    def peek(self):
        return self.s[self.i] if self.i < len(self.s) else ""

    def get(self):
        c = self.peek(); self.i += 1; return c

    def backref(self, d):
        d = int(d)
        return self.names[d] if d < len(self.names) else "t" + d

    def parse_name_body(self):
        """Parse 'part@part@...@@' at cursor; returns list of parts (innermost first)."""
        parts = []
        while self.i < len(self.s):
            if self.s.startswith("@@", self.i):
                self.i += 2
                break
            p = self.parse_name_part()
            parts.append(p)
            if self.peek() == "@":
                self.i += 1
            else:
                break
        return parts

    def parse_name_part(self):
        s = self.s
        if s.startswith("?$", self.i):
            self.i += 2
            tname = self.parse_name_part()  # template name (no args)
            args = []
            while self.i < len(s) and s[self.i] != "@":
                args.append(self.parse_type())
            full = tname + "<" + ", ".join(a for a in args if a) + ">"
            self.names.append(full)
            return full
        # plain part until '@' or end
        j = self.i
        while j < len(s) and s[j] != "@":
            j += 1
        part = s[self.i:j]
        self.i = j
        if part and part[0].isdigit() and len(part) == 1:
            part = self.backref(part)
        self.names.append(part)
        return part

    def parse_type(self):
        s = self.s
        c = self.get()
        if c == "$":  # integral constant: $<hex-ish> like $03 $0A@ or e$-style
            # constants appear as $0<nibble chars> in type-arg context
            num = ""
            while self.i < len(s) and s[self.i] not in "@":
                num += self.get()
            return num.lstrip("0") or "0"
        if c.isdigit():
            return self.backref(c)
        if c in "PAQRSTU":
            ptr = c  # P=ptr A=ref Q/R/S/T=cv variants
            cv = ""
            # next char: cv qualifier for pointed type: A=near, B=const, etc.
            q = self.get()
            if q == "6":  # vftable ref
                return self.parse_type()
            if q in "ABCD":
                cv = {"A": "", "B": "const ", "C": "volatile ", "D": "const volatile "}[q]
            else:
                self.i -= 1
                q = ""
            inner = self.parse_type()
            suf = "*" if ptr in "PQSU" else "&"
            return cv + inner + suf
        if c == "V":  # class/struct type — nested name follows, ends '@'
            parts = self.parse_name_body()
            return "::".join(reversed(parts))
        if c == "_":
            c2 = self.get()
            key = "_" + c2
            if key in BASIC:
                return BASIC[key]
            return key
        if c in BASIC:
            return BASIC[c]
        return c

def demangle_type_desc(m):
    """'.?AVFoo@Bar@@' -> 'Bar::Foo' ; '.?AU' unions same. Falls back to input."""
    if not m or not m.startswith(".?A"):
        return m
    s = m[1:]  # ?AV...
    try:
        d = Demangler(s)
        kind = s[:3]  # ?AV ?AU ?AT
        d.i = 3
        parts = d.parse_name_body()
        return "::".join(reversed([p for p in parts if p]))
    except Exception:
        return m

def demangle_vftable_sym(n):
    """'??_7Foo@Bar@@6B@' -> 'Bar::Foo'. '??_6' = vbtable. Falls back to input."""
    if not n.startswith("??_7") and not n.startswith("??_6"):
        return n
    s = n[4:]
    if s.endswith("@@6B@"): s = s[:-5]
    elif s.endswith("@@6B"): s = s[:-4]
    elif s.endswith("@@"): s = s[:-2]
    try:
        d = Demangler(s)
        parts = d.parse_name_body()
        return "::".join(reversed([p for p in parts if p]))
    except Exception:
        return n

def vtbl_name(cls):
    """'Ns::Cls<Ns::Arg, 3>' -> 'vtbl_Ns_Cls_Ns_Arg_3' (IDA-name-safe)."""
    s = cls.replace("::", "_")
    s = re.sub(r"[?$]", "", s)
    s = re.sub(r"[<>,'()\[\] \t\-+*&=.!\"\\/:@~]", "_", s)
    s = re.sub(r"_+", "_", s).strip("_")
    if not s:
        s = "anon"
    return "vtbl_" + s[:180]

if __name__ == "__main__":
    tests = [
        ".?AVPCaller@Phyre@@",
        ".?AV?$PClassDescriptorWithoutDefaultConstructor@VPWorld@Phyre@@@Phyre@@",
        ".?AV?$PClassDescriptorForType@V?$PArray@VPShaderStreamDefinition@PRendering@Phyre@@$03@Phyre@@@Phyre@@",
        "??_7btCylinderShapeZ@@6B@",
        "??_7?$PClassDescriptorConcrete@VPSpriteAnimationInfoInstance@PSprite@Phyre@@@Phyre@@6B@",
        "??_7?$PClassDescriptorForType@V?$PArray@PAVPAnimationChannel@PAnimation@Phyre@@$03@Phyre@@@Phyre@@6B@",
        "??_7FFXApplication@@6B@",
        ".?AVFFXApplication@@",
    ]
    for t in tests:
        d = demangle_vftable_sym(t) if t.startswith("??") else demangle_type_desc(t)
        print(t[:70], "->", d, "|", vtbl_name(d))
