# RECOVERED 2026-09-18 (lane Jarvis-TOOLS-REPAIR): restored from git history commit 53d82b2a
# (RuntimeTools/FFXMapViewerWeb/work/reverse/ida/scripts/run_ffx_ida_batch.ps1).
param(
    [Parameter(Mandatory = $true)]
    [string[]]$Target,

    [string]$DatabasePath = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\FFX_recon.i64",
    [string]$IdaPath = "C:\IDA\IDA-Professional-9.1-main\idat.exe",
    [string]$OutputPath = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\exports\ffx_ida_batch.json",
    [string]$DatabaseCopyRoot,
    [string]$SummaryPath,
    [string]$LogPath = "C:\Users\wande\Documents\ffx-editor-main\work\reverse\ida\exports\ffx_ida_batch.log",
    [int]$MaxXrefs = 20,
    [int]$TargetLimit = 100,
    [int]$OutputGraceSeconds = 5,
    [switch]$NoDatabaseCopy,
    [switch]$NoPseudocode,
    [switch]$NoSummary
)

$ErrorActionPreference = "Stop"

function Get-DatabaseBundleFiles {
    param(
        [Parameter(Mandatory = $true)]
        [string]$SourceDatabasePath
    )

    $directory = Split-Path -Parent $SourceDatabasePath
    $baseName = [System.IO.Path]::GetFileNameWithoutExtension($SourceDatabasePath)
    $extensions = @(".i64", ".id0", ".id1", ".id2", ".nam", ".til")
    $files = @()

    foreach ($extension in $extensions) {
        $candidate = Join-Path $directory ($baseName + $extension)
        if (Test-Path -LiteralPath $candidate) {
            $files += (Get-Item -LiteralPath $candidate)
        }
    }

    if ($files.Count -eq 0) {
        throw "No IDA database bundle files were found for: $SourceDatabasePath"
    }

    return $files
}

function Copy-DatabaseBundle {
    param(
        [Parameter(Mandatory = $true)]
        [string]$SourceDatabasePath,

        [Parameter(Mandatory = $true)]
        [string]$DestinationRoot
    )

    $bundleFiles = Get-DatabaseBundleFiles -SourceDatabasePath $SourceDatabasePath
    $baseName = [System.IO.Path]::GetFileNameWithoutExtension($SourceDatabasePath)
    $runStamp = Get-Date -Format "yyyyMMdd_HHmmss"
    $destinationDirectory = Join-Path $DestinationRoot ("{0}_{1}" -f $baseName, $runStamp)
    New-Item -ItemType Directory -Force -Path $destinationDirectory | Out-Null

    foreach ($file in $bundleFiles) {
        Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $destinationDirectory $file.Name) -Force
    }

    return Join-Path $destinationDirectory ([System.IO.Path]::GetFileName($SourceDatabasePath))
}

if (-not (Test-Path -LiteralPath $IdaPath)) {
    throw "IDA executable not found: $IdaPath"
}

if (-not (Test-Path -LiteralPath $DatabasePath)) {
    throw "IDA database not found: $DatabasePath"
}

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$idaScriptPath = Join-Path $scriptDir "ida_batch_decompile.py"
$readerScriptPath = Join-Path $scriptDir "read_ffx_decompilation.py"
if (-not (Test-Path -LiteralPath $idaScriptPath)) {
    throw "IDA batch script not found: $idaScriptPath"
}
if (-not (Test-Path -LiteralPath $readerScriptPath)) {
    throw "IDA reader script not found: $readerScriptPath"
}

$outputDir = Split-Path -Parent $OutputPath
$logDir = Split-Path -Parent $LogPath
New-Item -ItemType Directory -Force -Path $outputDir | Out-Null
New-Item -ItemType Directory -Force -Path $logDir | Out-Null

if (-not $NoSummary.IsPresent -and [string]::IsNullOrWhiteSpace($SummaryPath)) {
    $summaryFileName = "{0}.summary.md" -f [System.IO.Path]::GetFileNameWithoutExtension($OutputPath)
    $SummaryPath = Join-Path $outputDir $summaryFileName
}

$normalizedTargets = @()
foreach ($entry in $Target) {
    foreach ($piece in ($entry -split ",")) {
        $trimmed = $piece.Trim()
        if ($trimmed) {
            $normalizedTargets += $trimmed
        }
    }
}

$configPath = Join-Path $outputDir "ffx_ida_batch.config.json"
$errorPath = Join-Path $outputDir "ffx_ida_batch.error.txt"
$databaseCopyRoot = if ([string]::IsNullOrWhiteSpace($DatabaseCopyRoot)) {
    Join-Path (Split-Path -Parent $DatabasePath) "_tmp\headless"
}
else {
    $DatabaseCopyRoot
}

