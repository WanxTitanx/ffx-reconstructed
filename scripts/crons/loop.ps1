# ffx_reconstructed/scripts/crons/loop.ps1
# Loop perpetuo de 1 ciclo a cada 4 min. Roda indefinidamente.
param([switch]$Once)

$ErrorActionPreference = "Stop"
$markerFile = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\.next_cycle_marker.json"
$logFile = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\loop_cycle.log"

function Run-Cycle {
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    $msg = "[$timestamp] === CICLO INICIA ==="
    Write-Host $msg
    Add-Content -LiteralPath $logFile -Value $msg
    $marker = @{ last_cycle = $timestamp; cycle_id = [guid]::NewGuid().ToString() } | ConvertTo-Json
    Set-Content -LiteralPath $markerFile -Value $marker -Encoding UTF8
    Add-Content -LiteralPath $logFile -Value "[$timestamp] marker gravado em $markerFile"
    Add-Content -LiteralPath $logFile -Value "[$timestamp] === CICLO OK ==="
}

if ($Once) { Run-Cycle; return }

while ($true) {
    Run-Cycle
    Start-Sleep -Seconds 240
}
