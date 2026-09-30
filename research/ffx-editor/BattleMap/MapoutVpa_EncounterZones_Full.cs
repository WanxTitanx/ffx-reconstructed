// MapoutVpa_EncounterZones_Full.cs
// RESEARCH ONLY - standalone reference parser for mapout.vpa encounter zones
// Created: 2026-08-19 (Jarvis, RE lane)
// Updated: 2026-08-19 - Family 4 (YNDT guide map) decoded and integrated
// FIX 2026-09-15 (Jarvis-STRUCT validator): added using System.IO (File.ReadAllBytes)
// and explicit (uint)/(ushort) casts on R32/U16 results assigned into TriRec fields —
// the helpers return int, so the file never compiled standalone as committed. Casts are
// bit-preserving (U16 max 0xFFFF fits ushort; R32 wraps to the same 32-bit pattern).

using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace MapoutVpaFull
{
    public enum MapoutFamily { Unknown, S16Ring, Float32Transform, IndirectTriangle, YNDT }
    public enum MapoutStatus { Ok, InvalidMagic, Stub, NoMeta, NoDispatch, NoZones, Unsupported }

    public record Vert(float X, float Z);
    public record Poly(List<Vert> Vs);
    public record TriRec(Vert V0, Vert V1, Vert V2, uint R0, uint R1, uint R2, ushort I0, ushort I1, ushort I2);
    public record Result(MapoutStatus S, MapoutFamily F, int Sz, List<Poly> Rings, List<TriRec>? Tris, string N);

    public static class Parser
    {
        const int HSZ=0x80, MF=0x38, GF=0x18, YF=0x3C;
        const ushort SA=0x0080; const short SB=-2;
        const float SC=1f/256f;
        static readonly HashSet<int> ZT=new(){0x19,0x71,4};

        public static Result Go(string p)=>Go(File.ReadAllBytes(p));

        public static Result Go(byte[] b)
        {
            if(b.Length<4||Encoding.ASCII.GetString(b,0,4)!="MAP1")
                return Fail(MapoutStatus.InvalidMagic,MapoutFamily.Unknown,b.Length,"bad magic");
            if(b.Length<=HSZ) return Fail(MapoutStatus.Stub,CF(b),b.Length,"stub");
            int m=R32(b,MF),g=R32(b,GF); var fm=CF(b);
            if(m<=0||m>=b.Length||g<=0||g>=b.Length)
                return Fail(MapoutStatus.NoMeta,fm,b.Length,"no meta");
            int dr=R32(b,m+0x1C),da=m+dr;
            if(dr<=0||da+8>b.Length) return Fail(MapoutStatus.NoDispatch,fm,b.Length,"no dispatch");
            var rows=RR(b,da); var zr=rows.FindAll(r=>ZT.Contains(r.T));
            if(fm==MapoutFamily.S16Ring) return D16(b,g,zr,fm);
            if(fm==MapoutFamily.IndirectTriangle) return DT(b,g,zr,fm);
            if(fm==MapoutFamily.YNDT) return DY(b);
            string msg=fm==MapoutFamily.Float32Transform?"transform records, rings indirect":"YNDT";
            return Fail(MapoutStatus.Unsupported,fm,b.Length,msg);
        }

        // Family 4: YNDT Guide Map (section at +0x3C)
        // Container: +0x00 "YNDT", +0x10 "YNGM" header, +0x58 tri records (20B each),
        // then vertex pool (6B each: s16 X, s16 Y=0, s16 Z), then 6x32B transform matrices, +End "YNED".
        static Result DY(byte[] b)
        {
            int y=R32(b,YF);
            if(y<=0||y+0x58>b.Length||Encoding.ASCII.GetString(b,y,4)!="YNDT")
                return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"no YNDT at +0x3C");
            // YNGM header at section+0x10
            int h=y+0x10;
            if(h+0x48>b.Length||Encoding.ASCII.GetString(b,h,4)!="YNGM")
                return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"no YNGM header");
            int triCount=U16(b,y+0x38), vertCount=U16(b,y+0x3A);
            if(triCount<=0||triCount>4096||vertCount<=0||vertCount>4096)
                return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"bad counts t="+triCount+" v="+vertCount);
            // Triangle records at section+0x58, 20 bytes each
            int trBase=y+0x58;
            if(trBase+triCount*20>b.Length)
                return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"tri pool OOB");
            // Vertex pool immediately after tri records + padding
            int vp=trBase+triCount*20;
            // skip alignment padding (zeros)
            while(vp+6<=b.Length&&b[vp]==0&&b[vp+1]==0&&b[vp+2]==0&&b[vp+3]==0&&b[vp+4]==0&&b[vp+5]==0)
                vp+=6;
            if(vp+vertCount*6>b.Length)
                return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"vertex pool OOB");
            var tr=new List<TriRec>();
            for(int i=0;i<triCount;i++)
            {
                int c=trBase+i*20;
                uint r0=(uint)R32(b,c),r1=(uint)R32(b,c+4),r2=(uint)R32(b,c+8);
                ushort iA=(ushort)U16(b,c+12),iB=(ushort)U16(b,c+14),iC=(ushort)U16(b,c+16);
                if(iA>=vertCount||iB>=vertCount||iC>=vertCount) continue;
                tr.Add(new TriRec(V(b,vp,iA),V(b,vp,iB),V(b,vp,iC),r0,r1,r2,iA,iB,iC));
            }
            if(tr.Count==0) return Fail(MapoutStatus.NoZones,MapoutFamily.YNDT,b.Length,"no valid tris");
            return new(MapoutStatus.Ok,MapoutFamily.YNDT,b.Length,new(),tr,
                tr.Count+" tris / "+vertCount+" verts (YNDT guide)");
        }

        // Vertex from pool: 6-byte stride s16 X, s16 Y(0), s16 Z
        static Vert V(byte[] b,int vp,int idx)
        {
            int c=vp+idx*6;
            return new Vert(I16(b,c),I16(b,c+4));
        }

        static Result D16(byte[] b,int g,List<(int K,int T,int O)> z,MapoutFamily fm)
        {
            var rings=new List<Poly>();
            foreach(var(_,_,o) in z){int a=g+o; if(a>=0&&a<b.Length) rings.AddRange(ER(b,a));}
            return new(rings.Count>0?MapoutStatus.Ok:MapoutStatus.NoZones,fm,b.Length,rings,null,rings.Count+" rings");
        }

        static List<Poly> ER(byte[] b,int s)
        {
            var res=new List<Poly>(); int c=s, e=Math.Min(s+8192,b.Length-4);
            while(c+12<=e&&res.Count<32){var v=new List<Vert>();
                while(c+4<=b.Length){short a=I16(b,c),bb=I16(b,c+2);
                    if(a==SA&&bb==SB){c+=4;break;}
                    v.Add(new Vert(a*SC,bb*SC)); c+=4; if(v.Count>64)break;}
                if(v.Count>=3&&v.Count<=32) res.Add(new Poly(v));}
            return res;
        }

        static Result DT(byte[] b,int g,List<(int K,int T,int O)> z,MapoutFamily fm)
        {
            var tr=new List<TriRec>();
            foreach(var(_,_,o) in z){int a=g+o; if(a<0||a>=b.Length)continue;
                int cnt=U16(b,a),c=a+4,lim=Math.Min(c+cnt*32,b.Length-32);
                for(int i=0;i<cnt&&c<=lim;i++,c+=32)
                    tr.Add(new TriRec(new(I16(b,c),I16(b,c+2)),new(I16(b,c+4),I16(b,c+6)),
                        new(I16(b,c+8),I16(b,c+10)),(uint)R32(b,c+12),(uint)R32(b,c+16),(uint)R32(b,c+20),
                        (ushort)U16(b,c+24),(ushort)U16(b,c+26),(ushort)U16(b,c+28)));}
            return new(tr.Count>0?MapoutStatus.Ok:MapoutStatus.NoZones,fm,b.Length,new(),tr,tr.Count+" tris");
        }

        static List<(int K,int T,int O)> RR(byte[] b,int s){var r=new List<(int,int,int)>();
            for(int p=s,i=0;i<256&&p+8<=b.Length;i++){int k=U16(b,p),t=U16(b,p+2),o=R32(b,p+4);
                if(k==0&&t==0&&o==0)break; r.Add((k,t,o));
                if(t>=0x20&&t<=0x40&&k>=0x20)break; p+=8;} return r; }

        static MapoutFamily CF(byte[] b){if(b.Length<HSZ+4)return MapoutFamily.Unknown;
            string h=Encoding.ASCII.GetString(b,HSZ,4);
            if(h.StartsWith("YN"))return MapoutFamily.YNDT; return MapoutFamily.S16Ring; }
        static Result Fail(MapoutStatus s,MapoutFamily f,int sz,string n)
            =>new(s,f,sz,new(),null,n);
        static int U16(byte[] b,int o)=>b[o]|(b[o+1]<<8);
        static short I16(byte[] b,int o)=>(short)(b[o]|(b[o+1]<<8));
        static int R32(byte[] b,int o)=>b[o]|(b[o+1]<<8)|(b[o+2]<<16)|(b[o+3]<<24);
    }
}
