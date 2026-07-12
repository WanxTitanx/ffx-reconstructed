// Function: sub_8EADF0
// Address: 0x8eadf0
_DWORD *__cdecl sub_8EADF0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // esi
  int v6; // ebx
  int v8; // esi
  int v10; // [esp+1Ch] [ebp+10h]
  int v11; // [esp+20h] [ebp+14h]
  int v12; // [esp+24h] [ebp+18h]

  *a1 = 1;
  a1[1] = 0x10000000;
  a1[2] = 14;
  a1[3] = 0;
  a1[4] = 556875264;
  a1[5] = 1074123782;
  a1[6] = 6;
  a1[7] = 0;
  a1[8] = 32777;
  a1[9] = 1353400320;
  a1[10] = 275505;
  a1[11] = 0;
  dword_187168C = a1 + 12;
  v5 = a4 - 22;
  v6 = a5 - 9;
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(216, 40);
  sub_8FACF0(a2, a3);
  sub_8FACA0(227, 44);
  sub_8FACF0(a2 + 11, a3 + 4);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(227, 40);
  sub_8FACF0(a2 + 11, a3);
  sub_8FACA0(230, 44);
  v11 = a4 - 22 + a2 + 11;
  sub_8FACF0(v11, a3 + 4);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(231, 40);
  sub_8FACF0(v11, a3);
  sub_8FACA0(242, 44);
  v12 = v5 + a2 + 22;
  sub_8FACF0(v12, a3 + 4);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(216, 44);
  sub_8FACF0(a2, a3 + 4);
  sub_8FACA0(227, 47);
  v10 = v6 + a3 + 4;
  sub_8FACF0(a2 + 11, v10);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(227, 44);
  sub_8FACF0(a2 + 11, a3 + 4);
  sub_8FACA0(230, 47);
  sub_8FACF0(v11, v6 + a3 + 4);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(231, 44);
  sub_8FACF0(v11, a3 + 4);
  sub_8FACA0(242, 47);
  sub_8FACF0(v12, v6 + a3 + 4);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(216, 48);
  sub_8FACF0(a2, v6 + a3 + 4);
  sub_8FACA0(226, 53);
  v8 = v6 + a3 + 9;
  sub_8FACF0(a2 + 11, v8);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(227, 48);
  sub_8FACF0(a2 + 11, v10);
  sub_8FACA0(230, 53);
  sub_8FACF0(v11, v8);
  sub_8FAB80(128, 128, 128, 128);
  sub_8FACA0(231, 48);
  sub_8FACF0(v11, v10);
  sub_8FACA0(242, 53);
  sub_8FACF0(v12, v8);
  return dword_187168C;
}
