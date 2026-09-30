<#
  Export-Ps3Textures.ps1 — batch .dds.phyre -> PNG (read-only). Handles ARGB8 / DXT1 / DXT5.
  Usage: .\Export-Ps3Textures.ps1 -InDir "D:\...\ps3data\chr\pc" -OutDir "...\out" [-MaxFiles N] [-MaxDim 512]
  Mirrors the source folder tree under -OutDir. Never writes into the source.
#>
param([Parameter(Mandatory)][string]$InDir,[Parameter(Mandatory)][string]$OutDir,[int]$MaxFiles=0,[int]$MaxDim=0,[switch]$IncludeAnim)
Add-Type -AssemblyName System.Drawing
Add-Type @"
public static class TexBC{
 static void Col(ushort c0,ushort c1,int[] r,int[] g,int[] b,bool dxt1){
  r[0]=((c0>>11)&31)*255/31;g[0]=((c0>>5)&63)*255/63;b[0]=(c0&31)*255/31;
  r[1]=((c1>>11)&31)*255/31;g[1]=((c1>>5)&63)*255/63;b[1]=(c1&31)*255/31;
  if(!dxt1||c0>c1){r[2]=(2*r[0]+r[1])/3;g[2]=(2*g[0]+g[1])/3;b[2]=(2*b[0]+b[1])/3;r[3]=(r[0]+2*r[1])/3;g[3]=(g[0]+2*g[1])/3;b[3]=(b[0]+2*b[1])/3;}
  else{r[2]=(r[0]+r[1])/2;g[2]=(g[0]+g[1])/2;b[2]=(b[0]+b[1])/2;r[3]=g[3]=b[3]=0;}
 }
 public static byte[] D5(byte[] d,int off,int w,int h){byte[] o=new byte[w*h*4];int bx=(w+3)/4,by=(h+3)/4,p=off;int[] r=new int[4],g=new int[4],b=new int[4];
  for(int Y=0;Y<by;Y++)for(int X=0;X<bx;X++){byte a0=d[p],a1=d[p+1];ulong ab=0;for(int i=0;i<6;i++)ab|=(ulong)d[p+2+i]<<(8*i);byte[] al=new byte[8];al[0]=a0;al[1]=a1;
   if(a0>a1){for(int i=1;i<7;i++)al[i+1]=(byte)(((7-i)*a0+i*a1)/7);}else{for(int i=1;i<5;i++)al[i+1]=(byte)(((5-i)*a0+i*a1)/5);al[6]=0;al[7]=255;}
   Col((ushort)(d[p+8]|(d[p+9]<<8)),(ushort)(d[p+10]|(d[p+11]<<8)),r,g,b,false);uint cb=(uint)(d[p+12]|(d[p+13]<<8)|(d[p+14]<<16)|(d[p+15]<<24));
   for(int py=0;py<4;py++)for(int px=0;px<4;px++){int x=X*4+px,y=Y*4+py;if(x>=w||y>=h)continue;int ci=(int)((cb>>(2*(py*4+px)))&3),ai=(int)((ab>>(3*(py*4+px)))&7),q=(y*w+x)*4;o[q]=(byte)b[ci];o[q+1]=(byte)g[ci];o[q+2]=(byte)r[ci];o[q+3]=al[ai];}p+=16;}return o;}
 public static byte[] D1(byte[] d,int off,int w,int h){byte[] o=new byte[w*h*4];int bx=(w+3)/4,by=(h+3)/4,p=off;int[] r=new int[4],g=new int[4],b=new int[4];
  for(int Y=0;Y<by;Y++)for(int X=0;X<bx;X++){ushort c0=(ushort)(d[p]|(d[p+1]<<8)),c1=(ushort)(d[p+2]|(d[p+3]<<8));Col(c0,c1,r,g,b,true);uint cb=(uint)(d[p+4]|(d[p+5]<<8)|(d[p+6]<<16)|(d[p+7]<<24));bool dxt1=c0<=c1;
   for(int py=0;py<4;py++)for(int px=0;px<4;px++){int x=X*4+px,y=Y*4+py;if(x>=w||y>=h)continue;int ci=(int)((cb>>(2*(py*4+px)))&3),q=(y*w+x)*4;o[q]=(byte)b[ci];o[q+1]=(byte)g[ci];o[q+2]=(byte)r[ci];o[q+3]=(byte)((dxt1&&ci==3)?0:255);}p+=8;}return o;}
 public static byte[] D3(byte[] d,int off,int w,int h){byte[] o=new byte[w*h*4];int bx=(w+3)/4,by=(h+3)/4,p=off;int[] r=new int[4],g=new int[4],b=new int[4];
  for(int Y=0;Y<by;Y++)for(int X=0;X<bx;X++){ulong ab=0;for(int i=0;i<8;i++)ab|=(ulong)d[p+i]<<(8*i);
   Col((ushort)(d[p+8]|(d[p+9]<<8)),(ushort)(d[p+10]|(d[p+11]<<8)),r,g,b,false);uint cb=(uint)(d[p+12]|(d[p+13]<<8)|(d[p+14]<<16)|(d[p+15]<<24));
   for(int py=0;py<4;py++)for(int px=0;px<4;px++){int x=X*4+px,y=Y*4+py;if(x>=w||y>=h)continue;int ci=(int)((cb>>(2*(py*4+px)))&3),an=(int)((ab>>(4*(py*4+px)))&0xF),q=(y*w+x)*4;o[q]=(byte)b[ci];o[q+1]=(byte)g[ci];o[q+2]=(byte)r[ci];o[q+3]=(byte)(an*255/15);}p+=16;}return o;}
 public static byte[] L8(byte[] d,int off,int w,int h){byte[] o=new byte[w*h*4];for(int i=0;i<w*h;i++){byte v=d[off+i];o[i*4]=v;o[i*4+1]=v;o[i*4+2]=v;o[i*4+3]=255;}return o;}}
