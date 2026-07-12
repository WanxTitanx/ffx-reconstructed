// Function: sub_A42700
// Address: 0xa42700
// Size: 0x3a

int __stdcall sub_A42700(int a1, int *a2)
{
  if ( *a2 ) /*0xa42706*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)Size_19); /*0xa42715*/
  sub_94AC00(a1, 1); /*0xa42726*/
  return LuaStack_PushSlot(a1); /*0xa4271d*/
}