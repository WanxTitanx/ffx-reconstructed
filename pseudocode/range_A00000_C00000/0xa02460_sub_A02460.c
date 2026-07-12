// Function: sub_A02460
// Address: 0xa02460
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A02460(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PPostEffectBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

