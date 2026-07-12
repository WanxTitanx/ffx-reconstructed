// Function: sub_A03110
// Address: 0xa03110
// Size: 0x21
// Prototype: 

void *__thiscall sub_A03110(void *this, char a2)
{
  sub_9FE890();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

