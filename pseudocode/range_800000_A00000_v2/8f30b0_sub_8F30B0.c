// Function: sub_8F30B0
// Address: 0x8f30b0
int __cdecl sub_8F30B0(int a1, int a2, int a3, int n355, char a5)
{
  int n214; // ecx
  char v7[32]; // [esp+0h] [ebp-24h] BYREF

  sub_8B90F0(a2, v7, 0);
  if ( FFX_Game_GetRegion() || FFX_Kernel_GetStubZero() )
    n214 = -9 * strlen(v7) + a3;
  else
    n214 = a3 - 12 * strlen(v7);
  return sub_8E92A0(a1, -1, v7, n214, n355, a5, 0, 128, 128, 128, 128);
}
