// Function: sub_930550
// Address: 0x930550
int __cdecl sub_930550(int a1, int a2, int n2, int a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp-2Ch] [ebp-34h]
  int v10; // [esp-10h] [ebp-18h]
  int v11; // [esp-Ch] [ebp-14h]
  void *v12; // [esp-4h] [ebp-Ch]

  v4 = sub_92E1C0(a2);
  *(_DWORD *)(a1 + 4) = v4;
  v5 = sub_8036E0(v4, n2, a4);
  v6 = sub_716B10(*(_DWORD *)off_C3A4C4, *(_DWORD *)off_C3A4C4 + 16, v5);
  v7 = unknown_libname_742(v6);
  v9 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 8) = v7;
  sub_831440(v9, -1, 15360);
  sub_831410(*(_DWORD *)(a1 + 4), -1, 12000);
  v12 = off_C498DC;
  v11 = *(_DWORD *)(a1 + 4);
  v10 = unknown_libname_741(*(_DWORD *)(a1 + 8));
  if ( a4 )
    sub_803280(v10, v11, n2, (int)v12);
  else
    sub_803140(v10, v11, n2, (int)v12);
  sub_834000(*(_DWORD *)(a1 + 4), a1 + 192);
  return sub_82EBE0(*(_DWORD *)(a1 + 4), 1);
}
