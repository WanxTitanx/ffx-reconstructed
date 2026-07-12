// Function: sub_600FE0
// Address: 0x600fe0
// Size: 0x3d

int __stdcall sub_600FE0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600fe6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBFBA8); /*0x600ff8*/
  sub_94AC00(a1, 1); /*0x601009*/
  return LuaStack_PushSlot(a1); /*0x601000*/
}
