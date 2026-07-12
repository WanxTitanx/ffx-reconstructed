// Function: sub_8FF3E0
// Address: 0x8ff3e0
int __cdecl sub_8FF3E0(int a1, int a2, int a3, int a4)
{
  float v5; // [esp+8h] [ebp-8h] BYREF
  _BYTE v6[4]; // [esp+Ch] [ebp-4h] BYREF

  sub_8B9600(0, a1, &v5, v6, 0, 0);
  sub_8FB150(a2 + 4, a3 + 4, (int)(478.0 - v5), unk_25D1642, 0, 0, 0, 128);
  sub_8FD390(a2, a3, (int)(482.0 - v5), unk_25D1642, unk_25D163C, unk_25D1638);
  return sub_901CB0(a1, a2 + 15, a3 + 2, a4);
}
