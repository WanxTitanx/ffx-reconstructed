// Function: sub_A2BF20
// Address: 0xa2bf20
// Size: 0x27

_DWORD *__thiscall sub_A2BF20(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PText::PBitmapFont>::`vftable'; /*0xa2bf26*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa2bf2c*/
  if ( (a2 & 1) != 0 ) /*0xa2bf35*/
    Phyre_Memory_AlignedFree((int)this); /*0xa2bf38*/
  return this; /*0xa2bf42*/
}