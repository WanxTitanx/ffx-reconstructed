// Function: sub_9A9B60
// Address: 0x9a9b60
_DWORD *__thiscall sub_9A9B60(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
