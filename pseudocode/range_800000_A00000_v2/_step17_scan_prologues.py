import urllib.request, json, os, re

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

CHUNK_SIZE = 0x10000  # 64KB
range_start = 0x800000
range_end = 0xA00000

all_funcs = {}

# Try: search for "endp ; sp-analysis failed" which is unique per function
# Or: search for disasm containing "push    ebp" (function prologue)
# Actually, let's try the regex approach: match lines that start with pattern
# IDA lines: ".text:00XXXXXX                               sub_XXXXXX      proc near"
# The function name + "proc near" on a disasm line

# Strategy: search for "proc near" with include='disasm' to only get disassembly lines
# This filters out comment lines with "CODE XREF" etc.

print("Strategy 1: 'proc near' with include='disasm'")
for start_addr in range(range_start, range_end, CHUNK_SIZE):
    end_addr = min(start_addr + CHUNK_SIZE, range_end)
    sh = '0x%X' % start_addr
    eh = '0x%X' % end_addr
    
    try:
        raw = call('search_text', {
            'database': DB,
            'pattern': 'proc near',
            'start': sh,
            'end': eh,
            'limit': 500,
            'code_only': True,
            'include': 'disasm'
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            addr = h.get('addr', '')
            fn = h.get('function', '')
            if fn:
                all_funcs[addr] = fn
    except Exception as e:
        print('  ERROR %s: %s' % (sh, e))

print('Found: %d unique functions' % len(all_funcs))

# Strategy 2: Search for function-like disasm patterns "sub_XXXXXX      proc near"
# using regex to match the function definition line
func_list_2 = {}
print()
print("Strategy 2: 'endp' with regex for function ending...")
for start_addr in range(range_start, range_end, CHUNK_SIZE):
    end_addr = min(start_addr + CHUNK_SIZE, range_end)
    sh = '0x%X' % start_addr
    eh = '0x%X' % end_addr
    
    try:
        raw = call('search_text', {
            'database': DB,
            'pattern': 'endp',
            'start': sh,
            'end': eh,
            'limit': 500,
            'code_only': True,
            'include': 'disasm'
        })
        
        text = raw['result']['content'][0]['text']
        data = json.loads(text)
        hits = data.get('hits', [])
        
        for h in hits:
            addr = h.get('addr', '')
            matches = h.get('matches', [])
            fn = h.get('function', '')
            if fn:
                # For endp, the addr is the last address of function.
                # But we only store the function name for dedup
                func_list_2[addr] = fn
    except Exception as e:
        print('  ERROR %s: %s' % (sh, e))

print('Found via endp: %d unique functions' % len(func_list_2))

# Compare
print()
print('Strategy 1 first 20:')
fl = sorted(all_funcs.items(), key=lambda x: int(x[0],16) if x[0].startswith('0x') else 0)
for addr, name in fl[:20]:
    print('  %s %s' % (addr, name))

print()
print('Strategy 2 first 20:')
fl2 = sorted(func_list_2.items(), key=lambda x: int(x[0],16) if x[0].startswith('0x') else 0)
for addr, name in fl2[:20]:
    print('  %s %s' % (addr, name))