"@ -ReferencedAssemblies System.Drawing
function U32($a,$o){[BitConverter]::ToUInt32($a,$o)}
function Decode($path){
  $b=[IO.File]::ReadAllBytes($path);$s=[Text.Encoding]::Latin1.GetString($b);$pos=0;$pidx=-1;$fmt=$null
  while(($i=$s.IndexOf('PTexture2D',$pos)) -ge 0){$o=$i+10;while($o -lt $b.Length -and $b[$o] -eq 0){$o++};$t='';while($o -lt $b.Length -and $b[$o] -ge 32 -and $b[$o] -lt 127){$t+=[char]$b[$o];$o++};if($t -match '^(ARGB8|DXT[135]|L8)$'){$pidx=$i;$fmt=$t;break};$pos=$i+1}
  if($pidx -lt 0){return $null}
  $w=U32 $b ($pidx-88);$h=U32 $b ($pidx-84);if($w -lt 1 -or $w -gt 8192 -or $h -lt 1 -or $h -gt 8192){return $null}
  $bs=$pidx+11+$fmt.Length+38
  switch($fmt){'ARGB8'{$bgra=$b[$bs..($bs+$w*$h*4-1)]}'DXT5'{$bgra=[TexBC]::D5($b,$bs,$w,$h)}'DXT3'{$bgra=[TexBC]::D3($b,$bs,$w,$h)}'DXT1'{$bgra=[TexBC]::D1($b,$bs,$w,$h)}'L8'{$bgra=[TexBC]::L8($b,$bs,$w,$h)}}
  [pscustomobject]@{w=$w;h=$h;fmt=$fmt;bgra=$bgra}
}
$files=Get-ChildItem -LiteralPath $InDir -Recurse -File -Filter *.dds.phyre
if(-not $IncludeAnim){$files=$files|Where-Object{$_.Name -notlike '*anim_n*'}}
if($MaxFiles -gt 0){$files=$files|Select-Object -First $MaxFiles}
$ok=0;$fail=0;$total=$files.Count;$sw=[Diagnostics.Stopwatch]::StartNew()
if(-not(Test-Path $OutDir)){New-Item -ItemType Directory -Force $OutDir|Out-Null}
Set-Content "$OutDir\_progress.log" "start total=$total"
foreach($f in $files){
  try{
   $d=Decode $f.FullName; if(-not $d){$fail++;continue}
   $bmp=New-Object Drawing.Bitmap($d.w,$d.h,[Drawing.Imaging.PixelFormat]::Format32bppArgb)
   $bd=$bmp.LockBits((New-Object Drawing.Rectangle(0,0,$d.w,$d.h)),[Drawing.Imaging.ImageLockMode]::WriteOnly,$bmp.PixelFormat)
   [Runtime.InteropServices.Marshal]::Copy([byte[]]$d.bgra,0,$bd.Scan0,$d.bgra.Length);$bmp.UnlockBits($bd)
   $rel=$f.FullName.Substring($InDir.Length).TrimStart('\') -replace '\.dds\.phyre$','.png'
   $dest=Join-Path $OutDir $rel; $dd=Split-Path $dest -Parent; if(-not(Test-Path $dd)){New-Item -ItemType Directory -Force $dd|Out-Null}
   if($MaxDim -gt 0 -and ($d.w -gt $MaxDim -or $d.h -gt $MaxDim)){
     $sc=[math]::Min($MaxDim/$d.w,$MaxDim/$d.h);$nw=[int]($d.w*$sc);$nh=[int]($d.h*$sc)
     $sm=New-Object Drawing.Bitmap($nw,$nh);$gg=[Drawing.Graphics]::FromImage($sm);$gg.DrawImage($bmp,0,0,$nw,$nh);$gg.Dispose();$sm.Save($dest,[Drawing.Imaging.ImageFormat]::Png);$sm.Dispose()
   } else { $bmp.Save($dest,[Drawing.Imaging.ImageFormat]::Png) }
   $bmp.Dispose();$ok++
  }catch{$fail++}
  if(($ok+$fail)%1000 -eq 0){ Add-Content "$OutDir\_progress.log" ("{0}/{1} ok={2} fail={3} {4}s" -f ($ok+$fail),$total,$ok,$fail,[int]$sw.Elapsed.TotalSeconds) }
}
$sw.Stop()
Add-Content "$OutDir\_progress.log" ("DONE {0}/{1} ok={2} fail={3} {4}s" -f ($ok+$fail),$total,$ok,$fail,[int]$sw.Elapsed.TotalSeconds)
"exported $ok PNG, $fail skipped, in $([int]$sw.Elapsed.TotalSeconds)s -> $OutDir"
