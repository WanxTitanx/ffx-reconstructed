// Function: sub_A5EEA0
// Address: 0xa5eea0
// Size: 0x118
// Prototype: _DWORD __cdecl(_DWORD, int n4, _DWORD *, _DWORD *)

_DWORD *__cdecl sub_A5EEA0(int a1, int n4, _DWORD *a3, _DWORD *a4)
{
  int *v4; // esi
  int v6; // ecx
  int v7; // edi
  _DWORD *result; // eax
  int v9; // edi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // [esp+Ch] [ebp-4h]
  _DWORD *v14; // [esp+24h] [ebp+14h]

  v4 = (int *)(a3[2] + 64); /*0xa5eeb2*/
  sub_A5E7B0((_DWORD *)a3[2], n4, 1); /*0xa5eeb6*/
  v6 = *((unsigned __int16 *)a3 + 8); /*0xa5eebe*/
  v13 = a4[1]; /*0xa5eec8*/
  v7 = *((unsigned __int8 *)a4 + 26) * (v6 + n4 - 1) - 8 * (*((_WORD *)a4 + 11) & 0xFFFE); /*0xa5eee1*/
  v14 = (_DWORD *)(*((unsigned __int8 *)a4 + 27) * *((unsigned __int16 *)a3 + 9) - 8 * (a4[6] & 0xFFFE) + 0x8000); /*0xa5ef0c*/
  result = (_DWORD *)(v6 + n4); /*0xa5ef13*/
  v9 = v7 + 0x8000; /*0xa5ef19*/
  *((_WORD *)a3 + 8) = v6 + n4; /*0xa5ef1f*/
  if ( n4 <= 0 ) /*0xa5ef25*/
  {
    a3[3] = v4; /*0xa5efaf*/
  }
  else
  {
    do /*0xa5ef9f*/
    {
      v10 = a1 & 0xF; /*0xa5ef33*/
      a1 >>= 4; /*0xa5ef36*/
      v11 = dword_... [1784 chars total]