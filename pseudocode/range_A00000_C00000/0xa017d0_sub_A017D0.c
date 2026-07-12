// Function: sub_A017D0
// Address: 0xa017d0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A017D0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMotionBlurD3D11>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

