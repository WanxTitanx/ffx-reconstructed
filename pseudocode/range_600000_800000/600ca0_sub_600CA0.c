// Function: sub_600CA0
// Address: 0x600ca0
// Size: 0x3d

int __stdcall sub_600CA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600ca6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBFA78); /*0x600cb8*/
  sub_94AC00(a1, 1); /*0x600cc9*/
  return LuaStack_PushSlot(a1); /*0x600cc0*/
}
