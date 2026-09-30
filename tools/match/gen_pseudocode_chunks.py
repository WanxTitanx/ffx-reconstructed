#!/usr/bin/env python3
"""Turn the Hex-Rays pseudocode corpus into compilable chunks.

Each pseudocode file decompiles one function. Concatenating many of them into a
single translation unit turns 19k compiles into a few hundred. Every function is
self-contained (all callees and globals are extern), so concatenation is safe.

The decompiler output needs a small amount of repair to compile under VS2012 C:
  * define the IDA types (_BYTE/_WORD/_DWORD/_QWORD/...) and the Hex-Rays helper
    macros/instrinsics (LODWORD/COERCE_INT/__PAIR64__/...);
  * flatten C++ scope (Phyre::PBase -> Phyre_PBase);
  * rename the C++ keyword 'this'; map __thiscall onto __fastcall;
  * map __usercall (with its register annotations) onto __stdcall;
  * strip IDA array markers (flt_X[0] -> flt_X) and the vftable backtick;
  * erase the "... [N chars total]" markers baked into the corpus;
  * declare every referenced global and callee.

Global declarations come from analyze_globals.py, which infers a table type for
the objects Hex-Rays only ever reaches through an address, so the binary's
"push 0xC5C2C8" is reproduced instead of a dword load.
"""
import base64, glob, json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import analyze_globals

OUT = '/tmp/chunks'
PER = 100
FUNCTION_CONVENTIONS = {}

PRE_TYPES = '''typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned long long _QWORD;
typedef long long _LONGLONG;
typedef int _BOOL;
typedef void _UNKNOWN;

/* Hex-Rays helper macros and intrinsics the decompiler leaves in the bodies.
   Each is an expression, so it is defined as a cast or a two-argument macro
   exactly as the Hex-Rays C output expects it. */
#define LODWORD(x) (*(_DWORD *)&(x))
#define HIDWORD(x) (*(_DWORD *)((char *)&(x) + 4))
#define SLODWORD(x) (*(int *)&(x))
#define SHIDWORD(x) (*(int *)((char *)&(x) + 4))
#define LOWORD(x) (*(_WORD *)&(x))
#define HIWORD(x) (*(_WORD *)((char *)&(x) + 2))
#define LOBYTE(x) (*(_BYTE *)&(x))
#define HIBYTE(x) (*(_BYTE *)((char *)&(x) + 1))
#define SLOBYTE(x) (*(signed char *)&(x))
#define SHIBYTE(x) (*(signed char *)((char *)&(x) + 1))
#define BYTE1(x) (*(_BYTE *)((char *)&(x) + 1))
#define BYTE2(x) (*(_BYTE *)((char *)&(x) + 2))
#define COERCE_INT(x) ((int)(x))
#define COERCE_FLOAT(x) ((float)(x))
#define COERCE_DOUBLE(x) ((double)(x))
#define MEMORY ((_DWORD *)0)
#define __PAIR64__(hi, lo) (((_QWORD)(_DWORD)(hi) << 32) | (_DWORD)(lo))
#define __SPAIR64__(hi, lo) (((_LONGLONG)(int)(hi) << 32) | (_DWORD)(lo))
#define __ROL4__(x, n) (((_DWORD)(x) << (n)) | ((_DWORD)(x) >> (32 - (n))))
#define __ROL2__(x, n) (((_WORD)(x) << (n)) | ((_WORD)(x) >> (16 - (n))))
#define __ROR4__(x, n) (((_DWORD)(x) >> (n)) | ((_DWORD)(x) << (32 - (n))))
#define __ROR2__(x, n) (((_WORD)(x) >> (n)) | ((_WORD)(x) << (16 - (n))))
#define __CFADD__(a, b) ((_DWORD)(a) + (_DWORD)(b) < (_DWORD)(a))
#define __OFADD__(a, b) (((int)(a) + (int)(b)) < (int)(a))
#define __OFSUB__(a, b) (((int)(a) - (int)(b)) > (int)(a))
#define __SETP__(a, b) 0
union __m64u { unsigned __int64 q; _DWORD d[2]; };
typedef union __m64u __m64;
typedef struct { _QWORD low; _QWORD high; } __m128i;
'''

