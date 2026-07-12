// Function: sub_A02770
// Address: 0xa02770
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02770(void *this, char a2)
{
  sub_9FDC00();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

