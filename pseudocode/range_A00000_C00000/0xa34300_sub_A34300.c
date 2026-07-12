// Function: sub_A34300
// Address: 0xa34300
// Size: 0x31
// Prototype: 

char __stdcall sub_A34300(int *a1)
{
  if ( *a1 >= 0 )
    Phyre_Memory_AlignedFree(a1[1]);
  a1[1] = 0;
  *a1 = 0;
  return 1;
}

