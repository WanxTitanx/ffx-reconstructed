// Function: sub_812CB0
// Address: 0x812cb0
char __cdecl sub_812CB0(int a1, int a2)
{
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  __int64 v5; // kr08_8
  int v6; // eax
  double v7; // st7
  __int64 v8; // rax
  int v9; // eax
  int v11; // [esp+10h] [ebp-30h]
  int v12; // [esp+14h] [ebp-2Ch]

  v2 = *(_DWORD *)(a1 + 544);
  LOBYTE(v3) = byte_12A8480[*(unsigned __int8 *)(v2 + 24)];
  v11 = v2;
  if ( ((unsigned __int8)v3 & *(_BYTE *)(v2 + 179)) == 0 )
  {
    *(_DWORD *)(a1 + 256) = word_C8F508[0];
    *(float *)(a1 + 260) = word_C8F50C;
    *(float *)(a1 + 264) = word_C8F510;
    *(float *)(a1 + 268) = 1.0;
    v4 = *(_DWORD *)(dword_C8B500 + v2 + 200);
    HIBYTE(n1065353216) = BYTE1(word_C8F508[0]);
    BYTE1(n1065353216) = word_C8F508[0];
    *((_BYTE *)&n1065353216 + 7) = HIBYTE(word_C8F50A);
    *((_BYTE *)&n1065353216 + 5) = word_C8F50A;
    *((_BYTE *)&n1065353216 + 4) = BYTE2(v4);
    *((_BYTE *)&n1065353216 + 6) = HIBYTE(v4);
    BYTE2(n1065353216) = BYTE1(v4);
    LOBYTE(n1065353216) = v4;
    v5 = *(_QWORD *)&n1065353216;
    HIWORD(n1065353216) = word_C8F508[0];
    *((_WORD *)&n1065353216 + 3) = word_C8F50A;
    unk_C8F536 = unk_C8F50E;
    *((_WORD *)&n1065353216 + 2) = WORD1(v5);
    dword_C8B500 = 0;
    unk_C8F532 = LOWORD(word_C8F50C);
    LOWORD(n1065353216) = v5;
    n1065353216_3 = HIWORD(v5);
    LOWORD(n1065353216_2) = WORD2(v5);
    *(float *)&n964689920 = (float)(int)n1065353216;
    *((float *)&n964689920 + 1) = (float)(int)*(&n1065353216 + 1);
    n1065353216_13 = (float)n1065353216_2;
    flt_C8F98C[0] = (float)n1065353216_3;
    *(_QWORD *)(a1 + 272) = n964689920;
    *(float *)(a1 + 280) = n1065353216_13;
    *(float *)(a1 + 284) = flt_C8F98C[0];
    sub_7EA610((void *)(a1 + 128), 0.0625);
    *(_QWORD *)&n1065353216 = *(_QWORD *)(v11 + 144);
    n1065353216_2 = *(_DWORD *)(v11 + 152);
    n1065353216_3 = *(_DWORD *)(v11 + 156);
    *(_QWORD *)(a1 + 64) = *(_QWORD *)&n1065353216;
    *(_DWORD *)(a1 + 72) = n1065353216_2;
    *(_DWORD *)(a1 + 76) = n1065353216_3;
    v6 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v11);
    sub_7E78B0(a1 + 176, v6, a1 + 64);
    *(_DWORD *)(a1 + 256) = *(_DWORD *)(a1 + 176);
    *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 180);
    *(_DWORD *)(a1 + 264) = *(_DWORD *)(a1 + 184);
    *(float *)(a1 + 268) = 1.0;
    sub_7EA5E0((void *)a1);
    sub_7E9440(a1, a1, v11 + 48);
    *(_DWORD *)(a1 + 64) = word_C8F508[0];
    *(float *)(a1 + 68) = word_C8F50C;
    *(float *)(a1 + 72) = word_C8F510;
    *(float *)(a1 + 76) = word_C8F514[0];
    *(float *)(a1 + 72) = *(float *)(v11 + 76) * 0.0625;
    sub_7E78B0(a1 + 64, a1, a1 + 64);
    *(_DWORD *)(a1 + 176) = word_C8F508[0];
    *(float *)(a1 + 180) = word_C8F50C;
    *(float *)(a1 + 184) = word_C8F510;
    *(float *)(a1 + 188) = word_C8F514[0];
    sub_7E78B0(a1, a1 + 128, a1 + 64);
    *(_DWORD *)(a1 + 288) = unknown_libname_742(a1 + 704);
    *(_DWORD *)(a1 + 296) = unknown_libname_742(a1 + 704);
    *(float *)(a1 + 304) = *(float *)a1;
    *(float *)(a1 + 308) = *(float *)(a1 + 4);
    v7 = *(float *)(a1 + 8);
    *(_DWORD *)(a1 + 316) = 0;
    *(float *)(a1 + 312) = v7;
    v8 = (unk_11A0710 & 0x1FF) != 0 ? 0 : 3328;
    *(_DWORD *)(a1 + 320) = v8 | 0x24020000;
    *(_DWORD *)(a1 + 324) = HIDWORD(v8) | 2;
    *(_DWORD *)(a1 + 328) = unk_11A0740;
    *(_DWORD *)(a1 + 332) = unk_11A0744;
    *(_DWORD *)(a1 + 336) = unk_11A0730;
    *(_DWORD *)(a1 + 340) = unk_11A0734;
    v12 = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(a1 + 292) = unknown_libname_742(v12 + 16);
    sub_768E40(a1 + 256);
    v3 = sub_767870(a1 + 256);
    if ( v3 )
    {
      v9 = unknown_libname_741(*(_DWORD *)(a1 + 292));
      *(_DWORD *)(a2 + 84) = v9;
      LOBYTE(v3) = nullsub_97(v12, (v9 - v12) >> 4, *(_DWORD *)(a1 + 300) / 12288, 0);
    }
  }
  return v3;
}
