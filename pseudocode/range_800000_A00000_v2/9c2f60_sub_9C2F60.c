// Function: sub_9C2F60
// Address: 0x9c2f60
_WORD *__thiscall sub_9C2F60(_WORD *this, int a2, _DWORD *a3, int a4)
{
  *(this + 4) = 1;
  *(this + 5) = -1;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 24) = a2;
  *((_DWORD *)this + 1) = 1065353216;
  *((_DWORD *)this + 20) = 0;
  *(_DWORD *)this = &btKinematicClosestNotMeConvexResultCallback::`vftable';
  *((_DWORD *)this + 28) = *a3;
  *((_DWORD *)this + 29) = a3[1];
  *((_DWORD *)this + 30) = a3[2];
  *((_DWORD *)this + 31) = a3[3];
  *((_DWORD *)this + 32) = a4;
  return this;
}
