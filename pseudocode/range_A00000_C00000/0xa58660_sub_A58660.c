// Function: sub_A58660
// Address: 0xa58660
// Size: 0x2a0
// Prototype: int(void)

int sub_A58660()
{
  _BYTE *v0; // ecx
  int buf; // esi
  int i; // ebx
  int v3; // eax
  int n136; // edi
  int v5; // eax
  int n76; // edi
  int v7; // eax
  int buf_1; // eax
  __int16 v9; // cx
  int v10; // ecx
  int (__cdecl *v11)(int, int, _DWORD); // edx
  int v12; // ecx

  v0 = (_BYTE *)dword_2305834[0]; /*0xa58660*/
  buf = buf; /*0xa58668*/
  for ( i = 0; i < 12; ++i )
  {
    if ( !*(_BYTE *)(buf + 35) ) /*0xa58675*/
      goto LABEL_57; /*0xa58675*/
    if ( i == 7 ) /*0xa5867e*/
    {
      if ( v0[71106] ) /*0xa58684*/
      {
        if ( v0[71104] ) /*0xa5868d*/
          v3 = 3 - (unsigned __int8)v0[71105]; /*0xa586ab*/
        else
          v3 = (unsigned __int8)v0[71105]; /*0xa58696*/
        n136 = 136 * v3 / 4 + 27; /*0xa586bd*/
        if ( n136 <= 0 ) /*0xa586c2*/
          goto LABEL_13; /*0xa586c2*/
        goto LABEL_12; /*0xa586c2*/
      }
      if ( !v0[71104] ) /*0xa586c6*/
      {
        n136 = 136; /*0xa586cf*/
LABEL_12:
        sub_A58900(buf, n1... [4399 chars total]