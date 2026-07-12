// Function: sub_A5C7B0
// Address: 0xa5c7b0
// Size: 0x32
// Prototype: 

int __cdecl sub_A5C7B0(int a1, int a2)
{
  int result; // eax

  result = (int)(sqrt((double)a2) * 0.25 + 16.0);
  if ( !result )
    return 1;
  return result;
}

