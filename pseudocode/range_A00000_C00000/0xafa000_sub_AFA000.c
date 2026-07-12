// Function: sub_AFA000
// Address: 0xafa000
// Size: 0x14
// Prototype: void __cdecl()

void __cdecl sub_AFA000()
{
  MEMORY[0xC90610][0] = &Phyre::PClassDescriptorForType<Phyre::PClassMember>::`vftable';
  Phyre_PClassDescriptor_Dtor((int)MEMORY[0xC90610]);
}

