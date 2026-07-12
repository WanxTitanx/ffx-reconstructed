// Function: sub_819590
// Address: 0x819590
int __cdecl sub_819590(int a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  unsigned int n0x8000; // eax
  int v5; // esi
  char v7; // cl
  char v8; // dl
  __int16 v9; // dx
  char v10; // cl
  char v11; // dl
  int n1065353216; // ecx
  int v13; // esi
  int v14; // edx
  int v15; // edx
  float v16; // eax
  float v17; // [esp+14h] [ebp-10h]
  float v18; // [esp+14h] [ebp-10h]
  float v19; // [esp+1Ch] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-8h]
  float v21; // [esp+20h] [ebp-4h]
  float v22; // [esp+20h] [ebp-4h]

  v2 = a2;
  v3 = *(_DWORD *)(a1 + 544);
  n0x8000 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n0x8000 > 0x4000 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x7000 )
    {
      if ( n0x8000 != 0x8000 )
        return v2;
      sub_81B2F0(*((unsigned __int8 *)&unk_12A40D0 + 32 * *(unsigned __int16 *)(v3 + 20)), a1);
      v17 = (float)*(__int16 *)(a2 + 2);
      v18 = v17 * 0.0625;
      if ( v18 > sub_7E7ED0(v3 + 144, a1) )
        return a2 + 6;
      return *(__int16 *)(a2 + 4) + a2;
    }
    else
    {
      switch ( n0x8000 )
      {
        case 0x7000u:
          v22 = sub_836120();
          *(float *)(v3 + 148) = v22;
          *(float *)(v3 + 68) = v22 * 16.0;
          return a2 + 2;
        case 0x5000u:
          v13 = *(_DWORD *)(v3 + 188);
          v14 = (*(unsigned __int16 *)(v13 + 6) - 1) % *(unsigned __int16 *)(v13 + 4);
          unk_C8F954 = 0;
          n1065353216_5 = n1065353216_2;
          *(_QWORD *)&n1065353216 = 1098907648;
          flt_C8F950 = 16.0;
          n1065353216_6 = n1065353216_3;
          v15 = v13 + 16 * (v14 + 1);
          qword_C8F980 = *(_QWORD *)v15;
          flt_C8F988 = *(float *)(v15 + 8);
          flt_C8F98C[0] = *(float *)(v15 + 12);
          flt_C8F970 = *(float *)(v3 + 144);
          flt_C8F974 = *(float *)(v3 + 148);
          flt_C8F978 = *(float *)(v3 + 152);
          flt_C8F97C = *(float *)(v3 + 156);
          flt_C8F960 = *(float *)(v3 + 96);
          flt_C8F964 = *(float *)(v3 + 100);
          flt_C8F968 = *(float *)(v3 + 104);
          v16 = *(float *)(v3 + 108);
          flt_C8F960 = flt_C8F970 - *(float *)&qword_C8F980;
          flt_C8F96C = v16;
          flt_C8F964 = flt_C8F974 - *((float *)&qword_C8F980 + 1);
          flt_C8F968 = flt_C8F978 - flt_C8F988;
          sub_42EF00();
          flt_C8F960 = flt_C8F950 * flt_C8F960;
          flt_C8F964 = flt_C8F950 * flt_C8F964;
          flt_C8F968 = flt_C8F950 * flt_C8F968;
          *(float *)(v3 + 96) = flt_C8F960;
          *(float *)(v3 + 100) = flt_C8F964;
          *(float *)(v3 + 104) = flt_C8F968;
          *(float *)(v3 + 108) = flt_C8F96C;
          return a2 + 4;
        case 0x6000u:
          sub_782BA0(a1);
          qword_C8F980 = *(_QWORD *)a1;
          flt_C8F988 = *(float *)(a1 + 8);
          flt_C8F98C[0] = *(float *)(a1 + 12);
          n1065353216_3 = LODWORD(flt_C8F98C[0]);
          n1065353216_2 = LODWORD(flt_C8F988);
          *(_QWORD *)&n1065353216 = qword_C8F980;
          *(_DWORD *)(dword_C8B500 + v3 + 144) = qword_C8F980;
          *(_DWORD *)(dword_C8B500 + v3 + 148) = *(&n1065353216 + 1);
          n1065353216 = n1065353216_2;
          n1065353216_2 = n1065353216;
          n1065353216 = n1065353216;
          *(_DWORD *)(v3 + 152) = n1065353216;
          dword_C8B500 = 0;
          sub_7EA760(v3 + 64, a1, 16.0);
          return a2 + 2;
        default:
          return v2;
      }
    }
  }
  else if ( n0x8000 == 0x4000 )
  {
    v21 = sub_7949A0(*(unsigned __int8 *)(v3 + 24));
    *(float *)(v3 + 68) = 16.0 * v21;
    *(float *)(v3 + 148) = v21;
    return a2 + 2;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x2000 )
  {
    if ( n0x8000 != 12288 )
      return v2;
    v7 = *(_BYTE *)(a2 + 11);
    v8 = *(_BYTE *)(a2 + 12);
    *(float *)a1 = *(float *)(*(char *)(a2 + 10) + v3);
    *(float *)(a1 + 4) = *(float *)(v7 + v3);
    *(float *)(a1 + 8) = *(float *)(v8 + v3);
    *(_DWORD *)(a1 + 16) = word_C8F508[0];
    *(float *)(a1 + 20) = word_C8F50C;
    *(float *)(a1 + 24) = word_C8F510;
    *(float *)(a1 + 28) = word_C8F514[0];
    sub_7EA5E0((void *)(a1 + 64));
    sub_7E97C0(a1 + 64, a1 + 64, a1, a1 + 16, *(__int16 *)(a2 + 2));
    v9 = *(_WORD *)(a2 + 8);
    v20 = *(__int16 *)(a2 + 6);
    *(float *)(a1 + 32) = (float)*(__int16 *)(a2 + 4);
    *(float *)(a1 + 36) = (float)v20;
    *(float *)(a1 + 40) = (float)v9;
    sub_7E78B0(a1 + 48, a1 + 64, a1 + 32);
    v10 = *(_BYTE *)(a2 + 14);
    v11 = *(_BYTE *)(a2 + 15);
    *(float *)(*(char *)(a2 + 13) + v3) = *(float *)(a1 + 48) + *(float *)(*(char *)(a2 + 13) + v3);
    *(float *)(v10 + v3) = *(float *)(a1 + 52) + *(float *)(v10 + v3);
    *(float *)(v11 + v3) = *(float *)(a1 + 56) + *(float *)(v11 + v3);
    sub_7EA760(v3 + 144, v3 + 64, 0.0625);
    return a2 + 16;
  }
  else if ( n0x8000 == 0x2000 )
  {
    g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v3 + 186)](a1, a2);
    return a2 + 2;
  }
  else
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
    {
      if ( n0x8000 != 4096 )
        return v2;
      v5 = *(__int16 *)(a2 + 2);
      v19 = sub_800A90(*(unsigned __int8 *)(v3 + 24), *(char *)(a1 + 542));
      sub_800BB0(*(unsigned __int8 *)(v3 + 24), *(char *)(a1 + 542));
      *(float *)(v3 + 4 * v5 + 48) = (double)*(unsigned __int16 *)(a2 + 4) * v19 * 0.0625;
      return a2 + 6;
    }
    sub_782BA0(a1);
    *(float *)(v3 + 68) = *(float *)(a1 + 4) * 16.0;
    *(float *)(v3 + 148) = *(float *)(a1 + 4);
    return a2 + 2;
  }
}
