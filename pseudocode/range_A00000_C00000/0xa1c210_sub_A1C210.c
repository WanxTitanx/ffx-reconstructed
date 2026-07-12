// Function: sub_A1C210
// Address: 0xa1c210
// Size: 0x3a

int __stdcall sub_A1C210(int a1, int *a2)
{
  if ( *a2 ) /*0xa1c216*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)Size_10); /*0xa1c225*/
  sub_94AC00(a1, 1); /*0xa1c236*/
  return LuaStack_PushSlot(a1); /*0xa1c22d*/
}