// Function: sub_A0F850
// Address: 0xa0f850
// Size: 0x67
// Prototype: 

char __stdcall sub_A0F850(_DWORD *a1)
{
  if ( a1 )
  {
    sub_9FCBB0();
    a1[851] = 0;
    *a1 = &Phyre::PPostProcessing::PMotionBlur::`vftable';
    a1[1] = dword_1943AA8;
  }
  return 1;
}

