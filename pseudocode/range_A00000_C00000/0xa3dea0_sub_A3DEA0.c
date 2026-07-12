// Function: sub_A3DEA0
// Address: 0xa3dea0
// Size: 0x18
// Prototype: int __thiscall(_DWORD *this)

int __thiscall sub_A3DEA0(_DWORD *this)
{
  *((_BYTE *)this + 44) = 0;
  PhyreEvent_Set((HANDLE *)this + 7);
  return PhyreEvent_Set((HANDLE *)this + 9);
}

