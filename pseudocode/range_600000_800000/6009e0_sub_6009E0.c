// Function: sub_6009E0
// Address: 0x6009e0
// Size: 0x3a

int __stdcall sub_6009E0(int a1, int *a2)
{
  if ( *a2 ) /*0x6009e6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBE9D8); /*0x6009f5*/
  sub_94AC00(a1, 1); /*0x600a06*/
  return LuaStack_PushSlot(a1); /*0x6009fd*/
}
