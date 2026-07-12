// Function: sub_A023A0
// Address: 0xa023a0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A023A0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMeshParticleSystemBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

