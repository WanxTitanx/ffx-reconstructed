// Function: sub_A79D90
// Address: 0xa79d90
// Size: 0x1f

int __cdecl sub_A79D90(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1); /*0xa79d96*/
  if ( result ) /*0xa79da0*/
    return sub_82ACF0(result); /*0xa79da5*/
  return result; /*0xa79da2*/
}