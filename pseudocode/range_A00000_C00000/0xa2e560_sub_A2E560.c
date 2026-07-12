// Function: sub_A2E560
// Address: 0xa2e560
// Size: 0x15
// Prototype: 

int __stdcall sub_A2E560(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 )
    return *(_DWORD *)(a1 + 4);
  return result;
}

