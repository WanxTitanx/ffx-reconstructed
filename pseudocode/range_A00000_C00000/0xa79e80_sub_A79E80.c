// Function: sub_A79E80
// Address: 0xa79e80
// Size: 0x1f
// Prototype: 

int __cdecl sub_A79E80(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1);
  if ( result )
    return sub_8347C0(result);
  return result;
}

