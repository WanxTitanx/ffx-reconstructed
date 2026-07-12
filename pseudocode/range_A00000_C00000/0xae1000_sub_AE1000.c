// Function: sub_AE1000
// Address: 0xae1000
// Size: 0xb5
// Prototype: 

int sub_AE1000()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    &p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6,
    (int)Registry,
    (int)"PWorldMatrix",
    48,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C92120 |= 2u;
  p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6 = &Phyre::PClassDescriptorAbstract<Phyre::PWorldMatrix>::`vftable';
  Phyre_PObject_SetInstanceOffset(&p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6, (int)&unk_C92230);
  Phyre_PObject_SetField68(&p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6, (int)&unk_C92260);
  Phyre_PObject_SetField6C(&p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6, (int)&unk_C92290);
  unk_C92120 &= ~2u;
  p____7__PClassDescriptorAbstract_VPWorldMatrix_Phyre___Phyre__6 = &Phyre::PClassDescriptorConcrete<Phyre::PWorldMatrix>::`vftable';
  return atexit(sub_AFA8D0);
}

