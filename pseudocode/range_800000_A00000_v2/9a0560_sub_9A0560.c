// Function: sub_9A0560
// Address: 0x9a0560
int __thiscall sub_9A0560(_DWORD *this)
{
  int result; // eax

  *this = &btSortedOverlappingPairCache::`vftable';
  result = *(this + 4);
  if ( result )
  {
    if ( *((_BYTE *)this + 20) )
      result = sub_9D4D50(result);
    *(this + 4) = 0;
  }
  *((_BYTE *)this + 20) = 1;
  *(this + 4) = 0;
  *(this + 2) = 0;
  *(this + 3) = 0;
  *this = &btOverlappingPairCallback::`vftable';
  return result;
}
