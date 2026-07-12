// Function: sub_A398A0
// Address: 0xa398a0
// Size: 0x3e
// Prototype: 

int __stdcall sub_A398A0(int a1, int a2, int a3)
{
  int result; // eax

  result = a2;
  if ( *(_DWORD *)(a1 + 20) == a2 || !a2 )
  {
    if ( *(_DWORD **)(a1 + 24) == dword_1A858B4 + 164 )
      return sub_A39F00(a1);
    else
      return sub_A3B480(a1, a3);
  }
  return result;
}

