// Function: sub_A01BF0
// Address: 0xa01bf0
// Size: 0x27

_DWORD *__thiscall sub_A01BF0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PGlowGPUBase>::`vftable'; /*0xa01bf6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01bfc*/
  if ( (a2 & 1) != 0 ) /*0xa01c05*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01c08*/
  return this; /*0xa01c12*/
}