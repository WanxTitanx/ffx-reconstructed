// Function: sub_A9AD40
// Address: 0xa9ad40
// Size: 0x223
// Prototype: 

int __fastcall sub_A9AD40(int n2, int a2, float *a3, float *a4, int a5)
{
  int v5; // edi
  int v6; // edx
  int result; // eax
  float *v8; // edx
  float *v9; // esi
  float *v10; // edi
  float v11; // xmm0_4
  float *v12; // edx
  float *v13; // esi
  float *v14; // eax
  float *v15; // edi
  unsigned int v16; // eax
  float *v17; // ecx
  float *v18; // esi
  float *v19; // edi
  float v20; // xmm4_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  bool v23; // zf
  int v24; // edx
  int v25; // esi
  float *v26; // ecx
  int *v27; // edx
  float *v28; // esi
  float v29; // xmm0_4
  int v30; // [esp+8h] [ebp-38h]
  float *v31; // [esp+Ch] [ebp-34h]
  int v32; // [esp+Ch] [ebp-34h]
  int v33; // [esp+10h] [ebp-30h]
  int v34; // [esp+14h] [ebp-2Ch]
  int v35; // [esp+18h] [ebp-28h]
  int v36; // [esp+1Ch] [ebp-24h]
  int n2_1; // [esp+20h] [ebp-20h]
  int v38; // [esp+24h] [ebp-1Ch]
  float *v39; // [esp+28h] [ebp-18h]
  int v40; // [esp+2Ch] [ebp-14h]
  int v41; // [esp+30h] [ebp-10h]
  float *v42; // [esp+30h] [ebp-10h]
  int v43; // [esp+34h] [ebp-Ch]
  float *v44; // [esp+34h] [ebp-Ch]
  int v45; // [esp+38h] [ebp-8h]
  float *v46; // [esp+38h] [ebp-8h]
  float *v47; // [esp+3Ch] [ebp-4h]

  v5 = a2;
  v6 = a2 * n2;
  result = 2 * n2;
  v40 = v5;
  n2_1 = n2;
  v33 = v6;
  if ( v5 > 0 )
  {
    v41 = 4 * n2;
    v43 = 8 * n2;
    result = (int)a3;
    v8 = &a3[v6];
    v9 = a4;
    v45 = v5;
    v10 = &a4[2 * n2 - 1];
    do
    {
      *v9 = *(float *)result + *v8;
      v11 = *(float *)result - *v8;
      v9 = (float *)((char *)v9 + v43);
      result += v41;
      v8 = (float *)((char *)v8 + v41);
      *v10 = v11;
      v10 = (float *)((char *)v10 + v43);
      --v45;
    }
    while ( v45 );
    v5 = v40;
  }
  if ( n2 >= 2 )
  {
    if ( n2 == 2 )
      goto LABEL_16;
    if ( v5 > 0 )
    {
      v35 = 8 * n2;
      v36 = 4 * n2;
      v42 = a4;
      v46 = a3;
      v12 = a3;
      v13 = &a3[v33];
      v34 = v5;
      v47 = &a4[2 * n2];
      v14 = a4;
      v15 = v47;
      v44 = v13;
      do
      {
        if ( n2 > 2 )
        {
          v31 = v14;
          v39 = (float *)(a5 + 4);
          v16 = n2 - 3;
          v17 = v44;
          v18 = v15;
          v19 = v31;
          v38 = (v16 >> 1) + 1;
          do
          {
            v20 = v17[2];
            v17 += 2;
            v12 += 2;
            v21 = (float)(v20 * *v39) + (float)(*(v39 - 1) * *(v17 - 1));
            v22 = (float)(*(v39 - 1) * *v17) - (float)(*v39 * *(v17 - 1));
            v19 += 2;
            v18 -= 2;
            v23 = v38-- == 1;
            v39 += 2;
            *v19 = *v12 + v22;
            *v18 = v22 - *v12;
            *(v19 - 1) = v21 + *(v12 - 1);
            *(v18 - 1) = *(v12 - 1) - v21;
          }
          while ( !v23 );
          n2 = n2_1;
          v14 = v42;
          v12 = v46;
          v13 = v44;
          v15 = v47;
        }
        v15 = (float *)((char *)v15 + v35);
        v12 = (float *)((char *)v12 + v36);
        v13 = (float *)((char *)v13 + v36);
        v14 = (float *)((char *)v14 + v35);
        v23 = v34-- == 1;
        v47 = v15;
        v46 = v12;
        v44 = v13;
        v42 = v14;
      }
      while ( !v23 );
      v5 = v40;
    }
    result = n2 % 2;
    if ( n2 % 2 != 1 )
    {
LABEL_16:
      v24 = n2 - 1;
      v25 = v33 + n2 - 1;
      if ( v5 > 0 )
      {
        v30 = 8 * n2;
        v32 = 4 * n2;
        v26 = &a4[n2];
        v27 = (int *)&a3[v24];
        v28 = &a3[v25];
        do
        {
          v29 = *v28;
          v28 = (float *)((char *)v28 + v32);
          *v26 = -v29;
          result = *v27;
          v27 = (int *)((char *)v27 + v32);
          *((_DWORD *)v26 - 1) = result;
          v26 = (float *)((char *)v26 + v30);
          --v5;
        }
        while ( v5 );
      }
    }
  }
  return result;
}

