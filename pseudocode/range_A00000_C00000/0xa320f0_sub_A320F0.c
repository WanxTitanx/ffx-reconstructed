// Function: sub_A320F0
// Address: 0xa320f0
// Size: 0x60

int __thiscall sub_A320F0(int (__thiscall **this)(_DWORD), int a2)
{
  int v3; // eax
  int v4; // eax

  v3 = sub_A31020(a2); /*0xa320fb*/
  if ( !v3 ) /*0xa32105*/
    return 0; /*0xa32149*/
  v4 = (*(this + 1))(v3); /*0xa3210c*/
  if ( v4 ) /*0xa32110*/
  {
    PhyreLua_PushPhyreObject(a2, v4, (int)&unk_C92090); /*0xa32119*/
  }
  else
  {
    sub_94AC00(a2, 1); /*0xa3212f*/
    LuaStack_PushSlot(a2); /*0xa32135*/
  }
  return 1; /*0xa32126*/
}