// Function: sub_8F3390
// Address: 0x8f3390
int __cdecl sub_8F3390(int a1, int a2, int a3, int a4, int a5)
{
  char Buffer[32]; // [esp+Ch] [ebp-24h] BYREF

  sprintf(Buffer, "%d", a2);
  return sub_8EE060(a1, Buffer, a3 - 10 * strlen(Buffer) + 2, a4, a5, 128, 128, 128, 128);
}
