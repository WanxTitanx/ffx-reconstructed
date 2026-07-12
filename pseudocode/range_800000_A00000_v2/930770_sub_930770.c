// Function: sub_930770
// Address: 0x930770
int __cdecl sub_930770(int a1)
{
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = unknown_libname_742(0);
  memset((void *)(a1 + 16), 0, 0x70u);
  *(_DWORD *)(a1 + 16) = 28;
  *(_DWORD *)(a1 + 20) = off_C498DC;
  *(_BYTE *)(a1 + 24) = 68;
  *(_DWORD *)(a1 + 40) = -2139062144;
  *(_DWORD *)(a1 + 48) = a1 + 128;
  *(_DWORD *)(a1 + 52) = sub_836230();
  *(_DWORD *)(a1 + 56) = sub_8362C0();
  *(_DWORD *)(a1 + 60) = a1 + 192;
  *(_WORD *)(a1 + 92) = -32640;
  sub_6EDAE0(a1 + 128);
  return sub_6EDAE0(a1 + 192);
}
