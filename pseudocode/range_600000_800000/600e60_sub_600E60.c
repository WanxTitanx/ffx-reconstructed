// Function: sub_600E60
// Address: 0x600e60
// Size: 0x3a

int __stdcall sub_600E60(int a1, int *a2)
{
  if ( *a2 ) /*0x600e66*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBFC40); /*0x600e75*/
  sub_94AC00(a1, 1); /*0x600e86*/
  return LuaStack_PushSlot(a1); /*0x600e7d*/
}
