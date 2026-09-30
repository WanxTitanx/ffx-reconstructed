#!/usr/bin/env python3
"""Export IDA function calling conventions for pseudocode compilation.

Run with IDA 9.2's Python 3.11 environment:
    py -3.11 export_call_conventions.py input.i64 call-conventions.json
"""
import json
import os
import re
import sys

import idapro
import ida_auto
import ida_name
import idautils
import idc


CALL_CONVENTIONS = ('__cdecl', '__thiscall', '__fastcall', '__stdcall')


def main():
    if len(sys.argv) != 3:
        raise SystemExit('usage: export_call_conventions.py <database.i64> <output.json>')

    database, output = (os.path.abspath(path) for path in sys.argv[1:3])
    idapro.open_database(database, False)
    conventions = {}
    ambiguous = set()
    try:
        ida_auto.auto_wait()
        for ea in idautils.Functions():
            name = ida_name.get_name(ea)
            signature = idc.get_type(ea) or ''
            match = re.search(r'\b(__cdecl|__thiscall|__fastcall|__stdcall)\b', signature)
            if name and match:
                convention = match.group(1)
                for alias in {name, name.replace('::', '_')}:
                    previous = conventions.get(alias)
                    if previous is not None and previous != convention:
                        ambiguous.add(alias)
                    else:
                        conventions[alias] = convention
    finally:
        idapro.close_database(False)

    for name in ambiguous:
        conventions.pop(name, None)
    os.makedirs(os.path.dirname(output), exist_ok=True)
    with open(output, 'w', encoding='utf-8') as f:
        json.dump(conventions, f, indent=2, sort_keys=True)
        f.write('\n')
    print('exported:', len(conventions), 'ambiguous names omitted:', len(ambiguous))


if __name__ == '__main__':
    main()
