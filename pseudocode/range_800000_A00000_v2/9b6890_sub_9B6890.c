// Function: sub_9B6890
// Address: 0x9b6890
_DWORD *__thiscall sub_9B6890(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, int a5, int a6)
{
  *this = &btCollisionWorld::ClosestConvexResultCallback::`vftable';
  *(this + 1) = 1065353216;
  *((_WORD *)this + 4) = 1;
  *((_WORD *)this + 5) = -1;
  *(this + 4) = *a3;
  *(this + 5) = a3[1];
  *(this + 6) = a3[2];
  *(this + 7) = a3[3];
  *(this + 8) = *a4;
  *(this + 9) = a4[1];
  *(this + 10) = a4[2];
  *(this + 11) = a4[3];
  *(this + 24) = a2;
  *(this + 26) = a5;
  *(this + 27) = a6;
  *(this + 20) = 0;
  *this = &btClosestNotMeConvexResultCallback::`vftable';
  *(this + 25) = 0;
  return this;
}
