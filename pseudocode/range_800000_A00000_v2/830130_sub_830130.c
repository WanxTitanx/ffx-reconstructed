// Function: sub_830130
// Address: 0x830130
int __cdecl sub_830130(int a1, int a2)
{
  int result; // eax

  result = (*(_DWORD *)(a1 + 404) ^ (a2 << 19)) & 0x80000;
  *(_DWORD *)(a1 + 404) ^= result;
  return result;
}
