// Function: sub_A17280
// Address: 0xa17280
// Size: 0x5f

int __stdcall sub_A17280(int a1, _DWORD *a2)
{
  _DWORD *v2; // edi
  int result; // eax

  v2 = (_DWORD *)sub_A090C0(a1); /*0xa17293*/
  sub_9FFD70(v2); /*0xa17298*/
  a2[30] = v2[30]; /*0xa172a0*/
  a2[31] = v2[31]; /*0xa172a6*/
  a2[32] = v2[32]; /*0xa172af*/
  a2[33] = v2[33]; /*0xa172bb*/
  a2[34] = v2[34]; /*0xa172c7*/
  result = v2[35]; /*0xa172cd*/
  a2[35] = result; /*0xa172d4*/
  return result; /*0xa172d3*/
}