# Identifiers a decompiled body may reference but never declares itself.
STD_TYPEDEFS = '''typedef unsigned int size_t;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef unsigned char bool;
typedef void *HANDLE;
typedef void *LPVOID;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef struct _FILE FILE;
extern FILE *stderr;
/* Opaque engine, Windows and Lua types that appear in Hex-Rays signatures but
   are never defined by the emitted unit.  Their layout is irrelevant because
   only pointers to them are used. */
typedef struct lua_State lua_State;
typedef struct lua_TValue TValue;
typedef union _LARGE_INTEGER { struct { _DWORD LowPart; int HighPart; } u; _LONGLONG QuadPart; } LARGE_INTEGER;
typedef struct _SYSTEMTIME { _WORD wYear, wMonth, wDayOfWeek, wDay, wHour, wMinute, wSecond, wMilliseconds; } SYSTEMTIME;
typedef void *HMODULE;
typedef void *HINSTANCE;
typedef void *HWND;
typedef void *HKEY;
typedef void *HGLOBAL;
typedef int BOOLEAN;
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
typedef unsigned int UINT32;
typedef int INT32;
typedef unsigned long DWORD_PTR;
typedef long LONG;
typedef unsigned long long SIZE_T;
typedef int HRESULT;
typedef unsigned char u_char;
typedef struct { _DWORD v[4]; } __m128;
typedef struct { _DWORD v[2]; } __m64i;
typedef struct { _DWORD v[8]; } __m256i;
'''

# Identifiers the shared header declares as types or objects, so a body never
# needs a per-file declaration for them.
HEADER_NAMES = frozenset('''bool size_t FILE BOOL DWORD WORD BYTE HANDLE
LPVOID LPCSTR LPSTR UINT ULONG stderr'''.split())

# Hex-Rays helper names that the header defines as macros.  A per-file
# 'extern _DWORD LODWORD();' would expand the macro and break the file, so
# they must never be declared as functions.
HEXR_MACROS = frozenset([
     'LODWORD', 'HIDWORD', 'SLODWORD', 'SHIDWORD', 'LOWORD', 'HIWORD',
     'LOBYTE', 'HIBYTE', 'SLOBYTE', 'SHIBYTE', 'BYTE1', 'BYTE2', 'COERCE_INT',
     'COERCE_FLOAT', 'COERCE_DOUBLE', 'MEMORY', '__PAIR64__', '__SPAIR64__',
     '__ROL4__', '__ROL2__', '__ROR4__', '__ROR2__', '__CFADD__', '__OFADD__',
     '__OFSUB__', '__SETP__',
])

KW = set('''if else for while do switch case default return break continue goto sizeof
void int char float double unsigned signed long short struct union enum const static
extern typedef volatile register inline __int64 __int8 __int16 _BYTE _WORD _DWORD
_QWORD _LONGLONG _BOOL _UNKNOWN self'''.split())


GLOB = re.compile(r'\b([a-zA-Z][A-Za-z0-9_]*_(?:[0-9A-Fa-f]{4,}))\b')

TYPEMAP = [('qword_', '_QWORD'), ('dword_', '_DWORD'), ('word_', '_WORD'),
           ('byte_', '_BYTE'), ('unk_', '_DWORD'), ('off_', 'void *'),
           ('flt_', 'float'), ('dbl_', 'double'), ('str_', 'char *'),
           ('asc_', 'char'), ('funcs_', 'void *')]

# U+0060 is what IDA puts before an array subscript (flt_X[0]) and before a
# vftable name.  It is not valid C, so it is erased; the subscript is kept.
ARR = re.compile('\x60(\\d+)')

# C++ template instantiations Hex-Rays left in an identifier, e.g.
# 'Phyre_PClassDescriptorAbstract<Phyre_PArray<...>>_vftable' or the
# callable 'std_vector<void *>_size'.  Angle brackets are not valid C,
# so the vftable forms collapse to the class address and the rest lose
# the argument list.  TPL is anchored on a name character at both ends
# and may not contain statement punctuation, so a comparison such as
# 'i <= 256' is never mistaken for a template list.
# The vftable patterns consume the & in front of the address literal.
TPL_VFT = re.compile("&?\\s*([A-Za-z_]\\w*)(?:<[^<>]*(?:<[^<>]*>[^<>]*)*>)+[_A-Za-z0-9]*`vftable\\'")
VFT = re.compile("&?\\s*([A-Za-z_]\\w*)_`vftable'")
TPL = re.compile('(?<=[A-Za-z0-9_])<[^<>;(){}\n]{0,80}>(?=[A-Za-z_])')


