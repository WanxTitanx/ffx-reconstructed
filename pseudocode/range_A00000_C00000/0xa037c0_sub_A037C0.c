// Function: sub_A037C0
// Address: 0xa037c0
// Size: 0x12c

_DWORD *sub_A037C0()
{
  int v0; // eax
  _DWORD *Singleton; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // eax

  Phyre_TypeRegistry_Register(Size_6); /*0xa037e7*/
  v0 = dword_1944C88; /*0xa037ec*/
  if ( (dword_1944C88 & 1) == 0 ) /*0xa037f6*/
  {
    dword_1944C88 |= 1u; /*0xa037fb*/
    Singleton = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa03812*/
    Phyre_PClassDataMember_Init(dword_1944C5C, (size_t)Size_6, (int)Singleton, "m_focusPlaneDistance", 20, 0, 0); /*0xa03822*/
    atexit(sub_B08F20); /*0xa0382c*/
    v0 = dword_1944C88; /*0xa03831*/
  }
  if ( (v0 & 2) == 0 ) /*0xa03842*/
  {
    dword_1944C88 = v0 | 2; /*0xa03847*/
    v2 = Phyre_PTypeDefault_Float_GetSingleton(); /*0xa0385e*/
    Phyre_PClassDataMember_Init(dword_1944C8C, (size_t)Size_6, (int)v2, "m_focusRange", 24, 0, 0); /*0xa0386e*/
    atexit(sub_B08F30); /*0xa03878*/
    v0 = dword_1944C88; /*0xa0387d*/
  }
  if ( (v0 & 4) == 0 ) /*0xa0388e*/
  {
    dword_1944C88 = v0 | 4; /*0xa03893*/
    v3 = Phyre_PTypeDef... [1279 chars total]