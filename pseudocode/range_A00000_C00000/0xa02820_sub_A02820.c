// Function: sub_A02820
// Address: 0xa02820
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02820(void *this, char a2)
{
  sub_9FDD30();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

