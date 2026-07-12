// Function: sub_AE2A50
// Address: 0xae2a50
// Size: 0xb5
// Prototype: 

int sub_AE2A50()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9AF80, (int)Registry, (int)"PLight", 52, 4, (int)GlobalTypeAccessor, 0);
  unk_C9B010 |= 2u;
  dword_C9AF80[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PLight>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9AF80, (int)&unk_C9B410);
  Phyre_PObject_SetField68(dword_C9AF80, (int)&unk_C9B450);
  Phyre_PObject_SetField6C(dword_C9AF80, (int)&unk_C9B490);
  unk_C9B010 &= ~2u;
  dword_C9AF80[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PLight>::`vftable';
  return atexit(sub_AFCDE0);
}

