// Function: sub_814E80
// Address: 0x814e80
int __cdecl sub_814E80(int a1, int a2)
{
  int v2; // edx
  __int16 v3; // si
  _DWORD *v4; // edi
  float *v5; // ebx
  int v6; // eax
  float *v7; // edi
  int v8; // esi
  int v9; // eax
  _DWORD *v11; // [esp-Ch] [ebp-1Ch]
  float v12; // [esp+Ch] [ebp-4h]
  float *v13; // [esp+18h] [ebp+8h]
  float v14; // [esp+18h] [ebp+8h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+18h] [ebp+8h]
  float v17; // [esp+18h] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(v2 + 162);
  v4 = (_DWORD *)(a1 + 768);
  v11 = (_DWORD *)(a1 + 768);
  v13 = (float *)v2;
  v5 = (float *)sub_800F80(v11, v2, *(_WORD *)(v2 + 160));
  v6 = sub_800F80(v4, (int)v13, v3);
  v7 = v13;
  v8 = v6;
  v9 = ((int)v13[18] & 0xFFF) + 1024;
  v13[36] = flt_C43BE0[v9] * v13[16] * 0.0625 + v5[36];
  v13[38] = flt_C44BE0[v9 & 0xFFF] * v13[16] * 0.0625 + v5[38];
  v13[37] = 0.0625 * v13[17] + v5[37];
  v12 = *(float *)(v8 + 144) - v5[36];
  v14 = *(float *)(v8 + 152) - v5[38];
  v15 = v12 * v12 + v14 * v14;
  v16 = sqrt(fabs(v15));
  v17 = v7[12] * 0.0625 + v16;
  if ( v17 <= 0.0625 * v7[16] )
    *((_WORD *)v7 + 88) |= 0x2000u;
  else
    *((_WORD *)v7 + 88) &= ~0x2000u;
  return a2;
}
