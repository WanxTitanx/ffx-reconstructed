// Function: sub_816340
// Address: 0x816340
int __cdecl sub_816340(int a1, int a2)
{
  int v3; // ebx
  int v4; // ecx
  float v5; // esi
  unsigned int n49152; // eax
  char *v7; // edx
  int v9; // edi
  float *v10; // esi
  __int16 n2; // ax
  unsigned __int8 v13; // cl
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  int i; // esi
  int v18; // ecx
  __int16 v19; // ax
  float v20; // [esp+Ch] [ebp-8h]
  int n0x20_1; // [esp+10h] [ebp-4h]
  int v22; // [esp+1Ch] [ebp+8h]
  BOOL v23; // [esp+1Ch] [ebp+8h]
  unsigned __int8 n0x20; // [esp+1Fh] [ebp+Bh]
  unsigned __int8 v25; // [esp+23h] [ebp+Fh]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = *(unsigned __int16 *)(a1 + 538);
  n0x20 = *(_BYTE *)(v3 + 24);
  n0x20_1 = n0x20;
  v5 = flt_12A80C0[n0x20];
  n49152 = v4 & 0xF000;
  v7 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v3 + 20);
  v20 = v5;
  if ( n49152 > 0x7000 )
  {
    if ( (v4 & 0xF000u) > 0xB000 )
    {
      if ( n49152 != 49152 && n49152 != 53248 )
        return a2;
      goto LABEL_49;
    }
    switch ( n49152 )
    {
      case 0xB000u:
        *(_DWORD *)a1 = word_C8F508[0];
        *(float *)(a1 + 4) = word_C8F50C;
        *(float *)(a1 + 8) = word_C8F510;
        *(float *)(a1 + 12) = word_C8F514[0];
        *(_DWORD *)(a1 + 16) = word_C8F508[0];
        *(float *)(a1 + 20) = word_C8F50C;
        *(float *)(a1 + 24) = word_C8F510;
        v15 = 0;
        *(float *)(a1 + 28) = word_C8F514[0];
        if ( v7[8] )
        {
          do
          {
            v16 = (unsigned __int8)v7[v15++ + 16];
            *(_BYTE *)(v16 + a1) = 1;
          }
          while ( v15 < (unsigned __int8)v7[8] );
        }
        for ( i = 0; i < 32; ++i )
        {
          if ( LODWORD(flt_12A80C0[i]) && !*(_BYTE *)(i + a1) && *(unsigned __int8 *)(v3 + 24) != i )
            FFX_BtlActor_SetEffectStateFlag_ByMode2(i, 0);
        }
        return a2 + 2;
      case 0x8000u:
        n2 = *(_WORD *)(a2 + 2);
        v13 = *(_BYTE *)(a2 + 4);
        v25 = v13;
        v14 = v13;
        if ( n2 >= 2 )
        {
          sub_82B340(LODWORD(v20), (int)*(float *)(v13 + v3));
        }
        else
        {
          v22 = sub_82B340(LODWORD(v20), n2);
          if ( v25 )
          {
            *(float *)(v14 + v3) = (float)v22;
            return a2 + 6;
          }
        }
        return a2 + 6;
      case 0x9000u:
        FFX_BtlActor_SetEffectStateFlag_ByMode2(n0x20, 1);
        return a2 + 2;
      case 0xA000u:
        FFX_BtlActor_SetEffectStateFlag_ByMode2(n0x20, 0);
        return a2 + 2;
      default:
        return a2;
    }
  }
  else
  {
    if ( n49152 == 28672 )
    {
      sub_82EBE0(LODWORD(v5), 1);
      return a2 + 2;
    }
    if ( (v4 & 0xF000u) <= 0x3000 )
    {
      if ( n49152 == 12288 )
      {
        sub_82B320(LODWORD(flt_12A80C0[(unsigned __int8)v7[24]]), 1);
        return a2 + 2;
      }
      if ( (v4 & 0xF000) != 0 && n49152 != 4096 )
      {
        if ( n49152 == 0x2000 )
        {
          sub_82B320(LODWORD(flt_12A80C0[(unsigned __int8)v7[24]]), 0);
          return a2 + 2;
        }
        return a2;
      }
LABEL_49:
      v18 = (v4 >> 12) & 1;
      if ( *(_BYTE *)(a1 + 542) && n0x20 < 0x20u )
      {
        v23 = v18 == 0;
        FFX_BtlActor_SetEffectStateFlag_ByMode2(n0x20_1, v23);
        v19 = *(_WORD *)(a1 + 538) & 0xF000;
        if ( (v19 == -16384 || v19 == -12288) && FFX_Btl_GetCurrentBattleFormationId() != 119 )
          FFX_BtlActor_ResetEffectStateFlags(*(_BYTE *)(v3 + 24), v23);
        if ( (_UNKNOWN *)sub_782A30() == &unk_1050032
          && (FFX_Btl_GetCurrentBattleFormationId() == 148 || FFX_Btl_GetCurrentBattleFormationId() == 595)
          && (*(_WORD *)(a1 + 538) & 0xF000) == 0
          && sub_826C00(LODWORD(v5)) == 2 )
        {
          dword_C64CD8 = *(unsigned __int8 *)(v3 + 24);
          FFX_BtlActor_SetEffectStateFlag_ByMode2(*(unsigned __int8 *)(v3 + 24), 0);
          return a2 + 2;
        }
      }
      else
      {
        sub_82B320(LODWORD(v5), v18);
      }
      return a2 + 2;
    }
    if ( n49152 != 0x4000 && n49152 != 20480 )
    {
      if ( n49152 == 24576 )
      {
        sub_82EBE0(LODWORD(v5), 0);
        return a2 + 2;
      }
      return a2;
    }
    if ( *(_BYTE *)(a1 + 542) )
    {
      if ( (v4 & 0x1000) != 0 )
        sub_796690(0);
      else
        sub_796690(1);
      return a2 + 2;
    }
    else
    {
      v9 = (unsigned __int16)(v4 & 0x1000) >> 12;
      v10 = flt_12A80C0;
      do
      {
        if ( *(_DWORD *)v10 )
          sub_82B320(*(_DWORD *)v10, v9);
        ++v10;
      }
      while ( (int)v10 < (int)&flt_12A8140 );
      return a2 + 2;
    }
  }
}
