// Function: sub_812610
// Address: 0x812610
int __cdecl sub_812610(int a1, int a2)
{
  int v2; // ebx
  unsigned __int16 *v3; // esi
  float *v4; // edi
  int v5; // eax
  int v6; // ecx
  int result; // eax
  double v8; // st7
  __int16 *v9; // esi
  int v10; // edx
  bool v11; // zf
  __int16 v12; // ax
  int v13; // eax
  double v14; // st6
  double v15; // st6
  double v16; // st5
  double v17; // st5
  double v18; // st4
  char v19; // cl
  int v20; // eax
  int v21; // eax
  float *v22; // ebx
  float v23; // edi
  double v24; // st3
  int v25; // edi
  int v26; // ebx
  __int16 v27; // cx
  int v28; // eax
  double v29; // st7
  int v30; // ecx
  unsigned __int8 v31; // dl
  int v32; // esi
  int v33; // eax
  __int64 v34; // [esp-1Ch] [ebp-50h]
  __int64 n2622; // [esp-18h] [ebp-4Ch]
  __int64 v36; // [esp-10h] [ebp-44h]
  __int64 v37; // [esp-8h] [ebp-3Ch]
  __int64 v38; // [esp-4h] [ebp-38h]
  __int64 v39; // [esp-4h] [ebp-38h]
  unsigned __int16 *v40; // [esp+0h] [ebp-34h]
  unsigned __int16 *v41; // [esp+10h] [ebp-24h]
  float v42; // [esp+14h] [ebp-20h]
  float v43; // [esp+14h] [ebp-20h]
  int v44; // [esp+14h] [ebp-20h]
  float v45; // [esp+1Ch] [ebp-18h]
  float v46; // [esp+1Ch] [ebp-18h]
  float v47; // [esp+1Ch] [ebp-18h]
  float v48; // [esp+1Ch] [ebp-18h]
  float v49; // [esp+1Ch] [ebp-18h]
  float v50; // [esp+1Ch] [ebp-18h]
  float v51; // [esp+1Ch] [ebp-18h]
  int v52; // [esp+20h] [ebp-14h]
  int v53; // [esp+24h] [ebp-10h]
  int v54; // [esp+28h] [ebp-Ch] BYREF
  int v55; // [esp+2Ch] [ebp-8h]
  float v56; // [esp+30h] [ebp-4h]

  v2 = a1;
  v3 = *(unsigned __int16 **)(*(_DWORD *)(a1 + 544) + 168);
  v40 = *(unsigned __int16 **)(a1 + 544);
  v4 = (float *)(v3 + 16);
  v41 = v3;
  LODWORD(v56) = v3 + 16;
  *(_BYTE *)(a1 + 528) = 0;
  v5 = sub_801E20((_DWORD *)a1, v40);
  sub_7E7F20(a1 + 64, v5);
  v6 = a2;
  *(_WORD *)(a1 + 2) = 128;
  *(_DWORD *)(a1 + 16) = a1 + 128;
  *(_DWORD *)(a1 + 28) = a1 + 128;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = *((_DWORD *)v3 + 1);
  *(_BYTE *)(a1 + 24) = 0;
  result = 0;
  v52 = *(_DWORD *)(a2 + 84);
  v53 = 0;
  if ( *v3 )
  {
    v8 = 0.0625;
    while ( 1 )
    {
      v9 = *(__int16 **)v4;
      if ( *(_DWORD *)v4 )
        break;
LABEL_32:
      v33 = *v41;
      v4 += 20;
      v56 = *(float *)&v4;
      if ( ++v53 >= v33 )
      {
        *(_DWORD *)(v6 + 84) = v52;
        return v52;
      }
    }
    v10 = *(_DWORD *)(v6 + 32) + (*((unsigned __int16 *)v4 + 38) << 8);
    v11 = (*((_BYTE *)v4 + 9))-- == 1;
    v55 = v10;
    if ( v11 )
    {
      do
      {
        v12 = *v9;
        *(_WORD *)(v2 + 538) = *v9;
        v13 = funcs_8126C9[(unsigned __int8)v12](v2);
        v9 = (__int16 *)v13;
      }
      while ( !*(_BYTE *)(v2 + 528) );
      *((_BYTE *)v4 + 9) = *(_BYTE *)(v2 + 528);
      *(_DWORD *)v4 = v13;
      if ( !v13 )
      {
        HIDWORD(v38) = v4;
        LODWORD(v38) = 0;
        if ( sub_645580(v38) )
          sub_645430(0, v4);
      }
      v8 = 0.0625;
      *(_BYTE *)(v2 + 528) = 0;
      if ( !v9 )
        goto LABEL_31;
      v10 = v55;
    }
    v14 = v4[12] + v4[8];
    *((_WORD *)v4 + 6) += *((_WORD *)v4 + 7);
    v45 = v14;
    v15 = v45;
    *((_BYTE *)v4 + 28) += *((_BYTE *)v4 + 44);
    v4[8] = v45;
    v16 = v4[13] + v4[9];
    *((_BYTE *)v4 + 29) += *((_BYTE *)v4 + 45);
    v46 = v16;
    v17 = v46;
    *((_BYTE *)v4 + 30) += *((_BYTE *)v4 + 46);
    v4[9] = v46;
    v18 = v4[14] + v4[10];
    *((_BYTE *)v4 + 31) += *((_BYTE *)v4 + 47);
    v19 = *((_BYTE *)v4 + 28);
    v47 = v18;
    v4[10] = v47;
    v4[4] = v15 + v4[4];
    v4[5] = v17 + v4[5];
    v4[6] = v47 + v4[6];
    *(_BYTE *)(v2 + 4) = v19;
    *(_BYTE *)(v2 + 5) = *((_BYTE *)v4 + 29);
    *(_BYTE *)(v2 + 6) = *((_BYTE *)v4 + 30);
    *(_BYTE *)(v2 + 7) = *((_BYTE *)v4 + 31);
    *((_WORD *)v4 + 30) += *((_WORD *)v4 + 31);
    switch ( *((_BYTE *)v4 + 78) )
    {
      case 0:
        *(float *)(v2 + 176) = v4[4] * v8;
        *(float *)(v2 + 180) = v4[5] * v8;
        *(float *)(v2 + 184) = v8 * v4[6];
        break;
      case 2:
        v20 = ((int)v4[6] & 0xFFF) + 1024;
        *(float *)(v2 + 192) = flt_C43BE0[v20] * v4[4];
        *(float *)(v2 + 200) = flt_C44BE0[v20 & 0xFFF] * v4[4];
        *(float *)(v2 + 196) = v4[5];
        *(float *)(v2 + 176) = (v4[16] + *(float *)(v2 + 192)) * v8;
        *(float *)(v2 + 180) = (v4[17] + *(float *)(v2 + 196)) * v8;
        *(float *)(v2 + 184) = v8 * (v4[18] + *(float *)(v2 + 200));
        break;
      case 3:
        v21 = ((int)v4[6] & 0xFFF) + 1024;
        *(float *)(v2 + 192) = flt_C43BE0[v21] * v4[4];
        *(float *)(v2 + 200) = flt_C44BE0[v21 & 0xFFF] * v4[4];
        *(float *)(v2 + 196) = v4[5];
        *(float *)(v2 + 176) = *(float *)(v2 + 192) * v8;
        *(float *)(v2 + 180) = *(float *)(v2 + 196) * v8;
        *(float *)(v2 + 184) = v8 * *(float *)(v2 + 200);
        break;
      case 4:
        v22 = (float *)(v2 + 192);
        v23 = flt_12A80C0[*(unsigned __int8 *)(v10 + 24)];
        sub_833D90(LODWORD(v23), (int)*(float *)(LODWORD(v56) + 64), 0, v22);
        sub_833D90(LODWORD(v23), (int)*(float *)(LODWORD(v56) + 68), 0, a1 + 208);
        *(float *)&v4 = v56;
        v24 = *v22;
        v2 = a1;
        *(float *)(a1 + 176) = (1.0 - *(float *)(LODWORD(v56) + 72)) * v24
                             + *(float *)(LODWORD(v56) + 16) * 0.0625
                             + *(float *)(a1 + 208) * *(float *)(LODWORD(v56) + 72);
        *(float *)(a1 + 180) = *(float *)(a1 + 212) * v4[18] + v4[5] * 0.0625 + (1.0 - v4[18]) * *(float *)(a1 + 196);
        *(float *)(a1 + 184) = 0.0625 * v4[6] + *(float *)(a1 + 216) * v4[18] + (1.0 - v4[18]) * *(float *)(a1 + 200);
        break;
      case 5:
        *(float *)(v2 + 192) = v4[4];
        *(float *)(v2 + 196) = v4[5];
        *(float *)(v2 + 200) = v4[6];
        v25 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v10 + 24)]);
        v48 = sub_82ABE0(v25);
        v26 = v2 + 256;
        sub_805320(v26, v25);
        sub_805350((_DWORD *)(a1 + 320), v25, (int)*(float *)(LODWORD(v56) + 64));
        sub_7E82C0(v26, v26, a1 + 320);
        v49 = 10.0 / v48;
        sub_7EA760(a1 + 192, a1 + 192, LODWORD(v49));
        sub_7E78B0(a1 + 192, v26, a1 + 192);
        v2 = a1;
        *(float *)&v4 = v56;
        *(float *)(a1 + 176) = *(float *)(a1 + 192);
        *(float *)(a1 + 180) = *(float *)(a1 + 196);
        *(float *)(a1 + 184) = *(float *)(a1 + 200);
        break;
      default:
        break;
    }
    v27 = *((_WORD *)v4 + 30);
    v28 = *((__int16 *)v4 + 6);
    v56 = flt_C44BE0[(v27 + 1024) & 0xFFF];
    v42 = flt_C44BE0[v27 & 0xFFF];
    v50 = (double)v28 * 0.000244140625;
    memset((void *)(v2 + 128), 0, 0x30u);
    v29 = v50;
    v51 = v50 * v56;
    *(float *)(v2 + 128) = v51;
    v43 = v29 * v42;
    *(float *)(v2 + 132) = v43;
    *(float *)(v2 + 144) = -v43;
    *(float *)(v2 + 148) = v51;
    *(float *)(v2 + 168) = v29;
    *(float *)(v2 + 188) = 1.0;
    sub_6ED420(v2 + 176, v2 + 64, v2 + 176);
    v30 = *((_DWORD *)v4 + 1);
    if ( v30 )
    {
      v11 = (*((_BYTE *)v4 + 10))-- == 1;
      if ( v11 )
      {
        v31 = ++*((_BYTE *)v4 + 11);
        if ( v31 >= *(__int16 *)(v30 + 4) )
        {
          if ( *(char *)(v30 + 8 * (unsigned __int8)(*(_BYTE *)(v30 + 4) - 1) + 20) >= 0 && *((char *)v4 + 8) >= 0 )
          {
            HIDWORD(v39) = v4;
            LODWORD(v39) = 0;
            *v4 = 0.0;
            if ( sub_645580(v39) )
              sub_645430(0, v4);
            goto LABEL_30;
          }
          *((_BYTE *)v4 + 11) = 0;
          v31 = 0;
        }
        *((_BYTE *)v4 + 10) = *(__int16 *)(v30 + 8 * v31 + 18) / 512;
      }
      if ( (byte_12A8480[*(unsigned __int8 *)(v55 + 24)] & *(_BYTE *)(v55 + 179)) == 0 )
      {
        v44 = v30 + *(__int16 *)(v30 + 8 * *((unsigned __int8 *)v4 + 11) + 16);
        *(_DWORD *)(v2 + 20) = v52;
        v54 = unknown_libname_742(v30);
        HIDWORD(v37) = v4;
        LODWORD(v37) = 0;
        if ( sub_645580(v37) )
        {
          HIDWORD(v36) = v4;
          LODWORD(v36) = 0;
          FFX_MagicHost_ApplyPppDrawableColors(v36, &v54, v2, *((unsigned __int8 *)v4 + 11));
          HIDWORD(n2622) = v4;
          LODWORD(n2622) = 0;
          FFX_MagicHost_CommitDrawableResources(n2622);
        }
        else
        {
          v32 = FFX_MagicHost_ClassifyPppOpcodeByte(*(unsigned __int8 *)(*(_DWORD *)(v44 + 4) + v44 + 4));
          sub_7176F0(8);
          HIDWORD(v34) = v4;
          LODWORD(v34) = 0;
          FFX_MagicHost_BindPppResourceToDrawable(v34, &v54, v2, *((unsigned __int8 *)v4 + 11), v32);
          sub_7176E0();
        }
      }
    }
LABEL_30:
    v8 = 0.0625;
LABEL_31:
    v6 = a2;
    goto LABEL_32;
  }
  *(_DWORD *)(a2 + 84) = *(_DWORD *)(a2 + 84);
  return result;
}
