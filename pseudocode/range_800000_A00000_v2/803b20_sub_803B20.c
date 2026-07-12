// Function: sub_803B20
// Address: 0x803b20
__int16 *__cdecl sub_803B20(int a1, __int16 *a2)
{
  int v3; // edx
  _WORD *v4; // ecx
  int v5; // ebx
  int v6; // esi
  unsigned int n20480; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edi
  double v11; // st7
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  double v17; // st7
  int v18; // eax
  int v19; // esi
  int *v20; // eax
  int *v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // [esp-4h] [ebp-38h]
  int v25; // [esp+4h] [ebp-30h]
  float v26; // [esp+Ch] [ebp-28h]
  int v27; // [esp+Ch] [ebp-28h]
  int v28; // [esp+Ch] [ebp-28h]
  int v29; // [esp+Ch] [ebp-28h]
  int v30; // [esp+24h] [ebp-10h]
  int v31; // [esp+28h] [ebp-Ch]
  int v32; // [esp+2Ch] [ebp-8h]
  int v33; // [esp+2Ch] [ebp-8h]
  int v34; // [esp+30h] [ebp-4h]
  int v35; // [esp+30h] [ebp-4h]
  int *v36; // [esp+30h] [ebp-4h]
  float v37; // [esp+3Ch] [ebp+8h]
  int n2; // [esp+3Ch] [ebp+8h]
  int v39; // [esp+3Ch] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = (_WORD *)(a1 + 768);
  v34 = v3;
  v5 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v3 + 30) + 864);
  v6 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]);
  n20480 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n20480 > 0x4000 )
  {
    if ( n20480 == 20480 )
    {
      sub_831380(v6, -1);
      sub_831250(v6, -1);
      return a2 + 1;
    }
    if ( n20480 != 24576 )
      return a2;
    n1065353216 = *(_DWORD *)(v3 + 48);
    v30 = a1 + 256;
    unk_C8F52C = *(_DWORD *)(v3 + 52);
    unk_C8F530 = *(_DWORD *)(v3 + 56);
    unk_C8F534 = *(_DWORD *)(v3 + 60);
    *(_DWORD *)a1 = n1065353216;
    *(_DWORD *)(a1 + 4) = unk_C8F52C;
    *(_DWORD *)(a1 + 8) = unk_C8F530;
    *(_DWORD *)(a1 + 12) = unk_C8F534;
    v39 = a1 + 128;
    v33 = a1 + 192;
    if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
      v17 = *(float *)(v3 + 204);
    else
      v17 = 0.0;
    v18 = *(char *)(a1 + 542);
    *(float *)a1 = v17;
    sub_8061E0(a1 + 128, *(unsigned __int8 *)(v3 + 24), *(float *)(v3 + 60), a1, v3 + 144, v18);
    v19 = v34;
    v31 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v34);
    sub_7E82C0(a1 + 192, v31, a1 + 128);
    sub_7E82C0(a1 + 192, a1 + 704, a1 + 192);
    v28 = a2[1];
    v25 = a1 + 768;
    v24 = a1 + 256;
    if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
      v20 = (int *)sub_80E390(v24, a1, v25, v34, v28);
    else
      v20 = (int *)sub_80E2C0(v24, a1, v25, v34, v28);
    *(_DWORD *)(a1 + 256) |= 0x40u;
    v36 = v20;
    sub_80EA60(v30, a1, a1 + 768, v19, a2 + 1);
    v21 = &v36[4 * (int)*(float *)(a2[6] + v19) + 4];
    *(_DWORD *)(v30 + 32) = v33;
    *(_DWORD *)(v30 + 44) = v39;
    v22 = unknown_libname_741(v21[1]);
    sub_7E82C0(v39, v39, v22);
    sub_7E82C0(v33, v31, v39);
    sub_7E82C0(v33, a1 + 704, v33);
    v29 = *v36;
    v23 = unknown_libname_741(*v21);
    sub_A6A3A0(v23, v30, v29);
    return a2 + 7;
  }
  else
  {
    if ( n20480 == 0x4000 )
    {
      sub_831440(v6, -1, -1);
      sub_831410(v6, -1, -1);
      sub_83C890(v6);
      return a2 + 1;
    }
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    {
      if ( n20480 != 4096 )
      {
        if ( n20480 == 0x2000 )
        {
          n1065353216 = *(_DWORD *)(v3 + 48);
          unk_C8F52C = *(_DWORD *)(v3 + 52);
          unk_C8F530 = *(_DWORD *)(v3 + 56);
          unk_C8F534 = *(_DWORD *)(v3 + 60);
          *(_DWORD *)a1 = n1065353216;
          *(_DWORD *)(a1 + 4) = unk_C8F52C;
          *(_DWORD *)(a1 + 8) = unk_C8F530;
          *(_DWORD *)(a1 + 12) = unk_C8F534;
          *(float *)a1 = 0.0;
          sub_8061E0(a1 + 128, *(unsigned __int8 *)(v3 + 24), *(float *)(v3 + 60), a1, v3 + 144, *(char *)(a1 + 542));
          v8 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v34);
          sub_7E82C0(a1 + 192, v8, a1 + 128);
          sub_7E82C0(a1 + 192, a1 + 704, a1 + 192);
          v9 = sub_80E2C0(a1 + 256, a1, a1 + 768, v34, a2[1]);
          *(_DWORD *)(a1 + 256) |= 0x40u;
          v10 = v9;
          sub_80EA60(a1 + 256, a1, a1 + 768, v34, a2 + 1);
          sub_8040E0(a1 + 256);
          *(_DWORD *)(a1 + 852) = sub_A68C90(v10, a1 + 256, a1 + 128, a1 + 640);
          v37 = (double)*(unsigned __int8 *)(v34 + 203) * 0.0078125;
          v11 = v37;
          if ( v37 < 0.00009999999747378752 )
            v11 = (float)0.000099999997;
          v26 = v11;
          sub_63B9D0(*(_DWORD *)(v6 + 2096), *(unsigned __int16 *)v6, v26);
          return a2 + 6;
        }
        return a2;
      }
      sub_8060C0(v5, v6, *(_DWORD *)(a1 + 936), *v4 == 1);
      v13 = sub_804070(v6);
      if ( (v13 & 1) != 0 )
        sub_82B2E0(v6, 1);
      if ( (v13 & 2) != 0 )
        sub_82B340(v6, 1);
      if ( v13 )
      {
        v14 = sub_826BF0(v6);
        sub_63C550(v14, 0);
      }
      return a2 + 2;
    }
    else
    {
      sub_8060C0(v5, v6, *(_DWORD *)(a1 + 936), *v4 == 1);
      n2 = a2[2];
      sub_831440(v6, -1, 15360);
      sub_831410(v6, -1, 12000);
      v15 = sub_8036E0(v6, n2, 1);
      if ( !v15 )
        return a2 + 3;
      v32 = sub_7FF6A0(*(_DWORD *)(a1 + 936), v15);
      v35 = a2[1];
      sub_7E37B0(v5, 4, v35, v32);
      v27 = *(_DWORD *)(a1 + 808);
      if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
        sub_803140(v32, v6, n2, v27);
      else
        sub_803280(v32, v6, n2, v27);
      v16 = (char *)&unk_12A2280 + 32 * sub_7FE890(v6, 0, 0);
      if ( (*(_WORD *)(a1 + 538) & 0x400) == 0 )
      {
        if ( *(_WORD *)(a1 + 768) != 1 )
        {
          v16[20] = v35;
          return a2 + 3;
        }
        v16[21] = v35;
      }
      return a2 + 3;
    }
  }
}
