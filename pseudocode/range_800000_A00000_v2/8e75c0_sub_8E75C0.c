// Function: sub_8E75C0
// Address: 0x8e75c0
char __cdecl sub_8E75C0(int a1, char *a2, int n214_2, int n355, char a5, char n128, char a7, char a8, char a9)
{
  char *v9; // esi
  char result; // al
  unsigned __int8 n0xE0; // al
  char v12; // al
  unsigned __int8 n0x40; // cl
  unsigned __int8 n0x34; // al
  void *v15; // ecx
  double v16; // [esp+24h] [ebp-14h]
  _BYTE v17[4]; // [esp+2Ch] [ebp-Ch] BYREF
  _BYTE v18[4]; // [esp+30h] [ebp-8h] BYREF
  float n214_1; // [esp+34h] [ebp-4h]
  float n214; // [esp+48h] [ebp+10h]
  float v21; // [esp+48h] [ebp+10h]
  float n355_1; // [esp+48h] [ebp+10h]
  float v23; // [esp+48h] [ebp+10h]

  sub_640F60(v17, v18);
  memset(word_1841D10, 0, 0x40u);
  v9 = a2;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  n214 = (float)n214_2;
  n214_1 = n214;
  unk_25D09A1 = a7;
  unk_25D09A2 = a8;
  n214 = n214;
  unk_25D09A3 = a9;
  n355 = (float)n355;
  n128 = n128;
  unk_25D09BB = a5;
  for ( result = *a2; *v9; result = *v9 )
  {
    switch ( sub_8DF600(result) )
    {
      case 1:
        n214 = n214_1;
        n355 = n355 + 16.0;
        break;
      case 2:
        if ( *v9 == 7 )
        {
          n0xE0 = v9[1];
          if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u )
          {
            v21 = (float)(n0xE0 - 224);
            n214 = v21 + n214;
          }
        }
        else
        {
          if ( *v9 == 10 )
          {
            v12 = unk_25D09BB;
            if ( (v9[1] & 0xF) != 0 )
            {
              v12 = ((v9[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
              unk_25D09BB = v12;
            }
            n0x40 = v9[1] & 0xF0;
            if ( n0x40 >= 0x40u )
              unk_25D09BB = (n0x40 - 64) | v12 & 0xF;
          }
          if ( *v9 == 11 )
          {
            n0x34 = v9[1];
            n355_1 = n355;
            if ( n0x34 >= 0x34u && n0x34 <= 0x37u )
              n355_1 = n355 + 1.0;
            sub_8B1300(n0x34, -1);
            v23 = sub_8E5280(v15) + n355_1 + 3.0;
            sub_8F8EE0((unsigned __int8)v9[1], n214, v23, 0.64999998, n128, a7, a8, a9);
            v16 = sub_8FA800((unsigned __int8)v9[1], 0.64999998);
            n214 = sub_8FA570(0) + v16 + n214;
          }
          sub_8B12E0();
        }
        break;
      case 3:
        if ( a1 != -1 )
          sub_8E9CA0(a1, (int)v9, (int)&n128, 0.77999997, 1.0, 1);
        break;
      case 4:
        sub_8B71F0(v9, word_1841D10);
        sub_643CA0(1);
        sub_640F80(0);
        sub_8FBAE0((float *)&n128, word_1841D10, 0.77999997);
        sub_640F80(1);
        sub_8FB940((int *)&n128, word_1841D10, 0.77999997);
        sub_643CA0(0);
        sub_8E8ED0((int)&n128, (int)word_1841D10, 0.77999997);
        break;
      default:
        break;
    }
    v9 = (char *)sub_8DFD70(v9);
  }
  return result;
}
