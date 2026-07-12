// Function: sub_9A0650
// Address: 0x9a0650
_DWORD *__thiscall sub_9A0650(_DWORD *this, char a2)
{
  *this = &btOverlapCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
