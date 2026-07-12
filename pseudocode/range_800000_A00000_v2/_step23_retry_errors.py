import urllib.request, json, os, sys
from concurrent.futures import ThreadPoolExecutor, as_completed

MCP = 'http://127.0.0.1:8745/mcp'
DB = '1b332ea0'
OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'
MAX_WORKERS = 8  # Lower concurrency to avoid connection saturation

def call(m, args):
    body = json.dumps({'jsonrpc':'2.0','id':1,'method':'tools/call',
                       'params':{'name':m,'arguments':args}})
    req = urllib.request.Request(MCP, data=body.encode(),
                                 headers={'Content-Type':'application/json'})
    resp = urllib.request.urlopen(req, timeout=300)
    return json.loads(resp.read().decode())

# Read the function list
with open(os.path.join(OUT, 'target_funcs_final.txt'), 'r') as f:
    lines = f.readlines()

all_funcs = []
for line in lines:
    parts = line.strip().split(' ', 1)
    if len(parts) == 2:
        all_funcs.append((parts[0], parts[1]))

# Find which ones don't have .c files (errors + skipped)
missing_funcs = []
existing_count = 0
for addr, name in all_funcs:
    safe_name = name.replace('/', '_').replace('\\', '_').replace(':', '_')
    safe_name = safe_name.replace('<', '_').replace('>', '_').replace('?', '_')
    safe_name = safe_name.replace('*', '_').replace('|', '_').replace('"', '_')
    if len(safe_name) > 120:
        safe_name = safe_name[:120]
    filename = '%s_%s.c' % (addr.replace('0x', ''), safe_name)
    filepath = os.path.join(OUT, filename)
    if os.path.exists(filepath):
        existing_count += 1
    else:
        missing_funcs.append((addr, name))

print('Existing .c files: %d' % existing_count)
print('Missing .c files (to retry): %d' % len(missing_funcs))

if not missing_funcs:
    print('Nothing to retry!')
    sys.exit(0)

# Retry with lower concurrency
print()
print('Retrying with MAX_WORKERS=%d...' % MAX_WORKERS)
retry_ok = 0
retry_err = 0
retry_empty = 0

def decompile_one(addr, name):
    safe_name = name.replace('/', '_').replace('\\', '_').replace(':', '_')
    safe_name = safe_name.replace('<', '_').replace('>', '_').replace('?', '_')
    safe_name = safe_name.replace('*', '_').replace('|', '_').replace('"', '_')
    if len(safe_name) > 120:
        safe_name = safe_name[:120]
    filename = '%s_%s.c' % (addr.replace('0x', ''), safe_name)
    filepath = os.path.join(OUT, filename)
    
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
        return (addr, name, 'retry_err: %s' % str(e)[:60], 0)

# Process in smaller batches
for i in range(0, len(missing_funcs), 50):
    batch = missing_funcs[i:i+50]
    sys.stdout.write('Retry batch %d/%d... ' % (i//50 + 1, (len(missing_funcs)+49)//50))
    sys.stdout.flush()
    
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
        futures = {}
        for addr, name in batch:
            future = executor.submit(decompile_one, addr, name)
            futures[future] = (addr, name)
        
        for future in as_completed(futures):
            addr, name, status, size = future.result()
            if status == 'ok':
                retry_ok += 1
            elif status == 'empty':
                retry_empty += 1
            else:
                retry_err += 1
    
    sys.stdout.write('OK=%d Empty=%d Err=%d (total: OK=%d Err=%d)\n' % (
        retry_ok, retry_empty, retry_err, existing_count + retry_ok, retry_err))
    sys.stdout.flush()

print()
print('Retry complete:')
print('  New OK: %d' % retry_ok)
print('  Empty: %d' % retry_empty)
print('  Still failing: %d' % retry_err)
print('  Total .c files: %d' % (existing_count + retry_ok))

# Final count
import glob
c_files = glob.glob(os.path.join(OUT, '*.c'))
editor_files = [f for f in c_files if '_step' not in os.path.basename(f)]
print('Final .c file count: %d' % len(editor_files))
