// Function: sub_8169B0
// Address: 0x8169b0
int __cdecl sub_8169B0(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a1 + 538) >> 12;
  if ( (*(_BYTE *)(v3 + v2 + 180))-- == 1 )
    return a2 + 4;
  else
    return a2 + *(__int16 *)(a2 + 2);
}
