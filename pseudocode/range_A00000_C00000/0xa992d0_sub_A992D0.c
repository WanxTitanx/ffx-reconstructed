// Function: sub_A992D0
// Address: 0xa992d0
// Size: 0x2e7
// Prototype: 

int __fastcall sub_A992D0(int n2, int a2, float *a3, float *a4, int a5, float *a6)
{
  int result; // eax
  int v7; // esi
  float *v8; // edi
  int v9; // edx
  float *v10; // eax
  float *v11; // ebx
  float *v12; // esi
  float *v13; // ecx
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  bool v17; // zf
  int v18; // edx
  float *v19; // esi
  int v20; // ebx
  float *v21; // esi
  unsigned int v22; // eax
  float *v23; // ecx
  int v24; // edx
  float *v25; // edi
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm5_4
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm2_4
  float v36; // xmm5_4
  float v37; // xmm0_4
  int v38; // [esp+0h] [ebp-50h]
  int v39; // [esp+4h] [ebp-4Ch]
  float *v40; // [esp+Ch] [ebp-44h]
  float *v41; // [esp+10h] [ebp-40h]
  int n2_1; // [esp+14h] [ebp-3Ch]
  int v43; // [esp+18h] [ebp-38h]
  int v44; // [esp+18h] [ebp-38h]
  int v45; // [esp+1Ch] [ebp-34h]
  float *v46; // [esp+1Ch] [ebp-34h]
  int v47; // [esp+20h] [ebp-30h]
  char *v48; // [esp+24h] [ebp-2Ch]
  int v49; // [esp+28h] [ebp-28h]
  float *v50; // [esp+2Ch] [ebp-24h]
  float *v51; // [esp+30h] [ebp-20h]
  int v52; // [esp+30h] [ebp-20h]
  int v53; // [esp+34h] [ebp-1Ch]
  float *v54; // [esp+34h] [ebp-1Ch]
  int v55; // [esp+38h] [ebp-18h]
  int v56; // [esp+38h] [ebp-18h]
  float *v57; // [esp+3Ch] [ebp-14h]
  float *v58; // [esp+40h] [ebp-10h]
  float *v59; // [esp+44h] [ebp-Ch]
  int v60; // [esp+48h] [ebp-8h]
  int v61; // [esp+4Ch] [ebp-4h]

  result = a2;
  v60 = a2 * n2;
  v43 = 2 * a2 * n2;
  v7 = 2 * n2;
  v8 = a3;
  v61 = a2;
  n2_1 = n2;
  v45 = 2 * n2;
  v47 = 3 * n2;
  if ( a2 > 0 )
  {
    v9 = 4 * n2;
    v55 = 4 * n2;
    v10 = &a3[2 * n2];
    v11 = a3;
    v12 = a4;
    v51 = &a4[v60];
    v53 = v61;
    v13 = &a4[v43];
    do
    {
      v14 = *(v10 - 1) + *(v10 - 1);
      v15 = (float)(v14 * -0.5) + *v11;
      *v12 = *v11 + v14;
      v12 = (float *)((char *)v12 + v9);
      v16 = (float)(*v10 + *v10) * 0.86602539;
      *v51 = v15 - v16;
      *v13 = v16 + v15;
      v13 = (float *)((char *)v13 + v9);
      v51 = (float *)((char *)v51 + v9);
      v9 = v55;
      v10 += v47;
      v11 += v47;
      v17 = v53-- == 1;
      v8 = a3;
    }
    while ( !v17 );
    n2 = n2_1;
    result = v61;
    v7 = v45;
  }
  if ( n2 != 1 && result > 0 )
  {
    v52 = 0;
    v18 = 0;
    v38 = 2 * n2;
    v44 = 12 * n2;
    v39 = 4 * n2;
    v19 = &v8[v7];
    result = v61;
    v54 = &a4[2 * v60];
    v56 = 0;
    v46 = v19;
    v20 = 0;
    do
    {
      if ( n2 > 2 )
      {
        v41 = v19;
        v40 = v19;
        v50 = v8;
        v57 = a6;
        v21 = v54;
        v58 = &a4[v60 + v56 - v20];
        v22 = n2 - 3;
        v23 = v41;
        v24 = a5 + 4;
        v48 = (char *)a6 - a5;
        v25 = v40;
        v59 = &a4[v56 - v20];
        v49 = (v22 >> 1) + 1;
        do
        {
          v26 = v23[1] + *(v25 - 3);
          v27 = v50[1];
          v23 += 2;
          v25 -= 2;
          v50 += 2;
          v28 = (float)(v26 * -0.5) + v27;
          v58 += 2;
          v59 += 2;
          v21 += 2;
          *(v59 - 1) = v27 + v26;
          v29 = *v23 - *v25;
          v24 += 8;
          v30 = (float)(v29 * -0.5) + *v50;
          *v59 = *v50 + v29;
          v31 = (float)(*(v23 - 1) - *(v25 - 1)) * 0.86602539;
          v32 = (float)(*v25 + *v23) * 0.86602539;
          v33 = v28 - v32;
          v34 = v32 + v28;
          v35 = v31 + v30;
          v36 = v30 - v31;
          *(v58 - 1) = (float)(*(float *)(v24 - 12) * v33) - (float)(v35 * *(float *)(v24 - 8));
          *v58 = (float)(*(float *)(v24 - 12) * v35) + (float)(v33 * *(float *)(v24 - 8));
          *(v21 - 1) = (float)(*v57 * v34) - (float)(*(float *)&v48[v24 - 8] * v36);
          v37 = *v57 * v36;
          v17 = v49-- == 1;
          v57 += 2;
          *v21 = (float)(*(float *)&v48[v24 - 8] * v34) + v37;
        }
        while ( !v17 );
        v19 = v46;
        v8 = a3;
        result = v61;
        v20 = v52;
        v18 = v56;
      }
      v18 += v47;
      v19 = (float *)((char *)v19 + v44);
      v8 = (float *)((char *)v8 + v44);
      v54 = (float *)((char *)v54 + v39);
      v20 += v38;
      n2 = n2_1;
      --result;
      v56 = v18;
      v46 = v19;
      a3 = v8;
      v52 = v20;
      v61 = result;
    }
    while ( result );
  }
  return result;
}

