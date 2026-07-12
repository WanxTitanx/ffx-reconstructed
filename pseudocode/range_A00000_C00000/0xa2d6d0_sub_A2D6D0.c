// Function: sub_A2D6D0
// Address: 0xa2d6d0
// Size: 0x2b

int __thiscall sub_A2D6D0(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 14); /*0xa2d6d5*/
  if ( v2 ) /*0xa2d6da*/
    return v2(a2); /*0xa2d6df*/
  else
    return *(_DWORD *)((char *)*(this + 9) + a2 - *((_DWORD *)*(this + 3) + 34)); /*0xa2d6f4*/
}