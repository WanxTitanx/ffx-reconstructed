# F8 UnX Fase 4c - isolamento: UnX SEM o probe ativo (ffx-probe fica .RT2OFF).
# Se crashar igual -> SpecialK e o culpado. Se nao -> conflito probe x UnX (INC-002).
param([int]$TimeoutSec = 100)
$ErrorActionPreference = 'Stop'
$root = 'D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster'
$iso  = Join-Path $root '_isolated'
$out  = 'C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\fase4'
New-Item -ItemType Directory -Force (Join-Path $out 'logs_v3') | Out-Null
$reportFile = Join-Path $out 'session_v3_report.txt'

function Log($m) {
    Add-Content -Path $reportFile -Value ('{0}  {1}' -f (Get-Date -Format 'HH:mm:ss'), $m) -Encoding utf8
    Write-Host $m
}

try {
    if (Get-Process FFX -ErrorAction SilentlyContinue) { throw 'FFX rodando' }
    Copy-Item (Join-Path $iso 'dxgi.dll') (Join-Path $root 'dxgi.dll') -Force
    Copy-Item (Join-Path $iso 'unx.dll')  (Join-Path $root 'unx.dll')  -Force
    Copy-Item (Join-Path $iso 'dxgi.ini') (Join-Path $root 'dxgi.ini') -Force
    Log 'UnX installed (probe NOT restored - stays .RT2OFF)'

    $wer = 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps\FFX.exe'
    New-Item -Path $wer -Force | Out-Null
    Set-ItemProperty $wer 'DumpFolder' (Join-Path $out 'dumps_v3')
    Set-ItemProperty $wer 'DumpType' 2
    Set-ItemProperty $wer 'DumpCount' 3
    New-Item -ItemType Directory -Force (Join-Path $out 'dumps_v3') | Out-Null

    $p = Start-Process -FilePath (Join-Path $root 'FFX.exe') -WorkingDirectory $root -PassThru
    $deadline = (Get-Date).AddSeconds($TimeoutSec)
    while ((Get-Date) -lt $deadline) {
        Start-Sleep -Milliseconds 1500
        if ($p.HasExited) { Log "FFX exited: code=$($p.ExitCode) after $([int]((Get-Date)-$p.StartTime).TotalSeconds)s"; break }
    }
    if (-not $p.HasExited) {
        Log 'FFX alive at deadline (BOOT OK sem probe!)'
        Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
    }
} catch {
    Log "ERROR: $($_.Exception.Message)"
} finally {
    foreach ($f in @('dxgi.dll','unx.dll','dxgi.ini')) { Remove-Item (Join-Path $root $f) -Force -ErrorAction SilentlyContinue }
    Remove-Item 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps' -Recurse -Force -ErrorAction SilentlyContinue
    Start-Sleep -Seconds 30   # WER async -> dumps_v3
    foreach ($lf in @('logs\dxgi.log','logs\crash.log')) {
        $src = Join-Path $root $lf
        if (Test-Path $src) { Copy-Item $src (Join-Path $out 'logs_v3' (($lf -replace '\\','_'))) -Force -ErrorAction SilentlyContinue }
    }
    Log 'State restored'
}
Get-ChildItem (Join-Path $out 'dumps_v3') -File -ErrorAction SilentlyContinue | Select-Object Name, Length | Format-Table -AutoSize
