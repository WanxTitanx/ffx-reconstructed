import struct

# Compare with a slightly bigger FSB: 2031_bank00.fsb (14720 bytes)
import shutil
src = r'D:\FFX Extracted\FFX\ffx_data\gamedata\ps3data\sound_pc\sfx\us\2031_bank00.fsb'
shutil.copy(src, '2031_bank00.fsb')
data = open('2031_bank00.fsb','rb').read()
print('File size: %d (0x%x)' % (len(data), len(data)))
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

# Try to find where name table starts by looking for the bank name string
# The bank name is likely "2031_bank00" or similar
import re
for m in re.finditer(rb'[ -~]{4,}', data[:0x200]):
    print('string @0x%04x: %r' % (m.start(), m.group()))
