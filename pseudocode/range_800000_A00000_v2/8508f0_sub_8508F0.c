// Function: sub_8508F0
// Address: 0x8508f0
int __cdecl sub_8508F0(int a1, int a2, int a3)
{
  _DWORD *v3; // ecx
  int result; // eax

  sub_84A4D0(a1, a2, a3, 0, unk_13240EC, 70, 10);
  unk_13240EC += 10;
  sub_84A670(a1, a2, 1);
  v3 = dword_1323D2C;
  result = *dword_1323D2C;
  dword_1323D2C[*dword_1323D2C + 1] = a2;
  ++*v3;
  return result;
}
