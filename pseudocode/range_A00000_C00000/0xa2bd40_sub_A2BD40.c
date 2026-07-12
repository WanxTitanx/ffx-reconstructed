// Function: sub_A2BD40
// Address: 0xa2bd40
// Size: 0x21
// Prototype: 

void *__thiscall sub_A2BD40(void *this, char a2)
{
  sub_5760E0();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

