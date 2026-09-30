#!/usr/bin/env python3
import json, subprocess, sys

ADDRS = """0x630670 0x7110b0 0x79f010 0x888e30 0x6fa3a0 0x640f60 0x785440 0x7e6610
0x640590 0x869de0 0x783730 0x783e30 0x7e3d80 0x7dabf0 0x7d9870 0x7d3630
0xa182f0 0x6a3ca0 0x6a4ba0 0x6e84d0 0x6b45f0 0xaa3640 0x654fd0 0x8bf020
0xa77e00 0xa79370 0xa77d20 0x7c0de0 0x870cd0 0x85b120 0x860aa0 0x860740
0x8573c0 0x8671d0 0x867510 0x867370 0x863510 0x630670""".split()
ADDRS = list(dict.fromkeys(ADDRS))

OUT = open('/home/wanderson/Documents/ffx-editor-main/work/_structural_lift/decompiles_r3.jsonl', 'w')
for a in ADDRS:
    try:
        r = subprocess.run(
            ['python3', 'research_tools/Ida/ida_mcp.py', 'decompile',
             json.dumps({"addr": a, "include_addresses": False})],
            capture_output=True, text=True, timeout=120, cwd='/home/wanderson/Documents/ffx-editor-main')
        d = json.loads(r.stdout)
        OUT.write(json.dumps({'addr': a, 'code': d.get('code', d)}) + '\n')
    except Exception as e:
        OUT.write(json.dumps({'addr': a, 'error': str(e)[:300]}) + '\n')
    OUT.flush()
    print('done', a, file=sys.stderr)
OUT.close()
