// Function: sub_810DC0
// Address: 0x810dc0
_BYTE *__cdecl sub_810DC0(int a1, int a2, int a3, _BYTE *a4)
{
  _BYTE *v4; // edx

  v4 = (_BYTE *)(a3 + 2);
  if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
  {
    a4[28] = *v4;
    v4 = (_BYTE *)(a3 + 4);
  }
  if ( (*(_WORD *)(a1 + 538) & 0x2000) != 0 )
  {
    a4[29] = *v4;
    v4 += 2;
  }
  if ( (*(_WORD *)(a1 + 538) & 0x4000) != 0 )
  {
    a4[30] = *v4;
    v4 += 2;
  }
  if ( *(__int16 *)(a1 + 538) >= 0 )
    return v4;
  a4[31] = *v4;
  return v4 + 2;
}
