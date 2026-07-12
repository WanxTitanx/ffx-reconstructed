// Function: sub_AEBF40
// Address: 0xaebf40
// Size: 0xb5
// Prototype: 

int sub_AEBF40()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CBD390,
    (int)Registry,
    (int)"PMorphModifierWeightsUserDataObject",
    8,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_CBD420 |= 2u;
  dword_CBD390[0] = &Phyre::PClassDescriptorAbstract<Phyre::PDynamicGeometry::PMorphModifierWeightsUserDataObject>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBD390, (int)&unk_CBD8E0);
  Phyre_PObject_SetField68(dword_CBD390, (int)&unk_CBD8F0);
  Phyre_PObject_SetField6C(dword_CBD390, (int)&unk_CBD900);
  unk_CBD420 &= ~2u;
  dword_CBD390[0] = &Phyre::PClassDescriptorConcrete<Phyre::PDynamicGeometry::PMorphModifierWeightsUserDataObject>::`vftable';
  return atexit(sub_B047B0);
}

