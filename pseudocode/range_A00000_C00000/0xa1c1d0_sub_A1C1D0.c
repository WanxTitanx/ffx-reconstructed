// Function: sub_A1C1D0
// Address: 0xa1c1d0
// Size: 0x3d

int __stdcall sub_A1C1D0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c1d6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)Size_9); /*0xa1c1e8*/
  sub_94AC00(a1, 1); /*0xa1c1f9*/
  return LuaStack_PushSlot(a1); /*0xa1c1f0*/
}