// Function: sub_808710
// Address: 0x808710
int __cdecl sub_808710(int a1, int a2)
{
  int v2; // ebx
  int v3; // edx
  int v4; // edi
  __int16 v5; // cx
  unsigned int v6; // esi
  int n12288; // ecx
  int v8; // esi
  int v9; // eax
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  int v12; // esi
  int v13; // edi
  int v14; // eax
  _DWORD *i; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // edi
  char v20; // al
  int n2; // edx
  int v22; // esi
  int v23; // eax
  _DWORD *i_1; // eax
  int v25; // [esp+Ch] [ebp-18h]
  int v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  int v28; // [esp+1Ch] [ebp-8h]
  __int16 v29; // [esp+20h] [ebp-4h]
  int v30; // [esp+2Ch] [ebp+8h]

  v2 = a2;
  v3 = *(unsigned __int16 *)(a2 + 2);
  v29 = *(_WORD *)(a2 + 2);
  v4 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(*(_DWORD *)(a1 + 544) + 30) + 864);
  v5 = *(_WORD *)(a1 + 538);
  v6 = (v5 & 0x800) != 0 ? 0x80000008 : 0;
  n12288 = v5 & 0xF000;
  v8 = v6 + 0x80000000;
  v25 = v4;
  if ( n12288 > 12288 )
  {
    switch ( n12288 )
    {
      case 16384:
        sub_7E4740(v4, v3, *(unsigned __int16 *)(a2 + 4), v8);
        return a2 + 6;
      case 20480:
        v22 = (__int16)v3;
        v23 = sub_7E3720(v4, 2, (__int16)v3);
        sub_7E4F40(v23, 1);
        i_1 = (_DWORD *)sub_7E3720(v4, 3, v22);
        sub_7E45C0(i_1);
        return a2 + 4;
      case 24576:
        FFX_GpuCleanup_ReleaseSlotByFlag(v8);
        return a2 + 2;
    }
    return v2;
  }
  if ( n12288 == 12288 )
  {
LABEL_28:
    if ( sub_7E45E0(v8) )
    {
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    }
    return a2 + 2;
  }
  if ( !n12288 )
  {
    sub_7E4740(v4, v3, v3, v8);
    return a2 + 4;
  }
  if ( n12288 != 4096 )
  {
    if ( n12288 == 0x2000 )
    {
      v9 = sub_800DA0(v4);
      v28 = v9;
      if ( v9 >= 0 )
      {
        if ( *((char *)&unk_119FED0 + v9) < 0 )
          return a2 + 4;
        v10 = sub_800D70(v9);
        v27 = v10;
        if ( v10 )
        {
          v11 = sub_800D40(v28);
          v26 = v11;
          if ( v11 )
          {
            v30 = sub_7E3720(v4, 2, v29);
            v12 = v30;
            v13 = sub_7E3720(v4, 3, v29);
            if ( !*(_BYTE *)(v30 + 31) )
            {
              sub_7E4F00(v30, v27);
              sub_7E44F0(v13, v26);
              sub_7E3D80(v25);
              v2 = a2;
              v12 = v30;
            }
            v14 = 0;
            for ( i = &dword_119FEF0[2 * v28]; *i; ++i )
            {
              if ( ++v14 >= 2 )
                return v2 + 4;
            }
            v17 = v14 + 2 * v28;
            dword_119FEF0[v17] = v12;
            dword_119FF30[v17] = v13;
            return v2 + 4;
          }
        }
      }
      goto LABEL_22;
    }
    return v2;
  }
  v18 = sub_800DA0(v4);
  v19 = v18;
  if ( v18 < 0 )
  {
LABEL_22:
    if ( unk_2322790 )
    {
      nullsub_34();
      return a2 + 4;
    }
    nullsub_34();
    nullsub_35(1);
    goto LABEL_28;
  }
  if ( !*((_BYTE *)&unk_119FED0 + v18) )
  {
    v20 = byte_C48E60[v29];
    n2 = 0;
    while ( ((unsigned __int8)v20
           & (unsigned __int8)(unk_119FED7
                             | unk_119FED6
                             | unk_119FED5
                             | unk_119FED4
                             | unk_119FED3
                             | unk_119FED2
                             | unk_119FED1
                             | unk_119FED0)) != 0 )
    {
      ++n2;
      v20 *= 2;
      if ( n2 >= 2 )
        goto LABEL_22;
    }
    *((_BYTE *)&unk_119FED0 + v19) = v20;
    dword_119FEF0[2 * v19] = 0;
    dword_119FEF4[2 * v19] = 0;
    dword_119FF30[2 * v19] = 0;
    dword_119FF34[2 * v19] = 0;
  }
  return a2 + 4;
}
