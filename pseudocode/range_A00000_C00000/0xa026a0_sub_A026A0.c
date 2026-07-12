// Function: sub_A026A0
// Address: 0xa026a0
// Size: 0x21
// Prototype: 

void *__thiscall sub_A026A0(void *this, char a2)
{
  sub_9FDC00();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

