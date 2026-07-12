// Function: sub_817C10
// Address: 0x817c10
int __cdecl sub_817C10(int a1, int a2)
{
  unsigned __int8 v3; // al
  int v4; // ebx
  int v5; // esi
  unsigned int n0x2000; // ecx
  int v7; // edx
  bool v9; // zf
  bool v10; // zf
  bool v11; // zf
  int v12; // [esp+14h] [ebp+8h]

  v12 = *(_DWORD *)(a1 + 544);
  if ( *(__int16 *)(a1 + 538) < 0 )
  {
    v4 = sub_795670(*(unsigned __int8 *)(v12 + 24));
    v3 = HIBYTE(v12);
  }
  else
  {
    v3 = sub_82AA20(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v12 + 24)]));
    v4 = v12;
  }
  v5 = a2;
  n0x2000 = *(_WORD *)(a1 + 538) & 0xF000;
  v7 = *(unsigned __int16 *)(a2 + 2);
  if ( n0x2000 <= 0x5000 )
  {
    if ( n0x2000 != 20480 )
    {
      if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0x2000 )
      {
        if ( n0x2000 == 0x2000 )
        {
          if ( (v3 & (unsigned __int8)v7) == 0 )
            return a2 + 6;
          return *(__int16 *)(a2 + 4) + a2;
        }
        if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
        {
          if ( n0x2000 == 4096 )
          {
            if ( v3 == (_WORD)v7 )
              return a2 + 6;
            return *(__int16 *)(a2 + 4) + a2;
          }
          return v5;
        }
        v9 = (unsigned __int16)v3 == (unsigned __int16)v7;
LABEL_13:
        if ( !v9 )
          return a2 + 6;
        return *(__int16 *)(a2 + 4) + a2;
      }
      if ( n0x2000 == 12288 )
      {
        v9 = (v3 & (unsigned __int8)v7) == 0;
        goto LABEL_13;
      }
      if ( n0x2000 == 0x4000 )
      {
        v10 = (unsigned __int16)v3 == (unsigned __int16)v7;
        goto LABEL_33;
      }
      return v5;
    }
    v11 = (unsigned __int16)v3 == (unsigned __int16)v7;
LABEL_36:
    if ( !v11 )
      goto LABEL_34;
    return a2 + 4;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0x9000 )
  {
    if ( n0x2000 != 36864 )
    {
      if ( n0x2000 == 24576 )
      {
        sub_82AA50(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v12 + 24)]), *(unsigned __int16 *)(a2 + 2));
        return a2 + 4;
      }
      if ( n0x2000 != 0x8000 )
        return v5;
      if ( (v7 & v4) != 0 )
        return *(__int16 *)(a2 + 4) + a2;
      return a2 + 6;
    }
    v9 = (v7 & v4) == 0;
    goto LABEL_13;
  }
  if ( n0x2000 == 40960 )
  {
    v11 = (v7 & v4) == 0;
    goto LABEL_36;
  }
  if ( n0x2000 == 45056 )
  {
    v10 = (v7 & v4) == 0;
LABEL_33:
    if ( v10 )
    {
LABEL_34:
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    }
    return a2 + 4;
  }
  return v5;
}
