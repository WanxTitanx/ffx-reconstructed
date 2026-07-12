// Function: sub_A288B0
// Address: 0xa288b0
// Size: 0x33

_DWORD *__thiscall sub_A288B0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v6; // [esp-8h] [ebp-Ch]

  *(_BYTE *)this = 1; /*0xa288bf*/
  *(this + 14) = a2; /*0xa288c2*/
  v4 = IggyValueRefFromTempRef(a2, a3, 0); /*0xa288c5*/
  v6 = *(this + 14); /*0xa288cc*/
  *(this + 1) = v4; /*0xa288cf*/
  IggyValuePathFromRef(this + 2, v6, v4); /*0xa288d6*/
  return this; /*0xa288de*/
}