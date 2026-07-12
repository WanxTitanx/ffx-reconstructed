// Function: sub_8F3220
// Address: 0x8f3220
int __cdecl sub_8F3220(int a1, int a2, int a3, int a4, int a5)
{
  char Buffer[32]; // [esp+4h] [ebp-24h] BYREF

  sprintf(Buffer, "%d", a2);
  return sub_8EDFC0(a1, Buffer, a3, a4, a5, 128, 128, 128, 128);
}
