// Function: sub_A332F0
// Address: 0xa332f0
// Size: 0x21
// Prototype: 

void *__thiscall sub_A332F0(void *this, char a2)
{
  sub_5760E0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

