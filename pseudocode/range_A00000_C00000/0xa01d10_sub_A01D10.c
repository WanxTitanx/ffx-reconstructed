// Function: sub_A01D10
// Address: 0xa01d10
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A01D10(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PMLAABase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

