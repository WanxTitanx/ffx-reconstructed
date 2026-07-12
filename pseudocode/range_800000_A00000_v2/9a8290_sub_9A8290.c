// Function: sub_9A8290
// Address: 0x9a8290
_DWORD *__thiscall sub_9A8290(_DWORD *this, char a2)
{
  *this = &btCollisionAlgorithm::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
