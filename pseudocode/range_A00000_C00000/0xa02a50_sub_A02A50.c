// Function: sub_A02A50
// Address: 0xa02a50
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02A50(void *this, char a2)
{
  sub_9FDF60();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

