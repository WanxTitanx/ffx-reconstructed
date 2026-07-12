// Function: sub_8EA680
// Address: 0x8ea680
_DWORD *__cdecl sub_8EA680(
        _DWORD *a1,
        int a2,
        char *a3,
        int n214_1,
        int n355,
        char a6,
        char n128,
        char a8,
        char a9,
        char a10)
{
  char *v10; // esi
  char i; // al
  char n11; // al
  char n0x50; // cl
  char v14; // al
  unsigned __int8 n0x40; // cl
  float n214; // [esp+Ch] [ebp+8h]

  memset(&unk_1841D10, 0, 0x40u);
  v10 = a3;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  dword_187168C = a1;
  n214 = (float)n214_1;
  ::n128 = n128;
  unk_25D09A1 = a8;
  n214 = n214;
  unk_25D09A2 = a9;
  unk_25D09A3 = a10;
  n355 = (float)n355;
  unk_25D09BB = a6;
  for ( i = *a3; *v10; i = *v10 )
  {
    switch ( sub_8DF600(i) )
    {
      case 1:
        n214 = (float)n214_1;
        n355 = n355 + 16.0;
        break;
      case 2:
        n11 = *v10;
        if ( *v10 == 16 )
        {
          n0x50 = v10[1];
          if ( (unsigned __int8)n0x50 >= 0x50u && (unsigned __int8)n0x50 <= 0x57u )
            goto LABEL_16;
        }
        if ( n11 == 10 )
        {
          v14 = unk_25D09BB;
          if ( (v10[1] & 0xF) != 0 )
          {
            v14 = ((v10[1] & 0xF) - 1) | unk_25D09BB & 0xF0;
            unk_25D09BB = v14;
          }
          n0x40 = v10[1] & 0xF0;
          if ( n0x40 >= 0x40u )
            unk_25D09BB = (n0x40 - 64) | v14 & 0xF;
        }
        else if ( n11 == 11 )
        {
          sub_8B1300((unsigned __int8)v10[1], -1);
          dword_187168C = (_DWORD *)sub_8E9970((int)dword_187168C, (unsigned __int8)v10[1], (int)n214, (int)n355);
          n214 = n214 + 22.0;
        }
        else
        {
          sub_8B12E0();
        }
        break;
      case 3:
LABEL_16:
        sub_8E9B80(a2, (int)v10, (int)&::n128);
        break;
      case 4:
        sub_8B71F0(v10, &unk_1841D10);
        sub_906290(&::n128, &unk_1841D10);
        sub_906270(&::n128, &unk_1841D10);
        n214 = unk_1841D2C + 1.0 + n214;
        break;
      default:
        break;
    }
    v10 = (char *)sub_8DFD70(v10);
  }
  return dword_187168C;
}
