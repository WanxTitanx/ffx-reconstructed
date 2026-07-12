// Function: sub_A024C0
// Address: 0xa024c0
// Size: 0x27

_DWORD *__thiscall sub_A024C0(_DWORD *this, char a2)
{
  *this = &Phyre::PClassDescriptorForType<Phyre::PPostProcessing::PScreenSpaceAmbientOcclusion>::`vftable'; /*0xa024c6*/
  Phyre_PClassDescriptor_Dtor((int)this); /*0xa024cc*/
  if ( (a2 & 1) != 0 ) /*0xa024d5*/
    Phyre_Memory_AlignedFree((int)this); /*0xa024d8*/
  return this; /*0xa024e2*/
}