# Names VS2012 resolves as compiler intrinsics: a declaration would be an error.
BARE_INTRINSICS = ('strcpy', 'strcat', 'strcmp', 'strlen', 'memset', 'memcpy',
                   'memmove', 'memcmp', 'sprintf', 'wsprintfA', 'abs', 'labs',
                   'fabs', 'sin', 'cos', 'tan', 'sqrt', 'pow', 'log', 'log10',
                   'exp', 'atan', 'atan2', 'floor', 'ceil', 'fmod', 'rand',
                   'strset', 'strncat', 'strncpy', 'strncmp', 'strchr',
                   'strrchr', 'strstr', 'strtod', 'strtol', 'strtoul', 'atoi',
                   'atol', 'atof', 'qmemcpy', 'memchr', 'wcscpy', 'alloca',
                   'setjmp', 'longjmp', '_alloca')


def own_name(src):
    m = re.search(r'Function:\s*([A-Za-z_][A-Za-z0-9_]*)', src)
    if m:
        return m.group(1)
    # Bodies taken from the raw `pseudocode/complete/<range>/` layout carry no
    # `// Function:` marker, only the definition itself.  Without this fallback
    # the function being defined is also emitted as an `extern` declaration of
    # itself, which does not compile.
    # Locate the header of the first function body: the identifier immediately
    # before the parameter list that precedes the first opening brace.
    brace = src.find('{')
    if brace < 0:
        return None
    close = src.rfind(')', 0, brace)
    if close < 0:
        return None
    depth = 0
    for i in range(close, -1, -1):
        if src[i] == ')':
            depth += 1
        elif src[i] == '(':
            depth -= 1
            if depth == 0:
                break
    else:
        return None
    head = src[:i]
    # The identifier is everything from the last delimiter (start of line,
    # whitespace, '*', '&', ':', '>') up to the opening parenthesis.
    m = re.search(r'([^\s\*&\n]+)\s*$', head)
    if not m:
        return None
    return re.sub(r'<[^<>]*>', '', m.group(1)).lstrip('~') or None


PRELUDE = ''          # shared typed declarations, filled in by collect_prelude()
PRE = PRE_TYPES       # full header; extended by ensure_prelude()
PRELUDE_BANNER = ('/* Shared per-global declarations inferred from Hex-Rays use.\n'
                  '   Generated by analyze_globals.py -- do not edit by hand. */')
_PRELUDE_READY = False


def ensure_prelude():
    """Build the shared global declarations once, on first use.

    Every consumer of transform() goes through this, including the ones that
    prepend PRE themselves.  PRE is rewritten here to carry the inferred
    declarations, so a caller that writes "PRE + body" -- rather than
    unit_header() -- still sees the tables declared as arrays.  Without it the
    bodies that take a global's address (the "push 0xC5C2C8" case) are emitted
    undeclared and fail to compile.
    """
    global _PRELUDE_READY, PRE
    if not _PRELUDE_READY:
        collect_prelude(*load_functions())
        PRE = header_text()
    return PRELUDE


def header_text():
    """Typedefs, Hex-Rays macros and the inferred global declarations."""
    return (PRE_TYPES + '\n' + STD_TYPEDEFS + '\n'
            + analyze_globals.prelude_block(PRELUDE) + '\n')


def unit_header():
    """Prelude for one translation unit: base typedefs + every global once."""
    ensure_prelude()
    return PRE


def _balance_braces(s):
    """Append the braces a truncated body is missing.

    113 corpus files were cut off mid-body with a "... [N chars total]"
    marker; after the marker is erased those bodies end without their closing
    brace.  Only ever adds, and only when the body opens more than it closes.
    """
    diff = s.count('{') - s.count('}')
    return s + '}' * diff if diff > 0 else s


def _strip_templates(s):
    """Erase C++ template argument lists that are not inside a string.

    Hex-Rays prints a class or template name with its arguments, as in
    "std_vector<void *>_size"; the angle brackets are not valid C.  A message
    such as "invalid map/set<T> iterator" is a real string literal and has to
    keep its text, so the substitution only runs outside quotes.
    """
    out, buf, in_str, i = [], [], False, 0
    while i < len(s):
        c = s[i]
        if in_str:
            buf.append(c)
            if c == '\\' and i + 1 < len(s):
                buf.append(s[i + 1])
                i += 2
                continue
            if c == '"':
                out.append(''.join(buf))
                buf = []
                in_str = False
            i += 1
            continue
        if c == '"':
            out.append(TPL.sub('', ''.join(buf)))
            out.append(c)
            buf = []
            in_str = True
            i += 1
            continue
        buf.append(c)
        i += 1
    out.append(TPL.sub('', ''.join(buf)))
    return ''.join(out)


