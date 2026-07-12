// Function: sub_A2C6C0
// Address: 0xa2c6c0
// Size: 0x206
// Prototype: _DWORD __cdecl(_DWORD)

_DWORD *__cdecl sub_A2C6C0(int a1)
{
  int v1; // eax
  int v2; // ecx
  _DWORD *Singleton; // eax
  _DWORD *v4; // eax

  v1 = dword_1A85144; /*0xa2c6e2*/
  if ( (dword_1A85144 & 1) == 0 ) /*0xa2c6e9*/
  {
    dword_1A85144 |= 1u; /*0xa2c6ee*/
    sub_A2B780(Size_15); /*0xa2c6ff*/
    unk_1A85140 &= ~2u; /*0xa2c704*/
    Size_15[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2c710*/
    atexit(sub_B090E0); /*0xa2c71a*/
    v1 = dword_1A85144; /*0xa2c71f*/
  }
  if ( a1 && !unk_1A850C8 ) /*0xa2c740*/
  {
    v2 = unk_1A852E4; /*0xa2c746*/
    if ( !unk_1A852E4 ) /*0xa2c74e*/
    {
      v2 = a1; /*0xa2c750*/
      unk_1A852E4 = a1; /*0xa2c752*/
    }
    unk_1A850C8 = v2; /*0xa2c758*/
    if ( (v1 & 2) == 0 ) /*0xa2c760*/
    {
      dword_1A85144 = v1 | 2; /*0xa2c765*/
      Singleton = Phyre_PTypeDefault_Uint32_GetSingleton(); /*0xa2c77c*/
      Phyre_PClassDataMember_Init(dword_1A85148, (size_t)Size_15, (int)Singleton, "m_c... [2489 chars total]