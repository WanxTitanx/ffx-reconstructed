// Function: sub_A02C90
// Address: 0xa02c90
// Size: 0x69
// Prototype: 

void *__thiscall sub_A02C90(void *this, char a2)
{
  sub_5853C0();
  sub_5853C0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

