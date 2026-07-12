// Function: FFX_Btl_UI_OpenSubmenu
// Address: 0x89ba80
int __cdecl FFX_Btl_UI_OpenSubmenu(int a1)
{
  int result; // eax

  result = FFX_Battle_QueueGateCheck();
  if ( result == 1 && !unk_23CC08C )
  {
    unk_133D70C = 0;
    unk_133D710 = 0;
    unk_133D714 = 0;
    unk_133D718 = 0;
    unk_133D71C = 0;
    unk_133D720 = 0;
    unk_133D724 = 0;
    unk_133D728 = 0;
    unk_133D72C = 0;
    n256_0 = 0;
    unk_23CC038 = 0;
    memset(&unk_133C910, 0, 0x780u);
    unk_23CC092[0] = -1;
    unk_133F0C0 = 0;
    unk_133F0C4 = 0;
    memset(unk_23CC040, 0, 0x48u);
    sub_8A0C60();
    sub_8A0C70();
    sub_897940();
    FFX_Battle_SubmenuOvrRowBuild();
    unk_133C8FC = 0;
    memset(&n44, 0, 0x80u);
    unk_133F4DC = 0;
    unk_133F4E0 = 0;
    unk_133F4E8 = 0;
    unk_133F4EC = 0;
    unk_133C8FE = 0;
    unk_133F4D0 = 0;
    n7_0 = 7;
    unk_133F4D8 = 0;
    n7_6 = 7;
    n255_1 = 255;
    sub_897B40();
    FFX_BtlHud_ShimmerResetAll();
    unk_23CC088[0] = a1;
    unk_23CC08C |= 1 << a1;
    return sub_89A2A0(a1, 254);
  }
  return result;
}
