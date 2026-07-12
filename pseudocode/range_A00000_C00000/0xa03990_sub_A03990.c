// Function: sub_A03990
// Address: 0xa03990
// Size: 0x12c

_DWORD *sub_A03990()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax

  Phyre_TypeRegistry_Register(Size_7); /*0xa039b7*/
  v0 = dword_1944DF0; /*0xa039bc*/
  if ( (dword_1944DF0 & 1) == 0 ) /*0xa039c6*/
  {
    dword_1944DF0 |= 1u; /*0xa039cb*/
    Singleton = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa039e2*/
    Phyre_PClassDataMember_Init(dword_1944DC4, (size_t)Size_7, (int)Singleton, "m_glowAmountScale", 104, 0, 0); /*0xa039f2*/
    atexit(sub_B08F80); /*0xa039fc*/
    v0 = dword_1944DF0; /*0xa03a01*/
  }
  if ( (v0 & 2) == 0 ) /*0xa03a12*/
  {
    dword_1944DF0 = v0 | 2; /*0xa03a17*/
    v2 = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa03a2e*/
    Phyre_PClassDataMember_Init(dword_1944DF4, (size_t)Size_7, (int)v2, "m_glowLuminanceThreshold", 108, 0, 0); /*0xa03a3e*/
    atexit(sub_B08FA0); /*0xa03a48*/
    v0 = dword_1944DF0; /*0xa03a4d*/
  }
  if ( (v0 & 4) == 0 ) /*0xa03a5e*/
  {
    dword_1944DF0 = v0 | 4; /*0xa03a63*/
    v3 = Phy... [1295 chars total]