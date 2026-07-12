// Function: sub_A029F0
// Address: 0xa029f0
// Size: 0x21
// Prototype: 

void *__thiscall sub_A029F0(void *this, char a2)
{
  sub_9FDF60();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

