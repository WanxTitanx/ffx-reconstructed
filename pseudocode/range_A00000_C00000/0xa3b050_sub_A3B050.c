// Function: sub_A3B050
// Address: 0xa3b050
// Size: 0x38

int __stdcall sub_A3B050(_DWORD *a1, int a2, int a3)
{
  int n5; // ecx

  n5 = a1[12] >> 28; /*0xa3b059*/
  if ( n5 != 5 ) /*0xa3b05f*/
  {
    if ( a1[5] != a2 ) /*0xa3b067*/
      return 0; /*0xa3b06c*/
    if ( n5 == 1 ) /*0xa3b072*/
      sub_A3A010(a1, 2); /*0xa3b077*/
  }
  return 1; /*0xa3b06b*/
}