// Function: FFX_Btl_UI_Overdrive_ResetGaugeToActor
// Address: 0x899e90
int __cdecl FFX_Btl_UI_Overdrive_ResetGaugeToActor(int a1)
{
  int v1; // esi
  __int16 n8; // ax
  float v4; // [esp+Ch] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+10h] [ebp-4h] BYREF

  sub_897B40();
  v1 = sub_78F810(a1, 1);
  sub_8B9600(0, v1, &v4, v5, 0, 0);
  n8 = 8;
  if ( v4 >= (double)unk_133F5DE )
    n8 = 2;
  n2_15 = n8;
  unk_133F5E4 = (float)word_133F64C;
  unk_133F5E8 = (float)word_133F650[0];
  unk_133F5EC[0] = (int)v4;
  unk_133F5F0 = v1;
  unk_133F648 = 1;
  return 1;
}
