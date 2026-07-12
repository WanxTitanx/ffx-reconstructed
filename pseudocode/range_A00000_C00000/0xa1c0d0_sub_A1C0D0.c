// Function: sub_A1C0D0
// Address: 0xa1c0d0
// Size: 0x3d

int __stdcall sub_A1C0D0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c0d6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943FB8); /*0xa1c0e8*/
  sub_94AC00(a1, 1); /*0xa1c0f9*/
  return LuaStack_PushSlot(a1); /*0xa1c0f0*/
}