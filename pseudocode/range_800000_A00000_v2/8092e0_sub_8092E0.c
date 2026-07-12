// Function: sub_8092E0
// Address: 0x8092e0
__int16 *__cdecl sub_8092E0(int a1, __int16 *a2)
{
  int v2; // ecx
  float *v3; // ecx
  float *v4; // ecx
  double v5; // st7
  __int16 *v6; // ebx
  float *v7; // ecx
  int i; // esi
  int v10; // [esp+10h] [ebp-1Ch]
  __int16 *v11; // [esp+14h] [ebp-18h]
  float v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  float v15; // [esp+24h] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 544);
  v11 = a2;
  v10 = v2;
  switch ( *(unsigned __int16 *)(a1 + 538) >> 12 )
  {
    case 0:
      v3 = (float *)sub_800F80((_DWORD *)(a1 + 768), v2, a2[1]);
      unk_C8F980[0] = v3[16];
      flt_C8F984 = v3[17];
      flt_C8F988 = v3[18];
      flt_C8F98C[0] = v3[19];
      goto LABEL_9;
    case 1:
      v4 = (float *)sub_800F80((_DWORD *)(a1 + 768), v2, a2[1]);
      n1065353216 = 1006632960;
      unk_C8F78C[0] = 0.0078125;
      unk_C8F980[0] = v4[16];
      flt_C8F984 = v4[17];
      flt_C8F988 = v4[18];
      flt_C8F98C[0] = v4[19];
      v12 = v4[16];
      v13 = *((_DWORD *)v4 + 17);
      v14 = *((_DWORD *)v4 + 18);
      v15 = v4[19];
      n1065353216 = 1124073472;
      unk_C8F980[0] = unk_C8F980[0] * v15;
      flt_C8F984 = flt_C8F984 * v15;
      flt_C8F988 = v15 * flt_C8F988;
      unk_C8F980[0] = unk_C8F980[0] * 0.0078125;
      flt_C8F984 = flt_C8F984 * 0.0078125;
      flt_C8F988 = 0.0078125 * flt_C8F988;
      *(_DWORD *)(a1 + dword_C8B500 + 12) = 1124073472;
      dword_C8B500 = 0;
      flt_C8F970 = *(float *)a1;
      flt_C8F974 = *(float *)(a1 + 4);
      flt_C8F978 = *(float *)(a1 + 8);
      flt_C8F97C = *(float *)(a1 + 12);
      v5 = flt_C8F97C;
      goto LABEL_8;
    case 2:
      *(_DWORD *)a1 = a2[1];
      *(_DWORD *)(a1 + 4) = a2[2];
      *(_DWORD *)(a1 + 8) = a2[3];
      *(_DWORD *)(a1 + 12) = a2[4];
      unk_C8F980[0] = *(float *)a1;
      flt_C8F984 = *(float *)(a1 + 4);
      flt_C8F988 = *(float *)(a1 + 8);
      flt_C8F98C[0] = *(float *)(a1 + 12);
      v12 = *(float *)a1;
      v13 = *(_DWORD *)(a1 + 4);
      v14 = *(_DWORD *)(a1 + 8);
      v15 = *(float *)(a1 + 12);
      unk_C8F980[0] = (float)SLODWORD(v12);
      v6 = a2 + 5;
      flt_C8F984 = (float)v13;
      flt_C8F988 = (float)v14;
      flt_C8F98C[0] = (float)SLODWORD(v15);
      goto LABEL_10;
    case 3:
      unk_C8F980[0] = *(float *)(v2 + 48);
      flt_C8F984 = *(float *)(v2 + 52);
      flt_C8F988 = *(float *)(v2 + 56);
      flt_C8F98C[0] = *(float *)(v2 + 60);
      v6 = a2 + 1;
      goto LABEL_10;
    case 4:
      v7 = (float *)sub_800F80((_DWORD *)(a1 + 768), v2, a2[1]);
      unk_C8F980[0] = v7[12];
      flt_C8F984 = v7[13];
      flt_C8F988 = v7[14];
      flt_C8F98C[0] = v7[15];
      goto LABEL_9;
    case 5:
      *(_DWORD *)a1 = *(unsigned __int8 *)(v2 + 200);
      *(_DWORD *)(a1 + 4) = *(unsigned __int8 *)(v2 + 201);
      *(_DWORD *)(a1 + 8) = *(unsigned __int8 *)(v2 + 202);
      *(_DWORD *)(a1 + 12) = a2[1];
      unk_C8F980[0] = *(float *)a1;
      flt_C8F984 = *(float *)(a1 + 4);
      flt_C8F988 = *(float *)(a1 + 8);
      flt_C8F98C[0] = *(float *)(a1 + 12);
      v12 = *(float *)a1;
      v13 = *(_DWORD *)(a1 + 4);
      v14 = *(_DWORD *)(a1 + 8);
      v15 = *(float *)(a1 + 12);
      unk_C8F980[0] = (float)SLODWORD(v12);
      flt_C8F984 = (float)v13;
      flt_C8F988 = (float)v14;
      v5 = (double)SLODWORD(v15);
LABEL_8:
      flt_C8F98C[0] = v5;
LABEL_9:
      v6 = a2 + 2;
LABEL_10:
      v11 = v6;
      break;
    default:
      break;
  }
  n1065353216 = 1132396544;
  unk_C8F78C[0] = 255.0;
  flt_C8F970 = flt_C0A004 - flt_C0A004;
  flt_C8F974 = *(float *)&dword_C0A008 - *(float *)&dword_C0A008;
  flt_C8F978 = *(float *)&dword_C0A00C - *(float *)&dword_C0A00C;
  flt_C8F97C = flt_C0A010 - flt_C0A010;
  sub_42EF00();
  sub_808D80(unk_C8F980, unk_C8F980, unk_C8F78C[0]);
  sub_808CE0(unk_C8F980, unk_C8F980, LODWORD(flt_C8F970), LODWORD(flt_C8F974), LODWORD(flt_C8F978), LODWORD(flt_C8F97C));
  v12 = unk_C8F980[0];
  v13 = LODWORD(flt_C8F984);
  v14 = LODWORD(flt_C8F988);
  v15 = flt_C8F98C[0];
  for ( i = 0; i < 4; ++i )
    LODWORD(unk_C8F980[i]) = (int)*(float *)((char *)&v12 + i * 4);
  LOWORD(n1065353216) = LOWORD(unk_C8F980[0]);
  unk_C8F52A = LOWORD(flt_C8F984);
  LOWORD(unk_C8F52C) = LOWORD(flt_C8F988);
  unk_C8F52E = LOWORD(flt_C8F98C[0]);
  LOWORD(unk_C8F530) = word_C8F508[0];
  unk_C8F532 = word_C8F50C;
  unk_C8F534 = word_C8F510;
  unk_C8F536 = word_C8F514;
  sub_737690(&n1065353216, word_C8F508, &n1065353216);
  *(_DWORD *)(v10 + 200) = n1065353216;
  return v11;
}
