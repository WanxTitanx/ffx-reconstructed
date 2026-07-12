// Function: sub_A333E0
// Address: 0xa333e0
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A333E0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

