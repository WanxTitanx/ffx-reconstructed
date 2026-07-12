// Function: sub_A01E60
// Address: 0xa01e60
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A01E60(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PPostEffectManager>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

