// Function: sub_A3ABC0
// Address: 0xa3abc0
// Size: 0x18

int __stdcall sub_A3ABC0(int a1, int a2, int a3)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 20); /*0xa3abc6*/
  if ( result == a2 ) /*0xa3abcc*/
  {
    *(_DWORD *)(a1 + 20) = a3; /*0xa3abd1*/
    return a3; /*0xa3abce*/
  }
  return result; /*0xa3abd4*/
}