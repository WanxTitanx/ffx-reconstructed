// Function: sub_600AA0
// Address: 0x600aa0
// Size: 0x3d

int __stdcall sub_600AA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600aa6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBEB08); /*0x600ab8*/
  sub_94AC00(a1, 1); /*0x600ac9*/
  return LuaStack_PushSlot(a1); /*0x600ac0*/
}
