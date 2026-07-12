// Function: sub_99C880
// Address: 0x99c880
_DWORD **__thiscall sub_99C880(_DWORD **this, char a2)
{
  *this = &btConvexPlaneCollisionAlgorithm::`vftable';
  if ( *((_BYTE *)this + 8) && *(this + 3) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 3));
  *this = &btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
