// Function: sub_850850
// Address: 0x850850
int __cdecl sub_850850(int a1, int a2, int a3)
{
  _DWORD *v3; // ecx

  sub_84A470(a1, a2, a3, 0, unk_13240EC, 70, 10);
  v3 = dword_1323D2C;
  unk_13240EC += 11;
  dword_1323D2C[*dword_1323D2C + 1] = a2;
  ++*v3;
  return sub_84A670(a1, a2, 1);
}
