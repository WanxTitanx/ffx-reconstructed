// Function: sub_A01CB0
// Address: 0xa01cb0
// Size: 0x27

_DWORD *__thiscall sub_A01CB0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlowGPUBase>::`vftable'; /*0xa01cb6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01cbc*/
  if ( (a2 & 1) != 0 ) /*0xa01cc5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01cc8*/
  return this; /*0xa01cd2*/
}