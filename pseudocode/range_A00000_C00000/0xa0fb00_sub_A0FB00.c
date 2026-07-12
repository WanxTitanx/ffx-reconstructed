// Function: sub_A0FB00
// Address: 0xa0fb00
// Size: 0x5d
// Prototype: 

char __stdcall sub_A0FB00(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FD080();
    *a1 = &Phyre::PPostProcessing::PScreenSpaceReflection::`vftable';
    a1[1] = dword_1944770;
  }
  return 1;
}

