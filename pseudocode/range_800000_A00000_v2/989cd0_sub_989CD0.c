// Function: sub_989CD0
// Address: 0x989cd0
int __cdecl sub_989CD0(int a1, int a2, int a3, float *a4, float *a5)
{
  int v5; // edi
  int v6; // ecx
  _DWORD *v7; // eax
  int v8; // edx
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // ecx
  int result; // eax
  int v13; // edx
  double v14; // st7
  double v15; // st6
  float *v16; // eax
  double v17; // st7
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // ecx
  int j_1; // eax
  int j_2; // edx
  int *v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  _DWORD *v28; // ecx
  int i_1; // eax
  int i_2; // edx
  int *v31; // ecx
  float v32; // [esp-50h] [ebp-5Ch]
  float v33; // [esp-4Ch] [ebp-58h]
  float v34; // [esp-48h] [ebp-54h]
  float v35; // [esp-40h] [ebp-4Ch]
  float v36; // [esp-3Ch] [ebp-48h]
  float v37; // [esp-38h] [ebp-44h]
  float v38; // [esp-30h] [ebp-3Ch]
  float v39; // [esp-2Ch] [ebp-38h]
  float v40; // [esp-28h] [ebp-34h]
  int v41; // [esp-18h] [ebp-24h]
  int j; // [esp-14h] [ebp-20h]
  int i; // [esp-14h] [ebp-20h]
  int v44; // [esp-10h] [ebp-1Ch]
  int v45; // [esp-10h] [ebp-1Ch]
  float v46; // [esp-Ch] [ebp-18h]
  int v47; // [esp-Ch] [ebp-18h]
  _DWORD *v48; // [esp-Ch] [ebp-18h]
  _DWORD *v49; // [esp-8h] [ebp-14h]
  int v50; // [esp-8h] [ebp-14h]
  int v51; // [esp-4h] [ebp-10h]

  v5 = *(_DWORD *)(a2 + 4);
  if ( v5 < 0 )
  {
    if ( *(int *)(a2 + 8) < 0 )
    {
      if ( *(_DWORD *)(a2 + 12) )
      {
        if ( *(_BYTE *)(a2 + 16) )
          sub_9D4D50(*(_DWORD *)(a2 + 12));
        *(_DWORD *)(a2 + 12) = 0;
      }
      *(_BYTE *)(a2 + 16) = 1;
      *(_DWORD *)(a2 + 12) = 0;
      *(_DWORD *)(a2 + 8) = 0;
    }
    v6 = 4 * v5;
    do
    {
      v7 = (_DWORD *)(v6 + *(_DWORD *)(a2 + 12));
      if ( v7 )
        *v7 = 0;
      v6 += 4;
    }
    while ( v6 < 0 );
  }
  *(_DWORD *)(a2 + 4) = 0;
  v8 = *(_DWORD *)(a3 + 4);
  v44 = v8;
  if ( v8 < 0 )
  {
    if ( *(int *)(a3 + 8) < 0 )
    {
      if ( *(_DWORD *)(a3 + 12) )
      {
        if ( *(_BYTE *)(a3 + 16) )
        {
          sub_9D4D50(*(_DWORD *)(a3 + 12));
          v8 = v44;
        }
        *(_DWORD *)(a3 + 12) = 0;
      }
      *(_BYTE *)(a3 + 16) = 1;
      *(_DWORD *)(a3 + 12) = 0;
      *(_DWORD *)(a3 + 8) = 0;
    }
    if ( v8 < 0 )
    {
      v9 = 4 * v8;
      do
      {
        v10 = (_DWORD *)(v9 + *(_DWORD *)(a3 + 12));
        if ( v10 )
          *v10 = 0;
        v9 += 4;
      }
      while ( v9 < 0 );
    }
  }
  v11 = a1;
  *(_DWORD *)(a3 + 4) = 0;
  result = *(_DWORD *)(a1 + 4);
  v13 = 0;
  v51 = 0;
  v41 = result;
  if ( result > 0 )
  {
    v14 = 0.5;
    v15 = 0.0;
    while ( 1 )
    {
      v45 = *(_DWORD *)(v11 + 12);
      v16 = *(float **)(v45 + 4 * v13);
      v38 = v16[4] + *v16;
      v39 = v16[5] + v16[1];
      v40 = v16[6] + v16[2];
      v35 = v38 * v14;
      v36 = v39 * v14;
      v37 = v14 * v40;
      v32 = v35 - *a4;
      v33 = v36 - a4[1];
      v34 = v37 - a4[2];
      v46 = v32 * *a5 + a5[1] * v33 + a5[2] * v34;
      v17 = v15;
      if ( v15 <= v46 )
      {
        v25 = *(_DWORD *)(a3 + 8);
        v26 = *(_DWORD *)(a3 + 4);
        if ( v26 == v25 )
        {
          v27 = v26 ? 2 * v26 : 1;
          v50 = v27;
          if ( v25 < v27 )
          {
            if ( v27 )
            {
              v28 = (_DWORD *)sub_9D4CE0(4 * v27, 16);
              v48 = v28;
            }
            else
            {
              v28 = 0;
              v48 = 0;
            }
            i_1 = *(_DWORD *)(a3 + 4);
            i_2 = 0;
            for ( i = i_1; i_2 < i_1; ++v28 )
            {
              if ( v28 )
              {
                *v28 = *(_DWORD *)(*(_DWORD *)(a3 + 12) + 4 * i_2);
                i_1 = i;
              }
              ++i_2;
            }
            if ( *(_DWORD *)(a3 + 12) )
            {
              if ( *(_BYTE *)(a3 + 16) )
                sub_9D4D50(*(_DWORD *)(a3 + 12));
              *(_DWORD *)(a3 + 12) = 0;
            }
            v17 = 0.0;
            v13 = v51;
            *(_DWORD *)(a3 + 12) = v48;
            *(_BYTE *)(a3 + 16) = 1;
            *(_DWORD *)(a3 + 8) = v50;
          }
        }
        result = *(_DWORD *)(a3 + 12);
        v31 = (int *)(result + 4 * *(_DWORD *)(a3 + 4));
        if ( v31 )
        {
          result = *(_DWORD *)(v45 + 4 * v13);
          *v31 = result;
        }
        ++*(_DWORD *)(a3 + 4);
      }
      else
      {
        v18 = *(_DWORD *)(a2 + 8);
        v19 = *(_DWORD *)(a2 + 4);
        if ( v19 == v18 )
        {
          v20 = v19 ? 2 * v19 : 1;
          v47 = v20;
          if ( v18 < v20 )
          {
            if ( v20 )
            {
              v21 = (_DWORD *)sub_9D4CE0(4 * v20, 16);
              v49 = v21;
            }
            else
            {
              v21 = 0;
              v49 = 0;
            }
            j_1 = *(_DWORD *)(a2 + 4);
            j_2 = 0;
            for ( j = j_1; j_2 < j_1; ++v21 )
            {
              if ( v21 )
              {
                *v21 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * j_2);
                j_1 = j;
              }
              ++j_2;
            }
            if ( *(_DWORD *)(a2 + 12) )
            {
              if ( *(_BYTE *)(a2 + 16) )
                sub_9D4D50(*(_DWORD *)(a2 + 12));
              *(_DWORD *)(a2 + 12) = 0;
            }
            v17 = 0.0;
            v13 = v51;
            *(_DWORD *)(a2 + 12) = v49;
            *(_BYTE *)(a2 + 16) = 1;
            *(_DWORD *)(a2 + 8) = v47;
          }
        }
        result = *(_DWORD *)(a2 + 12);
        v24 = (int *)(result + 4 * *(_DWORD *)(a2 + 4));
        if ( v24 )
        {
          result = *(_DWORD *)(v45 + 4 * v13);
          *v24 = result;
        }
        ++*(_DWORD *)(a2 + 4);
      }
      v11 = a1;
      v51 = ++v13;
      if ( v13 >= v41 )
        break;
      v15 = v17;
      v14 = 0.5;
    }
  }
  return result;
}
