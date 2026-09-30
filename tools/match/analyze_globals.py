#!/usr/bin/env python3
"""Infer usable C types for Hex-Rays data-global references.

gen_pseudocode_chunks.py declares every referenced global as a scalar
("extern _DWORD dword_X;").  That is wrong whenever the object is really a byte
buffer, a table or a float slot, and cl.exe then rejects the file with
"subscript requires array or pointer type" or "cannot convert from int * to int".

Hex-Rays keeps the object's shape in how it prints the reference.  A table is
printed "X[i]", "*X" or "(T *)X"; a scalar is printed "X" or "&X".  Counting the
shapes across every chunk decides the declaration.

An object is retyped to an array only when the corpus proves it is reached as a
pointer/index -- it is subscripted ("X[i]"), dereferenced ("*X") or
pointer-cast ("(T *)X") -- and it is *never* read as a plain value, assigned,
incremented or member-accessed.  A bare "&X" is deliberately not evidence: it
compiles the same for a scalar and for an array, and retyping on it alone can
change the meaning of a call that takes a differently-typed pointer.  With this
rule, every use in a body that compiles today still means the same thing.

Public API
----------
    scan(paths) / scan_texts(texts)  -> (file_refs, usage)     raw counters
    classify(name, usage)            -> (kind, ctype, reason)  'scalar'|'array'
    build_prelude(paths, top_n)      -> (prelude dict, report rows)
    prelude_block(prelude)           -> the declarations as one ordered block
"""
import collections
import re

# <ident>_<hex> is how IDA names a referenced address.
GLOB = re.compile(r'\b([a-zA-Z][A-Za-z0-9_]*_(?:[0-9A-Fa-f]{4,}))\b')
CODE_PREFIX = ('sub_', 'loc_', 'nullsub_', 'psub_')
GLOBAL_PREFIX = ('dword_', 'word_', 'byte_', 'unk_', 'off_', 'flt_', 'dbl_',
                 'str_', 'qword_', 'xmmword_', 'asc_', 'funcs_')
SCALAR_TYPE = {'dword_': '_DWORD', 'word_': '_WORD', 'byte_': '_BYTE',
               'unk_': '_DWORD', 'qword_': '_QWORD', 'xmmword_': '_DWORD',
               'off_': 'void *', 'flt_': 'float', 'dbl_': 'double',
               'str_': 'char *', 'asc_': 'char', 'funcs_': 'void *'}
# Element type chosen for an array object, by the IDA prefix.
ELEMENT_TYPE = {'byte_': '_BYTE', 'asc_': 'char', 'str_': 'char',
                'word_': '_WORD', 'qword_': '_QWORD', 'xmmword_': '_DWORD',
                'flt_': 'float', 'dbl_': 'double', 'off_': 'void *',
                'dword_': '_DWORD', 'unk_': '_BYTE'}
# Per-object counters.  'pointer' folds the three shapes that require the object
# to be a pointer/array; the rest are the shapes that forbid it.
KINDS = ('addr', 'castaddr', 'castptr', 'sub', 'deref', 'callarg', 'bare',
         'mem', 'assign', 'incdec')
POINTER_REQUIRING = ('sub', 'deref', 'castptr', 'callarg')
FORBIDDING = ('bare', 'mem', 'assign', 'incdec')

_CAST = re.compile(r'\(\s*([A-Za-z_][\w\s]*?)\s*\*+\s*\)\s*$')
_ASSIGN = re.compile(r'\s*(?:[-+*/%&|^]|<<|>>)=')
_NOCALL = ('if', 'while', 'for', 'switch', 'sizeof', 'return', 'else')


def is_global(name):
    return name.startswith(GLOBAL_PREFIX) and not name.startswith(CODE_PREFIX)


def scalar_type(name):
    for k, v in SCALAR_TYPE.items():
        if name.startswith(k):
            return v
    return '_DWORD'


def element_type(name):
    for k, v in ELEMENT_TYPE.items():
        if name.startswith(k):
            return v
    return '_DWORD'


def strip_comments(src):
    """Drop Hex-Rays comments before looking at identifier shapes.

    The explanatory header and the trailing address notes mention globals by
    name ("Looks up atlas base data from dword_C5C2C8 table"); counting a
    mention as a value read blocks the very retype those bodies need.
    """
    return re.sub(r'/\*.*?\*/', '', src, flags=re.S)


def strip_decls(src):
    """Bodies only: drop the per-file extern/typedef lines."""
    return '\n'.join(l for l in src.splitlines()
                     if not l.startswith(('extern ', 'typedef ')))


