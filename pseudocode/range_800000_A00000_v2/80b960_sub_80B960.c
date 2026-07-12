// Function: sub_80B960
// Address: 0x80b960
int __cdecl sub_80B960(int a1, int a2)
{
  int v2; // ebx
  int v4; // ecx
  int v5; // eax
  int i; // edi
  float *v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // esi
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // ecx
  int v17; // [esp+18h] [ebp-40h]
  float v18; // [esp+40h] [ebp-18h]
  float v19; // [esp+40h] [ebp-18h]
  _DWORD v20[4]; // [esp+44h] [ebp-14h]

  v2 = *(_DWORD *)(a1 + 544);
  v17 = v2;
  if ( *(_BYTE *)(v2 + 187) != 3 )
    return a2 + *(__int16 *)(a2 + 2);
  if ( !*(_DWORD *)(v2 + 188) )
  {
    nullsub_34();
    return a2 + 4;
  }
  v18 = *(float *)(v2 + 60) * 0.00390625;
  unk_230FD50 = v18;
  unk_230FD54 = v18;
  unk_230FD58 = v18;
  unk_230FD5C = 1.0;
  v4 = *(_DWORD *)(v2 + 188);
  if ( (byte_12A8480[*(unsigned __int8 *)(v2 + 24)] & *(_BYTE *)(v2 + 179)) != 0 )
  {
    *(_DWORD *)(v4 + 112) = 0;
    *(_DWORD *)(v4 + 116) = 0;
  }
  else
  {
    *(_WORD *)(v4 + 112) = 32 * *(unsigned __int8 *)(v2 + 200);
    *(_WORD *)(v4 + 114) = 32 * *(unsigned __int8 *)(v2 + 201);
    *(_WORD *)(v4 + 116) = 32 * *(unsigned __int8 *)(v2 + 202);
    *(_WORD *)(v4 + 118) = 32 * *(unsigned __int8 *)(v2 + 203);
  }
  v5 = *(_DWORD *)(v2 + 208) + 16 * (*(unsigned __int8 *)(v2 + 212) + 2);
  *(float *)(v4 + 64) = *(float *)(v2 + 144);
  *(float *)(v4 + 68) = *(float *)(v2 + 148);
  *(float *)(v4 + 72) = *(float *)(v2 + 152);
  *(float *)(v4 + 76) = 1.0;
  *(float *)a1 = *(float *)(v2 + 48) * 16.0;
  *(float *)(a1 + 4) = *(float *)(v2 + 52) * 16.0;
  *(float *)(a1 + 8) = 16.0 * *(float *)(v2 + 56);
  *(float *)(a1 + 12) = 1.0;
  if ( (*(_BYTE *)(v2 + 192) & 1) != 0 )
    *(float *)(a1 + 4) = -*(float *)(a1 + 4);
  unk_C8F980[0] = *(float *)a1;
  flt_C8F984 = *(_DWORD *)(a1 + 4);
  flt_C8F988 = *(_DWORD *)(a1 + 8);
  flt_C8F98C = *(_DWORD *)(a1 + 12);
  v20[0] = *(_DWORD *)a1;
  v20[1] = *(_DWORD *)(a1 + 4);
  v20[2] = *(_DWORD *)(a1 + 8);
  v20[3] = *(_DWORD *)(a1 + 12);
  for ( i = 0; i < 4; ++i )
    LODWORD(unk_C8F980[i]) = (int)*(float *)&v20[i];
  v7 = (float *)v4;
  *(float *)(v4 + 80) = unk_C8F980[0];
  *(_DWORD *)(v4 + 84) = flt_C8F984;
  *(_DWORD *)(v4 + 88) = flt_C8F988;
  *(_DWORD *)(v4 + 92) = flt_C8F98C;
  v19 = 0.00390625 * (*(float *)(v2 + 220) * *(float *)(v2 + 60));
  sub_6EDA30(v4 + 96, v5, v19);
  sub_7174F0(v7);
  v8 = sub_801E20(a1, v2);
  sub_7E7F20(&unk_230FF60, v8);
  if ( *(char *)(v2 + 25) >= 0 )
  {
    n1065353216 = *(_DWORD *)(a1 + 704);
    unk_C8F52C = *(_DWORD *)(a1 + 708);
    unk_C8F530 = *(_DWORD *)(a1 + 712);
    unk_C8F534 = *(_DWORD *)(a1 + 716);
    n3_11 = *(_DWORD *)(a1 + 720);
    unk_C8F53C = *(_DWORD *)(a1 + 724);
    unk_C8F540 = *(_DWORD *)(a1 + 728);
    unk_C8F544 = *(_DWORD *)(a1 + 732);
    unk_C8F548 = *(_DWORD *)(a1 + 736);
    unk_C8F54C = *(_DWORD *)(a1 + 740);
    unk_C8F550 = *(_DWORD *)(a1 + 744);
    v9 = *(_DWORD *)(a1 + 748);
    unk_C8F554 = v9;
    v10 = *(_DWORD *)(a1 + 752);
    MEMORY[0xC8F558] = v10;
    v11 = *(_DWORD *)(a1 + 756);
    unk_C8F55C = v11;
    v12 = *(_DWORD *)(a1 + 760);
    unk_C8F560 = v12;
    v13 = *(_DWORD *)(a1 + 764);
    unk_230FE60 = n1065353216;
    unk_230FE64 = unk_C8F52C;
    unk_230FE68 = unk_C8F530;
    unk_230FE6C = unk_C8F534;
    unk_230FE70 = n3_11;
    unk_230FE74 = unk_C8F53C;
    unk_230FE78 = unk_C8F540;
    unk_230FE7C = unk_C8F544;
    unk_230FE80 = unk_C8F548;
    unk_230FE84 = unk_C8F54C;
    v14 = unk_C8F550;
  }
  else
  {
    unk_C8F550 = unk_113FD58;
    n1065353216 = unk_113FD30;
    unk_230FE60 = unk_113FD30;
    v9 = unk_113FD5C;
    v10 = unk_113FD60;
    v11 = unk_113FD64;
    v12 = unk_113FD68;
    unk_C8F52C = unk_113FD34;
    unk_230FE64 = unk_113FD34;
    unk_C8F530 = unk_113FD38;
    unk_230FE68 = unk_113FD38;
    unk_C8F534 = unk_113FD3C;
    unk_230FE6C = unk_113FD3C;
    n3_11 = unk_113FD40;
    unk_230FE70 = unk_113FD40;
    unk_C8F53C = unk_113FD44;
    unk_230FE74 = unk_113FD44;
    unk_C8F540 = unk_113FD48;
    unk_230FE78 = unk_113FD48;
    unk_C8F544 = unk_113FD4C;
    unk_230FE7C = unk_113FD4C;
    unk_C8F548 = unk_113FD50;
    unk_230FE80 = unk_113FD50;
    unk_C8F54C = unk_113FD54;
    v13 = unk_113FD6C;
    unk_230FE84 = unk_113FD54;
    v14 = unk_113FD58;
    unk_C8F554 = unk_113FD5C;
    MEMORY[0xC8F558] = unk_113FD60;
    unk_C8F55C = unk_113FD64;
    unk_C8F560 = unk_113FD68;
  }
  unk_230FE9C = v13;
  unk_230FE98 = v12;
  unk_230FE94 = v11;
  unk_230FE90 = v10;
  unk_230FE8C = v9;
  unk_230FE88 = v14;
  unk_C8F564 = v13;
  sub_6ED700(&unk_230FF20, &unk_230FF60, &unk_230FFA0);
  sub_6ED4A0(&unk_230FE20, &unk_230FF20);
  v15 = unk_2332E80;
  if ( (*(_BYTE *)(v17 + 178) & 1) == 0 )
    v15 = *(_DWORD *)(a1 + 852);
  unk_230FD2C = v15;
  v16 = (*(char (__cdecl **)(_DWORD))(*(_DWORD *)(a1 + 848) + 72))(*(_DWORD *)(a1 + 544));
  if ( (*(_BYTE *)(v17 + 178) & 1) != 0 )
    unk_2332E80 = unk_230FD2C;
  else
    *(_DWORD *)(a1 + 852) = unk_230FD2C;
  if ( v16 )
    return a2 + *(__int16 *)(a2 + 2);
  else
    return a2 + 4;
}
