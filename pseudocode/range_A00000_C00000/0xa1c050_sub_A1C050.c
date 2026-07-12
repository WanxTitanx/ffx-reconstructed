// Function: sub_A1C050
// Address: 0xa1c050
// Size: 0x3d

int __stdcall sub_A1C050(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c056*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943DF0); /*0xa1c068*/
  sub_94AC00(a1, 1); /*0xa1c079*/
  return LuaStack_PushSlot(a1); /*0xa1c070*/
}