// Function: sub_600BA0
// Address: 0x600ba0
// Size: 0x3b

int __stdcall sub_600BA0(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600ba6*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 1, (int)&unk_CBFD70); /*0x600bb6*/
  sub_94AC00(a1, 1); /*0x600bc7*/
  return LuaStack_PushSlot(a1); /*0x600bbe*/
}
