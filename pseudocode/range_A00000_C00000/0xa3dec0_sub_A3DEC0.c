// Function: sub_A3DEC0
// Address: 0xa3dec0
// Size: 0x39
// Prototype: 

_DWORD *__thiscall sub_A3DEC0(_DWORD *this, int a2)
{
  _DWORD *result; // eax

  if ( !(unsigned __int8)sub_A3DFB0(this + 4, *(this + 3), a2, this + 2, this + 7) )
    return 0;
  result = (_DWORD *)(*(this + 3) + *(this + 1));
  *result = a2;
  return result;
}

