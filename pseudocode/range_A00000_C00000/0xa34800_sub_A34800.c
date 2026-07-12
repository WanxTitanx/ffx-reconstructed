// Function: sub_A34800
// Address: 0xa34800
// Size: 0x22
// Prototype: 

int __thiscall sub_A34800(int (__thiscall **this)(int, int, int), int a2, int a3, int a4)
{
  int (__thiscall *v4)(int, int, int); // eax

  v4 = *(this + 15);
  if ( v4 )
    return v4(a2, a3, a4);
  else
    return 21;
}

