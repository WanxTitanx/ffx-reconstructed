// Function: sub_601020
// Address: 0x601020
// Size: 0x3d

int __stdcall sub_601020(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0x601026*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_CBF520); /*0x601038*/
  sub_94AC00(a1, 1); /*0x601049*/
  return LuaStack_PushSlot(a1); /*0x601040*/
}
