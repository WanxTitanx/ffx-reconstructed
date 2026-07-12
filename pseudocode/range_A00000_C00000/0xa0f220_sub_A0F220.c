// Function: sub_A0F220
// Address: 0xa0f220
// Size: 0x7e
// Prototype: 

char __stdcall sub_A0F220(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FBD90();
    *a1 = &Phyre::PPostProcessing::PDepthOfFieldD3D11::`vftable';
    a1[1004] = 0;
    a1[1005] = 0;
    a1[1006] = 0;
    a1[1007] = 0;
  }
  return 1;
}

