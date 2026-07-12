// Function: sub_A8DA90
// Address: 0xa8da90
// Size: 0xc5
// Prototype: 

int __thiscall sub_A8DA90(_DWORD *this)
{
  int v2; // eax
  int v3; // eax

  *this = &btSimulationIslandManager::`vftable';
  v2 = *(this + 14);
  if ( v2 )
  {
    if ( *((_BYTE *)this + 60) )
      sub_9D4D50(v2);
    *(this + 14) = 0;
  }
  *((_BYTE *)this + 60) = 1;
  *(this + 14) = 0;
  *(this + 12) = 0;
  *(this + 13) = 0;
  v3 = *(this + 9);
  if ( v3 )
  {
    if ( *((_BYTE *)this + 40) )
      sub_9D4D50(v3);
    *(this + 9) = 0;
  }
  *((_BYTE *)this + 40) = 1;
  *(this + 9) = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
  return sub_A8E680();
}

