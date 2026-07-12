// Function: sub_A3B010
// Address: 0xa3b010
// Size: 0x38

int __stdcall sub_A3B010(_DWORD *a1, int a2, int a3)
{
  int n5; // ecx

  n5 = a1[12] >> 28; /*0xa3b019*/
  if ( n5 != 5 ) /*0xa3b01f*/
  {
    if ( a1[5] != a2 ) /*0xa3b027*/
      return 0; /*0xa3b02c*/
    if ( n5 == 1 ) /*0xa3b032*/
      sub_A3A010(a1, 2); /*0xa3b037*/
  }
  return 1; /*0xa3b02b*/
}