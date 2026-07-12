// Function: sub_8E99A0
// Address: 0x8e99a0
int __cdecl sub_8E99A0(
        int a1,
        int n49_1,
        int n214,
        int n355,
        unsigned __int8 n128,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  int n49; // ebx
  int n214_1; // esi
  int v10; // esi
  int v12; // [esp-4h] [ebp-10h]

  n49 = n49_1;
  n214_1 = n214;
  unk_187168C = a1;
  if ( (unsigned int)(n49_1 - 64) <= 0xF )
  {
    v10 = n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8);
    n49 = n49_1 & 0xF;
    if ( (n49_1 & 1) != 0 )
      sub_903A50(601, n214, n355, v10, v10);
    else
      sub_903A50(600, n214, n355, v10, v10);
    if ( (n49_1 & 2) != 0 )
      sub_903A50(603, n214, n355, v10, v10);
    else
      sub_903A50(602, n214, n355, v10, v10);
    if ( (n49_1 & 4) != 0 )
      sub_903A50(605, n214, n355, v10, v10);
    else
      sub_903A50(604, n214, n355, v10, v10);
    v12 = n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8);
    n214_1 = n214;
    if ( (n49_1 & 8) != 0 )
      sub_903A50(607, n214, n355, v12, v12);
    else
      sub_903A50(606, n214, n355, v12, v12);
  }
  if ( (unsigned int)(n49 - 48) <= 9 )
  {
    if ( sub_8ACEE0() == 1 && (unsigned int)(n49 - 49) <= 1 )
    {
      if ( n49 == 49 )
      {
        sub_903A50(
          610,
          n214_1,
          n355,
          n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
          n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
        return unk_187168C;
      }
      if ( n49 == 50 )
      {
        sub_903A50(
          609,
          n214_1,
          n355,
          n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
          n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
        return unk_187168C;
      }
    }
    else
    {
      sub_903A50(
        n49 + 560,
        n214_1,
        n355,
        n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
        n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
    }
  }
  if ( n49 == 96 )
    sub_903A50(
      624,
      n214_1,
      n355,
      n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
      n128 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
  return unk_187168C;
}
