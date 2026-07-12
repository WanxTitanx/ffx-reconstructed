// Function: sub_AE6DC0
// Address: 0xae6dc0
// Size: 0xb5
// Prototype: 

int sub_AE6DC0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA70F8,
    (int)Registry,
    (int)"PMeshInstanceSegmentStreamBinding",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA7188 |= 2u;
  dword_CA70F8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshInstanceSegmentStreamBinding>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA70F8, (int)&unk_CA7C20);
  Phyre_PObject_SetField68(dword_CA70F8, (int)&unk_CA7C30);
  Phyre_PObject_SetField6C(dword_CA70F8, (int)&unk_CA7C40);
  unk_CA7188 &= ~2u;
  dword_CA70F8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PMeshInstanceSegmentStreamBinding>::`vftable';
  return atexit(sub_AFF310);
}

