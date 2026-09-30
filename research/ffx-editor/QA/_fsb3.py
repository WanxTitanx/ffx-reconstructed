import struct

data = open('2031_bank00.fsb','rb').read()
print('=== 2031_bank00.fsb first 0x100 bytes ===')
for off in range(0, 0x100, 16):
    chunk = data[off:off+16]
    vals = ' '.join('%02x' % b for b in chunk)
    ascii_ = ''.join(chr(b) if 32<=b<127 else '.' for b in chunk)
    print('%04x  %-47s  %s' % (off, vals, ascii_))

print()
print('=== Header fields ===')
print('numSamples: %d' % struct.unpack_from('<I', data, 8)[0])
print('sampleHeaderSize: %d' % struct.unpack_from('<I', data, 0x0C)[0])
print('nameTableSize: %d' % struct.unpack_from('<I', data, 0x10)[0])
print('dataSize: %d (0x%x)' % (struct.unpack_from('<I', data, 0x14)[0], struct.unpack_from('<I', data, 0x14)[0]))

# Try header=60: sample headers at 0x3C
print()
print('=== Sample headers (assuming header=60, sampleHeaderSize=32) ===')
sh_start = 0x3C
for i in range(4):
    o = sh_start + i*32
    vals = [struct.unpack_from('<I', data, o+j)[0] for j in range(0, 32, 4)]
    print('  sample[%d] @0x%04x: %s' % (i, o, ' '.join('0x%08x' % v for v in vals)))
