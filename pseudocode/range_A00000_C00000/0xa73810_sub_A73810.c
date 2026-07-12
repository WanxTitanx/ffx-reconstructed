// Function: sub_A73810
// Address: 0xa73810
// Size: 0x40b
// Prototype: 

int __cdecl sub_A73810(int a1, _DWORD *a2)
{
  int v2; // edi
  int v3; // ebx
  float v4; // ecx
  int v5; // eax
  int v6; // eax
  __int16 *v7; // esi
  double v8; // st7
  int v9; // ebx
  int v10; // edi
  int v11; // esi
  _DWORD *v12; // esi
  int v13; // edx
  int v14; // esi
  int v15; // eax
  unsigned int n2622_2; // esi
  float v17; // eax
  int v18; // ecx
  int v19; // eax
  float *v20; // esi
  int v21; // eax
  double v22; // st7
  bool v23; // cc
  float v24; // ecx
  __int64 v26; // [esp+8h] [ebp-3Ch]
  float v27; // [esp+8h] [ebp-3Ch]
  __int64 n2622_1; // [esp+1Ch] [ebp-28h] BYREF
  float v29; // [esp+24h] [ebp-20h]
  unsigned __int16 *v30; // [esp+2Ch] [ebp-18h]
  float v31; // [esp+30h] [ebp-14h]
  int v32; // [esp+34h] [ebp-10h]
  int v33; // [esp+38h] [ebp-Ch]
  __int64 n2622; // [esp+3Ch] [ebp-8h]
  int v35; // [esp+4Ch] [ebp+8h]

  v2 = a1;
  v3 = *(_DWORD *)(a1 + 544);
  HIDWORD(n2622_1) = v3;
  v30 = *(unsigned __int16 **)(v3 + 168);
  LODWORD(v4) = *v30;
  v31 = v4;
  if ( unk_12FB790 )
  {
    n2622 = n2622_1;
    v5 = (int)a2;
  }
  else
  {
    HIDWORD(v26) = v3;
    LODWORD(v26) = 0;
    LODWORD(n2622) = 0;
    HIDWORD(n2622) = v3;
    v5 = sub_645580(v26);
    v4 = v31;
  }
  v33 = v5;
  if ( LOWORD(v4) )
    v6 = sub_800F80(a2, v3, LODWORD(v4));
  else
    v6 = *(_DWORD *)(a1 + 544);
  v7 = *(__int16 **)(v6 + 188);
  v29 = 1.0 / *(float *)(v3 + 72);
  v31 = 0.0;
  v8 = *(float *)(v3 + 64);
  v32 = (int)v8;
  if ( (int)v8 > 0 )
  {
    v9 = (int)v8;
    v10 = a2[10];
    do
    {
      sub_7EA030(v10, v31, *((_DWORD *)v7 + 2), *((_DWORD *)v7 + 3), *v7);
      v10 += 16;
      v31 = v31 + v29;
      --v9;
    }
    while ( v9 );
    v2 = a1;
    v3 = HIDWORD(n2622_1);
  }
  v11 = sub_800F80(a2, v3, *(unsigned __int16 *)(v3 + 184));
  sub_7EA610((void *)(v2 + 192), 1.0);
  sub_7E9760(v2 + 192, v2 + 192, v11 + 48, v11 + 144);
  v12 = a2;
  v31 = COERCE_FLOAT(sub_800F80(a2, v3, v30[2]));
  if ( LODWORD(v31) != a2[8] )
  {
    v13 = sub_7E3720(a2[*(unsigned __int8 *)(v3 + 30) + 24], 4, (__int16)v30[1]);
    v35 = v13 + *(__int16 *)(v13 + 16);
    *(_WORD *)(v2 + 2) = 128;
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(v3 + 200);
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 28) = v2 + 128;
    *(_DWORD *)(v2 + 16) = v2 + 128;
    *(_DWORD *)(v2 + 20) = a2[21];
    if ( !unk_12FB790 )
    {
      v14 = v33;
      HIDWORD(n2622_1) = unknown_libname_742(v13);
      if ( !v33 )
      {
        v15 = FFX_MagicHost_ClassifyPppOpcodeByte(*(unsigned __int8 *)(*(_DWORD *)(v35 + 4) + v35 + 4));
        n2622_2 = n2622;
        sub_7114B0(n2622, HIDWORD(n2622), (char *)&n2622_1 + 4, v32, v15);
        v14 = sub_645580(__SPAIR64__(HIDWORD(n2622), n2622_2));
        v33 = v14;
      }
      sub_713370(n2622, HIDWORD(n2622));
      if ( v14 )
      {
        *(_DWORD *)(*(_DWORD *)(v14 + 148) + 8) = 6 * v32 * *(__int16 *)(v35 + 2);
        *(_DWORD *)(*(_DWORD *)(v14 + 148) + 4) = 4 * v32 * *(__int16 *)(v35 + 2);
        if ( !sub_63FF60(v14, 0, *(_DWORD *)(*(_DWORD *)(v14 + 148) + 4), *(_DWORD *)(*(_DWORD *)(v14 + 148) + 8)) )
          return 0;
        memset(*(void **)(*(_DWORD *)(v14 + 148) + 28), 0, 2 * *(_DWORD *)(*(_DWORD *)(v14 + 148) + 8));
      }
      sub_713370(n2622, HIDWORD(n2622));
      v12 = a2;
    }
    v17 = COERCE_FLOAT(sub_801E20(v2, v3));
    v18 = *(unsigned __int8 *)(v3 + 23);
    v29 = v17;
    v19 = v32;
    *(_BYTE *)(v3 + 22) = 16;
    if ( v18 < v19 )
      *(_BYTE *)(v3 + 23) = v19;
    v20 = (float *)v12[10];
    v30 = 0;
    if ( v19 <= 0 )
    {
LABEL_28:
      v24 = v31;
      v20 -= 4;
    }
    else
    {
      v21 = v2 + 176;
      while ( 1 )
      {
        v20[3] = 1.0;
        sub_6ED420(v21, v2 + 192, v20);
        if ( *(float *)(v3 + 148) < (double)*(float *)(v2 + 180) )
          break;
        v27 = v29;
        *((float *)&n2622_1 + 1) = *(float *)(v3 + 60) * 0.000244140625;
        *(float *)(v2 + 140) = 0.0;
        *(float *)(v2 + 136) = 0.0;
        *(float *)(v2 + 132) = 0.0;
        *(float *)(v2 + 156) = 0.0;
        *(float *)(v2 + 152) = 0.0;
        *(float *)(v2 + 144) = 0.0;
        *(float *)(v2 + 172) = 0.0;
        *(float *)(v2 + 164) = 0.0;
        *(float *)(v2 + 160) = 0.0;
        *(float *)(v2 + 184) = 0.0;
        *(float *)(v2 + 180) = 0.0;
        *(float *)(v2 + 176) = 0.0;
        v22 = *((float *)&n2622_1 + 1);
        *(float *)(v2 + 168) = *((float *)&n2622_1 + 1);
        *(float *)(v2 + 148) = v22;
        *(float *)(v2 + 128) = v22;
        *(float *)(v2 + 188) = 1.0;
        sub_6ED420(v2 + 176, LODWORD(v27), v20);
        if ( !unk_12FB790 && v33 )
          sub_71A5C0(n2622, HIDWORD(n2622), v35, v2);
        v20 += 4;
        v23 = (int)v30 + 1 < v32;
        v30 = (unsigned __int16 *)((char *)v30 + 1);
        v21 = v2 + 176;
        if ( !v23 )
          goto LABEL_28;
      }
      v24 = v31;
      *(_WORD *)(v3 + 176) |= 0x1000u;
      *(_WORD *)(LODWORD(v24) + 176) |= 0x1000u;
    }
    *(float *)(LODWORD(v24) + 144) = *v20;
    *(float *)(LODWORD(v24) + 148) = v20[1];
    *(float *)(LODWORD(v24) + 152) = v20[2];
    sub_7EA760(LODWORD(v24) + 64, LODWORD(v24) + 144, 16.0);
    a2[21] = *(_DWORD *)(v2 + 20);
    if ( !unk_12FB790 && v33 )
      FFX_MagicHost_CommitDrawableResources(n2622);
  }
  return 0;
}

