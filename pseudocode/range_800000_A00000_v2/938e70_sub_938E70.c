// Function: sub_938E70
// Address: 0x938e70
int __cdecl sub_938E70(int a1, int a2)
{
  int v2; // esi
  int v3; // edi
  int v4; // eax

  v2 = a2;
  v3 = a1;
  sub_62FF70(a2, a1 + 16);
  a1 = sub_928270(v3);
  sub_62FF70(v2, &a1);
  v4 = unknown_libname_741(*(_DWORD *)(v3 + 20));
  sub_62FF70(v2, v4);
  sub_62FF70(v2, v3 + 32);
  sub_62FF70(v2, v3 + 144);
  sub_62FF70(v2, v3 + 176);
  sub_62FF70(v2, v3 + 192);
  return sub_62FF70(v2, v3 + 256);
}
