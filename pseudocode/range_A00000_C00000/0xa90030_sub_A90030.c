// Function: sub_A90030
// Address: 0xa90030
// Size: 0x6e
// Prototype: 

void __cdecl sub_A90030(int a1)
{
  int i; // edi

  if ( a1 )
  {
    if ( *(_DWORD *)a1 )
    {
      for ( i = 0; i < *(_DWORD *)(a1 + 8); ++i )
      {
        if ( *(_DWORD *)(*(_DWORD *)a1 + 4 * i) )
          free_1(*(void **)(*(_DWORD *)a1 + 4 * i));
      }
      free_1(*(void **)a1);
    }
    if ( *(_DWORD *)(a1 + 4) )
      free_1(*(void **)(a1 + 4));
    if ( *(_DWORD *)(a1 + 12) )
      free_1(*(void **)(a1 + 12));
    *(_QWORD *)a1 = 0;
    *(_QWORD *)(a1 + 8) = 0;
  }
}

