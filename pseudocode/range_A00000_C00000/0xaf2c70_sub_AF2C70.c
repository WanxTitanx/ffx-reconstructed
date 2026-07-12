// Function: sub_AF2C70
// Address: 0xaf2c70
// Size: 0xb7
// Prototype: 

int sub_AF2C70()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_1943718, (int)Registry, (int)"PDeferredLighting", 16448, 4, (int)dword_19437B0, 0);
  unk_19437A8 |= 2u;
  dword_1943718[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPostProcessing::PDeferredLighting>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_1943718, (int)&unk_195D140);
  Phyre_PObject_SetField68(dword_1943718, (int)&unk_1961180);
  Phyre_PObject_SetField6C(dword_1943718, (int)&unk_19651C0);
  unk_19437A8 &= ~2u;
  dword_1943718[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPostProcessing::PDeferredLighting>::`vftable';
  return atexit(sub_B086B0);
}

