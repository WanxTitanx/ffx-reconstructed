// Function: sub_A3DD20
// Address: 0xa3dd20
// Size: 0x2b
// Prototype: int __thiscall(_DWORD)

_BYTE *__thiscall sub_A3DD20(_BYTE *this)
{
  *(_DWORD *)this = &CDataFrameQueue::`vftable';
  *(this + 24) = 0;
  Phyre_ZeroDword((_DWORD *)this + 7);
  *(this + 32) = 0;
  Phyre_ZeroDword((_DWORD *)this + 9);
  *(this + 40) = 0;
  return this;
}

