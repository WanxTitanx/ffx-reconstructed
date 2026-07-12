// Function: sub_A1BC90
// Address: 0xa1bc90
// Size: 0x3d
// Prototype: 

int __stdcall sub_A1BC90(int a1, _DWORD *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2 + 4, (int)&unk_19438E0);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

