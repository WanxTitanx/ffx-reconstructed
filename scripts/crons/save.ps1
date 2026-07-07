# ffx_reconstructed/scripts/crons/save.ps1
# idb_save defensive via IDA MCP. Roda a cada 15 min.
$ErrorActionPreference = "Continue"
$dbPath = "D:\SteamLibrary\steamapps\common\FINAL FANTASY FFX&FFX-2 HD Remaster\ffxoficial.exe.i64"
$lockFile = "$dbPath.lock"
$logFile = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\save_cycle.log"
$intervalSec = 900  # 15 min

while ($true) {
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    if (Test-Path -LiteralPath $lockFile) {
        Add-Content -LiteralPath $logFile -Value "[$timestamp] DB locked, skipping save"
    } else {
        # Hook: idalib_idb_save via MCP - implementacao real quando agente cron chamar
        # Por enquanto so loga
        Add-Content -LiteralPath $logFile -Value "[$timestamp] save.ps1 tick (idb_save via MCP pending - cron stub)"
    }
    Start-Sleep -Seconds $intervalSec
}
