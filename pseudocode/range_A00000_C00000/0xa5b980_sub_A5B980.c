// Function: sub_A5B980
// Address: 0xa5b980
// Size: 0x147

int __cdecl sub_A5B980(int a1, unsigned __int16 a2, __int16 a3)
{
  float v3; // ecx
  int v4; // ecx
  _BYTE *v5; // eax
  __int16 *v6; // esi
  __int64 v7; // rax
  float v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = v3; /*0xa5b983*/
  v4 = *(__int16 *)(dword_2305834[0] + 2); /*0xa5b989*/
  if ( *(_WORD *)(dword_2305834[0] + 2) ) /*0xa5b989*/
  {
    v5 = (_BYTE *)(dword_2305834[0] + 2090); /*0xa5b991*/
    do /*0xa5b9af*/
    {
      --v4; /*0xa5b9a0*/
      if ( *((_WORD *)v5 - 14) != 0xFFFF ) /*0xa5b9a5*/
        *v5 &= 0xFCu; /*0xa5b9a7*/
      v5 += 40; /*0xa5b9aa*/
    }
    while ( v4 ); /*0xa5b9af*/
  }
  sub_A5B400(a1, a2, a3, 3); /*0xa5b9be*/
  *(_DWORD *)(dword_2305834[0] + 71328) = 0; /*0xa5b9cd*/
  *(_DWORD *)(dword_2305834[0] + 71324) = 0; /*0xa5b9dc*/
  *(_DWORD *)(dword_2305834[0] + 71080) = sub_A452D0; /*0xa5b9eb*/
  *(_DWORD *)(dword_2305834[0] + 71084) = sub_A45500; /*0xa5b9fa*/
  v6 = sub_A56A40( /*0xa5ba2f*/
         &v9,
         (float *)(dword_2305834[0] + 69768 + 80... [1901 chars total]