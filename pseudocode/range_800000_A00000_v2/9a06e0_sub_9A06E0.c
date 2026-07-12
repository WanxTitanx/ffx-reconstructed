// Function: sub_9A06E0
// Address: 0x9a06e0
_DWORD *__thiscall sub_9A06E0(_DWORD *this, char a2)
{
  int v3; // eax

  *this = &btSortedOverlappingPairCache::`vftable';
  v3 = *(this + 4);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 20) )
      sub_9D4D50(v3);
    *(this + 4) = 0;
  }
  *((_BYTE *)this + 20) = 1;
  *(this + 4) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *this = &btOverlappingPairCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}
