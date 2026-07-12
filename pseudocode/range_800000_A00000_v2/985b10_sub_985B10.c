// Function: sub_985B10
// Address: 0x985b10
int __userpurge sub_985B10@<eax>(int a1@<ecx>, int a2@<ebp>, float *a3, int a4, int a5, int a6)
{
  double v6; // st7
  int v7; // eax
  double v8; // st7
  double v9; // st4
  double v10; // st4
  double v11; // st6
  double v12; // st5
  int v13; // ecx
  _DWORD v15[12]; // [esp-60h] [ebp-6Ch] BYREF
  float v16; // [esp-30h] [ebp-3Ch]
  float v17; // [esp-2Ch] [ebp-38h]
  float v18; // [esp-28h] [ebp-34h]
  int v19; // [esp-24h] [ebp-30h]
  _DWORD v20[2]; // [esp-14h] [ebp-20h] BYREF
  float v21; // [esp-Ch] [ebp-18h]
  float v22; // [esp-8h] [ebp-14h]
  float v23; // [esp-4h] [ebp-10h]
  int v24; // [esp+0h] [ebp-Ch]
  void *v25; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v24 = a2;
  v25 = retaddr;
  v20[0] = a5;
  v20[1] = a6;
  v6 = a3[1];
  v19 = 0;
  v23 = v6;
  v15[8] = a4;
  v22 = *a3;
  v7 = *(_DWORD *)(a1 + 68);
  v21 = a3[2];
  v15[0] = v7;
  v8 = *(float *)(a1 + 84);
  v15[1] = v20;
  v16 = *(float *)(a1 + 88) * v21 + v8 * v23 + v22 * *(float *)(a1 + 80);
  v9 = *(float *)(a1 + 100);
  *(float *)&v15[4] = v16;
  v17 = v9 * v23 + *(float *)(a1 + 96) * v22 + *(float *)(a1 + 104) * v21;
  v10 = *(float *)(a1 + 116);
  *(float *)&v15[5] = v17;
  v11 = v23 * v10 + v22 * *(float *)(a1 + 112);
  v12 = *(float *)(a1 + 120);
  v13 = *(_DWORD *)(a1 + 64);
  v18 = v21 * v12 + v11;
  *(float *)&v15[6] = v18;
  v15[7] = 0;
  return (*(int (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v13 + 8))(v13, v15, 1);
}
