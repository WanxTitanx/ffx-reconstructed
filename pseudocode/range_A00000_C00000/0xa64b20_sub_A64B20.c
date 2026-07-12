// Function: sub_A64B20
// Address: 0xa64b20
// Size: 0x3f
// Prototype: 

int __cdecl sub_A64B20(int a1, int a2, int a3)
{
  _DWORD *v3; // edx
  int result; // eax

  if ( a2 )
  {
    v3 = (_DWORD *)((char *)&n0xFFFF + 64 * (a3 & 3));
    result = a3 & 0xF00;
    if ( result <= (*v3 & 0xF00) )
    {
      *v3 = a3;
      v3[2] = a1;
      v3[3] = a2;
      return a1;
    }
  }
  return result;
}

