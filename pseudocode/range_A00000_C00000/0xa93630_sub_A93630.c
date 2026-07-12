// Function: sub_A93630
// Address: 0xa93630
// Size: 0x2f2
// Prototype: 

int __fastcall sub_A93630(int *a1, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // ebx
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // edi
  int v16; // eax
  int v17; // edx
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // edx
  int v21; // eax
  int v22; // edx
  int v23; // esi
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // edi
  int v34; // eax
  int v35; // ecx
  int v36; // edx
  int v37; // eax
  int v39; // edx
  int v40; // ebx
  int v41; // edi
  int v42; // [esp+Ch] [ebp-24h]
  char v44; // [esp+14h] [ebp-1Ch]
  unsigned int v45; // [esp+18h] [ebp-18h]
  int v46; // [esp+1Ch] [ebp-14h]
  int v47; // [esp+20h] [ebp-10h]
  int v48; // [esp+24h] [ebp-Ch]
  int v49; // [esp+24h] [ebp-Ch]
  int v50; // [esp+28h] [ebp-8h]

  v6 = 0;
  v47 = 0;
  if ( a1[2] <= 0 )
    return 0;
  v46 = a3 / a4;
  v42 = (a3 + a6) / a4;
  if ( a3 / a4 >= v42 )
    return 0;
  v7 = a5;
  while ( 1 )
  {
    v50 = a1[10];
    v8 = sub_42E840(v7, a1[9]);
    if ( v8 < 0 )
      break;
    v9 = *(_DWORD *)(a1[8] + 4 * v8);
    v48 = v9;
    if ( v9 < 0 )
    {
      v10 = (v9 >> 15) & 0x7FFF;
      v11 = a1[2] - (*(_DWORD *)(a1[8] + 4 * v8) & 0x7FFF);
      goto LABEL_12;
    }
    v12 = v7[4];
    v13 = v7[1] + *(char *)(a1[7] + v9 - 1);
    v14 = *v7;
    if ( *v7 <= v12 - ((v13 + 7) >> 3) )
    {
      v16 = v13 / 8;
      v7[3] += v13 / 8;
      v7[1] = v13 & 7;
      v15 = v48;
      *v7 = v14 + v16;
    }
    else
    {
      v15 = v48;
      v7[3] = 0;
      *v7 = v12;
      v7[1] = 1;
    }
    v10 = v15 - 1;
LABEL_23:
    if ( v10 == -1 )
      return -1;
    v32 = v10 * *a1;
    v33 = v46;
    v34 = a1[4] + 4 * v32;
    v35 = 0;
    if ( *a1 > 0 )
    {
      v36 = v34;
      do
      {
        v37 = *(_DWORD *)(a2 + 4 * v6++);
        *(float *)(v37 + 4 * v33) = *(float *)(v36 + 4 * v35) + *(float *)(v37 + 4 * v33);
        if ( v6 == a4 )
        {
          v6 = 0;
          ++v33;
        }
        ++v35;
      }
      while ( v35 < *a1 );
      v7 = a5;
      v46 = v33;
      v47 = v6;
    }
    if ( v33 >= v42 )
      return 0;
  }
  v10 = 0;
  v11 = a1[2];
LABEL_12:
  v49 = v11;
  v17 = sub_42E840(v7, v50);
  if ( v17 < 0 )
  {
    while ( v50 > 1 )
    {
      v17 = sub_42E840(v7, --v50);
      if ( v17 >= 0 )
        goto LABEL_15;
    }
    return -1;
  }
LABEL_15:
  v18 = __ROL4__(v17, 16);
  v19 = (v18 << 8) ^ (unsigned int)&unk_FF00FF & ((v18 << 8) ^ (v18 >> 8));
  v20 = (16 * v19) ^ ((16 * v19) ^ (v19 >> 4)) & 0xF0F0F0F;
  v21 = 2 * ((4 * v20) ^ ((4 * v20) ^ (v20 >> 2)) & 0x33333333);
  v45 = v21 ^ (v21 ^ (((4 * v20) ^ ((4 * v20) ^ (v20 >> 2)) & 0x33333333) >> 1)) & 0x55555555;
  v22 = v49 - v10;
  if ( v49 - v10 > 1 )
  {
    v23 = v49;
    v24 = a1[5];
    do
    {
      v25 = v22 >> 1;
      v26 = v45 < *(_DWORD *)(v24 + 4 * (v25 + v10));
      v27 = v25 & (v26 - 1);
      v23 -= v25 & -v26;
      v24 = a1[5];
      v10 += v27;
      v22 = v23 - v10;
    }
    while ( v23 - v10 > 1 );
    v7 = a5;
    v6 = v47;
  }
  v28 = *(char *)(a1[7] + v10);
  if ( v28 <= v50 )
  {
    v29 = v28 + v7[1];
    v44 = v28 + *((_BYTE *)v7 + 4);
    v30 = *v7;
    if ( *v7 <= v7[4] - ((v29 + 7) >> 3) )
    {
      v7[3] += v29 / 8;
      *v7 = v30 + v29 / 8;
      v7[1] = v44 & 7;
    }
    else
    {
      v31 = v7[4];
      v7[3] = 0;
      *v7 = v31;
      v7[1] = 1;
    }
    goto LABEL_23;
  }
  v39 = v7[4];
  v40 = *v7;
  v41 = v50 + v7[1];
  if ( *v7 > v39 - ((v41 + 7) >> 3) )
  {
    v7[3] = 0;
    *v7 = v39;
    v7[1] = 1;
    return -1;
  }
  v7[3] += v41 / 8;
  *v7 = v40 + v41 / 8;
  v7[1] = v41 & 7;
  return -1;
}

