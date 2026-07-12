// Function: sub_A926F0
// Address: 0xa926f0
// Size: 0x2c6
// Prototype: 

void *__fastcall sub_A926F0(int *a1, int a2, int a3)
{
  int n2; // eax
  double X; // xmm0_8
  double X_1; // xmm0_8
  size_t Count; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // esi
  float j; // xmm2_4
  float j_1; // xmm0_4
  int v15; // eax
  float v16; // xmm3_4
  int v17; // edx
  int v18; // ecx
  int v19; // esi
  float v20; // xmm2_4
  float v21; // xmm0_4
  int v23; // [esp+18h] [ebp-18h]
  float v24; // [esp+1Ch] [ebp-14h]
  float v25; // [esp+20h] [ebp-10h]
  int i; // [esp+20h] [ebp-10h]
  void *v27; // [esp+24h] [ebp-Ch]
  int v28; // [esp+28h] [ebp-8h]
  int v29; // [esp+28h] [ebp-8h]
  int v30; // [esp+2Ch] [ebp-4h]

  n2 = a1[3];
  v30 = 0;
  if ( n2 != 1 && n2 != 2 )
    return 0;
  X = (double)(a1[4] & 0x1FFFFF);
  if ( a1[4] < 0 )
    X = -X;
  v25 = ldexp(X, ((a1[4] >> 21) & 0x3FFu) - 788);
  X_1 = (double)(a1[5] & 0x1FFFFF);
  if ( a1[5] < 0 )
    X_1 = -X_1;
  v24 = ldexp(X_1, ((a1[5] >> 21) & 0x3FFu) - 788);
  Count = a2 * *a1;
  v27 = calloc_0(Count, 4u);
  memset(v27, 0, 4 * Count);
  if ( a1[3] == 1 )
  {
    v23 = sub_A929C0(a1);
    v15 = 0;
    v29 = 0;
    if ( a1[1] <= 0 )
      return v27;
    v16 = v25;
    v17 = a3;
    while ( 1 )
    {
      if ( !v17 )
        goto LABEL_30;
      if ( *(_BYTE *)(v29 + a1[2]) )
        break;
LABEL_38:
      v15 = v29 + 1;
      v29 = v15;
      if ( v15 >= a1[1] )
        return v27;
    }
    v15 = v29;
LABEL_30:
    v18 = *a1;
    v19 = 0;
    v20 = 0.0;
    for ( i = 1; v19 < *a1; v15 = v29 )
    {
      v21 = fabs((float)*(int *)(a1[8] + 4 * (v15 / i % v23))) * v24 + v16 + v20;
      if ( a1[7] )
        v20 = v21;
      v17 = a3;
      if ( a3 )
        *((float *)v27 + v19 + v18 * *(_DWORD *)(a3 + 4 * v30)) = v21;
      else
        *((float *)v27 + v19 + v30 * v18) = v21;
      v18 = *a1;
      ++v19;
      i *= v23;
    }
    ++v30;
    goto LABEL_38;
  }
  v9 = a1[3] - 2;
  if ( a1[3] == 2 )
  {
    v28 = 0;
    if ( a1[1] > 0 )
    {
      v10 = a3;
      while ( 1 )
      {
        if ( !v10 )
          goto LABEL_15;
        if ( *(_BYTE *)(v28 + a1[2]) )
          break;
LABEL_23:
        v9 = v28 + 1;
        v28 = v9;
        if ( v9 >= a1[1] )
          return v27;
      }
      v9 = v28;
LABEL_15:
      v11 = *a1;
      v12 = 0;
      for ( j = 0.0; v12 < *a1; ++v12 )
      {
        j_1 = fabs((float)*(int *)(a1[8] + 4 * (v12 + v9 * v11))) * v24 + v25 + j;
        if ( a1[7] )
          j = j_1;
        v10 = a3;
        if ( a3 )
        {
          *((float *)v27 + v12 + v11 * *(_DWORD *)(a3 + 4 * v30)) = j_1;
          v10 = a3;
        }
        else
        {
          *((float *)v27 + v12 + v30 * v11) = j_1;
        }
        v11 = *a1;
        v9 = v28;
      }
      ++v30;
      goto LABEL_23;
    }
  }
  return v27;
}

