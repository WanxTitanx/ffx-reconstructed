// Function: sub_A01680
// Address: 0xa01680
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A01680(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlowGPUBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

