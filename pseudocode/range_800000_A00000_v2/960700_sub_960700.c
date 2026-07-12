// Function: sub_960700
// Address: 0x960700
int __cdecl sub_960700(int a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+10h] [ebp-6Ch]
  _BYTE v8[100]; // [esp+14h] [ebp-68h] BYREF

  if ( Lua_Type(a1, 1) == 8 )
  {
    v1 = 1;
    v2 = sub_94C130(a1, 1);
    v7 = v2;
  }
  else
  {
    v1 = 0;
    v2 = a1;
    v7 = a1;
  }
  v3 = sub_94C920(a1, v1 + 1);
  if ( !sub_957070(v2, v3, v8) )
    sub_94C700(a1, v1 + 1, "level out of range");
  sub_94C8F0(a1, v1 + 3);
  Lua_Pop(a1, v1 + 3);
  sub_94C2E0(a1, v7, 1);
  v4 = sub_94C920(a1, v1 + 2);
  v5 = sub_957100(v7, v8, v4);
  sub_94B770(a1, v5);
  return 1;
}
