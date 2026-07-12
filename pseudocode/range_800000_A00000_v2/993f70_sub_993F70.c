// Function: sub_993F70
// Address: 0x993f70
_DWORD **__thiscall sub_993F70(_DWORD **this, char a2)
{
  *this = &btConvexConvexAlgorithm::`vftable';
  if ( *((_BYTE *)this + 16) && *(this + 5) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(this + 1) + 12))(*(this + 1), *(this + 5));
  sub_9A8280(this);
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
