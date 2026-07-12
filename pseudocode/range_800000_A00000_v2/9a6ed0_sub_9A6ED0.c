// Function: sub_9A6ED0
// Address: 0x9a6ed0
_DWORD *__thiscall sub_9A6ED0(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::Result::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
