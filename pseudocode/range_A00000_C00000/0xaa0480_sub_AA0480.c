// Function: sub_AA0480
// Address: 0xaa0480
// Size: 0x30c
// Prototype: 

int __cdecl sub_AA0480(_DWORD *a1, int *a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  void *v7; // esp
  void *v8; // esp
  void *v9; // esp
  _BYTE *v10; // ebx
  void *v11; // esp
  int v12; // esi
  bool v13; // cc
  _DWORD *v14; // edi
  int v15; // ecx
  int v16; // eax
  _DWORD *v17; // edx
  int *v18; // ecx
  int v19; // edx
  _DWORD *v20; // ecx
  int v21; // esi
  _BYTE *v22; // eax
  int v23; // ecx
  int v24; // esi
  _BYTE *v25; // edx
  int v26; // edi
  int v27; // esi
  int *v28; // ebx
  float *v29; // ecx
  int v30; // edx
  int v31; // eax
  float v32; // xmm0_4
  float v33; // xmm1_4
  int v34; // ebx
  int i; // esi
  int v36; // ecx
  int j; // esi
  size_t Size_1; // [esp-Ch] [ebp-44h]
  _BYTE v40[12]; // [esp+0h] [ebp-38h] BYREF
  _BYTE *v41; // [esp+Ch] [ebp-2Ch]
  size_t Size; // [esp+10h] [ebp-28h]
  int v43; // [esp+14h] [ebp-24h]
  _BYTE *v44; // [esp+18h] [ebp-20h]
  int v45; // [esp+1Ch] [ebp-1Ch]
  _DWORD *v46; // [esp+20h] [ebp-18h]
  _BYTE *v47; // [esp+24h] [ebp-14h]
  _BYTE *v48; // [esp+28h] [ebp-10h]
  _BYTE *v49; // [esp+2Ch] [ebp-Ch]
  int v50; // [esp+30h] [ebp-8h]
  int v51; // [esp+34h] [ebp-4h]
  int v52; // [esp+40h] [ebp+8h]

  v2 = a1[16];
  v3 = *(_DWORD *)(v2 + 4);
  v4 = *(_DWORD *)(v3 + 28);
  v50 = *(_DWORD *)(v2 + 104);
  v5 = *(_DWORD *)(v4 + 4 * a1[7]);
  a1[9] = v5;
  v6 = *(_DWORD *)(v3 + 4);
  v43 = v5;
  v51 = v3;
  v45 = v4;
  v7 = alloca(4 * v6);
  v44 = v40;
  v8 = alloca(4 * v6);
  v47 = v40;
  v9 = alloca(4 * v6);
  v10 = v40;
  v48 = v40;
  v11 = alloca(4 * v6);
  v12 = 0;
  v13 = v6 <= 0;
  v14 = a1;
  v41 = v40;
  if ( !v13 )
  {
    Size = (unsigned int)(4 * v43) >> 1;
    v49 = v40;
    v46 = 0;
    do
    {
      v15 = a2[a2[v12 + 1] + 257];
      v16 = (*((int (__cdecl **)(_DWORD *, _DWORD))*(&off_B81500 + *(_DWORD *)(v45 + 4 * v15 + 800)) + 5))(
              a1,
              *(_DWORD *)(*(_DWORD *)(v50 + 48) + 4 * v15));
      v17 = v49;
      Size_1 = Size;
      *(_DWORD *)((char *)v46 + (_DWORD)v49) = v16;
      *v17 = v16 != 0;
      memset(*(void **)(*a1 + 4 * v12), 0, Size_1);
      v49 += 4;
      ++v12;
    }
    while ( v12 < *(_DWORD *)(v51 + 4) );
    v10 = v48;
  }
  v18 = a2;
  v19 = 0;
  if ( a2[289] > 0 )
  {
    v20 = a2 + 546;
    do
    {
      v21 = *(v20 - 256);
      if ( *(_DWORD *)&v10[4 * v21] || *(_DWORD *)&v10[4 * *v20] )
      {
        *(_DWORD *)&v10[4 * v21] = 1;
        *(_DWORD *)&v10[4 * *v20] = 1;
      }
      ++v19;
      ++v20;
    }
    while ( v19 < a2[289] );
    v18 = a2;
  }
  v22 = 0;
  v49 = 0;
  if ( *v18 > 0 )
  {
    v46 = v18 + 273;
    do
    {
      v23 = 0;
      v24 = 0;
      if ( *(int *)(v51 + 4) > 0 )
      {
        v25 = v47;
        v26 = v44 - v47;
        do
        {
          if ( (_BYTE *)a2[v23 + 1] == v22 )
          {
            ++v24;
            v25 += 4;
            *((_DWORD *)v25 - 1) = *(_DWORD *)&v48[4 * v23] != 0;
            *(_DWORD *)&v25[v26 - 4] = *(_DWORD *)(*a1 + 4 * v23);
            v22 = v49;
          }
          ++v23;
        }
        while ( v23 < *(_DWORD *)(v51 + 4) );
        v14 = a1;
      }
      (*((void (__cdecl **)(_DWORD *, _DWORD, _BYTE *, _BYTE *, int))*(&off_B814F0 + *(_DWORD *)(v45 + 4 * *v46 + 1312))
       + 7))(
        v14,
        *(_DWORD *)(*(_DWORD *)(v50 + 52) + 4 * *v46),
        v44,
        v47,
        v24);
      v18 = a2;
      ++v46;
      v22 = v49 + 1;
      v49 = v22;
    }
    while ( (int)v22 < *a2 );
  }
  v27 = v18[289] - 1;
  if ( v27 >= 0 )
  {
    v52 = v43 / 2;
    v28 = &v18[v18[289] + 545];
    do
    {
      v29 = *(float **)(*v14 + 4 * *(v28 - 256));
      v30 = v52;
      if ( v52 > 0 )
      {
        v31 = *(_DWORD *)(*v14 + 4 * *v28) - (_DWORD)v29;
        do
        {
          v32 = *v29;
          v33 = *(float *)((char *)v29 + v31);
          if ( *v29 <= 0.0 )
          {
            if ( v33 <= 0.0 )
            {
              *(float *)((char *)v29 + v31) = v32;
              *v29 = v32 - v33;
            }
            else
            {
              *(float *)((char *)v29 + v31) = v33 + v32;
            }
          }
          else if ( v33 <= 0.0 )
          {
            *(float *)((char *)v29 + v31) = v32;
            *v29 = v33 + v32;
          }
          else
          {
            *(float *)((char *)v29 + v31) = v32 - v33;
          }
          ++v29;
          --v30;
        }
        while ( v30 );
      }
      --v28;
      --v27;
    }
    while ( v27 >= 0 );
    v18 = a2;
  }
  v34 = v51;
  for ( i = 0; i < *(_DWORD *)(v34 + 4); ++i )
  {
    v36 = v18[v18[i + 1] + 257];
    (*((void (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD))*(&off_B81500 + *(_DWORD *)(v45 + 4 * v36 + 800)) + 6))(
      v14,
      *(_DWORD *)(*(_DWORD *)(v50 + 48) + 4 * v36),
      *(_DWORD *)&v41[4 * i],
      *(_DWORD *)(*v14 + 4 * i));
    v18 = a2;
  }
  for ( j = 0; j < *(_DWORD *)(v34 + 4); ++j )
    sub_A9BE10(**(int ***)(v50 + 4 * v14[7] + 12), *(_DWORD *)(*v14 + 4 * j), *(_DWORD *)(*v14 + 4 * j));
  return 0;
}

