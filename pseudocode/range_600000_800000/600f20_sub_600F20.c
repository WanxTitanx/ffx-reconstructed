// Function: sub_600F20
// Address: 0x600f20
// Size: 0x3d

int __stdcall sub_600F20(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600f26*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF818); /*0x600f38*/
  sub_94AC00(a1, 1); /*0x600f49*/
  return LuaStack_PushSlot(a1); /*0x600f40*/
}
