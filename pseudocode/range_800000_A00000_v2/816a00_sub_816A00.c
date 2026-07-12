// Function: sub_816A00
// Address: 0x816a00
int __cdecl sub_816A00(int a1, int a2)
{
  int v2; // ebx
  unsigned int n0x8000; // eax
  int v4; // edx
  __int16 v5; // cx
  int v6; // edi
  bool v7; // zf
  int v8; // eax
  int v10; // esi
  __int16 v11; // si
  __int16 v12; // si
  int BattleModeContext; // eax
  int BattleModeContext_1; // edx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int n1024; // eax
  bool v19; // c0
  bool v20; // c3
  int v21; // eax
  double v22; // st7
  unsigned __int8 v23; // al
  float v24; // [esp+Ch] [ebp-18h]
  float v25; // [esp+Ch] [ebp-18h]
  float v26; // [esp+Ch] [ebp-18h]
  float v27; // [esp+Ch] [ebp-18h]
  float v28; // [esp+14h] [ebp-10h]
  float v29; // [esp+18h] [ebp-Ch]

  v2 = *(_DWORD *)(a1 + 544);
  n0x8000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n0x8000 <= 0x8000 )
  {
    if ( n0x8000 == 0x8000 )
      goto LABEL_39;
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0x4000 )
    {
      if ( n0x8000 != 0x4000 )
      {
        if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0x2000 )
        {
          if ( n0x8000 == 0x2000 )
          {
LABEL_9:
            v4 = sub_787CA0();
            if ( unk_2322790 )
            {
              v5 = *(_WORD *)(a1 + 952);
              if ( v5 )
                v4 = v5;
            }
            v6 = a2;
            v7 = v4 == *(__int16 *)(a2 + 2);
LABEL_13:
            if ( v7 )
            {
LABEL_14:
              v8 = *(__int16 *)(v6 + 4);
              return v8 + v6;
            }
            return v6 + 6;
          }
          if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
          {
            if ( n0x8000 == 4096 )
              goto LABEL_9;
            return a2;
          }
          v6 = a2;
          v10 = *(__int16 *)(a2 + 2);
          if ( v10 > sub_7E5C60(256) )
            goto LABEL_14;
          return v6 + 6;
        }
        if ( n0x8000 == 12288 )
        {
          v6 = a2;
          if ( *(_BYTE *)(a1 + 542) )
          {
            v11 = *(_WORD *)(a2 + 2);
            if ( sub_794DC0(*(unsigned __int8 *)(v2 + 24)) )
            {
              v8 = v11;
              return v8 + v6;
            }
          }
          return v6 + 4;
        }
        return a2;
      }
      v6 = a2;
      if ( *(_BYTE *)(a1 + 542) )
      {
        v12 = *(_WORD *)(a2 + 2);
        if ( sub_794D80(*(unsigned __int8 *)(v2 + 24)) )
        {
          v8 = v12;
          return v8 + v6;
        }
      }
      return v6 + 4;
    }
    switch ( n0x8000 )
    {
      case 0x5000u:
        BattleModeContext = sub_908F40();
        break;
      case 0x6000u:
        if ( !*(_BYTE *)(a1 + 542) )
        {
          BattleModeContext_1 = 0;
          goto LABEL_34;
        }
        BattleModeContext = FFX_Btl_Hp_GetBattleModeContext();
        break;
      case 0x7000u:
LABEL_39:
        v15 = sub_7FE890(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]), 0, 0);
        v6 = a2;
        v16 = *(__int16 *)(a2 + 2);
        v17 = *((_DWORD *)&unk_12A2284 + 8 * v15);
        if ( (*(_WORD *)(a1 + 538) & 0x1000) != 0 )
        {
          v7 = v17 == v16;
          goto LABEL_13;
        }
        if ( v17 != v16 )
          goto LABEL_14;
        return v6 + 6;
      default:
        return a2;
    }
    BattleModeContext_1 = BattleModeContext;
LABEL_34:
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
    {
      if ( BattleModeContext_1 != *(unsigned __int16 *)(a2 + 2) + (*(unsigned __int16 *)(a2 + 4) << 16) )
        return *(__int16 *)(a2 + 6) + a2;
    }
    else if ( BattleModeContext_1 == *(unsigned __int16 *)(a2 + 2) + (*(unsigned __int16 *)(a2 + 4) << 16) )
    {
      return *(__int16 *)(a2 + 6) + a2;
    }
    return a2 + 8;
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0xC000 )
  {
    if ( n0x8000 == 49152 )
    {
      v27 = sub_836120();
      sub_835570(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]), 1, a1);
      v22 = *(float *)(a1 + 4);
      v19 = v27 < v22;
      v20 = v27 == v22;
