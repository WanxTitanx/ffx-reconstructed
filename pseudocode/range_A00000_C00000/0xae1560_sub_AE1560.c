// Function: sub_AE1560
// Address: 0xae1560
// Size: 0xb5
// Prototype: 

int sub_AE1560()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C94030,
    (int)Registry,
    (int)"PAssetReferenceImport",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C940C0 |= 2u;
  dword_C94030[0] = &Phyre::PClassDescriptorAbstract<Phyre::PAssetReferenceImport>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C94030, (int)&unk_C94300);
  Phyre_PObject_SetField68(dword_C94030, (int)&unk_C94310);
  Phyre_PObject_SetField6C(dword_C94030, (int)&unk_C94320);
  unk_C940C0 &= ~2u;
  dword_C94030[0] = &Phyre::PClassDescriptorConcrete<Phyre::PAssetReferenceImport>::`vftable';
  return atexit(sub_AFAF40);
}

