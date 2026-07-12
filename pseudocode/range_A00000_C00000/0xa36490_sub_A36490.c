// Function: sub_A36490
// Address: 0xa36490
// Size: 0xf5

int __cdecl sub_A36490(int a1, int *a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // edx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int result; // eax
  int v14; // edi
  double v15; // st7
  float v16; // [esp+4h] [ebp-38h]
  int v17[2]; // [esp+24h] [ebp-18h] BYREF
  int v18; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+30h] [ebp-Ch]
  float v20; // [esp+34h] [ebp-8h]
  float v21; // [esp+38h] [ebp-4h]
  int v22; // [esp+4Ch] [ebp+10h]

  v6 = (int)a2; /*0xa36496*/
  v8 = *(_DWORD *)(a3 + 28); /*0xa364a4*/
  v21 = (float)a2[2]; /*0xa364a7*/
  v22 = v8; /*0xa364b1*/
  v21 = 1.0 / v21; /*0xa364bb*/
  v20 = (float)a2[3]; /*0xa364c1*/
  v9 = a2[1]; /*0xa364cf*/
  v10 = a5[1]; /*0xa364d5*/
  v17[0] = (*a5 - 1) & ((*a5 - 1 <= 0) - 1); /*0xa364d8*/
  v11 = (v10 - 1) & ((v10 - 1 <= 0) - 1); /*0xa364e4*/
  v12 = *a2; /*0xa364e6*/
  v17[1] = v11; /*0xa364e8*/
  v18 = a5[2] + 1; /*0xa364ef*/
  v20 = 1.0 / v20; /*0xa364f2*/
  if ( v18 >= v12 ) /*... [1712 chars total]