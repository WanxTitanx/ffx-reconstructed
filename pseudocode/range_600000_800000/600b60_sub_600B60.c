// Function: sub_600B60
// Address: 0x600b60
// Size: 0x3b

int __stdcall sub_600B60(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600b66*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 1, (int)&unk_CBEC38); /*0x600b76*/
  sub_94AC00(a1, 1); /*0x600b87*/
  return LuaStack_PushSlot(a1); /*0x600b7e*/
}
