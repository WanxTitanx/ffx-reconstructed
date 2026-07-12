// Function: sub_950560
// Address: 0x950560
int __cdecl sub_950560(int a1, int a2)
{
  int v2; // esi
  int v4; // [esp+8h] [ebp-8h] BYREF
  int n72; // [esp+Ch] [ebp-4h]

  v2 = LuaStr_TableNew(a1);
  *(_DWORD *)(a2 + 36) = v2;
  *(_DWORD *)(a2 + 40) = 69;
  LuaTable_ArrayResize(a1, v2, 2, 0);
  v4 = a1;
  n72 = 72;
  LuaTable_ArrayGet(a1, v2, 1, &v4);
  v4 = LuaStr_TableNew(a1);
  n72 = 69;
  return LuaTable_ArrayGet(a1, v2, 2, &v4);
}
