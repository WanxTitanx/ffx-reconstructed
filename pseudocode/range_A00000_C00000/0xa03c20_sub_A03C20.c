// Function: sub_A03C20
// Address: 0xa03c20
// Size: 0x97

_DWORD *sub_A03C20()
{
  _DWORD *Singleton; // eax

  Phyre_TypeRegistry_Register(Size_8); /*0xa03c47*/
  if ( (dword_1944D80 & 1) == 0 ) /*0xa03c56*/
  {
    dword_1944D80 |= 1u; /*0xa03c5b*/
    Singleton = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa03c75*/
    Phyre_PClassDataMember_Init(dword_1944D54, (size_t)Size_8, (int)Singleton, "m_velocityScale", 3284, 0, 0); /*0xa03c85*/
    atexit(sub_B09000); /*0xa03c8f*/
  }
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_8); /*0xa03cb3*/
}