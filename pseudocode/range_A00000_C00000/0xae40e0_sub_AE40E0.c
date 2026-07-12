// Function: sub_AE40E0
// Address: 0xae40e0
// Size: 0xbe
// Prototype: 

int sub_AE40E0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_C9C618, (int)Registry, (int)"PShaderSource", 20, 4, (int)GlobalTypeAccessor, 0);
  unk_C9C6A8 |= 2u;
  dword_C9C618[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderSource>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9C618, (int)&unk_C9D6E0);
  Phyre_PObject_SetField68(dword_C9C618, (int)&unk_C9D700);
  Phyre_PObject_SetField6C(dword_C9C618, (int)&unk_C9D720);
  dword_C9C618[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderSource>::`vftable';
  unk_C9C6A8 = unk_C9C6A8 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD660);
}

