// Function: sub_A02340
// Address: 0xa02340
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A02340(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMLAABase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

