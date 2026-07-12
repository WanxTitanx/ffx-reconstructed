// Function: sub_A02D30
// Address: 0xa02d30
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02D30(void *this, char a2)
{
  sub_9FE2A0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

