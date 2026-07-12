// Function: sub_8E92A0
// Address: 0x8e92a0
int __cdecl sub_8E92A0(
        int a1,
        int a2,
        char *a3,
        int n214_1,
        int n355,
        char a6,
        char a7,
        char a8,
        char a9,
        char a10,
        char a11)
{
  char *v11; // esi
  char i; // al
  double v13; // st7
  unsigned __int8 n0xE0; // al
  char v15; // al
  unsigned __int8 n0x40; // cl
  float v18; // [esp+0h] [ebp-Ch]
  float n214; // [esp+14h] [ebp+8h]
  float v20; // [esp+20h] [ebp+14h]
  float v21; // [esp+20h] [ebp+14h]

  memset(&unk_1841D10, 0, 0x40u);
  v11 = a3;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  unk_187168C = a1;
  n214 = (float)n214_1;
  unk_25D09A1 = a9;
  unk_25D09A2 = a10;
  n214 = n214;
  unk_25D09A3 = a11;
  unk_25D09BA = a7;
  n355 = (float)n355;
  unk_25D09A0 = a8;
  unk_25D09BB = a6;
  for ( i = *a3; *v11; i = *v11 )
  {
    switch ( sub_8DF600(i) )
    {
      case 1:
        n214 = n214;
        n355 = n355 + 16.0;
        break;
      case 2:
        if ( *v11 == 7 )
        {
          n0xE0 = v11[1];
          if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u )
          {
            v20 = (float)(n0xE0 - 224);
            n214 = v20 + n214;
          }
        }
        else
        {
          if ( *v11 == 10 )
          {
            v15 = unk_25D09BB;
            if ( (v11[1] & 0xF) != 0 )
            {
              v15 = ((v11[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
              unk_25D09BB = v15;
            }
            n0x40 = v11[1] & 0xF0;
            if ( n0x40 >= 0x40u )
              unk_25D09BB = (n0x40 - 64) | v15 & 0xF;
          }
          if ( *v11 == 11 )
          {
            sub_8B1300((unsigned __int8)v11[1], -1);
            unk_187168C = sub_8E99A0(unk_187168C, (unsigned __int8)v11[1], (int)n214, (int)n355, a8, a9, a10, a11);
            v21 = (float)(int)sub_8B6590((unsigned __int8)v11[1]);
            n214 = v21 * flt_C5D778 + n214;
          }
          sub_8B12E0();
        }
        break;
      case 3:
        if ( a2 != -1 )
          sub_8E9B80(a2, v11, &unk_25D09A0);
        break;
      case 4:
        sub_8B71F0(v11, &unk_1841D10);
        if ( unk_25D09BA == 1 )
        {
          sub_906260(&unk_25D09A0, &unk_1841D10);
          sub_906270(&unk_25D09A0, &unk_1841D10);
          v13 = flt_C5D784;
        }
        else
        {
          sub_643CA0(1);
          sub_640F80(0);
          sub_906290(&unk_25D09A0, &unk_1841D10);
          sub_640F80(1);
          sub_906270(&unk_25D09A0, &unk_1841D10);
          sub_643CA0(0);
          v13 = 0.77999997;
        }
        v18 = v13;
        sub_8E8ED0((int)&unk_25D09A0, (int)&unk_1841D10, v18);
        break;
      default:
        break;
    }
    v11 = (char *)sub_8DFD70(v11);
  }
  return unk_187168C;
}
