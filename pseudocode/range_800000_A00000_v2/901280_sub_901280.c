// Function: sub_901280
// Address: 0x901280
_DWORD *__cdecl sub_901280(int n16, int a2, int a3, int a4)
{
  int i; // esi
  char n48; // al
  char Buffer[8]; // [esp+Ch] [ebp-Ch] BYREF

  sprintf(Buffer, "%02d", n16);
  for ( i = 0; i < 8; ++i )
  {
    n48 = Buffer[i];
    if ( !n48 )
      break;
    if ( n48 >= 48 && n48 <= 57 )
      sub_903A50(n48 + 442, a2, a3, a4, a4);
    a2 += 16;
  }
  return sub_8F3A30();
}
