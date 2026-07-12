// Function: sub_A2C350
// Address: 0xa2c350
// Size: 0x310

_DWORD *sub_A2C350()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax

  Phyre_TypeRegistry_Register(Size_14); /*0xa2c377*/
  v0 = dword_1A84DE0; /*0xa2c37c*/
  if ( (dword_1A84DE0 & 1) == 0 ) /*0xa2c386*/
  {
    dword_1A84DE0 |= 1u; /*0xa2c38b*/
    Singleton = Phyre_PTypeDefault_Int32_GetSingleton(); /*0xa2c3a2*/
    Phyre_PClassDataMember_Init(dword_1A84DB4, (size_t)Size_14, (int)Singleton, "m_characterCode", 0, 16, 0); /*0xa2c3b2*/
    atexit(sub_B09130); /*0xa2c3bc*/
    v0 = dword_1A84DE0; /*0xa2c3c1*/
  }
  if ( (v0 & 2) == 0 ) /*0xa2c3d2*/
  {
    dword_1A84DE0 = v0 | 2; /*0xa2c3d7*/
    v2 = Phyre_PTypeDefault_Int32_GetSingleton(); /*0xa2c3ee*/
    Phyre_PClassDataMember_Init(dword_1A84DE4, (size_t)Size_14, (int)v2, "m_kernPairs", 4, 16, 0); /*0xa2c3fe*/
    atexit(sub_B091B0); /*0xa2c408*/
    v0 = dword_1A84DE0... [3433 chars total]