// Function: sub_A9EB80
// Address: 0xa9eb80
// Size: 0x20c
// Prototype: 

_DWORD *__cdecl sub_A9EB80(_DWORD *a1, _DWORD *a2, int *a3, int a4, int a5)
{
  int v5; // ecx
  int v7; // eax
  int v8; // ebx
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // ecx
  size_t Size_1; // edx
  size_t Size; // ebx
  _DWORD *v14; // eax
  void *v15; // eax
  int v16; // eax
  void *v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  signed int v21; // esi
  int v22; // edx
  signed int v23; // eax
  int v24; // esi
  __int64 v25; // rax
  int v26; // eax
  int v27; // edx
  _DWORD *v28; // eax
  bool v29; // cc
  int v31; // [esp+4h] [ebp-24h]
  int v32; // [esp+Ch] [ebp-1Ch]
  int v33; // [esp+10h] [ebp-18h]
  _DWORD *v34; // [esp+14h] [ebp-14h]
  int v35; // [esp+18h] [ebp-10h]
  signed int v36; // [esp+18h] [ebp-10h]
  int v37; // [esp+1Ch] [ebp-Ch]
  int v38; // [esp+20h] [ebp-8h]
  _DWORD *v39; // [esp+24h] [ebp-4h]
  size_t Size_2; // [esp+40h] [ebp+18h]
  int v41; // [esp+40h] [ebp+18h]

  v5 = 0;
  v7 = 0;
  if ( a5 <= 0 )
    return 0;
  do
  {
    if ( *(_DWORD *)(a4 + 4 * v7) )
      ++v5;
    ++v7;
  }
  while ( v7 < a5 );
  if ( !v5 )
    return 0;
  v34 = (_DWORD *)*a2;
  v35 = *(_DWORD *)(*a2 + 12);
  v37 = *(_DWORD *)(*a2 + 8);
  v8 = (v34[1] - *v34) / v37;
  v32 = v8;
  if ( a1[18] + 8 > a1[19] )
  {
    if ( a1[17] )
    {
      v9 = malloc_0(8u);
      a1[20] += a1[18];
      v9[1] = a1[21];
      *v9 = a1[17];
      a1[21] = v9;
    }
    a1[19] = 8;
    a1[17] = malloc_0(8u);
    a1[18] = 0;
  }
  v10 = a1[18];
  v11 = a1[17];
  v39 = (_DWORD *)(v11 + v10);
  Size_1 = 4 * v8;
  v10 += 8;
  Size = (4 * v8 + 7) & 0xFFFFFFF8;
  a1[18] = v10;
  Size_2 = Size_1;
  if ( (signed int)(Size + v10) > a1[19] )
  {
    if ( v11 )
    {
      v14 = malloc_0(8u);
      a1[20] += a1[18];
      v14[1] = a1[21];
      *v14 = a1[17];
      a1[21] = v14;
    }
    a1[19] = Size;
    v15 = malloc_0(Size);
    Size_1 = Size_2;
    a1[17] = v15;
    a1[18] = 0;
  }
  v16 = a1[18];
  v17 = (void *)(v16 + a1[17]);
  a1[18] = Size + v16;
  *v39 = v17;
  memset(v17, 0, Size_1);
  v18 = *v34 / a5;
  v33 = 0;
  v41 = v18;
  if ( v32 > 0 )
  {
    v31 = v35 - 1;
    do
    {
      v19 = 0;
      v20 = 0;
      v21 = 0;
      v38 = 0;
      if ( v37 > 0 )
      {
        v22 = *a3;
        do
        {
          v23 = abs32(*(_DWORD *)(v22 + 4 * v18));
          if ( v23 > v21 )
            v21 = v23;
          v36 = v21;
          v24 = 1;
          if ( a5 > 1 )
          {
            do
            {
              v25 = *(int *)(a3[v24] + 4 * v41);
              v26 = (HIDWORD(v25) ^ v25) - HIDWORD(v25);
              if ( v26 > v19 )
                v19 = v26;
              ++v24;
            }
            while ( v24 < a5 );
            v20 = v38;
          }
          v21 = v36;
          v22 = *a3;
          v20 += a5;
          v18 = ++v41;
          v38 = v20;
        }
        while ( v20 < v37 );
      }
      v27 = 0;
      if ( v31 > 0 )
      {
        v28 = v34 + 646;
        do
        {
          if ( v21 <= *(v28 - 64) && v19 <= *v28 )
            break;
          ++v27;
          ++v28;
        }
        while ( v27 < v31 );
      }
      v29 = v33 + 1 < v32;
      *(_DWORD *)(*v39 + 4 * ++v33 - 4) = v27;
      v18 = v41;
    }
    while ( v29 );
  }
  ++a2[10];
  return v39;
}

