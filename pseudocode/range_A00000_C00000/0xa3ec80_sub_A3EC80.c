// Function: sub_A3EC80
// Address: 0xa3ec80
// Size: 0x20

int __stdcall sub_A3EC80(_DWORD *a1)
{
  int result; // eax

  result = sub_A41750(); /*0xa3ec83*/
  *(_WORD *)(result + 12) = 0; /*0xa3ec8b*/
  if ( result != -16 ) /*0xa3ec93*/
    *(_DWORD *)(result + 16) = *a1; /*0xa3ec9a*/
  return result; /*0xa3ec9c*/
}