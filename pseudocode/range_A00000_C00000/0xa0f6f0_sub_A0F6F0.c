// Function: sub_A0F6F0
// Address: 0xa0f6f0
// Size: 0x5d
// Prototype: 

char __stdcall sub_A0F6F0(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FC7E0();
    *a1 = &Phyre::PPostProcessing::PMLAA::`vftable';
    a1[1] = dword_1943E88;
  }
  return 1;
}

