// Function: sub_8ED190
// Address: 0x8ed190
_DWORD *__cdecl sub_8ED190(
        _DWORD *a1,
        _BYTE *a2,
        int n214,
        int n355,
        char a5,
        char n128,
        char a7,
        char a8,
        char a9,
        int a10,
        int n4)
{
  _BYTE *v11; // edi
  bool v12; // zf
  double v13; // st7
  double v14; // st7
  float n4_1; // [esp+Ch] [ebp+8h]
  float n4_2; // [esp+Ch] [ebp+8h]

  memset(word_1841D10, 0, 0x40u);
  v11 = a2;
  unk_25D09B8 = 0;
  n214 = (float)n214;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  n355 = (float)n355;
  ::n128 = n128;
  unk_25D09A1 = a7;
  unk_25D09A2 = a8;
  unk_25D09A3 = a9;
  unk_25D09BB = a5;
  v12 = *a2 == 0;
  dword_187168C = a1;
  if ( v12 )
    return a1;
  do
  {
    sub_8B7860(v11, word_1841D10, a10);
    if ( n4 <= 0 )
    {
      sub_8FCCA0((float *)&::n128, word_1841D10, n4);
      sub_8FCAD0((int *)&::n128, word_1841D10, n4);
    }
    else
    {
      n4_1 = (float)n4;
      v13 = 100.0 / n4_1;
      unk_1841D2C = unk_1841D2C * v13;
      unk_1841D30 = v13 * unk_1841D30;
      sub_8FCCA0((float *)&::n128, word_1841D10, 4);
      sub_8FCAD0((int *)&::n128, word_1841D10, 5);
    }
    if ( n4 <= 0 )
    {
      v14 = unk_1841D2C * flt_C5D778 + 1.0 + unk_1871698;
    }
    else
    {
      n4_2 = (float)n4;
      v14 = 100.0 / n4_2 * (unk_1871698 + 1.0) + unk_1841D2C * flt_C5D778 * 0.6000000238418579;
    }
    n214 = v14 + n214;
    v11 = (_BYTE *)sub_8DFD70(v11);
  }
  while ( *v11 );
  return dword_187168C;
}
