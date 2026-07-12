// Function: sub_9A3010
// Address: 0x9a3010
void __userpurge sub_9A3010(int a1@<ecx>, int a2@<ebp>, int a3)
{
  int v4; // esi
  bool v5; // sf
  int *v6; // eax
  int v7; // eax
  __int32 v8; // esi
  int v9; // ecx
  int *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int *v14; // eax
  bool v15; // zf
  int *v16; // esi
  int v17; // eax
  int *v18; // ecx
  int *v19; // eax
  int v20; // ecx
  int v21; // esi
  _DWORD *v22; // edx
  unsigned int v23; // ecx
  double v24; // st7
  _DWORD src[8]; // [esp-60h] [ebp-6Ch] BYREF
  __m128 v26; // [esp-40h] [ebp-4Ch]
  _DWORD v27[2]; // [esp-24h] [ebp-30h] BYREF
  float v28; // [esp-1Ch] [ebp-28h]
  int v29; // [esp-18h] [ebp-24h] BYREF
  int v30; // [esp-14h] [ebp-20h] BYREF
  int v31; // [esp-10h] [ebp-1Ch] BYREF
  int v32; // [esp-Ch] [ebp-18h] BYREF
  int *v33; // [esp-8h] [ebp-14h]
  int v34; // [esp-4h] [ebp-10h]
  _DWORD v35[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v35[0] = a2;
  v35[1] = retaddr;
  sub_989190(
    (int *)(a1 + 4),
    (int)v35,
    ((int)((unsigned __int64)(1374389535LL * *(_DWORD *)(a1 + 16) * *(_DWORD *)(a1 + 112)) >> 32) >> 5)
  + ((unsigned int)((unsigned __int64)(1374389535LL * *(_DWORD *)(a1 + 16) * *(_DWORD *)(a1 + 112)) >> 32) >> 31)
  + 1);
  if ( *(_DWORD *)(a1 + 124) )
  {
    v4 = ((int)((unsigned __int64)(1374389535LL * *(_DWORD *)(a1 + 56) * *(_DWORD *)(a1 + 108)) >> 32) >> 5)
       + ((unsigned int)((unsigned __int64)(1374389535LL * *(_DWORD *)(a1 + 56) * *(_DWORD *)(a1 + 108)) >> 32) >> 31)
       + 1;
    sub_989190((int *)(a1 + 44), (int)v35, v4);
    v5 = *(_DWORD *)(a1 + 124) - v4 < 0;
    v31 = *(_DWORD *)(a1 + 124) - v4;
    v6 = &v32;
    if ( !v5 )
      v6 = &v31;
    v32 = 0;
    *(_DWORD *)(a1 + 124) = *v6;
  }
  v7 = (*(_DWORD *)(a1 + 104) + 1) % 2;
  *(_DWORD *)(a1 + 104) = v7;
  v8 = *(_DWORD *)(a1 + 4 * v7 + 84);
  if ( v8 )
  {
    do
    {
      v9 = *(_DWORD *)(v8 + 52);
      v10 = *(int **)(v8 + 56);
      v11 = *(_DWORD *)(v8 + 60);
      v33 = v10;
      if ( v9 )
        *(_DWORD *)(v9 + 56) = v10;
      else
        *(_DWORD *)(a1 + 4 * v11 + 84) = v10;
      v12 = *(_DWORD *)(v8 + 56);
      if ( v12 )
        *(_DWORD *)(v12 + 52) = *(_DWORD *)(v8 + 52);
      *(_DWORD *)(v8 + 52) = 0;
      *(_DWORD *)(v8 + 56) = *(_DWORD *)(a1 + 92);
      v13 = *(_DWORD *)(a1 + 92);
      if ( v13 )
        *(_DWORD *)(v13 + 52) = v8;
      *(_DWORD *)(a1 + 92) = v8;
      sub_989750((int *)(a1 + 4), *(_DWORD **)(v8 + 48));
      src[0] = *(_DWORD *)(v8 + 16);
      src[1] = *(_DWORD *)(v8 + 20);
      src[2] = *(_DWORD *)(v8 + 24);
      src[3] = *(_DWORD *)(v8 + 28);
      src[4] = *(_DWORD *)(v8 + 32);
      src[5] = *(_DWORD *)(v8 + 36);
      src[6] = *(_DWORD *)(v8 + 40);
      src[7] = *(_DWORD *)(v8 + 44);
      *(_DWORD *)(v8 + 48) = sub_988CC0((_DWORD *)(a1 + 44), src, v8);
      v14 = v33;
      *(_DWORD *)(v8 + 60) = 2;
      v8 = (__int32)v14;
    }
    while ( v14 );
    *(_DWORD *)(a1 + 124) = *(_DWORD *)(a1 + 56);
    *(_BYTE *)(a1 + 154) = 1;
  }
  v15 = *(_BYTE *)(a1 + 153) == 0;
  v27[0] = a1;
  v16 = (int *)(a1 + 4);
  if ( !v15 )
  {
    sub_9A1D10(a1 + 4, *v16, *(_DWORD *)(a1 + 44), (int)v27);
    if ( *(_BYTE *)(a1 + 153) )
      sub_9A1D10(a1 + 4, *v16, *v16, (int)v27);
  }
  if ( *(_BYTE *)(a1 + 154) )
  {
    v28 = COERCE_FLOAT((*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a1 + 96) + 24))(*(_DWORD *)(a1 + 96)));
    v33 = (int *)(LODWORD(v28) + 4);
    v17 = *(_DWORD *)(LODWORD(v28) + 4);
    v34 = v17;
    if ( v17 > 0 )
    {
      v18 = &v30;
      if ( *(_DWORD *)(a1 + 120) > v17 * *(_DWORD *)(a1 + 116) / 100 )
        v18 = (int *)(a1 + 120);
      v30 = v17 * *(_DWORD *)(a1 + 116) / 100;
      v19 = &v29;
      if ( v34 >= *v18 )
        v19 = v18;
      v29 = v34;
      v21 = 0;
      v34 = *v19;
      v20 = v34;
      if ( v34 > 0 )
      {
        do
        {
          v22 = (_DWORD *)(*(_DWORD *)(LODWORD(v28) + 12) + 16 * ((v21 + *(_DWORD *)(a1 + 144)) % *v33));
          v26 = _mm_or_ps(
                  _mm_cmplt_ps(*(__m128 *)(*(_DWORD *)(*v22 + 48) + 16), *(__m128 *)*(_DWORD *)(v22[1] + 48)),
                  _mm_cmplt_ps(*(__m128 *)(*(_DWORD *)(v22[1] + 48) + 16), *(__m128 *)*(_DWORD *)(*v22 + 48)));
          if ( v26.m128_i32[2] | v26.m128_i32[1] | v26.m128_i32[0] )
          {
            (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int))(**(_DWORD **)(a1 + 96) + 8))(
              *(_DWORD *)(a1 + 96),
              *v22,
              v22[1],
              a3);
            v20 = --v34;
            --v21;
          }
          else
          {
            v20 = v34;
          }
          ++v21;
        }
        while ( v21 < v20 );
      }
      if ( *v33 <= 0 )
        *(_DWORD *)(a1 + 144) = 0;
      else
        *(_DWORD *)(a1 + 144) = (v20 + *(_DWORD *)(a1 + 144)) % *v33;
    }
  }
  v23 = *(_DWORD *)(a1 + 128);
  ++*(_DWORD *)(a1 + 140);
  *(_DWORD *)(a1 + 120) = 1;
  *(_BYTE *)(a1 + 154) = 0;
  if ( v23 )
  {
    v28 = (float)*(unsigned int *)(a1 + 132);
    v24 = v28;
    v28 = (float)v23;
    *(float *)(a1 + 136) = v24 / v28;
  }
  else
  {
    *(_DWORD *)(a1 + 136) = 0;
  }
  *(_DWORD *)(a1 + 132) >>= 1;
  *(_DWORD *)(a1 + 128) = v23 >> 1;
}
