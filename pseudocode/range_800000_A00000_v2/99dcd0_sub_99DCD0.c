// Function: sub_99DCD0
// Address: 0x99dcd0
_BYTE *__thiscall sub_99DCD0(_BYTE *this, int a2, int a3, int a4, int a5)
{
  sub_9A8260(a3, a4, a5);
  *(_DWORD *)this = &btSphereSphereCollisionAlgorithm::`vftable';
  *(this + 8) = 0;
  *((_DWORD *)this + 3) = a2;
  if ( !a2 )
  {
    *((_DWORD *)this + 3) = (*(int (__thiscall **)(_DWORD, int, int))(**((_DWORD **)this + 1) + 8))(
                              *((_DWORD *)this + 1),
                              a4,
                              a5);
    *(this + 8) = 1;
  }
  return this;
}
