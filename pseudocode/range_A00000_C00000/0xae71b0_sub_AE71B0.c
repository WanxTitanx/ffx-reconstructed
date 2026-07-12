// Function: sub_AE71B0
// Address: 0xae71b0
// Size: 0xb5
// Prototype: 

int sub_AE71B0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA89B8,
    (int)Registry,
    (int)"PMeshInstanceBounds",
    36,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CA8A48 |= 2u;
  dword_CA89B8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshInstanceBounds>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA89B8, (int)&unk_CA8B50);
  Phyre_PObject_SetField68(dword_CA89B8, (int)&unk_CA8B80);
  Phyre_PObject_SetField6C(dword_CA89B8, (int)&unk_CA8BB0);
  unk_CA8A48 &= ~2u;
  dword_CA89B8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PMeshInstanceBounds>::`vftable';
  return atexit(sub_AFF970);
}

