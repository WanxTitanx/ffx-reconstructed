// Function: sub_A02A80
// Address: 0xa02a80
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02A80(void *this, char a2)
{
  sub_9FE0D0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

