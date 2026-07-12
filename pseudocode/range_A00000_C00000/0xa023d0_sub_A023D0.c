// Function: sub_A023D0
// Address: 0xa023d0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A023D0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMotionBlur>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

