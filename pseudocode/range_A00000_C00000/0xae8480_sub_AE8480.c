// Function: sub_AE8480
// Address: 0xae8480
// Size: 0xa4
// Prototype: 

int sub_AE8480()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CAB858,
    (int)Registry,
    (int)"PAnimationHierarchyNode",
    8,
    16,
    (int)GlobalTypeAccessor,
    4);
  unk_CAB8E8 |= 2u;
  dword_CAB858[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAnimation::PAnimationHierarchyNode>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CAB858, (int)&unk_CAB8F0);
  Phyre_PObject_SetField68(dword_CAB858, (int)&unk_CAB900);
  Phyre_PObject_SetField6C(dword_CAB858, (int)&unk_CAB910);
  return atexit(sub_B00B20);
}

