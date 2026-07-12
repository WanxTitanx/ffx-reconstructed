// Function: sub_600EA0
// Address: 0x600ea0
// Size: 0x3d

int __stdcall sub_600EA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600ea6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF358); /*0x600eb8*/
  sub_94AC00(a1, 1); /*0x600ec9*/
  return LuaStack_PushSlot(a1); /*0x600ec0*/
}
