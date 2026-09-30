# Scan confiavel: todas as linhas com U+00C3 (A-til) nos .axaml/.cs, com o codepoint seguinte (para distinguir mojibake de PT-BR legitimo)
$root = 'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor'
$hits = 0
Get-ChildItem $root -Recurse -Include '*.axaml', '*.cs' | Where-Object { $_.FullName -notmatch 'bin\\|obj\\' } | ForEach-Object {
    $lines = [System.IO.File]::ReadAllLines($_.FullName)
    for ($i = 0; $i -lt $lines.Length; $i++) {
        $l = $lines[$i]
        $idx = 0
        while (($idx = $l.IndexOf([char]0xC3, $idx)) -ge 0) {
            $next = if ($idx + 1 -lt $l.Length) { [int][char]$l[$idx + 1] } else { -1 }
            $nextHex = if ($next -ge 0) { ('U+{0:X4}' -f $next) } else { 'EOF' }
            $t = $l.Trim()
            if ($t.Length -gt 100) { $t = $t.Substring(0, 100) }
            "$($_.FullName.Replace($root + '\', '')) : $($i + 1) : C3-next=$nextHex :: $t"
            $hits++
            $idx += 2
        }
    }
}
"TOTAL C3 hits: $hits"
