// Function: sub_8E4E60
// Address: 0x8e4e60
int __cdecl sub_8E4E60(
        int a1,
        int a2,
        char *a3,
        int n214_2,
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
  double n355_3; // st7
  double n355_4; // st7
  int v16; // eax
  double n355_5; // st7
  unsigned __int8 n0xE0; // al
  char v19; // al
  unsigned __int8 n0x40; // cl
  double v21; // st7
  int n0x34_1; // eax
  double v23; // st7
  unsigned __int8 n0x34; // cl
  double n355_1; // st7
  float v27; // [esp+4h] [ebp-1Ch]
  float v28; // [esp+8h] [ebp-18h]
  char v29; // [esp+Ch] [ebp-14h]
  char v30; // [esp+10h] [ebp-10h]
  char v31; // [esp+14h] [ebp-Ch]
  char v32; // [esp+18h] [ebp-8h]
  float n214; // [esp+28h] [ebp+8h]
  float v34; // [esp+28h] [ebp+8h]
  float v35; // [esp+28h] [ebp+8h]
  float n355_2; // [esp+28h] [ebp+8h]
  float v37; // [esp+28h] [ebp+8h]
  float n214_1; // [esp+34h] [ebp+14h]

  memset(&unk_1841D10, 0, 0x40u);
  v11 = a3;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  unk_187168C = a1;
  n214 = (float)n214_2;
  unk_25D09A0 = a8;
  n214_1 = n214;
  unk_25D09A1 = a9;
  n214 = n214;
  unk_25D09A2 = a10;
  unk_25D09A3 = a11;
  n355 = (float)n355;
  unk_25D09BA = a7;
  unk_25D09BB = a6;
  for ( i = *a3; *v11; i = *v11 )
  {
    switch ( sub_8DF600(i) )
    {
      case 1:
        n214 = n214_1;
        n355 = n355 + 16.0;
        break;
      case 2:
        if ( *v11 == 7 )
        {
          n0xE0 = v11[1];
          if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u )
          {
            v34 = (float)(n0xE0 - 224);
            n214 = v34 + n214;
          }
        }
        else
        {
          if ( *v11 == 10 )
          {
            v19 = unk_25D09BB;
            if ( (v11[1] & 0xF) != 0 )
            {
              v19 = ((v11[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
              unk_25D09BB = v19;
            }
            n0x40 = v11[1] & 0xF0;
            if ( n0x40 >= 0x40u )
              unk_25D09BB = (n0x40 - 64) | v19 & 0xF;
          }
          if ( *v11 == 11 )
          {
            sub_8B1300((unsigned __int8)v11[1], -1);
            if ( FFX_Game_GetRegion() )
            {
              n0x34 = v11[1];
              n355_1 = n355;
              if ( n0x34 >= 0x34u && n0x34 <= 0x37u
                || n0x34 == 32
                || n0x34 == 33
                || n0x34 == 34
                || n355_1 < 350.0 && (n0x34 == 72 || n0x34 == 48)
                || n0x34 == 66 )
              {
                n355_2 = n355_1 - 2.5;
                n355_1 = n355_2;
              }
              v32 = a11;
              n0x34_1 = n0x34;
              v31 = a10;
              v30 = a9;
              v29 = a8;
              v28 = 0.73000002;
              v37 = n355_1 + 5.0;
              v23 = v37;
            }
            else
            {
              v32 = a11;
              v31 = a10;
              v30 = a9;
              v29 = a8;
              v28 = 0.73000002;
              v21 = sub_8E5280();
              n0x34_1 = (unsigned __int8)v11[1];
              v35 = v21 + n355 + 4.0;
              v23 = v35;
            }
            v27 = v23;
            sub_8F8EE0(n0x34_1, n214, v27, v28, v29, v30, v31, v32);
            sub_8FA800((unsigned __int8)v11[1], 0.73000002);
            n214 = 0.73000002 + 1.0 + n214;
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
        }
        else
        {
          if ( n355 == 355 )
          {
            Region = FFX_Game_GetRegion();
            n355_3 = n355;
            if ( Region )
              n355_4 = n355_3 + 3.0;
            else
              n355_4 = n355_3 + 1.0;
            n355 = n355_4;
          }
          sub_643CA0(1);
          sub_640F80(0);
          sub_906290(&unk_25D09A0, &unk_1841D10);
          sub_640F80(1);
          sub_906270(&unk_25D09A0, &unk_1841D10);
          sub_643CA0(0);
          if ( n355 == 355 )
          {
            v16 = FFX_Game_GetRegion();
            n355_5 = n355;
            if ( v16 )
              n355 = n355_5 - 3.0;
            else
              n355 = n355_5 - 1.0;
          }
        }
        sub_8E8ED0((int)&unk_25D09A0, (int)&unk_1841D10, 0.77999997);
        break;
      default:
        break;
    }
    v11 = (char *)sub_8DFD70(v11);
  }
  return unk_187168C;
}
