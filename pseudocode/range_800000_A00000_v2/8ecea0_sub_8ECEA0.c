// Function: sub_8ECEA0
// Address: 0x8ecea0
int __cdecl sub_8ECEA0(int a1, int a2, int a3, int a4, int n355, char a6)
{
  int n214; // ecx
  _DWORD v8[8]; // [esp+0h] [ebp-24h] BYREF

  sub_8B90F0(a3, v8, a2);
  if ( FFX_Game_GetRegion(v8[0]) || FFX_Kernel_GetStubZero() )
    n214 = -9 * strlen((const char *)v8) + a4;
  else
    n214 = a4 - 12 * strlen((const char *)v8);
  return sub_8E92A0(a1, -1, (char *)v8, n214, n355, a6, 0, 128, 128, 128, 128);
}
