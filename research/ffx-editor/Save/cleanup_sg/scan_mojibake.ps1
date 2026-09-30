# Scan de mojibake CP1252 em .axaml/.cs do FFXProjectEditor (chars que NUNCA aparecem em PT-BR legitimo)
$root = 'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor'
$suspects = @(0xC3, 0x20AC, 0x201A, 0x161, 0x2122, 0xE6, 0xE5, 0xC6, 0x2030, 0x2020)  # A-til, EUR, low-quote, s-caron, TM, ae, aa, AE, permille, dagger
$seq = 'â€'  # E2 80 93/94 -> em-dash/en-dash mojibake

$results = @()
Get-ChildItem $root -Recurse -Include '*.axaml', '*.cs' | Where-Object { $_.FullName -notmatch 'bin\\|obj\\' } | ForEach-Object {
    $t = [System.IO.File]::ReadAllText($_.FullName)
    $count = 0
    foreach ($cp in $suspects) {
        $ch = [string][char]$cp
        $count += ([regex]::Matches($t, [regex]::Escape($ch))).Count
    }
    $count += ([regex]::Matches($t, [regex]::Escape($seq))).Count
    if ($count -gt 0) {
        $results += [PSCustomObject]@{ Count = $count; File = $_.FullName.Replace($root + '\', '') }
    }
}
$results | Sort-Object Count -Descending | Select-Object -First 30 | Format-Table -AutoSize | Out-String -Width 170
"TOTAL arquivos com suspeita: $($results.Count)"
