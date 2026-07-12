// Function: sub_A01380
// Address: 0xa01380
// Size: 0x27
// Prototype: _DWORD *__thiscall(_DWORD *this, char)

_DWORD *__thiscall sub_A01380(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PDeferredLighting>::`vftable'; /*0xa01386*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa0138c*/
  if ( (a2 & 1) != 0 ) /*0xa01395*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01398*/
  return this; /*0xa013a2*/
}