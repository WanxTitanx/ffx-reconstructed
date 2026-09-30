import struct
files = [
    ('azit00', '/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/azit/azit00/bin/mapout.vpa'),
    ('azit03', '/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/azit/azit03/bin/mapout.vpa'),
    ('azit04', '/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/azit/azit04/bin/mapout.vpa'),
    ('azit05', '/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/azit/azit05/bin/mapout.vpa'),
]
for name, path in files:
    b = open(path,'rb').read()
    s3c = struct.unpack_from('<I', b, 0x3C)[0]
    sec = b[s3c:]
    yn = sec.find(b'YNGM')
    gm = sec[yn:]
    hdr = struct.unpack_from('<6I6H', gm, 0)
    print(name, 'hdr[1]=0x%X hdr[4]=%d hdr[8]=0x%X hdr[9]=0x%X hdr[10]=%d hdr[11]=%d hdr[16]=%d hdr[17]=%d' % (hdr[1], hdr[4], hdr[8], hdr[9], hdr[10], hdr[11], hdr[16], hdr[17]))
    cnt = 0
    o = yn + 0x48
    while o+20<=len(sec) and struct.unpack_from('<I',sec,o)[0]==0x80FFFFFF:
        cnt+=1; o+=20
    ed = sec.find(b'YNED')
    print('  tri=%d YNED=0x%X' % (cnt, ed))
