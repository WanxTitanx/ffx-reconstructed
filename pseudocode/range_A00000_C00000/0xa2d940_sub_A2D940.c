// Function: sub_A2D940
// Address: 0xa2d940
// Size: 0x3a
// Prototype: 

int __stdcall sub_A2D940(int a1, int *a2)
{
  if ( *a2 )
    return PhyreLua_PushPhyreObject(a1, *a2, (int)dword_1A84C88);
  sub_94AC00(a1, 1);
  return LuaStack_PushSlot(a1);
}

