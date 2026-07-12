// Function: sub_AE60B0
// Address: 0xae60b0
// Size: 0xb5
// Prototype: 

int sub_AE60B0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA5530, (int)Registry, (int)"PSceneRenderPass", 40, 4, (int)GlobalTypeAccessor, 0);
  unk_CA55C0 |= 2u;
  dword_CA5530[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PSceneRenderPass>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA5530, (int)&unk_CA5EC0);
  Phyre_PObject_SetField68(dword_CA5530, (int)&unk_CA5EF0);
  Phyre_PObject_SetField6C(dword_CA5530, (int)&unk_CA5F20);
  unk_CA55C0 &= ~2u;
  dword_CA5530[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PSceneRenderPass>::`vftable';
  return atexit(sub_AFEA10);
}

