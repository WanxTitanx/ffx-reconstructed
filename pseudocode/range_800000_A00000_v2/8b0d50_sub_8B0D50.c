// Function: sub_8B0D50
// Address: 0x8b0d50
int __usercall sub_8B0D50@<eax>(int a1@<ebp>, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD v9[31]; // [esp-70h] [ebp-7Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v9[28] = a1;
  v9[29] = retaddr;
  sub_62F9E0(v9, a3, a7 / 64, a4, a5, a6, a7, a8);
  nullsub_33(0);
  sub_62FA30(0, 0);
  sub_62F960(v9, a2);
  return sub_62FA30(0, 0);
}
