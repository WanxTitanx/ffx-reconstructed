// Function: sub_A0F9E0
// Address: 0xa0f9e0
// Size: 0x5e
// Prototype: 

char __stdcall sub_A0F9E0(int a1)
{
  if ( a1 )
  {
    *(_DWORD *)(a1 + 8) = 0;
    *(float *)(a1 + 20) = 0.0015;
    *(_DWORD *)(a1 + 12) = 0;
    *(_WORD *)(a1 + 16) = 256;
    *(float *)(a1 + 24) = 0.69999999;
    *(_DWORD *)a1 = &Phyre::PPostProcessing::PScreenSpaceAmbientOcclusion::`vftable';
    *(_DWORD *)(a1 + 4) = dword_1943C70;
    *(float *)(a1 + 28) = 0.0085000005;
    *(float *)(a1 + 32) = 0.018999999;
    *(float *)(a1 + 36) = 0.1;
  }
  return 1;
}

