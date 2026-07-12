// Function: sub_A97330
// Address: 0xa97330
// Size: 0xd3
// Prototype: int __thiscall(void *)

void *__thiscall sub_A97330(void **this)
{
  int i; // ebx
  int j; // esi
  int k; // esi
  void *result; // eax

  if ( this )
  {
    if ( *(this + 4) )
      free_1(*(this + 4));
    if ( *(this + 5) )
      free_1(*(this + 5));
    if ( *(this + 6) )
      free_1(*(this + 6));
    if ( *(this + 2) )
    {
      for ( i = 0; i < 68; i += 4 )
      {
        for ( j = 0; j < 32; j += 4 )
          free_1(*(void **)(*(_DWORD *)((char *)*(this + 2) + i) + j));
        free_1(*(void **)((char *)*(this + 2) + i));
      }
      free_1(*(this + 2));
    }
    if ( *(this + 3) )
    {
      for ( k = 0; k < 12; k += 4 )
        free_1(*(void **)((char *)*(this + 3) + k));
      free_1(*(this + 3));
    }
    return memset(this, 0, 0x34u);
  }
  return result;
}

