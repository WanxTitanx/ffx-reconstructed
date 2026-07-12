// Function: sub_A33540
// Address: 0xa33540
// Size: 0x13d
// Prototype: 

_DWORD *sub_A33540()
{
  Phyre_TypeRegistry_Register(Size_6);
  if ( (dword_1A85678 & 1) == 0 )
  {
    dword_1A85678 |= 1u;
    Phyre_PClassDataMember_Init(dword_1A8564C, (size_t)Size_6, (int)&unk_1941910, "m_inputMap", 8, 2, 0);
    atexit(sub_B0B8A0);
  }
  sub_A33680(off_C6D25C[0]);                    // "PArray<PInputMap *>"
  if ( (dword_1A85678 & 2) == 0 )
  {
    dword_1A85678 |= 2u;
    if ( (dword_1A85744 & 1) == 0 )
    {
      dword_1A85744 |= 1u;
      sub_A32EF0();
      unk_1A85740 &= ~2u;
      dword_1A856B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
      atexit(sub_B0B860);
    }
    sub_576060((size_t)Size_6, (int)dword_1A856B0, "m_inputMaps", 0, 0, 3, 4);
    p____7__PClassDataMemberPhyreArray_PAVPInputMap_PInputs_Phyre__ = &Phyre::PClassDataMemberPhyreArray<Phyre::PInputs::PInputMap *>::`vftable';
    atexit(sub_B0B8B0);
  }
  return Phyre_PClassDescriptor_RegisterWithNamespace((int)Size_6);
}

