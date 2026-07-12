// Function: sub_A03DC0
// Address: 0xa03dc0
// Size: 0x375

_DWORD *sub_A03DC0()
{
  int v0; // eax
  int v1; // esi
  _DWORD *v2; // eax
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // esi
  _DWORD *v6; // eax
  int v7; // esi
  _DWORD *v8; // eax
  int v10; // [esp-4h] [ebp-18h]

  Phyre_TypeRegistry_Register(Size_10); /*0xa03de8*/
  sub_A074C0(off_C684A4[0], v10); // "PArray<PPostEffectBase *>" /*0xa03df3*/
  v0 = dword_1944F6C; /*0xa03df8*/
  if ( (dword_1944F6C & 1) == 0 ) /*0xa03e02*/
  {
    dword_1944F6C |= 1u; /*0xa03e0b*/
    if ( (dword_19450A4 & 1) == 0 ) /*0xa03e1e*/
    {
      dword_19450A4 |= 1u; /*0xa03e23*/
      sub_9F96D0(); /*0xa03e31*/
      unk_19450A0 &= ~2u; /*0xa03e36*/
      dword_1945010[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable'; /*0xa03e42*/
      atexit(sub_B08DA0); /*0xa03e4c*/
    }
    sub_576060((size_t)Size_10, (int)dword_1945010, "m_postEffects", 0, 0, 3, 4); /*0xa03e74*/
    p____7__PClassDataMemberPhyreArray_PAVPPostEffectBase_PPostProc =... [5949 chars total]