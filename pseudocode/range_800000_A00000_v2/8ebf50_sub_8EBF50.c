// Function: sub_8EBF50
// Address: 0x8ebf50
int __cdecl sub_8EBF50(int a1, int a2, int a3, int a4, int a5)
{
  char Buffer[32]; // [esp+0h] [ebp-24h] BYREF

  sprintf(Buffer, "%d", a2);
  return sub_8EA000(a1, Buffer, a3 - 12 * strlen(Buffer), a4, a5);
}