def _is_whole_call_arg(body, pos):
    """True when the identifier at pos is the entire argument of a call.

    Walks left to the enclosing '(' and rejects the reference when anything but
    whitespace separates it from that '(', so "&X & 3" or "X ? a : b" used as an
    argument are not treated as a bare address literal.
    """
    depth, i, open_i = 0, pos - 1, None
    while i >= 0:
        c = body[i]
        if c == ')':
            depth += 1
        elif c == '(':
            if depth == 0:
                open_i = i
                break
            depth -= 1
        i -= 1
    if open_i is None or body[open_i + 1:pos].strip():
        return False
    j = open_i - 1
    while j >= 0 and body[j] in ' \t':
        j -= 1
    if j < 0 or not (body[j].isalnum() or body[j] == '_'):
        return False
    k = j
    while k >= 0 and (body[k].isalnum() or body[k] == '_'):
        k -= 1
    callee = body[k + 1:j + 1]
    return bool(callee) and callee not in _NOCALL and not callee[0].isdigit()


def classify_occurrence(body, m):
    """Shape of one reference: how the identifier is used where it appears."""
    pre, post = body[:m.start()], body[m.end():]
    if _ASSIGN.match(post):
        return 'assign'
    if post[:2] in ('++', '--') or pre[-2:] in ('++', '--'):
        return 'incdec'
    # A cast that wraps the identifier's address is "&X" with a type on top; a
    # cast applied directly to the identifier is "(T *)X".  Both compile against
    # either declaration, so only the pointer cast is counted as evidence.
    cm = _CAST.search(pre)
    if cm and not re.search(r'&\s*$', pre[:cm.start()]):
        return 'castptr'
    if cm:
        return 'castaddr'
    # Subscript wins over address-of: "&X[i]" indexes X and then takes the
    # address of the element, so X must be an array/pointer.
    if post[:1] == '[':
        return 'sub'
    if re.search(r'&\s*$', pre):
        return 'addr'
    star = re.search(r'\*\s*$', pre)
    if star and not _is_binary_star(pre[:star.start()]):
        return 'deref'
    if post.startswith('.') or post.startswith('->'):
        return 'mem'
    if _is_whole_call_arg(body, m.start()):
        return 'callarg'
    return 'bare'


def _is_binary_star(before):
    """Distinguish "a * X" / "f() * X" (multiply) from "return *X" / "= *X".

    A '*' is binary when the token to its left is a complete operand -- a
    literal, an identifier that is not a keyword, a closed ')' or a closed ']'.
    """
    before = before.rstrip()
    if not before:
        return False
    if before[-1].isdigit() or before[-1] in ')]':
        return True
    m = re.search(r'([A-Za-z_]\w*)$', before)
    return bool(m) and m.group(1) not in _NOCALL


def scan_texts(texts):
    """Count file references and per-kind body usages for every global."""
    file_refs = collections.Counter()
    usage = collections.defaultdict(lambda: collections.Counter(dict.fromkeys(KINDS, 0)))
    for raw in texts:
        src = strip_comments(raw)
        for n in set(GLOB.findall(src)):
            file_refs[n] += 1
        body = strip_decls(src)
        for m in GLOB.finditer(body):
            usage[m.group(1)][classify_occurrence(body, m)] += 1
    return file_refs, usage


def scan(paths):
    return scan_texts((open(p, encoding='utf-8', errors='replace').read()
                       for p in paths))


def pointer_uses(u):
    return sum(u[k] for k in POINTER_REQUIRING)


def classify(name, u):
    """Return (kind, ctype, reason); kind is 'scalar' or 'array'."""
    if not is_global(name):
        return 'scalar', scalar_type(name), 'code label'
    blocked = [k for k in FORBIDDING if u[k]]
    if blocked and not pointer_uses(u):
        return 'scalar', scalar_type(name), 'read as value (%s)' % ','.join(blocked)
    if blocked:
        # Pointer-shaped somewhere and value-shaped somewhere else: masking it as
        # an array would change the value-shaped bodies, so keep the scalar.
        return 'scalar', scalar_type(name), ('mixed use (%s + %s)'
                                             % (','.join(blocked), 'pointer'))
    if pointer_uses(u):
        return 'array', element_type(name), 'only X[i]/*X/(T *)X uses'
    return 'scalar', scalar_type(name), 'no pointer-shaped use'


def build_prelude_from_texts(texts, top_n=200):
    file_refs, usage = scan_texts(texts)
    ranked = [n for n, _ in file_refs.most_common() if is_global(n)]
    prelude, report = {}, []
    for rank, n in enumerate(ranked, 1):
        kind, ctype, reason = classify(n, usage[n])
        if kind == 'array':
            prelude[n] = 'extern %s %s[];' % (ctype, n)
        if rank <= top_n:
            report.append({'rank': rank, 'name': n, 'refs': file_refs[n],
                           'kind': kind, 'ctype': ctype, 'reason': reason,
                           'usage': {k: usage[n][k] for k in KINDS}})
    return prelude, report


def build_prelude(paths, top_n=200):
    return build_prelude_from_texts(
        [open(p, encoding='utf-8', errors='replace').read() for p in paths], top_n)


def prelude_block(prelude):
    return '\n'.join(prelude[n] for n in sorted(prelude))
