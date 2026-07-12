// Function: sub_A96440
// Address: 0xa96440
// Size: 0x18a
// Prototype: 

int *__fastcall sub_A96440(int a1, int a2, int a3)
{
  void *v3; // esp
  char *v4; // ebx
  int *result; // eax
  void *v6; // esp
  int n2; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // edi
  float v11; // xmm1_4
  char *v12; // eax
  char *v13; // ebx
  float v14; // xmm0_4
  int n2_2; // esi
  int v16; // ebx
  int v17; // eax
  _DWORD *v18; // ebx
  unsigned int v19; // edi
  int v20; // ecx
  _DWORD v21[3]; // [esp+0h] [ebp-30h] BYREF
  int v22; // [esp+Ch] [ebp-24h]
  int v23; // [esp+10h] [ebp-20h]
  unsigned int v24; // [esp+14h] [ebp-1Ch]
  int v25; // [esp+18h] [ebp-18h]
  int v26; // [esp+1Ch] [ebp-14h]
  int v27; // [esp+20h] [ebp-10h]
  char *v28; // [esp+24h] [ebp-Ch]
  int n2_1; // [esp+28h] [ebp-8h]
  char *v30; // [esp+2Ch] [ebp-4h]

  v27 = a2;
  v26 = a1;
  v3 = alloca(4 * a3);
  v4 = (char *)v21;
  result = (int *)(4 * a3);
  v30 = (char *)v21;
  v6 = alloca(4 * a3);
  n2 = 0;
  v8 = 0;
  v9 = 0;
  n2_1 = 0;
  if ( a3 > 0 )
  {
    v10 = v26;
    do
    {
      if ( n2 >= 2 )
      {
        v11 = *(float *)(v10 + 4 * v9);
        if ( *(float *)&v21[n2 - 1] <= v11 )
        {
          v12 = v30;
          n2_1 = (char *)v21 - v30;
          v13 = &v30[4 * n2 - 8];
          while ( v9 < v27 + *(_DWORD *)&v12[4 * n2 - 4]
               && n2 > 1
               && *(float *)&v13[n2_1] >= *(float *)&v21[n2 - 1]
               && v9 < v27 + *(_DWORD *)v13 )
          {
            v14 = *(float *)&v21[n2 - 2];
            v12 = v30;
            --n2;
            v13 -= 4;
            if ( v14 > v11 )
            {
              v4 = v30;
              goto LABEL_13;
            }
          }
          v4 = v30;
        }
      }
LABEL_13:
      *(_DWORD *)&v4[4 * n2] = v9;
      result = *(int **)(v10 + 4 * v9);
      v21[n2] = result;
      ++v9;
      ++n2;
    }
    while ( v9 < a3 );
    n2_1 = n2;
    v8 = 0;
  }
  n2_2 = 0;
  if ( n2 > 0 )
  {
    result = (int *)(v4 + 4);
    v28 = (char *)((char *)v21 - v4);
    v30 = v4 + 4;
    do
    {
      if ( n2_2 >= n2 - 1 || *(float *)&v28[(_DWORD)result] <= *(float *)&v21[n2_2] )
      {
        v16 = *(result - 1) + v27 + 1;
        result = (int *)v30;
      }
      else
      {
        v16 = *result;
      }
      if ( v16 > a3 )
        v16 = a3;
      v22 = v16;
      if ( v8 < v16 )
      {
        if ( v16 - v8 >= 4 )
        {
          v25 = v26 + 4 * v8 + 8;
          v17 = v16;
          v18 = (_DWORD *)v25;
          v24 = ((unsigned int)(v17 - v8 - 4) >> 2) + 1;
          v23 = v8 + 4 * v24;
          v19 = v24;
          do
          {
            *(v18 - 2) = v21[n2_2];
            *(v18 - 1) = v21[n2_2];
            *v18 = v21[n2_2];
            v18[1] = v21[n2_2];
            v18 += 4;
            --v19;
          }
          while ( v19 );
          v8 = v23;
          v16 = v22;
        }
        if ( v8 < v16 )
        {
          v20 = v26;
          do
            *(_DWORD *)(v20 + 4 * v8++) = v21[n2_2];
          while ( v8 < v16 );
          n2 = n2_1;
        }
        result = (int *)v30;
      }
      ++n2_2;
      v30 = (char *)++result;
    }
    while ( n2_2 < n2 );
  }
  return result;
}

