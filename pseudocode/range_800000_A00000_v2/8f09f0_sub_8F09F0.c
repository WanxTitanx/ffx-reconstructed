// Function: sub_8F09F0
// Address: 0x8f09f0
int __cdecl sub_8F09F0(int a1, unsigned int n0xC6, unsigned int n0xC6_1, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // eax
  int v9; // eax
  int v11; // [esp+8h] [ebp-4h]

  v8 = sub_8FA4F0(n0xC6_1);
  v11 = v8 + 4;
  v9 = sub_8ED380(a1, n0xC6, a4, a5, a6 - *(unsigned __int16 *)(v8 + 8), 0, a7, a8);
  return sub_8ED380(v9, n0xC6_1, a6 + a4 - *(unsigned __int16 *)(v11 + 4), a5, 0, 0, a8, a8);
}
