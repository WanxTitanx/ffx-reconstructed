// Function: sub_960230
// Address: 0x960230
int __cdecl sub_960230(int a1)
{
  if ( Lua_Type(a1, 1) == 7 )
    sub_94B210(a1, 1);
  else
    LuaStack_PushSlot(a1);
  return 1;
}
