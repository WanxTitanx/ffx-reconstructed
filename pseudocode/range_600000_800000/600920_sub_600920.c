// Function: sub_600920
// Address: 0x600920
// Size: 0x3d

int __stdcall sub_600920(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600926*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF948); /*0x600938*/
  sub_94AC00(a1, 1); /*0x600949*/
  return LuaStack_PushSlot(a1); /*0x600940*/
}
