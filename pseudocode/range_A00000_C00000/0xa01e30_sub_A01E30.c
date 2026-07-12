// Function: sub_A01E30
// Address: 0xa01e30
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A01E30(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PPostEffectBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

