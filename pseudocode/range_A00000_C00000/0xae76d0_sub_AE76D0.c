// Function: sub_AE76D0
// Address: 0xae76d0
// Size: 0xb5
// Prototype: 

int sub_AE76D0()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA91F8, (int)Registry, (int)"PNode", 84, 4, (int)GlobalTypeAccessor, 4);
  unk_CA9288 |= 2u;
  dword_CA91F8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PScene::PNode>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA91F8, (int)&unk_CA95E0);
  Phyre_PObject_SetField68(dword_CA91F8, (int)&unk_CA9640);
  Phyre_PObject_SetField6C(dword_CA91F8, (int)&unk_CA96A0);
  unk_CA9288 &= ~2u;
  dword_CA91F8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PScene::PNode>::`vftable';
  return atexit(sub_AFFB80);
}

