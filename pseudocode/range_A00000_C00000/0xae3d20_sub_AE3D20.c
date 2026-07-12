// Function: sub_AE3D20
// Address: 0xae3d20
// Size: 0xbe
// Prototype: 

int sub_AE3D20()
{
  _DWORD *Registry; // eax
  void *GlobalTypeAccessor; // [esp-8h] [ebp-18h]

  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(
    dword_C9BDC8,
    (int)Registry,
    (int)"PShaderParameterCaptureBufferTextureBase",
    12,
    4,
    (int)GlobalTypeAccessor,
    0);
  unk_C9BE58 |= 2u;
  dword_C9BDC8[0] = &Phyre::PClassDescriptorAbstract<Phyre::PRendering::PShaderParameterCaptureBufferTextureBase>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_C9BDC8, (int)&unk_C9D380);
  Phyre_PObject_SetField68(dword_C9BDC8, (int)&unk_C9D390);
  Phyre_PObject_SetField6C(dword_C9BDC8, (int)&unk_C9D3A0);
  dword_C9BDC8[0] = &Phyre::PClassDescriptorWithoutDefaultConstructor<Phyre::PRendering::PShaderParameterCaptureBufferTextureBase>::`vftable';
  unk_C9BE58 = unk_C9BE58 & 0xFFFFFFF5 | 8;
  return atexit(sub_AFD5C0);
}

