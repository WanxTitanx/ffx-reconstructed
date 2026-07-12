// Function: sub_A173B0
// Address: 0xa173b0
// Size: 0x2f

int __stdcall sub_A173B0(int a1, int a2)
{
  int v2; // edi
  int result; // eax

  v2 = sub_A096D0(a1); /*0xa173c3*/
  sub_A00A70(a2, v2); /*0xa173c8*/
  result = *(_DWORD *)(v2 + 3404); /*0xa173cd*/
  *(_DWORD *)(a2 + 3404) = result; /*0xa173d4*/
  return result; /*0xa173d3*/
}