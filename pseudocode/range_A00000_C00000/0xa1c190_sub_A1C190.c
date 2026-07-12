// Function: sub_A1C190
// Address: 0xa1c190
// Size: 0x3d

int __stdcall sub_A1C190(int a1, _DWORD *a2)
{
  if ( *a2 ) /*0xa1c196*/
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)dword_1943B40); /*0xa1c1a8*/
  sub_94AC00(a1, 1); /*0xa1c1b9*/
  return LuaStack_PushSlot(a1); /*0xa1c1b0*/
}