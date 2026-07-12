// Function: sub_9A0460
// Address: 0x9a0460
int __thiscall sub_9A0460(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  *this = &btHashedOverlappingPairCache::`vftable';
  v2 = *(this + 16);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 68) )
      sub_9D4D50(v2);
    *(this + 16) = 0;
  }
  *((_BYTE *)this + 68) = 1;
  *(this + 16) = 0;
  *(this + 14) = 0;
  *(this + 15) = 0;
  v3 = *(this + 11);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 48) )
      sub_9D4D50(v3);
    *(this + 11) = 0;
  }
  *((_BYTE *)this + 48) = 1;
  *(this + 11) = 0;
  *(this + 9) = 0;
  *(this + 10) = 0;
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
