// Function: sub_997440
// Address: 0x997440
_DWORD *__thiscall sub_997440(_DWORD *this, char a2)
{
  *this = &btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
