// Function: sub_8EA940
// Address: 0x8ea940
_DWORD *__cdecl sub_8EA940(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // ebx
  int v7; // esi
  int v9; // [esp+24h] [ebp+18h]

  *a1 = 6;
  a1[1] = 0x10000000;
  a1[2] = 14;
  a1[3] = 0;
  dword_187168C = a1 + 4;
  sub_8FAC80();
  v5 = dword_187168C;
  *dword_187168C = &unk_2000000;
  v5[1] = &unk_1A00000;
  v5[2] = 64;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  v5[6] = 8;
  v5[7] = 0;
  v5[8] = 68;
  v5[9] = 128;
  v5[10] = 66;
  v5[11] = 0;
  v5[12] = 15;
  v5[13] = 0;
  v5[14] = 71;
  v5[15] = 0;
  v5[16] = 556875520;
  v5[17] = 1074123910;
  v5[18] = 6;
  v5[19] = 0;
  v5[20] = 32777;
  v5[21] = 1353400320;
  v5[22] = 275505;
  v5[23] = 0;
  dword_187168C = v5 + 24;
  v6 = a5 - a3 - 17;
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(147, 152);
  sub_8FACF0(a2, a3);
  sub_8FACA0(155, 160);
  sub_8FACF0(a2 + 8, a3 + 8);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(155, 152);
  sub_8FACF0(a2 + 8, a3);
  sub_8FACA0(160, 160);
  sub_8FACF0(a4 - 9, a3 + 8);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(160, 152);
  sub_8FACF0(a4 - 9, a3);
  sub_8FACA0(169, 160);
  sub_8FACF0(a4, a3 + 8);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(147, 160);
  sub_8FACF0(a2, a3 + 8);
  sub_8FACA0(155, 163);
  v9 = a5 - 9;
  sub_8FACF0(a2 + 8, v9);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(155, 160);
  sub_8FACF0(a2 + 8, a3 + 8);
  sub_8FACA0(160, 163);
  sub_8FACF0(a4 - 9, v9);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(160, 160);
  sub_8FACF0(a4 - 9, a3 + 8);
  sub_8FACA0(169, 163);
  sub_8FACF0(a4, v9);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(147, 163);
  sub_8FACF0(a2, v9);
  sub_8FACA0(155, 172);
  v7 = v6 + a3 + 17;
  sub_8FACF0(a2 + 8, v7);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(155, 163);
  sub_8FACF0(a2 + 8, v9);
  sub_8FACA0(160, 172);
  sub_8FACF0(a4 - 9, v7);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(160, 163);
  sub_8FACF0(a4 - 9, v9);
  sub_8FACA0(169, 172);
  sub_8FACF0(a4, v7);
  return dword_187168C;
}