Remove-Item -LiteralPath $errorPath -Force -ErrorAction SilentlyContinue
Remove-Item -LiteralPath $configPath -Force -ErrorAction SilentlyContinue
Remove-Item -LiteralPath $LogPath -Force -ErrorAction SilentlyContinue
Remove-Item -LiteralPath $OutputPath -Force -ErrorAction SilentlyContinue
if (-not $NoSummary.IsPresent -and -not [string]::IsNullOrWhiteSpace($SummaryPath)) {
    Remove-Item -LiteralPath $SummaryPath -Force -ErrorAction SilentlyContinue
}

$launchDatabasePath = if ($NoDatabaseCopy.IsPresent) {
    $DatabasePath
}
else {
    New-Item -ItemType Directory -Force -Path $databaseCopyRoot | Out-Null
    Copy-DatabaseBundle -SourceDatabasePath $DatabasePath -DestinationRoot $databaseCopyRoot
}

$config = [ordered]@{
    output_path        = (Resolve-Path -LiteralPath $outputDir).Path + "\" + (Split-Path -Leaf $OutputPath)
    include_pseudocode = (-not $NoPseudocode.IsPresent)
    max_xrefs          = $MaxXrefs
    target_limit       = $TargetLimit
    targets            = $normalizedTargets
}

$config | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $configPath -Encoding UTF8

$env:FFX_IDA_BATCH_CONFIG = $configPath
$env:FFX_IDA_BATCH_ERROR = $errorPath

Write-Host "[ffx_ida_batch] launching IDA..."
Write-Host "  IDA:      $IdaPath"
Write-Host "  Database: $launchDatabasePath"
if (-not $NoDatabaseCopy.IsPresent) {
    Write-Host "  SourceDB: $DatabasePath"
}
Write-Host "  Output:   $OutputPath"
Write-Host "  Targets:  $($normalizedTargets -join ', ')"

$quotedLaunchDatabasePath = '"' + $launchDatabasePath + '"'
$arguments = @("-A", "-L$LogPath", "-S$idaScriptPath", $quotedLaunchDatabasePath)
$launchTime = Get-Date
$process = Start-Process -FilePath $IdaPath -ArgumentList $arguments -PassThru -WindowStyle Hidden
$outputSeenAt = $null

while (-not $process.HasExited) {
    Start-Sleep -Seconds 1
    $process.Refresh()

    if (Test-Path -LiteralPath $OutputPath) {
        $outputItem = Get-Item -LiteralPath $OutputPath
        if ($outputItem.LastWriteTime -ge $launchTime) {
            if (-not $outputSeenAt) {
                $outputSeenAt = Get-Date
            }
            elseif (((Get-Date) - $outputSeenAt).TotalSeconds -ge $OutputGraceSeconds) {
                Stop-Process -Id $process.Id -Force -ErrorAction SilentlyContinue
                break
            }
        }
    }
}

try {
    Wait-Process -Id $process.Id -Timeout 5 -ErrorAction SilentlyContinue
} catch {
}

$exitCode = $process.ExitCode

if (($exitCode -ne 0) -and -not (Test-Path -LiteralPath $OutputPath)) {
    if (Test-Path -LiteralPath $errorPath) {
        Get-Content -LiteralPath $errorPath | Write-Error
    }
    throw "IDA batch decompilation failed with exit code $exitCode"
}

if (-not (Test-Path -LiteralPath $OutputPath)) {
    throw "IDA finished without producing output: $OutputPath"
}

if (-not $NoSummary.IsPresent) {
    $pythonCommand = Get-Command -Name py -ErrorAction SilentlyContinue
    $pythonArguments = @()

    if ($pythonCommand) {
        $pythonExecutable = $pythonCommand.Source
        $pythonArguments += "-3"
    }
    else {
        $pythonCommand = Get-Command -Name python -ErrorAction SilentlyContinue
        if (-not $pythonCommand) {
            throw "Could not find Python launcher (`py`) or `python` to build the Markdown summary."
        }
        $pythonExecutable = $pythonCommand.Source
    }

    $pythonArguments += @(
        $readerScriptPath,
        "--input", $OutputPath,
        "--write-summary",
        "--summary-output", $SummaryPath
    )

    Write-Host "[ffx_ida_batch] writing summary..."
    & $pythonExecutable @pythonArguments
    if ($LASTEXITCODE -ne 0) {
        throw "Summary generation failed with exit code $LASTEXITCODE"
    }
}

Write-Host "[ffx_ida_batch] completed successfully."
Write-Host "  JSON: $OutputPath"
Write-Host "  Log:  $LogPath"
if (-not $NoSummary.IsPresent) {
    Write-Host "  Summary: $SummaryPath"
}
