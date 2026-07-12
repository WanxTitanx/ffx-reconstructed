// Function: sub_AF1590
// Address: 0xaf1590
// Size: 0xb4
// Prototype: 

int sub_AF1590()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1940C98, (int)Registry, (int)"PInputSourceJoypadAxis", 32, 4, (int)dword_1940AD0, 0);
  unk_1940D28 |= 2u;
  dword_1940C98[0] = &Phyre::PClassDescriptorAbstract<Phyre::PInputs::PInputSourceJoypadAxis>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1940C98, (int)&unk_1942100);
  Phyre_PObject_SetField68(dword_1940C98, (int)&unk_1942120);
  Phyre_PObject_SetField6C(dword_1940C98, (int)&unk_1942140);
  unk_1940D28 &= ~2u;
  dword_1940C98[0] = &Phyre::PClassDescriptorConcrete<Phyre::PInputs::PInputSourceJoypadAxis>::`vftable';
  return atexit(sub_B07E40);
}

