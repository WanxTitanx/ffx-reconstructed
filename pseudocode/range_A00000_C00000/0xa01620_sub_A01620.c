// Function: sub_A01620
// Address: 0xa01620
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A01620(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PLegacyGlowBase>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

