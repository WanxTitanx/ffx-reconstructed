// Function: sub_9ACCC0
// Address: 0x9accc0
_DWORD *__thiscall sub_9ACCC0(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
