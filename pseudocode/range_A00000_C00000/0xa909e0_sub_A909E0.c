// Function: sub_A909E0
// Address: 0xa909e0
// Size: 0x25
// Prototype: 

int __cdecl sub_A909E0(int a1, int a2)
{
  if ( a2 && a2 + *(_DWORD *)(a1 + 24) > *(_DWORD *)(a1 + 20) )
    return -131;
  *(_DWORD *)(a1 + 24) += a2;
  return 0;
}

