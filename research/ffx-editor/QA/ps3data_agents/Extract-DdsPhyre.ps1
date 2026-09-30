<#
  Extract-DdsPhyre.ps1  —  READ-ONLY research extractor for PhyreEngine .dds.phyre textures.
  Extracts mip0 (full-resolution surface) to a standard .dds. NEVER writes into the source tree.

  Proven container model (see PS3DATA_DDS_PHYRE_DECODE doc):
    file = [ PhyreEngine RYHPT header (~2.7 KB) ] + [ texture buffer: mip0, mip1, ... (largest first) ]
    The PTexture2D instance string sits at the end of the header. Anchor:
      bufferStart = indexOf("PTexture2D") + 11 + len(formatToken) + 38   [proved on icon/worldmap/battle]
      formatToken = ASCII run right after "PTexture2D\0"  (ARGB8 / DXT5 / DXT1 / DXT3 ...)
      ARGB8 dims  = U32@(bufferStart-142)=width, U32@(bufferStart-138)=height  [proved, single-surface]
    U32@80 = m_maxTextureBufferSize = mip0 byte size (largest mip).
    mip0 occupies the first mip0Size bytes of the buffer; that is what we emit.

  Single-surface ARGB8 (e.g. menu_us\icon) reconstructs BYTE-EXACT vs the shipped .dds [proved].
  For compressed/mipped textures pass -Width/-Height (e.g. from the texlist.txt filename WxH).
#>
param(
  [Parameter(Mandatory)][string]$InPath,
  [string]$OutDir = "C:\Users\wande\Documents\ffx-editor-main\work\ps3data_extract",
  [int]$Width = 0,
  [int]$Height = 0,
  [switch]$Quiet
)
function Get-U32([byte[]]$a,[int]$o){ [BitConverter]::ToUInt32($a,$o) }

function Find-Ascii([byte[]]$buf,[string]$needle,[int]$start,[int]$limit){
  $nb=[Text.Encoding]::ASCII.GetBytes($needle); $end=[math]::Min($buf.Length-$nb.Length,$limit)
  for($i=$start;$i -le $end;$i++){ $ok=$true; for($k=0;$k -lt $nb.Length;$k++){ if($buf[$i+$k] -ne $nb[$k]){$ok=$false;break} }; if($ok){return $i} }
  return -1
}
function Read-Token([byte[]]$buf,[int]$start){  # skip nulls then read printable run
  $o=$start; while($o -lt $buf.Length -and $buf[$o] -eq 0){$o++}
  $s=''; while($o -lt $buf.Length -and $buf[$o] -ge 32 -and $buf[$o] -lt 127){ $s+=[char]$buf[$o]; $o++ }
  return $s
}
function Get-Mip0Size([int]$w,[int]$h,[string]$fmt){
  switch -Regex ($fmt){
    '^ARGB8$' { return $w*$h*4 }
    '^DXT1$'  { return [int]([math]::Ceiling($w/4.0)*[math]::Ceiling($h/4.0)*8) }
    '^DXT[35]$'{ return [int]([math]::Ceiling($w/4.0)*[math]::Ceiling($h/4.0)*16) }
    default   { throw "Unknown format '$fmt'" }
  }
}
function New-DdsHeader([int]$w,[int]$h,[string]$fmt){
  $hdr=New-Object byte[] 128
  [Text.Encoding]::ASCII.GetBytes('DDS ').CopyTo($hdr,0)
  function S($off,$val){ [BitConverter]::GetBytes([uint32]([int64]$val -band 0xFFFFFFFFL)).CopyTo($hdr,$off) }
  S 4 124; S 76 32; S 12 $h; S 16 $w; S 24 1; S 28 1; S 108 0x1000
  switch -Regex ($fmt){
    '^ARGB8$' { S 8 0x100F; S 20 ($w*4); S 80 0x41; S 88 32; S 92 0x00FF0000; S 96 0x0000FF00; S 100 0x000000FF; S 104 0xFF000000 }
    '^DXT[1-5]$' { S 8 0x80007; S 20 (Get-Mip0Size $w $h $fmt); S 80 0x4; [Text.Encoding]::ASCII.GetBytes($fmt).CopyTo($hdr,84) }
    default { throw "Unsupported format '$fmt'" }
  }
  return ,$hdr
}

# ---- main ----
$buf=[IO.File]::ReadAllBytes($InPath)
if(($buf.Length -lt 96) -or ((-join ($buf[0..4]|%{[char]$_})) -ne 'RYHPT')){ throw "Not a RYHPT/.phyre file" }
$hdrScan=[math]::Min($buf.Length,16384)
# The class-descriptor table also contains "PTexture2D[Base|D3D11]"; the real instance is the
# occurrence whose following token is an actual pixel format. Pick that one.
$pidx=-1; $fmt=$null; $from=0
while($true){
  $hit=Find-Ascii $buf 'PTexture2D' $from $hdrScan
  if($hit -lt 0){ break }
  $tok=Read-Token $buf ($hit+10)
  if($tok -match '^(ARGB8|DXT[1235]|A8|L8|A8L8|R8G8B8|R8G8B8A8|BC[1-7])$'){ $pidx=$hit; $fmt=$tok; break }
  $from=$hit+1
}
if($pidx -lt 0){ throw "No PTexture2D instance with a known format token (atlas/other class?) [blocked]" }
$bufferStart = $pidx + 11 + $fmt.Length + 38

# Unified dims rule (all formats): width=U32@(pidx-88), height=U32@(pidx-84). Self-validated 17/17.
if($Width -gt 0 -and $Height -gt 0){ $w=$Width; $h=$Height; $dimSrc='param' }
else {
  $w=Get-U32 $buf ($pidx-88); $h=Get-U32 $buf ($pidx-84); $dimSrc='header'
  if($w -lt 1 -or $w -gt 8192 -or $h -lt 1 -or $h -gt 8192){ throw "Header dims implausible ($w x $h) [blocked] — pass -Width/-Height" }
}

$mip0=Get-Mip0Size $w $h $fmt
if($bufferStart -lt 0 -or ($bufferStart+$mip0) -gt $buf.Length){ throw "Computed mip0 region out of range (W=$w H=$h fmt=$fmt bufStart=$bufferStart mip0=$mip0 len=$($buf.Length))" }
$mippedTotal = $buf.Length - $bufferStart
$isMipped = $mippedTotal -gt ($mip0 + 16)

$ddsHeader=New-DdsHeader $w $h $fmt
$payload=New-Object byte[] $mip0
[Array]::Copy($buf,$bufferStart,$payload,0,$mip0)
if(-not (Test-Path -LiteralPath $OutDir)){ New-Item -ItemType Directory -Force -Path $OutDir|Out-Null }
$outPath=Join-Path $OutDir ([IO.Path]::GetFileNameWithoutExtension($InPath)+".extracted.dds")
$fs=[IO.File]::Create($outPath); try{ $fs.Write($ddsHeader,0,128); $fs.Write($payload,0,$mip0) } finally{ $fs.Dispose() }

$res=[PSCustomObject]@{ Input=([IO.Path]::GetFileName($InPath)); Output=$outPath; Format=$fmt; Width=$w; Height=$h
  DimSource=$dimSrc; BufferStart=$bufferStart; Mip0Bytes=$mip0; Mipped=$isMipped; OutSize=(Get-Item $outPath).Length }
if(-not $Quiet){ $res|Format-List|Out-String|Write-Host }
return $res
