// Function: sub_A03CE0
// Address: 0xa03ce0
// Size: 0xdf

_DWORD *sub_A03CE0()
{
  int v0; // eax
  _DWORD *Singleton; // eax

  Phyre_TypeRegistry_Register(Size_9); /*0xa03d07*/
  v0 = dword_1944A20; /*0xa03d0c*/
  if ( (dword_1944A20 & 1) == 0 ) /*0xa03d16*/
  {
    dword_1944A20 |= 1u; /*0xa03d1b*/
    Phyre_PClassDataMember_Init(dword_19449F4, (size_t)Size_9, (int)&unk_CA5268, "m_effectMaterial", 8, 2, 0); /*0xa03d41*/
    atexit(sub_B08EE0); /*0xa03d4b*/
    v0 = dword_1944A20; /*0xa03d50*/
  }
  if ( (v0 & 2) == 0 ) /*0xa03d61*/
  {
    dword_1944A20 = v0 | 2; /*0xa03d66*/
    Singleton = Phyre_PTypeDefault_Bool_GetSingleton(); /*0xa03d7d*/
    Phyre_PClassDataMember_Init(dword_1944A24, (size_t)Size_9, (int)Singleton, "m_enabled", 17, 0, 0); /*0xa03d8d*/
    atexit(sub_B08F00); /*0xa03d97*/
  }
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_9); /*0xa03dbb*/
}