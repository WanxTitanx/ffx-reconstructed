// Function: sub_AE6C10
// Address: 0xae6c10
// Size: 0xb5
// Prototype: 

int sub_AE6C10()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CA66E8, (int)Registry, (int)"PEffect", 64, 4, (int)GlobalTypeAccessor, 0);
  unk_CA6778 |= 2u;
  dword_CA66E8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PEffect>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CA66E8, (int)&unk_CA6F30);
  Phyre_PObject_SetField68(dword_CA66E8, (int)&unk_CA6F70);
  Phyre_PObject_SetField6C(dword_CA66E8, (int)&unk_CA6FB0);
  unk_CA6778 &= ~2u;
  dword_CA66E8[0] = &Phyre::PClassDescriptorConcrete<Phyre::PRendering::PEffect>::`vftable';
  return atexit(sub_AFF070);
}

