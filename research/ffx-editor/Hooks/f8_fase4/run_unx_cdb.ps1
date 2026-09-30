# F8 UnX Fase 4b - rodada com cdb (windbg) para capturar a excecao do crash no boot com UnX.
param([int]$TimeoutSec = 130)
$ErrorActionPreference = 'Stop'
$root = 'D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster'
$iso  = Join-Path $root '_isolated'
$out  = 'C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\fase4'
New-Item -ItemType Directory -Force (Join-Path $out 'cdb') | Out-Null
$cdb  = 'C:\Program Files (x86)\Windows Kits\10\Debuggers\x64\cdb.exe'
$reportFile = Join-Path $out 'session_cdb_report.txt'

function Log($m) {
    $line = '{0}  {1}' -f (Get-Date -Format 'HH:mm:ss'), $m
    Add-Content -Path $reportFile -Value $line -Encoding utf8
    Write-Host $line
}

try {
    if (Get-Process FFX -ErrorAction SilentlyContinue) { throw 'FFX rodando' }
    Copy-Item (Join-Path $iso 'dxgi.dll') (Join-Path $root 'dxgi.dll') -Force
    Copy-Item (Join-Path $iso 'unx.dll')  (Join-Path $root 'unx.dll')  -Force
    Copy-Item (Join-Path $iso 'dxgi.ini') (Join-Path $root 'dxgi.ini') -Force
    Log 'UnX installed'

    $logFile = Join-Path $out 'cdb\cdb_session.txt'
    $ffx = Join-Path $root 'FFX.exe'
    Log 'Launching under cdb...'
    $args = @('-o','-g','-G','-c','.logopen "' + $logFile + '"; g; !analyze -v; .ecxr; kv; q','-cd','"'+$root+'"',$ffx)
    $p = Start-Process -FilePath $cdb -ArgumentList $args -PassThru -WindowStyle Hidden
    $deadline = (Get-Date).AddSeconds($TimeoutSec)
    while ((Get-Date) -lt $deadline) {
        Start-Sleep -Seconds 3
        if ($p.HasExited) { Log "cdb exited: code=$($p.ExitCode)"; break }
    }
    if (-not $p.HasExited) {
        Log 'timeout: killing cdb+FFX'
        Get-Process FFX -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue
        Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
    }
} catch {
    Log "ERROR: $($_.Exception.Message)"
} finally {
    foreach ($f in @('dxgi.dll','unx.dll','dxgi.ini')) { Remove-Item (Join-Path $root $f) -Force -ErrorAction SilentlyContinue }
    Log 'UnX removed. State restored.'
}
