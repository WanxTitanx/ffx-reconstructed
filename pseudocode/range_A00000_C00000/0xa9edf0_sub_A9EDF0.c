// Function: sub_A9EDF0
// Address: 0xa9edf0
// Size: 0x274
// Prototype: 

int *__cdecl sub_A9EDF0(_DWORD *a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  int v5; // edx
  int v6; // ebx
  _DWORD *v7; // ecx
  unsigned int v8; // edi
  _DWORD *v9; // eax
  int v10; // edx
  int v11; // eax
  int *v12; // ecx
  float v13; // xmm1_4
  int v14; // eax
  int v15; // ebx
  size_t Size; // edi
  _DWORD *v17; // eax
  int v18; // eax
  void *v19; // ecx
  int v20; // ecx
  _DWORD *v21; // esi
  int v22; // edi
  int *v23; // ecx
  int v24; // ebx
  int v25; // esi
  int v26; // edi
  int v27; // ebx
  int *v28; // ecx
  signed int v29; // eax
  int v30; // edx
  int v31; // edi
  int *v32; // eax
  int v33; // eax
  bool v34; // zf
  int v36; // [esp+10h] [ebp-2Ch]
  int v37; // [esp+18h] [ebp-24h]
  int v38; // [esp+1Ch] [ebp-20h]
  int v39; // [esp+20h] [ebp-1Ch]
  int *v40; // [esp+24h] [ebp-18h]
  int v41; // [esp+28h] [ebp-14h]
  _DWORD *v42; // [esp+2Ch] [ebp-10h]
  int *v43; // [esp+30h] [ebp-Ch]
  int v44; // [esp+34h] [ebp-8h]
  int v45; // [esp+38h] [ebp-4h]
  int v46; // [esp+54h] [ebp+18h]

  v5 = a5;
  v6 = 0;
  if ( a5 <= 0 )
    return 0;
  v7 = a3;
  do
  {
    if ( *(_DWORD *)((char *)v7 + a4 - (_DWORD)a3) )
      a3[v6++] = *v7;
    ++v7;
    --v5;
  }
  while ( v5 );
  v45 = v6;
  if ( !v6 )
    return 0;
  v42 = (_DWORD *)*a2;
  v37 = *(_DWORD *)(*a2 + 12);
  v46 = *(_DWORD *)(*a2 + 8);
  v8 = (4 * v6 + 7) & 0xFFFFFFF8;
  v44 = (v42[1] - *v42) / v46;
  if ( (signed int)(v8 + a1[18]) > a1[19] )
  {
    if ( a1[17] )
    {
      v9 = malloc_0(8u);
      a1[20] += a1[18];
      v9[1] = a1[21];
      *v9 = a1[17];
      a1[21] = v9;
    }
    a1[19] = v8;
    a1[17] = malloc_0((4 * v6 + 7) & 0xFFFFFFF8);
    a1[18] = 0;
  }
  v10 = v46;
  v11 = a1[18];
  v12 = (int *)(v11 + a1[17]);
  a1[18] = v8 + v11;
  v14 = v6;
  v15 = 0;
  v40 = v12;
  if ( v45 > 0 )
  {
    Size = (4 * v44 + 7) & 0xFFFFFFF8;
    do
    {
      if ( (signed int)(Size + a1[18]) > a1[19] )
      {
        if ( a1[17] )
        {
          v17 = malloc_0(8u);
          a1[20] += a1[18];
          v17[1] = a1[21];
          *v17 = a1[17];
          a1[21] = v17;
        }
        a1[19] = Size;
        a1[17] = malloc_0(Size);
        a1[18] = 0;
      }
      v18 = a1[18];
      v19 = (void *)(v18 + a1[17]);
      a1[18] = Size + v18;
      v40[v15] = (int)v19;
      memset(v19, 0, 4 * v44);
      v14 = v45;
      ++v15;
    }
    while ( v15 < v45 );
    v10 = v46;
  }
  v20 = 0;
  v41 = 0;
  if ( v44 > 0 )
  {
    v21 = v42;
    v22 = 0;
    v38 = 0;
    do
    {
      v36 = v22 + *v21;
      if ( v14 > 0 )
      {
        v23 = v40;
        v24 = v37 - 1;
        v43 = v40;
        v39 = v14;
        do
        {
          v25 = 0;
          v26 = 0;
          if ( v10 > 0 )
          {
            v27 = v10;
            v28 = (int *)(*(int *)((char *)v23 + (char *)a3 - (char *)v40) + 4 * v36);
            do
            {
              v29 = abs32(*v28);
              if ( v29 > v25 )
                v25 = v29;
              v26 += v29;
              ++v28;
              --v27;
            }
            while ( v27 );
            v24 = v37 - 1;
            v23 = v43;
          }
          v30 = 0;
          v13 = 100.0 / (double)v46;
          v31 = (int)(float)((float)v26 * v13);
          if ( v24 > 0 )
          {
            v32 = v42 + 646;
            do
            {
              if ( v25 <= *(v32 - 64) && (*v32 < 0 || v31 < *v32) )
                break;
              ++v30;
              ++v32;
            }
            while ( v30 < v24 );
            v23 = v43;
          }
          v33 = *v23++;
          v34 = v39-- == 1;
          *(_DWORD *)(v33 + 4 * v41) = v30;
          v10 = v46;
          v43 = v23;
        }
        while ( !v34 );
        v14 = v45;
        v22 = v38;
        v20 = v41;
        v21 = v42;
      }
      ++v20;
      v22 += v10;
      v41 = v20;
      v38 = v22;
    }
    while ( v20 < v44 );
  }
  ++a2[10];
  return v40;
}

