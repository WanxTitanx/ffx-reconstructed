// Function: sub_600C60
// Address: 0x600c60
// Size: 0x3d

int __stdcall sub_600C60(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600c66*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBEE00); /*0x600c78*/
  sub_94AC00(a1, 1); /*0x600c89*/
  return LuaStack_PushSlot(a1); /*0x600c80*/
}
