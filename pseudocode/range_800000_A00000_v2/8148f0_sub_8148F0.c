// Function: sub_8148F0
// Address: 0x8148f0
int __cdecl sub_8148F0(int a1, int a2)
{
  int v2; // ebx
  int v4; // [esp-4h] [ebp-10h]

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
  {
    v4 = a2 + *(__int16 *)(a2 + 4);
    *(_WORD *)(v2 + 168) = *(_WORD *)(a2 + 2);
    *(_DWORD *)(v2 + 172) = unknown_libname_742(v4);
    *(_BYTE *)(v2 + 187) = 11;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
  }
  return a2 + 6;
}