def _single_argument_call(src, name):
    """Return true when every source call to name has exactly one argument."""
    code = re.sub(r'//[^\n]*|/\*.*?\*/', '', src, flags=re.S)
    pattern = re.compile(r'\b' + re.escape(name) + r'\s*\(')
    arities = []
    for match in pattern.finditer(code):
        i = match.end()
        nesting = 0
        commas = 0
        has_argument = False
        quote = None
        while i < len(code):
            ch = code[i]
            if quote:
                has_argument = True
                if ch == '\\':
                    i += 2
                    continue
                if ch == quote:
                    quote = None
            elif ch in ('"', "'"):
                quote = ch
                has_argument = True
            elif ch in '([{':
                nesting += 1
                has_argument = True
            elif ch in ')]}':
                if ch == ')' and nesting == 0:
                    break
                nesting = max(0, nesting - 1)
                has_argument = True
            elif ch == ',' and nesting == 0:
                commas += 1
            elif not ch.isspace():
                has_argument = True
            i += 1
        else:
            continue
        arities.append(commas + 1 if has_argument else 0)
    return bool(arities) and all(arity == 1 for arity in arities)


def _external_function_decl(src, name, return_type, function_conventions=None):
    conventions = FUNCTION_CONVENTIONS if function_conventions is None else function_conventions
    if (conventions.get(name) in ('__thiscall', '__fastcall')
            and _single_argument_call(src, name)):
        return 'extern %s __fastcall %s(void *);' % (return_type, name)
    return 'extern %s %s();' % (return_type, name)


def rewrite_unit_call_conventions(src, function_conventions=None):
    """Fix old-style extern declarations in an already emitted C unit."""
    marker = re.search(r'(?m)^// Function:', src)
    if not marker:
        return src, 0
    header, body = src[:marker.start()], src[marker.start():]
    declaration = re.compile(r'^extern\s+(.+?)\s+([A-Za-z_]\w*)\s*\(\s*\)\s*;\s*$')
    lines = header.splitlines()
    rewritten = 0
    for i, line in enumerate(lines):
        match = declaration.match(line)
        if not match:
            continue
        return_type, name = match.group(1).strip(), match.group(2)
        replacement = _external_function_decl(
            body, name, return_type, function_conventions
        )
        if replacement != line:
            lines[i] = replacement
            rewritten += 1
    if not rewritten:
        return src, 0
    return '\n'.join(lines) + '\n' + body, rewritten


