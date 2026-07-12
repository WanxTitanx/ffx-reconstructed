// Function: sub_A935B0
// Address: 0xa935b0
// Size: 0x67
// Prototype: int __thiscall(void *)

void *__thiscall sub_A935B0(void **this)
{
  if ( *(this + 4) )
    free_1(*(this + 4));
  if ( *(this + 5) )
    free_1(*(this + 5));
  if ( *(this + 6) )
    free_1(*(this + 6));
  if ( *(this + 7) )
    free_1(*(this + 7));
  if ( *(this + 8) )
    free_1(*(this + 8));
  return memset(this, 0, 0x38u);
}

