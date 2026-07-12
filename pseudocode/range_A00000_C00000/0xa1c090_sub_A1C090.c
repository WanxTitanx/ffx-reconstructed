// Function: sub_A1C090
// Address: 0xa1c090
// Size: 0x3d

int __stdcall sub_A1C090(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c096*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943F20); /*0xa1c0a8*/
  sub_94AC00(a1, 1); /*0xa1c0b9*/
  return LuaStack_PushSlot(a1); /*0xa1c0b0*/
}