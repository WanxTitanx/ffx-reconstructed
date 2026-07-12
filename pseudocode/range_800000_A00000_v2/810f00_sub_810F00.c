// Function: sub_810F00
// Address: 0x810f00
int __cdecl sub_810F00(int a1, int a2, int a3, int a4)
{
  *(float *)(*(unsigned __int8 *)(a3 + 2) + a4) = *(float *)(*(unsigned __int8 *)(a3 + 3)
                                                           + (*(unsigned __int16 *)(a4 + 76) << 8)
                                                           + *(_DWORD *)(a2 + 32));
  return a3 + 4;
}
