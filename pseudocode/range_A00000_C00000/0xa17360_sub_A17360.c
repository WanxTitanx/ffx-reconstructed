// Function: sub_A17360
// Address: 0xa17360
// Size: 0x2f

int __stdcall sub_A17360(int a1, int a2)
{
  int v2; // edi
  int result; // eax

  v2 = sub_A09510(a1); /*0xa17373*/
  sub_A00A70(a2, v2); /*0xa17378*/
  result = *(_DWORD *)(v2 + 3404); /*0xa1737d*/
  *(_DWORD *)(a2 + 3404) = result; /*0xa17384*/
  return result; /*0xa17383*/
}