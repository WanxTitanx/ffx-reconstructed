// Function: sub_A79DB0
// Address: 0xa79db0
// Size: 0x1f

int __cdecl sub_A79DB0(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1); /*0xa79db6*/
  if ( result ) /*0xa79dc0*/
    return sub_83D900(result); /*0xa79dc5*/
  return result; /*0xa79dc2*/
}