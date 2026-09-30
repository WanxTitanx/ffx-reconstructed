import struct

data = open('1175_bank00.fsb','rb').read()
print('File size: %d (0x%x)' % (len(data), len(data)))

print('=== FSB5 header ===')
print('magic: %r' % data[0:4])
print('version: %d' % struct.unpack_from('<I', data, 4)[0])
print('numSamples: %d' % struct.unpack_from('<I', data, 8)[0])
print('sampleHeaderSize: %d' % struct.unpack_from('<I', data, 0x0C)[0])
print('nameTableSize: %d' % struct.unpack_from('<I', data, 0x10)[0])
print('dataSize: %d (0x%x)' % (struct.unpack_from('<I', data, 0x14)[0], struct.unpack_from('<I', data, 0x14)[0]))
print('numDSPPresets: %d' % struct.unpack_from('<I', data, 0x18)[0])
print('numHeaderExtensions: %d' % struct.unpack_from('<I', data, 0x1C)[0])
print('numSampleExtensions: %d' % struct.unpack_from('<I', data, 0x20)[0])
print('numSampleInfoExtensions: %d' % struct.unpack_from('<I', data, 0x24)[0])
print('guid: %s' % data[0x28:0x38].hex())
print('hash: %s' % data[0x38:0x58].hex())

print()
print('=== Full dump ===')
for off in range(0, len(data), 16):
    chunk = data[off:off+16]
    vals = ' '.join('%02x' % b for b in chunk)
    ascii_ = ''.join(chr(b) if 32<=b<127 else '.' for b in chunk)
    print('%08x  %-47s  %s' % (off, vals, ascii_))
