// Function: sub_81C600
// Address: 0x81c600
unsigned __int16 *__cdecl sub_81C600(_DWORD *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // edi
  int v3; // esi
  unsigned int n12288; // eax
  _DWORD *v5; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  __int64 v10; // rax
  unsigned int v11; // ecx
  __int16 *v12; // ebx
  int v13; // eax
  unsigned __int16 *v14; // esi
  int v15; // esi
  int v16; // ebx
  __int64 v17; // rax
  __int16 *v18; // ebx
  int v19; // ecx
  int v20; // [esp+18h] [ebp-40h]
  int v21; // [esp+1Ch] [ebp-3Ch]
  float v22; // [esp+1Ch] [ebp-3Ch]
  int v23; // [esp+20h] [ebp-38h]
  int v24; // [esp+20h] [ebp-38h]
  int v25; // [esp+34h] [ebp-24h]
  int v26; // [esp+34h] [ebp-24h]
  __int16 n3; // [esp+36h] [ebp-22h]
  int v28; // [esp+38h] [ebp-20h]
  __int16 v29; // [esp+46h] [ebp-12h]

  v2 = a2;
  v21 = a1[136];
  v20 = a1[*(unsigned __int8 *)(v21 + 30) + 216];
  v3 = sub_7E3720(v20, 4, a2[1]);
  n12288 = *((_WORD *)a1 + 269) & 0xF000;
  v23 = v3;
  if ( n12288 <= 0x3000 )
  {
    if ( n12288 == 12288 )
    {
      nullsub_200(v3, a2[2], a2[3]);
      return a2 + 4;
    }
    if ( (*((_WORD *)a1 + 269) & 0xF000) != 0 )
    {
      if ( n12288 == 4096 )
      {
        sub_7FF0F0(a1[234], v3);
        return a2 + 2;
      }
      if ( n12288 != 0x2000 )
        return v2;
      v5 = (_DWORD *)sub_7E3720(v20, 2, (__int16)a2[2]);
      sub_A69C80(v3, *v5);
    }
    else
    {
      v7 = sub_A698C0(v3);
      v8 = sub_7FF6A0(a1[234], v7);
      sub_A69290(v23, v8);
      sub_7E37B0(v20, 4, (__int16)a2[2], v8);
    }
LABEL_18:
    v2 += 3;
    return v2;
  }
  if ( n12288 == 0x4000 )
  {
    v16 = (__int16)a2[2];
    v17 = *(__int16 *)((char *)a2 + v16);
    v18 = (__int16 *)((char *)a2 + v16);
    *(_QWORD *)&n1065353216 = v17;
    *(_QWORD *)&n3_11 = v18[2];
    n3 = n3_11;
    v19 = v18[1];
    *(_QWORD *)&n1065353216 = v18[1];
    v29 = v18[3] >> 15;
    HIWORD(n1065353216) = v18[3];
    *(_QWORD *)&n3_11 = SHIWORD(n1065353216);
    *((_WORD *)&n1065353216 + 3) = v29;
    unk_C8F536 = SHIWORD(n1065353216) >> 15;
    *((_WORD *)&n1065353216 + 2) = HIWORD(v19);
    n1065353216_3 = (unsigned __int64)v19 >> 48;
    unk_C8F532 = (unsigned __int64)SHIWORD(n1065353216) >> 32;
    LOWORD(n1065353216_2) = v19 >> 31;
    LOWORD(n1065353216) = v19;
    HIWORD(v28) = HIWORD(n1065353216);
    LOWORD(v28) = n3;
    HIWORD(v26) = v19;
    LOWORD(v26) = v17;
    sub_A69DE0(v3, v26, v28);
    v2 = a2;
    goto LABEL_18;
  }
  if ( n12288 != 20480 )
  {
    if ( n12288 == 24576 )
    {
      v9 = (__int16)a2[3];
      v10 = *(__int16 *)((char *)a2 + v9);
      v11 = *(__int16 *)((char *)a2 + v9);
      v12 = (__int16 *)((char *)a2 + v9);
      *(_QWORD *)&n1065353216 = __PAIR64__(HIDWORD(v10), v11);
      *(_QWORD *)&n3_11 = v12[2];
      LODWORD(v10) = v12[1];
      *(_QWORD *)&n1065353216 = v12[1];
      HIWORD(n1065353216) = v12[3];
      *(_QWORD *)&n3_11 = SHIWORD(n1065353216);
      *((_WORD *)&n1065353216 + 3) = SHIWORD(n1065353216) >> 15;
      unk_C8F536 = SHIWORD(n1065353216) >> 15;
      *((_WORD *)&n1065353216 + 2) = WORD1(v10);
      n1065353216_3 = (unsigned __int64)(int)v10 >> 48;
      unk_C8F532 = (unsigned __int64)SHIWORD(n1065353216) >> 32;
      LOWORD(n1065353216_2) = (int)v10 >> 31;
      LOWORD(n1065353216) = v10;
      HIWORD(v25) = v10;
      LOWORD(v25) = v11;
      sub_81CB30(v20, (__int16)a2[1], (__int16)a2[2], v25);
      return a2 + 4;
    }
    return v2;
  }
  v13 = sub_7E3720(v20, 4, (__int16)a2[1]);
  v24 = v13;
  if ( !unk_12F40D8 )
  {
    sub_A69F10(v13, 109051904, 113246208);
    ++unk_12F40D8;
  }
  v14 = (unsigned __int16 *)v21;
  v22 = *(float *)(v21 + 60) * 0.000000476837158203125;
  sub_7EA610(a1, v22);
  v15 = sub_801E20(a1, v14);
  sub_7E82C0(a1 + 16, &n1065353216_0, &unk_113FCB0);
  sub_7E82C0(a1 + 48, v15, a1);
  sub_7E82C0(a1 + 48, &n1065353216_0, a1 + 48);
  sub_A693B0(v24, a1 + 48, a1, a1 + 16, a1[202]);
  return a2 + 2;
}
