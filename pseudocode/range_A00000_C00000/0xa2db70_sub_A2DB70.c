// Function: sub_A2DB70
// Address: 0xa2db70
// Size: 0x45
// Prototype: 

int __thiscall sub_A2DB70(int *this, int a2, int a3)
{
  int v4; // ecx

  if ( a3 >= 0 )
  {
    v4 = *(this + 1);
    if ( v4 != a2 && *this >= 0 && v4 )
      Phyre_Memory_AlignedFree(v4);
    *(this + 1) = a2;
    *this = a3 | 0x80000000;
  }
  return 0;
}

