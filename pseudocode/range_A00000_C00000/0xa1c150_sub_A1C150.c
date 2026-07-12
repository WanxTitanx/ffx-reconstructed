// Function: sub_A1C150
// Address: 0xa1c150
// Size: 0x3d

int __stdcall sub_A1C150(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c156*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)Size_8); /*0xa1c168*/
  sub_94AC00(a1, 1); /*0xa1c179*/
  return LuaStack_PushSlot(a1); /*0xa1c170*/
}