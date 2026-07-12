// Function: sub_9A3660
// Address: 0x9a3660
int __userpurge sub_9A3660@<eax>(int a1@<ecx>, int a2@<edi>, int a3@<esi>, int a4)
{
  int result; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  _DWORD *v10; // esi
  bool v11; // cl
  bool v12; // cc
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  _DWORD *n8; // edx
  int v18; // esi
  _DWORD *v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // edx
  __m128 v24; // [esp-40h] [ebp-4Ch]
  int v25; // [esp-30h] [ebp-3Ch]
  int v26; // [esp-2Ch] [ebp-38h]
  int v27; // [esp-2Ch] [ebp-38h]
  int v28; // [esp-28h] [ebp-34h]
  int v29; // [esp-28h] [ebp-34h]
  int v30; // [esp-28h] [ebp-34h]
  int v31; // [esp-24h] [ebp-30h]
  int v32; // [esp-24h] [ebp-30h]
  int v33; // [esp-20h] [ebp-2Ch]
  int v34; // [esp-4h] [ebp-10h]
  int v35; // [esp-4h] [ebp-10h]

  result = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a1 + 96) + 52))(*(_DWORD *)(a1 + 96), a2, a3);
  if ( (_BYTE)result )
  {
    v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 96) + 24))(*(_DWORD *)(a1 + 96));
    LOBYTE(v28) = 0;
    v7 = *(_DWORD *)(v6 + 4);
    if ( v7 > 1 )
      sub_9765F0(v28, 0, v7 - 1);
    v8 = 0;
    v34 = 0;
    v33 = 0;
    v31 = 0;
    if ( *(int *)(v6 + 4) > 0 )
    {
      v9 = 0;
      v29 = 0;
      do
      {
        v10 = (_DWORD *)(v9 + *(_DWORD *)(v6 + 12));
        v11 = *v10 == v33 && v10[1] == v8;
        v33 = *v10;
        v25 = v10[1];
        if ( v11
          || (v24 = _mm_or_ps(
                      _mm_cmplt_ps(*(__m128 *)(*(_DWORD *)(*v10 + 48) + 16), *(__m128 *)*(_DWORD *)(v10[1] + 48)),
                      _mm_cmplt_ps(*(__m128 *)(*(_DWORD *)(v10[1] + 48) + 16), *(__m128 *)*(_DWORD *)(*v10 + 48))),
              v24.m128_i32[2] | v24.m128_i32[1] | v24.m128_i32[0]) )
        {
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(**(_DWORD **)(v26 + 96) + 28))(*(_DWORD *)(v26 + 96), v10, a4);
          ++v34;
          *v10 = 0;
          v10[1] = 0;
        }
        v9 = v29 + 16;
        v12 = ++v31 < *(_DWORD *)(v6 + 4);
        v8 = v25;
        v29 += 16;
      }
      while ( v12 );
    }
    v13 = *(_DWORD *)(v6 + 4);
    LOBYTE(v25) = 0;
    if ( v13 > 1 )
      sub_9765F0(v25, 0, v13 - 1);
    result = *(_DWORD *)(v6 + 4);
    v14 = result - v34;
    v32 = result;
    v27 = result - v34;
    if ( result - v34 >= result )
    {
      if ( v14 > result && *(_DWORD *)(v6 + 8) < v14 )
      {
        if ( v14 )
          v15 = sub_9D4CE0(16 * v14, 16);
        else
          v15 = 0;
        v16 = *(_DWORD *)(v6 + 4);
        v35 = v15;
        v30 = v16;
        if ( v16 > 0 )
        {
          n8 = (_DWORD *)(v15 + 8);
          v18 = -8 - v15;
          do
          {
            if ( n8 != (_DWORD *)8 )
            {
              v19 = (_DWORD *)((char *)n8 + v18 + *(_DWORD *)(v6 + 12));
              *(n8 - 2) = *v19;
              *(n8 - 1) = v19[1];
              *n8 = v19[2];
              v20 = v19[3];
              v16 = v30;
              n8[1] = v20;
            }
            n8 += 4;
            v30 = --v16;
          }
          while ( v16 );
          v14 = v27;
        }
        if ( *(_DWORD *)(v6 + 12) )
        {
          if ( *(_BYTE *)(v6 + 16) )
            sub_9D4D50(*(_DWORD *)(v6 + 12));
          *(_DWORD *)(v6 + 12) = 0;
        }
        *(_DWORD *)(v6 + 12) = v35;
        result = v32;
        *(_BYTE *)(v6 + 16) = 1;
        *(_DWORD *)(v6 + 8) = v14;
      }
      if ( result < v14 )
      {
        v21 = 16 * result;
        v22 = v14 - result;
        do
        {
          result = v21 + *(_DWORD *)(v6 + 12);
          if ( result )
          {
            *(_DWORD *)result = 0;
            *(_DWORD *)(result + 4) = 0;
            *(_DWORD *)(result + 8) = 0;
            *(_DWORD *)(result + 12) = 0;
          }
          v21 += 16;
          --v22;
        }
        while ( v22 );
      }
    }
    *(_DWORD *)(v6 + 4) = v14;
  }
  return result;
}
