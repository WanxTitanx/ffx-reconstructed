// Function: sub_993FF0
// Address: 0x993ff0
_DWORD *__thiscall sub_993FF0(_DWORD *this, char a2)
{
  *this = &btDiscreteCollisionDetectorInterface::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
