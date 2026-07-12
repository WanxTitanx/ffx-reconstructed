// Function: sub_9C5B70
// Address: 0x9c5b70
_DWORD *__thiscall sub_9C5B70(_DWORD *this, char a2)
{
  *this = &btTypedConstraint::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
