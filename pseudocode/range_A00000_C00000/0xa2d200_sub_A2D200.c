// Function: sub_A2D200
// Address: 0xa2d200
// Size: 0xb4
// Prototype: 

int __cdecl sub_A2D200(int a1, int a2)
{
  if ( (dword_1A85144 & 1) == 0 )
  {
    dword_1A85144 |= 1u;
    sub_A2B780(dword_1A850B0);
    unk_1A85140 &= ~2u;
    dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable';
    atexit(sub_B090E0);
  }
  if ( a2 )
    return PhyreLua_PushPhyreObject(a1, a2, (int)dword_1A850B0);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

