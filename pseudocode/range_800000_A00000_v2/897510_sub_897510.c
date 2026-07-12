// Function: sub_897510
// Address: 0x897510
int sub_897510()
{
  int n12565; // ecx
  int result; // eax

  FFX_Btl_SubmenuBuildCommandList();
  FFX_Battle_ConfirmTargetSelection(unk_23CC040, unk_23CC038, 0);
  if ( sub_785280(n12565) == 1 && unk_23CC040[0] <= 0x11u )
    sub_898940();
  unk_133C8FC = 0;
  unk_23CC08C = 0;
  unk_133D70C = 0;
  unk_133D710 = 0;
  unk_133D714 = 0;
  unk_133D718 = 0;
  unk_133D71C = 0;
  unk_133D720 = 0;
  unk_133D724 = 0;
  unk_133D728 = 0;
  unk_133D72C = 0;
  result = sub_8AE550(2);
  if ( !unk_133D6A0 )
  {
    unk_23CC088[0] = 255;
    return 255;
  }
  return result;
}
