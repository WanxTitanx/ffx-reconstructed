# ffx_reconstructed/scripts/crons/commit.ps1
# Commit consolidado se dirty + push origin main. Roda a cada 60 min.
$ErrorActionPreference = "Continue"
$repoPath = "C:\Users\wande\Documents\ffx-editor-main\ffx_reconstructed"
$logFile = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\commit_cycle.log"
$intervalSec = 3600  # 60 min

while ($true) {
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Push-Location -LiteralPath $repoPath
    try {
        $status = git status --porcelain
        if (-not $status) {
            Add-Content -LiteralPath $logFile -Value "[$timestamp] clean, skipping"
        } else {
            git add .
            $commitMsg = "chore(cron): auto-commit $timestamp"
            git commit -m $commitMsg | Out-Null
            $pushResult = git push origin main 2>&1
            Add-Content -LiteralPath $logFile -Value "[$timestamp] committed + pushed: $commitMsg"
        }
    } catch {
        Add-Content -LiteralPath $logFile -Value "[$timestamp] FAILED: $_"
    } finally {
        Pop-Location
    }
    Start-Sleep -Seconds $intervalSec
}
