// Function: sub_A79CF0
// Address: 0xa79cf0
// Size: 0x1f

int __cdecl sub_A79CF0(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1); /*0xa79cf6*/
  if ( result ) /*0xa79d00*/
    return sub_82AE40(result); /*0xa79d05*/
  return result; /*0xa79d02*/
}