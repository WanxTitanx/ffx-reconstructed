import sys
sys.path.insert(0,"/home/wanderson/Documents/ffx-editor-main/work")
import importlib.util
spec=importlib.util.spec_from_file_location("vbr", "/home/wanderson/Documents/ffx-editor-main/work/_vbf_reader.py")
# avoid re-running side effects: _vbf_reader.py runs parse on import. Instead re-open here.
import struct, hashlib, zlib
def u32(b,o): return struct.unpack_from("<I", b, o)[0]
def u64(b,o): return struct.unpack_from("<Q", b, o)[0]
def u16(b,o): return struct.unpack_from("<H", b, o)[0]
VBF="/mnt/nvme-samsung/SteamLibrary/steamapps/common/FINAL FANTASY FFX&FFX-2 HD Remaster/data/FFX_Data.vbf"
fs=open(VBF,"rb")
assert u32(fs.read(4),0)==1264144979
fs.read(4); numfiles=u64(fs.read(8),0)
md5s=[fs.read(16).hex().upper() for _ in range(numfiles)]
bls=[]; osz=[]; so=[]
for i in range(numfiles):
    b=u32(fs.read(4),0); cnt=u32(fs.read(4),0); s=u64(fs.read(8),0); o=u64(fs.read(8),0); no=u64(fs.read(8),0)
    bls.append(b); osz.append(s); so.append(o)
sts=u32(fs.read(4),0)
st=fs.read(sts-4).decode("utf-8","replace")
names=st.strip("\x00").split("\x00")
bc=0
for s in osz: bc += s//65536 + (1 if s%65536 else 0)
block=[u16(fs.read(2),0) for _ in range(bc)]
fs.close()
print("parsed on disk: names=",len(names),"blockCount=",bc)
target="ffx_ps2/ffx/master/jppc/map/bika/bika03/bin/mapout.vpa"
low=target.lower()
h=hashlib.md5(low.encode("utf-8")).hexdigest().upper()
i=md5s.index(h) if h in md5s else -1
print("index=",i)
if i>=0:
    s=osz[i]; start=so[i]; blstart=bls[i]
    bcnt=s//65536 + (1 if s%65536 else 0); rem=s%65536 or 65536
    fs=open(VBF,"rb"); fs.seek(start)
    with open("/mnt/nvme-samsung/ffx-task-artifacts/glm-parser-docs-exec-8c41f7/_bika03_mapout_extracted.vpa","wb") as o:
        for bi in range(bcnt):
            bl=block[blstart+bi]
            if bl==0: bl=65536
            cb=fs.read(bl)
            decsz=65536 if bi!=bcnt-1 else rem
            if bl==65536: o.write(cb[:decsz])
            else:
                d=zlib.decompressobj(-15); outb=d.decompress(cb[2:], decsz); o.write(outb[:decsz])
    fs.close()
    import os
    print("extracted bytes=", os.path.getsize("/mnt/nvme-samsung/ffx-task-artifacts/glm-parser-docs-exec-8c41f7/_bika03_mapout_extracted.vpa"))
    # compare to corpus copy
    corp="/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc/map/bika/bika03/bin/mapout.vpa"
    a=open("/mnt/nvme-samsung/ffx-task-artifacts/glm-parser-docs-exec-8c41f7/_bika03_mapout_extracted.vpa","rb").read()
    b=open(corp,"rb").read()
    print("corpus size=", len(b))
    print("byte-identical=", a==b, " md5same=", hashlib.md5(a).hexdigest()==hashlib.md5(b).hexdigest())
    print("md5=", hashlib.md5(a).hexdigest())