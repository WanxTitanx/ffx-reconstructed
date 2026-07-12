// Function: sub_99DD50
// Address: 0x99dd50
int __thiscall sub_99DD50(_DWORD **this)
{
  *this = &btSphereSphereCollisionAlgorithm::`vftable';
  if ( *((_BYTE *)this + 8) && *(this + 3) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 3));
  return sub_9A8280(this);
}
