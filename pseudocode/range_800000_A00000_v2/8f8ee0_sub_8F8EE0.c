// Function: sub_8F8EE0
// Address: 0x8f8ee0
int __cdecl sub_8F8EE0(
        int n32,
        float a2,
        int a3,
        float a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        unsigned __int8 a7,
        unsigned __int8 a8)
{
  int n49; // ebx
  double v9; // st7
  double v10; // st6
  unsigned int v11; // esi
  int result; // eax
  float v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]

  n49 = n32;
  if ( (unsigned int)(n32 - 52) <= 3 )
    *(float *)&a3 = *(float *)&a3 - 2.0;
  v9 = *(float *)&a3;
  v10 = a2;
  if ( n32 == 32 || n32 == 33 || n32 == 34 )
  {
    FFX_Menu2D_DrawTexQuadTinted(
      0x258u,
      a2,
      a3,
      10.0,
      10.0,
      COERCE_INT(96.0),
      COERCE_INT(224.0),
      COERCE_INT(139.0),
      COERCE_INT(267.0),
      a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
      a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
    v9 = *(float *)&a3;
    v10 = a2;
  }
  if ( (unsigned int)(n32 - 64) <= 0xF )
  {
    v11 = a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8);
    n49 = n32 & 0xF;
    *(float *)&v14 = v9;
    v13 = v10;
    if ( (n32 & 1) != 0 )
      sub_8E7A90(601, v13, v14, a4, v11, v11);
    else
      sub_8E7A90(600, v13, v14, a4, v11, v11);
    if ( (n32 & 2) != 0 )
      sub_8E7A90(603, a2, a3, a4, v11, v11);
    else
      sub_8E7A90(602, a2, a3, a4, v11, v11);
    if ( (n32 & 4) != 0 )
      sub_8E7A90(605, a2, a3, a4, v11, v11);
    else
      sub_8E7A90(604, a2, a3, a4, v11, v11);
    if ( (n32 & 8) != 0 )
      sub_8E7A90(607, a2, a3, a4, v11, v11);
    else
      sub_8E7A90(606, a2, a3, a4, v11, v11);
  }
  result = n49 - 48;
  if ( (unsigned int)(n49 - 48) <= 9 )
  {
    if ( sub_8ACEE0() == 1 && (result = n49 - 49, (unsigned int)(n49 - 49) <= 1) )
    {
      if ( n49 == 49 )
        return sub_8E7A90(
                 610,
                 a2,
                 a3,
                 a4,
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
      if ( n49 == 50 )
        return sub_8E7A90(
                 609,
                 a2,
                 a3,
                 a4,
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
    }
    else
    {
      result = sub_8E7A90(
                 n49 + 560,
                 a2,
                 a3,
                 a4,
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
                 a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
    }
  }
  if ( n49 == 96 )
    return sub_8E7A90(
             624,
             a2,
             a3,
             a4,
             a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8),
             a5 | ((a6 | ((a7 | (a8 << 8)) << 8)) << 8));
  return result;
}
