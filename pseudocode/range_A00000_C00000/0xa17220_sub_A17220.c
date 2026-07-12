// Function: sub_A17220
// Address: 0xa17220
// Size: 0x5f

int __stdcall sub_A17220(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int result; // eax

  v2 = (_DWORD *)sub_A08FF0(a1); /*0xa17233*/
  sub_9FFD70(v2); /*0xa17238*/
  a2[30] = v2[30]; /*0xa17240*/
  a2[31] = v2[31]; /*0xa17246*/
  a2[32] = v2[32]; /*0xa1724f*/
  a2[33] = v2[33]; /*0xa1725b*/
  a2[34] = v2[34]; /*0xa17267*/
  result = v2[35]; /*0xa1726d*/
  a2[35] = result; /*0xa17274*/
  return result; /*0xa17273*/
}