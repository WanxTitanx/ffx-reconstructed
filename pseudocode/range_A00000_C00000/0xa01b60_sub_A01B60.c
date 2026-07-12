// Function: sub_A01B60
// Address: 0xa01b60
// Size: 0x27

_DWORD *__thiscall sub_A01B60(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PGlow>::`vftable'; /*0xa01b66*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa01b6c*/
  if ( (a2 & 1) != 0 ) /*0xa01b75*/
    Phyre_Memory_AlignedFree((int)this); /*0xa01b78*/
  return this; /*0xa01b82*/
}