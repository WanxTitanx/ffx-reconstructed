// Function: sub_A03500
// Address: 0xa03500
// Size: 0x271

_DWORD *sub_A03500()
{
  int v0; // eax
  int v1; // eax
  _DWORD *Singleton; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // eax

  Phyre_TypeRegistry_Register(Size_5); /*0xa03527*/
  v0 = dword_1944A7C; /*0xa0352c*/
  if ( (dword_1944A7C & 1) == 0 ) /*0xa03536*/
  {
    dword_1944A7C |= 1u; /*0xa0353b*/
    v1 = sub_460120(); /*0xa03555*/
    Phyre_PClassDataMember_Init(dword_1944A50, (size_t)Size_5, v1, "m_ambientColor", 16016, 0, 0); /*0xa03565*/
    atexit(sub_B08EC0); /*0xa0356f*/
    v0 = dword_1944A7C; /*0xa03574*/
  }
  if ( (v0 & 2) == 0 ) /*0xa03585*/
  {
    dword_1944A7C = v0 | 2; /*0xa0358a*/
    Singleton = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa035a4*/
    Phyre_PClassDataMember_Init(dword_1944A80, (size_t)Size_5, (int)Singleton, "m_instantLightIntensity", 16072, 0, 0); /*0xa035b4*/
    atexit(sub_B08FB0); /*0xa035be*/
    v0 = dword_1944A7C; /*0xa035c3*/
  }
  if ( (v0 & 4) == 0 ) /*0xa035d4*/
  {
    dword... [2734 chars total]