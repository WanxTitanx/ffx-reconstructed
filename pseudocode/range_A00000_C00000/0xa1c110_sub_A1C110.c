// Function: sub_A1C110
// Address: 0xa1c110
// Size: 0x3d

int __stdcall sub_A1C110(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c116*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943AA8); /*0xa1c128*/
  sub_94AC00(a1, 1); /*0xa1c139*/
  return LuaStack_PushSlot(a1); /*0xa1c130*/
}