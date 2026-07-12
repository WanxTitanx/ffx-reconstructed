// Function: sub_A9EA70
// Address: 0xa9ea70
// Size: 0x10f
// Prototype: 

int __cdecl sub_A9EA70(int a1, _DWORD *a2, int a3, int a4, _DWORD *a5, int a6, int a7)
{
  int v8; // ebx
  int v9; // edx
  size_t Size; // edi
  signed int v11; // eax
  _DWORD *v12; // eax
  int v13; // eax
  int v14; // ecx
  _DWORD *v15; // esi
  int v16; // eax
  int v17; // ecx
  int v18; // edi
  int v19; // eax
  _DWORD *v20; // edx
  bool v21; // zf
  _DWORD v23[2]; // [esp+Ch] [ebp-10h] BYREF
  int v24; // [esp+14h] [ebp-8h]
  int v25; // [esp+18h] [ebp-4h]
  int v26; // [esp+28h] [ebp+Ch]
  int v27; // [esp+30h] [ebp+14h]

  v8 = a2[9] / 2;
  v9 = 0;
  Size = (4 * a6 * v8 + 7) & 0xFFFFFFF8;
  v11 = Size + a2[18];
  v26 = 0;
  if ( v11 > a2[19] )
  {
    if ( a2[17] )
    {
      v12 = malloc_0(8u);
      a2[20] += a2[18];
      v12[1] = a2[21];
      *v12 = a2[17];
      a2[21] = v12;
    }
    a2[19] = Size;
    a2[17] = malloc_0(Size);
    a2[18] = 0;
    v9 = 0;
  }
  v13 = a2[18];
  v14 = v13 + a2[17];
  a2[18] = Size + v13;
  v23[0] = v14;
  if ( a6 <= 0 )
    return 0;
  v15 = a5;
  v16 = a4 - (_DWORD)a5;
  v24 = v14 - (_DWORD)a5;
  v17 = a6;
  v27 = a4 - (_DWORD)a5;
  v25 = a6;
  do
  {
    v18 = *(_DWORD *)((char *)v15 + v16);
    if ( *v15 )
      v26 = v9 + 1;
    v19 = 0;
    if ( v8 > 0 )
    {
      v20 = (_DWORD *)((char *)v15 + v24);
      v23[1] = 4 * v17;
      do
      {
        *v20 = *(_DWORD *)(v18 + 4 * v19++);
        v20 += v17;
      }
      while ( v19 < v8 );
      v15 = a5;
      v17 = a6;
    }
    v9 = v26;
    v16 = v27;
    ++v15;
    v21 = v25-- == 1;
    a5 = v15;
  }
  while ( !v21 );
  if ( v26 )
    return sub_A9F3C0(v23, 1, a7);
  else
    return 0;
}

