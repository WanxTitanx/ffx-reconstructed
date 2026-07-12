// Function: sub_994020
// Address: 0x994020
_DWORD *__thiscall sub_994020(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::Result::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
