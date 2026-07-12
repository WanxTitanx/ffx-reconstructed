// Function: sub_992630
// Address: 0x992630
int __userpurge sub_992630@<eax>(int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5)
{
  double v5; // st7
  float v6; // xmm1_4
  float v7; // xmm3_4
  double v8; // st6
  double v9; // st7
  float v10; // xmm0_4
  double v11; // st6
  double v12; // st5
  float v13; // xmm1_4
  double v14; // st4
  double v15; // st3
  float v16; // xmm2_4
  double v17; // st2
  bool v18; // zf
  double v19; // st7
  double v20; // st3
  double v21; // st5
  double v22; // st3
  double v23; // st7
  double v24; // st3
  double v25; // st2
  double v26; // st6
  float v27; // xmm2_4
  double v28; // st3
  double v29; // st4
  double v30; // st3
  float v31; // xmm1_4
  int result; // eax
  int v33; // ecx
  int v34; // edi
  int v35; // edi
  float v36; // edx
  float v37; // esi
  float v38; // ecx
  float v39; // ecx
  void *dst; // edi
  _DWORD src[16]; // [esp-80h] [ebp-8Ch] BYREF
  float v42; // [esp-40h] [ebp-4Ch]
  float v43; // [esp-3Ch] [ebp-48h]
  float v44; // [esp-38h] [ebp-44h]
  float v45; // [esp-34h] [ebp-40h]
  float v46; // [esp-30h] [ebp-3Ch]
  float v47; // [esp-2Ch] [ebp-38h]
  float v48; // [esp-28h] [ebp-34h]
  float v49; // [esp-24h] [ebp-30h]
  float v50; // [esp-14h] [ebp-20h]
  int v51; // [esp-10h] [ebp-1Ch]
  int v52; // [esp-Ch] [ebp-18h]
  float v53; // [esp-8h] [ebp-14h]
  float v54; // [esp-4h] [ebp-10h]
  int v55; // [esp+0h] [ebp-Ch]
  void *v56; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v55 = a2;
  v56 = retaddr;
  v54 = *a3;
  v46 = 9.9999998e17;
  v5 = v54;
  v6 = v54;
  v47 = 9.9999998e17;
  v48 = 9.9999998e17;
  v49 = 0.0;
  v42 = -9.9999998e17;
  v43 = -9.9999998e17;
  v44 = -9.9999998e17;
  v45 = 0.0;
  if ( v54 < 9.999999843067494e17 )
    v46 = v54;
  v54 = a3[1];
  v7 = v54;
  v8 = v54;
  if ( v54 < 9.999999843067494e17 )
    v47 = v54;
  v54 = a3[2];
  if ( v54 < 9.999999843067494e17 )
    v48 = v54;
  v50 = a3[3];
  if ( v50 < 0.0 )
    v49 = v50;
  if ( v5 > -9.999999843067494e17 )
    v42 = v6;
  if ( v8 > -9.999999843067494e17 )
    v43 = v7;
  if ( v54 > -9.999999843067494e17 )
    v44 = v54;
  if ( v50 > 0.0 )
    v45 = v50;
  v54 = a3[4];
  v9 = v54;
  v10 = v54;
  v11 = v46;
  if ( v46 > (double)v54 )
  {
    v46 = v54;
    v11 = v54;
  }
  v54 = a3[5];
  v12 = v54;
  v13 = v54;
  v14 = v47;
  if ( v47 > (double)v54 )
  {
    v47 = v54;
    v14 = v54;
  }
  v54 = a3[6];
  v15 = v54;
  v16 = v54;
  if ( v48 > (double)v54 )
    v48 = v54;
  v54 = a3[7];
  if ( v49 > (double)v54 )
    v49 = v54;
  v17 = v9;
  v18 = v9 == v42;
  v19 = v15;
  if ( v17 >= v42 && !v18 )
    v42 = v10;
  v20 = v12;
  v21 = v43;
  if ( v20 > v43 )
  {
    v43 = v13;
    v21 = v13;
  }
  v22 = v19;
  v23 = v44;
  if ( v22 > v44 )
  {
    v44 = v16;
    v23 = v16;
  }
  v24 = v45;
  if ( v54 > (double)v45 )
  {
    v45 = v54;
    v24 = v54;
  }
  v54 = a3[8];
  v25 = v11;
  v18 = v11 == v54;
  v26 = v24;
  if ( v25 >= v54 && !v18 )
    v46 = v54;
  v53 = a3[9];
  v27 = v53;
  v28 = v14;
  v29 = v53;
  if ( v28 > v53 )
    v47 = v53;
  v53 = a3[10];
  v30 = v53;
  v31 = v53;
  if ( v48 > (double)v53 )
    v48 = v53;
  v53 = a3[11];
  if ( v49 > (double)v53 )
    v49 = v53;
  if ( v54 > (double)v42 )
    v42 = v54;
  if ( v29 > v21 )
    v43 = v27;
  if ( v30 > v23 )
    v44 = v31;
  if ( v53 > v26 )
    v45 = v53;
  *(float *)src = v46;
  *(float *)&src[1] = v47;
  *(float *)&src[2] = v48;
  *(float *)&src[3] = v49;
  *(float *)&src[4] = v42;
  *(float *)&src[5] = v43;
  *(float *)&src[6] = v44;
  *(float *)&src[7] = v45;
  src[9] = a4;
  src[10] = a5;
  result = *(_DWORD *)(a1 + 4);
  src[8] = -1;
  v33 = *(_DWORD *)(result + 8);
  v34 = *(_DWORD *)(result + 4);
  v51 = result;
  if ( v34 == v33 )
  {
    v35 = v34 ? 2 * v34 : 1;
    v52 = v35;
    if ( v33 < v35 )
    {
      if ( v35 )
      {
        v36 = COERCE_FLOAT(sub_9D4CE0(v35 << 6, 16));
        v50 = v36;
        result = v51;
      }
      else
      {
        v36 = 0.0;
        v50 = 0.0;
      }
      v37 = *(float *)(result + 4);
      v54 = v37;
      if ( SLODWORD(v37) > 0 )
      {
        v38 = 0.0;
        v53 = 0.0;
        do
        {
          if ( v36 != 0.0 )
          {
            qmemcpy((void *)LODWORD(v36), (const void *)(LODWORD(v38) + *(_DWORD *)(result + 12)), 0x40u);
            v38 = v53;
            v37 = v54;
          }
          LODWORD(v38) += 64;
          LODWORD(v36) += 64;
          --LODWORD(v37);
          v53 = v38;
          v54 = v37;
        }
        while ( v37 != 0.0 );
        v35 = v52;
      }
      if ( *(_DWORD *)(result + 12) )
      {
        if ( *(_BYTE *)(result + 16) )
        {
          sub_9D4D50(*(_DWORD *)(result + 12));
          result = v51;
        }
        *(_DWORD *)(result + 12) = 0;
      }
      v39 = v50;
      *(_BYTE *)(result + 16) = 1;
      *(float *)(result + 12) = v39;
      *(_DWORD *)(result + 8) = v35;
    }
  }
  dst = (void *)(*(_DWORD *)(result + 12) + (*(_DWORD *)(result + 4) << 6));
  if ( dst )
    qmemcpy(dst, src, 0x40u);
  ++*(_DWORD *)(result + 4);
  return result;
}
