// Function: sub_AE5E70
// Address: 0xae5e70
// Size: 0xbe
// Prototype: 

int sub_AE5E70()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA5268, (int)Registry, (int)"PMaterial", 24, 4, (int)GlobalTypeAccessor, 0);
  unk_CA52F8 |= 2u;
  dword_CA5268[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMaterial>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA5268, (int)&unk_CA54A0);
  Phyre_PObject_SetField68(dword_CA5268, (int)&unk_CA54C0);
  Phyre_PObject_SetField6C(dword_CA5268, (int)&unk_CA54E0);
  dword_CA5268[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PMaterial>::`vftable';
  unk_CA52F8 = unk_CA52F8 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFE930);
}

