// Function: sub_AEE360
// Address: 0xaee360
// Size: 0xb7
// Prototype: 

int sub_AEE360()
{
  _DWORD *Registry; // eax

  Registry = Phyre_TypeSystem_GetRegistry();
  Phyre_PClassDescriptor_ctor(dword_CBF780, (int)Registry, (int)"PPhysicsWorld", 168, 4, (int)&unk_CBFCD8, 0);
  unk_CBF810 |= 2u;
  dword_CBF780[0] = &Phyre::PClassDescriptorAbstract<Phyre::PPhysics::PPhysicsWorld>::`vftable';
  Phyre_PObject_SetInstanceOffset(dword_CBF780, (int)&unk_CC9300);
  Phyre_PObject_SetField68(dword_CBF780, (int)&unk_CC93B0);
  Phyre_PObject_SetField6C(dword_CBF780, (int)&unk_CC9460);
  unk_CBF810 &= ~2u;
  dword_CBF780[0] = &Phyre::PClassDescriptorConcrete<Phyre::PPhysics::PPhysicsWorld>::`vftable';
  return atexit(sub_B05050);
}

