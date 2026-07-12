// Function: sub_9B6FC0
// Address: 0x9b6fc0
_DWORD *__thiscall sub_9B6FC0(_DWORD *this, char a2)
{
  *this = &btCollisionWorld::ConvexResultCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
