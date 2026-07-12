// Function: sub_AA2D80
// Address: 0xaa2d80
// Size: 0x1b6
// Prototype: 

_DWORD *__cdecl sub_AA2D80(int *a1, int a2)
{
  int *v2; // edi
  int v3; // esi
  _DWORD *v4; // ecx
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  int v7; // ecx
  unsigned int v8; // esi
  unsigned int v9; // eax
  _DWORD *result; // eax
  int v11; // ecx
  int v12; // esi
  int v13; // edx
  int v14; // eax
  _DWORD *v15; // esi
  int v16; // edi
  _DWORD *v17; // esi
  int v18; // [esp+Ch] [ebp-14h]
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+10h] [ebp-10h]
  int *v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-Ch]
  _DWORD *v24; // [esp+14h] [ebp-Ch]
  int v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]
  _DWORD *v27; // [esp+1Ch] [ebp-4h]
  int v28; // [esp+1Ch] [ebp-4h]

  v2 = a1;
  v25 = 0;
  v18 = a1[210];
  v3 = -1;
  sub_42E350(a2, *a1, 5);
  v26 = 0;
  if ( *a1 > 0 )
  {
    v4 = a1 + 1;
    v22 = a1 + 1;
    do
    {
      sub_42E350(a2, *v4, 4);
      if ( v3 < *v22 )
        v3 = *v22;
      v4 = v22 + 1;
      ++v26;
      ++v22;
    }
    while ( v26 < *a1 );
  }
  v20 = v3 + 1;
  if ( v3 + 1 > 0 )
  {
    v27 = a1 + 80;
    v5 = a1 + 48;
    do
    {
      sub_42E350(a2, *(v5 - 16) - 1, 3);
      sub_42E350(a2, *v5, 2);
      if ( *v5 )
        sub_42E350(a2, v5[16], 8);
      v23 = 0;
      if ( 1 << *v5 > 0 )
      {
        v6 = v27;
        do
        {
          sub_42E350(a2, *v6 + 1, 8);
          ++v23;
          ++v6;
        }
        while ( v23 < 1 << *v5 );
      }
      v27 += 8;
      ++v5;
      --v20;
    }
    while ( v20 );
    v2 = a1;
  }
  sub_42E350(a2, v2[208] - 1, 2);
  v7 = 0;
  v8 = v18 - 1;
  v9 = v18 - 1;
  if ( v18 != 1 )
  {
    do
    {
      ++v7;
      v9 >>= 1;
    }
    while ( v9 );
  }
  result = (_DWORD *)sub_42E350(a2, v7, 4);
  v11 = 0;
  v28 = 0;
  if ( v18 != 1 )
  {
    do
    {
      ++v11;
      v8 >>= 1;
    }
    while ( v8 );
    v28 = v11;
  }
  v12 = 0;
  v13 = 0;
  v21 = 0;
  if ( *v2 > 0 )
  {
    result = v2 + 1;
    v24 = v2 + 1;
    do
    {
      v14 = v2[*result + 32] + v25;
      v25 = v14;
      if ( v13 < v14 )
      {
        v15 = v2 + 211;
        v16 = v14 - v13;
        v17 = &v15[v13];
        v19 = v14;
        do
        {
          sub_42E350(a2, *v17, v11);
          v11 = v28;
          ++v17;
          --v16;
        }
        while ( v16 );
        v13 = v19;
        v2 = a1;
        v12 = v21;
      }
      ++v12;
      result = v24 + 1;
      v21 = v12;
      ++v24;
    }
    while ( v12 < *v2 );
  }
  return result;
}

