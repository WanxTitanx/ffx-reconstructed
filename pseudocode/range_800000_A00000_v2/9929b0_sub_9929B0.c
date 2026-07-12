// Function: sub_9929B0
// Address: 0x9929b0
int __thiscall sub_9929B0(float **this, float *a2, int a3, int a4)
{
  double v5; // st7
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st7
  double v13; // st3
  double v14; // st2
  float *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // edi
  int v20; // edx
  int result; // eax
  int v22; // edi
  int v23; // ecx
  int v24; // eax
  int v25; // edi
  _DWORD *v26; // edx
  _DWORD *v27; // ecx
  int v28; // ecx
  float v29; // [esp-40h] [ebp-4Ch]
  float v30; // [esp-3Ch] [ebp-48h]
  float v31; // [esp-38h] [ebp-44h]
  float v32; // [esp-30h] [ebp-3Ch]
  float v33; // [esp-30h] [ebp-3Ch]
  float v34; // [esp-30h] [ebp-3Ch]
  int v35; // [esp-30h] [ebp-3Ch]
  float v36; // [esp-2Ch] [ebp-38h]
  float v37; // [esp-2Ch] [ebp-38h]
  float v38; // [esp-2Ch] [ebp-38h]
  float v39; // [esp-28h] [ebp-34h]
  float v40; // [esp-28h] [ebp-34h]
  float v41; // [esp-28h] [ebp-34h]
  int v42; // [esp-28h] [ebp-34h]
  float v43; // [esp-20h] [ebp-2Ch]
  float v44; // [esp-20h] [ebp-2Ch]
  float v45; // [esp-20h] [ebp-2Ch]
  float v46; // [esp-20h] [ebp-2Ch]
  float v47; // [esp-1Ch] [ebp-28h]
  float v48; // [esp-1Ch] [ebp-28h]
  float v49; // [esp-1Ch] [ebp-28h]
  float v50; // [esp-1Ch] [ebp-28h]
  float v51; // [esp-18h] [ebp-24h]
  float v52; // [esp-18h] [ebp-24h]
  float v53; // [esp-18h] [ebp-24h]
  float v54; // [esp-18h] [ebp-24h]
  float v55; // [esp-Ch] [ebp-18h]
  int v56; // [esp-Ch] [ebp-18h]
  float v57; // [esp-8h] [ebp-14h]
  float v58; // [esp-8h] [ebp-14h]
  int v59; // [esp-8h] [ebp-14h]
  float v60; // [esp-4h] [ebp-10h]
  float v61; // [esp-4h] [ebp-10h]
  int v62; // [esp-4h] [ebp-10h]
  int v63; // [esp+14h] [ebp+8h]

  v43 = 9.9999998e17;
  v47 = 9.9999998e17;
  v5 = *a2;
  v51 = 9.9999998e17;
  v32 = -9.9999998e17;
  v36 = -9.9999998e17;
  v39 = -9.9999998e17;
  if ( v5 < 9.999999843067494e17 )
    v43 = *a2;
  v6 = a2[1];
  if ( v6 < 9.999999843067494e17 )
    v47 = a2[1];
  v7 = a2[2];
  if ( v7 < 9.999999843067494e17 )
    v51 = a2[2];
  if ( v5 > -9.999999843067494e17 )
    v32 = *a2;
  if ( v6 > -9.999999843067494e17 )
    v36 = a2[1];
  if ( v7 > -9.999999843067494e17 )
    v39 = a2[2];
  v8 = a2[4];
  v9 = v43;
  if ( v43 > (double)v8 )
    v9 = v8;
  v60 = a2[5];
  v10 = v47;
  if ( v47 > (double)v60 )
    v10 = v60;
  v57 = a2[6];
  v11 = v51;
  if ( v51 > (double)v57 )
    v11 = v57;
  v12 = v32;
  if ( a2[4] > (double)v32 )
    v12 = v8;
  v13 = v36;
  if ( v60 > (double)v36 )
    v13 = v60;
  v14 = v39;
  if ( v57 > (double)v39 )
    v14 = v57;
  v58 = a2[8];
  if ( v9 > v58 )
    v9 = v58;
  v61 = a2[9];
  if ( v10 > v61 )
    v10 = v61;
  v55 = a2[10];
  if ( v11 > v55 )
    v11 = v55;
  if ( v58 > v12 )
    v12 = v58;
  if ( v61 > v13 )
    v13 = v61;
  if ( v55 > v14 )
    v14 = v55;
  if ( v12 - v9 < 0.002000000094994903 )
  {
    v33 = v12 + 0.001000000047497451;
    v44 = v9 - 0.001000000047497451;
    v12 = v33;
    v9 = v44;
  }
  if ( v13 - v10 < 0.002000000094994903 )
  {
    v37 = v13 + 0.001000000047497451;
    v48 = v10 - 0.001000000047497451;
    v13 = v37;
    v10 = v48;
  }
  if ( v14 - v11 < 0.002000000094994903 )
  {
    v40 = v14 + 0.001000000047497451;
    v52 = v11 - 0.001000000047497451;
    v11 = v52;
    v14 = v40;
  }
  v15 = *(this + 2);
  v34 = v9 - v15[4];
  v38 = v10 - v15[5];
  v41 = v11 - v15[6];
  v45 = v15[12] * v34;
  v49 = v15[13] * v38;
  v53 = v15[14] * v41;
  LOWORD(v35) = (int)v45 & 0xFFFE;
  v16 = (int)v49;
  v46 = v12 - v15[4];
  v50 = v13 - v15[5];
  HIWORD(v35) = v16 & 0xFFFE;
  v17 = (int)v53;
  v54 = v14 - v15[6];
  v29 = v46 * v15[12];
  LOWORD(v38) = v17 & 0xFFFE;
  v30 = v15[13] * v50;
  v31 = v15[14] * v54;
  LOWORD(v42) = (int)(v30 + 1.0) | 1;
  v18 = (int)*(this + 1);
  v19 = *(_DWORD *)(v18 + 4);
  v20 = a4 | (a3 << 21);
  HIWORD(v42) = (int)(v31 + 1.0) | 1;
  result = *(_DWORD *)(v18 + 8);
  v63 = v20;
  if ( v19 == result )
  {
    v22 = v19 ? 2 * v19 : 1;
    v59 = v22;
    if ( result < v22 )
    {
      if ( v22 )
      {
        v23 = sub_9D4CE0(16 * v22, 16);
        v62 = v23;
      }
      else
      {
        v23 = 0;
        v62 = 0;
      }
      v24 = *(_DWORD *)(v18 + 4);
      v56 = v24;
      if ( v24 > 0 )
      {
        v25 = 0;
        v26 = (_DWORD *)v23;
        do
        {
          if ( v26 )
          {
            v27 = (_DWORD *)(v25 + *(_DWORD *)(v18 + 12));
            *v26 = *v27;
            v26[1] = v27[1];
            v26[2] = v27[2];
            v26[3] = v27[3];
            v24 = v56;
          }
          v25 += 16;
          v26 += 4;
          v56 = --v24;
        }
        while ( v24 );
        v22 = v59;
      }
      if ( *(_DWORD *)(v18 + 12) )
      {
        if ( *(_BYTE *)(v18 + 16) )
          sub_9D4D50(*(_DWORD *)(v18 + 12));
        *(_DWORD *)(v18 + 12) = 0;
      }
      result = v62;
      v20 = v63;
      *(_BYTE *)(v18 + 16) = 1;
      *(_DWORD *)(v18 + 12) = v62;
      *(_DWORD *)(v18 + 8) = v22;
    }
  }
  v28 = *(_DWORD *)(v18 + 12) + 16 * *(_DWORD *)(v18 + 4);
  if ( v28 )
  {
    *(_DWORD *)v28 = v35;
    HIWORD(v38) = (int)(v29 + 1.0) | 1;
    *(float *)(v28 + 4) = v38;
    result = v42;
    *(_DWORD *)(v28 + 8) = v42;
    *(_DWORD *)(v28 + 12) = v20;
  }
  ++*(_DWORD *)(v18 + 4);
  return result;
}
