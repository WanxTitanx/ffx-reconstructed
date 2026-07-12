// Function: sub_A8FD80
// Address: 0xa8fd80
// Size: 0x24b
// Prototype: 

_QWORD *__cdecl sub_A8FD80(int a1)
{
  _QWORD *result; // eax
  int v2; // esi
  int v3; // edi
  void **v4; // ebx
  int v5; // ebx
  _DWORD *v6; // edi
  int v7; // ebx
  _DWORD *v8; // edi
  int v9; // ebx
  _DWORD *v10; // edi
  int v11; // ebx
  int v12; // ecx
  _DWORD **v13; // eax
  _DWORD *v14; // edi
  int v15; // eax
  void **v16; // edi
  void *v17; // eax
  int v18; // ebx
  void **v19; // eax
  void *v20; // edi
  int v21; // [esp+4h] [ebp-8h]
  void **v22; // [esp+4h] [ebp-8h]
  int v23; // [esp+8h] [ebp-4h]

  result = (_QWORD *)a1;
  v2 = *(_DWORD *)(a1 + 28);
  if ( v2 )
  {
    v3 = 0;
    if ( *(int *)(v2 + 8) > 0 )
    {
      v4 = (void **)(v2 + 32);
      do
      {
        if ( *v4 )
          free_1(*v4);
        ++v3;
        ++v4;
      }
      while ( v3 < *(_DWORD *)(v2 + 8) );
    }
    v5 = 0;
    if ( *(int *)(v2 + 12) > 0 )
    {
      v6 = (_DWORD *)(v2 + 544);
      do
      {
        if ( *v6 )
          ((void (__cdecl *)(_DWORD))(&off_B814FC)[*(v6 - 64)][2])(*v6);
        ++v5;
        ++v6;
      }
      while ( v5 < *(_DWORD *)(v2 + 12) );
    }
    v7 = 0;
    if ( *(int *)(v2 + 16) > 0 )
    {
      v8 = (_DWORD *)(v2 + 1056);
      do
      {
        if ( *v8 )
          (*((void (__cdecl **)(_DWORD))*(&off_B81500 + *(v8 - 64)) + 3))(*v8);
        ++v7;
        ++v8;
      }
      while ( v7 < *(_DWORD *)(v2 + 16) );
    }
    v9 = 0;
    if ( *(int *)(v2 + 20) > 0 )
    {
      v10 = (_DWORD *)(v2 + 1568);
      do
      {
        if ( *v10 )
          (*((void (__cdecl **)(_DWORD))*(&off_B814F0 + *(v10 - 64)) + 3))(*v10);
        ++v9;
        ++v10;
      }
      while ( v9 < *(_DWORD *)(v2 + 20) );
    }
    v11 = 0;
    if ( *(int *)(v2 + 24) > 0 )
    {
      v12 = 0;
      v13 = (_DWORD **)(v2 + 1824);
      v23 = 0;
      v21 = v2 + 1824;
      do
      {
        v14 = *v13;
        if ( *v13 && v14[9] )
        {
          if ( v14[8] )
            free_1((void *)v14[8]);
          if ( v14[2] )
            free_1((void *)v14[2]);
          *(_QWORD *)v14 = 0;
          *((_QWORD *)v14 + 1) = 0;
          *((_QWORD *)v14 + 2) = 0;
          *((_QWORD *)v14 + 3) = 0;
          *((_QWORD *)v14 + 4) = 0;
          free_1(v14);
          v12 = v23;
        }
        v15 = *(_DWORD *)(v2 + 2848);
        if ( v15 )
        {
          v16 = (void **)(v12 + v15);
          v17 = *(void **)(v12 + v15 + 16);
          if ( v17 )
            free_1(v17);
          if ( v16[5] )
            free_1(v16[5]);
          if ( v16[6] )
            free_1(v16[6]);
          if ( v16[7] )
            free_1(v16[7]);
          if ( v16[8] )
            free_1(v16[8]);
          memset(v16, 0, 0x38u);
          v12 = v23;
        }
        ++v11;
        v13 = (_DWORD **)(v21 + 4);
        v12 += 56;
        v21 += 4;
        v23 = v12;
      }
      while ( v11 < *(_DWORD *)(v2 + 24) );
    }
    if ( *(_DWORD *)(v2 + 2848) )
      free_1(*(void **)(v2 + 2848));
    v18 = 0;
    if ( *(int *)(v2 + 28) > 0 )
    {
      v19 = (void **)(v2 + 2852);
      v22 = (void **)(v2 + 2852);
      do
      {
        v20 = *v19;
        if ( *v19 )
        {
          memset(v20, 0, 0x208u);
          free_1(v20);
          v19 = v22;
        }
        ++v18;
        v22 = ++v19;
      }
      while ( v18 < *(_DWORD *)(v2 + 28) );
    }
    free_1((void *)v2);
    result = (_QWORD *)a1;
  }
  *result = 0;
  result[1] = 0;
  result[2] = 0;
  result[3] = 0;
  return result;
}

