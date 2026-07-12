// Function: sub_A02520
// Address: 0xa02520
// Size: 0x27

_DWORD *__thiscall sub_A02520(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionD3D11>::`vftable'; /*0xa02526*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0252c*/
  if ( (a2 & 1) != 0 ) /*0xa02535*/
    Phyre_Memory_AlignedFree((int)this); /*0xa02538*/
  return this; /*0xa02542*/
}