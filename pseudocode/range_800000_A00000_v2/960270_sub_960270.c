// Function: sub_960270
// Address: 0x960270
int __cdecl sub_960270(int a1)
{
  if ( Lua_Type(a1, 1) == 2 )
    sub_94C700(a1, 1, "full userdata expected, got light userdata");
  sub_94CB30(a1, 1, 7);
  if ( Lua_Type(a1, 2) > 0 )
    sub_94CB30(a1, 2, 5);
  Lua_Pop(a1, 2);
  sub_94BE90(a1, 1);
  return 1;
}
