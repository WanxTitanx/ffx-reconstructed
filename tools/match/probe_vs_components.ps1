<#
Probe which Visual Studio channel still offers the MSVC v110 (VS2012) toolset.

The target FFX.exe was linked by 11.00.50727, so reproducing its codegen needs
that toolset. This script downloads the channel manifests for VS2019 and VS2022
and greps the catalog for v110 / VS2012 components.
#>

param(
    [string[]] $Channels = @('https://aka.ms/vs/16/release/channel', 'https://aka.ms/vs/17/release/channel'),
    [string] $OutDir = 'C:\IDA_DB\vsprobe'
)

$ErrorActionPreference = 'Continue'
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

foreach ($channel in $Channels) {
    Write-Output "=== $channel ==="
    try {
        $json = (Invoke-WebRequest -Uri $channel -UseBasicParsing -TimeoutSec 60).Content | ConvertFrom-Json
    } catch {
        Write-Output "  channel fetch failed: $($_.Exception.Message)"
        continue
    }
    $items = if ($json.PSObject.Properties.Name -contains 'channelItems') { $json.channelItems } else { $json }
    $catalogs = @()
    foreach ($item in $items) {
        Write-Output "  item type=$($item.type) id=$($item.id)"
        if ($item.type -eq 'Manifest' -and $item.payloads) {
            foreach ($p in $item.payloads) {
                if ($p.url -like '*.json') { $catalogs += $p.url }
            }
        }
    }
    Write-Output "  catalogs: $($catalogs.Count)"
    foreach ($cat in $catalogs) {
        $name = Split-Path $cat -Leaf
        $dest = Join-Path $OutDir $name
        if (-not (Test-Path $dest)) {
            try {
                Invoke-WebRequest -Uri $cat -OutFile $dest -UseBasicParsing -TimeoutSec 300
            } catch {
                Write-Output "  catalog download failed ($name): $($_.Exception.Message)"
                continue
            }
        }
        $hits = Select-String -Path $dest -Pattern 'v110|x86\.x64\.v110|VS2012|11\.0\.50727' -AllMatches -ErrorAction SilentlyContinue
        Write-Output "  $name : $($hits.Count) v110-ish matches"
        foreach ($h in $hits | Select-Object -First 6) {
            $line = $h.Line.Trim()
            if ($line.Length -gt 220) { $line = $line.Substring(0, 220) }
            Write-Output "     $line"
        }
    }
}
