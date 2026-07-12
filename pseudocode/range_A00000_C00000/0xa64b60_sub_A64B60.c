// Function: sub_A64B60
// Address: 0xa64b60
// Size: 0x39
// Prototype: 

void __cdecl sub_A64B60(int a1, int a2)
{
  _DWORD *v2; // edx

  if ( a1 )
  {
    v2 = (_DWORD *)((char *)&n0xFFFF + 64 * (a2 & 3));
    if ( (a2 & 0xF00) <= (*v2 & 0xF00) )
    {
      *v2 = a2;
      v2[1] = a1;
    }
  }
}

