// Function: sub_9C1900
// Address: 0x9c1900
double __userpurge sub_9C1900@<st0>(
        _DWORD *a1@<ecx>,
        char a2@<efl>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  int v11; // edx
  int v12; // ebx
  _DWORD *v13; // esi
  int v14; // eax
  int v15; // eax
  unsigned int n2; // edi
  int v17; // ebx
  unsigned int v18; // edx
  int v19; // edx
  int v20; // eax
  unsigned int n2_1; // edi
  int v22; // ebx
  unsigned int v23; // edx
  int v24; // edx
  int v25; // edi
  int v26; // ebx
  int v27; // edi
  int i_1; // ebx
  int i; // edi
  int j_1; // ebx
  int j; // edi
  __m128 *v32; // edx
  double v33; // st7
  int v34; // ebx
  int v35; // eax
  int v36; // edi
  int k_1; // ebx
  int k; // edi
  int v39; // eax
  int m_1; // ebx
  int m; // edi
  int v42; // edx
  int v43; // eax
  int v44; // ecx
  float v45; // xmm0_4
  bool v46; // cf
  bool v47; // zf
  bool v48; // sf
  bool v49; // of
  bool v50; // pf
  double v51; // st7
  __m128 *v53; // [esp-8h] [ebp-38h]
  float *v54; // [esp-8h] [ebp-38h]
  __m128 *v55; // [esp-4h] [ebp-34h]
  float *v56; // [esp-4h] [ebp-34h]
  int v57; // [esp+0h] [ebp-30h]
  float v58; // [esp+14h] [ebp-1Ch]
  int v59; // [esp+18h] [ebp-18h]
  int v60; // [esp+18h] [ebp-18h]
  int v61; // [esp+1Ch] [ebp-14h]
  int v63; // [esp+24h] [ebp-Ch]
  int v64; // [esp+28h] [ebp-8h]
  int v65; // [esp+2Ch] [ebp-4h]
  int v66; // [esp+2Ch] [ebp-4h]

  v11 = a9;
  LOBYTE(v12) = 0;
  v13 = a1;
  v61 = 0;
  if ( *(int *)(a9 + 20) > 0 )
  {
    do
    {
      v14 = v13[12];
      v63 = v13[2];
      v64 = v14;
      if ( (*(_BYTE *)(v11 + 60) & 1) != 0 && (v12 & 7) == 0 )
      {
        if ( (int)v13[2] > 0 )
        {
          v15 = 0;
          v65 = 0;
          n2 = 1;
          do
          {
            v17 = v13[19];
            v18 = 1664525 * v13[31] + 1013904223;
            v59 = *(_DWORD *)(v15 + v17);
            v13[31] = v18;
            if ( n2 <= 0x10000 )
            {
              v18 ^= HIWORD(v18);
              if ( n2 <= 0x100 )
              {
                v18 ^= v18 >> 8;
                if ( n2 <= 0x10 )
                {
                  v18 ^= v18 >> 4;
                  if ( n2 <= 4 )
                  {
                    v18 ^= v18 >> 2;
                    if ( n2 <= 2 )
                      v18 ^= v18 >> 1;
                  }
                }
              }
            }
            v19 = v18 % n2++;
            *(_DWORD *)(v65 + v17) = *(_DWORD *)(v17 + 4 * v19);
            *(_DWORD *)(v13[19] + 4 * v19) = v59;
            v15 = v65 + 4;
            v47 = v63-- == 1;
            v65 += 4;
          }
          while ( !v47 );
          v14 = v64;
        }
        if ( v14 > 0 )
        {
          v20 = 0;
          v66 = 0;
          n2_1 = 1;
          do
          {
            v22 = v13[24];
            v23 = 1664525 * v13[31] + 1013904223;
            v60 = *(_DWORD *)(v20 + v22);
            v13[31] = v23;
            if ( n2_1 <= 0x10000 )
            {
              v23 ^= HIWORD(v23);
              if ( n2_1 <= 0x100 )
              {
                v23 ^= v23 >> 8;
                if ( n2_1 <= 0x10 )
                {
                  v23 ^= v23 >> 4;
                  if ( n2_1 <= 4 )
                  {
                    v23 ^= v23 >> 2;
                    if ( n2_1 <= 2 )
                      v23 ^= v23 >> 1;
                  }
                }
              }
            }
            v24 = v23 % n2_1++;
            *(_DWORD *)(v66 + v22) = *(_DWORD *)(v22 + 4 * v24);
            *(_DWORD *)(v13[24] + 4 * v24) = v60;
            v20 = v66 + 4;
            v47 = v64-- == 1;
            v66 += 4;
          }
          while ( !v47 );
        }
      }
      v25 = 0;
      if ( (*(_DWORD *)(a9 + 60) & 0x100) != 0 )
      {
        if ( (int)v13[7] > 0 )
        {
          v26 = 0;
          do
          {
            sub_9BE980(*(__m128 **)(v26 + v13[9] + 128), *(__m128 **)(v26 + v13[9] + 132), (__m128 *)(v26 + v13[9]));
            ++v25;
            v26 += 192;
          }
          while ( v25 < v13[7] );
        }
        v27 = 0;
        if ( a8 > 0 )
        {
          do
          {
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a7 + 4 * v27) + 20))(
              *(_DWORD *)(a7 + 4 * v27),
              *(_DWORD *)(*(_DWORD *)(a7 + 4 * v27) + 20),
              *(_DWORD *)(*(_DWORD *)(a7 + 4 * v27) + 24),
              *(float *)(a9 + 12));
            ++v27;
          }
          while ( v27 < a8 );
          v13 = a1;
        }
        i_1 = v13[2];
        for ( i = 0; i < i_1; ++i )
        {
          v57 = v13[4] + 192 * *(_DWORD *)(v13[19] + 4 * i);
          sub_9BEEF0(*(__m128 **)(v57 + 128), *(__m128 **)(v57 + 132), (__m128 *)v57);
        }
        j_1 = v13[12];
        for ( j = 0; j < j_1; ++j )
        {
          v32 = (__m128 *)(v13[14] + 192 * *(_DWORD *)(v13[24] + 4 * j));
          v58 = *(float *)(192 * v32[7].m128_i32[3] + v13[4] + 96);
          if ( v58 > 0.0 )
          {
            v33 = v32[7].m128_f32[0] * v58;
            v55 = (__m128 *)v32[8].m128_i32[1];
            v53 = (__m128 *)v32[8].m128_i32[0];
            v32[9].m128_f32[1] = -v33;
            v32[9].m128_f32[2] = v33;
            sub_9BE980(v53, v55, v32);
          }
        }
      }
      else
      {
        if ( (int)v13[7] > 0 )
        {
          v34 = 0;
          do
          {
            v35 = v13[9];
            v46 = __CFADD__(v34, v35);
            v49 = __OFADD__(v34, v35);
            v47 = v34 + v35 == 0;
            v50 = __SETP__(v34 + v35, 0);
            v48 = v34 + v35 < 0;
            sub_9BE5E0(a2, *(float **)(v34 + v35 + 128), *(float **)(v34 + v35 + 132), (float *)(v34 + v35));
            ++v25;
            v34 += 192;
          }
          while ( v25 < v13[7] );
        }
        v36 = 0;
        if ( a8 > 0 )
        {
          do
          {
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(a7 + 4 * v36) + 20))(
              *(_DWORD *)(a7 + 4 * v36),
              *(_DWORD *)(*(_DWORD *)(a7 + 4 * v36) + 20),
              *(_DWORD *)(*(_DWORD *)(a7 + 4 * v36) + 24),
              *(float *)(a9 + 12));
            ++v36;
          }
          while ( v36 < a8 );
          v13 = a1;
        }
        k_1 = v13[2];
        for ( k = 0; k < k_1; ++k )
        {
          v39 = 192 * *(_DWORD *)(v13[19] + 4 * k);
          v46 = __CFADD__(v13[4], v39);
          v49 = __OFADD__(v13[4], v39);
          v47 = v13[4] + v39 == 0;
          v50 = __SETP__(v13[4] + v39, 0);
          v48 = v13[4] + v39 < 0;
          sub_9BEB70(a2, *(float **)(v13[4] + v39 + 128), *(float **)(v13[4] + v39 + 132), (float *)(v13[4] + v39));
        }
        m_1 = v13[12];
        for ( m = 0; m < m_1; ++m )
        {
          v42 = v13[14] + 192 * *(_DWORD *)(v13[24] + 4 * m);
          v43 = v13[4];
          v44 = 192 * *(_DWORD *)(v42 + 124);
          v45 = *(float *)(v44 + v43 + 96);
          v46 = v45 < 0.0;
          v50 = 0;
          v47 = v45 == 0.0;
          v48 = 0;
          v49 = 0;
          if ( v45 > 0.0 )
          {
            v51 = *(float *)(v42 + 112) * *(float *)(v44 + v43 + 96);
            v56 = *(float **)(v42 + 132);
            v54 = *(float **)(v42 + 128);
            *(float *)(v42 + 148) = -v51;
            *(float *)(v42 + 152) = v51;
            sub_9BE5E0(a2, v54, v56, (float *)v42);
          }
        }
      }
      v11 = a9;
      v12 = v61 + 1;
      v61 = v12;
    }
    while ( v12 < *(_DWORD *)(a9 + 20) );
  }
  (*(void (__thiscall **)(_DWORD *, int, int, int, int, int, int, int, int, int))(*v13 + 20))(
    v13,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    v11,
    a10,
    a11);
  return 0.0;
}
