// Function: sub_AE6D00
// Address: 0xae6d00
// Size: 0xb4
// Prototype: 

int sub_AE6D00()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CA7190,
    (int)Registry,
    (int)"PMeshInstanceSegmentContext",
    36,
    4,
    (int)dword_CA4E28,
    0);
  unk_CA7220 |= 2u;
  dword_CA7190[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PMeshInstanceSegmentContext>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA7190, (int)&unk_CA7C50);
  Phyre_PObject_SetField68(dword_CA7190, (int)&unk_CA7C80);
  Phyre_PObject_SetField6C(dword_CA7190, (int)&unk_CA7CB0);
  unk_CA7220 &= ~2u;
  dword_CA7190[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PMeshInstanceSegmentContext>::`vftable';
  return atexit(sub_AFF2F0);
}

