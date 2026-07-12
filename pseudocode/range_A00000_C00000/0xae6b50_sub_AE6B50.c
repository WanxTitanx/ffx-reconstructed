// Function: sub_AE6B50
// Address: 0xae6b50
// Size: 0xbe
// Prototype: 

int sub_AE6B50()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA5FF0, (int)Registry, (int)"PEffectVariant", 52, 4, (int)GlobalTypeAccessor, 0);
  unk_CA6080 |= 2u;
  dword_CA5FF0[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PEffectVariant>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA5FF0, (int)&unk_CA65A0);
  Phyre_PObject_SetField68(dword_CA5FF0, (int)&unk_CA65E0);
  Phyre_PObject_SetField6C(dword_CA5FF0, (int)&unk_CA6620);
  dword_CA5FF0[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PEffectVariant>::`vftable';
  unk_CA6080 = unk_CA6080 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFEED0);
}

