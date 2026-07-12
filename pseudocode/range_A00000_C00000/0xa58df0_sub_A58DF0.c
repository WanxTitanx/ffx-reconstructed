// Function: sub_A58DF0
// Address: 0xa58df0
// Size: 0xcb
// Prototype: _DWORD __cdecl(char n2)

unsigned __int16 *__cdecl sub_A58DF0(char n2)
{
  unsigned __int16 *result; // eax
  int v2; // edi
  int v3; // esi
  int v4; // eax
  unsigned int i; // ecx
  unsigned int i_2; // edx
  unsigned int i_1; // eax
  int v8; // eax
  bool v9; // cc
  int v10; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h]

  result = 0; /*0xa58df6*/
  v2 = dword_2305834[0]; /*0xa58dfa*/
  v3 = 0; /*0xa58e00*/
  if ( *(__int16 *)(dword_2305834[0] + 2) > 0 ) /*0xa58e06*/
  {
    result = (unsigned __int16 *)(dword_2305834[0] + 2062); /*0xa58e0c*/
    v11 = dword_2305834[0] + 2062; /*0xa58e16*/
    do /*0xa58eae*/
    {
      v4 = *result; /*0xa58e20*/
      if ( (_WORD)v4 != 0xFFFF ) /*0xa58e26*/
      {
        if ( *((__int16 *)FFX_Table_GetEntryByIdRange(v4, (__int16 *)unk_1A860E0, &v10) + 8) >= 0 ) /*0xa58e44*/
        {
          v2 = dword_2305834[0]; /*0xa58e95*/
        }
        else
        {
          for ( i = 0; ; i = i_1 ) /*0xa58e46*/
          {
            v2 = dword_2305834[0]... [1910 chars total]