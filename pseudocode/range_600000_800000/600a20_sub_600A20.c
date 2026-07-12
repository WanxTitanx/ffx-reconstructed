// Function: sub_600A20
// Address: 0x600a20
// Size: 0x3a

int __stdcall sub_600A20(int a1, int *a2)
{
  if ( *a2 ) /*0x600a26*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBFE08); /*0x600a35*/
  sub_94AC00(a1, 1); /*0x600a46*/
  return LuaStack_PushSlot(a1); /*0x600a3d*/
}
