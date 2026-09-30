# ApplyBannerByteFix.ps1 — recupera os .cs corrompidos pelo script de banners, via PATCH 100% EM BYTES.
# Causa-raiz: o banner C# perdeu o prefixo '//' nas linhas de nome/path, virando código literal
# com caminhos Windows 'C:\...' (escape invalido) + um char na linha seguinte -> quebra o build.
#
# Estrategia (usuario, 2026-08-18): comentar so as linhas do bloco de banner que nao sao comentario,
# inserindo os bytes ASCII {0x2F,0x2F,0x20} ('// ') no coluna 0 dessas linhas.
# NENHUM outro byte do arquivo e lido/alterado/re-encodado -> preserva strings, encoding (UTF-8,
# UTF-8 com BOM, cp1252/Latin-1, arquivos MISTOS) e line-endings exatamente como estao.
# Isso evita os bugs das versoes anteriores (v1 UTF-8 corrompia cp1252; v2 Latin-1 decompunha UTF-8;
# v3/v4 detector de encoding errava em arquivos mistos -> CS1012).
#
# Uso: .\ApplyBannerByteFix.ps1 [-DryRun] [-Root <dir>]
param(
    [switch]$DryRun,
    [string]$Root = "C:\Users\wande\Documents\ffx-editor-main"
)

$ErrorActionPreference = "Stop"

function Test-BannerOpen { param([byte[]]$b, [int]$st)
    if ($st + 1 -lt $b.Length -and $b[$st] -eq 0x2F -and $b[$st+1] -eq 0x2F) {
        $t = $st + 2
        while ($t -lt $b.Length -and (Is-WsByte $b[$t])) { $t++ }
        return ($t -lt $b.Length -and $b[$t] -eq 0x3D)
    }
    return $false
}

function Test-BannerClose { param([byte[]]$b, [int]$st)
    # '//' seguido de '=' (ignorando espacos)
    return ($st + 2 -lt $b.Length -and $b[$st] -eq 0x2F -and $b[$st+1] -eq 0x2F -and $b[$st+2] -eq 0x3D)
}

function Is-WsByte { param([byte]$v) return ($v -eq 0x20 -or $v -eq 0x09 -or $v -eq 0x0D) }

function Get-Files {
    $out = @()
    $out += Get-ChildItem -LiteralPath (Join-Path $Root "FFXProjectEditor") -Recurse -Filter *.cs -File
    $t = Join-Path $Root "FFXProjectEditor.Tests"
    if (Test-Path -LiteralPath $t) { $out += Get-ChildItem -LiteralPath $t -Recurse -Filter *.cs -File }
    return $out
}

$files = Get-Files
$touched = 0; $written = 0

foreach ($f in $files) {
    $orig = [System.IO.File]::ReadAllBytes($f.FullName)
    if ($orig.Length -lt 4) { continue }

    # banner de abertura no inicio?
    if (-not (Test-BannerOpen $orig 0)) { continue }

    # offsets de inicio de linha (apos cada \n, 0x0A)
    $starts = New-Object System.Collections.Generic.List[int]
    $starts.Add(0)
    $insertions = New-Object System.Collections.Generic.List[int]
    for ($i = 1; $i -lt $orig.Length; $i++) {
        if ($orig[$i-1] -eq 0x0A) { $starts.Add($i) }
    }
    $lineCount = $starts.Count

    # achar separador de fechamento (2a linha que comeca com '// =')
    $closeIdx = -1
    $maxLines = [Math]::Min($lineCount - 1, 40)
    for ($li = 1; $li -le $maxLines; $li++) {
        $st = $starts[$li]
        # skip espacos/CR
        $t = $st
        while ($t -lt $orig.Length -and (Is-WsByte $orig[$t])) { $t++ }
        if ($t + 2 -lt $orig.Length -and $orig[$t] -eq 0x2F -and $orig[$t+1] -eq 0x2F -and $orig[$t+2] -eq 0x3D) {
            $closeIdx = $li; break
        }
    }

    $endLi = if ($closeIdx -ge 0) { $closeIdx } else { $lineCount }

    $codeDelimitersDone = $false
    for ($li = 1; $li -lt $endLi; $li++) {
        $st = $starts[$li]
        # fim da linha (ate \n)
        $ee = $st
        while ($ee -lt $orig.Length -and $orig[$ee] -ne 0x0A) { $ee++ }
        # skip espacos/CR no inicio
        $t = $st
        while ($t -lt $ee -and (Is-WsByte $orig[$t])) { $t++ }
        if ($t -ge $ee) { continue }        # linha em branco
        if ($orig[$t] -eq 0x2F) {           # '/': comentario se // ou /*
            if ($t + 1 -lt $ee -and $orig[$t+1] -eq 0x2F) { continue }
            if ($t + 1 -lt $ee -and $orig[$t+1] -eq 0x2A) { continue }
        }
        if ($orig[$t] -eq 0x2A) { continue } # '*'
        # fallback (sem separador de fechamento): parar antes do primeiro codigo de verdade
        if ($closeIdx -lt 0) {
            $c = [char]([int]$orig[$t])
            if ($t + 5 -lt $ee -and ([System.Text.Encoding]::ASCII.GetString($orig,$t,[Math]::Min(10,$ee-$t))) -match '^(using|namespace|public|internal|partial|class|enum|struct|interface|[#{\[|])') { break }
        }
        # linha ofensiva no banner -> marcar insercao de '// ' na coluna 0
        $insertions.Add($st)
    }

    if ($insertions.Count -eq 0) { continue }
    $touched += 1
    if (-not $DryRun) {
        $ins = $insertions.ToArray(); [Array]::Sort($ins)
        $out = New-Object System.Collections.Generic.List[byte]
        $skip = 0
        $new = 0
        for ($i = 0; $i -lt $orig.Length; $i++) {
            if ($new -lt $ins.Length -and $i -eq $ins[$new]) {
                $out.Add(0x2F); $out.Add(0x2F); $out.Add(0x20)  # '// '
                $new++
            }
            $out.Add($orig[$i])
        }
        [System.IO.File]::WriteAllBytes($f.FullName, $out.ToArray())
        $written += 1
    }
}

$mode = if ($DryRun) { 'DRY-RUN' } else { 'APPLY' }
Write-Host ("[$mode] files with corrupted banner block: " + $touched + " ; files written: " + $written)
if ($DryRun) { Write-Host "Nada foi gravado (dry-run)." }
