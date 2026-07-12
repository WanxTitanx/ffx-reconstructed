// Function: sub_A2D5D0
// Address: 0xa2d5d0
// Size: 0x36
// Prototype: 

char __stdcall sub_A2D5D0(int *a1)
{
  if ( *a1 >= 0 && a1[1] )
    Phyre_Memory_AlignedFree(a1[1]);
  a1[1] = 0;
  *a1 = 0;
  return 1;
}

