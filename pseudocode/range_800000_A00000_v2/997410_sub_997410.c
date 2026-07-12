// Function: sub_997410
// Address: 0x997410
_DWORD *__thiscall sub_997410(_DWORD *this, char a2)
{
  *this = &btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
