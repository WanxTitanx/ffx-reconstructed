// Function: sub_600960
// Address: 0x600960
// Size: 0x3d

int __stdcall sub_600960(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600966*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBE940); /*0x600978*/
  sub_94AC00(a1, 1); /*0x600989*/
  return LuaStack_PushSlot(a1); /*0x600980*/
}
