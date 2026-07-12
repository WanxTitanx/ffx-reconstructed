// Function: sub_AF3E70
// Address: 0xaf3e70
// Size: 0xb5
// Prototype: 

int sub_AF3E70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_19435E8, (int)Registry, (int)"PPostEffectBase", 20, 4, (int)GlobalTypeAccessor, 4);
  unk_1943678 |= 2u;
  dword_19435E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PPostEffectBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_19435E8, (int)&unk_1945140);
  Phyre_PObject_SetField68(dword_19435E8, (int)&unk_1945160);
  Phyre_PObject_SetField6C(dword_19435E8, (int)&unk_1945180);
  unk_1943678 &= ~2u;
  dword_19435E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PPostEffectBase>::`vftable';
  return atexit(sub_B089B0);
}

