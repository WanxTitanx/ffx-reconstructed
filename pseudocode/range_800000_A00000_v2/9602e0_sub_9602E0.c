// Function: sub_9602E0
// Address: 0x9602e0
int __cdecl sub_9602E0(int a1)
{
  int v1; // edi
  int v2; // ebx
  const char *v3; // edi
  int v4; // eax
  int v6; // [esp+Ch] [ebp-74h]
  int v7; // [esp+10h] [ebp-70h]
  int v8; // [esp+14h] [ebp-6Ch]
  _BYTE v9[4]; // [esp+18h] [ebp-68h] BYREF
  int v10; // [esp+1Ch] [ebp-64h]
  int v11; // [esp+20h] [ebp-60h]
  int v12; // [esp+24h] [ebp-5Ch]
  int v13; // [esp+28h] [ebp-58h]
  int v14; // [esp+2Ch] [ebp-54h]
  int v15; // [esp+30h] [ebp-50h]
  int v16; // [esp+34h] [ebp-4Ch]
  unsigned __int8 v17; // [esp+38h] [ebp-48h]
  unsigned __int8 v18; // [esp+39h] [ebp-47h]
  char v19; // [esp+3Ah] [ebp-46h]
  char v20; // [esp+3Bh] [ebp-45h]
  _BYTE v21[64]; // [esp+3Ch] [ebp-44h] BYREF

  if ( Lua_Type(a1, 1) == 8 )
  {
    v1 = 1;
    v8 = 1;
    v2 = sub_94C130(a1, 1);
    v7 = v2;
  }
  else
  {
    v1 = 0;
    v8 = 0;
    v2 = a1;
    v7 = a1;
  }
  v6 = v1 + 2;
  v3 = (const char *)sub_94D610(a1, v1 + 2, "flnStu", 0);
  if ( sub_94B2D0(a1, v8 + 1) )
  {
    v4 = sub_94BF60(a1, v8 + 1, 0);
    if ( !sub_957070(v2, v4, v9) )
    {
      LuaStack_PushSlot(a1);
      return 1;
    }
  }
  else
  {
    if ( Lua_Type(a1, v8 + 1) != 6 )
      sub_94C700(a1, v8 + 1, "function or level expected");
    sub_94B660(a1, ">%s", v3);
    v3 = (const char *)LuaBridge_ResolveValue(a1, -1, 0);
    sub_94B850(a1, v8 + 1);
    sub_94C2E0(a1, v2, 1);
  }
  if ( !sub_956F50(v2, v3, v9) )
    sub_94C700(a1, v6, "invalid option");
  sub_94ADC0(a1, 0, 2);
  if ( strchr(v3, 83) )
  {
    sub_94B770(a1, v13);
    sub_94BC30(a1, -2, "source");
    sub_94B770(a1, v21);
    sub_94BC30(a1, -2, "short_src");
    sub_94B690(a1, v15);
    sub_94BC30(a1, -2, "linedefined");
    sub_94B690(a1, v16);
    sub_94BC30(a1, -2, "lastlinedefined");
    sub_94B770(a1, v12);
    sub_94BC30(a1, -2, "what");
  }
  if ( strchr(v3, 108) )
  {
    sub_94B690(a1, v14);
    sub_94BC30(a1, -2, "currentline");
  }
  if ( strchr(v3, 117) )
  {
    sub_94B690(a1, v17);
    sub_94BC30(a1, -2, "nups");
    sub_94B690(a1, v18);
    sub_94BC30(a1, -2, "nparams");
    sub_94B5A0(a1, v19);
    sub_94BC30(a1, -2, "isvararg");
  }
  if ( strchr(v3, 110) )
  {
    sub_94B770(a1, v10);
    sub_94BC30(a1, -2, "name");
    sub_94B770(a1, v11);
    sub_94BC30(a1, -2, "namewhat");
  }
  if ( strchr(v3, 116) )
  {
    sub_94B5A0(a1, v20);
    sub_94BC30(a1, -2, "istailcall");
  }
  if ( strchr(v3, 76) )
    sub_960CD0(a1, v7, "activelines");
  if ( strchr(v3, 102) )
    sub_960CD0(a1, v7, "func");
  return 1;
}
