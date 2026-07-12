// Function: sub_A02B40
// Address: 0xa02b40
// Size: 0x69
// Prototype: 

void *__thiscall sub_A02B40(void *this, char a2)
{
  sub_5853C0();
  sub_5853C0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

