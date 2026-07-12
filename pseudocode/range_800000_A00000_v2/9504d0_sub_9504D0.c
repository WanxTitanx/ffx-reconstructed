// Function: sub_9504D0
// Address: 0x9504d0
int __cdecl sub_9504D0(int a1)
{
  int v1; // edi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 12);
  sub_950A00(a1, a1);
  sub_950560(a1, v1);
  LuaStr_TableResize(a1, 32);
  sub_95C550(a1);
  sub_95CF70(a1);
  result = LuaStr_Create(a1, "not enough memory", 0x11u);
  *(_DWORD *)(v1 + 152) = result;
  *(_BYTE *)(result + 5) |= 0x20u;
  *(_BYTE *)(v1 + 51) = 1;
  return result;
}
