// Function: sub_600C20
// Address: 0x600c20
// Size: 0x3d

int __stdcall sub_600C20(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600c26*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBEE98); /*0x600c38*/
  sub_94AC00(a1, 1); /*0x600c49*/
  return LuaStack_PushSlot(a1); /*0x600c40*/
}
