// Function: sub_A79D10
// Address: 0xa79d10
// Size: 0x1f

int __cdecl sub_A79D10(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1); /*0xa79d16*/
  if ( result ) /*0xa79d20*/
    return sub_83D840(result); /*0xa79d25*/
  return result; /*0xa79d22*/
}