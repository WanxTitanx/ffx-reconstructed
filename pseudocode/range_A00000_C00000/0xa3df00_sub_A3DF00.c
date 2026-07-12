// Function: sub_A3DF00
// Address: 0xa3df00
// Size: 0x11
// Prototype: int __thiscall(_DWORD *this)

int __thiscall sub_A3DF00(HANDLE *this)
{
  void *v1; // eax

  v1 = *(this + 4);
  *(this + 14) = (char *)*(this + 14) + 1;
  *(this + 3) = v1;
  return PhyreEvent_Set(this + 9);
}

