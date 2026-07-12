// Function: sub_600CE0
// Address: 0x600ce0
// Size: 0x3a

int __stdcall sub_600CE0(int a1, int *a2)
{
  if ( *a2 ) /*0x600ce6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBEF30); /*0x600cf5*/
  sub_94AC00(a1, 1); /*0x600d06*/
  return LuaStack_PushSlot(a1); /*0x600cfd*/
}
