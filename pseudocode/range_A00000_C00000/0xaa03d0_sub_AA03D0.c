// Function: sub_AA03D0
// Address: 0xaa03d0
// Size: 0x76
// Prototype: int __cdecl(void *Block)

void __cdecl sub_AA03D0(void *Block)
{
  int i; // edi
  int j; // edi

  if ( Block )
  {
    for ( i = 0; i < *((_DWORD *)Block + 1); ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)Block + 5) + 4 * i) )
        free_1(*(void **)(*((_DWORD *)Block + 5) + 4 * i));
    }
    free_1(*((void **)Block + 5));
    for ( j = 0; j < *((_DWORD *)Block + 6); ++j )
      free_1(*(void **)(*((_DWORD *)Block + 7) + 4 * j));
    free_1(*((void **)Block + 7));
    memset(Block, 0, 0x2Cu);
    free_1(Block);
  }
}

