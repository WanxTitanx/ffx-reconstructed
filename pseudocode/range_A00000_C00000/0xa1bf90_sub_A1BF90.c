// Function: sub_A1BF90
// Address: 0xa1bf90
// Size: 0x3a
// Prototype: 

int __stdcall sub_A1BF90(int a1, int *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_1944478);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

