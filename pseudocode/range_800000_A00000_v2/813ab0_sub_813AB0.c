// Function: sub_813AB0
// Address: 0x813ab0
int __cdecl sub_813AB0(int a1, int a2, __int16 a3, __int16 a4)
{
  int v4; // eax
  int v5; // eax
  int result; // eax

  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 4) = a3;
  *(_WORD *)(a1 + 6) = a4;
  *(_WORD *)(a1 + 8) = 0;
  *(_WORD *)(a1 + 2) = a2;
  v4 = unknown_libname_742(a1 + 32);
  *(_DWORD *)(a1 + 24) = v4;
  v5 = unknown_libname_741(v4);
  result = unknown_libname_742(32 * a2 + v5);
  *(_DWORD *)(a1 + 28) = result;
  return result;
}
