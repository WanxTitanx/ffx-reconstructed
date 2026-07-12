// Function: sub_A02130
// Address: 0xa02130
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A02130(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PFXAABase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

