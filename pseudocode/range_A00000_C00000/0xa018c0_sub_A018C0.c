// Function: sub_A018C0
// Address: 0xa018c0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A018C0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusionD3D11>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

