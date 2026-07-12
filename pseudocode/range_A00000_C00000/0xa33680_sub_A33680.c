// Function: sub_A33680
// Address: 0xa33680
// Size: 0x206
// Prototype: _DWORD __cdecl(_DWORD)

_DWORD *__cdecl sub_A33680(int a1)
{
  int v1; // eax
  int v2; // ecx
  _DWORD *Singleton; // eax
  _DWORD *v4; // eax

  v1 = dword_1A85744;
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    Size_7[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
    v1 = dword_1A85744;
  }
  if ( a1 && !unk_1A856C8 )
  {
    v2 = unk_1A857FC;
    if ( !unk_1A857FC )
    {
      v2 = a1;
      unk_1A857FC = a1;
    }
    unk_1A856C8 = v2;
    if ( (v1 & 2) == 0 )
    {
      dword_1A85744 = v1 | 2;
      Singleton = Phyre_PTypeDefault_Uint32_GetSingleton();
      Phyre_PClassDataMember_Init(dword_1A85748, (size_t)Size_7, (int)Singleton, "m_count", 0, 0, 0);
      atexit(sub_B0B880);
      v1 = dword_1A85744;
    }
    if ( (v1 & 4) == 0 )
    {
      dword_1A85744 = v1 | 4;
      v4 = Phyre_PTypeDefault_Uint32_GetSingleton();
      sub_5759B0(&unk_C907F4, v4, 0);
      p____7__PAnnotationWithValue_I_Phyre__6B_ = &Phyre::PAnnotationWithValue<unsigned int>::`vftable';
      n0x7FFFFFFF = 0x7FFFFFFF;
      atexit(sub_B0B850);
      v1 = dword_1A85744;
    }
    if ( (_DWORD *)dword_1A85778[0] == dword_1A85778 )
    {
      sub_575D80(&p____7__PAnnotationWithValue_I_Phyre__6B_);
      v1 = dword_1A85744;
    }
    if ( (v1 & 8) == 0 )
    {
      dword_1A85744 = v1 | 8;
      sub_576060((size_t)Size_7, (int)&unk_1941910, "m_els", 4, 2, 2, 4);
      p____7__PClassDataMemberArrayDynamic_V__PArray_PAVPInputMap_PIn = &Phyre::PClassDataMemberArrayDynamic<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
      psub_4321C0 = sub_4321C0;
      unk_1A857C8 = 0;
      psub_A347B0 = sub_A347B0;
      atexit(sub_B0B890);
    }
    n4_5 = 4;
    Phyre_TypeRegistry_Register(Size_7);
    Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_7);
  }
  return Size_7;
}

