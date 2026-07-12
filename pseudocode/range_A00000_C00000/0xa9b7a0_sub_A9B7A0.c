// Function: sub_A9B7A0
// Address: 0xa9b7a0
// Size: 0x95
// Prototype: int __thiscall(void *)

void *__thiscall sub_A9B7A0(void **this)
{
  void **v2; // esi
  void **v3; // esi
  int n7; // edi

  v2 = this + 4;
  if ( this != (void **)-16 )
  {
    if ( *(this + 6) )
      free_1(*(this + 6));
    if ( v2[3] )
      free_1(v2[3]);
    *(_QWORD *)v2 = 0;
    *((_QWORD *)v2 + 1) = 0;
    v2[4] = 0;
  }
  v3 = this + 12;
  n7 = 7;
  do
  {
    free_1(*v3);
    v3 += 4;
    --n7;
  }
  while ( n7 );
  free_1(*(this + 9));
  free_1(*(this + 38));
  free_1(*(this + 40));
  return memset(this, 0, 0xB4u);
}

