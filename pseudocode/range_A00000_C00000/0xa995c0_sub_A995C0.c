// Function: sub_A995C0
// Address: 0xa995c0
// Size: 0x20c
// Prototype: 

int __fastcall sub_A995C0(int n2, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  bool v10; // zf
  int v11; // esi
  int v12; // edx
  int v13; // eax
  int v14; // edi
  float *v15; // eax
  float *v16; // edx
  unsigned int v17; // edi
  float *v18; // ecx
  int v19; // esi
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  int v23; // edi
  float *v24; // edx
  float *v25; // esi
  int v26; // ecx
  float v27; // xmm0_4
  int v28; // [esp+Ch] [ebp-24h]
  int v29; // [esp+10h] [ebp-20h]
  int v30; // [esp+10h] [ebp-20h]
  int n2_1; // [esp+14h] [ebp-1Ch]
  int v32; // [esp+18h] [ebp-18h]
  int v33; // [esp+1Ch] [ebp-14h]
  int v34; // [esp+20h] [ebp-10h]
  float *v35; // [esp+24h] [ebp-Ch]
  float *v36; // [esp+24h] [ebp-Ch]
  int v37; // [esp+28h] [ebp-8h]
  int v38; // [esp+28h] [ebp-8h]
  int v39; // [esp+2Ch] [ebp-4h]

  result = a2;
  v6 = a2 * n2;
  v7 = 0;
  v8 = 0;
  v34 = result;
  n2_1 = n2;
  v28 = v6;
  if ( result > 0 )
  {
    v35 = (float *)(a4 + 4 * v6);
    v37 = result;
    do
    {
      v9 = v8 + 2 * n2;
      *(float *)(a4 + 4 * v7) = *(float *)(a3 + 4 * v9 - 4) + *(float *)(a3 + 4 * v8);
      n2 = n2_1;
      v7 += n2_1;
      *v35 = *(float *)(a3 + 4 * v8) - *(float *)(a3 + 4 * v9 - 4);
      v10 = v37-- == 1;
      v35 += n2_1;
      v8 = 2 * v7;
    }
    while ( !v10 );
    result = v34;
  }
  if ( n2 >= 2 )
  {
    if ( n2 == 2 )
      goto LABEL_15;
    v11 = 0;
    v38 = 0;
    if ( result > 0 )
    {
      v39 = a4;
      v36 = (float *)(a4 + 4 * v6);
      v12 = a3;
      v29 = result;
      v13 = a4;
      do
      {
        v14 = v38;
        if ( n2 > 2 )
        {
          v33 = v39;
          v15 = (float *)(v12 + 4 * (v11 + 2 * n2));
          v16 = (float *)(v12 + 4 * v11);
          v17 = n2 - 3;
          v18 = v36;
          v19 = a5 + 4;
          v32 = (v17 >> 1) + 1;
          do
          {
            v20 = *(v15 - 3) + v16[1];
            v15 -= 2;
            v16 += 2;
            v18 += 2;
            *(float *)(v33 + 4) = v20;
            v21 = *(v16 - 1) - *(v15 - 1);
            v19 += 8;
            v10 = v32-- == 1;
            *(float *)(v33 + 8) = *v16 - *v15;
            v22 = *v15 + *v16;
            v33 += 8;
            *(v18 - 1) = (float)(*(float *)(v19 - 12) * v21) - (float)(*(float *)(v19 - 8) * v22);
            *v18 = (float)(*(float *)(v19 - 12) * v22) + (float)(*(float *)(v19 - 8) * v21);
          }
          while ( !v10 );
          n2 = n2_1;
          v14 = v38;
          v13 = v39;
        }
        v36 += n2;
        v13 += 4 * n2;
        v10 = v29-- == 1;
        v12 = a3;
        v38 = n2 + v14;
        v39 = v13;
        v11 = 2 * (n2 + v14);
      }
      while ( !v10 );
    }
    result = n2 % 2;
    if ( n2 % 2 != 1 )
    {
LABEL_15:
      v23 = v34;
      if ( v34 > 0 )
      {
        v30 = 8 * n2;
        v24 = (float *)(a3 - 4 + 4 * n2);
        v25 = (float *)(a4 - 4 + 4 * n2);
        result = a4 + 4 * (n2 + v28 - 1);
        v26 = 4 * n2;
        do
        {
          *v25 = *v24 + *v24;
          v27 = v24[1];
          v24 = (float *)((char *)v24 + v30);
          v25 = (float *)((char *)v25 + v26);
          *(float *)result = -(float)(v27 + v27);
          result += v26;
          --v23;
        }
        while ( v23 );
      }
    }
  }
  return result;
}

