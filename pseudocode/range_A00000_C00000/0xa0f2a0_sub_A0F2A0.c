// Function: sub_A0F2A0
// Address: 0xa0f2a0
// Size: 0x5d

char __stdcall sub_A0F2A0(_DWORD *a1)
{
  if ( a1 ) /*0xa0f2d3*/
  {
    sub_9FC160(); /*0xa0f2d7*/
    *a1 = &Phyre::PPostProcessing::PFXAA::`vftable'; /*0xa0f2dc*/
    a1[1] = dword_19445A8; /*0xa0f2e2*/
  }
  return 1; /*0xa0f2eb*/
}