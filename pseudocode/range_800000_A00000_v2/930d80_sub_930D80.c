// Function: sub_930D80
// Address: 0x930d80
int sub_930D80()
{
  int result; // eax

  if ( unk_193C0F0 )
    return sub_937F50(unk_193C0F0);
  if ( !unk_193BF80 )
    sub_921CE0();
  unk_193C0F0 = sub_9258B0(1, 3084);
  sub_937EF0(unk_193C0F0, 8, 8, 76, 183, 6, sub_935000, "PRE2D", 0);
  *(_DWORD *)(unk_193C0F0 + 2788) = 13824;
  *(_DWORD *)(unk_193C0F0 + 2792) = 4;
  *(_DWORD *)(unk_193C0F0 + 2796) = 4;
  *(_DWORD *)(unk_193C0F0 + 2800) = 8;
  *(_DWORD *)(unk_193C0F0 + 2804) = 8;
  *(_DWORD *)(unk_193C0F0 + 2808) = 14080;
  *(_DWORD *)(unk_193C0F0 + 2812) = 256;
  *(_DWORD *)(unk_193C0F0 + 2816) = 256;
  *(_DWORD *)(unk_193C0F0 + 2820) = 1;
  result = unk_193C0F0;
  *(_DWORD *)(unk_193C0F0 + 2824) = 0;
  return result;
}
