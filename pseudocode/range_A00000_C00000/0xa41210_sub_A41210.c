// Function: sub_A41210
// Address: 0xa41210
// Size: 0x55
// Prototype: 

unsigned int *__cdecl sub_A41210(int a1, unsigned int n0xFF, unsigned int n0xFF_1, unsigned int a4)
{
  unsigned int *result; // eax

  if ( n0xFF > 0xFF || n0xFF_1 > 0xFF )
    return 0;
  result = (unsigned int *)sub_4410E0(1, (int)Size_8, 4 * (a4 + 4 * (n0xFF_1 + 4 * ((n0xFF + 3) >> 2))));
  if ( result )
  {
    *result = n0xFF;
    result[1] = n0xFF_1;
    result[2] = a4;
  }
  return result;
}

