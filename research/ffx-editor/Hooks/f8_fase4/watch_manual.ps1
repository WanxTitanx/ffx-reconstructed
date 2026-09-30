# F8 Fase 4 - watcher da sessao manual (usuario abre o FFX). Registra tudo e captura dump/logs.
param([int]$MaxWaitSec = 900)
$ErrorActionPreference = 'Continue'
$root = 'D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster'
$out  = 'C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\fase4'
$ctl  = 'C:\Users\wande\Documents\ffx-editor-main\RuntimeTools\FfxDinput8Probe\ctl\bin\Release\net8.0\ffxprobectl.exe'
$reportFile = Join-Path $out 'session_manual_report.txt'

function Log($m) {
    Add-Content -Path $reportFile -Value ('{0}  {1}' -f (Get-Date -Format 'HH:mm:ss'), $m) -Encoding utf8
    Write-Host $m
}

Log 'WATCHER started. Aguardando o usuario abrir o FFX.exe...'
$deadline = (Get-Date).AddSeconds($MaxWaitSec)
$seen = $false
$hbSeen = $false
while ((Get-Date) -lt $deadline) {
    $p = Get-Process FFX -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($p) {
        if (-not $seen) {
            $seen = $true
            Log "FFX ABRIU: pid=$($p.Id) start=$($p.StartTime)"
        }
        if (-not $hbSeen) {
            $mon = & $ctl mon 2>&1 | Out-String
            if ($mon -match 'hooked') { $hbSeen = $true; Log "probe heartbeat OK: $($mon.Trim())" }
        }
        # amostra dos alvos do UnX enquanto vive
        $sz1 = (Get-Item (Join-Path $root 'logs\dxgi.log') -ErrorAction SilentlyContinue).Length
        if ($sz1 -ne $lastSz) { Log "dxgi.log grows: $sz1 bytes"; $lastSz = $sz1 }
        Start-Sleep -Seconds 2
        continue
    }
    if ($seen) {
        # FFX saiu
        Log 'FFX FECHOU/CRASHOU. Esperando WER (30s) e coletando...'
        Start-Sleep -Seconds 30
        foreach ($lf in @('logs\dxgi.log','logs\UnX.log','logs\crash.log','logs\game_output.log','logs\modules.log','hook.log')) {
            $src = Join-Path $root $lf
            if (Test-Path $src) {
                $dst = Join-Path $out 'logs_manual' (($lf -replace '\\','_'))
                Copy-Item $src $dst -Force -ErrorAction SilentlyContinue
            }
        }
        Get-ChildItem (Join-Path $out 'dumps2') -File -ErrorAction SilentlyContinue | ForEach-Object {
            Log "DUMP CAPTURADO: $($_.Name) $($_.Length) bytes"
        }
        Log 'WATCHER done (coleta finalizada).'
        exit 0
    }
    Start-Sleep -Seconds 2
}
if ($seen) {
    Log 'Timeout do watcher com FFX vivo. Finalizando.'
} else {
    Log 'Timeout: FFX nunca abriu nesta janela.'
}
