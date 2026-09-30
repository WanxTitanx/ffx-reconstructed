# Decodifica os nomes das entries do sphere.bin US (string pool, ASCII-like)
$p = 'D:\FFX Extracted\FFX\ffx_ps2\ffx\master\new_uspc\battle\kernel\sphere.bin'
$b = [System.IO.File]::ReadAllBytes($p)
$min = [BitConverter]::ToUInt16($b, 0x08)
$max = [BitConverter]::ToUInt16($b, 0x0A)
$elen = [BitConverter]::ToUInt16($b, 0x0C)
$dlen = [BitConverter]::ToUInt16($b, 0x0E)
$poolStart = 0x14 + $dlen
"US sphere.bin: min=$min max=$max entryLen=$elen dataLen=$dlen poolStart=0x$($poolStart.ToString('X4')) fileLen=$($b.Length)"

function Read-Str([byte[]]$bytes, [int]$start, [int]$offset) {
    if ($offset -lt 0 -or $offset -ge $bytes.Length) { return '<bad>' }
    $sb = New-Object System.Text.StringBuilder
    $i = $start + $offset
    while ($i -lt $bytes.Length -and $bytes[$i] -ne 0) {
        $c = $bytes[$i]
        if ($c -ge 0x20 -and $c -lt 0x7F) { [void]$sb.Append([char]$c) }
        elseif ($c -gt 0x7F) { [void]$sb.Append(('[{0:X2}]' -f $c)) }
        else { [void]$sb.Append(('~{0:X2}' -f $c)) }
        $i++
    }
    return $sb.ToString()
}

for ($i = $min; $i -le $max; $i++) {
    $off = 0x14 + ($i - $min) * $elen
    $dOff = [BitConverter]::ToUInt16($b, $off + 0x00)
    $sOff = [BitConverter]::ToUInt16($b, $off + 0x04)
    $behavior = [BitConverter]::ToUInt16($b, $off + 0x08)
    $activates = [BitConverter]::ToUInt16($b, $off + 0x0A)
    $range = $b[$off + 0x0C]
    $special = $b[$off + 0x0D]
    $name = Read-Str $b $poolStart $dOff
    $short = Read-Str $b $poolStart $sOff
    "entry $i : name='$name' short='$short' | behavior=$behavior activates=0x$($activates.ToString('X4')) range=0x$($range.ToString('X2')) special=0x$($special.ToString('X2'))"
}
