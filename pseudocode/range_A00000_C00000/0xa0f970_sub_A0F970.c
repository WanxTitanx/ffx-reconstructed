// Function: sub_A0F970
// Address: 0xa0f970
// Size: 0x31
// Prototype: 

char __stdcall sub_A0F970(int a1)
{
  if ( a1 )
  {
    *(_DWORD *)a1 = &Phyre::PPostProcessing::PPostEffectBase::`vftable';
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
    *(_WORD *)(a1 + 16) = 256;
  }
  return 1;
}

