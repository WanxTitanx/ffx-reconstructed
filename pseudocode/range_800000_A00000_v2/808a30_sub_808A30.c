// Function: sub_808A30
// Address: 0x808a30
int __cdecl sub_808A30(int a1, int a2)
{
  int v2; // ecx
  int v3; // edi
  float v4; // ecx
  int n20480; // eax
  int v7; // eax
  __int16 v8; // si
  int v9; // edi
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  int v12; // edi
  unsigned int v13; // edx
  int v14; // [esp+8h] [ebp-8h] BYREF
  int v15; // [esp+Ch] [ebp-4h] BYREF
  float v16; // [esp+18h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v2 + 30) + 864);
  v4 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
  n20480 = *(_WORD *)(a1 + 538) & 0xF000;
  v16 = v4;
  if ( n20480 > 0x2000 )
  {
    if ( n20480 == 0x4000 )
    {
      v8 = *(_WORD *)(a2 + 2);
      v9 = sub_7E3720(v3, 9, *(__int16 *)(a2 + 4));
      v10 = (_DWORD *)sub_83CD50(LODWORD(v16), v8, &v15, &v14);
      v11 = v10;
      if ( v14 * v15 > 0 )
      {
        v12 = v9 - (_DWORD)v10;
        v13 = ((unsigned int)(v14 * v15 - 1) >> 4) + 1;
        do
        {
          *v11 = *(_DWORD *)((char *)v11 + v12);
          v11[1] = *(_DWORD *)((char *)v11 + v12 + 4);
          v11[2] = *(_DWORD *)((char *)v11 + v12 + 8);
          v11[3] = *(_DWORD *)((char *)v11 + v12 + 12);
          v11 += 4;
          --v13;
        }
        while ( v13 );
      }
      if ( FFX_Btl_GetCurrentBattleFormationId() >= 630 && FFX_Btl_GetCurrentBattleFormationId() <= 637 )
        sub_63D5B0(LODWORD(v16));
      return a2 + 6;
    }
    else
    {
      if ( n20480 != 20480 )
        return a2;
      sub_830D90(LODWORD(v4), 0);
      return a2 + 2;
    }
  }
  else if ( n20480 == 0x2000 )
  {
    sub_7FEFB0(0);
    return a2 + 2;
  }
  else
  {
    if ( n20480 )
    {
      if ( n20480 == 4096 )
      {
        sub_7FEFB0(1);
        return a2 + 2;
      }
      return a2;
    }
    v7 = sub_7E3720(v3, 2, *(__int16 *)(a2 + 2));
    sub_7E4F40(v7, 1);
    return a2 + 4;
  }
}
