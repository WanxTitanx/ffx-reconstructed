// Function: sub_A2C020
// Address: 0xa2c020
// Size: 0x32a

_DWORD *sub_A2C020()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  int v5; // eax

  Phyre_TypeRegistry_Register(Size_13); /*0xa2c047*/
  v0 = dword_1A84F94; /*0xa2c04c*/
  if ( (dword_1A84F94 & 1) == 0 ) /*0xa2c056*/
  {
    dword_1A84F94 |= 1u; /*0xa2c05b*/
    Singleton = Phyre_PTypeDefault_Uint32_GetSingleton(); /*0xa2c072*/
    Phyre_PClassDataMember_Init(dword_1A84F68, (size_t)Size_13, (int)Singleton, "m_fontSize", 4, 16, 0); /*0xa2c082*/
    atexit(sub_B09170); /*0xa2c08c*/
    v0 = dword_1A84F94; /*0xa2c091*/
  }
  if ( (v0 & 2) == 0 ) /*0xa2c0a2*/
  {
    dword_1A84F94 = v0 | 2; /*0xa2c0a7*/
    v2 = Phyre_PTypeDefault_Bool_GetSingleton(); /*0xa2c0be*/
    Phyre_PClassDataMember_Init(dword_1A84F98, (size_t)Size_13, (int)v2, "m_isSDF", 0, 16, 0); /*0xa2c0ce*/
    atexit(sub_B09190); /*0xa2c0d8*/
    v0 = dword_1A84F94; /*0xa2c0dd*/
  }
  if ( (v0 & 4) == 0 ) /*0xa2c0ee*/
  {
    dword_1A84F94 = v0 | 4; /*0xa2c0f3... [3652 chars total]