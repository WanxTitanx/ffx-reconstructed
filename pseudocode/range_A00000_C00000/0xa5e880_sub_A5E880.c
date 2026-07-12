// Function: sub_A5E880
// Address: 0xa5e880
// Size: 0x1aa
// Prototype: _DWORD __cdecl(_DWORD, int n4, _DWORD *, _DWORD *)

_DWORD *__cdecl sub_A5E880(int n99999999, int n4, _DWORD *a3, _DWORD *a4)
{
  int *v4; // esi
  int n4_1; // ecx
  int v6; // ebx
  int v7; // edi
  int n4_2; // eax
  int n99999999_1; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  _DWORD *v17; // [esp+Ch] [ebp-20h]
  int v18; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+20h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-8h]
  int v21; // [esp+28h] [ebp-4h]

  v17 = (_DWORD *)a3[2]; /*0xa5e89a*/
  v4 = v17 + 16; /*0xa5e89d*/
  v19 = a4[1]; /*0xa5e8a3*/
  n4_1 = n4; /*0xa5e8c4*/
  v6 = *((unsigned __int8 *)a4 + 26) * *((unsigned __int16 *)a3 + 8) - 8 * (*((_WORD *)a4 + 11) & 0xFFFE) + 0x8000; /*0xa5e8d5*/
  v21 = 0; /*0xa5e8de*/
  v18 = 0; /*0xa5e8e5*/
  v20 = *((unsigned __int8 *)a4 + 27) * *((unsigned __int16 *)a3 + 9) - 8 * (a4[6] & 0xFFFE) + 0x8000; /*0xa5e8ec*/
  v7 = 1; /*0xa5e8ef*/
  if ( n4 > 0 ) /*0xa5e8f6*/
  {
    n4_2 = n4; /*0xa5e8f8*/
    do /*0xa5e906*/
    {
    ... [2684 chars total]