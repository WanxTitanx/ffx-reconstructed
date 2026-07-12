// Function: sub_9A05F0
// Address: 0x9a05f0
_DWORD *__thiscall sub_9A05F0(_DWORD *this, char a2)
{
  *this = &btOverlapCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
