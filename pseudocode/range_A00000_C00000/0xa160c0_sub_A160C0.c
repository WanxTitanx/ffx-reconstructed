// Function: sub_A160C0
// Address: 0xa160c0
// Size: 0x19
// Prototype: 

int __thiscall sub_A160C0(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 13);
  if ( v2 )
    return v2(a2);
  else
    return 0;
}

