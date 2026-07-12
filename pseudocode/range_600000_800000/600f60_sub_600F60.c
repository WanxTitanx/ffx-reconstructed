// Function: sub_600F60
// Address: 0x600f60
// Size: 0x3d

int __stdcall sub_600F60(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600f66*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF488); /*0x600f78*/
  sub_94AC00(a1, 1); /*0x600f89*/
  return LuaStack_PushSlot(a1); /*0x600f80*/
}
