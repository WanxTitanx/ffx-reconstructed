"""Reject typed literal pointers into the original image before static linking.

LLVM IR preserves the distinction between an integer constant and a pointer
initializer/call containing the same bits. Dynamic address computations remain
subject to the modification's semantic review and are reported explicitly.
"""
import hashlib
import re


QUOTED_OR_COMMENT = re.compile(r'"(?:[^"\\]|\\.)*"|;[^\n]*')
CAST = re.compile(r'(?<![%@.\w])inttoptr\b')
LITERAL = re.compile(r'inttoptr\s*\(?\s*i([1-9][0-9]*)\s+(-?[0-9]+|true|false)\s+to\s+ptr\b')


def validate_ir(ir, layout):
    if not isinstance(ir, str) or not ir:
        raise ValueError('fresh compiler IR is required for pointer admission')
    triple = re.search(r'^target triple = "([^"]+)"$', ir, re.MULTILINE)
    data_layout = re.search(r'^target datalayout = "([^"]+)"$', ir, re.MULTILINE)
    if (triple is None or re.fullmatch(r'i686-pc-windows-msvc(?:[0-9]+(?:\.[0-9]+)*)?', triple[1]) is None
            or data_layout is None or re.search(r'(?:^|-)p:32:32(?:-|$)', data_layout[1]) is None):
        raise ValueError('compiler IR target or pointer width does not match PE32')
    base = layout['image_base']
    size = layout['optional_header']['size_of_image']
    if type(base) is not int or type(size) is not int or not 0 <= base < base + size <= 2**32:
        raise ValueError('invalid original image range for pointer admission')
    # Strings, quoted symbol names and comments are data, not typed conversions.
    code = QUOTED_OR_COMMENT.sub(lambda match: ' ' * len(match[0]), ir)
    literal_count = dynamic_count = 0
    for cast in CAST.finditer(code):
        literal = LITERAL.match(code, cast.start())
        if literal is None:
            dynamic_count += 1
            continue
        literal_count += 1
        width = int(literal[1])
        value = {'true': 1, 'false': 0}.get(literal[2])
        if value is None:
            value = int(literal[2])
        address = value % (1 << min(width, 32))
        if base <= address < base + size:
            raise ValueError('literal absolute pointer %#x into the original image requires a symbolic binding'
                             % address)
    return {'schema_version': 1, 'kind': 'typed-literal-pointer-admission',
            'ir_sha256': hashlib.sha256(ir.encode('utf-8')).hexdigest(),
            'original_image_base': base, 'original_image_size': size,
            'literal_pointer_count': literal_count, 'dynamic_inttoptr_count': dynamic_count,
            'literal_image_pointers_rejected': True, 'computed_addresses_require_review': True}
