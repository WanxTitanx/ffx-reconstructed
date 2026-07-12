// Function: sub_A030B0
// Address: 0xa030b0
// Size: 0x21
// Prototype: 

void *__thiscall sub_A030B0(void *this, char a2)
{
  sub_9FE890();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

