// Function: sub_920540
// Address: 0x920540
int __cdecl sub_920540(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  ++*(_DWORD *)(a1 + 12);
  result = sub_9258F0(*(void **)(a1 + 16), 4 * *(_DWORD *)(a1 + 12), (int)"..\\program\\src\\rcBg\\rcbgScene.c", 118);
  v3 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 16) = result;
  *(_DWORD *)(result + 4 * v3 - 4) = a2;
  return result;
}
