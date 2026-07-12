// Function: sub_A343C0
// Address: 0xa343c0
// Size: 0x2b

int __thiscall sub_A343C0(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 14); /*0xa343c5*/
  if ( v2 ) /*0xa343ca*/
    return v2(a2); /*0xa343cf*/
  else
    return *(_DWORD *)((char *)*(this + 9) + a2 - *((_DWORD *)*(this + 3) + 34)); /*0xa343e4*/
}