// Function: sub_600E20
// Address: 0x600e20
// Size: 0x3a

int __stdcall sub_600E20(int a1, int *a2)
{
  if ( *a2 ) /*0x600e26*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBF0F8); /*0x600e35*/
  sub_94AC00(a1, 1); /*0x600e46*/
  return LuaStack_PushSlot(a1); /*0x600e3d*/
}
