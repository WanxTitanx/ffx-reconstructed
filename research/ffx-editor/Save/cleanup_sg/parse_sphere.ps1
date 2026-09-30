# Parse sphere.bin (50 entries x 0x10) - campos em hex, sem dependencia de console encoding
$p = 'D:\FFX Extracted\FFX\ffx_ps2\ffx\master\jppc\battle\kernel\sphere.bin'
$b = [System.IO.File]::ReadAllBytes($p)
"len=$($b.Length) entries=$($b.Length / 0x10)"
for ($i = 0; $i -lt $b.Length; $i += 0x10) {
    $idx = $i / 0x10
    $b0 = $b[$i]; $b1 = $b[$i+1]; $b2 = $b[$i+2]; $b3 = $b[$i+3]
    $b4 = $b[$i+4]; $b5 = $b[$i+5]; $b6 = $b[$i+6]; $b7 = $b[$i+7]
    $bh = $b[$i+8]; $bl = $b[$i+9]
    $ah = $b[$i+0x0A]; $al = $b[$i+0x0B]
    $rng = $b[$i+0x0C]; $d = $b[$i+0x0D]
    $e0 = $b[$i+0x0E]; $e1 = $b[$i+0x0F]
    $behavior = $bh * 256 + $bl
    $activates = $ah * 256 + $al
    $bin = [Convert]::ToString($activates, 2).PadLeft(16, '0')
    $u16a = [BitConverter]::ToUInt16($b, $i+0)
    $u16b = [BitConverter]::ToUInt16($b, $i+2)
    $u16c = [BitConverter]::ToUInt16($b, $i+4)
    $u16d = [BitConverter]::ToUInt16($b, $i+6)
    "entry $idx : b0=$($b0.ToString('X2')) b1=$($b1.ToString('X2')) b2=$($b2.ToString('X2')) b3=$($b3.ToString('X2')) b4=$($b4.ToString('X2')) b5=$($b5.ToString('X2')) b6=$($b6.ToString('X2')) b7=$($b7.ToString('X2')) | u16@0=$($u16a.ToString('X4')) @2=$($u16b.ToString('X4')) @4=$($u16c.ToString('X4')) @6=$($u16d.ToString('X4')) | behavior=$behavior activates=0x$($activates.ToString('X4')) [$bin] range=0x$($rng.ToString('X2')) d=0x$($d.ToString('X2')) e0=0x$($e0.ToString('X2')) e1=0x$($e1.ToString('X2'))"
}
