// Function: sub_99DDC0
// Address: 0x99ddc0
_DWORD **__thiscall sub_99DDC0(_DWORD **this, char a2)
{
  *this = &btSphereSphereCollisionAlgorithm::`vftable';
  if ( *((_BYTE *)this + 8) && *(this + 3) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 3));
  sub_9A8280(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
