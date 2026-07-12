// Function: sub_A2D570
// Address: 0xa2d570
// Size: 0x57
// Prototype: 

char __stdcall sub_A2D570(int a1)
{
  int v1; // ecx

  v1 = Phyre_PObject_ComputeLayout(dword_CA37D0);
  if ( !v1 )
    return 0;
  if ( a1 )
  {
    *(_BYTE *)a1 = 0;
    *(float *)(a1 + 8) = 0.0;
    *(_DWORD *)(a1 + 4) = 0;
    *(float *)(a1 + 12) = 0.0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 0;
    *(_DWORD *)(a1 + 24) = 0;
    *(_DWORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 32) = v1;
  }
  return 1;
}

