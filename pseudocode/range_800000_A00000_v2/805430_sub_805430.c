// Function: sub_805430
// Address: 0x805430
int __cdecl sub_805430(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // ebx
  int v7; // eax
  _DWORD *v8; // eax
  float *v9; // ebx
  int v10; // edx
  int v11; // edi
  float *v12; // eax
  int v13; // ecx
  int n128; // ecx
  int v15; // ecx
  float *v16; // edi
  unsigned __int8 v17; // cl
  int n3; // edx
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // st4
  double v23; // rt1
  double v24; // st4
  double v25; // rt2
  double v26; // st4
  double v27; // rtt
  float *v28; // ecx
  double v29; // rt0
  double v30; // st4
  double v31; // st5
  double v32; // rt1
  double v33; // st4
  double v34; // st6
  double v35; // rt2
  double v36; // st4
  double v37; // st7
  float *v38; // esi
  int n3_1; // ebx
  int v40; // ecx
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int n3_2; // edx
  int v45; // esi
  int v46; // eax
  __int64 n2622; // [esp-2Ch] [ebp-A0h]
  __int64 v49; // [esp-8h] [ebp-7Ch]
  float *v50; // [esp+10h] [ebp-64h]
  float v51; // [esp+14h] [ebp-60h]
  float v52; // [esp+18h] [ebp-5Ch]
  float v53; // [esp+1Ch] [ebp-58h]
  float v54; // [esp+20h] [ebp-54h]
  _DWORD *v55; // [esp+24h] [ebp-50h]
  float *v56; // [esp+2Ch] [ebp-48h]
  int v57; // [esp+30h] [ebp-44h]
  float v58; // [esp+34h] [ebp-40h]
  float v59; // [esp+34h] [ebp-40h]
  int v60; // [esp+34h] [ebp-40h]
  float v61[4]; // [esp+40h] [ebp-34h] BYREF
  float v62[4]; // [esp+50h] [ebp-24h] BYREF
  float v63[4]; // [esp+60h] [ebp-14h] BYREF

  v5 = a1;
  v6 = *(_DWORD *)(a1 + 4);
  HIDWORD(v49) = a2;
  LODWORD(v49) = 0;
  v7 = sub_645580(v49);
  v57 = v7;
  if ( !v7 || !sub_63FF60(v7, 0, 3 * v6, 3 * v6) )
    v57 = 0;
  v8 = (_DWORD *)sub_7E6910(6144);
  v9 = (float *)(v8 + 1280);
  v8[1408] = unk_C8F508[0];
  v8[1409] = unk_C8F50C;
  v8[1410] = unk_C8F510;
  v50 = (float *)(v8 + 1280);
  v8[1411] = unk_C8F514;
  if ( a5 )
  {
    v11 = a2;
  }
  else
  {
    v10 = 0;
    v11 = 0;
    if ( *(int *)(a1 + 4) <= 0 )
    {
LABEL_16:
      *(_WORD *)(a2 + 176) |= **(_WORD **)(a1 + 12);
      goto LABEL_32;
    }
    v12 = (float *)(a1 + 176);
    do
    {
      v13 = *((unsigned __int16 *)v12 - 28) - 1;
      v58 = v12[1] + *v12;
      *v12 = v58;
      *(v12 - 1) = v58 + *(v12 - 1);
      v59 = v12[15] + v12[14];
      v12[14] = v59;
      v12[13] = v59 + v12[13];
      v12[4] = v12[8] + v12[4];
      v12[5] = v12[9] + v12[5];
      v12[6] = v12[10] + v12[6];
      if ( v13 > 0 )
        ++v11;
      else
        v13 = 0;
      *((_WORD *)v12 - 28) = v13;
      n128 = 8 * v13;
      if ( n128 >= 128 )
        LOBYTE(n128) = 0x80;
      *((_BYTE *)v12 - 37) = n128;
      ++v10;
      v12 += 48;
    }
    while ( v10 < *(_DWORD *)(a1 + 4) );
  }
  if ( !v11 )
    goto LABEL_16;
  v15 = 0;
  v16 = (float *)(a1 + 48);
  v56 = (float *)(a1 + 48);
  v60 = 0;
  if ( *(int *)(a1 + 4) > 0 )
  {
    do
    {
      v16[24] = v16[28] * v16[31] + *(float *)(v5 + 16);
      v16[25] = v16[29] * v16[31] + *(float *)(v5 + 20) + v16[45];
      v16[26] = v16[30] * v16[31] + *(float *)(v5 + 24);
      if ( *(float *)(v5 + 32) <= (double)v16[25] )
        v16[46] = -v16[46];
      if ( !unk_12FB790 )
      {
        v55 = v9 + 16;
        sub_802D40(v9 + 16, v16);
        v17 = *((_BYTE *)v16 + 91);
        if ( v17 )
        {
          n3 = 0;
          v51 = (double)*((unsigned __int8 *)v16 + 88) * 0.00390625;
          v52 = (double)*((unsigned __int8 *)v16 + 89) * 0.00390625;
          v53 = (double)*((unsigned __int8 *)v16 + 90) * 0.00390625;
          v54 = 0.00390625 * (double)v17;
          v19 = v54;
          v20 = v53;
          v21 = v52;
          v22 = v51;
          while ( 1 )
          {
            v28 = (float *)(*(_DWORD *)(*(_DWORD *)(v57 + 148) + 20)
                          + 16 * (*((_DWORD *)v9 + 129) + n3 + 2 * *((_DWORD *)v9 + 129)));
            ++n3;
            *v28 = v22;
            v29 = v22;
            v30 = v21;
            v31 = v29;
            v28[1] = v30;
            v32 = v30;
            v33 = v20;
            v34 = v32;
            v28[2] = v33;
            v35 = v33;
            v36 = v19;
            v37 = v35;
            v28[3] = v36;
            if ( n3 >= 3 )
              break;
            v23 = v36;
            v24 = v37;
            v19 = v23;
            v25 = v24;
            v26 = v34;
            v20 = v25;
            v27 = v26;
            v22 = v31;
            v21 = v27;
          }
          sub_6ED4B0(v61, v16);
          sub_6ED4B0(v62, v16 + 4);
          sub_6ED4B0(v63, v16 + 8);
          v38 = v61;
          n3_1 = 3;
          do
          {
            v38[3] = 1.0;
            sub_6ED420(v38, v55, v38);
            v38 += 4;
            --n3_1;
          }
          while ( n3_1 );
          v9 = v50;
          v16 = v56;
          v40 = 9 * *((_DWORD *)v50 + 129);
          v41 = *(_DWORD *)(*(_DWORD *)(v57 + 148) + 12);
          *(float *)(v41 + 4 * v40) = v61[0];
          *(float *)(v41 + 4 * v40 + 4) = v61[1];
          *(float *)(v41 + 4 * v40 + 8) = v61[2];
          *(float *)(v41 + 4 * v40 + 12) = v62[0];
          *(float *)(v41 + 4 * v40 + 16) = v62[1];
          *(float *)(v41 + 4 * v40 + 20) = v62[2];
          *(float *)(v41 + 4 * v40 + 24) = v63[0];
          *(float *)(v41 + 4 * v40 + 28) = v63[1];
          *(float *)(v41 + 4 * v40 + 32) = v63[2];
          v42 = 3 * *((_DWORD *)v50 + 129);
          v43 = *(_DWORD *)(*(_DWORD *)(v57 + 148) + 24);
          *(float *)(v43 + 8 * v42) = v56[12];
          *(float *)(v43 + 8 * v42 + 4) = v56[13];
          *(float *)(v43 + 8 * v42 + 8) = v56[16];
          *(float *)(v43 + 8 * v42 + 12) = v56[17];
          *(float *)(v43 + 8 * v42 + 16) = v56[20];
          *(float *)(v43 + 8 * v42 + 20) = v56[21];
          n3_2 = 0;
          v45 = *(_DWORD *)(*(_DWORD *)(v57 + 148) + 28);
          do
          {
            v46 = (unsigned __int16)(n3_2++ + 3 * *((_WORD *)v50 + 258));
            *(_WORD *)(v45 + 2 * v46) = v46;
          }
          while ( n3_2 < 3 );
          ++*((_DWORD *)v50 + 129);
          v5 = a1;
        }
        ++*((_DWORD *)v9 + 128);
        v15 = v60;
        v16 += 48;
        v56 = v16;
      }
      v60 = ++v15;
    }
    while ( v15 < *(_DWORD *)(v5 + 4) );
  }
LABEL_32:
  sub_62FA30(0, 0);
  memset(
    (void *)(*(_DWORD *)(*(_DWORD *)(v57 + 148) + 28) + 6 * *((_DWORD *)v9 + 129)),
    0,
    6 * (*(_DWORD *)(v5 + 4) - *((_DWORD *)v9 + 129)));
  sub_6EDAE0(v57);
  *(_DWORD *)(v57 + 128) = 0;
  *(float *)(v57 + 152) = -9999999.0;
  *(float *)(v57 + 156) = -9999999.0;
  *(float *)(v57 + 160) = -9999999.0;
  *(float *)(v57 + 164) = 9999999.0;
  *(float *)(v57 + 168) = 9999999.0;
  *(float *)(v57 + 172) = 9999999.0;
  sub_6458C0(0, a2, 1);
  HIDWORD(n2622) = a2;
  LODWORD(n2622) = 0;
  FFX_MagicHost_CommitDrawableResources(n2622);
  return sub_7E6970(6144);
}
