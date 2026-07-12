// Function: sub_81CB70
// Address: 0x81cb70
_WORD *__cdecl sub_81CB70(int a1, _WORD *a2)
{
  int v2; // edx
  unsigned int n0x4000; // eax
  bool v4; // zf
  _WORD *result; // eax

  v2 = *(_DWORD *)(a1 + 544);
  n0x4000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n0x4000 > 0x2000 )
  {
    if ( n0x4000 == 12288 )
    {
      *(_WORD *)(v2 + 192) &= ~a2[1];
      return a2 + 2;
    }
    else if ( n0x4000 == 0x4000 )
    {
      *(_BYTE *)(v2 + 187) = 0;
      sub_800C30(a1 + 768, *(_WORD *)(a1 + 532));
      return a2 + 1;
    }
    else
    {
      return a2;
    }
  }
  else if ( n0x4000 == 0x2000 )
  {
    *(_BYTE *)(v2 + 187) = *((_BYTE *)a2 + 2);
    *(_DWORD *)(v2 + 168) = a2 + 3;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    return (_WORD *)((char *)a2 + (unsigned __int16)(2 * a2[2]) + 6);
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    v4 = n0x4000 == 4096;
    result = a2;
    if ( v4 )
    {
      *(_WORD *)(v2 + 192) |= a2[1];
      return a2 + 2;
    }
  }
  else
  {
    *(_BYTE *)(v2 + 187) = *((_BYTE *)a2 + 2);
    *(_WORD *)(v2 + 168) = a2[2];
    *(_WORD *)(v2 + 170) = a2[3];
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    return a2 + 4;
  }
  return result;
}
