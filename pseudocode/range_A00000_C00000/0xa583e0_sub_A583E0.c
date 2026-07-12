// Function: sub_A583E0
// Address: 0xa583e0
// Size: 0x27a
// Prototype: int(void)

__int16 sub_A583E0()
{
  int buf; // edx
  __int16 result; // ax
  int v2; // esi
  __int16 v3; // bx
  __int16 v4; // ax
  __int16 v5; // di
  __int16 v6; // ax
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // bx
  __int16 v10; // di
  __int16 v11; // ax
  __int16 v12; // ax
  int v13; // edi
  int v14; // ecx
  int v15; // edi
  bool v16; // zf
  int v17; // edi
  char v18; // al
  int buf_1; // ecx

  buf = buf; /*0xa583e0*/
  result = *(_WORD *)(buf + 9984); /*0xa583e6*/
  if ( result < 0 ) /*0xa583f0*/
    return result; /*0xa583f0*/
  v2 = buf + 832 * result; /*0xa58400*/
  if ( *(_BYTE *)(v2 + 38) ) /*0xa58402*/
    return result; /*0xa58406*/
  v3 = *(_WORD *)(dword_2305834[0] + 71284); /*0xa58412*/
  v4 = *(_WORD *)(v2 + 22); /*0xa58419*/
  v5 = *(_WORD *)(v2 + 30); /*0xa5841e*/
  if ( v5 <= v4 ) /*0xa58425*/
    goto LABEL_14; /*0xa58425*/
  if ( (v3 & 1) != 0 ) /*0xa5842e*/
  {
    if ( *(__int16 *)(v2 + 26) > 0 ) /*0xa58435*/
    {
      FFX_BtlEffect_Enable(-214748... [5087 chars total]