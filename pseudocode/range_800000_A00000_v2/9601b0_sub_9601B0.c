// Function: sub_9601B0
// Address: 0x9601b0
int __cdecl sub_9601B0(_DWORD *a1)
{
  sub_94C8F0(a1, 1);
  if ( !Lua_PushTypedValue(a1, 1) )
    LuaStack_PushSlot((int)a1);
  return 1;
}
