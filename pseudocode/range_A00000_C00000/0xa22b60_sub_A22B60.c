// Function: sub_A22B60
// Address: 0xa22b60
// Size: 0x66
// Prototype: 

int __thiscall sub_A22B60(int *this, int a2)
{
  int v3; // ebx
  int v5; // ecx

  if ( a2 != *this )
  {
    v3 = 0;
    if ( a2 )
    {
      v3 = sub_42FC60(16 * a2, 16);
      if ( !v3 )
        return 13;
    }
    v5 = *(this + 1);
    if ( v5 != v3 && *this >= 0 )
    {
      if ( v5 )
        Phyre_Memory_AlignedFree(*(this + 1));
    }
    *(this + 1) = v3;
    *this = a2;
  }
  return 0;
}

