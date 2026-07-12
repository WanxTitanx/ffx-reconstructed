// Function: sub_A16000
// Address: 0xa16000
// Size: 0x2b
// Prototype: 

int __thiscall sub_A16000(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 14);
  if ( v2 )
    return v2(a2);
  else
    return *(_DWORD *)((char *)*(this + 9) + a2 - *((_DWORD *)*(this + 3) + 34));
}

