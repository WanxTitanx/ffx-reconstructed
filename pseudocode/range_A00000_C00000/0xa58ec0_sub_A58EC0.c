// Function: sub_A58EC0
// Address: 0xa58ec0
// Size: 0x121
// Prototype: int(void)

int sub_A58EC0()
{
  int result; // eax
  __int16 v1; // cx

  result = dword_2305834[0]; /*0xa58ec0*/
  if ( !*(_DWORD *)(dword_2305834[0] + 71088) ) /*0xa58ec5*/
  {
    v1 = *(_WORD *)(dword_2305834[0] + 71282); /*0xa58ed2*/
    if ( (v1 & 4) != 0 ) /*0xa58edc*/
    {
      sub_8AAF50(); /*0xa58ede*/
      *(_BYTE *)(dword_2305834[0] + 71102) = 1; /*0xa58ee8*/
    }
    else
    {
      if ( (v1 & 8) == 0 ) /*0xa58ef4*/
        return sub_A5B030(); /*0xa58fdb*/
      *(_BYTE *)(dword_2305834[0] + 71102) = 2; /*0xa58efa*/
      sub_8AAEC0(); /*0xa58f01*/
    }
    *(_BYTE *)(dword_2305834[0] + 71103) = 0; /*0xa58f0b*/
    *(_BYTE *)(dword_2305834[0] + 71101) = *(_BYTE *)(dword_2305834[0] + 71100); /*0xa58f1f*/
    *(_BYTE *)(dword_2305834[0] + 71100) = FFX_Party_GetMenuSlotIndex(); /*0xa58f30*/
    if ( *(_BYTE *)(dword_2305834[0] + 71101) == *(_BYTE *)(dword_2305834[0] + 71100) ) /*0xa58f49*/
    {
      *(_BYTE *)(dword_2305834[0] + 71102) = 0; /*0xa58f4b*/
    }
    else
    {
   ... [1752 chars total]