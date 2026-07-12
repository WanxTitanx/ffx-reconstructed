// Function: sub_AEE880
// Address: 0xaee880
// Size: 0xbe
// Prototype: 

int sub_AEE880()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(Size_4, (int)Registry, (int)"PApplicationViewport", 40, 4, (int)GlobalTypeAccessor, 4);
  unk_CC9E48 |= 2u;
  Size_4[0] = &Phyre::PClassDescriptorAbstract<Phyre::PFramework::PApplicationViewport>::`vftable';
  Phyre_PObject_SetInstanceOffset(Size_4, (int)&unk_CCB070);
  Phyre_PObject_SetField68(Size_4, (int)&unk_CCB0A0);
  Phyre_PObject_SetField6C(Size_4, (int)&unk_CCB0D0);
  Size_4[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PFramework::PApplicationViewport>::`vftable';
  unk_CC9E48 = unk_CC9E48 & 0xFFFFFFF5 | 8;
  return atexit(sub_B060F0);
}

