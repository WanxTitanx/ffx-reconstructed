// Function: sub_A34020
// Address: 0xa34020
// Size: 0xb4
// Prototype: 

int __cdecl sub_A34020(int a1, int a2)
{
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    Size_7[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  if ( a2 )
    return PhyreLua_PushPhyreObject(a1, a2, (int)Size_7);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

