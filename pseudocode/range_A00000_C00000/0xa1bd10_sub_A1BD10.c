// Function: sub_A1BD10
// Address: 0xa1bd10
// Size: 0x3d
// Prototype: 

int __stdcall sub_A1BD10(int a1, _DWORD *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_1943978);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

