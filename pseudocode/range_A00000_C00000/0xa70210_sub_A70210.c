// Function: sub_A70210
// Address: 0xa70210
// Size: 0x3d8

int __cdecl sub_A70210(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  int v6; // esi
  int v7; // eax
  _DWORD *v8; // edi
  int i_1; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v14; // [esp+10h] [ebp-64h]
  int i; // [esp+14h] [ebp-60h]
  float v16; // [esp+1Ch] [ebp-58h]
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  v5 = sub_7E6910(6144); /*0xa70237*/
  *(_DWORD *)a1 |= 4u; /*0xa7023c*/
  v14 = v5; /*0xa70242*/
  v6 = sub_A69940(a1, a2, v5); /*0xa7024a*/
  v7 = sub_A68FF0(); /*0xa7024c*/
  v16 = (double)*(unsigned __int8 *)(v6 + 76) * 0.0078125; /*0xa70271*/
  *(float *)(v14 + 880) = (double)(unsigned __int8)v7 * v16 + (double)*(unsigned __int8 *)(v6 + 28) * (1.0 - v16); /*0xa7029f*/
  *(float *)(v14 + 884) = (double)*(unsigned __int8 *)(v6 + 29) * (1.0 - v16) + (double)BYTE1(v7) * v16; /*0xa702cb*/
  *(float *)(v14 + 888) = (double)*(unsigned __int8 *)(v6 + 30) * (1.0 - v16) + (double)BYTE2(v7) * v16; /*0xa702f7*/
  *(float *)(v14 + 892) = v16 ... [3454 chars total]