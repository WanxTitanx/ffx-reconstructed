import urllib.request, json, os, sys, glob
from concurrent.futures import ThreadPoolExecutor, as_completed

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

# 1. Retry the 2 persistent failures
print("=== Retrying 2 persistent failures ===")
failed = ['0x8135e0', '0x99dac0']
for addr in failed:
    try:
        raw = call('decompile', {'database': DB, 'addr': addr, 'include_addresses': False})
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        code = data.get('code', '')
        name = data.get('addr', addr)
        print('  %s: got %d chars of code' % (addr, len(code)))
    except Exception as e:
        print('  %s: %s' % (addr, e))

# 2. Search for missing functions using "proc" (without "near") and "proc far"
print()
print("=== Checking for 'proc' (without near) and 'proc far' ===")
CHUNK_SIZE = 0x20000
range_start = 0x800000
range_end = 0xA00000

for search_term in ['proc far', 'proc near']:
    count = 0
    for start_addr in range(range_start, range_end, CHUNK_SIZE):
        end_addr = min(start_addr + CHUNK_SIZE, range_end)
        try:
            raw = call('search_text', {
                'database': DB,
                'pattern': search_term,
                'start': '0x%X' % start_addr,
                'end': '0x%X' % end_addr,
                'limit': 500,
                'code_only': True,
                'include': 'disasm'
            })
            text = json.loads(raw['result']['content'][0]['text'])
            hits = text.get('hits', [])
            count += len(hits)
        except:
            pass
    print('  "%s": %d hits' % (search_term, count))

# 3. Count .c files
c_files = glob.glob(os.path.join(OUT, '*.c'))
editor_files = [f for f in c_files if '_step' not in os.path.basename(f)]
print()
print('=== Final count ===')
print('Total .c pseudocode files: %d' % len(editor_files))

# 4. Show sample named functions (not sub_)
named = []
for fp in editor_files:
    basename = os.path.basename(fp)
    # Parse name from filename: <addr>_<name>.c
    parts = basename.split('_', 1)
    if len(parts) >= 2:
        name_part = parts[1].replace('.c', '')
        if not name_part.startswith('sub_') and not name_part.startswith('nullsub'):
            named.append((parts[0], name_part))

print('Named functions (non-sub_): %d' % len(named))
named.sort()
for addr_tag, name in named[:30]:
    print('  %s %s' % (addr_tag, name))

# 5. Count by address range
ranges = {'0x800000-0x880000': 0, '0x880000-0x900000': 0,
          '0x900000-0x980000': 0, '0x980000-0xA00000': 0}
for fp in editor_files:
    basename = os.path.basename(fp)
    addr_str = basename.split('_')[0]
    try:
        addr = int(addr_str, 16)
        for rng in ranges:
            rng_start = int(rng.split('-')[0], 16)
            rng_end = int(rng.split('-')[1], 16)
            if rng_start <= addr < rng_end:
                ranges[rng] += 1
                break
    except:
        pass

print()
print('Functions by address range:')
for rng, cnt in sorted(ranges.items()):
    print('  %s: %d' % (rng, cnt))
