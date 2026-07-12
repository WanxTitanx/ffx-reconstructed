// Function: sub_A2BE60
// Address: 0xa2be60
// Size: 0x27

_DWORD *__thiscall sub_A2BE60(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PText::PBitmapFontCharInfo>::`vftable'; /*0xa2be66*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2be6c*/
  if ( (a2 & 1) != 0 ) /*0xa2be75*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2be78*/
  return this; /*0xa2be82*/
}