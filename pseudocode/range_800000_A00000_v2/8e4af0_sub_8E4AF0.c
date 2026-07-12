// Function: sub_8E4AF0
// Address: 0x8e4af0
int __cdecl sub_8E4AF0(
        int a1,
        int a2,
        char *a3,
        int n214,
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
  int Region; // eax
  double n355_1; // st7
  double n355_2; // st7
  int v16; // eax
  double n355_3; // st7
  double n355_4; // st7
  unsigned __int8 n0xE0; // al
  char v20; // al
  unsigned __int8 n0x40; // cl
  float n214_1; // [esp+2Ch] [ebp+8h]
  float v24; // [esp+34h] [ebp+10h]
  float v25; // [esp+34h] [ebp+10h]

  memset(&unk_1841D10, 0, 0x40u);
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  unk_187168C = a1;
  n214_1 = (float)n214;
  unk_25D09A0 = a8;
  unk_25D09A1 = a9;
  n214 = n214_1;
  unk_25D09A2 = a10;
  unk_25D09A3 = a11;
  n355 = (float)n355;
  unk_25D09BA = a7;
  unk_25D09BB = a6;
  v11 = a3;
  if ( FFX_Game_GetRegion() == 1 )
  {
    if ( n355 == 355 && *a3 == 72 && a3[1] == 115 && a3[2] == 120 && a3[3] == -126 && a3[4] == 127 )
      v11 = a3 + 5;
    if ( n214 == 214 && n355 == 187 && *v11 == 104 )
      n214 = 200.0;
  }
  for ( i = *v11; *v11; i = *v11 )
  {
    switch ( sub_8DF600(i) )
    {
      case 1:
        n214 = (float)n214;
        n355 = n355 + 16.0;
        break;
      case 2:
        if ( *v11 == 7 )
        {
          n0xE0 = v11[1];
          if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u )
          {
            v24 = (float)(n0xE0 - 224);
            n214 = v24 + n214;
          }
        }
        else
        {
          if ( *v11 == 10 )
          {
            v20 = unk_25D09BB;
            if ( (v11[1] & 0xF) != 0 )
            {
              v20 = ((v11[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
              unk_25D09BB = v20;
            }
            n0x40 = v11[1] & 0xF0;
            if ( n0x40 >= 0x40u )
              unk_25D09BB = (n0x40 - 64) | v20 & 0xF;
          }
          if ( *v11 == 11 )
          {
            sub_8B1300((unsigned __int8)v11[1], -1);
            v25 = sub_8E5280() + n355 + 4.5;
            sub_8F8EE0((unsigned __int8)v11[1], n214, v25, 0.73000002, a8, a9, a10, a11);
            sub_8FA800((unsigned __int8)v11[1], 0.73000002);
            n214 = 0.73000002 + 1.0 + n214;
            sub_8B12E0();
          }
        }
        break;
      case 3:
        if ( a2 != -1 )
          sub_8E9B80(a2, v11, &unk_25D09A0);
        break;
      case 4:
        sub_8B71F0(v11, &unk_1841D10);
        if ( n355 == 355 )
        {
          Region = FFX_Game_GetRegion();
          n355_1 = n355;
          if ( Region )
            n355_2 = n355_1 + 2.0;
          else
            n355_2 = n355_1 + 1.0;
          n355 = n355_2;
        }
        if ( unk_25D09BA == 1 )
        {
          sub_906260(&unk_25D09A0, &unk_1841D10);
          sub_906270(&unk_25D09A0, &unk_1841D10);
        }
        else
        {
          sub_643CA0(1);
          sub_640F80(0);
          sub_906290(&unk_25D09A0, &unk_1841D10);
          sub_640F80(1);
          sub_906270(&unk_25D09A0, &unk_1841D10);
          sub_643CA0(0);
        }
        sub_8E8ED0((int)&unk_25D09A0, (int)&unk_1841D10, 0.77999997);
        if ( n355 == 355 )
        {
          v16 = FFX_Game_GetRegion();
          n355_3 = n355;
          if ( v16 )
            n355_4 = n355_3 - 2.0;
          else
            n355_4 = n355_3 - 1.0;
          n355 = n355_4;
        }
        break;
      default:
        break;
    }
    v11 = (char *)sub_8DFD70(v11);
  }
  return unk_187168C;
}
