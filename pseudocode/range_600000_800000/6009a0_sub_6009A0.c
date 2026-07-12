// Function: sub_6009A0
// Address: 0x6009a0
// Size: 0x3a

int __stdcall sub_6009A0(int a1, int *a2)
{
  if ( *a2 ) /*0x6009a6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBEA70); /*0x6009b5*/
  sub_94AC00(a1, 1); /*0x6009c6*/
  return LuaStack_PushSlot(a1); /*0x6009bd*/
}
