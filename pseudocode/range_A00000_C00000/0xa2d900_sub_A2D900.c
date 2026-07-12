// Function: sub_A2D900
// Address: 0xa2d900
// Size: 0x3a
// Prototype: 

int __stdcall sub_A2D900(int a1, int *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_1A84D20);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

