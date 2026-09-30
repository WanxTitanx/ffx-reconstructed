import struct

data = open('0328.fev','rb').read()
lgcy = data[0x152:0x152+547]

print('=== LGCY strings ===')
i = 0
while i < len(lgcy):
    if lgcy[i] == 0:
        i += 1
        continue
    if 32 <= lgcy[i] < 127:
        end = i
        while end < len(lgcy) and lgcy[end] != 0:
            end += 1
        s = lgcy[i:end].decode('ascii', errors='replace')
        if len(s) >= 2:
            print('  @+0x%03x (%3d): "%s"' % (i, i, s))
        i = end
    else:
        i += 1

print()
print('=== LGCY tail (last 80 bytes) ===')
for i in range(max(0, len(lgcy)-80), len(lgcy), 16):
    chunk = lgcy[i:i+16]
    vals = ' '.join('%02x' % b for b in chunk)
    ascii_ = ''.join(chr(b) if 32<=b<127 else '.' for b in chunk)
    print('  +0x%03x (%3d): %s  %s' % (i, i, vals, ascii_))
