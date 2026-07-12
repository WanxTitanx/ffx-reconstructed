// Function: sub_600B20
// Address: 0x600b20
// Size: 0x3b

int __stdcall sub_600B20(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600b26*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 1, (int)&unk_CBECD0); /*0x600b36*/
  sub_94AC00(a1, 1); /*0x600b47*/
  return LuaStack_PushSlot(a1); /*0x600b3e*/
}
