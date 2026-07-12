// Function: sub_A5BCA0
// Address: 0xa5bca0
// Size: 0xa4

int __cdecl sub_A5BCA0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  unsigned __int8 v6; // al
  char *EntryByIdRange; // eax
  unsigned __int8 v8; // al

  result = dword_2305834[0]; /*0xa5bca3*/
  v4 = a2; /*0xa5bca9*/
  if ( (*(_BYTE *)(dword_2305834[0] + 40 * a2 + 2090) & 3) != 0 ) /*0xa5bcb7*/
  {
    v5 = a3; /*0xa5bcbe*/
    result = sub_A493B0(a1, a2, a3); /*0xa5bcc8*/
    if ( result ) /*0xa5bcd2*/
    {
      result = FFX_Inventory_AddItem(v5, -1); /*0xa5bcd7*/
      if ( !result ) /*0xa5bce1*/
      {
        v6 = FFX_Battle_GetMagicEntryById(v5, &a2)[93]; /*0xa5bced*/
        if ( v6 == 0xFF ) /*0xa5bcf5*/
          EntryByIdRange = 0; /*0xa5bcf7*/
        else
          EntryByIdRange = FFX_Table_GetEntryByIdRange(v6, (__int16 *)unk_1A860E4, &a2); /*0xa5bd09*/
        v8 = EntryByIdRange[13]; /*0xa5bd11*/
        if ( v8 ) /*0xa5bd16*/
        {
          return sub_A5CF30(v8, v4, a1); /*0xa5bd1e*/
        }
        else
        {
     ... [1162 chars total]