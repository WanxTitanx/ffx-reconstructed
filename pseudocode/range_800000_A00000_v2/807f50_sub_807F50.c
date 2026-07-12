// Function: sub_807F50
// Address: 0x807f50
int __cdecl sub_807F50(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int i_1; // ecx
  int v10; // esi
  int i; // [esp+Ch] [ebp-4h]

  i_1 = sub_7E6910(2048);
  v10 = a3 / 256;
  for ( i = i_1; v10 > 0; a1 += 1024 )
  {
    sub_808000(i_1, a2, 256);
    sub_807CE0(a1, i, 256, a4, a5, a6, a7);
    i_1 = i;
    --v10;
    a2 += 1024;
  }
  if ( (a3 & 0x800000FF) == 0 )
  {
    sub_808000(i_1, a2, 0);
    sub_807CE0(a1, i, 0, a4, a5, a6, a7);
  }
  return sub_7E6970(2048);
}
