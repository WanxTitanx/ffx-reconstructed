// Function: sub_A6A320
// Address: 0xa6a320
// Size: 0x73
// Prototype: 

int __cdecl sub_A6A320(int a1, int a2)
{
  unsigned int n0x100000; // eax
  unsigned int v3; // esi
  unsigned int v5; // esi

  n0x100000 = unknown_libname_741(*(_DWORD *)(a1 + 20));
  if ( n0x100000 < 0x100000 )
  {
    v5 = a1 + 32 * a2 + n0x100000;
    if ( sub_A446A0(*(_DWORD *)(v5 + 28)) )
      return 0;
    return a1 + unknown_libname_741(*(_DWORD *)(v5 + 28));
  }
  else
  {
    v3 = 32 * a2 + n0x100000;
    if ( unknown_libname_741(*(_DWORD *)(v3 + 28)) == a1 )
      return 0;
    return unknown_libname_741(*(_DWORD *)(v3 + 28));
  }
}

