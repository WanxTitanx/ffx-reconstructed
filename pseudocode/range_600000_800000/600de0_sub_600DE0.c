// Function: sub_600DE0
// Address: 0x600de0
// Size: 0x3a

int __stdcall sub_600DE0(int a1, int *a2)
{
  if ( *a2 ) /*0x600de6*/
    return PhyreLua_PushPhyreObject(a1, *a2, (int)&unk_CBF228); /*0x600df5*/
  sub_94AC00(a1, 1); /*0x600e06*/
  return LuaStack_PushSlot(a1); /*0x600dfd*/
}
