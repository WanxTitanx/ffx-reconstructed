// Function: sub_A322D0
// Address: 0xa322d0
// Size: 0x3a
// Prototype: 

int __stdcall sub_A322D0(int a1, int *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2, (int)Size_5);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

