// Function: sub_8E9F20
// Address: 0x8e9f20
_DWORD *__cdecl sub_8E9F20(_DWORD *a1, unsigned __int8 *i_1, int n214, int n355, char a5)
{
  unsigned __int8 *i; // esi
  bool v6; // zf

  memset(&unk_1841D10, 0, 0x40u);
  i = i_1;
  n214 = (float)n214;
  unk_25D09B8 = 0;
  unk_25D09AC = 0;
  n355 = (float)n355;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  n128 = -2139062144;
  unk_25D09BB = a5;
  v6 = *i_1 == 0;
  dword_187168C = a1;
  if ( v6 )
    return a1;
  do
  {
    sub_89E2D0(i, (int)&unk_1841D10);
    sub_8FC770(&n128, &unk_1841D10);
    i = (unsigned __int8 *)sub_8DFD70(i);
  }
  while ( *i );
  return dword_187168C;
}
