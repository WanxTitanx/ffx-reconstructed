// Function: sub_A3DF20
// Address: 0xa3df20
// Size: 0x34
// Prototype: int __thiscall(int this)

int __thiscall sub_A3DF20(int this)
{
  int result; // eax

  if ( *(_BYTE *)(this + 24) )
  {
    (*(void (__cdecl **)(_DWORD))(this + 60))(*(_DWORD *)(this + 4));
    PhyreEvent_Close((HANDLE *)(this + 28));
    *(_BYTE *)(this + 32) = 0;
    result = PhyreEvent_Close((HANDLE *)(this + 36));
    *(_BYTE *)(this + 40) = 0;
    *(_BYTE *)(this + 24) = 0;
  }
  return result;
}

