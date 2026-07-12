// Function: sub_8F2B60
// Address: 0x8f2b60
_DWORD *__cdecl sub_8F2B60(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v7; // [esp-Ch] [ebp-14h]
  int v8; // [esp-8h] [ebp-10h]

  dword_187168C = a1;
  sub_8F5E90(204, 205, a3, a4, unk_25D1672, unk_25D0B14, unk_25D0B10);
  v8 = a4 + unk_25D1662;
  v7 = a3 + unk_25D1664;
  v5 = sub_8AC800(a2);
  sub_901CB0(v5, v7, v8, a5);
  sub_903B70(231, a3, a4, 512, 0, -2139062144, -2139062144);
  return dword_187168C;
}