def transform(src):
    src, _ = rewrite_unit_call_conventions(src)
    ensure_prelude()
    s = src.replace('::', '_')
    # __usercall register annotations such as '@<eax>', and any other '@',
    # as it is not valid C and never introduces an identifier.
    s = re.sub(r'@<[^<>]*>', '', s)
    s = re.sub(r'@<[^<>]*>', '', s)
    s = ARR.sub('', s)
    # The class name is only an identifier after the :: flattening above.
    # A vftable is an address literal in the image, so the & and the template
    # arguments Hex-Rays printed around it both go away, leaving the address
    # of the class's vftable.
    vft_names = set(re.findall("([A-Za-z_]\\w*)(?:<[^<>]*(?:<[^<>]*>[^<>]*)*>)?_`vftable'", s))
    # `s` already has '::' flattened, so the fallback detector in own_name
    # recovers the emitted definition name rather than the last '::' component.
    self_name = own_name(s)
    s = TPL_VFT.sub(r'(int)&\1', s)
    s = VFT.sub(r'(int)&\1', s)
    s = _strip_templates(s)
    s = re.sub(r'\bint\s+__thiscall\s*\(', 'int __fastcall(', s)
    s = re.sub(r'__thiscall', '__fastcall', s)
    s = re.sub(r'\bthis\b', 'self', s)
    s = re.sub(r'\b__int8\b', 'char', s)
    s = re.sub(r'\b__int16\b', 'short', s)
    s = re.sub(r'\b__usercall\b', '__stdcall', s)
    s = s.replace('@', '')
    s = re.sub(r'[^\n]*\[\d+ chars total\][^\n]*', '', s)
    s = re.sub(r'/\*0x[0-9a-fA-F]+\*/', '', s)
    s = s.replace('/*?*/', '')
    s = s.replace('\x60', '')
    s = re.sub(r'(sub_[0-9A-Fa-f]{4,})\.pdb\b', r'\1', s)
    names = sorted(set(GLOB.findall(s)) - {self_name})
    called = set(re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*_[0-9A-Fa-f]{4,})\s*\(', s))
    called.discard(self_name)
    open_calls = set(re.findall(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(', s)) - KW
    known = set(names) | called | {self_name}
    unknown_calls = sorted(c for c in open_calls
                           if c not in known
                           and not c.startswith(('_', 'sub_'))
                           and GLOB.fullmatch(c) is None
                           and not c.startswith(('dword_', 'word_', 'byte_', 'unk_',
                                                 'off_', 'flt_', 'dbl_', 'str_')))
    hdr = []
    for n in names:
        if n in called or n in PRELUDE:
            continue
        t = '_DWORD'
        for k, v in TYPEMAP:
            if n.startswith(k):
                t = v
                break
        hdr.append('extern %s %s;' % (t, n))
    for n in sorted(vft_names - {self_name} - set(PRELUDE)):
        hdr.append('extern _DWORD %s;' % n)
    for n in sorted(called):
        hdr.append(_external_function_decl(s, n, 'int'))
    for n in unknown_calls:
        if n in BARE_INTRINSICS or n in HEADER_NAMES or n in HEXR_MACROS:
            continue
        hdr.append(_external_function_decl(s, n, '_DWORD'))
    s = _balance_braces(s)
    if not hdr:
        return s
    # The declarations must follow any typedefs and macros already present in
    # the body.  Emitting them first made every pool unit fail with
    # "C2061: syntax error : identifier ..." on line 1, because the types the
    # declarations use were declared further down: 2,816 of 3,109 otherwise
    # buildable units failed for this reason alone.
    lines = s.splitlines()
    last = -1
    for i, line in enumerate(lines[:400]):
        if line.startswith(('typedef ', '#define ')):
            last = i
    if last < 0:
        return '\n'.join(hdr) + '\n' + s
    head, tail = lines[:last + 1], lines[last + 1:]
    return '\n'.join(head + hdr + tail) + '\n' 


def load_functions():
    """Return (sorted addresses, {address: path}) for every decompiled function."""
    seen = {}
    for p in sorted(glob.glob('/mnt/ssd-kingston/ffx-reconstructed/pseudocode/*/*.c')):
        head = open(p, encoding='utf-8', errors='replace').read(1200)
        if 'NOT EXTRACTED' in head or 'not decompiled' in head:
            continue
        m = re.search(r'Address:\s*(0x[0-9a-fA-F]+)', head)
        if not m:
            continue
        va = int(m.group(1), 16)
        seen.setdefault(va, p)
    return sorted(seen), seen


def collect_prelude(keys, seen, top_n=200):
    """Learn every data global's use across the corpus and fill the shared prelude."""
    global PRELUDE, _PRELUDE_READY
    texts = [open(seen[va], encoding='utf-8', errors='replace').read() for va in keys]
    PRELUDE, report = analyze_globals.build_prelude_from_texts(texts, top_n=top_n)
    _PRELUDE_READY = True
    arrays = [r for r in report if r['kind'] == 'array']
    print('prelude globals: %d (retyped arrays: %d)' % (len(PRELUDE), len(arrays)))
    return report


def emit_units(outdir, pattern='f%08X.c'):
    """Write one translation unit per function, all sharing the typed prelude."""
    keys, seen = load_functions()
    report = collect_prelude(keys, seen)
    os.makedirs(outdir, exist_ok=True)
    with open(os.path.join(outdir, 'prelude_globals.h'), 'w', encoding='utf-8') as f:
        f.write(PRELUDE_BANNER + '\n' + analyze_globals.prelude_block(PRELUDE) + '\n')
    for va in keys:
        src = open(seen[va], encoding='utf-8', errors='replace').read()
        open(os.path.join(outdir, pattern % va), 'w',
             encoding='utf-8').write(unit_header() + transform(src))
    print('units emitted:', len(keys))
    return report


def main():
    global FUNCTION_CONVENTIONS
    outdir = sys.argv[1] if len(sys.argv) > 1 else OUT
    per = int(sys.argv[2]) if len(sys.argv) > 2 else PER
    if len(sys.argv) > 3:
        with open(sys.argv[3], encoding='utf-8') as f:
            FUNCTION_CONVENTIONS = json.load(f)
    os.makedirs(outdir, exist_ok=True)
    keys, seen = load_functions()
    print('unique functions:', len(keys))
    collect_prelude(keys, seen)
    with open(os.path.join(outdir, 'prelude_globals.h'), 'w', encoding='utf-8') as f:
        f.write(PRELUDE_BANNER + '\n' + analyze_globals.prelude_block(PRELUDE) + '\n')
    for ci in range(0, len(keys), per):
        part = keys[ci:ci + per]
        body = [unit_header()]
        for va in part:
            body.append(transform(open(seen[va], encoding='utf-8', errors='replace').read()))
        open(os.path.join(outdir, 'c%04d.c' % (ci // per)), 'w', encoding='utf-8').write('\n'.join(body))
    print('chunks written:', (len(keys) + per - 1) // per)


if __name__ == '__main__':
    main()
