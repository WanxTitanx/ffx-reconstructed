import struct, hashlib, zlib, os
def u32(b,o): return struct.unpack_from("<I",b,o)[0]
def u64(b,o): return struct.unpack_from("<Q",b,o)[0]
def u16(b,o): return struct.unpack_from("<H",b,o)[0]
VBF=r"D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\data\FFX_Data.vbf"
fs=open(VBF,"rb")
assert u32(fs.read(4),0)==1264144979
fs.read(4); nf=u64(fs.read(8),0)
md5s=[fs.read(16).hex().upper() for _ in range(nf)]
bls=[];osz=[];so=[]
for i in range(nf):
    b=u32(fs.read(4),0); fs.read(4); s=u64(fs.read(8),0); o=u64(fs.read(8),0); fs.read(8); bls.append(b);osz.append(s);so.append(o)
sts=u32(fs.read(4),0); st=fs.read(sts-4).decode("utf-8","replace"); names=st.strip("\x00").split("\x00")
bc=0
for s in osz: bc+=s//65536+(1 if s%65536 else 0)
blk=[u16(fs.read(2),0) for _ in range(bc)]
fs.close()
def extract(path,out):
    low=path.lower(); h=hashlib.md5(low.encode("utf-8")).hexdigest().upper()
    i=md5s.index(h) if h in md5s else -1
    if i<0: return False
    s=osz[i]; start=so[i]; bls2=bls[i]; bc2=s//65536+(1 if s%65536 else 0); rem=s%65536 or 65536
    fs=open(VBF,"rb"); fs.seek(start)
    with open(out,"wb") as o:
        for bi in range(bc2):
            bl=blk[bls2+bi]
            if bl==0: bl=65536
            cb=fs.read(bl); decsz=65536 if bi!=bc2-1 else rem
            if bl==65536: o.write(cb[:decsz])
            else:
                d=zlib.decompressobj(-15); ob=d.decompress(cb[2:],decsz); o.write(ob[:decsz])
    fs.close(); return True
p="ffx_data/gamedata/ps3data/map/bika/bika03/bika03.ahwin32"
out=r"C:\Users\wande\Documents\ffx-editor-main\work\_bika03.ahwin32"
ok=extract(p,out)
print("extracted=",ok)
if ok:
    b=open(out,"rb").read()
    print("size=",len(b),"magic=",b[:8])
    print("first64:", b[:64].hex(" "))
    # search strings
    for sig in [b"encount",b"encnt",b"zone",b"spawn",b"btl",b"ENCOUNTER",b"mapout",b"trigger"]:
        idxs=[]; start=0
        while True:
            j=b.find(sig,start)
            if j<0: break
            idxs.append(j); start=j+1
            if len(idxs)>4: break
        if idxs: print("  sig",repr(sig),"at",[hex(x) for x in idxs])