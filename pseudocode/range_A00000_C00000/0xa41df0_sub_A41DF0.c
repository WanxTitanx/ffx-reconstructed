// Function: sub_A41DF0
// Address: 0xa41df0
// Size: 0x3f
// Prototype: 

char __stdcall sub_A41DF0(int a1)
{
  if ( a1 )
  {
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
    *(float *)(a1 + 16) = 0.0;
    *(float *)(a1 + 20) = 0.0;
    *(float *)(a1 + 24) = 0.0;
    *(float *)(a1 + 32) = 0.0;
    *(float *)(a1 + 36) = 0.0;
    *(float *)(a1 + 40) = 0.0;
  }
  return 1;
}

