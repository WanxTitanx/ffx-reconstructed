# ffx_reconstructed/scripts/crons/backup.ps1
# Backup da DB com timestamp + rotation 5 ultimos. Roda a cada 30 min.
$ErrorActionPreference = "Continue"
$dbPath = "D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\ffxoficial.exe.i64"
$backupRoot = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\backups_ffxoficial"
$logFile = "$backupRoot\backup.log"
$intervalSec = 1800  # 30 min

if (-not (Test-Path -LiteralPath $backupRoot)) {
    New-Item -ItemType Directory -Path $backupRoot -Force | Out-Null
}

while ($true) {
    $timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
    $dst = Join-Path $backupRoot "ffxoficial_$timestamp.i64"

    try {
        Copy-Item -LiteralPath $dbPath -Destination $dst -Force
        $hash = (Get-FileHash -LiteralPath $dst -Algorithm MD5).Hash
        $size = [math]::Round((Get-Item -LiteralPath $dst).Length / 1MB, 1)
        Add-Content -LiteralPath $logFile -Value "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] BACKUP $dst ($size MB, MD5 $hash)"
    } catch {
        Add-Content -LiteralPath $logFile -Value "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] BACKUP FAILED: $_"
    }

    # Rotation: manter ultimos 5
    $existing = Get-ChildItem -LiteralPath $backupRoot -Filter "ffxoficial_*.i64" | Sort-Object LastWriteTime -Descending
    if ($existing.Count -gt 5) {
        $toDelete = $existing | Select-Object -Skip 5
        foreach ($f in $toDelete) {
            Remove-Item -LiteralPath $f.FullName -Force
            Add-Content -LiteralPath $logFile -Value "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] ROTATION removed $($f.Name)"
        }
    }

    Start-Sleep -Seconds $intervalSec
}
