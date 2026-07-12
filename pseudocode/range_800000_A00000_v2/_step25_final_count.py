import glob, os

OUT = r'C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed\pseudocode\range_800000_A00000_v2'
c_files = glob.glob(os.path.join(OUT, '*.c'))
real = [f for f in c_files if '_step' not in os.path.basename(f)]
print('Total pseudocode .c files: %d' % len(real))

# Check for untracked files from function list
list_file = os.path.join(OUT, 'target_funcs_final.txt')
if os.path.exists(list_file):
    with open(list_file) as f:
        funcs = [line.strip().split(' ', 1) for line in f if line.strip()]
    
    missed = []
    for addr, name in funcs:
        safe = name.replace('/', '_').replace('\\', '_').replace(':', '_')
        safe = safe.replace('<', '_').replace('>', '_').replace('?', '_')
        safe = safe.replace('*', '_').replace('|', '_').replace('"', '_')
        if len(safe) > 120:
            safe = safe[:120]
        fn = '%s_%s.c' % (addr.replace('0x', ''), safe)
        if not os.path.exists(os.path.join(OUT, fn)):
            missed.append((addr, name))
    
    print('Missing from function list: %d' % len(missed))
    for addr, name in missed[:10]:
        print('  %s %s' % (addr, name))
else:
    print('No function list file found')

# File size stats
sizes = [os.path.getsize(f) for f in real]
if sizes:
    print()
    print('File sizes:')
    print('  Average: %d bytes' % (sum(sizes) // len(sizes)))
    print('  Min: %d bytes' % min(sizes))
    print('  Max: %d bytes' % max(sizes))
    print('  Total: %d bytes (%.2f MB)' % (sum(sizes), sum(sizes) / 1024 / 1024))
    
    # Files smaller than 100 bytes (likely empty/thunks)
    tiny = [f for f in real if os.path.getsize(f) < 100]
    print()
    print('Tiny files (<100 bytes): %d' % len(tiny))
    for f in sorted(tiny)[:10]:
        print('  %s (%d bytes)' % (os.path.basename(f), os.path.getsize(f)))

print()
print('=================================================================')
print('EXTRACTION SUMMARY')
print('=================================================================')
print('Range: 0x800000 - 0xA00000')
print('Functions extracted: %d' % len(real))
print('Previous extraction: 24 files')
print('Improvement: %dx' % (len(real) // 24))
print('Output: %s' % OUT)
print('=================================================================')

# Write summary file
with open(os.path.join(OUT, 'SUMMARY.txt'), 'w') as f:
    f.write('FFX Pseudocode Extraction Summary\n')
    f.write('='*50 + '\n')
    f.write('Range: 0x800000 - 0xA00000\n')
    f.write('Functions extracted: %d\n' % len(real))
    f.write('Previous extraction: 24 files\n')
    f.write('Output: %s\n' % OUT)
    f.write('='*50 + '\n')
print('Summary saved to SUMMARY.txt')
