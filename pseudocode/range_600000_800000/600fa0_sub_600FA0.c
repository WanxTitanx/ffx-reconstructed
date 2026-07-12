// Function: sub_600FA0
// Address: 0x600fa0
// Size: 0x3d

int __stdcall sub_600FA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600fa6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF3F0); /*0x600fb8*/
  sub_94AC00(a1, 1); /*0x600fc9*/
  return LuaStack_PushSlot(a1); /*0x600fc0*/
}
