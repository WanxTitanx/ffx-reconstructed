// Function: sub_9A0680
// Address: 0x9a0680
_DWORD *__thiscall sub_9A0680(_DWORD *this, char a2)
{
  *this = &btOverlapCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
