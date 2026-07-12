// Function: sub_A33410
// Address: 0xa33410
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A33410(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PGame::PGameSettings>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

