// Function: sub_600AE0
// Address: 0x600ae0
// Size: 0x3d

int __stdcall sub_600AE0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600ae6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF9E0); /*0x600af8*/
  sub_94AC00(a1, 1); /*0x600b09*/
  return LuaStack_PushSlot(a1); /*0x600b00*/
}
