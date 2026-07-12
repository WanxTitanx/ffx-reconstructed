// Function: sub_8EA060
// Address: 0x8ea060
_DWORD *__cdecl sub_8EA060(_DWORD *a1, char *a2, int n214, int n355, char a5, char n128, char a7, char a8, char a9)
{
  char *v9; // esi
  char v10; // al
  int n2; // eax
  char v12; // al
  unsigned __int8 n0x40; // cl

  memset(&unk_1841D10, 0, 0x40u);
  v9 = a2;
  unk_25D09B8 = 0;
  n214 = (float)n214;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  n355 = (float)n355;
  n128 = n128;
  unk_25D09A1 = a7;
  unk_25D09A2 = a8;
  unk_25D09A3 = a9;
  unk_25D09BB = a5;
  v10 = *a2;
  dword_187168C = a1;
  if ( !v10 )
    return a1;
  do
  {
    n2 = sub_8DF600(v10) - 2;
    if ( n2 )
    {
      if ( n2 == 2 )
      {
        sub_8B71F0(v9, &unk_1841D10);
        sub_906290(&n128, &unk_1841D10);
        sub_906270(&n128, &unk_1841D10);
        n214 = unk_1841D2C + 1.0 + n214;
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
        sub_8B1300((unsigned __int8)v9[1], -1);
        dword_187168C = (_DWORD *)sub_8E9970((int)dword_187168C, (unsigned __int8)v9[1], (int)n214, (int)n355);
        n214 = n214 + 22.0;
      }
      sub_8B12E0();
    }
    v9 = (char *)sub_8DFD70(v9);
    v10 = *v9;
  }
  while ( *v9 );
  return dword_187168C;
}
