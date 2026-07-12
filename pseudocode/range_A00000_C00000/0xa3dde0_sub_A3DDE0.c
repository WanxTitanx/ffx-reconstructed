// Function: sub_A3DDE0
// Address: 0xa3dde0
// Size: 0x10
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A3DDE0(int this)
{
  if ( *(_BYTE *)(this + 24) )
    return *(_DWORD *)(this + 56) - *(_DWORD *)(this + 52);
  else
    return 0;
}

