// Function: sub_9A1D10
// Address: 0x9a1d10
void __thiscall sub_9A1D10(int this, int a2, int a3, int a4)
{
  int n128; // eax
  int n124_1; // edi
  int v7; // ecx
  int i_1; // eax
  _DWORD *v9; // edx
  int i; // edi
  int v11; // ecx
  int n1024; // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  __m128 *v16; // edx
  __m128 *v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // ecx
  int v21; // eax
  int v22; // edi
  _DWORD *v23; // edx
  int v24; // ecx
  _DWORD *v25; // eax
  __int32 v26; // ecx
  int v27; // eax
  __int32 v28; // ecx
  int v29; // eax
  __int32 v30; // eax
  int v31; // ecx
  __int32 v32; // edx
  __int32 v33; // ecx
  __int32 v34; // edx
  int v35; // eax
  __int32 v36; // edx
  int v37; // ecx
  __int32 v38; // edx
  int v39; // ecx
  __int32 v40; // edx
  int v41; // ecx
  int v42; // ecx
  int v43; // ecx
  int v44; // eax
  __int32 v45; // ecx
  __int32 v46; // ecx
  int v47; // eax
  __m128 v48; // [esp-30h] [ebp-3Ch]
  int v49; // [esp-1Ch] [ebp-28h]
  int v50; // [esp-18h] [ebp-24h]
  int n124; // [esp-10h] [ebp-1Ch]
  int v52; // [esp-10h] [ebp-1Ch]
  int i_2; // [esp-Ch] [ebp-18h]
  int v54; // [esp-Ch] [ebp-18h]
  int v55; // [esp-8h] [ebp-14h]
  __m128 *v56; // [esp-8h] [ebp-14h]
  int n128_1; // [esp-4h] [ebp-10h]
  __m128 *v58; // [esp-4h] [ebp-10h]

  if ( a2 && a3 )
  {
    n128 = *(_DWORD *)(this + 24);
    n124_1 = 1;
    n124 = 124;
    n128_1 = n128;
    if ( n128 < 128 )
    {
      if ( *(int *)(this + 28) < 128 )
      {
        v7 = sub_9D4CE0(1024, 16);
        i_1 = *(_DWORD *)(this + 24);
        v55 = v7;
        i_2 = i_1;
        if ( i_1 > 0 )
        {
          v9 = (_DWORD *)v7;
          for ( i = 0; i < i_1; ++i )
          {
            if ( v9 )
            {
              v11 = *(_DWORD *)(this + 32);
              *v9 = *(_DWORD *)(v11 + 8 * i);
              v9[1] = *(_DWORD *)(v11 + 8 * i + 4);
              i_1 = i_2;
            }
            v9 += 2;
          }
          n124_1 = 1;
        }
        if ( *(_DWORD *)(this + 32) )
        {
          if ( *(_BYTE *)(this + 36) )
            sub_9D4D50(*(_DWORD *)(this + 32));
          *(_DWORD *)(this + 32) = 0;
        }
        *(_DWORD *)(this + 32) = v55;
        n128 = n128_1;
        *(_BYTE *)(this + 36) = 1;
        *(_DWORD *)(this + 28) = 128;
      }
      if ( n128 < 128 )
      {
        n1024 = 8 * n128;
        do
        {
          v13 = (_DWORD *)(n1024 + *(_DWORD *)(this + 32));
          if ( v13 )
          {
            *v13 = v48.m128_i32[2];
            v13[1] = v48.m128_i32[3];
          }
          n1024 += 8;
        }
        while ( n1024 < 1024 );
        n124_1 = 1;
      }
    }
    *(_DWORD *)(this + 24) = 128;
    v14 = *(_DWORD **)(this + 32);
    *v14 = a2;
    v14[1] = a3;
    do
    {
      v15 = *(_DWORD *)(this + 32);
      v48.m128_i32[3] = --n124_1;
      v16 = *(__m128 **)(v15 + 8 * n124_1);
      v17 = *(__m128 **)(v15 + 8 * n124_1 + 4);
      v56 = v16;
      v58 = v17;
      if ( n124_1 > n124 )
      {
        v18 = *(_DWORD *)(this + 24);
        v19 = 2 * v18;
        v52 = 2 * v18;
        v49 = v18;
        if ( 2 * v18 >= v18 )
        {
          if ( v19 > v18 && *(_DWORD *)(this + 28) < v19 )
          {
            if ( v19 )
            {
              v20 = sub_9D4CE0(16 * *(_DWORD *)(this + 24), 16);
              v54 = v20;
            }
            else
            {
              v20 = 0;
              v54 = 0;
            }
            v21 = *(_DWORD *)(this + 24);
            v50 = v21;
            if ( v21 > 0 )
            {
              v22 = 0;
              v23 = (_DWORD *)v20;
              do
              {
                if ( v23 )
                {
                  v24 = *(_DWORD *)(this + 32);
                  *v23 = *(_DWORD *)(v24 + 8 * v22);
                  v23[1] = *(_DWORD *)(v24 + 8 * v22 + 4);
                  v21 = v50;
                }
                ++v22;
                v23 += 2;
              }
              while ( v22 < v21 );
              v18 = v49;
            }
            if ( *(_DWORD *)(this + 32) )
            {
              if ( *(_BYTE *)(this + 36) )
                sub_9D4D50(*(_DWORD *)(this + 32));
              *(_DWORD *)(this + 32) = 0;
            }
            v19 = v52;
            v16 = v56;
            *(_BYTE *)(this + 36) = 1;
            *(_DWORD *)(this + 32) = v54;
            *(_DWORD *)(this + 28) = v52;
          }
          if ( v18 < v19 )
          {
            do
            {
              v25 = (_DWORD *)(*(_DWORD *)(this + 32) + 8 * v18);
              if ( v25 )
              {
                *v25 = v48.m128_i32[2];
                v19 = v52;
                v25[1] = v48.m128_i32[3];
              }
              ++v18;
            }
            while ( v18 < v19 );
            v16 = v56;
          }
        }
        n124_1 = v48.m128_i32[3];
        *(_DWORD *)(this + 24) = v19;
        n124 = v19 - 4;
        v17 = v58;
      }
      if ( v16 == v17 )
      {
        if ( v16[2].m128_i32[2] )
        {
          v26 = v16[2].m128_i32[1];
          v27 = *(_DWORD *)(this + 32);
          n124_1 += 3;
          *(_DWORD *)(v27 + 8 * n124_1 - 24) = v26;
          *(_DWORD *)(v27 + 8 * n124_1 - 20) = v26;
          v28 = v16[2].m128_i32[2];
          v29 = *(_DWORD *)(this + 32);
          *(_DWORD *)(v29 + 8 * n124_1 - 16) = v28;
          *(_DWORD *)(v29 + 8 * n124_1 - 12) = v28;
          v30 = v16[2].m128_i32[1];
          v31 = *(_DWORD *)(this + 32);
          v32 = v16[2].m128_i32[2];
          *(_DWORD *)(v31 + 8 * n124_1 - 8) = v30;
          *(_DWORD *)(v31 + 8 * n124_1 - 4) = v32;
        }
      }
      else
      {
        v48 = _mm_or_ps(_mm_cmplt_ps(v17[1], *v16), _mm_cmplt_ps(v16[1], *v17));
        if ( !(v48.m128_i32[2] | v48.m128_i32[1] | v48.m128_i32[0]) )
        {
          if ( v16[2].m128_i32[2] )
          {
            if ( v17[2].m128_i32[2] )
            {
              v33 = v16[2].m128_i32[1];
              n124_1 += 4;
              v34 = v58[2].m128_i32[1];
              v35 = *(_DWORD *)(this + 32);
              *(_DWORD *)(v35 + 8 * n124_1 - 32) = v33;
              *(_DWORD *)(v35 + 8 * n124_1 - 28) = v34;
              v36 = v58[2].m128_i32[1];
              v37 = *(_DWORD *)(this + 32);
              *(_DWORD *)(v37 + 8 * n124_1 - 24) = v56[2].m128_i32[2];
              *(_DWORD *)(v37 + 8 * n124_1 - 20) = v36;
              v38 = v58[2].m128_i32[2];
              v39 = *(_DWORD *)(this + 32);
              *(_DWORD *)(v39 + 8 * n124_1 - 16) = v56[2].m128_i32[1];
              *(_DWORD *)(v39 + 8 * n124_1 - 12) = v38;
              v40 = v58[2].m128_i32[2];
              v41 = *(_DWORD *)(this + 32);
              *(_DWORD *)(v41 + 8 * n124_1 - 8) = v56[2].m128_i32[2];
              *(_DWORD *)(v41 + 8 * n124_1 - 4) = v40;
            }
            else
            {
              v42 = *(_DWORD *)(this + 32);
              *(_DWORD *)(v42 + 8 * n124_1) = v16[2].m128_i32[1];
              *(_DWORD *)(v42 + 8 * n124_1 + 4) = v58;
              v43 = *(_DWORD *)(this + 32);
              n124_1 += 2;
              *(_DWORD *)(v43 + 8 * n124_1 - 8) = v16[2].m128_i32[2];
              *(_DWORD *)(v43 + 8 * n124_1 - 4) = v58;
            }
          }
          else if ( v17[2].m128_i32[2] )
          {
            v44 = *(_DWORD *)(this + 32);
            v45 = v17[2].m128_i32[1];
            *(_DWORD *)(v44 + 8 * n124_1) = v16;
            *(_DWORD *)(v44 + 8 * n124_1 + 4) = v45;
            n124_1 += 2;
            v46 = v58[2].m128_i32[2];
            v47 = *(_DWORD *)(this + 32);
            *(_DWORD *)(v47 + 8 * n124_1 - 8) = v16;
            *(_DWORD *)(v47 + 8 * n124_1 - 4) = v46;
          }
          else
          {
            (*(void (__thiscall **)(_DWORD, __int32, __int32))(**(_DWORD **)(*(_DWORD *)a4 + 96) + 4))(
              *(_DWORD *)(*(_DWORD *)a4 + 96),
              v56[2].m128_i32[1],
              v58[2].m128_i32[1]);
            ++*(_DWORD *)(*(_DWORD *)a4 + 120);
          }
        }
      }
    }
    while ( n124_1 );
  }
}
