// Function: sub_A9FEA0
// Address: 0xa9fea0
// Size: 0x248
// Prototype: 

_DWORD *__cdecl sub_A9FEA0(int a1, int a2)
{
  _DWORD *v2; // ebx
  int v3; // edx
  size_t Count; // esi
  int *v5; // eax
  void *v6; // edi
  int v7; // edx
  int v8; // eax
  unsigned int v9; // eax
  signed int Count_1; // edi
  signed int Count_3; // eax
  void *v12; // esi
  signed int Count_2; // esi
  int v14; // eax
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edx
  int v18; // edi
  size_t Size; // ecx
  int v20; // esi
  int v21; // edi
  int v22; // esi
  int v24; // [esp+Ch] [ebp-1Ch]
  int v25; // [esp+10h] [ebp-18h]
  _DWORD *v26; // [esp+14h] [ebp-14h]
  int v27; // [esp+14h] [ebp-14h]
  _DWORD *v28; // [esp+18h] [ebp-10h]
  signed int Count_4; // [esp+1Ch] [ebp-Ch]
  int v30; // [esp+20h] [ebp-8h]
  int v31; // [esp+24h] [ebp-4h]
  int v32; // [esp+30h] [ebp+8h]
  int v33; // [esp+30h] [ebp+8h]
  int v34; // [esp+34h] [ebp+Ch]

  v2 = calloc_0(1u, 0x2Cu);
  v26 = v2;
  memset(v2, 0, 0x2Cu);
  v30 = 0;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 28);
  *v2 = a2;
  v2[1] = *(_DWORD *)(a2 + 12);
  Count = v2[1];
  v2[3] = *(_DWORD *)(v3 + 2848);
  v24 = v3;
  v5 = (int *)(*(_DWORD *)(v3 + 2848) + 56 * *(_DWORD *)(a2 + 20));
  v2[4] = v5;
  Count_4 = 0;
  v31 = *v5;
  v6 = calloc_0(Count, 4u);
  memset(v6, 0, 4 * Count);
  v7 = 0;
  v2[5] = v6;
  v32 = 0;
  if ( (int)v2[1] > 0 )
  {
    v8 = a2 + 24;
    do
    {
      v9 = *(_DWORD *)(v8 + 4 * v7);
      Count_1 = 0;
      if ( v9 )
      {
        do
        {
          ++Count_1;
          v9 >>= 1;
        }
        while ( v9 );
        if ( Count_1 )
        {
          Count_3 = Count_4;
          if ( Count_1 > Count_4 )
            Count_3 = Count_1;
          Count_4 = Count_3;
          v12 = calloc_0(Count_1, 4u);
          memset(v12, 0, 4 * Count_1);
          v7 = v32;
          *(_DWORD *)(v2[5] + 4 * v32) = v12;
          Count_2 = 0;
          v14 = 1;
          if ( Count_1 > 0 )
          {
            v15 = (_DWORD *)(a2 + 4 * (v30 + 70));
            v28 = v15;
            do
            {
              v2 = v26;
              if ( (v14 & *(_DWORD *)(a2 + 24 + 4 * v7)) != 0 )
              {
                ++v30;
                v2 = v26;
                *(_DWORD *)(*(_DWORD *)(v26[5] + 4 * v32) + 4 * Count_2) = *(_DWORD *)(v24 + 2848) + 56 * *v15;
                v7 = v32;
                v15 = ++v28;
              }
              v14 = __ROL4__(v14, 1);
              ++Count_2;
            }
            while ( Count_2 < Count_1 );
          }
        }
      }
      v8 = a2 + 24;
      v32 = ++v7;
    }
    while ( v7 < v2[1] );
  }
  v2[6] = 1;
  if ( v31 > 0 )
  {
    v16 = 1;
    v17 = v31;
    do
    {
      v16 *= v2[1];
      --v17;
    }
    while ( v17 );
    v2[6] = v16;
  }
  v2[2] = Count_4;
  v18 = 0;
  v2[7] = malloc_0(4 * v2[6]);
  v25 = 0;
  if ( (int)v2[6] > 0 )
  {
    Size = 4 * v31;
    do
    {
      v34 = v18;
      v20 = v2[6] / v2[1];
      v33 = v20;
      v27 = 4 * v18;
      *(_DWORD *)(v2[7] + 4 * v18) = malloc_0(Size);
      if ( v31 > 0 )
      {
        v21 = 0;
        do
        {
          ++v21;
          v22 = v34 / v20;
          v34 -= v33 * v22;
          v33 /= (int)v2[1];
          *(_DWORD *)(*(_DWORD *)(v2[7] + v27) + 4 * v21 - 4) = v22;
          v20 = v33;
        }
        while ( v21 < v31 );
        v18 = v25;
      }
      Size = 4 * v31;
      v25 = ++v18;
    }
    while ( v18 < v2[6] );
  }
  return v2;
}

