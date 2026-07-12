// Function: sub_9A6050
// Address: 0x9a6050
_DWORD *__thiscall sub_9A6050(_DWORD *this, char a2)
{
  *this = &btConvexCast::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
