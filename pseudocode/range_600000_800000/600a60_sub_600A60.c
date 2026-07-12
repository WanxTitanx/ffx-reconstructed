// Function: sub_600A60
// Address: 0x600a60
// Size: 0x3d

int __stdcall sub_600A60(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x600a66*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBEBA0); /*0x600a78*/
  sub_94AC00(a1, 1); /*0x600a89*/
  return LuaStack_PushSlot(a1); /*0x600a80*/
}
