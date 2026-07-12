import urllib.request, json, os, sys, time
from concurrent.futures import ThreadPoolExecutor, as_completed

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'
BATCH_SIZE = 100
MAX_WORKERS = 20
CHUNK_SIZE = 0x10000  # 64KB

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

# Step 1: Scan ALL functions using 64KB chunks (verified working approach)
print("Step 1: Scanning for all functions in 0x800000-0xA00000...")
func_dict = {}
range_start = 0x800000
range_end = 0xA00000

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
            if fn and addr:
                func_dict[addr] = fn
    except Exception as e:
        print('  WARN chunk %s: %s' % (sh, e))
        continue

func_items = sorted(func_dict.items(), key=lambda x: int(x[0], 16) if x[0].startswith('0x') else 0)
total = len(func_items)
print('Found %d functions to decompile' % total)

# Save function list
list_path = os.path.join(OUT, 'target_funcs_final.txt')
with open(list_path, 'w') as f:
    for addr, name in func_items:
        f.write('%s %s\n' % (addr, name))
print('Saved function list to %s' % list_path)

# Step 2: Decompile all functions in parallel batches
print()
print('Step 2: Decompiling functions...')
total_ok = 0
total_skip = 0
total_err = 0
total_empty = 0

def decompile_one(addr, name):
    safe_name = name.replace('/', '_').replace('\\', '_').replace(':', '_')
    safe_name = safe_name.replace('<', '_').replace('>', '_').replace('?', '_')
    safe_name = safe_name.replace('*', '_').replace('|', '_').replace('"', '_')
    if len(safe_name) > 120:
        safe_name = safe_name[:120]
    
    filename = '%s_%s.c' % (addr.replace('0x', ''), safe_name)
    filepath = os.path.join(OUT, filename)
    
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
        
        return (addr, name, 'ok', len(content))
    
    except Exception as e:
        return (addr, name, 'error: %s' % str(e)[:80], 0)

for batch_start in range(0, total, BATCH_SIZE):
    batch = func_items[batch_start:batch_start + BATCH_SIZE]
    batch_idx = batch_start // BATCH_SIZE + 1
    num_batches = (total + BATCH_SIZE - 1) // BATCH_SIZE
    
    sys.stdout.write('\nBatch %d/%d (%d-%d of %d)... ' % (
        batch_idx, num_batches, batch_start + 1, min(batch_start + BATCH_SIZE, total), total))
    sys.stdout.flush()
    
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
            elif status == 'empty':
                total_empty += 1
            else:
                total_err += 1
                sys.stdout.write('\n  ERR: %s %s - %s' % (addr, name, status))
                sys.stdout.flush()
    
    done = total_ok + total_skip + total_err + total_empty
    sys.stdout.write('OK=%d Skip=%d Empty=%d Err=%d (%d/%d)' % (
        total_ok, total_skip, total_empty, total_err, done, total))
    sys.stdout.flush()

print()
print()
print('='*60)
print('EXTRACTION COMPLETE')
print('Total functions found: %d' % total)
print('Decompiled OK: %d' % total_ok)
print('Skipped (already exist): %d' % total_skip)
print('Empty: %d' % total_empty)
print('Errors: %d' % total_err)
print('Output directory: %s' % OUT)

# Count .c files
import glob
c_files = glob.glob(os.path.join(OUT, '*.c'))
editor_files = [f for f in c_files if '_step' not in os.path.basename(f)]
print('.c files in output: %d' % len(editor_files))
print('='*60)
