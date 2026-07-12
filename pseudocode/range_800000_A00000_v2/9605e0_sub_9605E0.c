// Function: sub_9605E0
// Address: 0x9605e0
int __cdecl sub_9605E0(int a1)
{
  int v1; // ebx
  int v2; // edi
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v9; // [esp+Ch] [ebp-6Ch]
  _BYTE v10[100]; // [esp+10h] [ebp-68h] BYREF

  if ( Lua_Type(a1, 1) == 8 )
  {
    v1 = 1;
    v2 = sub_94C130(a1, 1);
  }
  else
  {
    v1 = 0;
    v2 = a1;
  }
  v3 = sub_94C920(a1, v1 + 2);
  v4 = v1 + 1;
  v9 = v3;
  if ( Lua_Type(a1, v4) == 6 )
  {
    sub_94B850(a1, v4);
    v5 = sub_957000(a1, 0, v9);
    sub_94B770(a1, v5);
  }
  else
  {
    v6 = sub_94C920(a1, v4);
    if ( !sub_957070(v2, v6, v10) )
      sub_94C700(a1, v4, "level out of range");
    v7 = sub_957000(v2, v10, v9);
    if ( v7 )
    {
      sub_94C2E0(v2, a1, 1);
      sub_94B770(a1, v7);
      sub_94B850(a1, -2);
      return 2;
    }
    LuaStack_PushSlot(a1);
  }
  return 1;
}
