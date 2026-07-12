// Function: sub_A02490
// Address: 0xa02490
// Size: 0x27

_DWORD *__thiscall sub_A02490(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PPostEffectManager>::`vftable'; /*0xa02496*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0249c*/
  if ( (a2 & 1) != 0 ) /*0xa024a5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa024a8*/
  return this; /*0xa024b2*/
}