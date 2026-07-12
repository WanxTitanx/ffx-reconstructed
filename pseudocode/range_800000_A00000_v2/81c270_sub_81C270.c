// Function: sub_81C270
// Address: 0x81c270
int __cdecl sub_81C270(int a1, int a2)
{
  int v2; // esi
  unsigned int n12288; // eax
  unsigned __int8 v4; // al
  unsigned __int8 v5; // bl
  int result; // eax
  __int16 v8; // bx
  bool v9; // zf
  float v10; // [esp+10h] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  n12288 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n12288 > 0x2000 )
  {
    v9 = n12288 == 12288;
    result = a2;
    if ( v9 )
    {
      *(_WORD *)(v2 + 196) = *(_WORD *)(a2 + 2);
      return a2 + 4;
    }
  }
  else if ( n12288 == 0x2000 )
  {
    v8 = *(_WORD *)(a2 + 2);
    if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
    {
      v10 = (float)v8;
      v8 = (int)(sub_800BF0(*(unsigned __int8 *)(v2 + 24), *(char *)(a1 + 542)) * v10);
    }
    *(_WORD *)(v2 + 198) = v8;
    return a2 + 4;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( n12288 == 4096 )
    {
      v4 = *(_BYTE *)(a2 + 2);
      v5 = *(_BYTE *)(a2 + 3);
      if ( v4 )
        *(_WORD *)(v2 + 242) = (int)*(float *)(v4 + v2);
      if ( v5 )
        *(_WORD *)(v2 + 244) = (int)*(float *)(v5 + v2);
      return a2 + 6;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    *(_WORD *)(v2 + 192) |= 0x8000u;
    return a2 + 2;
  }
  return result;
}
