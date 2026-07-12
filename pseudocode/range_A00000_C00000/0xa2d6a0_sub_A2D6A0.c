// Function: sub_A2D6A0
// Address: 0xa2d6a0
// Size: 0x2b

int __thiscall sub_A2D6A0(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 14); /*0xa2d6a5*/
  if ( v2 ) /*0xa2d6aa*/
    return v2(a2); /*0xa2d6af*/
  else
    return *(_DWORD *)((char *)*(this + 9) + a2 - *((_DWORD *)*(this + 3) + 34)); /*0xa2d6c4*/
}