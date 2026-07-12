// Function: sub_A345F0
// Address: 0xa345f0
// Size: 0x3a
// Prototype: 

int __stdcall sub_A345F0(int a1, int *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2, (int)Size_6);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

