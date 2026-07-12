import urllib.request, json, os, sys, time
from concurrent.futures import ThreadPoolExecutor, as_completed

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'
BATCH_SIZE = 100
MAX_WORKERS = 20  # max-workers in idalib-mcp config

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

# Load the function list from strategy 1 (proc near with disasm)
print("Loading function list...")
raw = call('search_text', {
    'database': DB,
    'pattern': 'proc near',
    'start': '0x800000',
    'end': '0xA00000',
    'limit': 500,
    'code_only': True,
    'include': 'disasm'
})

text = json.loads(raw['result']['content'][0]['text'])
hits = text.get('hits', [])

# Build unique function dict
func_dict = {}
for h in hits:
    addr = h.get('addr', '')
    fn = h.get('function', '')
    if fn and addr:
        func_dict[addr] = fn

func_items = sorted(func_dict.items(), key=lambda x: int(x[0], 16) if x[0].startswith('0x') else 0)
total = len(func_items)
print('Total functions to decompile: %d' % total)

# Save function list
with open(os.path.join(OUT, 'target_funcs_list.txt'), 'w') as f:
    for addr, name in func_items:
        f.write('%s %s\n' % (addr, name))

def decompile_one(addr, name):
    """Decompile one function and save to file"""
    safe_name = name.replace('/', '_').replace('\\', '_').replace(':', '_')
    safe_name = safe_name.replace('<', '_').replace('>', '_').replace('?', '_')
    safe_name = safe_name.replace('*', '_').replace('|', '_').replace('"', '_')
    # truncate long names
    if len(safe_name) > 120:
        safe_name = safe_name[:120]
    
    filename = '%s_%s.c' % (addr.replace('0x', ''), safe_name)
    filepath = os.path.join(OUT, filename)
    
    # Skip if already exists
    if os.path.exists(filepath):
        return (addr, name, 'skipped', 0)
    
    try:
        raw = call('decompile', {
            'database': DB,
            'addr': addr,
            'include_addresses': False
        })
        
        code = ''
        if 'result' in raw:
            result_text = raw['result']['content'][0]['text']
            result_data = json.loads(result_text)
            code = result_data.get('code', '')
        
        if not code:
            return (addr, name, 'empty', 0)
        
        content = '// Function: %s\n// Address: %s\n%s\n' % (name, addr, code)
        
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(content)
        
        size = len(content)
        return (addr, name, 'ok', size)
    
    except Exception as e:
        return (addr, name, 'error: %s' % str(e)[:60], 0)

# Process in batches
total_ok = 0
total_skip = 0
total_err = 0

for batch_start in range(0, total, BATCH_SIZE):
    batch = func_items[batch_start:batch_start + BATCH_SIZE]
    batch_idx = batch_start // BATCH_SIZE + 1
    num_batches = (total + BATCH_SIZE - 1) // BATCH_SIZE
    
    print('\nBatch %d/%d (%d-%d of %d)...' % (
        batch_idx, num_batches, batch_start + 1, min(batch_start + BATCH_SIZE, total), total))
    
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
        futures = {}
        for addr, name in batch:
            future = executor.submit(decompile_one, addr, name)
            futures[future] = (addr, name)
        
        for future in as_completed(futures):
            addr, name, status, size = future.result()
            if status == 'ok':
                total_ok += 1
            elif status == 'skipped':
                total_skip += 1
            else:
                total_err += 1
                print('  ERR: %s %s - %s' % (addr, name, status))
    
    # Print progress
    done = total_ok + total_skip + total_err
    print('  Progress: %d/%d (OK=%d, Skip=%d, Err=%d)' % (
        done, total, total_ok, total_skip, total_err))

print('\n' + '='*60)
print('EXTRACTION COMPLETE')
print('Total functions: %d' % total)
print('Decompiled OK: %d' % total_ok)
print('Skipped (already exist): %d' % total_skip)
print('Errors: %d' % total_err)
print('Output: %s' % OUT)
print('='*60)
