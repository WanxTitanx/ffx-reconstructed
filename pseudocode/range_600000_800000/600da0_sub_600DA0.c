// Function: sub_600DA0
// Address: 0x600da0
// Size: 0x3d

int __stdcall sub_600DA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600da6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBFB10); /*0x600db8*/
  sub_94AC00(a1, 1); /*0x600dc9*/
  return LuaStack_PushSlot(a1); /*0x600dc0*/
}
