// Function: sub_A32500
// Address: 0xa32500
// Size: 0x21
// Prototype: 

void *__thiscall sub_A32500(void *this, char a2)
{
  sub_5A0400();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

