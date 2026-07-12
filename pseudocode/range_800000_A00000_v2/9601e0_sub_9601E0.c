// Function: sub_9601E0
// Address: 0x9601e0
int __cdecl sub_9601E0(int a1)
{
  int n5; // eax

  n5 = Lua_Type(a1, 2);
  if ( n5 && n5 != 5 )
    sub_94C700(a1, 2, "nil or table expected");
  Lua_Pop(a1, 2);
  sub_94BCE0(a1, 1);
  return 1;
}
