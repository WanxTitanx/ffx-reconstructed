// Function: sub_A93E20
// Address: 0xa93e20
// Size: 0x3a5
// Prototype: 

int __cdecl sub_A93E20(int *a1, int a2, int *a3, int a4)
{
  int *v4; // edi
  int n4; // ebx
  void *v6; // esp
  void *v7; // esp
  int *v8; // esi
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // edx
  int v16; // edi
  int v17; // ebx
  int v18; // edi
  int v19; // eax
  int v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int v32; // eax
  int v33; // ebx
  int v34; // ecx
  int v35; // edi
  int v36; // ebx
  _DWORD *v37; // edx
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // esi
  int v42; // ecx
  int n4_1; // edx
  int *v44; // edi
  unsigned int v45; // ebx
  float v46; // xmm0_4
  int v47; // eax
  float v48; // xmm0_4
  int v49; // eax
  float v50; // xmm0_4
  int v51; // eax
  float *v52; // ecx
  int v53; // eax
  float v54; // xmm0_4
  _DWORD v56[2]; // [esp+0h] [ebp-30h] BYREF
  int v57; // [esp+8h] [ebp-28h] BYREF
  int v58; // [esp+Ch] [ebp-24h]
  int v59; // [esp+10h] [ebp-20h]
  unsigned int v60; // [esp+14h] [ebp-1Ch]
  int n4_2; // [esp+1Ch] [ebp-14h]
  _DWORD *v62; // [esp+20h] [ebp-10h]
  int v63; // [esp+24h] [ebp-Ch]
  int v64; // [esp+28h] [ebp-8h]
  int v65; // [esp+2Ch] [ebp-4h]

  v4 = a1;
  if ( a1[2] <= 0 )
    return 0;
  n4 = a4 / *a1;
  n4_2 = n4;
  v6 = alloca(4 * n4);
  v7 = alloca(4 * n4);
  v63 = 0;
  if ( n4 <= 0 )
  {
LABEL_31:
    v40 = 0;
    v41 = 0;
    v65 = 0;
    if ( *v4 > 0 )
    {
      v42 = a2;
      v64 = a2;
      do
      {
        n4_1 = 0;
        if ( n4 >= 4 )
        {
          v44 = &v57;
          v45 = ((unsigned int)(n4 - 4) >> 2) + 1;
          n4_1 = 4 * v45;
          do
          {
            v42 += 16;
            v46 = *(float *)(*(v44 - 2) + 4 * v41) + *(float *)(v42 - 16);
            v47 = *(v44 - 1);
            v44 += 4;
            *(float *)(v42 - 16) = v46;
            v48 = *(float *)(v47 + 4 * v41) + *(float *)(v42 - 12);
            v49 = *(v44 - 4);
            *(float *)(v42 - 12) = v48;
            v50 = *(float *)(v49 + 4 * v41) + *(float *)(v42 - 8);
            v51 = *(v44 - 3);
            *(float *)(v42 - 8) = v50;
            *(float *)(v42 - 4) = *(float *)(v51 + 4 * v41) + *(float *)(v42 - 4);
            --v45;
          }
          while ( v45 );
          v4 = a1;
          n4 = n4_2;
          v40 = v65;
          v42 = v64;
        }
        if ( n4_1 < n4 )
        {
          v52 = (float *)(a2 + 4 * (n4_1 + v40));
          do
          {
            v53 = v56[n4_1++];
            v54 = *(float *)(v53 + 4 * v41) + *v52++;
            *(v52 - 1) = v54;
          }
          while ( n4_1 < n4 );
          v4 = a1;
          v40 = v65;
          v42 = v64;
        }
        ++v41;
        v40 += n4;
        v42 += 4 * n4;
        v65 = v40;
        v64 = v42;
      }
      while ( v41 < *v4 );
    }
    return 0;
  }
  v58 = 0;
  v8 = a3;
  v62 = v56;
  while ( 1 )
  {
    v9 = v4[10];
    v10 = v4[9];
    v64 = v9;
    v11 = sub_42E840(v8, v10);
    if ( v11 < 0 )
    {
      v13 = 0;
      v14 = a1[2];
    }
    else
    {
      v12 = *(_DWORD *)(v4[8] + 4 * v11);
      v65 = v12;
      if ( v12 >= 0 )
      {
        v15 = v8[4];
        v16 = v8[1] + *(char *)(v4[7] + v12 - 1);
        v17 = *v8;
        if ( *v8 <= v15 - ((v16 + 7) >> 3) )
        {
          v19 = v16 / 8;
          v8[3] += v16 / 8;
          v8[1] = v16 & 7;
          v18 = v65;
          *v8 = v17 + v19;
        }
        else
        {
          v18 = v65;
          v8[3] = 0;
          *v8 = v15;
          v8[1] = 1;
        }
        v13 = v18 - 1;
        goto LABEL_29;
      }
      v13 = (v12 >> 15) & 0x7FFF;
      v14 = a1[2] - (v12 & 0x7FFF);
    }
    v65 = v14;
    v20 = sub_42E840(v8, v9);
    if ( v20 < 0 )
    {
      while ( v9 > 1 )
      {
        v64 = --v9;
        v20 = sub_42E840(v8, v9);
        if ( v20 >= 0 )
          goto LABEL_17;
      }
      if ( v20 < 0 )
        goto LABEL_28;
    }
LABEL_17:
    v21 = __ROL4__(v20, 16);
    v22 = (v21 << 8) ^ (unsigned int)&unk_FF00FF & ((v21 << 8) ^ (v21 >> 8));
    v23 = (16 * v22) ^ ((16 * v22) ^ (v22 >> 4)) & 0xF0F0F0F;
    v24 = 2 * ((4 * v23) ^ ((4 * v23) ^ (v23 >> 2)) & 0x33333333);
    v60 = v24 ^ (v24 ^ (((4 * v23) ^ ((4 * v23) ^ (v23 >> 2)) & 0x33333333) >> 1)) & 0x55555555;
    v25 = v65 - v13;
    if ( v65 - v13 > 1 )
    {
      v26 = v65;
      v27 = a1[5];
      v59 = v27;
      do
      {
        v28 = v25 >> 1;
        v29 = v60 < *(_DWORD *)(v27 + 4 * (v28 + v13));
        v30 = v28 & (v29 - 1);
        v26 -= v28 & -v29;
        v27 = v59;
        v13 += v30;
        v25 = v26 - v13;
      }
      while ( v26 - v13 > 1 );
      v8 = a3;
      v9 = v64;
    }
    v31 = v8[4];
    v32 = *(char *)(a1[7] + v13);
    if ( v32 > v9 )
    {
      v35 = v9 + v8[1];
      v36 = *v8;
      if ( *v8 <= v31 - ((v35 + 7) >> 3) )
      {
        v8[3] += v35 / 8;
        *v8 = v36 + v35 / 8;
        v8[1] = v35 & 7;
      }
      else
      {
        v8[3] = 0;
        *v8 = v31;
        v8[1] = 1;
      }
LABEL_28:
      v13 = -1;
      goto LABEL_29;
    }
    v33 = v32 + v8[1];
    v34 = *v8;
    if ( *v8 <= v31 - ((v33 + 7) >> 3) )
    {
      v8[3] += v33 / 8;
      *v8 = v34 + v33 / 8;
      v8[1] = v33 & 7;
    }
    else
    {
      v8[3] = 0;
      *v8 = v31;
      v8[1] = 1;
    }
LABEL_29:
    v37 = v62;
    *(_DWORD *)((char *)v62 + v58) = v13;
    if ( v13 == -1 )
      return -1;
    n4 = n4_2;
    v38 = v13 * *a1;
    v4 = a1;
    v39 = a1[4];
    v62 = v37 + 1;
    *v37 = v39 + 4 * v38;
    if ( ++v63 >= n4 )
      goto LABEL_31;
  }
}

