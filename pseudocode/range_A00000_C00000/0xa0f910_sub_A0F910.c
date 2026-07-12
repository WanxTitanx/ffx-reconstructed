// Function: sub_A0F910
// Address: 0xa0f910
// Size: 0x60
// Prototype: 

char __stdcall sub_A0F910(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FCBB0();
    *a1 = &Phyre::PPostProcessing::PMotionBlurD3D11::`vftable';
    a1[851] = 0;
  }
  return 1;
}

