// Function: sub_A45FD0
// Address: 0xa45fd0
// Size: 0xc9
// Prototype: _DWORD __cdecl(int n8, int n3)

char *__cdecl sub_A45FD0(int n8, int n3)
{
  char *i_1; // eax
  int i_3; // ebx
  int v4; // eax
  __int16 v5; // si
  int v6; // eax
  __int16 n64; // si
  int v8; // edx
  int n64_1; // ecx
  __int16 v10; // si
  int v11; // edi
  int v12; // [esp+4h] [ebp-Ch] BYREF
  char *i; // [esp+8h] [ebp-8h]
  char *i_2; // [esp+Ch] [ebp-4h]

  sub_8C6700(n3); /*0xa45fda*/
  i_1 = (char *)sub_8C66D0(); /*0xa45fe2*/
  i_3 = 0; /*0xa45fe7*/
  for ( i = i_1; i_3 < (int)i; ++i_3 ) /*0xa45fee*/
  {
    v4 = sub_8C66E0(i_3); /*0xa45ff7*/
    v5 = v4; /*0xa45ffc*/
    i_1 = (char *)FFX_Inventory_GetItemCount(v4); /*0xa45fff*/
    if ( (int)i_1 > 0 ) /*0xa46009*/
    {
      i_1 = FFX_Battle_GetMagicEntryById(v5, &v12); /*0xa46010*/
      if ( i_1[93] != -1 ) /*0xa4601c*/
      {
        v6 = unk_1A86108 + 832 * n8; /*0xa46027*/
        LOWORD(i_2) = v5; /*0xa4602d*/
        n64 = *(_WORD *)(v6 + 30); /*0xa46031*/
        if ( n64 < 64 ) /*0xa46039*/
        {
          v8 = *(unsigned __int8 *)(v6 + ... [1689 chars total]