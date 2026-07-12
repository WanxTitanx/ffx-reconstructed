// Function: sub_A015C0
// Address: 0xa015c0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A015C0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PGlowGPUBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

