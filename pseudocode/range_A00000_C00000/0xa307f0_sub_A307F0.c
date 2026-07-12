// Function: sub_A307F0
// Address: 0xa307f0
// Size: 0x48
// Prototype: 

char __thiscall sub_A307F0(int *this, unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  char result; // al

  v3 = *this & 0x7FFFFFFF;
  if ( v3 >= a2 )
    v3 = a2;
  v4 = v3 | *this & 0x80000000;
  result = ~(((v3 | *this & 0x80000000) & 0x80000000) != 0);
  *this = v4;
  if ( (result & 1) != 0 && !v4 )
  {
    result = Phyre_Memory_AlignedFree(*(this + 1));
    *(this + 1) = 0;
  }
  return result;
}

