// Function: sub_A074C0
// Address: 0xa074c0
// Size: 0x206
// Prototype: 

_DWORD *__cdecl sub_A074C0(int a1)
{
  int v1; // eax
  int v2; // ecx
  _DWORD *Singleton; // eax
  _DWORD *v4; // eax

  v1 = dword_19450A4;
  if ( (dword_19450A4 & 1) == 0 )
  {
    dword_19450A4 |= 1u;
    sub_9F96D0();
    unk_19450A0 &= ~2u;
    Size_5[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
    atexit(sub_B08DA0);
    v1 = dword_19450A4;
  }
  if ( a1 && !unk_1945028 )
  {
    v2 = unk_1984C20;
    if ( !unk_1984C20 )
    {
      v2 = a1;
      unk_1984C20 = a1;
    }
    unk_1945028 = v2;
    if ( (v1 & 2) == 0 )
    {
      dword_19450A4 = v1 | 2;
      Singleton = Phyre_PTypeDefault_Uint32_GetSingleton();
      Phyre_PClassDataMember_Init(dword_19450A8, (size_t)Size_5, (int)Singleton, "m_count", 0, 0, 0);
      atexit(sub_B08ED0);
      v1 = dword_19450A4;
    }
    if ( (v1 & 4) == 0 )
    {
      dword_19450A4 = v1 | 4;
      v4 = Phyre_PTypeDefault_Uint32_GetSingleton();
      sub_5759B0(&unk_C907F4, v4, 0);
      p____7__PAnnotationWithValue_I_Phyre__6B_ = &Phyre::PAnnotationWithValue<unsigned int>::`vftable';
      n0x7FFFFFFF = 0x7FFFFFFF;
      atexit(sub_B08D90);
      v1 = dword_19450A4;
    }
    if ( (_DWORD *)dword_19450D8[0] == dword_19450D8 )
    {
      sub_575D80(&p____7__PAnnotationWithValue_I_Phyre__6B_);
      v1 = dword_19450A4;
    }
    if ( (v1 & 8) == 0 )
    {
      dword_19450A4 = v1 | 8;
      sub_576060((size_t)Size_5, (int)&unk_19435E8, "m_els", 4, 2, 2, 4);
      p____7__PClassDataMemberArrayDynamic_V__PArray_PAVPPostEffectBa = &Phyre::PClassDataMemberArrayDynamic<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
      psub_4321C0 = sub_4321C0;
      unk_1945128 = 0;
      psub_A23BE0 = sub_A23BE0;
      atexit(sub_B08EF0);
    }
    n4_5 = 4;
    Phyre_TypeRegistry_Register(Size_5);
    Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_5);
  }
  return Size_5;
}

