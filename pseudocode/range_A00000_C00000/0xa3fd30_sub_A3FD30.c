// Function: sub_A3FD30
// Address: 0xa3fd30
// Size: 0xe0
// Prototype: 

char __thiscall sub_A3FD30(int *this)
{
  int *v2; // edi
  int n16; // ebx
  int v4; // eax

  Phyre_Memory_AlignedFree(*(this + 16));
  v2 = this + 32;
  n16 = 16;
  do
  {
    Phyre_Memory_AlignedFree(*v2++);
    --n16;
  }
  while ( n16 );
  if ( *(this + 50) >= 0 && *(this + 51) )
    Phyre_Memory_AlignedFree(*(this + 51));
  *(this + 51) = 0;
  *(this + 50) = 0;
  LOBYTE(v4) = ~(*(this + 48) < 0);
  if ( *(this + 48) >= 0 )
  {
    v4 = *(this + 49);
    if ( v4 )
      LOBYTE(v4) = Phyre_Memory_AlignedFree(*(this + 49));
  }
  *(this + 49) = 0;
  *(this + 48) = 0;
  return v4;
}

