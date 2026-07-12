// Function: sub_AA4190
// Address: 0xaa4190
// Size: 0x65
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA4190(void *Block)
{
  void **v1; // eax
  void *v2; // eax

  if ( Block )
  {
    v1 = (void **)*((_DWORD *)Block + 2);
    if ( v1 )
    {
      v2 = *v1;
      if ( v2 )
        free_1(v2);
      if ( *(_DWORD *)(*((_DWORD *)Block + 2) + 4) )
        free_1(*(void **)(*((_DWORD *)Block + 2) + 4));
      free_1(*((void **)Block + 2));
    }
    *(_QWORD *)Block = 0;
    *((_QWORD *)Block + 1) = 0;
    *((_QWORD *)Block + 2) = 0;
    *((_QWORD *)Block + 3) = 0;
    free_1(Block);
  }
}

