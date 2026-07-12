// Function: sub_A02BB0
// Address: 0xa02bb0
// Size: 0x69
// Prototype: 

void *__thiscall sub_A02BB0(void *this, char a2)
{
  sub_5853C0();
  sub_5853C0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

