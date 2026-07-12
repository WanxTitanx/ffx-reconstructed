// Function: sub_9B6C10
// Address: 0x9b6c10
int __thiscall sub_9B6C10(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int result; // eax

  v2 = *(this + 21);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 88) )
      sub_9D4D50(v2);
    *(this + 21) = 0;
  }
  *((_BYTE *)this + 88) = 1;
  *(this + 21) = 0;
  *(this + 19) = 0;
  *(this + 20) = 0;
  v3 = *(this + 16);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 68) )
      sub_9D4D50(v3);
    *(this + 16) = 0;
  }
  *((_BYTE *)this + 68) = 1;
  *(this + 16) = 0;
  *(this + 14) = 0;
  *(this + 15) = 0;
  result = *(this + 11);
  if ( result )
  {
    if ( *((_BYTE *)this + 48) )
      result = sub_9D4D50(result);
    *(this + 11) = 0;
  }
  *((_BYTE *)this + 48) = 1;
  *(this + 11) = 0;
  *(this + 9) = 0;
  *(this + 10) = 0;
  *this = &btSimulationIslandManager::IslandCallback::`vftable';
  return result;
}
