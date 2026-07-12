// Function: sub_A2BE00
// Address: 0xa2be00
// Size: 0x27
// Prototype: 

_DWORD *__thiscall sub_A2BE00(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PText::PBitmapFontCharInfo>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)this);
  if ( (a2 & 1) != 0 )
    Phyre_Memory_AlignedFree((int)this);
  return this;
}

