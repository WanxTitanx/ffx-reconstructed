// Function: sub_A024F0
// Address: 0xa024f0
// Size: 0x27

_DWORD *__thiscall sub_A024F0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionBase>::`vftable'; /*0xa024f6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa024fc*/
  if ( (a2 & 1) != 0 ) /*0xa02505*/
    Phyre_Memory_AlignedFree((int)this); /*0xa02508*/
  return this; /*0xa02512*/
}