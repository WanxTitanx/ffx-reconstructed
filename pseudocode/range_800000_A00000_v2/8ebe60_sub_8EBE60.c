// Function: sub_8EBE60
// Address: 0x8ebe60
_DWORD *__cdecl sub_8EBE60(_DWORD *a1, int a2, int a3, int n355, char a5)
{
  unsigned __int8 *Buffer_1; // esi
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
  n128 = -2139062144;
  unk_25D09BA = 0;
  unk_25D09BB = a5;
  n214 = (float)(int)(a3 - 11 * strlen(Buffer));
  Buffer_1 = (unsigned __int8 *)Buffer;
  for ( n355 = (float)n355; *Buffer_1; Buffer_1 = (unsigned __int8 *)sub_8DFD70(Buffer_1) )
  {
    sub_89E2D0(Buffer_1, (int)&unk_1841D10);
    sub_8FC770(&n128, &unk_1841D10);
  }
  return dword_187168C;
}
