// Function: sub_8E8FB0
// Address: 0x8e8fb0
int __cdecl sub_8E8FB0(
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
        char a11,
        int a12)
{
  char *v12; // esi
  char i; // al
  unsigned __int8 n0xE0; // al
  char v15; // al
  unsigned __int8 n0x40; // cl
  void *v17; // ecx
  _BYTE v19[4]; // [esp+20h] [ebp-8h] BYREF
  _BYTE v20[4]; // [esp+24h] [ebp-4h] BYREF
  float n214; // [esp+30h] [ebp+8h]
  float v22; // [esp+3Ch] [ebp+14h]
  float v23; // [esp+3Ch] [ebp+14h]

  sub_640F60(v19, v20);
  memset(&unk_1841D10, 0, 0x40u);
  v12 = a3;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  unk_187168C = a1;
  n214 = (float)n214_1;
  unk_25D09A0 = a8;
  unk_25D09A1 = a9;
  n214 = n214;
  unk_25D09A2 = a10;
  unk_25D09A3 = a11;
  n355 = (float)n355;
  unk_25D09BA = a7;
  unk_25D09BB = a6;
  for ( i = *a3; *v12; i = *v12 )
  {
    switch ( sub_8DF600(i) )
    {
      case 1:
        n214 = n214;
        n355 = n355 + 16.0;
        break;
      case 2:
        if ( *v12 == 7 )
        {
          n0xE0 = v12[1];
          if ( n0xE0 > 0xE0u && n0xE0 < 0xF0u )
          {
            v22 = (float)(n0xE0 - 224);
            n214 = v22 + n214;
          }
        }
        else
        {
          if ( *v12 == 10 )
          {
            v15 = unk_25D09BB;
            if ( (v12[1] & 0xF) != 0 )
            {
              v15 = ((v12[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
              unk_25D09BB = v15;
            }
            n0x40 = v12[1] & 0xF0;
            if ( n0x40 >= 0x40u )
              unk_25D09BB = (n0x40 - 64) | v15 & 0xF;
          }
          if ( *v12 == 11 )
          {
            sub_8B1300((unsigned __int8)v12[1], -1);
            v23 = sub_8E5280(v17) + n355 + 3.0;
            sub_8F8EE0((unsigned __int8)v12[1], n214, v23, 0.64999998, 128, 128, 128, 128);
            sub_8FA800((unsigned __int8)v12[1], 0.64999998);
            n214 = 0.64999998 + 1.0 + n214;
          }
          sub_8B12E0();
        }
        break;
      case 3:
        if ( a2 != -1 )
          sub_8E9B80(a2, v12, &unk_25D09A0);
        break;
      case 4:
        sub_8B71F0(v12, &unk_1841D10);
        if ( unk_25D09BA != 1 )
        {
          if ( a12 <= 0 )
          {
            sub_8FCCA0(&unk_25D09A0, &unk_1841D10, 0);
            sub_8FCAD0(&unk_25D09A0, &unk_1841D10, 0);
          }
          else
          {
            sub_8FCCA0(&unk_25D09A0, &unk_1841D10, 4);
            sub_8FCAD0(&unk_25D09A0, &unk_1841D10, 5);
          }
          sub_8E8ED0((int)&unk_25D09A0, (int)&unk_1841D10, 0.77999997);
        }
        break;
      default:
        break;
    }
    v12 = (char *)sub_8DFD70(v12);
  }
  return unk_187168C;
}
