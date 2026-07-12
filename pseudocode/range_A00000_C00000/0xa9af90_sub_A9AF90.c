// Function: sub_A9AF90
// Address: 0xa9af90
// Size: 0x200
// Prototype: 

int *__fastcall sub_A9AF90(int a1, int a2, int *a3)
{
  int n2; // edi
  int n4; // eax
  int v5; // esi
  int v6; // ebx
  bool v7; // zf
  int *v8; // eax
  int *v9; // eax
  int *v10; // ecx
  int v11; // edx
  int *result; // eax
  int v13; // edx
  float v14; // xmm2_4
  int v15; // edi
  int v16; // ebx
  int v17; // ecx
  int v18; // esi
  int n2_1; // edx
  float *v20; // ebx
  int v21; // eax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float *v24; // edi
  unsigned int v25; // esi
  float v26; // xmm0_4
  int v27; // [esp+Ch] [ebp-38h]
  int v28; // [esp+10h] [ebp-34h]
  int n2_2; // [esp+14h] [ebp-30h]
  int v30; // [esp+18h] [ebp-2Ch]
  float v31; // [esp+20h] [ebp-24h]
  float v32; // [esp+24h] [ebp-20h]
  int v34; // [esp+30h] [ebp-14h]
  int *v35; // [esp+34h] [ebp-10h]
  int v36; // [esp+34h] [ebp-10h]
  int *v37; // [esp+38h] [ebp-Ch]
  int n4_1; // [esp+3Ch] [ebp-8h]
  int v39; // [esp+3Ch] [ebp-8h]
  int v40; // [esp+40h] [ebp-4h]
  int v41; // [esp+40h] [ebp-4h]
  int v42; // [esp+4Ch] [ebp+8h]

  n2 = 0;
  n4 = -1;
  v34 = a1;
  v40 = a1;
  v5 = 0;
  do
  {
LABEL_2:
    n4_1 = ++n4;
    if ( n4 >= 4 )
      n2 += 2;
    else
      n2 = dword_C8B220[n4];
    v6 = a1 / n2;
    v7 = a1 % n2 == 0;
    a1 = v40;
  }
  while ( !v7 );
  v8 = &a3[v5];
  while ( 1 )
  {
    v9 = v8 + 1;
    ++v5;
    v35 = v9;
    v9[1] = n2;
    v40 = v6;
    if ( n2 != 2 || v5 == 1 )
    {
      result = a3;
    }
    else
    {
      if ( v5 > 1 )
      {
        v10 = v9;
        v11 = v5 - 1;
        do
        {
          v10[1] = *v10;
          --v10;
          --v11;
        }
        while ( v11 );
      }
      result = a3;
      a3[2] = 2;
    }
    if ( v6 == 1 )
      break;
    v6 /= n2;
    v8 = v35;
    if ( v40 != n2 * v6 )
    {
      a1 = v40;
      n4 = n4_1;
      goto LABEL_2;
    }
  }
  v13 = v34;
  result[1] = v5;
  v14 = 6.2831855 / (float)v34;
  v15 = 1;
  *result = v34;
  v42 = 0;
  v36 = v5 - 1;
  v41 = 1;
  if ( v5 - 1 > 0 )
  {
    result += 2;
    v37 = result;
    do
    {
      v16 = v15 * *result;
      v17 = *result - 1;
      v18 = 0;
      v27 = v16;
      v39 = v17;
      n2_1 = v13 / v16;
      n2_2 = n2_1;
      if ( v17 > 0 )
      {
        v28 = 4 * n2_1;
        v20 = (float *)(a2 + 4 * v42);
        v42 += n2_1 * v17;
        v21 = 4 * n2_1;
        do
        {
          v18 += v15;
          v30 = v18;
          v22 = (float)v18 * v14;
          v23 = 0.0;
          v31 = v22;
          if ( n2_1 > 2 )
          {
            v24 = v20;
            v25 = ((unsigned int)(n2_1 - 3) >> 1) + 1;
            do
            {
              v32 = v23 + 1.0;
              libm_sse2_cos_precise();
              v26 = (float)(v23 + 1.0) * v22;
              *v24 = v26;
              libm_sse2_sin_precise();
              v22 = v31;
              v24 += 2;
              *(v24 - 1) = v26;
              v23 = v32;
              --v25;
            }
            while ( v25 );
            v14 = 6.2831855 / (float)v34;
            v18 = v30;
            v17 = v39;
            n2_1 = n2_2;
            v15 = v41;
            v21 = v28;
          }
          v20 = (float *)((char *)v20 + v21);
          v39 = --v17;
        }
        while ( v17 );
        v16 = v27;
      }
      v13 = v34;
      result = v37 + 1;
      v7 = v36-- == 1;
      v15 = v16;
      v41 = v16;
      ++v37;
    }
    while ( !v7 );
  }
  return result;
}

