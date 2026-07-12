// Function: sub_A9C340
// Address: 0xa9c340
// Size: 0x264
// Prototype: 

int __fastcall sub_A9C340(int a1, unsigned int a2, int a3)
{
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // edi
  int v6; // ebx
  int v7; // ecx
  int n2; // edx
  int v9; // ebx
  unsigned int v10; // edi
  float *v11; // esi
  float *v12; // edx
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float *v19; // esi
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float *v27; // esi
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm4_4
  float v34; // xmm0_4
  float *v35; // esi
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm4_4
  int result; // eax
  int v42; // eax
  int v44; // [esp+10h] [ebp-18h]
  float *v45; // [esp+14h] [ebp-14h]
  int v46; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  int v48; // [esp+20h] [ebp-8h]
  int n2_1; // [esp+24h] [ebp-4h]

  v3 = *(_DWORD *)(a1 + 4) - 6;
  v4 = a2;
  v5 = a3;
  v45 = *(float **)(a1 + 8);
  if ( v3 > 0 )
    sub_A9C780(a3);
  v6 = v3 - 1;
  v7 = 1;
  n2 = 2;
  v48 = 1;
  v46 = v6;
  for ( i = 2; v6 > 0; v46 = v6 )
  {
    if ( n2 > 0 )
    {
      v9 = v5 >> v7;
      v10 = v4;
      v44 = 4 << v7;
      n2_1 = n2;
      do
      {
        v11 = v45;
        v12 = (float *)(v10 + 4 * ((v9 >> 1) - 8));
        v13 = &v12[v9 - (v9 >> 1) + 7];
        do
        {
          v14 = *v13;
          v15 = *v13 - v12[7];
          v16 = *(v13 - 1) - v12[6];
          *(v13 - 1) = *(v13 - 1) + v12[6];
          *v13 = v14 + v12[7];
          v12[6] = (float)(*v11 * v16) + (float)(v15 * v11[1]);
          v17 = v16 * v11[1];
          v18 = *v11 * v15;
          v19 = &v11[v44];
          v12[7] = v18 - v17;
          v20 = *(v13 - 2);
          v21 = v20 - v12[5];
          v22 = *(v13 - 3);
          v23 = v22 + v12[4];
          v24 = v22 - v12[4];
          *(v13 - 3) = v23;
          *(v13 - 2) = v20 + v12[5];
          v12[4] = (float)(*v19 * v24) + (float)(v21 * v19[1]);
          v25 = v24 * v19[1];
          v26 = *v19 * v21;
          v27 = &v19[v44];
          v12[5] = v26 - v25;
          v28 = *(v13 - 4);
          v29 = v28 - v12[3];
          v30 = *(v13 - 5);
          v31 = v30 + v12[2];
          v32 = v30 - v12[2];
          *(v13 - 5) = v31;
          *(v13 - 4) = v28 + v12[3];
          v12[2] = (float)(*v27 * v32) + (float)(v29 * v27[1]);
          v33 = v32 * v27[1];
          v34 = *v27 * v29;
          v35 = &v27[v44];
          v12[3] = v34 - v33;
          v36 = *(v13 - 6);
          v37 = *(v13 - 7) - *v12;
          v38 = v36 - v12[1];
          *(v13 - 7) = *v12 + *(v13 - 7);
          *(v13 - 6) = v12[1] + v36;
          v12 -= 8;
          v13 -= 8;
          v12[8] = (float)(*v35 * v37) + (float)(v38 * v35[1]);
          v39 = *v35;
          v40 = v37 * v35[1];
          v11 = &v35[v44];
          v12[9] = (float)(v39 * v38) - v40;
        }
        while ( (unsigned int)v12 >= v10 );
        v10 += 4 * v9;
        --n2_1;
      }
      while ( n2_1 );
      n2 = i;
      v6 = v46;
      v4 = a2;
      v7 = v48;
    }
    n2 = __ROL4__(n2, 1);
    v5 = a3;
    --v6;
    v48 = ++v7;
    i = n2;
  }
  result = a3;
  if ( a3 > 0 )
  {
    do
    {
      v42 = sub_A9C940(v4);
      v4 += 128;
      result = v42 - 1;
    }
    while ( result );
  }
  return result;
}

