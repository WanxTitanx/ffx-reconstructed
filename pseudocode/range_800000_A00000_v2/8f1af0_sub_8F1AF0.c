// Function: sub_8F1AF0
// Address: 0x8f1af0
int __cdecl sub_8F1AF0(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // esi
  int v7; // eax

  v6 = sub_8ED380(a1, 0xDAu, a2, a3, 0, 0, a5, a5);
  v7 = sub_8FA7D0(18);
  return sub_8ED380(v6, 0xDBu, *(unsigned __int16 *)(v7 + 8) + a2, a3, a4 - *(unsigned __int16 *)(v7 + 8), 0, a5, a6);
}
