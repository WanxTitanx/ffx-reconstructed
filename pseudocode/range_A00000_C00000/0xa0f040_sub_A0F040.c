// Function: sub_A0F040
// Address: 0xa0f040
// Size: 0x5d
// Prototype: 

char __stdcall sub_A0F040(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FBB30(a1);
    *a1 = &Phyre::PPostProcessing::PDeferredLighting::`vftable';
    a1[1] = dword_1943718;
  }
  return 1;
}

