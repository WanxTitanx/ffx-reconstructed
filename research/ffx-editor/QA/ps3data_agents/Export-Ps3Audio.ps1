<#
  Export-Ps3Audio.ps1 — batch FSB5 -> WAV via vgmstream-cli (read-only on source).
  Extracts ALL subsongs of every .fsb under -InDir, mirroring the tree under -OutDir,
  one folder per bank, files named "<subsong>_<streamname>.wav".
  Usage: .\Export-Ps3Audio.ps1 -InDir "D:\...\sound_pc" -OutDir "D:\FFX Mods\ps3data_audio_wav" -Cli "D:\FFX Mods\tools\vgmstream\vgmstream-cli.exe"
#>
param(
  [Parameter(Mandatory)][string]$InDir,
  [Parameter(Mandatory)][string]$OutDir,
  [string]$Cli = "D:\FFX Mods\tools\vgmstream\vgmstream-cli.exe"
)
$fsb = Get-ChildItem -LiteralPath $InDir -Recurse -File -Filter *.fsb
if(-not (Test-Path $OutDir)){ New-Item -ItemType Directory -Force $OutDir | Out-Null }
$log = "$OutDir\_audio_progress.log"
Set-Content $log "start banks=$($fsb.Count)"
$i=0; $sw=[Diagnostics.Stopwatch]::StartNew()
foreach($f in $fsb){
  $rel = $f.FullName.Substring($InDir.Length).TrimStart('\') -replace '\.fsb$',''
  $sub = Join-Path $OutDir $rel
  if(-not (Test-Path $sub)){ New-Item -ItemType Directory -Force $sub | Out-Null }
  try{ & $Cli -S 0 -o (Join-Path $sub '?s_?n.wav') $f.FullName 2>$null | Out-Null }catch{}
  $i++
  if($i % 50 -eq 0){ Add-Content $log ("{0}/{1} banks, {2}s" -f $i,$fsb.Count,[int]$sw.Elapsed.TotalSeconds) }
}
$sw.Stop()
$wav = (Get-ChildItem -LiteralPath $OutDir -Recurse -File -Filter *.wav | Measure-Object).Count
Add-Content $log ("DONE {0} banks, {1} WAV, {2}s" -f $fsb.Count,$wav,[int]$sw.Elapsed.TotalSeconds)
