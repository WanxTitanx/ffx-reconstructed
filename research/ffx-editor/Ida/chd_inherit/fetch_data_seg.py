#!/usr/bin/env python3
"""fetch_data_seg.py — dump .data+.rodata+_RDATA (0xC0A000..0x25D9000) via ida_mcp
get_bytes. Server truncates `data` string ~49k chars -> use 0x2000 chunks,
verify every token parses; shrink on failure."""
import sys, json, time
sys.path.insert(0, '/home/wanderson/Documents/ffx-editor-main/research_tools/Ida')
from ida_mcp import post

BASE = 0xC0A000
END = 0x25D9000
CHUNK = 0x2000
OUT = '/home/wanderson/Documents/ffx-editor-main/work/_chd_inherit/data_seg.bin'

sess, _ = post({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                           "clientInfo": {"name": "chd-inherit", "version": "1"}}})
post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sess)


def read_chunk(addr, size):
    """Return bytes or None. Auto-halves on truncated output."""
    while size > 0:
        _, body = post({"jsonrpc": "2.0", "id": 2, "method": "tools/call",
                        "params": {"name": "get_bytes", "arguments":
                                   {"regions": {"addr": hex(addr), "size": size}}}}, sess)
        d = json.loads(body)
        toks = d['result']['structuredContent']['result'][0]['data'].split()
        try:
            bs = bytes(int(t, 16) for t in toks)
        except ValueError:
            size //= 2
            continue
        if len(bs) == size:
            return bs
        if len(bs) > size:   # shouldn't happen
            return bs[:size]
        size = len(bs) if len(bs) < size else size // 2  # short read: accept partial
        if len(bs):
            return bs
    return None


buf = bytearray(END - BASE)
pos = BASE
fails = []
n = 0
t0 = time.time()
while pos < END:
    sz = min(CHUNK, END - pos)
    bs = read_chunk(pos, sz)
    if bs is None:
        fails.append(hex(pos))
    else:
        buf[pos - BASE:pos - BASE + len(bs)] = bs
        if len(bs) < sz:
            # fill remainder next iterations
            pos += len(bs)
            n += 1
            continue
    pos += sz
    n += 1
    if n % 300 == 0:
        print(f'{hex(pos)} {n} calls {time.time()-t0:.0f}s', flush=True)

open(OUT, 'wb').write(buf)
json.dump({"base": hex(BASE), "end": hex(END), "fails": fails},
          open(OUT + '.idx.json', 'w'))
print('DONE', len(buf), 'fails:', fails)
