// Function: sub_A78750
// Address: 0xa78750
// Size: 0x1f

int __cdecl sub_A78750(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1); /*0xa78756*/
  if ( result ) /*0xa78760*/
    return sub_8398E0(result); /*0xa78765*/
  return result; /*0xa78762*/
}