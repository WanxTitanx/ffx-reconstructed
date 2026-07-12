// Function: sub_A0F140
// Address: 0xa0f140
// Size: 0x85
// Prototype: 

char __stdcall sub_A0F140(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FBD90();
    a1[1004] = 0;
    a1[1005] = 0;
    a1[1006] = 0;
    a1[1007] = 0;
    *a1 = &Phyre::PPostProcessing::PDepthOfField::`vftable';
    a1[1] = dword_19438E0;
  }
  return 1;
}

