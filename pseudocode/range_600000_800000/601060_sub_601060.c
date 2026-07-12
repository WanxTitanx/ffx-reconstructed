// Function: sub_601060
// Address: 0x601060
// Size: 0x3d

int __stdcall sub_601060(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x601066*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF5B8); /*0x601078*/
  sub_94AC00(a1, 1); /*0x601089*/
  return LuaStack_PushSlot(a1); /*0x601080*/
}
