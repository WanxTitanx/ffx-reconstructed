// Function: sub_AA4090
// Address: 0xaa4090
// Size: 0xf8
// Prototype: 

int *__cdecl sub_AA4090(int a1, int a2)
{
  int *v2; // ebx
  int v3; // eax
  bool v4; // cc
  int v5; // esi
  int *i; // edi
  int v7; // eax
  int *v8; // eax
  int v10; // [esp+14h] [ebp+8h]

  v10 = *(_DWORD *)(a1 + 28);
  v2 = (int *)malloc_0(0x60u);
  *v2 = sub_42EB10(a2, 8);
  v2[1] = sub_42EB10(a2, 16);
  v2[2] = sub_42EB10(a2, 16);
  v2[3] = sub_42EB10(a2, 6);
  v2[4] = sub_42EB10(a2, 8);
  v3 = sub_42EB10(a2, 4) + 1;
  v4 = *v2 < 1;
  v2[5] = v3;
  if ( !v4 && v2[1] >= 1 && v2[2] >= 1 && v3 >= 1 )
  {
    v5 = 0;
    for ( i = v2 + 6; ; ++i )
    {
      v7 = sub_42EB10(a2, 8);
      *i = v7;
      if ( v7 < 0 )
        break;
      if ( v7 >= *(_DWORD *)(v10 + 24) )
        break;
      v8 = *(int **)(v10 + 4 * v7 + 1824);
      if ( !v8[3] || *v8 < 1 )
        break;
      if ( ++v5 >= v2[5] )
        return v2;
    }
  }
  memset(v2, 0, 0x60u);
  free_1(v2);
  return 0;
}

