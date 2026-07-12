// Function: sub_600D60
// Address: 0x600d60
// Size: 0x3d

int __stdcall sub_600D60(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600d66*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBEFC8); /*0x600d78*/
  sub_94AC00(a1, 1); /*0x600d89*/
  return LuaStack_PushSlot(a1); /*0x600d80*/
}
