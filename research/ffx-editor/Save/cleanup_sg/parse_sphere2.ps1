# Parse correto do sphere.bin (container LocalizedDataPayload: header 0x14, entries em 0x14 + rel*EntryLength)
$p = 'D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\battle\kernel\sphere.bin'
$b = [System.IO.File]::ReadAllBytes($p)
$sig = $b[0]
$min = [BitConverter]::ToUInt16($b, 0x08)
$max = [BitConverter]::ToUInt16($b, 0x0A)
$elen = [BitConverter]::ToUInt16($b, 0x0C)
$dlen = [BitConverter]::ToUInt16($b, 0x0E)
"sig=0x$($sig.ToString('X2')) min=$min max=$max entryLen=$elen dataLen=$dlen fileLen=$($b.Length) entryCount=$($max-$min+1)"
for ($i = $min; $i -le $max; $i++) {
    $off = 0x14 + ($i - $min) * $elen
    if ($off + 0x10 -gt $b.Length) { "entry $i : FORA do arquivo"; continue }
    $u0 = [BitConverter]::ToUInt16($b, $off + 0x00)   # jpDescriptionOffset
    $u2 = [BitConverter]::ToUInt16($b, $off + 0x02)   # jpDescriptionKey
    $u4 = [BitConverter]::ToUInt16($b, $off + 0x04)   # jpSimplifiedOffset
    $u6 = [BitConverter]::ToUInt16($b, $off + 0x06)   # jpSimplifiedKey
    $behavior = [BitConverter]::ToUInt16($b, $off + 0x08)
    $activates = [BitConverter]::ToUInt16($b, $off + 0x0A)
    $range = $b[$off + 0x0C]
    $specialRole = $b[$off + 0x0D]
    $reserved = [BitConverter]::ToUInt16($b, $off + 0x0E)
    $bin = [Convert]::ToString($activates, 2).PadLeft(16, '0')
    $behavHex = $behavior.ToString('X4')
    $actHex = $activates.ToString('X4')
    "entry $i : off=0x$($off.ToString('X4')) str0=0x$($u0.ToString('X4')) key2=0x$($u2.ToString('X4')) str4=0x$($u4.ToString('X4')) key6=0x$($u6.ToString('X4')) | behavior=0x$behavHex activates=0x$actHex bits=$bin range=0x$($range.ToString('X2')) special=0x$($specialRole.ToString('X2')) reserved=0x$($reserved.ToString('X4'))"
}
