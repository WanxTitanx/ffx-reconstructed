# F8 UnX Fase 4 - RT2 harness: boot do FFX com UnX instalado + probe ativo.
# Reproduz o cenario de 19/07/2026 05:54 (crash no boot sem Steam) e coleta:
#   - logs (dxgi.log / UnX.log / crash.log / hook.log)
#   - WER dump (LocalDumps HKCU, escopo usuario, removido no final)
#   - heartbeat do probe + reads dos alvos do UnX (se o jogo chegar a rodar)
# Restaura o estado exato ao final (try/finally).
param(
    [int]$TimeoutSec = 100
)
$ErrorActionPreference = 'Stop'
$root = 'D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster'
$iso  = Join-Path $root '_isolated'
$out  = 'C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\fase4'
New-Item -ItemType Directory -Force (Join-Path $out 'logs') | Out-Null
New-Item -ItemType Directory -Force (Join-Path $out 'dumps') | Out-Null
$ctl  = 'C:\Users\wande\Documents\ffx-editor-main\RuntimeTools\FfxDinput8Probe\ctl\bin\Release\net8.0\ffxprobectl.exe'
$report = @()

function Log($m) { $script:report += ('{0}  {1}' -f (Get-Date -Format 'HH:mm:ss'), $m); Write-Host $m }

function Sha($p) { if (Test-Path $p) { (Get-FileHash -Algorithm SHA256 $p -ErrorAction SilentlyContinue).Hash } else { 'ABSENT' } }

# ---- 0. pre-checks ----------------------------------------------------------
if (Get-Process FFX -ErrorAction SilentlyContinue) { throw 'FFX esta rodando. Feche antes.' }
$pre = @{}
foreach ($f in @('dxgi.dll','unx.dll','dxgi.ini','dinput8.dll','UnX.ini')) { $pre[$f] = Sha (Join-Path $root $f) }
$pre['modules\ffx-probe.dll']    = Sha (Join-Path $root 'modules\ffx-probe.dll')
$pre['modules\ffx-probe.dll.RT2OFF'] = Sha (Join-Path $root 'modules\ffx-probe.dll.RT2OFF')
Log "PRE state: $($pre | ConvertTo-Json -Compress)"

# ---- 1. instalar UnX (do _isolated) ----------------------------------------
try {
    Copy-Item (Join-Path $iso 'dxgi.dll') (Join-Path $root 'dxgi.dll') -Force
    Copy-Item (Join-Path $iso 'unx.dll')  (Join-Path $root 'unx.dll')  -Force
    Copy-Item (Join-Path $iso 'dxgi.ini') (Join-Path $root 'dxgi.ini') -Force
    Log 'UnX installed (dxgi.dll + unx.dll + dxgi.ini)'

    # probe ativo (restaurar de .RT2OFF se presente)
    $probeOn = Join-Path $root 'modules\ffx-probe.dll'
    $probeOff = Join-Path $root 'modules\ffx-probe.dll.RT2OFF'
    if (-not (Test-Path $probeOn) -and (Test-Path $probeOff)) {
        Copy-Item $probeOff $probeOn -Force
        Log 'ffx-probe.dll restored from .RT2OFF (heartbeat/diff)'
    }

    # WER LocalDumps (HKCU, removido no finally)
    $wer = 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps\FFX.exe'
    New-Item -Path $wer -Force | Out-Null
    Set-ItemProperty $wer 'DumpFolder' (Join-Path $out 'dumps')
    Set-ItemProperty $wer 'DumpType' 2
    Set-ItemProperty $wer 'DumpCount' 3
    Log 'WER LocalDumps configured (HKCU, user scope)'

    # ---- 2. lancar FFX -------------------------------------------------------
    $ffx = Join-Path $root 'FFX.exe'
    Log "Launching FFX.exe (timeout ${TimeoutSec}s)..."
    $p = Start-Process -FilePath $ffx -WorkingDirectory $root -PassThru
    $deadline = (Get-Date).AddSeconds($TimeoutSec)
    $aliveAtEnd = $false
    $hbSeen = $false
    while ((Get-Date) -lt $deadline) {
        Start-Sleep -Milliseconds 1500
        if ($p.HasExited) { Log "FFX exited early: code=$($p.ExitCode) after $([int]((Get-Date)-$p.StartTime).TotalSeconds)s"; break }
        if (-not $hbSeen) {
            $mon = & $ctl mon 2>&1 | Out-String
            if ($mon -match 'hooked') { $hbSeen = $true; Log "probe heartbeat OK: $($mon.Trim())" }
        }
    }
    if (-not $p.HasExited) {
        $aliveAtEnd = $true
        Log 'FFX still alive at deadline (boot OK com UnX). Coletando reads...'
        foreach ($rva in @('0x30B040','0x392930','0xD2A8E2','0xD2A8D0')) {
            $r = & $ctl read $rva 16 2>&1 | Out-String
            Log "read $rva -> $($r.Trim())"
        }
        Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
        Log 'FFX killed (cleanup)'
    }
} finally {
    # ---- 3. restaurar estado --------------------------------------------------
    foreach ($f in @('dxgi.dll','unx.dll','dxgi.ini')) { Remove-Item (Join-Path $root $f) -Force -ErrorAction SilentlyContinue }
    if ((Test-Path (Join-Path $root 'modules\ffx-probe.dll')) -and (Test-Path (Join-Path $root 'modules\ffx-probe.dll.RT2OFF'))) {
        Remove-Item (Join-Path $root 'modules\ffx-probe.dll') -Force
        Log 'ffx-probe.dll removed (restored to pre-session state)'
    }
    $wer = 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps'
    Remove-Item "$wer\FFX.exe" -Recurse -Force -ErrorAction SilentlyContinue
    Remove-Item 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps' -Recurse -Force -ErrorAction SilentlyContinue
    # logs
    foreach ($lf in @('logs\dxgi.log','logs\UnX.log','logs\crash.log','logs\game_output.log','logs\modules.log','hook.log')) {
        $src = Join-Path $root $lf
        if (Test-Path $src) {
            $dst = Join-Path $out 'logs' (($lf -replace '\\','_'))
            Copy-Item $src $dst -Force -ErrorAction SilentlyContinue
        }
    }
    Start-Sleep -Seconds 8  # WER async
    Log 'State restored. WER key removed. Logs copied.'
}

Log "aliveAtEnd=$aliveAtEnd hbSeen=$hbSeen"
$report | Set-Content (Join-Path $out 'session_report.txt') -Encoding utf8
Get-ChildItem (Join-Path $out 'dumps') -File -ErrorAction SilentlyContinue | Select-Object Name, Length | Format-Table -AutoSize
