// Function: sub_A74D30
// Address: 0xa74d30
// Size: 0x43d
// Prototype: 

int __usercall sub_A74D30@<eax>(int a1@<ebp>, __int64 *a2, int a3)
{
  int v3; // ecx
  unsigned int n12288; // eax
  __int64 *v5; // edi
  int v6; // eax
  int v8; // ecx
  __int16 v9; // ax
  _WORD *v10; // ecx
  unsigned int v11; // edi
  int v12; // eax
  int v13; // ecx
  __int16 v14; // ax
  int v15; // ecx
  unsigned __int64 v16; // rdi
  int v17; // [esp-24h] [ebp-E4h]
  unsigned int v18; // [esp+10h] [ebp-B0h]
  float v19; // [esp+18h] [ebp-A8h]
  float v20; // [esp+18h] [ebp-A8h]
  int v21; // [esp+1Ch] [ebp-A4h]
  _BYTE v22[16]; // [esp+24h] [ebp-9Ch] BYREF
  float v23; // [esp+34h] [ebp-8Ch] BYREF
  int v24; // [esp+38h] [ebp-88h]
  int v25; // [esp+3Ch] [ebp-84h]
  float v26; // [esp+40h] [ebp-80h]
  float v27; // [esp+44h] [ebp-7Ch] BYREF
  int v28; // [esp+48h] [ebp-78h]
  int v29; // [esp+4Ch] [ebp-74h]
  float v30; // [esp+50h] [ebp-70h]
  __int16 v31; // [esp+5Ch] [ebp-64h] BYREF
  __int16 v32; // [esp+5Eh] [ebp-62h]
  _BYTE v33[6]; // [esp+60h] [ebp-60h]
  void *v34; // [esp+66h] [ebp-5Ah]
  _DWORD v35[21]; // [esp+6Ch] [ebp-54h] BYREF
  _UNKNOWN *retaddr; // [esp+C0h] [ebp+0h]

  v35[18] = a1;
  v35[19] = retaddr;
  v3 = *((_DWORD *)a2 + 136);
  n12288 = *((_WORD *)a2 + 269) & 0xF000;
  v21 = v3;
  if ( n12288 > 0x2000 )
  {
    if ( n12288 == 12288 )
    {
      v13 = *(__int16 *)(a3 + 2);
      *(_WORD *)a2 = *(_WORD *)(v13 + a3);
      v14 = *(_WORD *)(v13 + a3 + 2);
      v15 = a3 + v13;
      *((_WORD *)a2 + 1) = v14;
      *((_WORD *)a2 + 2) = *(_WORD *)(v15 + 4);
      *((_WORD *)a2 + 3) = *(_WORD *)(v15 + 6);
      v16 = *a2;
      v31 = *a2 & 0x3FFF;
      v32 = (1 << ((v16 >> 26) & 0xF)) / 64;
      *(_WORD *)&v33[4] = 0;
      *(_DWORD *)v33 = (v16 >> 20) & 0x3F;
      v34 = &unk_1000100;
      sub_7E4330(&v31, *(_DWORD *)(v21 + 188));
      sub_643A70(v31);
      return a3 + 4;
    }
    return a3;
  }
  if ( n12288 != 0x2000 )
  {
    if ( (*((_WORD *)a2 + 269) & 0xF000) == 0 )
    {
      sub_908420(109051904, 0);
      return a3 + 2;
    }
    if ( n12288 == 4096 )
    {
      v5 = a2 + 16;
      v19 = *(float *)(v3 + 60) * 0.0009765625;
      sub_7EA610(a2 + 16, v19);
      sub_7E9760(v5, v5, v21 + 48, v21 + 144);
      v6 = sub_801E20(a2, v21);
      sub_7E82C0(v5, v6, v5);
      sub_7E82C0(a2 + 24, a2 + 88, a2 + 16);
      sub_A69300(109051904, a2 + 24, &unk_1F00000);
      return a3 + 2;
    }
    return a3;
  }
  sub_7FF0F0(*((_DWORD *)a2 + 234), *(_DWORD *)(v3 + 188));
  *(_DWORD *)(v21 + 188) = sub_7FF6A0(*((_DWORD *)a2 + 234), 0x40000);
  v8 = *(__int16 *)(a3 + 2);
  v9 = *(_WORD *)(v8 + a3);
  v10 = (_WORD *)(a3 + v8);
  *(_WORD *)a2 = v9;
  *((_WORD *)a2 + 1) = v10[1];
  *((_WORD *)a2 + 2) = v10[2];
  *((_WORD *)a2 + 3) = v10[3];
  v11 = *((_DWORD *)a2 + 1);
  v18 = *(_DWORD *)a2;
  v20 = *(float *)(v21 + 60) * 0.00390625 / 10.0;
  sub_7EA610(v35, v20);
  sub_782BA0(v22);
  sub_7EA760(v22, v22, 0.1);
  sub_7EA460(v35, v35, v22);
  v26 = flt_C0A010;
  v30 = flt_C0A010;
  v23 = flt_C0A004;
  v25 = dword_C0A00C;
  v27 = flt_C0A004;
  v29 = dword_C0A00C;
  v24 = dword_C0A008;
  v28 = dword_C0A008;
  v23 = -(*(float *)(v21 + 64) * 0.00390625 / 10.0);
  *(float *)&v25 = -(*(float *)(v21 + 72) * 0.00390625 / 10.0);
  v27 = *(float *)(v21 + 64) * 0.00390625 / 10.0;
  *(float *)&v29 = 0.00390625 * *(float *)(v21 + 72) / 10.0;
  sub_7FF0F0(*((_DWORD *)a2 + 234), *(_DWORD *)(v21 + 188));
  v31 = v18 & 0x3FFF;
  v32 = (1 << ((__PAIR64__(v11, v18) >> 26) & 0xF)) / 64;
  *(_DWORD *)&v33[2] = 0;
  v17 = *((_DWORD *)a2 + 234);
  *(_DWORD *)v33 = (__PAIR64__(v11, v18) >> 20) & 0x3F;
  v34 = &unk_1000100;
  v12 = sub_7FF6A0(v17, 0x40000);
  sub_7E4450(&v31, v12);
  if ( FFX_Btl_GetCurrentBattleFormationId() == 170 || FFX_Btl_GetCurrentBattleFormationId() == 607 )
  {
    v23 = v23 * 10.0;
    *(float *)&v24 = *(float *)&v24 * 10.0;
    *(float *)&v25 = *(float *)&v25 * 10.0;
    v27 = v27 * 10.0;
    *(float *)&v28 = *(float *)&v28 * 10.0;
    *(float *)&v29 = 10.0 * *(float *)&v29;
  }
  sub_643190(1, v35, &v23, &v27, 0);
  return a3 + 4;
}

