# F8 UnX Fase 4 v2 - RT2 harness: boot do FFX com UnX + probe ativo (PS5.1-safe, sem Get-FileHash)
param([int]$TimeoutSec = 100)
$ErrorActionPreference = 'Stop'
$root = 'D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster'
$iso  = Join-Path $root '_isolated'
$out  = 'C:\Users\wande\Documents\ffx-editor-main\work\f8_recon\fase4'
New-Item -ItemType Directory -Force (Join-Path $out 'logs') | Out-Null
New-Item -ItemType Directory -Force (Join-Path $out 'dumps') | Out-Null
$ctl  = 'C:\Users\wande\Documents\ffx-editor-main\RuntimeTools\FfxDinput8Probe\ctl\bin\Release\net8.0\ffxprobectl.exe'
$reportFile = Join-Path $out 'session_report.txt'
$aliveAtEnd = $false
$hbSeen = $false

function Log($m) {
    $line = '{0}  {1}' -f (Get-Date -Format 'HH:mm:ss'), $m
    Add-Content -Path $reportFile -Value $line -Encoding utf8
    Write-Host $line
}

function Sha($p) {
    if (-not (Test-Path $p)) { return 'ABSENT' }
    try {
        $sha = [System.Security.Cryptography.SHA256]::Create()
        $fs = [System.IO.File]::OpenRead($p)
        try { return ([System.BitConverter]::ToString($sha.ComputeHash($fs)) -replace '-', '').ToLower() }
        finally { $fs.Dispose(); $sha.Dispose() }
    } catch { return 'ERR' }
}

function RestoreAll {
    foreach ($f in @('dxgi.dll','unx.dll','dxgi.ini')) { Remove-Item (Join-Path $root $f) -Force -ErrorAction SilentlyContinue }
    if ((Test-Path (Join-Path $root 'modules\ffx-probe.dll')) -and (Test-Path (Join-Path $root 'modules\ffx-probe.dll.RT2OFF'))) {
        Remove-Item (Join-Path $root 'modules\ffx-probe.dll') -Force -ErrorAction SilentlyContinue
        Log 'ffx-probe.dll removed (restored to pre-session state)'
    }
    Remove-Item 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps' -Recurse -Force -ErrorAction SilentlyContinue
    foreach ($lf in @('logs\dxgi.log','logs\UnX.log','logs\crash.log','logs\game_output.log','logs\modules.log','hook.log')) {
        $src = Join-Path $root $lf
        if (Test-Path $src) {
            $dst = Join-Path $out 'logs' (($lf -replace '\\','_'))
            Copy-Item $src $dst -Force -ErrorAction SilentlyContinue
        }
    }
}

try {
    if (Get-Process FFX -ErrorAction SilentlyContinue) { throw 'FFX esta rodando. Feche antes.' }
    Log "PRE: dxgi=$((Sha (Join-Path $root 'dxgi.dll'))) unx=$((Sha (Join-Path $root 'unx.dll'))) probe=$((Sha (Join-Path $root 'modules\ffx-probe.dll'))) probeOff=$((Sha (Join-Path $root 'modules\ffx-probe.dll.RT2OFF')))"

    Copy-Item (Join-Path $iso 'dxgi.dll') (Join-Path $root 'dxgi.dll') -Force
    Copy-Item (Join-Path $iso 'unx.dll')  (Join-Path $root 'unx.dll')  -Force
    Copy-Item (Join-Path $iso 'dxgi.ini') (Join-Path $root 'dxgi.ini') -Force
    Log 'UnX installed (dxgi.dll + unx.dll + dxgi.ini)'

    $probeOn = Join-Path $root 'modules\ffx-probe.dll'
    $probeOff = Join-Path $root 'modules\ffx-probe.dll.RT2OFF'
    if (-not (Test-Path $probeOn) -and (Test-Path $probeOff)) {
        Copy-Item $probeOff $probeOn -Force
        Log 'ffx-probe.dll restored from .RT2OFF'
    }

    $wer = 'HKCU:\Software\Microsoft\Windows\Windows Error Reporting\LocalDumps\FFX.exe'
    New-Item -Path $wer -Force | Out-Null
    Set-ItemProperty $wer 'DumpFolder' (Join-Path $out 'dumps')
    Set-ItemProperty $wer 'DumpType' 2
    Set-ItemProperty $wer 'DumpCount' 3
    Log 'WER LocalDumps configured (HKCU)'

    $ffx = Join-Path $root 'FFX.exe'
    Log "Launching FFX.exe (timeout ${TimeoutSec}s)..."
    $p = Start-Process -FilePath $ffx -WorkingDirectory $root -PassThru
    $deadline = (Get-Date).AddSeconds($TimeoutSec)
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
        Log 'FFX alive at deadline (boot OK com UnX). Coletando reads...'
        foreach ($rva in @('0x30B040','0x392930','0xD2A8E2','0xD2A8D0')) {
            $r = & $ctl read $rva 16 2>&1 | Out-String
            Log "read $rva -> $($r.Trim())"
        }
        Stop-Process -Id $p.Id -Force -ErrorAction SilentlyContinue
        Log 'FFX killed (cleanup)'
    }
} catch {
    Log "HARNESS ERROR: $($_.Exception.Message)"
} finally {
    RestoreAll
    Start-Sleep -Seconds 8
    Log 'State restored. WER key removed. Logs copied.'
    Log "aliveAtEnd=$aliveAtEnd hbSeen=$hbSeen"
}
