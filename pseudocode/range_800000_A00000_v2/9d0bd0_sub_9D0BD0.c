// Function: sub_9D0BD0
// Address: 0x9d0bd0
_DWORD *__thiscall sub_9D0BD0(_DWORD *this, char a2)
{
  *this = &btTypedConstraint::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
