// Function: sub_A041C0
// Address: 0xa041c0
// Size: 0xe0

_DWORD *sub_A041C0()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax

  Phyre_TypeRegistry_Register(Size_11); /*0xa041e7*/
  v0 = dword_1944ED8; /*0xa041ec*/
  if ( (dword_1944ED8 & 1) == 0 ) /*0xa041f6*/
  {
    dword_1944ED8 |= 1u; /*0xa041fb*/
    Singleton = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa04212*/
    Phyre_PClassDataMember_Init(dword_1944EAC, (size_t)Size_11, (int)Singleton, "m_minReflectionDirZ", 20, 0, 0); /*0xa04222*/
    atexit(sub_B08FE0); /*0xa0422c*/
    v0 = dword_1944ED8; /*0xa04231*/
  }
  if ( (v0 & 2) == 0 ) /*0xa04242*/
  {
    dword_1944ED8 = v0 | 2; /*0xa04247*/
    v2 = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa0425e*/
    Phyre_PClassDataMember_Init(dword_1944EDC, (size_t)Size_11, (int)v2, "m_marchStepFactor", 24, 0, 0); /*0xa0426e*/
    atexit(sub_B08FD0); /*0xa04278*/
  }
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_11); /*0xa0429c*/
}