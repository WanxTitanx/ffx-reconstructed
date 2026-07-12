// Function: sub_AF0F40
// Address: 0xaf0f40
// Size: 0xbd
// Prototype: 

int sub_AF0F40()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_CE82E8,
    (int)Registry,
    (int)"ShadowDynamicMeshInstance",
    12,
    4,
    (int)dword_CA7F28,
    0);
  unk_CE8378 |= 2u;
  dword_CE82E8[0] = &Phyre::PClassDescriptorAbstract<ShadowDynamicMeshInstance>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CE82E8, (int)&unk_CE8380);
  Phyre_PObject_SetField68(dword_CE82E8, (int)&unk_CE8390);
  Phyre_PObject_SetField6C(dword_CE82E8, (int)&unk_CE83A0);
  dword_CE82E8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<ShadowDynamicMeshInstance>::`vftable';
  unk_CE8378 = unk_CE8378 & 0xFFFFFFF5 | 8;
  return atexit(sub_B07AB0);
}

