// Function: sub_A01350
// Address: 0xa01350
// Size: 0x27
// Prototype: _DWORD *__thiscall(_DWORD *this, char)

_DWORD *__thiscall sub_A01350(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable'; /*0xa01356*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0135c*/
  if ( (a2 & 1) != 0 ) /*0xa01365*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01368*/
  return this; /*0xa01372*/
}