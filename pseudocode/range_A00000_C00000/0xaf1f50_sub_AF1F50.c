// Function: sub_AF1F50
// Address: 0xaf1f50
// Size: 0xb4
// Prototype: 

int sub_AF1F50()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1940D30,
    (int)Registry,
    (int)"PInputSourceMouseButton",
    32,
    4,
    (int)dword_1940AD0,
    0);
  unk_1940DC0 |= 2u;
  dword_1940D30[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceMouseButton>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940D30, (int)&unk_1942160);
  Phyre_PObject_SetField68(dword_1940D30, (int)&unk_1942180);
  Phyre_PObject_SetField6C(dword_1940D30, (int)&unk_19421A0);
  unk_1940DC0 &= ~2u;
  dword_1940D30[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceMouseButton>::`vftable';
  return atexit(sub_B07FE0);
}

