// Function: sub_99D8E0
// Address: 0x99d8e0
int __thiscall sub_99D8E0(_DWORD **this)
{
  *this = &btBoxBoxCollisionAlgorithm::`vftable';
  if ( *((_BYTE *)this + 8) && *(this + 3) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 3));
  return sub_9A8280(this);
}
