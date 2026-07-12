// Function: sub_8108F0
// Address: 0x8108f0
int __cdecl sub_8108F0(int a1, int a2, int a3, int a4)
{
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    *(_BYTE *)(a4 + 8) |= 0x80u;
  return a3 + 2;
}
