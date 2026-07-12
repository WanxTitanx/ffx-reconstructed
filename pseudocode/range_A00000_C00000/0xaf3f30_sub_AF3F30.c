// Function: sub_AF3F30
// Address: 0xaf3f30
// Size: 0xb5
// Prototype: 

int sub_AF3F30()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_19448A0,
    (int)Registry,
    (int)"PPostEffectManager",
    16,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_1944930 |= 2u;
  dword_19448A0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PPostEffectManager>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19448A0, (int)&unk_1984BF0);
  Phyre_PObject_SetField68(dword_19448A0, (int)&unk_1984C00);
  Phyre_PObject_SetField6C(dword_19448A0, (int)&unk_1984C10);
  unk_1944930 &= ~2u;
  dword_19448A0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PPostEffectManager>::`vftable';
  return atexit(sub_B089D0);
}