LABEL_52:
      v6 = a2;
      if ( v19 || v20 )
      {
        v8 = *(__int16 *)(a2 + 2);
        return v8 + v6;
      }
      return v6 + 4;
    }
    if ( n0x8000 == 36864 )
    {
      v21 = sub_794250(*(unsigned __int8 *)(v2 + 24));
      v6 = a2;
      if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      {
        if ( v21 )
        {
          v8 = *(__int16 *)(a2 + 2);
          return v8 + v6;
        }
      }
      else if ( !v21 )
      {
        v8 = *(__int16 *)(a2 + 2);
        return v8 + v6;
      }
      return v6 + 4;
    }
    if ( n0x8000 != 40960 )
    {
      if ( n0x8000 != 45056 )
        return a2;
      sub_834080(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]), a1);
      word_C8F980[0] = *(float *)a1;
      flt_C8F984 = *(float *)(a1 + 4);
      flt_C8F988 = *(float *)(a1 + 8);
      flt_C8F98C[0] = *(float *)(a1 + 12);
      v28 = *(float *)(a1 + 4);
      v29 = *(float *)(a1 + 8);
      word_C8F980[0] = *(float *)a1 * word_C8F980[0];
      flt_C8F984 = v28 * flt_C8F984;
      flt_C8F988 = v29 * flt_C8F988;
      word_C8F980[0] = flt_C8F984 + word_C8F980[0];
      word_C8F980[0] = flt_C8F988 + word_C8F980[0];
      v24 = fabs(word_C8F980[0]);
      v25 = sqrt(v24);
      unk_C8F788 = v25;
      word_C8F980[0] = flt_C0A004 + v25;
      *(float *)(a1 + 16) = word_C8F980[0];
      *(float *)(a1 + 20) = flt_C8F984;
      *(float *)(a1 + 24) = flt_C8F988;
      *(float *)(a1 + 28) = flt_C8F98C[0];
      v26 = *(float *)(a1 + 16);
      n1024 = *(_WORD *)(a1 + 538) & 0xF00;
      if ( (*(_WORD *)(a1 + 538) & 0xF00) == 0 )
      {
        v6 = a2;
        if ( v26 < 0.4000000059604645 )
        {
          v8 = *(__int16 *)(a2 + 2);
          return v8 + v6;
        }
        return v6 + 4;
      }
      if ( n1024 != 512 )
      {
        if ( n1024 != 1024 )
          return a2;
        v19 = v26 > 1.2;
        v20 = 1.2 == v26;
        goto LABEL_52;
      }
      if ( v26 >= 0.4000000059604645 && v26 < 1.2 )
      {
LABEL_56:
        v6 = a2;
        v8 = *(__int16 *)(a2 + 2);
        return v8 + v6;
      }
LABEL_87:
      v6 = a2;
      return v6 + 4;
    }
    if ( unk_2322790 )
    {
      if ( unk_11A004A )
      {
        if ( (unk_2321580 & 0x10) == 0 )
          return a2 + 2;
      }
      else if ( (unk_2321580 & 1) == 0 )
      {
        return a2 + 2;
      }
      if ( byte_12A1350[0] >= 0 || (byte_12A1350[0] & 0x20) == 0 )
      {
        *(_BYTE *)(a1 + 528) = 1;
        return a2;
      }
    }
    return a2 + 2;
  }
  if ( n0x8000 == 53248 )
  {
    v23 = byte_12A8480[*(unsigned __int8 *)(v2 + 24)];
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
    {
      v6 = a2;
      if ( (v23 & *(_BYTE *)(v2 + 179)) == 0 )
        return *(__int16 *)(a2 + 2) + a2;
      return v6 + 4;
    }
    if ( (v23 & *(_BYTE *)(v2 + 179)) != 0 )
      goto LABEL_56;
    goto LABEL_87;
  }
  if ( n0x8000 != 57344 )
  {
    if ( n0x8000 == 61440 )
    {
      v6 = a2;
      if ( unk_2322790 )
      {
        if ( (*(_WORD *)(a1 + 538) & 0x800) == 0 )
        {
          v8 = *(__int16 *)(a2 + 2);
          return v8 + v6;
        }
      }
      else if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      {
        return *(__int16 *)(a2 + 2) + a2;
      }
      return v6 + 4;
    }
    return a2;
  }
  v6 = a2;
  if ( *((_BYTE *)&unk_12A40D8 + 32 * *(unsigned __int16 *)(v2 + 20)) == *(_BYTE *)(v2 + 24) )
  {
    v8 = *(__int16 *)(a2 + 2);
    return v8 + v6;
  }
  return v6 + 4;
}
