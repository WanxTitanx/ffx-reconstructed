// Function: sub_99E7B0
// Address: 0x99e7b0
_DWORD *__thiscall sub_99E7B0(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::Result::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
