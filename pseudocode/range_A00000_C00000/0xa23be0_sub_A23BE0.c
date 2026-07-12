// Function: sub_A23BE0
// Address: 0xa23be0
// Size: 0x41
// Prototype: 

int __thiscall sub_A23BE0(int *this, int a2, int a3)
{
  int v4; // ecx

  if ( a3 >= 0 )
  {
    v4 = *(this + 1);
    if ( v4 != a2 && *this >= 0 )
      Phyre_Memory_AlignedFree(v4);
    *(this + 1) = a2;
    *this = a3 | 0x80000000;
  }
  return 0;
}

