// Function: sub_A398E0
// Address: 0xa398e0
// Size: 0x1e
// Prototype: 

int __stdcall sub_A398E0(int a1, int a2, int a3)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 20);
  if ( result == a2 )
    return sub_A3B480(a1, a3);
  return result;
}

