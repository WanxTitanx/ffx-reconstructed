// Function: sub_600D20
// Address: 0x600d20
// Size: 0x3d

int __stdcall sub_600D20(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600d26*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF060); /*0x600d38*/
  sub_94AC00(a1, 1); /*0x600d49*/
  return LuaStack_PushSlot(a1); /*0x600d40*/
}
