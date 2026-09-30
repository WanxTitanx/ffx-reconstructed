<#
Install Visual Studio 2012 Express for Windows Desktop on this VM.

The ISO (VS2012_WDX_ENU, SHA1 verified) must already be at C:\IDA_DB\VS2012_WDX_ENU.iso.
Installs silently to C:\VS2012 with /NoRefresh /NoRestart /Silent flags and
writes a marker file on success. Safe to re-run: skips when the marker exists
and cl.exe is present.
#>

param(
    [string] $IsoPath = 'C:\IDA_DB\VS2012_WDX_ENU.iso',
    [string] $InstallDir = 'C:\VS2012',
    [string] $Marker = 'C:\VS2012\vs2012_express_installed.txt'
)

$ErrorActionPreference = 'Stop'

function Test-Installed {
    return (Test-Path $Marker) -and (Test-Path (Join-Path $InstallDir 'VC\bin\cl.exe'))
}

if (Test-Installed) {
    Write-Output 'ALREADY_INSTALLED'
    & (Join-Path $InstallDir 'VC\bin\cl.exe') 2>&1 | Select-Object -First 2
    exit 0
}

Write-Output "mounting $IsoPath ..."
$vol = Mount-DiskImage -ImagePath $IsoPath -PassThru | Get-Volume
$drive = ($vol.DriveLetter + ':')
Write-Output "mounted at $drive"
try {
    $setup = Join-Path $drive 'wdexpress_full.exe'
    if (-not (Test-Path $setup)) { throw "setup not found: $setup" }
    Write-Output "running $setup /Silent /NoRestart ..."
    $p = Start-Process -FilePath $setup -ArgumentList '/Silent','/NoRestart' -Wait -PassThru
    Write-Output ("setup exit code: " + $p.ExitCode)
    if ($p.ExitCode -ne 0 -and $p.ExitCode -ne 3010) { throw "setup failed with $($p.ExitCode)" }
} finally {
    Dismount-DiskImage -ImagePath $IsoPath | Out-Null
    Write-Output 'dismounted'
}

New-Item -ItemType Directory -Force -Path $InstallDir | Out-Null
"installed $(Get-Date -Format o)" | Out-File -FilePath $Marker -Encoding ascii
Write-Output 'INSTALL_DONE'
& (Join-Path $InstallDir 'VC\bin\cl.exe') 2>&1 | Select-Object -First 2
