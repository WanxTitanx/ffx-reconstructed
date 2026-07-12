// Function: sub_AE7270
// Address: 0xae7270
// Size: 0xbe
// Prototype: 

int sub_AE7270()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA8BD8,
    (int)Registry,
    (int)"PMeshInstanceAttachPoint",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA8C68 |= 2u;
  dword_CA8BD8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshInstanceAttachPoint>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA8BD8, (int)&unk_CA8D00);
  Phyre_PObject_SetField68(dword_CA8BD8, (int)&unk_CA8D10);
  Phyre_PObject_SetField6C(dword_CA8BD8, (int)&unk_CA8D20);
  dword_CA8BD8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PMeshInstanceAttachPoint>::`vftable';
  unk_CA8C68 = unk_CA8C68 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFF9E0);
}

