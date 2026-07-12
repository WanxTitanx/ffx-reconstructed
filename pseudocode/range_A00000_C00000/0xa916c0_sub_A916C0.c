// Function: sub_A916C0
// Address: 0xa916c0
// Size: 0xdd
// Prototype: 

int __fastcall sub_A916C0(_DWORD *a1, int a2)
{
  _DWORD *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebx
  void *v5; // eax
  void *v6; // eax
  void *v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // esi
  void *v12; // eax
  int v13; // edx
  _DWORD *v14; // ecx
  int v15; // esi
  int v16; // edi
  int i; // [esp+14h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[26];
  v4 = a1[1];
  v5 = (void *)v3[16];
  if ( v5 )
    free_1(v5);
  v6 = (void *)v3[17];
  v3[16] = 0;
  if ( v6 )
    free_1(v6);
  v7 = (void *)v3[18];
  v3[17] = 0;
  if ( v7 )
    free_1(v7);
  v8 = v2[5];
  v3[18] = 0;
  if ( v8 + a2 >= v2[4] )
  {
    v9 = v8 + 2 * a2;
    v10 = 0;
    v2[4] = v9;
    for ( i = 0; v10 < *(_DWORD *)(v4 + 4); ++i )
    {
      v11 = v2[2];
      v12 = realloc_0(*(void **)(v11 + 4 * v10), 4 * v2[4]);
      v10 = i + 1;
      *(_DWORD *)(v11 + 4 * v10 - 4) = v12;
    }
  }
  v13 = 0;
  if ( *(int *)(v4 + 4) > 0 )
  {
    v14 = (_DWORD *)v2[3];
    v15 = 4 * v2[5];
    v16 = v2[2] - (_DWORD)v14;
    do
    {
      *v14 = v15 + *(_DWORD *)((char *)v14 + v16);
      ++v13;
      ++v14;
    }
    while ( v13 < *(_DWORD *)(v4 + 4) );
    v2 = a1;
  }
  return v2[3];
}

