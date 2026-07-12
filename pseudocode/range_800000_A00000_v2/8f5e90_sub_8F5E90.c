// Function: sub_8F5E90
// Address: 0x8f5e90
_DWORD *__cdecl sub_8F5E90(unsigned int n204, unsigned int n205, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *result; // eax
  int v8; // [esp+8h] [ebp-4h]

  v8 = *(unsigned __int16 *)(sub_8FA4F0(n205) + 8);
  dword_187168C = (_DWORD *)sub_8ED380((int)dword_187168C, n204, a3, a4, a5 - v8, 0, a6, a7);
  result = (_DWORD *)sub_8ED380((int)dword_187168C, n205, a5 + a3 - v8, a4, 0, 0, a7, a7);
  dword_187168C = result;
  return result;
}
