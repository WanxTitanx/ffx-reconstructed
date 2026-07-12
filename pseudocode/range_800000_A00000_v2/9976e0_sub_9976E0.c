// Function: sub_9976E0
// Address: 0x9976e0
_DWORD *__thiscall sub_9976E0(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  sub_96AE20();
  *this = &btTriangleShape::`vftable';
  *(this + 1) = 1;
  *(this + 16) = *a2;
  *(this + 17) = a2[1];
  *(this + 18) = a2[2];
  *(this + 19) = a2[3];
  *(this + 20) = *a3;
  *(this + 21) = a3[1];
  *(this + 22) = a3[2];
  *(this + 23) = a3[3];
  *(this + 24) = *a4;
  *(this + 25) = a4[1];
  *(this + 26) = a4[2];
  *(this + 27) = a4[3];
  return this;
}
