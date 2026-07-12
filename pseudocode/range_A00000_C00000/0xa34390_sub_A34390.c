// Function: sub_A34390
// Address: 0xa34390
// Size: 0x2b

int __thiscall sub_A34390(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 14); /*0xa34395*/
  if ( v2 ) /*0xa3439a*/
    return v2(a2); /*0xa3439f*/
  else
    return *(_DWORD *)((char *)*(this + 9) + a2 - *((_DWORD *)*(this + 3) + 34)); /*0xa343b4*/
}