// PhyreTextureReader.cs - standalone .dds.phyre parser
// See docs/reverse/FFX_PHYRE_TEXTURE_FORMAT_2026-08-19.md
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace PhyreTextureResearch{
public struct ClusterHeader{
  public uint Magic,HeaderSize,PackedNamespaceSize,PlatformID;
  public uint InstanceListCount,ArrayFixupSize,ArrayFixupCount;
  public uint PointerFixupSize,PointerFixupCount;
  public uint PointerArrayFixupSize,PointerArrayFixupCount,PointersInArraysCount;
  public uint UserFixupCount,UserFixupDataSize,TotalDataSize;
  public uint HeaderClassInstanceCount,HeaderClassChildCount,PhysicsEngineID;
  public uint IndexBufferSize,VertexBufferSize,MaxTextureBufferSize;
  // FIX 2026-09-15 (VALIDADOR-Restantes): MagicRYHP was 0x50594852 (an endianness
  // arithmetic typo inherited from the RE doc, which reads `"RYHP" (LE) = 0x50594852`).
  // Actual file bytes are 'R','Y','H','P' = 52 59 48 50, which as a little-endian
  // uint32 is 0x50485952 — proven by hexdump of ps3data menu_ch b_menu2.dds.phyre
  // and by BitConverter in the harness. With the old constant ReadHeader() rejected
  // EVERY real file. Doc erratum pending in docs/reverse (outside validator scope).
  public const uint Size=0x54,MagicRYHP=0x50485952;
}
public struct ILHeader{public uint ClassID,Count,Size,ObjSize,ArrSize,PIA,AFC,PFC,PAFC;}
public struct UserFixup{public uint TypeID,Size,Offset;}
public struct TexInfo{public string Asset,Format,Class;public uint W,H,Mips,MaxLvl,PDO,PDS;}
public class PhyreTextureReader{
  private byte[] _d;private ClusterHeader _h;private int _p;
  public ClusterHeader Header=>_h;
  public PhyreTextureReader(byte[] d){_d=d;}
  public PhyreTextureReader(string fp){_d=File.ReadAllBytes(fp);}
  private uint VLQ(){uint v=0;int s=0;while(true){byte r=_d[_p++];v|=(uint)(r&0x7f)<<s;s+=7;if((r&0x80)==0)break;}return v;}
  private uint U32(){uint v=BitConverter.ToUInt32(_d,_p);_p+=4;return v;}
  public bool ReadHeader(){
    if(_d.Length<(int)ClusterHeader.Size)return false;_p=0;
    _h.Magic=U32();_h.HeaderSize=U32();_h.PackedNamespaceSize=U32();
    _h.PlatformID=U32();_h.InstanceListCount=U32();
    _h.ArrayFixupSize=U32();_h.ArrayFixupCount=U32();
    _h.PointerFixupSize=U32();_h.PointerFixupCount=U32();
    _h.PointerArrayFixupSize=U32();_h.PointerArrayFixupCount=U32();
    _h.PointersInArraysCount=U32();_h.UserFixupCount=U32();
    _h.UserFixupDataSize=U32();_h.TotalDataSize=U32();
    _h.HeaderClassInstanceCount=U32();_h.HeaderClassChildCount=U32();
    _h.PhysicsEngineID=U32();
    _h.IndexBufferSize=U32();_h.VertexBufferSize=U32();_h.MaxTextureBufferSize=U32();
    return _h.Magic==ClusterHeader.MagicRYHP&&_h.HeaderSize==ClusterHeader.Size;}
  public ILHeader[] ReadILHeaders(){
    _p=(int)(_h.HeaderSize+_h.PackedNamespaceSize);
    var h=new ILHeader[_h.InstanceListCount];
    for(int i=0;i<_h.InstanceListCount;i++){
      h[i].ClassID=U32();h[i].Count=U32();h[i].Size=U32();
      h[i].ObjSize=U32();h[i].ArrSize=U32();h[i].PIA=U32();
      h[i].AFC=U32();h[i].PFC=U32();h[i].PAFC=U32();_p+=4;}
    return h;}
  private int ODS(){return(int)(_h.HeaderSize+_h.PackedNamespaceSize+_h.InstanceListCount*36);}
  private int ODE(){return ODS()+(int)_h.TotalDataSize;}
  public int PDO(){int p=ODE();p+=(int)_h.UserFixupDataSize+(int)_h.UserFixupCount*12;
    p+=(int)_h.HeaderClassInstanceCount*4+(int)_h.HeaderClassChildCount*16;
    p+=(int)_h.PointerArrayFixupSize+(int)_h.PointerFixupSize+(int)_h.ArrayFixupSize;return p;}
  public(byte[]data,UserFixup[]fx)ReadUserFixups(){
    int ds=ODE();byte[]data=new byte[_h.UserFixupDataSize];
    Array.Copy(_d,ds,data,0,(int)_h.UserFixupDataSize);
    int fs=ds+(int)_h.UserFixupDataSize;var fx=new UserFixup[_h.UserFixupCount];
    for(int i=0;i<_h.UserFixupCount;i++){int o2=fs+i*12;
      fx[i].TypeID=BitConverter.ToUInt32(_d,o2);fx[i].Size=BitConverter.ToUInt32(_d,o2+4);
      fx[i].Offset=BitConverter.ToUInt32(_d,o2+8);}return(data,fx);}
  public TexInfo ExtractTextureInfo(){
    var info=new TexInfo();
    if(!ReadHeader())return info;
    var ilh=ReadILHeaders();
    var(ud,ufx)=ReadUserFixups();
    foreach(var u in ufx){if(u.Offset+u.Size>ud.Length)continue;
      string s=Encoding.ASCII.GetString(ud,(int)u.Offset,(int)u.Size).TrimEnd((char)0);
      if(u.TypeID==8)info.Class=s;else if(u.TypeID==2)info.Format=s;}
    int il0=ilh.Length>0?(int)ilh[0].Size:0;
    int to=ODS()+il0;
    if(to+36<=_d.Length){
      info.W=BitConverter.ToUInt32(_d,to+28);info.H=BitConverter.ToUInt32(_d,to+32);
      info.Mips=BitConverter.ToUInt32(_d,to+12);info.MaxLvl=BitConverter.ToUInt32(_d,to+16);}
    info.PDO=(uint)PDO();info.PDS=(uint)(_d.Length-PDO());
    if(ilh.Length>0){int ar=ODS()+(int)ilh[0].ObjSize;
      if(ar<_d.Length){int e=Array.IndexOf(_d,(byte)0,ar);
        if(e>ar&&e<ar+ilh[0].ArrSize)
          info.Asset=Encoding.ASCII.GetString(_d,ar,e-ar);}}
    return info;}
  public static int DxtMipSz(uint w,uint h){return(int)(((w+3)/4)*((h+3)/4)*8);}
  public static int MipOff(uint w,uint h,uint lv){
    int o=0;uint mw=w,mh=h;
    for(uint i=0;i<lv;i++){o+=DxtMipSz(mw,mh);mw=Math.Max(mw/2,1);mh=Math.Max(mh/2,1);}return o;}
}
public static class Program{
  public static int Main(string[] args){
    if(args.Length<1){Console.Error.WriteLine("Usage: PhyreTextureReader <file>");return 1;}
    var r=new PhyreTextureReader(args[0]);
    var info=r.ExtractTextureInfo();
    Console.WriteLine("=== PhyreTextureReader ===");
    Console.WriteLine("Platform: 0x{0:X8}",r.Header.PlatformID);
    Console.WriteLine("Asset: {0}",info.Asset??"(none)");
    Console.WriteLine("Format: {0}",info.Format??"(unknown)");
    Console.WriteLine("Dims: {0}x{1}",info.W,info.H);
    Console.WriteLine("Mips: {0} maxLvl: {1}",info.Mips,info.MaxLvl);
    Console.WriteLine("PixelData @0x{0:X} size={1}",info.PDO,info.PDS);
    // FIX 2026-09-15 (VALIDADOR-Restantes): CS0103 — MipOff is a static member of
    // PhyreTextureReader; qualify it when called from Program. No behavior change.
    if(info.W>0&&info.H>0){int ex=PhyreTextureReader.MipOff(info.W,info.H,info.MaxLvl+1);
      Console.WriteLine("Expected chain: {0} match={1}",ex,ex==(int)info.PDS);}
    return 0;}}}
