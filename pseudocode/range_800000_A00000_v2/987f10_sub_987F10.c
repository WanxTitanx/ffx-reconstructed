// Function: sub_987F10
// Address: 0x987f10
int __cdecl sub_987F10(int a1, int a2)
{
  int v2; // ecx
  int result; // eax
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // ecx
  __m128 *v9; // eax
  __m128 **v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // edi
  __m128 *v14; // edx
  __m128 *v15; // ecx
  __m128 *v16; // eax
  int v17; // eax
  __m128 v18; // xmm2
  int v19; // esi
  int v20; // ecx
  int v21; // edx
  float v22; // [esp-60h] [ebp-6Ch]
  float v23; // [esp-5Ch] [ebp-68h]
  float v24; // [esp-58h] [ebp-64h]
  float v25; // [esp-4Ch] [ebp-58h]
  float v26; // [esp-48h] [ebp-54h]
  __m128 *v27; // [esp-40h] [ebp-4Ch]
  int v28; // [esp-38h] [ebp-44h]
  int v29; // [esp-34h] [ebp-40h]
  __m128 *v30; // [esp-34h] [ebp-40h]
  __m128 v31; // [esp-30h] [ebp-3Ch]
  __m128 v32; // [esp-20h] [ebp-2Ch]

  v2 = a2;
  for ( result = a1; *(int *)(a2 + 4) > 1; --*(_DWORD *)(a2 + 4) )
  {
    v4 = *(_DWORD *)(v2 + 4);
    v5 = 0;
    v25 = 3.4028235e38;
    v29 = -1;
    v28 = -1;
    if ( v4 > 0 )
    {
      do
      {
        v6 = v5 + 1;
        v7 = v5 + 1;
        if ( v5 + 1 < v4 )
        {
          v8 = *(_DWORD *)(v2 + 12);
          v9 = *(__m128 **)(v8 + 4 * v5);
          v10 = (__m128 **)(v8 + 4 * v5 + 4);
          do
          {
            v31 = _mm_min_ps(*v9, **v10);
            v32 = _mm_max_ps(v9[1], (*v10)[1]);
            v22 = v32.m128_f32[0] - v31.m128_f32[0];
            v23 = v32.m128_f32[1] - v31.m128_f32[1];
            v24 = v32.m128_f32[2] - v31.m128_f32[2];
            v26 = v23 + v22 + v23 * v22 * v24 + v24;
            if ( v25 > (double)v26 )
            {
              v25 = v23 + v22 + v23 * v22 * v24 + v24;
              v29 = v5;
              v28 = v7;
            }
            ++v7;
            ++v10;
          }
          while ( v7 < v4 );
          v6 = v5 + 1;
          v2 = a2;
        }
        v5 = v6;
      }
      while ( v6 < v4 );
    }
    v11 = *(_DWORD *)(v2 + 12);
    v12 = v29;
    v13 = v28;
    v14 = *(__m128 **)(v11 + 4 * v29);
    v15 = *(__m128 **)(a1 + 4);
    v16 = *(__m128 **)(v11 + 4 * v28);
    v27 = v14;
    v30 = v16;
    if ( v15 )
    {
      *(_DWORD *)(a1 + 4) = 0;
      v13 = v28;
    }
    else
    {
      v17 = sub_9D4CE0(48, 16);
      v14 = v27;
      v15 = (__m128 *)v17;
      v16 = v30;
    }
    v15[2].m128_i32[0] = 0;
    v15[2].m128_i32[1] = 0;
    v15[2].m128_i32[2] = 0;
    v18 = _mm_max_ps(v14[1], v16[1]);
    *v15 = _mm_min_ps(*v14, *v16);
    v15[1] = v18;
    v15[2].m128_i32[1] = (__int32)v14;
    v15[2].m128_i32[2] = (__int32)v16;
    v14[2].m128_i32[0] = (__int32)v15;
    v16[2].m128_i32[0] = (__int32)v15;
    *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v12) = v15;
    v19 = *(_DWORD *)(a2 + 4);
    v20 = *(_DWORD *)(a2 + 12);
    v21 = *(_DWORD *)(v20 + 4 * v13);
    *(_DWORD *)(v20 + 4 * v13) = *(_DWORD *)(v20 + 4 * v19 - 4);
    v2 = a2;
    result = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(result + 4 * v19 - 4) = v21;
  }
  return result;
}
