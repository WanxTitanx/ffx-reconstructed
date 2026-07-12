// Function: sub_89B5D0
// Address: 0x89b5d0
int sub_89B5D0()
{
  _DWORD *v0; // eax

  FFX_BtlHud_SubmenuStateClear();
  unk_133C908 = 1;
  n256_0 = 0;
  sub_8977D0();
  FFX_BtlHud_GetAnimTimingWord(2, "dumm79", &word_23CC090);
  sub_8AF570(1);
  memset(&unk_133C910, 0, 0x780u);
  memset(&n0x1C, 0, 0x140u);
  v0 = &unk_133D788;
  do
  {
    *(v0 - 9) = 0;
    *v0 = 0;
    v0[9] = 0;
    v0[18] = 0;
    v0[27] = 0;
    v0[36] = 0;
    v0[45] = 0;
    v0[54] = 0;
    v0[63] = 0;
    v0[72] = 0;
    v0 += 90;
  }
  while ( (int)v0 < (int)&dword_133F0D8 );
  unk_23CC08C = 0;
  unk_23CC088[0] = 255;
  word_133F0C8[0] = 0;
  byte_C58EF4 = 1;
  sub_897940();
  FFX_Battle_SubmenuOvrRowBuild();
  sub_897A60();
  unk_133C8FE = 0;
  n255_1 = 255;
  sub_897B40();
  unk_133C8FC = 0;
  memset(&n44, 0, 0x80u);
  unk_133F748 = 0.0;
  MEMORY[0x133F74C] = 0.0;
  MEMORY[0x133F750] = 0.0;
  MEMORY[0x133F754] = 0.0;
  unk_133F4D0 = 0;
  n7_0 = 7;
  unk_133F4D8 = 0;
  unk_133F4DC = 0;
  unk_133F4E0 = 0;
  n7_6 = 7;
  unk_133F4E8 = 0;
  unk_133F4EC = 0;
  unk_133F744 = 0;
  FFX_BtlHud_GetAnimTiming(2, (int)"dum201", &word_133F740, &word_133F742);
  n2_4 = 0;
  if ( FFX_BtlEffect_CheckEffect(-2147483570) )
    FFX_BtlEffect_Disable(-2147483570);
  n4_5 = 0;
  unk_133F774 = 0;
  unk_133F778 = 0;
  unk_133F77C = 0;
  unk_133F780 = 0;
  unk_133F784 = 0;
  unk_133F788 = 0;
  unk_133F78C = 0;
  unk_133F790 = 0;
  return sub_8AE550(2);
}
