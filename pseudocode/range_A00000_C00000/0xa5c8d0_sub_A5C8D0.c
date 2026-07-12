// Function: sub_A5C8D0
// Address: 0xa5c8d0
// Size: 0x34
// Prototype: 

int __cdecl sub_A5C8D0(int a1, int a2)
{
  long double v2; // st7
  int result; // eax

  v2 = sqrt((double)a2);
  result = (int)((v2 + v2) / 3.0 + 10.0);
  if ( !result )
    return 1;
  return result;
}

