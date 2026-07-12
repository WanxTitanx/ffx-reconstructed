// Function: sub_8F0990
// Address: 0x8f0990
int __cdecl sub_8F0990(int a1, unsigned int n0xC6, unsigned int n0xC6_1, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ebx
  int v9; // eax

  v8 = sub_8FA4F0(n0xC6);
  v9 = sub_8ED380(a1, n0xC6, a4, a5, 0, 0, a7, a7);
  return sub_8ED380(v9, n0xC6_1, *(unsigned __int16 *)(v8 + 8) + a4, a5, a6 - *(unsigned __int16 *)(v8 + 8), 0, a7, a8);
}
