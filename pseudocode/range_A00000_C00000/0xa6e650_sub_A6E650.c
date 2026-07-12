// Function: sub_A6E650
// Address: 0xa6e650
// Size: 0x6e3
// Prototype: 

int __cdecl sub_A6E650(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // edi
  BOOL v8; // eax
  int result; // eax
  int v10; // esi
  int v11; // eax
  int v12; // edx
  double v13; // st6
  double v14; // st3
  double v15; // st2
  double v16; // st2
  double v17; // st5
  int v18; // ecx
  double v19; // st4
  double v20; // st6
  double v21; // st5
  double v22; // st6
  double v23; // st6
  double v24; // st6
  double v25; // st6
  double v26; // st6
  bool v27; // zf
  int v28; // esi
  int v29; // eax
  const char *_13476_19_0_0_512_512.dds.phyre; // esi
  const char *v31; // esi
  int v32; // ecx
  char v33; // al
  int dst_1; // eax
  _DWORD *dst; // ebx
  int v36; // ecx
  int v37; // eax
  int v38; // eax
  int v39; // edi
  unsigned int v40; // esi
  int v41; // [esp+4h] [ebp-270h] BYREF
  double v42; // [esp+8h] [ebp-26Ch]
  int v43; // [esp+10h] [ebp-264h] BYREF
  int v44; // [esp+14h] [ebp-260h] BYREF
  int v45; // [esp+18h] [ebp-25Ch]
  BOOL v46; // [esp+1Ch] [ebp-258h]
  int v47; // [esp+20h] [ebp-254h]
  int v48; // [esp+24h] [ebp-250h]
  int v49; // [esp+28h] [ebp-24Ch]
  int v50; // [esp+2Ch] [ebp-248h]
  double v51; // [esp+30h] [ebp-244h]
  double v52; // [esp+38h] [ebp-23Ch]
  float v53[4]; // [esp+40h] [ebp-234h] BYREF
  float v54[4]; // [esp+50h] [ebp-224h] BYREF
  float v55[4]; // [esp+60h] [ebp-214h] BYREF
  _BYTE v56[256]; // [esp+70h] [ebp-204h] BYREF
  char Source[28]; // [esp+170h] [ebp-104h] BYREF
  __int16 v58; // [esp+18Ch] [ebp-E8h]
  char v59; // [esp+18Eh] [ebp-E6h]

  v47 = a1;
  v49 = a2;
  HIDWORD(v51) = *(unsigned __int8 *)(a2 + 76);
  v42 = (double)SHIDWORD(v51);
  v7 = (a7 >> 31) + 437;
  *((float *)&v52 + 1) = v42 * 0.0078125;
  v48 = a7;
  HIDWORD(v42) = a7;
  v45 = v7;
  v8 = sub_645580(a7 + 0x1B500000000LL) == 0;
  v46 = v8;
  if ( unk_12FB790 && !v8 )
    return a6;
  v10 = sub_7E6910(6144);
  v49 = sub_A69940(v47, v49, v10);
  v11 = sub_A68FF0();
  v12 = v49;
  v50 = v11;
  *((float *)&v51 + 1) = (double)*(unsigned __int8 *)(v49 + 76) * 0.0078125;
  v13 = *((float *)&v51 + 1);
  v51 = (double)(unsigned __int8)v11;
  v14 = v51;
  v51 = (double)*(unsigned __int8 *)(v49 + 28);
  *(float *)(v10 + 880) = v13 * v14 + v51 * (1.0 - v13);
  v15 = (double)*(unsigned __int8 *)(v12 + 29) * (1.0 - v13);
  v51 = (double)BYTE1(v50);
  *(float *)(v10 + 884) = v15 + v51 * v13;
  v16 = (double)*(unsigned __int8 *)(v12 + 30) * (1.0 - v13);
  v51 = (double)BYTE2(v50);
  *(float *)(v10 + 888) = v16 + v51 * v13;
  v17 = (1.0 - v13) * (double)*(unsigned __int8 *)(v12 + 31);
  v51 = (double)HIBYTE(v50);
  v18 = v47;
  *(float *)(v10 + 892) = v13 * v51 + v17;
  v19 = *((float *)&v52 + 1);
  v20 = 1.0 - *((float *)&v52 + 1);
  *(_DWORD *)(v10 + 912) = *(_DWORD *)(v12 + 4) + 32 * *(__int16 *)(v18 + 18);
  *(_DWORD *)(v10 + 916) = *(_DWORD *)(v12 + 4);
  *(_DWORD *)(v10 + 1024) = *(_DWORD *)(v10 + 912) + 16 * *(__int16 *)(v18 + 20);
  v55[0] = v14 * v19 + (double)*(unsigned __int8 *)(v12 + 28) * v20;
  v55[1] = (double)BYTE1(v50) * v19 + (double)*(unsigned __int8 *)(v12 + 29) * v20;
  v55[2] = (double)BYTE2(v50) * v19 + (double)*(unsigned __int8 *)(v12 + 30) * v20;
  v52 = (double)HIBYTE(v50);
  v21 = v19 * v52;
  v52 = (double)*(unsigned __int8 *)(v12 + 31);
  v22 = v20 * v52;
  HIDWORD(v52) = *(unsigned __int8 *)(v12 + 24);
  v55[3] = v22 + v21;
  v52 = (double)SHIDWORD(v52);
  v23 = v52 * 0.0078125;
  HIDWORD(v52) = *(unsigned __int8 *)(v12 + 25);
  v53[0] = v23;
  v52 = (double)SHIDWORD(v52);
  v24 = v52 * 0.0078125;
  HIDWORD(v52) = *(unsigned __int8 *)(v12 + 26);
  v53[1] = v24;
  v52 = (double)SHIDWORD(v52);
  v25 = v52 * 0.0078125;
  HIDWORD(v52) = *(unsigned __int8 *)(v12 + 27);
  v53[2] = v25;
  v26 = (double)SHIDWORD(v52);
  v52 = v26;
  HIDWORD(v52) = *(unsigned __int8 *)(*(_DWORD *)(v18 + 4) + v18 + 7);
  v53[3] = 0.0078125 * v26;
  v54[2] = 256.0;
  v54[1] = 256.0;
  v54[0] = 256.0;
  v54[3] = (float)SHIDWORD(v52);
  sub_A6D890(v18, v12, (_DWORD *)v10, (int)v55, (int)v53, (int)v54, v48);
  v27 = !v46;
  *(_DWORD *)(v10 + 1056) = *(_DWORD *)(a5 + 12);
  *(_DWORD *)(v10 + 1060) = a6;
  HIDWORD(v51) = a6;
  *(_DWORD *)(v10 + 1072) = a5 + 48;
  v50 = *(_DWORD *)(v49 + 56);
  v48 = dword_22FB3E0[v48];
  v28 = *(__int16 *)(v47 + 16);
  HIDWORD(v52) = v28;
  if ( !v27 )
  {
    v41 = 3 * v28;
    v43 = 3 * v28;
    v44 = 1;
    v29 = strcmp(*(const char **)(unk_22FB3DC + 4), "m100");
    if ( v29 )
      v29 = v29 < 0 ? -1 : 1;
    _13476_19_0_0_512_512.dds.phyre = "13476_19_0_0_512_512.dds.phyre";
    if ( v29 )
      _13476_19_0_0_512_512.dds.phyre = "13376_19_0_0_512_512.dds.phyre";
    qmemcpy(Source, _13476_19_0_0_512_512.dds.phyre, sizeof(Source));
    v31 = _13476_19_0_0_512_512.dds.phyre + 28;
    v58 = *(_WORD *)v31;
    v59 = v31[2];
    if ( sub_6455B0(Source, v56, 0, 0, 0, 0) )
    {
      v32 = 0;
      do
      {
        v33 = v56[v32];
        Source[v32++] = v33;
      }
      while ( v33 );
    }
    v7 = v45;
    FFX_MagicCoreOp_CreateModelTexturedVtxFormat(__SPAIR64__(v45, a7), 1048648);
    FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(__SPAIR64__(v45, a7), 1, (int)&v41, &v43, Source, (int)&v44);
    v28 = HIDWORD(v52);
  }
  dst_1 = sub_645580(__SPAIR64__(v7, a7));
  dst = (_DWORD *)dst_1;
  if ( dst_1 )
  {
    *(_DWORD *)(*(_DWORD *)(dst_1 + 148) + 36) = 0;
    result = sub_63FF60(dst_1, 0, *(_DWORD *)(*(_DWORD *)(dst_1 + 148) + 4), *(_DWORD *)(*(_DWORD *)(dst_1 + 148) + 8));
    if ( !result )
      return result;
    if ( sub_63FF20(v36) )
    {
      v37 = FFX_MagicHost_AllocPppDrawRecord(v28);
      *(_BYTE *)v37 = 5;
      *(_DWORD *)(v37 + 16) = dst[37];
      *(_DWORD *)(v37 + 20) = v47;
      *(_DWORD *)(v37 + 24) = a5;
      *(_DWORD *)(v37 + 28) = v50;
      *(_DWORD *)(v37 + 32) = v48;
      *(_DWORD *)(v37 + 36) = a6;
    }
    HIDWORD(v51) = v28 + a6;
    v38 = v49;
    qmemcpy(dst, *(const void **)(v49 + 44), 0x40u);
    sub_6ED700(dst, unk_2332EA4, *(_DWORD *)(v38 + 44));
    sub_6ED700(dst, &src__0, dst);
    v39 = v45;
    v40 = HIDWORD(v42);
    sub_6458C0(HIDWORD(v42), v45, 1);
    if ( v46 )
      sub_645930(__SPAIR64__(v39, v40));
    else
      sub_6457B0(v40, v39);
  }
  while ( (word_23056E8 & 0x100) != 0 )
    ;
  sub_7E6970(6144);
  return HIDWORD(v51);
}

