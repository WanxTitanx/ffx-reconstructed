// Function: sub_A2D520
// Address: 0xa2d520
// Size: 0x42
// Prototype: 

char __stdcall sub_A2D520(int a1)
{
  if ( a1 )
  {
    *(_DWORD *)a1 = 0;
    *(float *)(a1 + 20) = 0.0;
    *(_DWORD *)(a1 + 4) = 0;
    *(float *)(a1 + 24) = 0.0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_BYTE *)(a1 + 44) = 0;
    *(float *)(a1 + 16) = 0.0;
    *(float *)(a1 + 12) = 0.0;
    *(float *)(a1 + 32) = 0.0;
    *(float *)(a1 + 28) = 0.0;
    *(float *)(a1 + 40) = 0.0;
    *(float *)(a1 + 36) = 0.0;
  }
  return 1;
}

