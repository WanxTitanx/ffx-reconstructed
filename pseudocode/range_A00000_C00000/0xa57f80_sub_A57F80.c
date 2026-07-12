// Function: sub_A57F80
// Address: 0xa57f80
// Size: 0xfa
// Prototype: int __cdecl(int n7, int, float, int, int, int)

int __cdecl sub_A57F80(int n7, int a2, float a3, int a4, int a5, int a6)
{
  int v6; // edx
  int v7; // edi
  int v8; // eax
  double v9; // st7
  double v11; // [esp+Ch] [ebp-8h]
  int v12; // [esp+20h] [ebp+Ch]

  v6 = dword_2305834[0]; /*0xa57f86*/
  v7 = 80 * n7 + dword_2305834[0] + 69768; /*0xa57fa4*/
  *(_WORD *)(v7 + 68) = a2; /*0xa57fa6*/
  *(float *)v7 = (float)*(__int16 *)(v6 + 40 * a2 + 2056); /*0xa57fb8*/
  *(float *)(v7 + 4) = (float)*(__int16 *)(v6 + 40 * a2 + 2058); /*0xa57fc8*/
  *(float *)(v7 + 8) = 0.0; /*0xa57fcd*/
  *(float *)(v7 + 12) = 1.0; /*0xa57fd2*/
  v11 = (double)(*(__int16 *)(dword_2305834[0] + 48 * *(unsigned __int16 *)(dword_2305834[0] + 40 * a2 + 2062) + 63540) >> 1); /*0xa57ffd*/
  *(_DWORD *)(v7 + 32) = a4; /*0xa58003*/
  *(_DWORD *)(v7 + 36) = a5; /*0xa5800f*/
  *(float *)(v7 + 60) = v11 + 3.0; /*0xa58015*/
  *(_BYTE *)(v7 + 78) = 0; /*0xa58018*/
  *(_DWORD *)(v7 + 40) = a6; /*0xa5801f*/
  *(float *)(v7 + 64) = a3; /*0xa58022*/
  if ( n7 <= 6 ) /*0xa... [1402 chars total]