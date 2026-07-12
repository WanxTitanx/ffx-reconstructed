// Function: sub_A3ABE0
// Address: 0xa3abe0
// Size: 0x62
// Prototype: int __stdcall(int, int, float, float)

int __stdcall sub_A3ABE0(int a1, int a2, float a3, float a4)
{
  float *v4; // edi
  _DWORD *v5; // esi

  v4 = (float *)dword_1A858B4; /*0xa3abe5*/
  v5 = dword_1A858B4 + 627; /*0xa3abf0*/
  memset(dword_1A858B4 + 627, 0, 0xE0u); /*0xa3abf9*/
  *((_DWORD *)v4 + 683) = v5; /*0xa3ac07*/
  *((_DWORD *)v4 + 436) = a1; /*0xa3ac0d*/
  *((_DWORD *)v4 + 437) = a2; /*0xa3ac13*/
  *((_DWORD *)v4 + 438) = a1; /*0xa3ac19*/
  *((_DWORD *)v4 + 439) = a2; /*0xa3ac1f*/
  v4[489] = a3; /*0xa3ac25*/
  v4[490] = a4; /*0xa3ac31*/
  return sub_A3CD30(); /*0xa3ac3c*/
}