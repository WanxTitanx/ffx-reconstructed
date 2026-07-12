// Function: sub_816F90
// Address: 0x816f90
int __cdecl sub_816F90(int a1, int a2)
{
  int v2; // ecx
  unsigned int n0x3000; // eax
  int v4; // esi
  char *v5; // edi
  int v6; // eax
  int result; // eax
  bool v8; // zf
  float v9; // edi
  int v10; // eax
  char *v11; // esi
  int n2; // eax
  unsigned __int8 n2_1; // cl
  int v14; // esi
  int v15; // eax
  int n4274; // eax

  v2 = *(_DWORD *)(a1 + 544);
  n0x3000 = *(_WORD *)(a1 + 538) & 0xF000;
  v4 = *(_WORD *)(a1 + 538) & 0x800;
  v5 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  if ( n0x3000 > 0x3000 )
  {
    switch ( n0x3000 )
    {
      case 0x4000u:
        v14 = 0;
        if ( v5[8] )
        {
          while ( 1 )
          {
            v15 = sub_7FE890(LODWORD(flt_12A80C0[(unsigned __int8)v5[v14 + 16]]), 0, 0);
            if ( v15 >= 0 )
            {
              n4274 = *((_DWORD *)&unk_12A2284 + 8 * v15);
              if ( n4274 == 4274 || n4274 == 4275 || n4274 == 4276 || n4274 == 4385 || n4274 == 4386 || n4274 == 4387 )
                return *(__int16 *)(a2 + 2) + a2;
            }
            if ( ++v14 >= (unsigned __int8)v5[8] )
              goto LABEL_47;
          }
        }
        break;
      case 0x5000u:
        if ( (int)sub_83C070(0) < 1966080 && (int)sub_83C070(1) < 1966080 && (int)sub_83C070(2) < 1966080 )
          return *(__int16 *)(a2 + 2) + a2;
        break;
      case 0x6000u:
        v8 = (*((_BYTE *)&unk_12A2280 + 32 * sub_7FE890(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]), 0, 0) + 23)
            & 1) == 0;
        v6 = a2;
        if ( !v8 )
          return *(__int16 *)(a2 + 2) + a2;
        return v6 + 4;
      default:
        return a2;
    }
LABEL_47:
    v6 = a2;
    return v6 + 4;
  }
  if ( n0x3000 != 12288 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      v8 = sub_794F80(*(unsigned __int8 *)(v2 + 24)) == 0;
      v6 = a2;
      if ( v8 )
      {
        if ( v4 )
          return *(__int16 *)(a2 + 2) + a2;
      }
      else if ( !v4 )
      {
        return *(__int16 *)(a2 + 2) + a2;
      }
      return v6 + 4;
    }
    if ( n0x3000 == 4096 )
    {
      v8 = sub_79A930(*(_DWORD *)v5, *(unsigned __int8 *)(v2 + 24), 0, 0, a1) == 1;
      v6 = a2;
      if ( v8 )
        return *(__int16 *)(a2 + 2) + a2;
      return v6 + 4;
    }
    if ( n0x3000 == 0x2000 )
    {
      v6 = a2;
      if ( *(_BYTE *)(v2 + 24) < 8u )
        return *(__int16 *)(a2 + 2) + a2;
      return v6 + 4;
    }
    return a2;
  }
  v9 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
  if ( sub_82AC50(LODWORD(v9)) )
    return a2 + 6;
  v10 = sub_7FE890(LODWORD(v9), 0, 0);
  if ( v10 < 0 )
    return a2 + 6;
  v11 = (char *)&unk_12A2280 + 32 * v10;
  n2 = sub_82AC10(LODWORD(v9));
  n2_1 = v11[22];
  if ( n2 == n2_1 )
    return a2 + 6;
  if ( n2 == 2 )
  {
    result = a2;
    if ( !n2_1 )
      result = *(__int16 *)(a2 + 2) + a2;
    v11[22] = 2;
    return result;
  }
  if ( n2 )
  {
    v11[22] = 0;
    return a2 + 6;
  }
  result = a2;
  if ( n2_1 == 2 )
    result = *(__int16 *)(a2 + 4) + a2;
  v11[22] = 0;
  return result;
}
