// Function: sub_600BE0
// Address: 0x600be0
// Size: 0x3a

int __stdcall sub_600BE0(int a1, int *a2)
{
  if ( *a2 ) /*0x600be6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBED68); /*0x600bf5*/
  sub_94AC00(a1, 1); /*0x600c06*/
  return LuaStack_PushSlot(a1); /*0x600bfd*/
}
