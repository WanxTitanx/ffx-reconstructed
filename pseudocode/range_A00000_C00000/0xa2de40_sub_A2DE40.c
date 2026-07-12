// Function: sub_A2DE40
// Address: 0xa2de40
// Size: 0x21
// Prototype: 

void *__thiscall sub_A2DE40(void *this, char a2)
{
  sub_5A0400();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

