// Function: sub_A2BBD0
// Address: 0xa2bbd0
// Size: 0x9b
// Prototype: 

char __thiscall sub_A2BBD0(int *this)
{
  int v2; // eax

  if ( *(this + 6) >= 0 && *(this + 7) )
    Phyre_Memory_AlignedFree(*(this + 7));
  *(this + 7) = 0;
  *(this + 6) = 0;
  LOBYTE(v2) = ~(*(this + 4) < 0);
  if ( *(this + 4) >= 0 )
  {
    v2 = *(this + 5);
    if ( v2 )
      LOBYTE(v2) = Phyre_Memory_AlignedFree(*(this + 5));
  }
  *(this + 5) = 0;
  *(this + 4) = 0;
  return v2;
}

