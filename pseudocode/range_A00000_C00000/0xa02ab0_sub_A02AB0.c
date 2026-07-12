// Function: sub_A02AB0
// Address: 0xa02ab0
// Size: 0x21
// Prototype: 

void *__thiscall sub_A02AB0(void *this, char a2)
{
  sub_9FE020();
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

