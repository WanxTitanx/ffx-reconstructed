// Function: sub_9600F0
// Address: 0x9600f0
int __cdecl sub_9600F0(int a1)
{
  int v1; // ebx
  int v3; // eax
  int v4; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  if ( Lua_Type(a1, 1) == 8 )
  {
    v1 = 1;
    v5 = sub_94C130(a1, 1);
  }
  else
  {
    v1 = 0;
    v5 = a1;
  }
  v4 = LuaBridge_ResolveValue(a1, v1 + 1, 0);
  if ( v4 || Lua_Type(a1, v1 + 1) <= 0 )
  {
    v3 = sub_94D5E0(a1, v1 + 2, a1 == v5);
    sub_94DB70(a1, v5, v4, v3);
    return 1;
  }
  else
  {
    sub_94B850(a1, v1 + 1);
    return 1;
  }
}
