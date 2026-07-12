// Function: sub_A1B200
// Address: 0xa1b200
// Size: 0x18
// Prototype: 

bool __thiscall sub_A1B200(int this)
{
  _DWORD *v1; // eax

  v1 = *(_DWORD **)(this + 8);
  return v1 && *v1 && *(_BYTE *)(this + 17);
}

