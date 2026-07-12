// Function: sub_99C640
// Address: 0x99c640
int __thiscall sub_99C640(_DWORD **this)
{
  int result; // eax

  *this = &btConvexPlaneCollisionAlgorithm::`vftable';
  if ( *((_BYTE *)this + 8) && *(this + 3) )
    result = (*(int (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 3));
  *this = &btCollisionAlgorithm::`vftable';
  return result;
}
