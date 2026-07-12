// Function: sub_AF1650
// Address: 0xaf1650
// Size: 0xb4
// Prototype: 

int sub_AF1650()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_1940C00,
    (int)Registry,
    (int)"PInputSourceJoypadButton",
    40,
    4,
    (int)dword_1940AD0,
    0);
  unk_1940C90 |= 2u;
  dword_1940C00[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceJoypadButton>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940C00, (int)&unk_1942070);
  Phyre_PObject_SetField68(dword_1940C00, (int)&unk_19420A0);
  Phyre_PObject_SetField6C(dword_1940C00, (int)&unk_19420D0);
  unk_1940C90 &= ~2u;
  dword_1940C00[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceJoypadButton>::`vftable';
  return atexit(sub_B07E60);
}

