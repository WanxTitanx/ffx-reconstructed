// Function: sub_A1C010
// Address: 0xa1c010
// Size: 0x3d

int __stdcall sub_A1C010(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c016*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943E88); /*0xa1c028*/
  sub_94AC00(a1, 1); /*0xa1c039*/
  return LuaStack_PushSlot(a1); /*0xa1c030*/
}