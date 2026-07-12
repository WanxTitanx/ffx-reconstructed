// Function: sub_A3D310
// Address: 0xa3d310
// Size: 0xaf
// Prototype: 

_DWORD *__thiscall sub_A3D310(_DWORD *this)
{
  int v2; // eax

  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *(this + 4) = 0;
  *(this + 5) = 0;
  *(this + 6) = 0;
  *((_BYTE *)this + 40) = 0;
  *((float *)this + 9) = 0.0;
  *((float *)this + 8) = 0.0;
  *((float *)this + 7) = 0.0;
  v2 = *(this + 1);
  if ( v2 )
  {
    if ( *(this + 2) && v2 >= 0 )
      Phyre_Memory_AlignedFree(*(this + 2));
    *(this + 2) = 0;
    *(this + 1) = 0;
  }
  return this;
}

