// Function: sub_A3DD90
// Address: 0xa3dd90
// Size: 0x30
// Prototype: int __thiscall(_DWORD *this)

int __thiscall sub_A3DD90(_DWORD *this)
{
  _DWORD *v2; // edi

  v2 = this + 5;
  if ( (unsigned __int8)sub_A3DFB0(this + 5, *(this + 2), *(_DWORD *)(*(this + 1) + *(this + 2)), this + 3, this + 9) )
    return *(this + 1) + *v2;
  else
    return 0;
}

