// Function: sub_930710
// Address: 0x930710
int __cdecl sub_930710(int a1)
{
  int v1; // eax
  int result; // eax

  sub_831440(*(_DWORD *)(a1 + 4), -1, -1);
  sub_831410(*(_DWORD *)(a1 + 4), -1, -1);
  sub_82EBE0(*(_DWORD *)(a1 + 4), 0);
  v1 = unknown_libname_741(*(_DWORD *)(a1 + 8));
  if ( v1 )
    sub_716B70(*(_DWORD *)off_C3A4C4, *(_DWORD *)off_C3A4C4 + 16, v1);
  result = unknown_libname_742(0);
  *(_DWORD *)(a1 + 8) = result;
  return result;
}
