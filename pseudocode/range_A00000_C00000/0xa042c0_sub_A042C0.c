// Function: sub_A042C0
// Address: 0xa042c0
// Size: 0x19c
// Prototype: int __cdecl(int, int, int, int, int, int, float, char)

int __cdecl sub_A042C0(int a1, int a2, int a3, int a4, unsigned int a5, int a6, float a7, char a8)
{
  int n15; // ecx
  int v10; // ebx
  unsigned int v11; // esi
  double v12; // st7
  double v13; // st6
  _DWORD *v14; // ecx
  int v15; // edx
  unsigned int v16; // eax
  int v17; // edi
  _DWORD *v18; // ebx
  char *v19; // ecx
  _DWORD *v20; // edx
  int n4; // esi
  bool v22; // zf
  float v23; // [esp+0h] [ebp-74h]
  unsigned int v24; // [esp+18h] [ebp-5Ch]
  int v25; // [esp+1Ch] [ebp-58h]
  char v26; // [esp+20h] [ebp-54h]
  unsigned int v27; // [esp+24h] [ebp-50h]
  _DWORD *v28; // [esp+28h] [ebp-4Ch]
  int v29; // [esp+30h] [ebp-44h] BYREF
  char v30; // [esp+34h] [ebp-40h] BYREF
  unsigned int v31; // [esp+8Ch] [ebp+18h]

  v25 = a1; /*0xa042db*/
  if ( (*(_BYTE *)(a6 + 16) & 1) == 0 ) /*0xa042de*/
    return 5; /*0xa042de*/
  n15 = *(_DWORD *)(a6 + 8); /*0xa042f4*/
  if ( n15 != 15 && n15 != 17 ) /*0xa042ff*/
    return 5; /*0xa042e0*/
  v10 = a3; /*0xa04302*/
  if ( (a3 & ... [2900 chars total]