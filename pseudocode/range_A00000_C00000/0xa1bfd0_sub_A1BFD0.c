// Function: sub_A1BFD0
// Address: 0xa1bfd0
// Size: 0x3a

int __stdcall sub_A1BFD0(int a1, int *a2)
{
  if ( *a2 ) /*0xa1bfd6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)dword_1944348); /*0xa1bfe5*/
  sub_94AC00(a1, 1); /*0xa1bff6*/
  return LuaStack_PushSlot(a1); /*0xa1bfed*/
}