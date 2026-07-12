// Function: sub_8EBD80
// Address: 0x8ebd80
_DWORD *__cdecl sub_8EBD80(_DWORD *a1, int a2, int n214, int n355, char a5)
{
  unsigned __int8 *i; // esi
  char Buffer[32]; // [esp+4h] [ebp-24h] BYREF

  memset(&unk_1841D10, 0, 0x40u);
  n128 = 0;
  n214 = 0.0;
  n355 = 0.0;
  unk_25D09AC = 0;
  unk_25D09B0 = 0;
  unk_25D09B4 = 0;
  unk_25D09B8 = 0;
  dword_187168C = a1;
  sprintf(Buffer, "%d", a2);
  n214 = (float)n214;
  n128 = -2139062144;
  unk_25D09BA = 0;
  unk_25D09BB = a5;
  n355 = (float)n355;
  for ( i = (unsigned __int8 *)Buffer; *i; i = (unsigned __int8 *)sub_8DFD70(i) )
  {
    sub_89E2D0(i, (int)&unk_1841D10);
    sub_8FC770(&n128, &unk_1841D10);
  }
  return dword_187168C;
}
