// Function: sub_A025B0
// Address: 0xa025b0
// Size: 0x27

_DWORD *__thiscall sub_A025B0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceReflectionD3D11>::`vftable'; /*0xa025b6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa025bc*/
  if ( (a2 & 1) != 0 ) /*0xa025c5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa025c8*/
  return this; /*0xa025d2*/
}