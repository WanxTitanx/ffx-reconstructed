// Function: sub_A3AFB0
// Address: 0xa3afb0
// Size: 0x54

int __stdcall sub_A3AFB0(int a1)
{
  _DWORD *v1; // edx
  bool v2; // zf
  unsigned int v3; // esi
  _DWORD *v4; // ecx

  v1 = dword_1A858B4; /*0xa3afb3*/
  v2 = dword_1A858B4[438] == 0; /*0xa3afba*/
  v3 = dword_1A858B4[683]; /*0xa3afc1*/
  v4 = dword_1A858B4 + 683; /*0xa3afc7*/
  dword_1A858B4[683] = v3 - 28; /*0xa3afd0*/
  if ( v2 || !v1[439] || v3 >= (unsigned int)v4 ) /*0xa3afdf*/
    return 0; /*0xa3affd*/
  sub_A3C570(a1); /*0xa3afe4*/
  sub_A3CD30(); /*0xa3afec*/
  sub_A3C350(); /*0xa3aff1*/
  return *(_DWORD *)v3; /*0xa3aff8*/
}