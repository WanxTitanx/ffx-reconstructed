// Function: sub_A02F10
// Address: 0xa02f10
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02F10(void *this, char a2)
{
  sub_9FE640();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

