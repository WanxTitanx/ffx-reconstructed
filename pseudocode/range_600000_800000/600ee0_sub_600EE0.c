// Function: sub_600EE0
// Address: 0x600ee0
// Size: 0x3d

int __stdcall sub_600EE0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600ee6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF2C0); /*0x600ef8*/
  sub_94AC00(a1, 1); /*0x600f09*/
  return LuaStack_PushSlot(a1); /*0x600f00*/
}
